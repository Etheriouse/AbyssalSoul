#include <iostream>

#include "../headers/interface.h"
#include "../headers/function.h"

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

    SDL_SetWindowFullscreen(this->window, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_SOFTWARE);
    if (this->renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Impossible de créer le renderer : %s\n", SDL_GetError());
    }
    this->textures = std::map<const char *, SDL_Texture *>();
}

void interface::clearTexture()
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

void interface::run()
{

    this->textures["water"] = IMG_LoadTexture(renderer, "ressources/assets/water.png");
    this->textures["floor1"] = IMG_LoadTexture(renderer, "ressources/assets/floor1.png");
    this->textures["floor3"] = IMG_LoadTexture(renderer, "ressources/assets/floor3.png");
    this->textures["image"] = IMG_LoadTexture(renderer, "ressources/assets/image.png");
    this->textures["player"] = IMG_LoadTexture(renderer, "ressources/assets/player.png");
    this->textures["error"] = IMG_LoadTexture(renderer, "ressources/assets/Icone.png");

    bool gaucheAppuye = false;
    bool droiteAppuye = false;
    bool hautAppuye = false;
    bool basAppuye = false;

    Uint32 startTime = 0;
    Uint32 endTime = 0;
    Uint32 frameCount = 0;
    float avgFPS = 0;
    bool windows_on = true;
    while (windows_on)
    {
        startTime = SDL_GetTicks();

        system("clear");
        std::cout << checkColision(169) << std::endl;
        SDL_Event event;
        if (checkColision(90))
        {
            windows_on = !windows_on;
        }
        while (SDL_PollEvent(&event))
        {
            // std::cout << "x: " << m->getPosPlayerX() << " y: " << m->getPosPlayerY() << std::endl;
            if (event.type == SDL_QUIT)
            {
                windows_on = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    gaucheAppuye = true;
                    break;
                case SDLK_RIGHT:
                    droiteAppuye = true;
                    break;
                case SDLK_UP:
                    hautAppuye = true;
                    break;
                case SDLK_DOWN:
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
                case SDLK_LEFT:
                    gaucheAppuye = false;
                    break;
                case SDLK_RIGHT:
                    droiteAppuye = false;
                    break;
                case SDLK_UP:
                    hautAppuye = false;
                    break;
                case SDLK_DOWN:
                    basAppuye = false;
                    break;
                default:
                    break;
                }
            }
        }

        if (droiteAppuye)
        {
            movetoright(10);
            if (checkColision(169))
            {
                movetoleft(10);
            }
            if (checkColision(174))
            {
                movetoleft(5);
            }
        }

        if (gaucheAppuye)
        {
            movetoleft(10);
            if (checkColision(169))
            {
                movetoright(10);
            }
            if (checkColision(174))
            {
                movetoright(5);
            }
        }

        if (hautAppuye)
        {
            movetotop(10);
            if (checkColision(169))
            {
                movetobot(10);
            }
            if (checkColision(174))
            {
                movetobot(5);
            }
        }

        if (basAppuye)
        {
            movetobot(10);
            if (checkColision(169))
            {
                movetotop(10);
            }
            if (checkColision(174))
            {
                movetotop(5);
            }
        }

        SDL_Rect grass1 = {100, 100, 100, 100};
        SDL_Rect darksoul1 = {200, 100, 100, 100};
        // SDL_SetRenderTarget(renderer, target);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // SDL_RenderCopy(renderer, grass, NULL, &grass1); // Dessiner la texture 1
        // SDL_RenderCopy(renderer, darksoul, NULL, &darksoul1); // Dessiner la texture 2

        for (int y = 0; y < var::HEIGHT; y += 1)
        {
            for (int i = 0; i < var::WIDTH; i += 1)
            {

                // 255 -> floor1
                // 90 -> image.png
                // 169 -> floor3
                // 174 water

                SDL_Rect rect = {0 + i * 50, 0 + y * 50, 50, 50};
                switch (this->m->getSurface((i * 100) + y))
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

                default:
                    SDL_RenderCopy(renderer, this->textures["error"], NULL, &rect);
                    break;
                }
            }
        }

        // SDL_SetRenderTarget(renderer, NULL);

        SDL_Rect playerRect = {m->getPosPlayerX(), m->getPosPlayerY(), 50, 50};
        SDL_RenderCopy(renderer, this->textures["player"], NULL, &playerRect);
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
            // system("clear");
            // printf("fps: %.2f, total frame: %d\n", avgFPS, frameCount);
        }

        // Limiter le FPS pour économiser les ressources CPU
        if (frameTime < 1000 / 60)
        {
            SDL_Delay((1000 / 60) - frameTime);
        }
    }

    clearTexture();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool interface::checkColision(int block)
{
    int x = m->getPosPlayerX();
    int y = m->getPosPlayerY();

    printf("arrondi: x:%d y:%d\n", x / 50, y / 50);
    printf("arrondi: x:%d y:%d\n", arronditofiveteen(x) / 50, arronditofiveteen(y) / 50);

    // if (m->getSurface(((x / 50) * 100) + (y / 50)) == block || m->getSurface((((x + 49) / 50) * 100) + ((y + 49) / 50)) == block || m->getSurface((((x + 49) / 50) * 100) + (y / 50)) == block || m->getSurface(((x / 50) * 100) + ((y + 49) / 50)) == block)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    if (m->getSurface((((x + 49) / 50) * 100) + ((y + 49) / 50)) == block || m->getSurface(((x  / 50) * 100) + ((y+49) / 50)) == block)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int interface::arronditofiveteen(int i)
{
    i++;
    while (!(i % 50 == 0))
    {
        i -= 1;
    }
    return i;
}

void interface::movetoright(int i)
{
    m->setPosPlayer(m->getPosPlayerX() + i, m->getPosPlayerY());
}

void interface::movetoleft(int i)
{
    m->setPosPlayer(m->getPosPlayerX() - i, m->getPosPlayerY());
}

void interface::movetotop(int i)
{
    m->setPosPlayer(m->getPosPlayerX(), m->getPosPlayerY() - i);
}

void interface::movetobot(int i)
{
    m->setPosPlayer(m->getPosPlayerX(), m->getPosPlayerY() + i);
}