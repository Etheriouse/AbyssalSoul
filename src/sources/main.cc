#include <iostream>
#include <cmath>

#include "SDL2/SDL.h"

#include "../headers/map.h"

//using namespace std;

void EstusFunction(entity *target, entity *source) {
}

int testSDL() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible d'initialiser SDL : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* windows = SDL_CreateWindow("Test Windows SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if(windows == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de crée la fenêtre : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
        return 1;
    }

    bool windows_on = true;
    while(windows_on) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                windows_on = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(windows);
    SDL_Quit();
    return 0;
}

int main(int argc, char const *argv[])
{
    // player *p = new player(10);
    // int* stat = p->getStat();
    // cout << "vitality: " << stat[0] << endl;
    // delete[] stat;

    // cout << 12*100+34 << endl;

    // cout << "1478: " << getY(1478) << endl;
    //map *m = new map();
    //m->show(true);
    //m->show(false);
    std::cout << "Project work!" << std::endl;
    return testSDL();
}
