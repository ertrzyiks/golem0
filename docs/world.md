# World

World is static class that should be injected into Arduino setup and loop methds. 
It allows you to manage entities.

## Public methods

### World::loop

Handle timing based implementations. This function should be called in Arduino loop function. 

    static void loop();
    
---
    
### World::setup

Do hardware setup. This function should be called in Arduino setup function.

    static void setup();

---

### World::addEntity

Add annonymous entity to world. You need to keed pointer on your own, 
for now its not possible to find annonymous entity in the World.

    static void addEntity(Entity* ent);
     
Adding entity to world in `world_init` function mean that entity will get proper setup and will be able to thinking.

---

Add entity to world and label it with id. Id should be uniquee. 
You can get pointer later on using `World::findEntityById` method.

    static void addEntity(const char* endId, Entity* ent);

Adding entity to world in `world_init` function mean that entity will get proper setup and will be able to thinking.

### World::findEntityById

Get reference to entity with given id.

    static Entity* findEntityById(const char* entId);
