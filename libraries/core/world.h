#ifndef _golem0_world_included
#define _golem0_world_included

#include "entity.h"

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

#endif
