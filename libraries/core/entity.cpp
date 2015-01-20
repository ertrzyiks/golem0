#include "entity.h"

Entity::Entity()
{
    this->bRequestedThink = true;
    this->lNextThink = 0;
}

void Entity::setId(int id)
{
    this->id = id;
}

int Entity::getId()
{
    return this->id;
}


void Entity::think(long currentTime)
{
    this->bRequestedThink = false;
    this->onThink(currentTime);
}

void Entity::onThink(long currentTime)
{
    //Do nothing by default
}

void Entity::onSetup()
{
    //Do nothing by default
}

void Entity::setNextThink(long time)
{
    this->lNextThink = time;
    this->bRequestedThink = true;
}

void Entity::tryThink(long currentTime)
{
    if (this->bRequestedThink && currentTime >= this->lNextThink)
    {
        this->think(currentTime);
    }
}
