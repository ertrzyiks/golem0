# Led : OutputPin

Single color Led.

## <i class="fa fa-pencil"></i> Constructor

    Led(int pinNumber);

## <i class="fa fa-code"></i> Public methods 
---

### on

Turn led on
    
    void on();
    
### off

Turn led on

    void off();

### toggle

Toggle led on/off state

    void toggle();
    
### isOn

Turn led on/off, depend of `state` param

    void isOn(bool state);
    
Check if led is on or off

    bool isOn();

### setBrightness

Manually set brightness of led, should be value in range 0-255

    void setBrightness(int value);
    
### fadeIn

Turn on with transition, duration in ms
    
    void fadeIn(long duration = 500);
    
### fadeOut

Turn off with transition, duration in ms

    void fadeOut(long duration = 500);
