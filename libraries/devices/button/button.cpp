#include <Arduino.h>
#include "button.h"

void Button::tryThink(long currentTime)
{
    Pin::tryThink(currentTime);
}
