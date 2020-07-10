/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_touchgfx_dma.hpp TouchGFX DMA.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#ifndef MS_DMA_HPP
#define MS_DMA_HPP

#include <touchgfx/hal/DMA.hpp>

/**
 * @class MsDMA
 *
 * @brief This class specializes DMA_Interface for the MS-RTOS.
 *
 * @sa touchgfx::DMA_Interface
 */
class MsDMA : public touchgfx::DMA_Interface
{
    /**
     * @typedef touchgfx::DMA_Interface Base
     *
     * @brief Defines an alias representing the base.
     *
     Defines an alias representing the base.
     */
    typedef touchgfx::DMA_Interface Base;
public:
    /**
     * @fn MsDMA::MsDMA();
     *
     * @brief Default constructor.
     *
     *        Default constructor.
     */
    MsDMA();

    /**
     * @fn MsDMA::~MsDMA();
     *
     * @brief Destructor.
     *
     *        Destructor.
     */
    ~MsDMA();

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
    touchgfx::BlitOperations getBlitCaps();

    /**
     * @fn void MsDMA::initialize();
     *
     * @brief Perform hardware specific initialization.
     *
     *        Perform hardware specific initialization.
     */
    void initialize();

    /**
     * @fn void MsDMA::signalDMAInterrupt()
     *
     * @brief Raises a DMA interrupt signal.
     *
     *        Raises a DMA interrupt signal.
     */
    void signalDMAInterrupt();

protected:
    /**
     * @fn void MsDMA::setupDataCopy(const touchgfx::BlitOp& blitOp);
     *
     * @brief Configures the DMA for copying data to the frame buffer.
     *
     *        Configures the DMA for copying data to the frame buffer.
     *
     * @param blitOp Details on the copy to perform.
     */
    void setupDataCopy(const touchgfx::BlitOp& blitOp);

    /**
     * @fn void MsDMA::setupDataFill(const touchgfx::BlitOp& blitOp);
     *
     * @brief Configures the DMA for "filling" the frame-buffer with a single color.
     *
     *        Configures the DMA for "filling" the frame-buffer with a single color.
     *
     * @param blitOp Details on the "fill" to perform.
     */
    void setupDataFill(const touchgfx::BlitOp& blitOp);

private:
    touchgfx::LockFreeDMA_Queue dma_queue;
    touchgfx::BlitOp            queue_storage[96];
    ms_uint32_t                 blit_caps;
    ms_handle_t                 sembid;
};

#endif // MS_DMA_HPP
