#include "animation.h"

Animation::Animation()
{
    this->startedAt = -1;
}

bool Animation::isRunning()
{
    return this->startedAt != -1;
}

Animation* Animation::setDuration(int value)
{
    this->duration = value;
    return this;
}

Animation* Animation::start()
{
    this->startedAt = millis();
    return this;
}

float Animation::update(long timestamp)
{
    if (this->startedAt == -1) {
        return 0.0;
    }

    long elapsedTime = timestamp - this->startedAt;
    float elapsedProgress = elapsedTime * 1.0 / this->duration;

    if (elapsedProgress >= 1.0) {
        this->startedAt = -1;
        return 1.0;
    }

    return elapsedProgress;
}
