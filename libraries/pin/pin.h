#ifndef _golem0_pin_included
#define _golem0_pin_included

#include <Arduino.h>

class Pin : public Entity
{
    protected:
        int pinNumber;
        int mode;
        bool didSetup;

    public:
        Pin(int number, int mode);

        void onSetup();
};

#endif
