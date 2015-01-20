#include "managed_entity.h"

ManagedEntity::ManagedEntity() : Entity()
{
    World::addEntity(this);
}

ManagedEntity::~ManagedEntity()
{
    World::removeEntity(this);
}
