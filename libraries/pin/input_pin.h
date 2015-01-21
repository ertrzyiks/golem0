#ifndef _golem0_input_pin_included
#define _golem0_input_pin_included

#include <Arduino.h>
#include "pin.h"

class InputPin : public Pin
{
    public:
        InputPin(int number) : Pin(number, INPUT) {};

        void isPullUp(bool state);

        int readDigital();
        int readAnalog();
};

#endif
