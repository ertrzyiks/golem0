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

        bool isOn;

        AnimationHandler<MyButton> animation;
        AnimationHandler<MyButton> animation2;

    public:
        MyButton(int pin, const char* ledId) : Button(pin)
        {
            this->isPullUp(true);

            this->isOn = false;

            this->led = (Led*) World::findEntityById(ledId);

            this->animation.setStart(0);
            this->animation.setEnd(255);
            this->animation.setDuration(1000);
            this->animation.setOnApply(this, &MyButton::updateBrightness);

            this->setNextThink();
        }

        void onKeyUp()
        {
             if (this->isOn) {
                 this->animation.setStart(255);
                 this->animation.setEnd(0);
             } else {
                 this->animation.setStart(0);
                 this->animation.setEnd(255);
             }

             this->animation.start();
             this->setNextThink();

             this->isOn = !this->isOn;
        }

        void onThink(long currentTime)
        {
            this->setNextThink(currentTime + 30);

            this->animation.update(currentTime);
        }

        void updateBrightness(int value)
        {
          this->led->setBrightness(value);
        }
};

void world_init()
{
    World::addEntity("myled", new Led(PIN_13));
    World::addEntity("mybutton", new MyButton(PIN_2, "myled"));
}
