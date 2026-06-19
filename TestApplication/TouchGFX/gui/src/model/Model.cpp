#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdint.h>

extern "C"
{
    extern uint8_t bulb_image_state; // Declare the variable to hold the state of the bulb image 
    extern uint8_t slider_value; // Declare the variable to hold the value of the slider
    extern float gauge_value; // Declare the variable to hold the value of the gauge
    extern void toggle_led_touch_button(bool state); // Declare the function to toggle the LED when the touch button is pressed
    extern float measured_value; // Declare the variable to hold the value of the graph
    extern float measured_average_1s; // Declare the variable to hold the average value of the graph over 1 second
    extern uint32_t measured_average_sequence; // Declare the variable to hold the sequence number of the measured average

#ifdef SIMULATOR
    void simulator_fake_backend_tick(void);
#endif
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

#ifdef SIMULATOR
    simulator_fake_backend_tick();
#endif

    if (bulb_image_state)
    {
        modelListener->updateBulbImage(true); // Update the bulb image to ON state
    }
    else
    {
        modelListener->updateBulbImage(false); // Update the bulb image to OFF state
    }
    modelListener->updateGaugeValue(gauge_value); // Update the gauge value

    // Update the chart only when a new 1-second average exists
    const uint32_t currentSequence = measured_average_sequence;

    if (currentSequence != modelListener->lastGraphSequence)
    {
        modelListener->lastGraphSequence = currentSequence;
        modelListener->updateGraphValue(measured_average_1s, measured_value);
    }


}

void Model::function_toggle_pressed(bool state)
{
    // This function is called when the function toggle button is pressed.
    // You can add your custom code here to handle the button press event.
    toggle_led_touch_button(state); // Call the function to toggle the LED when the touch button is pressed
}

void Model::slider_value_changed(int value)
{
    // This function is called when the slider value is changed.
    // You can add your custom code here to handle the slider value change event.
    slider_value = value; // Update the slider value variable with the new value
}