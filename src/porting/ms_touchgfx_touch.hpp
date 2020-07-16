/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_touch.hpp TouchGFX touch screen.
 *
 * Author: Jiao.jinxing <jiaojinxing@acoinfo.com>
 *
 */


#ifndef MS_TOUCHGFX_TOUCH_HPP
#define MS_TOUCHGFX_TOUCH_HPP

#include <platform/driver/touch/TouchController.hpp>

/**
 * @class MsTouchController
 *
 * @brief This class specializes TouchController Interface.
 *
 * @sa touchgfx::TouchController
 */

class MsTouchController : public touchgfx::TouchController
{
public:
    MsTouchController() : touch_fd(-1) {}

    /**
      * @fn virtual void MsTouchController::init() = 0;
      *
      * @brief Initializes touch controller.
      *
      *        Initializes touch controller.
      */
    void init();

    /**
    * @fn virtual bool MsTouchController::sampleTouch(int32_t& x, int32_t& y) = 0;
    *
    * @brief Checks whether the touch screen is being touched, and if so, what coordinates.
    *
    *        Checks whether the touch screen is being touched, and if so, what coordinates.
    *
    * @param [out] x The x position of the touch
    * @param [out] y The y position of the touch
    *
    * @return True if a touch has been detected, otherwise false.
    */
    bool sampleTouch(int32_t& x, int32_t& y);

private:
    int touch_fd;
};

#endif // MS_TOUCHGFX_TOUCH_HPP
