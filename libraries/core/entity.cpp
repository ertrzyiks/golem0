#include "entity.h"

Entity::Entity()
{
    this->id[0] = '\0';
    this->bRequestedThink = true;
    this->lNextThink = 0;
}

void Entity::setId(const char* entId)
{
    for (int i = 0; i < ENTITY_ID_MAXLEN; i++) {
        this->id[i] = entId[i];

        if (entId[i] == '\0') {
            break;
        }
    }

    //Just to be sure
    this->id[ENTITY_ID_MAXLEN - 1] = '\0';
}

void Entity::getId(char* entId, int maxLength)
{
    if (maxLength > ENTITY_ID_MAXLEN) {
        maxLength = ENTITY_ID_MAXLEN;
    }

    for (int i = 0; i < maxLength; i++) {
        entId[i] = this->id[i];
        if (entId[i] == '\0') {
            break;
        }
    }
}

bool Entity::hasId()
{
    if (this->id[0] == '\0') {
        return false;
    }

    return true;
}

bool Entity::hasId(const char* entId)
{
    if (entId[0] == '\0' || this->id[0] == '\0') {
        return false;
    }

    for (int i = 0; i < ENTITY_ID_MAXLEN; i++) {
        if (entId[i] != this->id[i]) {
            return false;
        }

        if (entId[i] == '\0' && this->id[i] == '\0') {
            return true;
        }
    }

    return true;
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
