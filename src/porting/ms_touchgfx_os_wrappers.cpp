/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_os_wrappers.cpp TouchGFX OS wrappers.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#include <ms_rtos.h>

#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <touchgfx/hal/HAL.hpp>

#include <assert.h>

using namespace touchgfx;

static ms_handle_t frame_buffer_sem = 0;
static ms_handle_t vsync_queue = 0;

// Just a dummy value to insert in the VSYNC queue.
static ms_uint32_t dummy = 0x5a;
static ms_uint32_t vsync_queue_buffer;

#define __DEFAULT_TIMEOUT   10U

void OSWrappers::initialize()
{
    // Create a queue of length 1
    ms_semb_create("tgfx_semb", MS_FALSE, MS_WAIT_TYPE_PRIO, &frame_buffer_sem);

    // Create a queue of length 1
    ms_mqueue_create("tgfx_mq", &vsync_queue_buffer, 1U, sizeof(ms_uint32_t),
                     MS_WAIT_TYPE_PRIO, &vsync_queue);
}

void OSWrappers::takeFrameBufferSemaphore()
{
    assert(frame_buffer_sem);
    ms_semb_wait(frame_buffer_sem, __DEFAULT_TIMEOUT);
}

void OSWrappers::giveFrameBufferSemaphore()
{
    assert(frame_buffer_sem);
    ms_semb_post(frame_buffer_sem);
}

void OSWrappers::tryTakeFrameBufferSemaphore()
{
    assert(frame_buffer_sem);
    ms_semb_wait(frame_buffer_sem, MS_TIMEOUT_NO_WAIT);
}

void OSWrappers::giveFrameBufferSemaphoreFromISR()
{
    assert(frame_buffer_sem);
    ms_semb_post(frame_buffer_sem);
}

void OSWrappers::signalVSync()
{
    if (vsync_queue) {
        ms_mqueue_post(vsync_queue, &dummy, MS_TIMEOUT_NO_WAIT);
    }
}

void OSWrappers::waitForVSync()
{
    if (vsync_queue) {
        ms_uint32_t msg;

        // First make sure the queue is empty, by trying to remove an element with 0 timeout.
        ms_mqueue_wait(vsync_queue, &msg, MS_TIMEOUT_NO_WAIT);

        // Then, wait for next VSYNC to occur.
        ms_mqueue_wait(vsync_queue, &msg, __DEFAULT_TIMEOUT);
    }
}

void OSWrappers::taskDelay(uint16_t ms)
{
    ms_thread_sleep_ms(static_cast<uint32_t>(ms));
}
