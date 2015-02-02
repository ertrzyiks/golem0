#ifndef _golem0_button_included
#define _golem0_button_included

#include "../../pin/input_pin.h"

class Button : public InputPin
{
    protected:
        int lastState;
        int keyDownState;

        void onPullUpChange(bool state);

        void updatePullUpDownSettings();

        virtual void onKeyDown();
        virtual void onKeyUp();

    public:
        Button(int pinNumber);

        virtual void tryThink(long currentTime);
};

#endif
