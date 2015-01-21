#include <golem0.h>

void setup()
{
    World::setup();
}

void loop()
{
    World::loop();
}

class BlinkPinController : public PinController
{
    protected:
        bool value;

    public:
        BlinkPinController(int pin) : PinController(pin, OUTPUT)
        {
          this->value = true;
        }

       void onThink(long currentTime)
       {
            this->value = !this->value;

            this->writeDigital(this->value ? HIGH : LOW);

            this->setNextThink(currentTime + 500);
       }
};

void world_init()
{
   World::addEntity(new BlinkPinController(13));
}
