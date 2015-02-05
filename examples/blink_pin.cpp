#include <golem0.h>

void setup()
{
    World::setup();
}

void loop()
{
    World::loop();
}

class BlinkPinController : public OutputPin
{
    protected:
        bool value;

    public:
        BlinkPinController(int pin) : OutputPin(pin)
        {
            this->value = true;

            this->setNextThink();
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
   World::addEntity(new BlinkPinController(PIN_13));
}
