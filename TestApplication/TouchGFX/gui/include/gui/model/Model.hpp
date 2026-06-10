#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void function_toggle_pressed(bool state); // function to handle toggle button press event
    void slider_value_changed(int value); // function to handle slider value change event
    
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
