#ifndef Map_h
#define Map_h

#include <vector>
#include <map>

#include "mob.h"
#include "player.h"
#include "image.h"
#include "var.h"


class map {

    public:
        map();
        map(int level_global);
        map(int level_global, player *p);
        map(int level_global, player *p, int surface[var::HEIGHT][var::WIDTH]);
        map(int level_global, player *p, int surface[var::HEIGHT][var::WIDTH], std::map<int, mob> mobs);
        map(int level_global, player *p, image surface);
        map(int level_global, player *p, image surface, std::map<int, mob> mobs);

        player* getPlayer();
        std::map<int, mob> getMobs();
        int getLevelGlobal();
        int getSurface(int x, int y);
        int getPosPlayerX();
        int getPosPlayerY();
        int getHeight();
        int getWidth();

        void setPlayer(player *p);
        void setMobs(std::map<int, mob> mobs);
        void setLevelGlobal(int level_global);
        void setSurface(int x, int y, int value);
        void setPosPlayer(int x, int y);

        void show(bool number);

    private:
        int surface[var::HEIGHT][var::WIDTH];
        int level_global;
        std::map<int, mob> mobs;
        player *p;
        int player_x;
        int player_y;

};

#endif