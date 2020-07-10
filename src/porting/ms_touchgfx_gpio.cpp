/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_gpio.cpp TouchGFX GPIO.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#include <ms_rtos.h>

#include <touchgfx/hal/GPIO.hpp>

/**
 * GPIO_ID Enum, these are used bt TouchGFX framework to signal events.
 *
 * VSYNC_FREQ,  /// Pin is toggled at each VSYNC
 * RENDER_TIME, /// Pin is high when frame rendering begins, low when finished
 * FRAME_RATE,  /// Pin is toggled when the frame buffers are swapped.
 * MCU_ACTIVE   /// Pin is high when framework is utilizing the MCU.
 *
 */

using namespace touchgfx;

/*
 * Perform configuration of IO pins.
 */
void GPIO::init()
{

}

/*
 * Sets a pin high.
 */
void GPIO::set(GPIO_ID id)
{

}

/*
 * Sets a pin low.
 */
void GPIO::clear(GPIO_ID id)
{

}

/*
 * Toggles a pin.
 */
void GPIO::toggle(GPIO_ID id)
{

}

/*
 * Gets the state of a pin.
 */
bool GPIO::get(GPIO_ID id)
{
    return false;
}
