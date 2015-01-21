#include "output_pin.h"

void OutputPin::writeDigital(int value)
{
    digitalWrite(this->pinNumber, value);
}

void OutputPin::writeAnalog(int value)
{
    analogWrite(this->pinNumber, value);
}
