#ifndef _golem0_button_included
#define _golem0_button_included

#include "../../pin/input_pin.h"

class Button : public InputPin
{
    public:
        Button(int number) : InputPin(number) {};

        void tryThink(long currentTime);
};

#endif
