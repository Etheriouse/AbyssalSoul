#include <iostream>

#include "../headers/map.h"
#include "../headers/vector.h"
#include "../headers/function.h"

map::map()
{
    this->level_global = 1;
    this->p = new player();
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->mobs = std::map<int, mob>();
    this->player_x = 0;
    this->player_y = 0;
}

map::map(int level_global)
{
    this->level_global = level_global;
    this->p = new player();
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->mobs = std::map<int, mob>();
    this->player_x = 0;
    this->player_y = 0;
}

map::map(int level_global, player *p)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->mobs = std::map<int, mob>();
    this->player_x = 0;
    this->player_y = 0;
}

map::map(int level_global, player *p, int surface[var::HEIGHT][var::WIDTH])
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            this->surface[i][j] = surface[i][j];
        }
    }
    this->mobs = std::map<int, mob>();
    this->player_x = 0;
    this->player_y = 0;
}

map::map(int level_global, player *p, int surface[var::HEIGHT][var::WIDTH], std::map<int, mob> mobs)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            this->surface[i][j] = surface[i][j];
        }
    }
    this->mobs = mobs;
    this->player_x = 0;
    this->player_y = 0;
}

map::map(int level_global, player *p, image surface)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            int *rgb = surface.getPixel(vector(j, i));
            int average = (rgb[0] + rgb[1] + rgb[2])/3;
            this->surface[i][j] = average;
            delete(rgb);
        }
    }
    this->mobs = std::map<int, mob>();
    this->player_x = 0;
    this->player_y = 0;
}

map::map(int level_global, player *p, image surface, std::map<int, mob> mobs)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < var::HEIGHT; ++i)
    {
        for (int j = 0; j < var::WIDTH; ++j)
        {
            int *rgb = surface.getPixel(vector(j, i));
            int average = (rgb[0] + rgb[1] + rgb[2])/3;
            this->surface[i][j] = average;
            delete(rgb);
        }
    }
    this->mobs = mobs;
    this->player_x = 0;
    this->player_y = 0;
}

player *map::getPlayer()
{
    return this->p;
}

std::map<int, mob> map::getMobs()
{
    return this->mobs;
}

int map::getLevelGlobal()
{
    return this->level_global;
}

int map::getSurface(int x, int y)
{
    return this->surface[y][x];
}

int map::getPosPlayerX()
{
    return this->player_x;
}

int map::getPosPlayerY()
{
    return this->player_y;
}

int map::getHeight()
{
    return var::HEIGHT;
}

int map::getWidth()
{
    return var::WIDTH;
}

void map::setPlayer(player *p)
{
    this->p = p;
}

void map::setMobs(std::map<int, mob> mobs)
{
    this->mobs = mobs;
}

void map::setLevelGlobal(int level_global)
{
    this->level_global = level_global;
}

void map::setSurface(int x, int y, int value)
{
    this->surface[y][x] = value;
}

void map::setPosPlayer(int x, int y)
{
    this->player_x = x;
    this->player_y = y;
}

void map::show(bool number)
{

    for (int i = 0; i < var::HEIGHT; i++)
    {
        for (int y = 0; y < var::WIDTH; y++)
        {
            if (number)
            {
                std::cout << this->surface[i][y] << " ";
            }
            else
            {
                switch (this->surface[i][y])
                {
                case 255:
                    std::cout << ". ";
                    break;

                case 0:
                    std::cout << "# ";
                    break;

                default:
                    std::cout << "* ";
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}