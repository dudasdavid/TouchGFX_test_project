#include <gui/screen2_screen/Screen2View.hpp>

extern "C"
{
    extern uint8_t slider_value; // Declare the variable to hold the value of the slider
}

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

    slider1.setValue(slider_value);
    slider1.invalidate();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::function_slider_changed(int value)
{
    //int value = slider1.getValue();
    presenter->slider_value_changed(value); // Call the presenter function to handle the slider value change event

    // use value here
}

void Screen2View::updateGaugeValue(float value)
{
    // This function is called to update the gauge value.
    // You can add your custom code here to update the gauge based on the value variable.
    gauge1.setValue(value); // Update the gauge value
    gauge1.invalidate(); // Invalidate the gauge to trigger a redraw
}