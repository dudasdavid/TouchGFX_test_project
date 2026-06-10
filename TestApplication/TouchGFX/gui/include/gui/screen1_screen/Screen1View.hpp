#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void function_toggle_pressed() override; // override virtual function from Screen1ViewBase
    void updateBulbImage(bool state); // function to update the bulb image state
protected:
};

#endif // SCREEN1VIEW_HPP
