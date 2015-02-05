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
            this->isPullUp(true);
            this->led = (Led*) World::findEntityById(ledId);
        }

        void onKeyDown()
        {
             this->led->fadeIn();
        }
        void onKeyUp()
        {
             this->led->fadeOut();
        }
};

void world_init()
{
    World::addEntity("myled", new Led(PIN_13));
    World::addEntity("mybutton", new MyButton(PIN_2, "myled"));
}
