#ifndef _golem0_button_included
#define _golem0_button_included

#include "../../pin/input_pin.h"

class Button : public InputPin
{
    protected:
        int lastReadState;
        int buttonState;
        long lastStateChangeTime;

        long debounceTime;

        int keyDownState;

        void onPullUpChange(bool state);
        void onStateChange(bool buttonState);

        void updatePullUpDownSettings();

        virtual void onKeyDown();
        virtual void onKeyUp();

    public:
        Button(int pinNumber);

        void setDebounceTime(long debounceTime);
        long getDebounceTime();

        virtual void tryThink(long currentTime);
};

#endif
