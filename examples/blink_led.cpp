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
    public:
        BlinkLed(int pin) : Led(pin)
        {
          this->setNextThink();
        }

       void onThink(long currentTime)
       {
            this->toggle();
            this->setNextThink(currentTime + 500);
       }
};

void world_init()
{
   World::addEntity(new BlinkLed(PIN_13));
}
