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
# 文   件   名: touchgfx_demo.mk
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
LOCAL_TARGET_NAME := touchgfx_demo

#*********************************************************************************************************
# Source list
#*********************************************************************************************************
LOCAL_SRCS :=  \
src/demo/TouchGFX/App/app_touchgfx.c \
src/demo/TouchGFX/generated/fonts/src/ApplicationFontProvider.cpp \
src/demo/TouchGFX/generated/fonts/src/CachedFont.cpp \
src/demo/TouchGFX/generated/fonts/src/FontCache.cpp \
src/demo/TouchGFX/generated/fonts/src/Font_verdana_10_4bpp_0.cpp \
src/demo/TouchGFX/generated/fonts/src/Font_verdana_20_4bpp_0.cpp \
src/demo/TouchGFX/generated/fonts/src/Font_verdana_40_4bpp_0.cpp \
src/demo/TouchGFX/generated/fonts/src/GeneratedFont.cpp \
src/demo/TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.cpp \
src/demo/TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.cpp \
src/demo/TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.cpp \
src/demo/TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.cpp \
src/demo/TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.cpp \
src/demo/TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.cpp \
src/demo/TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.cpp \
src/demo/TouchGFX/generated/gui_generated/src/screen1_screen/Screen1ViewBase.cpp \
src/demo/TouchGFX/generated/images/src/BitmapDatabase.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Buttons_Round_Edge_small.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Buttons_Round_Edge_small_pressed.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_active.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_inactive.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_normal.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Check_buttons_Check_mark_pressed.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_ProgressIndicators_bg_medium_progress_indicator_bg_square_0_degrees.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_ProgressIndicators_fill_tiling_progress_indicator_fill_striped_normal_horizontal.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Togglebars_Toggle_round_large_button_OFF.cpp \
src/demo/TouchGFX/generated/images/src/__designer/Blue_Togglebars_Toggle_round_large_button_ON.cpp \
src/demo/TouchGFX/generated/texts/src/LanguageGb.cpp \
src/demo/TouchGFX/generated/texts/src/Texts.cpp \
src/demo/TouchGFX/generated/texts/src/TypedTextDatabase.cpp \
src/demo/TouchGFX/gui/src/common/FrontendApplication.cpp \
src/demo/TouchGFX/gui/src/model/Model.cpp \
src/demo/TouchGFX/gui/src/screen1_screen/Screen1Presenter.cpp \
src/demo/TouchGFX/gui/src/screen1_screen/Screen1View.cpp \
src/demo/ms_touchgfx_configuration.cpp \
src/demo/main.c

#*********************************************************************************************************
# Header file search path (eg. LOCAL_INC_PATH := -I"Your header files search path")
#*********************************************************************************************************
LOCAL_INC_PATH := \
-I"$(MSRTOS_BASE_PATH)/st_touchgfx/src/ST/touchgfx/framework/include" \
-I"$(MSRTOS_BASE_PATH)/st_touchgfx/src/porting" \
-I"./src/demo/TouchGFX/gui/include" \
-I"./src/demo/TouchGFX/generated/gui_generated/include" \
-I"./src/demo/TouchGFX/generated/fonts/include" \
-I"./src/demo/TouchGFX/generated/images/include" \
-I"./src/demo/TouchGFX/generated/texts/include" \
-I"./src/demo/TouchGFX/App/generated" \
-I"./src/demo/TouchGFX/App"

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
LOCAL_DEPEND_LIB      :=
LOCAL_DEPEND_LIB_PATH :=

ifeq ($(FLOAT_ABI), softfp)
LOCAL_DEPEND_LIB      += -ltouchgfx
else 
LOCAL_DEPEND_LIB      += -ltouchgfx-float-abi-hard
endif

ifeq ($(CPU_TYPE), cortex-m4)
LOCAL_DEPEND_LIB_PATH += -L"$(MSRTOS_BASE_PATH)/st_touchgfx/src/ST/touchgfx/lib/core/cortex_m4f/gcc"
else 
LOCAL_DEPEND_LIB_PATH += -L"$(MSRTOS_BASE_PATH)/st_touchgfx/src/ST/touchgfx/lib/core/cortex_m7/gcc"
endif

LOCAL_DEPEND_LIB      += -ltouchgfx_port
LOCAL_DEPEND_LIB_PATH += -L"$(MSRTOS_BASE_PATH)/st_touchgfx/$(OUTDIR)"

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
LOCAL_DEPEND_TARGET := $(OUTDIR)/libtouchgfx_port.a

include $(APPLICATION_MK)

#*********************************************************************************************************
# End
#*********************************************************************************************************
