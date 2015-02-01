#include "pin.h"

Pin::Pin(int pinNumber, int mode)
{
    this->pinNumber = pinNumber;
    this->mode = mode;
    this->didSetup = false;
}

void Pin::onSetup()
{
    pinMode(this->pinNumber, this->mode);
    this->didSetup = true;
}
