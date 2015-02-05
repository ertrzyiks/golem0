#include <Arduino.h>
#include "button.h"

Button::Button(int pinNumber) : InputPin(pinNumber)
{
    this->debounceTime = 50;
    this->updatePullUpDownSettings();
}

void Button::setDebounceTime(long debounceTime)
{
    this->debounceTime = debounceTime;
}

long Button::getDebounceTime()
{
    return this->debounceTime;
}

void Button::tryThink(long currentTime)
{
    InputPin::tryThink(currentTime);

    int currentState = this->readDigital();

    if (currentState != this->lastReadState) {
        this->lastStateChangeTime = currentTime;
    } else if ((currentTime - this->lastStateChangeTime) > this->debounceTime) {
        if (currentState != this->buttonState) {
            this->buttonState = currentState;
            this->onStateChange(currentState);
        }
    }

    this->lastReadState = currentState;
}
void Button::onStateChange(bool buttonState)
{
    if (buttonState == this->keyDownState) {
        this->onKeyDown();
    } else {
         this->onKeyUp();
    }
}

void Button::updatePullUpDownSettings()
{
    bool isPullUp = this->isPullUp();
    this->keyDownState = isPullUp ? LOW : HIGH;
    this->lastReadState = isPullUp ? HIGH : LOW;
    this->buttonState = this->lastReadState;
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
