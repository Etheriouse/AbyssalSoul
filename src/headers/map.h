#include <vector>
#include <map>

#include "mob.h"
#include "player.h"

#ifndef Map_h
#define Map_h

class map {

    public:
        map();
        map(int level_global);
        map(int level_global, player *p);
        map(int level_global, player *p, int surface[64][64]);
        map(int level_global, player *p, int surface[64][64], std::map<int, mob> mobs);

        player* getPlayer();
        std::map<int, mob> getMobs();
        int getLevelGlobal();
        int getSurface(int xy);

        void setPlayer(player *p);
        void setMobs(std::map<int, mob> mobs);
        void setLevelGlobal(int level_global);
        void setSurface(int xy, int value);


    private:
        int surface[64][64];
        int level_global;
        std::map<int, mob> mobs;
        player *p;

};

#endif