#include <iostream>
#include <chrono>
#include <thread>
#include <cstdio>

#include "../headers/interface.h"
#include "../headers/function.h"
#include "../headers/vector.h"
#include "../headers/camera.h"

interface::interface()
{
    this->m = new map();
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible d'initialiser SDL : %s\n", SDL_GetError());
    }

    this->window = SDL_CreateWindow("none", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de crée la fenêtre : %s\n", SDL_GetError());
    }

    SDL_SetWindowIcon(this->window, IMG_Load("ressources/assets/image.png"));

    SDL_SetWindowFullscreen(this->window, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
    }
    this->textures = std::map<const char *, SDL_Texture *>();
}

interface::interface(const char *name)
{
    this->m = new map();
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible d'initialiser SDL : %s\n", SDL_GetError());
    }

    this->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de crée la fenêtre : %s\n", SDL_GetError());
    }

    SDL_SetWindowIcon(this->window, IMG_Load("ressources/assets/image.png"));

    SDL_SetWindowFullscreen(this->window, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
    }
    this->textures = std::map<const char *, SDL_Texture *>();
}

interface::interface(const char *name, const char *icone_filename)
{
    this->m = new map();
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible d'initialiser SDL : %s\n", SDL_GetError());
    }

    this->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de crée la fenêtre : %s\n", SDL_GetError());
    }

    SDL_SetWindowIcon(this->window, IMG_Load(icone_filename));

    SDL_SetWindowFullscreen(this->window, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
    }
    this->textures = std::map<const char *, SDL_Texture *>();
}

interface::interface(const char *name, const char *icone_filename, map *m)
{
    this->m = m;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible d'initialiser SDL : %s\n", SDL_GetError());
    }

    this->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN);
    if (this->window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de crée la fenêtre : %s\n", SDL_GetError());
    }

    SDL_SetWindowIcon(this->window, IMG_Load(icone_filename));

    // SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
    SDL_SetWindowFullscreen(this->window, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
    }
    this->textures = std::map<const char *, SDL_Texture *>();
}

void interface::clearTextures()
{
    for (auto &pair : this->textures)
    {
        std::cout << "key: " << pair.first << " value: " << pair.second << std::endl;
        SDL_DestroyTexture(pair.second);
        this->textures.erase(pair.first);
    }

    for (auto &pair : this->textures)
    {
        std::cout << "key: " << pair.first << " value: " << pair.second << std::endl;
    }
}

void interface::loadTextures()
{
    this->textures["water"] = IMG_LoadTexture(renderer, "ressources/assets/water.png");
    this->textures["lava"] = IMG_LoadTexture(renderer, "ressources/assets/lava.jpg");
    this->textures["floor1"] = IMG_LoadTexture(renderer, "ressources/assets/floor1.png");
    this->textures["floor3"] = IMG_LoadTexture(renderer, "ressources/assets/floor3.png");
    this->textures["image"] = IMG_LoadTexture(renderer, "ressources/assets/image.png");
    this->textures["player"] = IMG_LoadTexture(renderer, "ressources/assets/player.png");
    this->textures["menu"] = IMG_LoadTexture(renderer, "ressources/assets/menu.png");
    this->textures["background"] = IMG_LoadTexture(renderer, "ressources/assets/background.jpg");
    this->textures["error"] = IMG_LoadTexture(renderer, "ressources/assets/Icone.png");
}

void interface::run()
{
    loadTextures();

    bool gaucheAppuye = false;
    bool droiteAppuye = false;
    bool hautAppuye = false;
    bool basAppuye = false;

    double acceleration = 1.1;
    vector direction = vector(0, 0);
    vector vitesse = vector(0, 0);
    double vitesse_max = 7;

    bool escapeMenuOn = false;

    auto start = std::chrono::high_resolution_clock::now();
    long frames = 0;
    double fps = 0;

    camera *view = new camera(this->m);

    while (windows_on)
    {
        SDL_Event event;
        if (checkColision(90))
        {
            windows_on = !windows_on;
        }
        while (SDL_PollEvent(&event))
        {
            if (event.key.keysym.sym == SDLK_ESCAPE && !escapeMenuOn)
            {
                escapeMenuOn = true;
            }

            if (event.type == SDL_QUIT)
            {
                windows_on = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_q:
                    gaucheAppuye = true;
                    break;
                case SDLK_d:
                    droiteAppuye = true;
                    break;
                case SDLK_z:
                    hautAppuye = true;
                    break;
                case SDLK_s:
                    basAppuye = true;
                    break;
                default:
                    break;
                }
            }

            if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_q:
                    gaucheAppuye = false;
                    break;
                case SDLK_d:
                    droiteAppuye = false;
                    break;
                case SDLK_z:
                    hautAppuye = false;
                    break;
                case SDLK_s:
                    basAppuye = false;
                    break;
                default:
                    break;
                }
            }
        }

        direction.x = 0;
        direction.y = 0;

        if (droiteAppuye)
        {
            direction.x = 1;
        }

        if (gaucheAppuye)
        {
            direction.x = -1;
        }

        if (hautAppuye)
        {
            direction.y = -1;
        }

        if (basAppuye)
        {
            direction.y = 1;
        }

        vitesse.x += direction.x * acceleration;
        vitesse.y += direction.y * acceleration;

        if (direction.x == 0 || direction.y == 0)
        {
            if (direction.x == 0)
            {
                if (vitesse.x > 1)
                {
                    vitesse.x = 0;
                }
                else if (vitesse.x < -1)
                {
                    vitesse.x = 0;
                }
            }

            if (direction.y == 0)
            {
                if (vitesse.y > 1)
                {
                    vitesse.y = 0;
                }
                else if (vitesse.y < -1)
                {
                    vitesse.y = 0;
                }
            }
        }

        if (vitesse.x > vitesse_max)
        {
            vitesse.x = vitesse_max;
        }
        else if (vitesse.x < (-vitesse_max))
        {
            vitesse.x = (-vitesse_max);
        }

        if (vitesse.y > vitesse_max)
        {
            vitesse.y = vitesse_max;
        }
        else if (vitesse.y < (-vitesse_max))
        {
            vitesse.y = (-vitesse_max);
        }

        moveX(vitesse.x);
        if (checkColision(174))
        {
            moveX(-vitesse.x / 2);
        }
        if (checkColision(169))
        {
            moveX(-vitesse.x);
        }

        moveY(vitesse.y);
        if (checkColision(174))
        {
            moveY(-vitesse.y / 2);
        }
        if (checkColision(169))
        {
            moveY(-vitesse.y);
        }

        std::cout << "player posSS: " << m->getPosPlayerX()/50 << " " << m->getPosPlayerY()/50 << std::endl;
        view->update();

        SDL_Rect grass1 = {100, 100, 100, 100};
        SDL_Rect darksoul1 = {200, 100, 100, 100};
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (int y = 0; y < var::C_HEIGHT; y += 1)
        {
            for (int i = 0; i < var::C_WIDTH; i += 1)
            {

                // 255 -> floor1
                // 90 -> image.png
                // 169 -> floor3
                // 174 -> water
                // 124 -> lava

                SDL_Rect rect = {0 + i * 50, 0 + y * 50, 50, 50};
                switch (view->getSurface(i, y))
                {
                case 255:
                    SDL_RenderCopy(renderer, this->textures["floor1"], NULL, &rect);
                    break;
                case 90:
                    SDL_RenderCopy(renderer, this->textures["image"], NULL, &rect);
                    break;
                case 169:
                    SDL_RenderCopy(renderer, this->textures["floor3"], NULL, &rect);
                    break;
                case 174:
                    SDL_RenderCopy(renderer, this->textures["water"], NULL, &rect);
                    break;
                case 124:
                    SDL_RenderCopy(renderer, this->textures["lava"], NULL, &rect);
                    break;

                default:
                    SDL_RenderCopy(renderer, this->textures["error"], NULL, &rect);
                    break;
                }
            }
        }

        SDL_Rect playerRect = {m->getPosPlayerX(), m->getPosPlayerY(), 50, 50};
        SDL_RenderCopy(renderer, this->textures["player"], NULL, &playerRect);

        SDL_RenderPresent(renderer);

        if (escapeMenuOn)
        {
            escapeMenu();
            escapeMenuOn = false;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        frames++;

        if (duration >= 1000)
        {
            fps = frames / (duration / 1000.0);
            //system("clear");
            printf("fps: %.2f, total frame: %d\n", fps, frames);

            start = std::chrono::high_resolution_clock::now();
            frames = 0;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(7)); // 60 fps (1/60 * 1000 ≈ 16.67) 144 fps ( 1/144 * 1000 ≈ 6.944)
    }
    system("clear");


    clearTextures();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

// bool interface::checkColision(int block, int[4] colision); //TODO

bool interface::checkColision(int block)
{
    int x = m->getPosPlayerX();
    int y = m->getPosPlayerY();

    if (m->getSurface((x + 39) / 50, (y + 49) / 50) == block || m->getSurface((x + 19) / 50, (y + 49) / 50) == block)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void interface::moveX(int i)
{
    m->setPosPlayer(m->getPosPlayerX() + i, m->getPosPlayerY());
}

void interface::moveY(int i)
{
    m->setPosPlayer(m->getPosPlayerX(), m->getPosPlayerY() + i);
}

void interface::escapeMenu()
{
    auto start = std::chrono::high_resolution_clock::now();
    long frames = 0;
    double fps = 0;

    bool menuOn = true;
    SDL_Event event;
    SDL_Rect menuRect = {100, 100, 1400, 700};
    SDL_Rect backgroundRect = {0, 0, 1600, 900};
    while (menuOn)
    {
        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_QUIT)
            {
                menuOn = false;
                windows_on = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_DOWN:
                    break;
                case SDLK_UP:
                    break;
                case SDLK_LEFT:
                    break;
                case SDLK_RIGHT:
                    break;
                case SDLK_a:
                    break;
                case SDLK_e:
                    break;
                case SDLK_x:
                    menuOn = false;
                default:
                    break;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, this->textures["background"], NULL, &backgroundRect);
        SDL_RenderCopy(renderer, this->textures["menu"], NULL, &menuRect);
        SDL_RenderPresent(renderer);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        frames++;

        if (duration >= 1000)
        {
            fps = frames / (duration / 1000.0);
            system("clear");
            printf("fps: %.2f, total frame: %d\n", fps, frames);

            start = std::chrono::high_resolution_clock::now();
            frames = 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(7)); // 60 FPS (1000ms / 60 ≈ 16.67)
    }
}