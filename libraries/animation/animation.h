#ifndef _golem0_animation_included
#define _golem0_animation_included

#include <Arduino.h>

class Animation
{
    protected:
        long startedAt;
        long duration;

    public:
        Animation();

        Animation* setDuration(int value);
        Animation* start();

        bool isRunning();

        float update(long timestamp);
};

#endif
