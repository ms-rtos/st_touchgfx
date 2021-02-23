/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/progress_indicators/BoxProgress.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Button button1;
    touchgfx::BoxProgress boxProgress1;
    touchgfx::RadioButton radioButton1;
    touchgfx::TextArea textArea1;
    touchgfx::RadioButtonGroup<1> radioButtonGroup1;

private:

};

#endif // SCREEN1VIEWBASE_HPP
