#ifndef _golem0_led_included
#define _golem0_led_included

#include "../../pin/output_pin.h"

class Led : public OutputPin
{
    protected:
        Animation* animation;
        bool inIncreasing;
        bool isToggledOn;

    public:
        Led(int pinNumber);
        ~Led();

        void on();
        void off();
        void toggle();

        void isOn(bool state);
        bool isOn();

        void setBrightness(int value);

        void fadeIn(long duration = 500);
        void fadeOut(long duration = 500);

        virtual void tryThink(long currentTime);

        virtual void writeDigital(int value);
        virtual void writeAnalog(int value);
};

#endif
