#include <golem0.h>

void setup()
{
    World::setup();
}

void loop()
{
    World::loop();
}

class BlinkLed : public Led
{
    protected:
        bool state;

    public:
        BlinkLed(int pin) : Led(pin)
        {
          this->state = true;
        }

       void onThink(long currentTime)
       {
            this->state = !this->state;
            this->setOn(this->state);

            this->setNextThink(currentTime + 500);
       }
};

void world_init()
{
   World::addEntity(new BlinkLed(13));
}
