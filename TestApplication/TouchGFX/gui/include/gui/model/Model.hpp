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
    void function_toggle_pressed(); // function to handle toggle button press event
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
