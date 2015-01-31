#include <golem0.h>
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    World::setup();
}

void loop()
{
    World::loop();
}

class MyButton : public Button
{
    protected:
        Led *led;

    public:
        MyButton(int pin, const char* ledId) : Button(pin)
        {
            this->led = (Led*) World::findEntityById(ledId);
        }

        void onThink(long currentTime)
        {
            this->led->setOn(this->readDigital());
            this->setNextThink(currentTime + 1000);
        }
};

void world_init()
{
    World::addEntity("myled", new Led(13));
    World::addEntity("mybutton", new MyButton(2, "myled"));
}
