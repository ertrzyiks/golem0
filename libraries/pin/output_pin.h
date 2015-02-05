#ifndef _golem0_output_pin_included
#define _golem0_output_pin_included

#include <Arduino.h>
#include "pin.h"

class OutputPin : public Pin
{
    public:
        OutputPin(int pinNumber);

        virtual void writeDigital(int value);
        virtual void writeAnalog(int value);
};

#endif
