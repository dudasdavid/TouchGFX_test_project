#include <stdint.h>
#include <stdbool.h>
#include <cmath>
#include <chrono>
#include <cstdio>

extern "C"
{
    // These types must exactly match the declarations used by Model.cpp
    uint8_t slider_value = 42U;
    uint8_t bulb_image_state = 0U;
    bool toggle_button_state = false;
    float gauge_value = 55.0f;

    float measured_value = 0.0f;
    float measured_average_1s = 0.0f;
    uint32_t measured_average_sequence = 0U;

    void toggle_led_touch_button(bool state);
    void simulator_fake_backend_tick(void);
}

static uint32_t noise_seed = 123456789U;

static float random_noise(float amplitude)
{
    noise_seed = noise_seed * 1664525U + 1013904223U;

    const float normalized =
        static_cast<float>(noise_seed & 0xFFFFU) / 65535.0f;

    return (normalized * 2.0f - 1.0f) * amplitude;
}

extern "C" void toggle_led_touch_button(bool state)
{
    toggle_button_state = state;
}

extern "C" void simulator_fake_backend_tick(void)
{
    using Clock = std::chrono::steady_clock;

    static Clock::time_point previousMeasurementTime = Clock::now();
    static Clock::time_point previousGaugeTime = Clock::now();

    static float measurementSum = 0.0f;
    static uint8_t measurementCount = 0U;
    static float phase = 0.0f;

    constexpr float noiseAmplitude = 0.1f;
    constexpr float phaseIncrement = 0.01f;

    const Clock::time_point currentTime = Clock::now();

    /*
     * Fake measurement task: every 50 ms
     */
    while ((currentTime - previousMeasurementTime) >=
           std::chrono::milliseconds(50))
    {
        previousMeasurementTime += std::chrono::milliseconds(50);

        const float measurementInput =
            phase + random_noise(noiseAmplitude);

        measured_value =
            std::sin(measurementInput) * 10.0f;

        measurementSum += measured_value;
        measurementCount++;

        if (measurementCount >= 20U)
        {
            measured_average_1s =
                measurementSum /
                static_cast<float>(measurementCount);

            measurementSum = 0.0f;
            measurementCount = 0U;

            phase += phaseIncrement;

            measured_average_sequence++;
        }
    }

    /*
     * Fake StartTestTask: every 100 ms
     */
    while ((currentTime - previousGaugeTime) >=
           std::chrono::milliseconds(100))
    {
        previousGaugeTime += std::chrono::milliseconds(100);

        gauge_value =
            static_cast<float>(slider_value) * 1.2f;

        std::printf(
            "Test task is running... Slider: %u, Gauge: %.1f\n",
            static_cast<unsigned int>(slider_value),
            static_cast<double>(gauge_value)
        );
    }
}