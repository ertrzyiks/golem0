# Entity

Single entity of world. Elements of world should extend this class adding custom behavior using callbacks.

## Callbacks

### onSetup

Callback triggered when entity can setup itself, like set pin mode.

    virtual void onSetup();
        
### onThink

Callback triggered when entity is supposed to think.
Each entity will think once on first loop call and then always when scheduled with `setNextThink`.

    virtual void onThink(long currentTime);
    
## Public methods

### setNextThink

Schedule next `onThink` callback for given time (milis).

    void setNextThink(long time);

