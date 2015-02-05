#include <Arduino.h>
#include "led.h"

Led::Led(int pinNumber) : OutputPin(pinNumber)
{
    this->animation = new Animation();
    this->inIncreasing = false;
}

Led::~Led()
{
    delete this->animation;
}

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
