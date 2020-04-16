/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_hal.cpp TouchGFX HAL.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#include <ms_rtos.h>
#include <stdlib.h>

#include <ms_touchgfx_hal.hpp>

using namespace touchgfx;

void TouchGFXHAL::initialize()
{
    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

    HAL::initialize();

    registerEventListener(*(touchgfx::Application::getInstance()));

    ms_fb_var_screeninfo_t var_info;
    ms_fb_fix_screeninfo_t fix_info;

    fb_fd = ms_io_open("/dev/fb0", O_RDWR, 0666);
    if (fb_fd < 0) {
        ms_printf("Failed to open /dev/fb0 device!\n");
        abort();
        return;
    }

    if (ms_io_ioctl(fb_fd, MS_FB_CMD_GET_VSCREENINFO, &var_info) < 0) {
        ms_printf("Failed to get /dev/fb0 variable screen info!\n");
        abort();
    }

    if (ms_io_ioctl(fb_fd, MS_FB_CMD_GET_FSCREENINFO, &fix_info) < 0) {
        ms_printf("Failed to get /dev/fb0 fix screen info!\n");
        abort();
    }

    frame_buffer = (uint16_t *)fix_info.smem_start;

    /*
     * TODO
     */
    setFrameBufferStartAddresses((void*)frame_buffer, (void*)0, (void*)0);

    /*
     * Set whether the DMA transfers are locked to the TFT update cycle. If
     * locked, DMA transfer will not begin until the TFT controller has finished
     * updating the display. If not locked, DMA transfers will begin as soon as
     * possible. Default is true (DMA is locked with TFT).
     *
     * Setting to false to increase performance when using double buffering
     */
    lockDMAToFrontPorch(false);
}

/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    return frame_buffer;
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
}

/**
 * @fn virtual void TouchGFXHAL::flushFrameBuffer();
 *
 * @brief This function is called whenever the framework has performed a complete draw.
 *
 * This specialization is only in place to keep compilers happy. Base impl. will call the
 * Rect version.
 * @see HAL::flushFrameBuffer
 */
void TouchGFXHAL::flushFrameBuffer()
{
    HAL::flushFrameBuffer();
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.

    HAL::flushFrameBuffer(rect);

    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then we need
    // to flush the Dcache to make sure framebuffer is correct in RAM. That's done
    // using SCB_CleanInvalidateDCache().

    /*
     * TODO
     */
    //SCB_CleanInvalidateDCache();
}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
}
