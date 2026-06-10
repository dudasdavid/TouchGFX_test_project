#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C"
{
    extern void toggle_led_touch_button(void); // Declare the function to toggle the LED when the touch button is pressed
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::function_toggle_pressed()
{
    // This function is called when the function toggle button is pressed.
    // You can add your custom code here to handle the button press event.
    toggle_led_touch_button(); // Call the function to toggle the LED when the touch button is pressed
}