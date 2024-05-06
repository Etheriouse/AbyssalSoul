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
    // this->textures["water"] = IMG_LoadTexture(renderer, "ressources/assets/water.png");
    this->textures["lava"] = IMG_LoadTexture(renderer, "ressources/assets/2d/lava.png");
    // this->textures["floor1"] = IMG_LoadTexture(renderer, "ressources/assets/floor1.png");
    // this->textures["floor3"] = IMG_LoadTexture(renderer, "ressources/assets/floor3.png");
    // this->textures["image"] = IMG_LoadTexture(renderer, "ressources/assets/image.png");
    this->textures["player"] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_idle.png");
    this->textures["menu"] = IMG_LoadTexture(renderer, "ressources/assets/menu.png");
    // this->textures["grass"] = IMG_LoadTexture(renderer, "ressources/assets/grass.png");
    this->textures["background"] = IMG_LoadTexture(renderer, "ressources/assets/background.jpg");
    this->textures["error"] = IMG_LoadTexture(renderer, "ressources/assets/2d/error.png");
    this->textures["dark_brick"] = IMG_LoadTexture(renderer, "ressources/assets/2d/dark_brick.png");
    this->textures["light_brick"] = IMG_LoadTexture(renderer, "ressources/assets/2d/light_brick.png");
    this->textures["open_door"] = IMG_LoadTexture(renderer, "ressources/assets/2d/open_door.png");
    this->textures["abyss"] = IMG_LoadTexture(renderer, "ressources/assets/2d/abyss_world.png");
}

void interface::run()
{
    loadTextures();

    bool gaucheAppuye = false;
    bool droiteAppuye = false;
    bool hautAppuye = false;
    bool basAppuye = false;
    bool sprint = false;
    bool jump = false;
    bool jump_started = false;
    bool it = false;

    int time_jump = 0;
    const int time_max_jump = 25;
    double acceleration = 2;
    vector direction = vector(0, 0);
    vector vitesse = vector(0, 0);
    vector gravity = vector(0, 1);
    const double vitesse_fall_max = 12;
    const double vitesse_jump_max = 6;
    const double vitesse_max_nosprint = 5;
    const double vitesse_max_sprint = 7;
    double vitesse_max = vitesse_max_nosprint;

    bool escapeMenuOn = false;

    auto start = std::chrono::high_resolution_clock::now();
    long frames = 0;
    double fps = 0;
    this->m->setPosPlayer(3250, 3100);
    SDL_Rect rect;
    SDL_Rect backgroundRect = {0, 0, 1600, 900};
    SDL_Event event;
    rectangle hitboxPlayer = rectangle(10, 10, 40, 40);

    SDL_Texture *walk[4] = {};
    walk[0] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_1.png");
    walk[1] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_2.png");
    walk[2] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_3.png");
    walk[3] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_walking_4.png");

    SDL_Texture *hurt[3] = {};
    hurt[0] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_hurt_1.png");
    hurt[1] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_hurt_2.png");
    hurt[2] = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_hurt_3.png");

    SDL_Texture *fall_jump = IMG_LoadTexture(renderer, "ressources/assets/player/Witchcraft_jump.png");

    int tick = 0;
    int frameSpriteWalk = 0;
    int frameSpriteHurt = 0;
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
            // std::cout << event.key.keysym.sym << std::endl;

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
                case SDLK_SPACE:
                    jump = true;
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
                case SDLK_SPACE:
                    jump = false;
                    break;
                default:
                    break;
                }
            }
        }

        if (sprint)
        {
            vitesse_max = vitesse_max_sprint;
        }
        else
        {
            vitesse_max = vitesse_max_nosprint;
        }

        if (jump && isFloor(169, hitboxPlayer))
        {
            jump_started = true;
        }

        if (!jump)
        {
            jump_started = false;
            time_jump = 0;
            direction.y = 0;
        }

        if (jump_started)
        {
            time_jump++;
        }

        if (time_jump > time_max_jump)
        {
            jump_started = false;
            time_jump = 0;
            direction.y = 0;
        }

        direction.x = 0;
        direction.y = 0;

        if (jump_started)
        {
            direction.y = -1;
        }
        else
        {
            direction.y = 0;
        }

        if (droiteAppuye)
        {
            direction.x = 1;
        }

        if (gaucheAppuye)
        {
            direction.x = -1;
        }

        if (direction.y != 0)
        {
            vitesse.y += direction.y * (acceleration + 1);
        }
        else if (!isFloor(169, hitboxPlayer))
        {
            printf("tu ajoute quoi dans se cas la gros fdp de tes grand mort la: %.2f\n", (gravity.y * acceleration));
            vitesse.y = vitesse.y + (gravity.y * (acceleration - 0.5));
            printf("ALORS PK TU AJOUTE PAS ENCULER %.2f\n", vitesse.y);
        }

        vitesse.x += direction.x * acceleration;

        if (direction.x == 0)
        {
            if (vitesse.x > 0)
            {
                vitesse.x -= (acceleration + 1);
            }
            else
            {
                vitesse.x += (acceleration + 1);
            }

            if (vitesse.x <= 3)
            {
                vitesse.x = 2;
            }
            if (vitesse.x <= 2)
            {
                vitesse.x = 1;
            }
            if (vitesse.x <= 1)
            {
                vitesse.x = 0;
            }

            if (vitesse.x >= -3)
            {
                vitesse.x = -2;
            }
            if (vitesse.x >= -2)
            {
                vitesse.x = -1;
            }
            if (vitesse.x >= -1)
            {
                vitesse.x = 0;
            }
        }

        std::cout << "direction y: " << direction.y << std::endl;
        std::cout << "jumpstard: " << jump_started << std::endl;
        std::cout << "vitesse en y: " << vitesse.y << std::endl;
        std::cout << "vitesse en x: " << vitesse.x << std::endl;

        if (vitesse.x > vitesse_max)
        {
            vitesse.x = vitesse_max;
        }

        else if (vitesse.x < (-vitesse_max))
        {
            vitesse.x = (-vitesse_max);
        }

        if (vitesse.y > vitesse_fall_max)
        {
            vitesse.y = vitesse_fall_max;
        }
        if (vitesse.y < (-vitesse_jump_max))
        {
            vitesse.y = (-vitesse_jump_max);
        }
        /*
        else if (vitesse.y < (-vitesse_max))
        {
            vitesse.y = (-vitesse_max);
        }
        */

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
        // if (checkColision(174))
        //{
        //     moveY(-vitesse.y / 2);
        // }
        if (checkColision(169, hitboxPlayer))
        {
            moveY(-vitesse.y);
            vitesse.y = 0;
        }
        if (checkColision(10))
        {
            moveY(-vitesse.y);
        }

        if (isFloor(169, hitboxPlayer))
        {
            std::cout << "floor touched" << std::endl;
        }
        else
        {
            std::cout << "floor not" << std::endl;
        }

        // std::cout << "player posSS: " << m->getPosPlayerX() << " " << m->getPosPlayerY() << std::endl;
        //  view->update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, this->textures["background"], NULL, &backgroundRect);

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
                // std::cout << "x: " << i / 50 << " y: " << y / 50 << std::endl;
                switch (this->m->getSurface(parseXmoin + c, parseYmoin + u))
                {
                    // case 255:
                    //     SDL_RenderCopy(renderer, this->textures["floor1"], NULL, &rect);
                    //     break;
                    // case 91:
                    //     SDL_RenderCopy(renderer, this->textures["image"], NULL, &rect);
                    //     break;
                    // case 169:
                    //     SDL_RenderCopy(renderer, this->textures["floor3"], NULL, &rect);
                    //     break;
                    // case 174:
                    //     SDL_RenderCopy(renderer, this->textures["water"], NULL, &rect);
                    //     break;
                    // case 124:
                    //     SDL_RenderCopy(renderer, this->textures["lava"], NULL, &rect);
                    //     break;
                    // case 154:
                    //     SDL_RenderCopy(renderer, this->textures["grass"], NULL, &rect);
                    //     break;
                    // case 10:
                    //     SDL_RenderCopy(renderer, this->textures["water"], NULL, &rect);
                    //     break;

                case 39:
                    break;
                case 176:
                    SDL_RenderCopy(renderer, this->textures["light_brick"], NULL, &rect);
                    break;
                case 169:
                    SDL_RenderCopy(renderer, this->textures["dark_brick"], NULL, &rect);
                    break;
                case 124:
                    SDL_RenderCopy(renderer, this->textures["lava"], NULL, &rect);
                    break;
                case 96:
                    SDL_RenderCopy(renderer, this->textures["open_door"], NULL, &rect);
                    break;
                case 10:
                    SDL_RenderCopy(renderer, this->textures["abyss"], NULL, &rect);
                    break;

                default:
                    SDL_RenderCopy(renderer, this->textures["error"], NULL, &rect);
                    break;
                }
                /**
                 * 39 -> nothing
                 * 176 -> lightbrick
                 * 169 -> darkbrick
                 * 124 -> lava
                 * 96-> woden door
                 * 10 -> abyss worldborder
                 *
                 */
                // 255->floor1 90->image.png 169->floor3 174->water 124->lava 154->grass 10->world border
            }
        }

        SDL_Rect playerRect = {800, 450, 50, 50};
        if (tick % 15 == 0)
        {
            frameSpriteWalk += 1;
            frameSpriteWalk %= 4;
        }

        if(tick%250==0) {
            it = true;
        }


        if (it)
        {
            if(tick%15 == 0) {
                frameSpriteHurt++;
                if(frameSpriteHurt == 3) {
                    it = false;
                }
                frameSpriteHurt %=3;
            }
            SDL_RenderCopy(renderer, hurt[frameSpriteHurt], NULL, &playerRect);
        }
        else
        {
            if (vitesse.x == 0 && vitesse.y == 0)
            {
                SDL_RenderCopy(renderer, this->textures["player"], NULL, &playerRect);
            }
            else if (vitesse.y != 0)
            {
                SDL_RenderCopy(renderer, fall_jump, NULL, &playerRect);
            }
            else
            {
                SDL_RenderCopy(renderer, walk[frameSpriteWalk], NULL, &playerRect);
            }
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
            //    system("clear");
            //    printf("fps: %.2f, total frame: %d\n", fps, tick);

            start = std::chrono::high_resolution_clock::now();
            frames = 0;
        }
        std::cout << "jump isactiv: " << jump_started << std::endl;
        std::cout << "jump tick: " << time_jump << std::endl;
        printf("fps: %.2f, total frame: %d\n", fps, frames);
        // std::this_thread::sleep_for(std::chrono::milliseconds(7)); // 60 fps (1/60 * 1000 ≈ 16.67) 144 fps ( 1/144 * 1000 ≈ 6.944)

        system("clear");
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // 60 fps (1/60 * 1000 ≈ 16.67) 144 fps ( 1/144 * 1000 ≈ 6.944)
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

bool interface::isFloor(int block, rectangle r)
{
    int x = m->getPosPlayerX();
    int y = m->getPosPlayerY();

    /*
     * a b
     * c d
     */

    bool a = m->getSurface((x + r.a) / 50, (y + r.b) / 50) == block;
    bool b = m->getSurface((x + r.c) / 50, (y + r.b) / 50) == block;
    bool c = m->getSurface((x + r.a) / 50, (y + r.d + 1) / 50) == block;
    bool d = m->getSurface((x + r.c) / 50, (y + r.d + 1) / 50) == block;

    if (c || d)
    {

        return true;
    }
    else
    {
        return false;
    }
}
