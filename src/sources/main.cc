#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"

#include "../headers/map.h"
#include "../headers/interface.h"

// using namespace std;

void EstusFunction(entity *target, entity *source)
{
}

int main(int argc, char const *argv[])
{
    // player *p = new player(10);
    // int* stat = p->getStat();
    // cout << "vitality: " << stat[0] << endl;
    // delete[] stat;

    // cout << 12*100+34 << endl;

    // cout << "1478: " << getY(1478) << endl;
    map *m = new map(1, new player(10), image("ressources/assets/2d/map.png"));
    //camera *view = new camera(m);
    //view->update();
    //m->show(true);
    // for(int i = 0; i<var::HEIGHT; i+=1) { 169 blue 174 pink 90 red 255 white
    //     for(int y = 0; y<var::WIDTH; y++) {
    //         m->setSurface((y*100)+i, 0);
    //     }
    // }
    interface* game = new interface("DarksoulIV", "ressources/assets/Icone.png", m);
    game->run();

    // 255 -> floor1
    // 90 -> image.png
    // 169 -> floor3
    // 174 water
    // é-> lava
    std::cout << "Project work!" << std::endl;

    return 0;
    //return testSDL(*m);
}
