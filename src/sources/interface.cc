#include <iostream>
#include <chrono>
#include <thread>
#include <cstdio>

#include "../headers/interface.h"
#include "../headers/function.h"
#include "../headers/vector.h"

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
    this->textures["player"] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_idle.png");
    this->textures["menu"] = IMG_LoadTexture(renderer, "ressources/assets/menu.png");
    this->textures["grass"] = IMG_LoadTexture(renderer, "ressources/assets/grass.png");
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
    bool sprint = false;

    double acceleration = 1.1;
    vector direction = vector(0, 0);
    vector vitesse = vector(0, 0);
    const double vitesse_max_nosprint = 5;
    const double vitesse_max_sprint = 7;
    double vitesse_max = vitesse_max_nosprint;

    bool escapeMenuOn = false;

    auto start = std::chrono::high_resolution_clock::now();
    long frames = 0;
    double fps = 0;
    this->m->setPosPlayer(3250, 3400);
    SDL_Rect rect;
    SDL_Event event;
    rectangle hitboxPlayer = rectangle(10, 40, 40, 49);

    SDL_Texture* walk[4] = {};
    walk[0] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_1.png");
    walk[1] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_2.png");
    walk[2] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_3.png");
    walk[3] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_4.png");

    int tick = 0;
    int frameSprite = 0;
    while (windows_on)
    {
        if (checkColision(90, hitboxPlayer))
        {
            windows_on = false;
        }
        while (SDL_PollEvent(&event))
        {
            // if (event.key.keysym.sym == SDLK_ESCAPE && !escapeMenuOn)
            //     {
            //         escapeMenuOn = true;
            //     }
            std::cout << event.key.keysym.sym << std::endl;

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
                case SDLK_LCTRL:
                    sprint = true;
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
                case SDLK_LCTRL:
                    sprint = false;
                    break;
                default:
                    break;
                }
            }
        }

        if(sprint) {
            vitesse_max = vitesse_max_sprint;
        } else {
            vitesse_max = vitesse_max_nosprint;
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
        if (checkColision(169, hitboxPlayer))
        {
            moveX(-vitesse.x);
        }
        if (checkColision(10))
        {
            moveX(-vitesse.x);
        }

        moveY(vitesse.y);
        if (checkColision(174))
        {
            moveY(-vitesse.y / 2);
        }
        if (checkColision(169, hitboxPlayer))
        {
            moveY(-vitesse.y);
        }
        if (checkColision(10))
        {
            moveY(-vitesse.y);
        }

        // std::cout << "player posSS: " << m->getPosPlayerX() << " " << m->getPosPlayerY() << std::endl;
        //  view->update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int xmoin = m->getPosPlayerX() - 800;
        int parseXmoin = xmoin / 50;
        int startCal = (parseXmoin * 50) - xmoin;

        int ymoin = m->getPosPlayerY() - 450;
        int parseYmoin = ymoin / 50;
        int startCalY = (parseYmoin * 50) - ymoin;

        for (int y = startCalY - 50, u = -1; y < startCalY + 950; u += 1, y += 50)
        {
            for (int i = startCal - 50, c = -1; i < startCal + 1650; c += 1, i += 50)
            {

                // std::cout << i << " " << c << std::endl;
                // printf("x: %d, y: %d\n", parseXmoin+c, parseYmoin+u);
                rect = {i, y, 50, 50};
                if (parseXmoin + c < 0)
                {
                    printf("here\n");
                }
                if (parseYmoin + u < 0)
                {
                    printf("here\n");
                }
                //std::cout << "x: " << i / 50 << " y: " << y / 50 << std::endl;
                switch (this->m->getSurface(parseXmoin + c, parseYmoin + u))
                {
                case 255:
                    SDL_RenderCopy(renderer, this->textures["floor1"], NULL, &rect);
                    break;
                case 91:
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
                case 154:
                    SDL_RenderCopy(renderer, this->textures["grass"], NULL, &rect);
                    break;
                case 10:
                    SDL_RenderCopy(renderer, this->textures["water"], NULL, &rect);
                    break;

                default:
                    SDL_RenderCopy(renderer, this->textures["error"], NULL, &rect);
                    break;
                }
                // 255->floor1 90->image.png 169->floor3 174->water 124->lava 154->grass 10->world border
            }
        }

        SDL_Rect playerRect = {800, 450, 50, 50};
        if(tick%15 == 0) {
            frameSprite+=1;
            frameSprite = frameSprite%4;
        }

        if(vitesse.x == 0 && vitesse.y == 0) {
            SDL_RenderCopy(renderer, this->textures["player"], NULL, &playerRect);
        } else {
            SDL_RenderCopy(renderer, walk[frameSprite], NULL, &playerRect);
        }
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
            system("clear");
            printf("fps: %.2f, total frame: %d\n", fps, frames);

            start = std::chrono::high_resolution_clock::now();
            frames = 0;
        }
        printf("fps: %.2f, total frame: %d\n", fps, frames);

        std::this_thread::sleep_for(std::chrono::milliseconds(7)); // 60 fps (1/60 * 1000 ≈ 16.67) 144 fps ( 1/144 * 1000 ≈ 6.944)
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // 60 fps (1/60 * 1000 ≈ 16.67) 144 fps ( 1/144 * 1000 ≈ 6.944)
        //system("clear");
        //  windows_on = false;
        // std::cout << "player posSS: " << m->getPosPlayerX() << " " << m->getPosPlayerY() << std::endl;
        tick++;
    }

    for (auto &i : walk)
    {
        SDL_DestroyTexture(i);
    }


    clearTextures();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

// bool interface::checkColision(int block, int[4] colision); //TODO

/**
 * @param block l'id du block a detecter
 * @param v1 les 2 point de gauche x haut y bas de la collision
 * @param v1 les 2 point de droite x haut y bas de la collision
 * @return si la collision est detecter dans la zone definie
 */
bool interface::checkColision(int block, rectangle r)
{
    int x = m->getPosPlayerX();
    int y = m->getPosPlayerY();

    /*
     * a b
     * c d
     */

    bool a = m->getSurface((x + r.a) / 50, (y + r.b) / 50) == block;
    bool b = m->getSurface((x + r.c) / 50, (y + r.b) / 50) == block;
    bool c = m->getSurface((x + r.a) / 50, (y + r.d) / 50) == block;
    bool d = m->getSurface((x + r.c) / 50, (y + r.d) / 50) == block;

    if (a || b || c || d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool interface::checkColision(int block)
{
    int x = m->getPosPlayerX();
    int y = m->getPosPlayerY();

    if (m->getSurface((x + 50) / 50, (y + 50) / 50) == block || m->getSurface((x + 0) / 50, (y + 50) / 50) == block)
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

void clearTextures() {}
