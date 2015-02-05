# Animation

Make it easier to create transitions.

## <i class="fa fa-pencil"></i> Constructor

    Animation();
    
## <i class="fa fa-code"></i> Public methods
---

### setDuration

Set animation duration
    
    Animation* setDuration(int value);
    
### start

Initialize animation, make it as running. Keep in mind that nothing happens until `update` call.

    Animation* start();
    
### isRunning

Return true, when animation is started and running. False when not started or finished.

    bool isRunning();
    
### update
    
Update animation progress, returns fraction 0.0-1.0 of completion.    

    float update(long timestamp);

