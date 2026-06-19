#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    uint32_t lastGraphSequence;

    virtual void updateBulbImage(bool state) {} // virtual function to update the bulb image state
    virtual void updateGaugeValue(float value) {} // virtual function to update the gauge value
    virtual void updateGraphValue(float value1, float value2) {} // virtual function to update the graph value
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
