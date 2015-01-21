#ifndef _golem0_output_pin_included
#define _golem0_output_pin_included

#include <Arduino.h>
#include "pin.h"

class OutputPin : public Pin
{
    public:
        OutputPin(int number) : Pin(number, OUTPUT) {};

        void writeDigital(int value);
        void writeAnalog(int value);
};

#endif
