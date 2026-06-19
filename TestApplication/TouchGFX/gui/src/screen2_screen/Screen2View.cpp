#include <gui/screen2_screen/Screen2View.hpp>
#include <algorithm>

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

    clearGraphs();
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

void Screen2View::updateGraphValue(float value1, float value2)
{

    if (graphPointCount >= MAX_GRAPH_POINTS)
    {
        clearGraphs();
    }

    // This function is called to update the graph value.
    // You can add your custom code here to update the graph based on the value variable.
    dynamicGraph1.addDataPoint(value1); // Add a new data point to the graph
    dynamicGraph2.addDataPoint(value2); // Add a new data point to the graph

    graphPointCount++;

    updateSharedGraphRange();

    dynamicGraph1.invalidate(); // Invalidate the graph to trigger a redraw
    dynamicGraph2.invalidate();
}

void Screen2View::updateSharedGraphRange()
{
    constexpr int Y_MARGIN = 1;

    // Temporarily calculate the required range for each dataset
    dynamicGraph1.setGraphRangeYAuto(false, Y_MARGIN);
    dynamicGraph2.setGraphRangeYAuto(false, Y_MARGIN);

    // Find the range that contains both graphs
    const int commonMin = std::min(
        dynamicGraph1.getGraphRangeYMinAsInt(),
        dynamicGraph2.getGraphRangeYMinAsInt()
    );

    const int commonMax = std::max(
        dynamicGraph1.getGraphRangeYMaxAsInt(),
        dynamicGraph2.getGraphRangeYMaxAsInt()
    );

    // Give both overlaid graphs exactly the same Y-axis scale
    dynamicGraph1.setGraphRangeY(commonMin, commonMax);
    dynamicGraph2.setGraphRangeY(commonMin, commonMax);
}

void Screen2View::clearGraphs()
{
    dynamicGraph1.clear();
    dynamicGraph2.clear();

    graphPointCount = 0;

    dynamicGraph1.invalidate();
    dynamicGraph2.invalidate();
}