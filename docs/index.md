# Golem0
Framework dedicated for Arduino

It is lightweight and easy to integrate with existing code by design. 
Let you write well organized code and easier model communication between components.

## Installation

Create folder `golem0` in `(My) Documents/Arduino/libraries/` and copy there content of `libraries` from this repo.
 
Now restart Arduino IDE and you should see it under _Sketch_ -> _Import library_ -> _golem0_

You can find more detailed description here: [http://arduino.cc/en/Guide/Libraries](http://arduino.cc/en/Guide/Libraries)

## Basic concepts

### Loop and setup handling

To let Golem do its job you need to forward to `World` setup and loop calls, like this:

```c++
void setup()
{
    World::setup();
}

void loop()
{
    World::loop();
}
```

### World init

Global function `world_init` is your place it initialize world and entities. 
Once configured there, entities will get their setup and can react according to time thanks to callbacks from main loop.

### Thinking

Think is single tick of original loop with controllable non-blocking delay.
To use it, create class extending Entity, override method `onThink` and add entity to world. 

**Important:** make sure to call `setNextThink` to receive next think.

Example:

```c++
class MyClass : public Entity 
{
    MyClass : Entity() 
    {
        this->setNextThink();
    }
    
    void onThink(long currentTime)
    {
        //Do something
        
        //Schedule next think for 10ms
        this->setNextThink(currentTime + 10);
    }
};

void world_init()
{
    World::addEntity(new MyClass());
}
```
