#include <Arduino.h>
#include "button.h"

Button::Button(int pinNumber) : InputPin(pinNumber)
{
    this->updatePullUpDownSettings();
}

void Button::tryThink(long currentTime)
{
    InputPin::tryThink(currentTime);

    int currentState = this->readDigital();

    if (currentState != this->lastState) {
        if (currentState == this->keyDownState) {
             this->onKeyDown();
        } else {
             this->onKeyUp();
        }

        this->lastState = currentState;
    }
}

void Button::updatePullUpDownSettings()
{
    bool isPullUp = this->isPullUp();
    this->keyDownState = isPullUp ? LOW : HIGH;
    this->lastState = isPullUp ? HIGH : LOW;
}

void Button::onPullUpChange(bool state)
{
    this->updatePullUpDownSettings();
}

void Button::onKeyDown()
{
    //Do nothing by default
}

void Button::onKeyUp()
{
    //Do nothing by default
}
