#*********************************************************************************************************
#
#                                 北京翼辉信息技术有限公司
#
#                                   微型安全实时操作系统
#
#                                       MS-RTOS(TM)
#
#                               Copyright All Rights Reserved
#
#--------------文件信息--------------------------------------------------------------------------------
#
# 文   件   名: touchgfx.mk
#
# 创   建   人: IoT Studio
#
# 文件创建日期: 2020 年 03 月 02 日
#
# 描        述: 本文件由 IoT Studio 生成，用于配置 Makefile 功能，请勿手动修改
#*********************************************************************************************************

#*********************************************************************************************************
# Clear setting
#*********************************************************************************************************
include $(CLEAR_VARS_MK)

#*********************************************************************************************************
# Target
#*********************************************************************************************************
LOCAL_TARGET_NAME := touchgfx

#*********************************************************************************************************
# Source list
#*********************************************************************************************************
LOCAL_SRCS :=  \
src/app/TouchGFX/App/app_touchgfx.c \
src/app/TouchGFX/generated/fonts/src/ApplicationFontProvider.cpp \
src/app/TouchGFX/generated/fonts/src/CachedFont.cpp \
src/app/TouchGFX/generated/fonts/src/FontCache.cpp \
src/app/TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.cpp \
src/app/TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.cpp \
src/app/TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.cpp \
src/app/TouchGFX/generated/fonts/src/GeneratedFont.cpp \
src/app/TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.cpp \
src/app/TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.cpp \
src/app/TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.cpp \
src/app/TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.cpp \
src/app/TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.cpp \
src/app/TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.cpp \
src/app/TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.cpp \
src/app/TouchGFX/generated/gui_generated/src/screen1_screen/Screen1ViewBase.cpp \
src/app/TouchGFX/generated/images/src/BitmapDatabase.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Buttons_Round_Edge_small.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Buttons_Round_Edge_small_pressed.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_active.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_inactive.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_normal.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_pressed.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_ProgressIndicators_bg_medium_progress_indicator_bg_square_0_degrees.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_ProgressIndicators_fill_tiling_progress_indicator_fill_striped_normal_horizontal.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Togglebars_Toggle_round_large_button_OFF.cpp \
src/app/TouchGFX/generated/images/src/__designer/Blue_Togglebars_Toggle_round_large_button_ON.cpp \
src/app/TouchGFX/generated/texts/src/LanguageGb.cpp \
src/app/TouchGFX/generated/texts/src/Texts.cpp \
src/app/TouchGFX/generated/texts/src/TypedTextDatabase.cpp \
src/app/TouchGFX/gui/src/common/FrontendApplication.cpp \
src/app/TouchGFX/gui/src/model/Model.cpp \
src/app/TouchGFX/gui/src/screen1_screen/Screen1Presenter.cpp \
src/app/TouchGFX/gui/src/screen1_screen/Screen1View.cpp \
src/porting/ms_touchgfx_configuration.cpp \
src/porting/ms_touchgfx_dma.cpp \
src/porting/ms_touchgfx_gpio.cpp \
src/porting/ms_touchgfx_hal.cpp \
src/porting/ms_touchgfx_os_wrappers.cpp \
src/porting/ms_touchgfx_touch.cpp \
src/main.c

#*********************************************************************************************************
# Header file search path (eg. LOCAL_INC_PATH := -I"Your header files search path")
#*********************************************************************************************************
LOCAL_INC_PATH := \
-I./src/ST/touchgfx/framework/include \
-I./src/porting \
-I./src/app/TouchGFX/gui/include \
-I./src/app/TouchGFX/generated/gui_generated/include \
-I./src/app/TouchGFX/generated/fonts/include \
-I./src/app/TouchGFX/generated/images/include \
-I./src/app/TouchGFX/generated/texts/include \
-I./src/app/TouchGFX/App/generated \
-I./src/app/TouchGFX/App

#*********************************************************************************************************
# Pre-defined macro (eg. -DYOUR_MARCO=1)
#*********************************************************************************************************
LOCAL_DSYMBOL :=

#*********************************************************************************************************
# Compiler flags
#*********************************************************************************************************
LOCAL_CFLAGS   := 
LOCAL_CXXFLAGS := 
LOCAL_LINKFLAGS := 

#*********************************************************************************************************
# Depend library (eg. LOCAL_DEPEND_LIB := -la LOCAL_DEPEND_LIB_PATH := -L"Your library search path")
#*********************************************************************************************************
LOCAL_DEPEND_LIB      := -ltouchgfx
LOCAL_DEPEND_LIB_PATH := -L"./src/ST/touchgfx/lib/core/cortex_m4f/gcc"

#*********************************************************************************************************
# C++ config
#*********************************************************************************************************
LOCAL_USE_CXX        := yes
LOCAL_USE_CXX_EXCEPT := no

#*********************************************************************************************************
# Code coverage config
#*********************************************************************************************************
LOCAL_USE_GCOV := no

#*********************************************************************************************************
# Stack check config
#*********************************************************************************************************
LOCAL_USE_STACK_CHECK := no

#*********************************************************************************************************
# User link command
#*********************************************************************************************************
LOCAL_PRE_LINK_CMD   := 
LOCAL_POST_LINK_CMD  := 
LOCAL_PRE_STRIP_CMD  := 
LOCAL_POST_STRIP_CMD := 

#*********************************************************************************************************
# Depend target
#*********************************************************************************************************
LOCAL_DEPEND_TARGET := 

include $(APPLICATION_MK)

#*********************************************************************************************************
# End
#*********************************************************************************************************
