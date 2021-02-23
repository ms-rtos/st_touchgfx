/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_os_wrappers.cpp TouchGFX OS wrappers.
 *
 * Author: Jiao.jinxing <jiaojinxing@acoinfo.com>
 *
 */

#include <ms_rtos.h>

#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <touchgfx/hal/HAL.hpp>

using namespace touchgfx;

static ms_handle_t  ms_tgfx_frame_buffer_sem = 0;
static ms_handle_t  ms_tgfx_vsync_queue = 0;

// Just a dummy value to insert in the VSYNC queue.
static ms_uint32_t  ms_tgfx_dummy = 0x5a;
static ms_uint32_t  ms_tgfx_vsync_queue_buffer;

extern ms_bool_t    ms_tgfx_using_double_fb;

static void ms_tgfx_active_area_enter(int sig)
{
    HAL::getInstance()->vSync();
    OSWrappers::signalVSync();
    if (ms_tgfx_using_double_fb) {
        // Swap frame buffers immediately instead of waiting for the task to be scheduled in.
        // Note: task will also swap when it wakes up, but that operation is guarded and will not have
        // any effect if already swapped.
        HAL::getInstance()->swapFrameBuffers();
    } else {
        OSWrappers::giveFrameBufferSemaphoreFromISR();
    }
    GPIO::set(GPIO::VSYNC_FREQ);
}

static void ms_tgfx_active_area_exit(int sig)
{
    HAL::getInstance()->vSync();
    GPIO::clear(GPIO::VSYNC_FREQ);
    HAL::getInstance()->frontPorchEntered();
}

/*
 * Initialize frame buffer semaphore and queue/mutex for VSYNC signal.
 */
void OSWrappers::initialize()
{
    // Create a queue of length 1
    ms_semb_create("tgfx_semb", MS_FALSE, MS_WAIT_TYPE_PRIO, &ms_tgfx_frame_buffer_sem);

    // Create a queue of length 1
    ms_mqueue_create("tgfx_mq", &ms_tgfx_vsync_queue_buffer, 1U, sizeof(ms_uint32_t),
                     MS_WAIT_TYPE_PRIO, &ms_tgfx_vsync_queue);

    ms_process_signal(MS_FB_SIGNAL_ACTIVE_AREA_ENTER, ms_tgfx_active_area_enter);
    ms_process_signal(MS_FB_SIGNAL_ACTIVE_AREA_EXIT,  ms_tgfx_active_area_exit);
}

/*
 * Take the frame buffer semaphore. Blocks until semaphore is available.
 */
void OSWrappers::takeFrameBufferSemaphore()
{
    ms_semb_wait(ms_tgfx_frame_buffer_sem, MS_TIMEOUT_FOREVER);
}

/*
 * Release the frame buffer semaphore.
 */
void OSWrappers::giveFrameBufferSemaphore()
{
    ms_semb_post(ms_tgfx_frame_buffer_sem);
}

/*
 * Attempt to obtain the frame buffer semaphore. If semaphore is not available, do
 * nothing.
 *
 * Note must return immediately! This function does not care who has the taken the semaphore,
 * it only serves to make sure that the semaphore is taken by someone.
 */
void OSWrappers::tryTakeFrameBufferSemaphore()
{
    ms_semb_wait(ms_tgfx_frame_buffer_sem, MS_TIMEOUT_NO_WAIT);
}

/*
 * Release the frame buffer semaphore in a way that is safe in interrupt context. Called
 * from ISR.
 *
 * Release the frame buffer semaphore in a way that is safe in interrupt context.
 * Called from ISR.
 */
void OSWrappers::giveFrameBufferSemaphoreFromISR()
{
    ms_semb_post(ms_tgfx_frame_buffer_sem);
}

/*
 * Signal that a VSYNC has occurred. Should make the vsync queue/mutex available.
 *
 * Note This function is called from an ISR, and should (depending on OS) trigger a
 * scheduling.
 */
void OSWrappers::signalVSync()
{
    ms_mqueue_post(ms_tgfx_vsync_queue, &ms_tgfx_dummy, MS_TIMEOUT_NO_WAIT);
}

/*
 * This function blocks until a VSYNC occurs.
 *
 * Note This function must first clear the mutex/queue and then wait for the next one to
 * occur.
 */
void OSWrappers::waitForVSync()
{
    ms_uint32_t msg;

    // First make sure the queue is empty, by trying to remove an element with 0 timeout.
    ms_mqueue_wait(ms_tgfx_vsync_queue, &msg, MS_TIMEOUT_NO_WAIT);

    // Then, wait for next VSYNC to occur.
    ms_mqueue_wait(ms_tgfx_vsync_queue, &msg, MS_TIMEOUT_FOREVER);
}

/*
 * A function that causes executing task to sleep for a number of milliseconds.
 *
 * A function that causes executing task to sleep for a number of milliseconds.
 * This function is OPTIONAL. It is only used by the TouchGFX in the case of
 * a specific frame refresh strategy (REFRESH_STRATEGY_OPTIM_SINGLE_BUFFER_TFT_CTRL).
 * Due to backwards compatibility, in order for this function to be useable by the HAL
 * the function must be explicitly registered:
 * hal.registerTaskDelayFunction(&OSWrappers::taskDelay)
 *
 * see HAL::setFrameRefreshStrategy(FrameRefreshStrategy s)
 * see HAL::registerTaskDelayFunction(void (*delayF)(uint16_t))
 */
void OSWrappers::taskDelay(uint16_t ms)
{
    ms_thread_sleep_ms(static_cast<uint32_t>(ms));
}
