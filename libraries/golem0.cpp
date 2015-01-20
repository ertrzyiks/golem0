#include "golem0.h"

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

ManagedEntity::ManagedEntity() : Entity()
{
    World::addEntity(this);
}

ManagedEntity::~ManagedEntity()
{
    World::removeEntity(this);
}

PinController::PinController(int number, int mode)
{
    this->pinNumber = number;
    this->mode = mode;
}

void PinController::onSetup()
{
    pinMode(this->pinNumber, this->mode);
}

void PinController::writeDigital(int value)
{
    digitalWrite(this->pinNumber, value);
}

void PinController::writeAnalog(int value)
{
    analogWrite(this->pinNumber, value);
}
