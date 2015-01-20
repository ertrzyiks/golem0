# golem0
Framework dedicated for Arduino

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
To use it, create class extending ManagedEntity and override method `onThink`. 
Make sure to call `setNextThink` to receive next think.

Example:

```c++
class MyClass : public ManagedEntity {
    void onThink(long currentTime)
    {
        //Do something
        
        //Schedule next think for 10ms
        this->setNextThink(currentTime + 10);
    }
};

void world_init()
{
   MyClass *obj = new MyClass();
}
```
