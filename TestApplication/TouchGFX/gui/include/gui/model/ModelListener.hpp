#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateBulbImage(bool state) {} // virtual function to update the bulb image state
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
