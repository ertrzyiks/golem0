#include "pin_controller.h"

PinController::PinController(int number, int mode)
{
    this->pinNumber = number;
    this->mode = mode;
}

void PinController::onSetup()
{
    pinMode(this->pinNumber, this->mode);
}

void PinController::writeDigital(int value)
{
    digitalWrite(this->pinNumber, value);
}

void PinController::writeAnalog(int value)
{
    analogWrite(this->pinNumber, value);
}
