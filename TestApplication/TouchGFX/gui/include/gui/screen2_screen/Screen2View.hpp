#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

    virtual void function_slider_changed(int value) override; // override virtual function from Screen2ViewBase
    void updateGaugeValue(float value); // function to update the gauge value
    void updateGraphValue(float value1, float value2); // function to update the graph value

private:
    static constexpr uint16_t MAX_GRAPH_POINTS = 1000;
    uint16_t graphPointCount = 0;
    void updateSharedGraphRange(); // function to update the shared graph range
    void clearGraphs(); // function to clear the graphs
    int progressValue = 0;

protected:
};

#endif // SCREEN2VIEW_HPP
