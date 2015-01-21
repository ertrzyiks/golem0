#include <Arduino.h>
#include "led.h"

void Led::on()
{
    this->writeDigital(HIGH);
}

void Led::setOn(bool state)
{
    if (state) {
        this->on();
    } else {
        this->off();
    }
}

void Led::off()
{
    this->writeDigital(LOW);
}
