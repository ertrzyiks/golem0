#ifndef _golem0_button_included
#define _golem0_button_included

#include "../../pin/input_pin.h"

class Button : public InputPin
{
    protected:
        int lastState;

    public:
        Button(int number);

        void tryThink(long currentTime);

        virtual void onKeyDown();
        virtual void onKeyUp();
};

#endif
