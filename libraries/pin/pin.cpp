#include "pin.h"

Pin::Pin(int number, int mode)
{
    this->pinNumber = number;
    this->mode = mode;
}

void Pin::onSetup()
{
    pinMode(this->pinNumber, this->mode);
}
