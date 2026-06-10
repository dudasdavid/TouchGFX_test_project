#include <gui/screen1_screen/Screen1View.hpp>

extern "C"
{
    extern bool toggle_button_state; // Declare the variable to hold the state of the toggle button
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    toggleButton1.forceState(toggle_button_state);
    toggleButton1.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::function_toggle_pressed()
{
    // This function is called when the function toggle button is pressed.
    // You can add your custom code here to handle the button press event.
    presenter->function_toggle_pressed(toggleButton1.getState()); // Call the presenter function to handle the button press event
}

void Screen1View::updateBulbImage(bool state)
{
    // This function is called to update the bulb image state.
    // You can add your custom code here to update the bulb image based on the state variable.
    if (state)
    {
        // Update the bulb image to ON state
        imageBulbOff.setVisible(false);
        imageBulbOn.setVisible(true);
    }
    else
    {
        // Update the bulb image to OFF state
        imageBulbOff.setVisible(true);
        imageBulbOn.setVisible(false);
    }
    imageBulbOff.invalidate(); // Invalidate the image to trigger a redraw
    imageBulbOn.invalidate(); // Invalidate the image to trigger a redraw
}