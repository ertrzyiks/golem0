#ifndef _golem0_included
#define _golem0_included

#include "Arduino.h";

void world_init();

class Entity
{
    protected:
        int id;

        bool bRequestedThink;
        long lNextThink;

        void think(long currentTime);

    public:
        Entity();

        void setId(int id);
        int getId();

        void tryThink(long currentTime);

        virtual void onSetup();
        virtual void onThink(long currentTime);

        void setNextThink(long time);
};

class World
{
    protected:
        static long currentTime;
        static int lastIndex;
        static Entity* entities[256];

    public:
        static void addEntity(Entity* ent);
        static void removeEntity(Entity* ent);

        static void loop();
        static void setup();
};

class ManagedEntity : public Entity
{
    public:
        ManagedEntity();
        ~ManagedEntity();
};


class PinController : public ManagedEntity
{
    protected:
        int pinNumber;
        int mode;

    public:
        PinController(int number, int mode);

        void onSetup();
        void writeDigital(int value);
        void writeAnalog(int value);
};

#endif
