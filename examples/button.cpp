#include <golem0.h>
#include <Arduino.h>

void setup()
{
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

        void onKeyDown()
        {
            this->led->on();
        }

        void onKeyUp()
        {
            this->led->off();
        }
};

void world_init()
{
    World::addEntity("myled", new Led(13));
    World::addEntity("mybutton", new MyButton(2, "myled"));
}
