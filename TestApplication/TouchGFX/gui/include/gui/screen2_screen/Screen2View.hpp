#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void function_slider_changed(int value) override; // override virtual function from Screen2ViewBase
    void updateGaugeValue(float value); // function to update the gauge value
    void updateGraphValue(uint16_t value); // function to update the graph value
protected:
};

#endif // SCREEN2VIEW_HPP
