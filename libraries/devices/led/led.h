#ifndef _golem0_led_included
#define _golem0_led_included

#include "../../pin/output_pin.h"

class Led : public OutputPin
{
    public:
        Led(int number) : OutputPin(number) {};

        void on();
        void off();

        void setOn(bool state);
};

#endif
