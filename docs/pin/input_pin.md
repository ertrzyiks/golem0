# InputPin : Pin

## <i class="fa fa-pencil"></i> Constructor

    InputPin(int pinNumber);

## <i class="fa fa-code"></i> Public methods
---

### isPullUp

You can choose to use internal pull-up resistors for input, 
see details [here](http://arduino.cc/en/Tutorial/InputPullupSerial)

Set to true if you want to use pull-up resitor

    void isPullUp(bool state);

Get current settings of pull-up input

    bool isPullUp();
    
**Important!** You cannot change this setting after setup call, so you need to call this method in `world_init` function

### readDigital

    int readDigital();
    
### readAnalog

    int readAnalog();
