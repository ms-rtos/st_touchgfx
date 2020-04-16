/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_touch.cpp TouchGFX touch screen.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#include <ms_rtos.h>

#include <ms_touchgfx_touch.hpp>
#include <ms_touchgfx_hal.hpp>
#include <touchgfx/hal/OSWrappers.hpp>

void MsTouchController::init()
{
    touch_fd = ms_io_open("/dev/touch0", O_RDONLY, 0666);
    if (touch_fd < 0) {
        ms_printf("Failed to open /dev/touch0 device!\n");
    }
}

bool MsTouchController::sampleTouch(int32_t& x, int32_t& y)
{
    if (touch_fd >= 0) {
        static int16_t last_x = 0;
        static int16_t last_y = 0;
        ms_touch_event_t event;

        if (ms_io_read(touch_fd, &event, sizeof(event)) == sizeof(event)) {
            if (event.touch_detected > 0) {
                last_x = event.touch_x[0];
                last_y = event.touch_y[0];

                x = event.touch_x[0];
                y = event.touch_y[0];
                return true;
            } else {
                x = last_x;
                y = last_y;
            }
        }
    }

    return false;
}