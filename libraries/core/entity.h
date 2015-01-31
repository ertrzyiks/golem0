#ifndef _golem0_entity_included
#define _golem0_entity_included

#ifndef ENTITY_ID_MAXLEN
#define ENTITY_ID_MAXLEN 32
#endif

class Entity
{
    protected:
        char id[ENTITY_ID_MAXLEN];

        bool bRequestedThink;
        long lNextThink;

        void think(long currentTime);

    public:
        Entity();

        void setId(const char* entId);
        void getId(char* entId, int maxLength);

        bool hasId();
        bool hasId(const char* entId);

        void tryThink(long currentTime);

        virtual void onSetup();
        virtual void onThink(long currentTime);

        void setNextThink(long time);
};

#endif
