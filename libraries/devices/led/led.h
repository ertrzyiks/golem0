#ifndef _golem0_led_included
#define _golem0_led_included

#include "../../pin/output_pin.h"

class Led : public OutputPin
{
    public:
        Led(int pinNumber);

        void on();
        void off();

        void setOn(bool state);

        void setBrightness(int value);
};

#endif
