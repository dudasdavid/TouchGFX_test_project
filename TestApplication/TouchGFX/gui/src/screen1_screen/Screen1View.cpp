#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::function_toggle_pressed()
{
    // This function is called when the function toggle button is pressed.
    // You can add your custom code here to handle the button press event.
    presenter->function_toggle_pressed(); // Call the presenter function to handle the button press event
}