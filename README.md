# golem0
Framework dedicated for Arduino

## Installation

Create folder `golem0` in `(My) Documents/Arduino/libraries/` and copy there content of `libraries` from this repo. 

You can find more detailed description here: http://arduino.cc/en/Guide/Libraries

## Usage

### Code structure

```c++
#include <golem0.h>

void setup()
{
    World::setup();
}

void loop()
{
    World::loop();
}

void world_init()
{
   //your code here
}

```

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
