#include "world.h"

long World::currentTime;

int World::lastIndex = -1;

Entity* World::entities[256];

void World::addEntity(const char* entId, Entity* ent)
{
    ent->setId(entId);

    World::addEntity(ent);
}

void World::addEntity(Entity* ent)
{
    lastIndex = lastIndex + 1;
    entities[lastIndex] = ent;
}

void World::removeEntity(Entity* ent)
{

}

Entity* World::findEntityById(const char* entId)
{
    char currentId[32];

    for (int i = 0; i <= lastIndex; i++) {

        entities[i]->getId(currentId, 31);

        if (entities[i]->hasId(entId)) {
            return entities[i];
        }
    }

    return 0;
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
