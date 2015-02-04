#ifndef _golem0_pin_included
#define _golem0_pin_included

#include <Arduino.h>

#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13

class Pin : public Entity
{
    protected:
        int pinNumber;
        int mode;
        bool didSetup;

    public:
        Pin(int pinNumber, int mode);

        virtual void onSetup();
};

#endif
