#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::function_toggle_pressed()
{
    // This function is called when the function toggle button is pressed.
    // You can add your custom code here to handle the button press event.
    model->function_toggle_pressed(); // Call the model function to handle the button press event
}

void Screen1Presenter::updateBulbImage(bool state)
{
    // This function is called to update the bulb image state.
    // You can add your custom code here to update the bulb image based on the state variable.
    view.updateBulbImage(state); // Call the view function to update the bulb image state
}