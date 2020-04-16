/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_configuration.cpp TouchGFX configuration.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#include <texts/TypedTextDatabase.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <BitmapDatabase.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <platform/driver/lcd/LCD24bpp.hpp>
#include <platform/driver/lcd/LCD32bpp.hpp>
#include <ms_touchgfx_dma.hpp>
#include <touchgfx/hal/NoDMA.hpp>
#include <ms_touchgfx_hal.hpp>
#include <ms_touchgfx_touch.hpp>

extern "C" void touchgfx_init();
extern "C" void touchgfx_taskEntry();

static MsTouchController tc;
static touchgfx::NoDMA dma; //For windows/linux, DMA transfers are simulated
static LCD32bpp display;
static ApplicationFontProvider fontProvider;
static Texts texts;
static TouchGFXHAL hal(dma, display, tc, 480, 272);

void touchgfx_init()
{
    Bitmap::registerBitmapDatabase(BitmapDatabase::getInstance(), BitmapDatabase::getInstanceSize());
    TypedText::registerTexts(&texts);
    Texts::setLanguage(0);

    FontManager::setFontProvider(&fontProvider);

    FrontendHeap& heap = FrontendHeap::getInstance();
    (void)heap; // we need to obtain the reference above to initialize the frontend heap.

    hal.initialize();
}

void touchgfx_taskEntry()
{
    /*
     * Main event loop. Will wait for VSYNC signal, and then process next frame. Call
     * this function from your GUI task.
     *
     * Note This function never returns
     */
    hal.taskEntry();
}

extern "C" uint32_t CRC_Lock(void)
{
    return (uint32_t)CRC_Lock;
}
