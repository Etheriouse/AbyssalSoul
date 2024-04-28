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

int testSDL(map m)
{
    srand(time(nullptr));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible d'initialiser SDL : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *windows = SDL_CreateWindow("Darksoul IV", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    if (windows == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de crée la fenêtre : %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetWindowIcon(windows, IMG_Load("ressources/assets/Icone.png"));

    //SDL_SetWindowFullscreen(windows, SDL_WINDOW_FULLSCREEN); // Pour le plein écran
    SDL_SetWindowFullscreen(windows, 0); // Pour revenir au mode fenêtré


    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture *grass = IMG_LoadTexture(renderer, "ressources/assets/grass.png");
    SDL_Texture *floor1 = IMG_LoadTexture(renderer, "ressources/assets/floor1.png");
    SDL_Texture *floor2 = IMG_LoadTexture(renderer, "ressources/assets/floor2.png");
    SDL_Texture *floor3 = IMG_LoadTexture(renderer, "ressources/assets/floor3.png");

    SDL_Texture *darksoul = IMG_LoadTexture(renderer, "ressources/assets/Icone.png");
    SDL_Texture *target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1600, 900);

    Uint32 startTime = 0;
    Uint32 endTime = 0;
    Uint32 frameCount = 0;
    float avgFPS = 0;
    bool windows_on = true;
    while (windows_on)
    {
        startTime = SDL_GetTicks();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                windows_on = false;
            }
        }

        SDL_Rect grass1 = {100, 100, 100, 100};
        SDL_Rect darksoul1 = {200, 100, 100, 100};
        SDL_SetRenderTarget(renderer, target);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // SDL_RenderCopy(renderer, grass, NULL, &grass1); // Dessiner la texture 1
        // SDL_RenderCopy(renderer, darksoul, NULL, &darksoul1); // Dessiner la texture 2

        for (int y = 0; y < var::HEIGHT; y += 1)
        {
            for (int i = 0; i < var::WIDTH; i += 1)
            {
                SDL_Rect rect = {0 + i * 50, 0 + y * 50, 50, 50};

                switch (m.getSurface((i*100)+y))
                {
                case 0:
                    SDL_RenderCopy(renderer, floor1, NULL, &rect);
                    break;
                case 1:
                    SDL_RenderCopy(renderer, floor2, NULL, &rect);
                    break;
                case 2:
                    SDL_RenderCopy(renderer, floor3, NULL, &rect);
                    break;

                default:
                    SDL_RenderCopy(renderer, darksoul, NULL, &rect);
                    break;
                }
            }
        }

        SDL_SetRenderTarget(renderer, NULL);

        SDL_RenderCopy(renderer, target, NULL, NULL);
        SDL_RenderPresent(renderer);

        // Mesurer le temps à la fin de la boucle
        endTime = SDL_GetTicks();

        // Calculer le temps écoulé pour cette trame
        Uint32 frameTime = endTime - startTime;

        // Calculer les FPS
        float currentFPS = 1000.0 / frameTime;
        avgFPS = (avgFPS * frameCount + currentFPS) / (frameCount + 1);

        // Incrémenter le compteur de trames
        frameCount++;

        // Afficher les FPS toutes les secondes
        if (endTime - startTime < 1000)
        {
            system("clear");
            printf("fps: %.2f, total frame: %d\n", avgFPS, frameCount);
        }

        // Limiter le FPS pour économiser les ressources CPU
        if (frameTime < 1000 / 60)
        {
            SDL_Delay((1000 / 60) - frameTime);
        }
    }

    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(darksoul);
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
    map *m = new map(1, new player(10), image("ressources/assets/map.png"));

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
    std::cout << "Project work!" << std::endl;

    return 0;
    //return testSDL(*m);
}
