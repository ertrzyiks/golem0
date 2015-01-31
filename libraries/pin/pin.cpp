#include "pin.h"

Pin::Pin(int number, int mode)
{
    this->pinNumber = number;
    this->mode = mode;
    this->didSetup = false;
}

void Pin::onSetup()
{
    pinMode(this->pinNumber, this->mode);
    this->didSetup = true;
}
