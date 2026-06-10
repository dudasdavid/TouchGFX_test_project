#include <stdint.h>
#include <stdbool.h>

extern "C"
{
    int slider_value = 42;
    bool toggle_button_state = false;
    int bulb_image_state = 0;
    int gauge_value = 55;

    // Declaration first, because TouchGFX treats missing declarations as errors
    void toggle_led_touch_button(bool state);

    void toggle_led_touch_button(bool state)
    {
        toggle_button_state = state;
    }
}