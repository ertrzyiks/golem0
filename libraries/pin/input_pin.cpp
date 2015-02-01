#include "input_pin.h"
#include "../core/log.h"

InputPin::InputPin(int pinNumber) : Pin(pinNumber, INPUT)
{

}

int InputPin::readDigital()
{
    return digitalRead(this->pinNumber);
}

int InputPin::readAnalog()
{
    return analogRead(this->pinNumber);
}

void InputPin::isPullUp(bool state)
{
    if (this->didSetup) {
        Golem0LogError("Setting pull up option has no effect after setup, try change it in world_init()");
        return;
    }

    if (state) {
        this->mode = INPUT_PULLUP;
    } else {
        this->mode = INPUT;
    }
};

bool InputPin::isPullUp()
{
    return (this->mode == INPUT_PULLUP);
};
