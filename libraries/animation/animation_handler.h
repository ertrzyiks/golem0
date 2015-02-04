#ifndef _golem0_animation_included
#define _golem0_animation_included

#include <Arduino.h>

template<class O>
class AnimationHandler
{
    protected:
        long startedAt;

        int startValue;
        int endValue;

        long duration;

        O* onApplyTarget;
        void (O::*onApply) (int);

        O* onDoneTarget;
        void (O::*onDone) ();

        void done()
        {
            this->apply(this->endValue);

            if (this->onDone) {
                (this->onDoneTarget->*(this->onDone))();
            }
        }

        void apply(int value)
        {
            if (this->onApply) {
                (this->onApplyTarget->*(this->onApply))(value);
            }
        }

    public:
        AnimationHandler()
        {
            this->startedAt = -1;
        }

        void setStart(int value)
        {
            this->startValue = value;
        }

        void setEnd(int value)
        {
            this->endValue = value;
        }

        void setDuration(int value)
        {
            this->duration = value;
        }

        void setOnApply(O* obj, void (O::*onApply) (int))
        {
            this->onApplyTarget = obj;
            this->onApply = onApply;
        }

        void setOnDone(O* obj, void (O::*onDone) ())
        {
            this->onDoneTarget = obj;
            this->onDone = onDone;
        }

        void start()
        {
            this->startedAt = millis();
        }

        void update(long timestamp)
        {
            if (this->startedAt == -1) {
                return;
            }

            long elapsedTime = timestamp - this->startedAt;
            float elapsedProgress = elapsedTime * 1.0 / this->duration;

            if (elapsedProgress >= 1.0) {
                this->done();
                this->startedAt = -1;
                return;
            }

            int value = floor(elapsedProgress * (endValue - startValue));
            Serial.println(value);
            this->apply(value);
        }
};

#endif
