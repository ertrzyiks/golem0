#include <Arduino.h>
#include "button.h"


Button::Button(int number) : InputPin(number)
{
    this->lastState = LOW;
}

void Button::tryThink(long currentTime)
{
    InputPin::tryThink(currentTime);

    int currentState = this->readDigital();

    if(currentState != this->lastState) {
        if (currentState == HIGH) {
             this->onKeyDown();
        } else {
             this->onKeyUp();
        }

        this->lastState = currentState;
    }
}


void Button::onKeyDown()
{
    //Do nothing by default
}

void Button::onKeyUp()
{
    //Do nothing by default
}
