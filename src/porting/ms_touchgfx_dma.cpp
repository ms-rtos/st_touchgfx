/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_dma.cpp TouchGFX DMA.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>

#include <ms_touchgfx_dma.hpp>

using namespace touchgfx;

/**
 * @fn MsDMA::MsDMA();
 *
 * @brief Default constructor.
 *
 *        Default constructor.
 */
MsDMA::MsDMA()
    : DMA_Interface(dma_queue), dma_queue(queue_storage, sizeof(queue_storage) / sizeof(queue_storage[0]))
{

}

/**
 * @fn MsDMA::~MsDMA();
 *
 * @brief Destructor.
 *
 *        Destructor.
 */
MsDMA::~MsDMA()
{

}

/**
 * @fn touchgfx::BlitOperations MsDMA::getBlitCaps();
 *
 * @brief Gets the blit capabilities.
 *
 *        Gets the blit capabilities.
 *
 *        This DMA supports a range of blit caps: BLIT_OP_COPY, BLIT_OP_COPY_ARGB8888,
 *        BLIT_OP_COPY_ARGB8888_WITH_ALPHA, BLIT_OP_COPY_A4, BLIT_OP_COPY_A8.
 *
 *
 * @return Currently supported blitcaps.
 */
touchgfx::BlitOperations MsDMA::getBlitCaps()
{
    return static_cast<BlitOperations>(BLIT_OP_FILL
                                       | BLIT_OP_FILL_WITH_ALPHA
                                       | BLIT_OP_COPY
                                       | BLIT_OP_COPY_WITH_ALPHA
                                       | BLIT_OP_COPY_ARGB8888
                                       | BLIT_OP_COPY_ARGB8888_WITH_ALPHA
                                       | BLIT_OP_COPY_A4
                                       | BLIT_OP_COPY_A8);
}

/**
 * @fn void MsDMA::initialize();
 *
 * @brief Perform hardware specific initialization.
 *
 *        Perform hardware specific initialization.
 */
void MsDMA::initialize()
{

}

/**
 * @fn void MsDMA::signalDMAInterrupt()
 *
 * @brief Raises a DMA interrupt signal.
 *
 *        Raises a DMA interrupt signal.
 */
void MsDMA::signalDMAInterrupt()
{
    executeCompleted();
}

/**
 * @fn void MsDMA::setupDataCopy(const touchgfx::BlitOp& blitOp);
 *
 * @brief Configures the DMA for copying data to the frame buffer.
 *
 *        Configures the DMA for copying data to the frame buffer.
 *
 * @param blitOp Details on the copy to perform.
 */
void MsDMA::setupDataCopy(const touchgfx::BlitOp& blitOp)
{
    /*
     * TODO
     */
    touchgfx::HAL::getInstance()->signalDMAInterrupt();
}

/**
 * @fn void MsDMA::setupDataFill(const touchgfx::BlitOp& blitOp);
 *
 * @brief Configures the DMA for "filling" the frame-buffer with a single color.
 *
 *        Configures the DMA for "filling" the frame-buffer with a single color.
 *
 * @param blitOp Details on the "fill" to perform.
 */
void MsDMA::setupDataFill(const touchgfx::BlitOp& blitOp)
{
    /*
     * TODO
     */
    touchgfx::HAL::getInstance()->signalDMAInterrupt();
}
