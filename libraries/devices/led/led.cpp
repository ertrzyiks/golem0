#include <Arduino.h>
#include "led.h"

Led::Led(int pinNumber) : OutputPin(pinNumber)
{
    this->animation = new Animation();
    this->inIncreasing = false;
    this->isToggledOn = false;
}

Led::~Led()
{
    delete this->animation;
}

void Led::on()
{
    this->writeDigital(HIGH);
}

void Led::off()
{
    this->writeDigital(LOW);
}

void Led::toggle()
{
    if (this->isToggledOn) {
        this->writeDigital(LOW);
    } else {
        this->writeDigital(HIGH);
    }
}

void Led::isOn(bool state)
{
    if (state) {
        this->on();
    } else {
        this->off();
    }
}

bool Led::isOn()
{
    return this->isToggledOn;
}

void Led::writeDigital(int value)
{
    OutputPin::writeDigital(value);

    this->isToggledOn = (value > 0);
}

void Led::writeAnalog(int value)
{
    OutputPin::writeDigital(value);

    this->isToggledOn = (value == HIGH);
}

void Led::setBrightness(int value)
{
    this->writeAnalog(value);
}

void Led::fadeIn(long duration)
{
    this->inIncreasing = true;
    this->animation->setDuration(duration)->start();
}

void Led::fadeOut(long duration)
{
    this->inIncreasing = false;
    this->animation->setDuration(duration)->start();
}

void Led::tryThink(long currentTime)
{
    OutputPin::tryThink(currentTime);

    if (!this->animation->isRunning()) {
        return;
    }

    float progress = this->animation->update(currentTime);

    int brightnessProgress = ceil(progress * 255);

    if (this->inIncreasing) {
        this->setBrightness(brightnessProgress);
    } else {
        this->setBrightness(255 - brightnessProgress);
    }
}
