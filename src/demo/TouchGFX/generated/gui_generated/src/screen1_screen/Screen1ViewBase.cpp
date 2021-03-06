/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase()
{

    button1.setXY(130, 68);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));

    boxProgress1.setXY(99, 158);
    boxProgress1.setProgressIndicatorPosition(2, 2, 180, 16);
    boxProgress1.setRange(0, 100);
    boxProgress1.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    boxProgress1.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID));
    boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 151, 255));
    boxProgress1.setValue(60);

    radioButton1.setXY(332, 24);
    radioButton1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_MARK_NORMAL_ID));
    radioButton1.setSelected(false);
    radioButton1.setDeselectionEnabled(false);

    textArea1.setXY(17, 21);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID1));

    add(button1);
    add(boxProgress1);
    add(radioButton1);
    add(textArea1);
    radioButtonGroup1.add(radioButton1);
}

void Screen1ViewBase::setupScreen()
{

}
