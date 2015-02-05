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
    public:
        MyButton(int pin) : Button(pin)
        {
            this->isPullUp(true);
        }

        void onKeyDown()
        {
            Serial.println("BUTTON DOWN");
        }

        void onKeyUp()
        {
            Serial.println("BUTTON UP");
        }
};

void world_init()
{
    World::addEntity("mybutton", new MyButton(PIN_2));
}
