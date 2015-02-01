#include "output_pin.h"

OutputPin::OutputPin(int pinNumber) : Pin(pinNumber, OUTPUT)
{

}

void OutputPin::writeDigital(int value)
{
    digitalWrite(this->pinNumber, value);
}

void OutputPin::writeAnalog(int value)
{
    analogWrite(this->pinNumber, value);
}
