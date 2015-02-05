# Button : InputPin

Simple switch. Its pull-down by default. 
You can use this class with button in pull-up configuration by calling [isPullUp](#ispullup) with `true` as first param,
like this:

```c++
class PullUpButton : public Button
{
    public:
        PullUpButton(int pin) : Button(pin)
        {
            this->isPullUp(true);
        }
};

void world_init()
{
    World::addEntity(new PullUpButton(2));
}
```

## <i class="fa fa-pencil"></i> Constructor

    Button(int pinNumber);

## <i class="fa fa-exclamation-circle"></i> Callbacks
---

### onKeyDown

Called when switch button is down (pressed).

    virtual void onKeyDown();

### onKeyUp

Called when switch button is up (released).

    virtual void onKeyUp();

## <i class="fa fa-code"></i> Public methods

### setDebounceTime

Set time on stable state change required to trigger button events, 50ms by default

    void setDebounceTime(long debounceTime);

### getDebounceTime

Set time on stable state change required to trigger button events, 50ms by default

    long getDebounceTime();

### isPullUp

Inherited from [InputPin::isPullUp](../pin/input_pin.md#ispullup)
