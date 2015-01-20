#include "world.h"

long World::currentTime;

int World::lastIndex = -1;

Entity* World::entities[256];

void World::addEntity(Entity* ent)
{
    lastIndex = lastIndex + 1;

    ent->setId(lastIndex);
    entities[lastIndex] = ent;
}

void World::removeEntity(Entity* ent)
{

}

void World::setup()
{
    world_init();
}

void World::loop()
{
    currentTime = millis();

    for (int i = 0; i <= lastIndex; i++) {
        entities[i]->tryThink(currentTime);
    }

    delay(1);
}
