#ifndef _golem0_pin_controller_included
#define _golem0_pin_controller_included

#include <Arduino.h>

class PinController : public Entity
{
    protected:
        int pinNumber;
        int mode;

    public:
        PinController(int number, int mode);

        void onSetup();
        void writeDigital(int value);
        void writeAnalog(int value);
};

#endif
