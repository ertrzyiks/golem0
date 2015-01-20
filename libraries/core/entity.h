#ifndef _golem0_entity_included
#define _golem0_entity_included

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

#endif
