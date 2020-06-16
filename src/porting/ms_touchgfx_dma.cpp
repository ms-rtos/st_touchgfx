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

#include <ms_rtos.h>

#include <touchgfx/hal/OSWrappers.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>

#include <ms_touchgfx_dma.hpp>

using namespace touchgfx;

extern int ms_tgfx_fb_fd;
extern ms_fb_var_screeninfo_t ms_tgfx_fb_var_info;
extern ms_fb_fix_screeninfo_t ms_tgfx_fb_fix_info;

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
    blit_caps = ms_tgfx_fb_fix_info.capability & ~MS_FB_CAP_DOUBLE_FB;

    ms_semb_create("tgfx_dma2d_semb", MS_FALSE, MS_WAIT_TYPE_PRIO, &sembid);
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
    ms_semb_destroy(sembid);
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
    return static_cast<BlitOperations>(blit_caps);
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
    ms_fb_data_copy_arg_t dca;

    dca.operation       = (ms_fb_blitop_t)blitOp.operation;
    dca.src             = blitOp.pSrc;
    dca.clut            = blitOp.pClut;
    dca.dst             = blitOp.pDst;
    dca.steps           = blitOp.nSteps;
    dca.loops           = blitOp.nLoops;
    dca.src_loop_stride = blitOp.srcLoopStride;
    dca.dst_loop_stride = blitOp.dstLoopStride;
    dca.color           = blitOp.color.getColor32();
    dca.alpha           = blitOp.alpha;
    dca.src_fmt         = blitOp.srcFormat;
    dca.dst_fmt         = blitOp.dstFormat;
    dca.sembid          = sembid;

    ms_io_ioctl(ms_tgfx_fb_fd, MS_FB_CMD_DATA_COPY_OP, &dca);

    ms_semb_wait(sembid, MS_TIMEOUT_FOREVER);

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
    ms_fb_data_fill_arg_t dfa;

    dfa.operation       = (ms_fb_blitop_t)blitOp.operation;
    dfa.src             = blitOp.pSrc;
    dfa.clut            = blitOp.pClut;
    dfa.dst             = blitOp.pDst;
    dfa.steps           = blitOp.nSteps;
    dfa.loops           = blitOp.nLoops;
    dfa.src_loop_stride = blitOp.srcLoopStride;
    dfa.dst_loop_stride = blitOp.dstLoopStride;
    dfa.color           = blitOp.color.getColor32();
    dfa.alpha           = blitOp.alpha;
    dfa.src_fmt         = blitOp.srcFormat;
    dfa.dst_fmt         = blitOp.dstFormat;
    dfa.sembid          = sembid;

    ms_io_ioctl(ms_tgfx_fb_fd, MS_FB_CMD_DATA_FILL_OP, &dfa);

    ms_semb_wait(sembid, MS_TIMEOUT_FOREVER);

    touchgfx::HAL::getInstance()->signalDMAInterrupt();
}
