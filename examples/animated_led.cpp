#include <golem0.h>

void setup()
{
    World::setup();
}

void loop()
{
    World::loop();
}

class AnimatedPinController : public PinController
{
    protected:
        int value;
        int diffBaseValue;
        int diff;

    public:
        AnimatedPinController(int pin, int diffBaseValue = 5) : PinController(pin, OUTPUT)
        {
            this->value = 0;
            this->diff = diffBaseValue;
            this->diffBaseValue = diffBaseValue;
        }

       void onThink(long currentTime)
       {
            this->value = max(0, min(this->value + this->diff, 255));

            this->writeAnalog(this->value);
            this->recalculateDiff();

            this->setNextThink(currentTime + 10);
       }

    protected:
        void recalculateDiff()
        {
            if (this->value >= 240) {
                this->diff = -this->diffBaseValue;
            }
            else if (this->value <= 0) {
                this->diff = this->diffBaseValue;
            }
        }
};

void world_init()
{
   AnimatedPinController* p1 = new AnimatedPinController(13, 2);
   AnimatedPinController* p2 = new AnimatedPinController(11, 10);
}
