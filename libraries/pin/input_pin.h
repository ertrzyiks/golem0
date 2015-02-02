#ifndef _golem0_input_pin_included
#define _golem0_input_pin_included

#include <Arduino.h>
#include "pin.h"

class InputPin : public Pin
{
    protected:
        virtual void onPullUpChange(bool state);

    public:
        InputPin(int pinNumber);

        void isPullUp(bool state);
        bool isPullUp();

        int readDigital();
        int readAnalog();
};

#endif
