#include "input_pin.h"

int InputPin::readDigital()
{
    return digitalRead(this->pinNumber);
}

int InputPin::readAnalog()
{
    return analogRead(this->pinNumber);
}
