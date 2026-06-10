#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::slider_value_changed(int value)
{
    // This function is called when the slider value is changed.
    // You can add your custom code here to handle the slider value change event.
    model->slider_value_changed(value); // Call the model function to handle the slider value change event
}

void Screen2Presenter::updateGaugeValue(float value)
{
    // This function is called to update the gauge value.
    // You can add your custom code here to update the gauge based on the value variable.
    view.updateGaugeValue(value); // Call the view function to update the gauge value
}