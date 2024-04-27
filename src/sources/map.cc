#include <iostream>

#include "../headers/map.h"
#include "../headers/function.h"

map::map()
{
    this->level_global = 1;
    this->p = new player();
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->mobs = std::map<int, mob>();
}

map::map(int level_global)
{
    this->level_global = level_global;
    this->p = new player();
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->mobs = std::map<int, mob>();
}

map::map(int level_global, player *p)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->mobs = std::map<int, mob>();
}

map::map(int level_global, player *p, int surface[64][64])
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            this->surface[i][j] = surface[i][j];
        }
    }
    this->mobs = std::map<int, mob>();
}

map::map(int level_global, player *p, int surface[64][64], std::map<int, mob> mobs)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            this->surface[i][j] = surface[i][j];
        }
    }
    this->mobs = mobs;
}

map::map(int level_global, player *p, image surface)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            int average = (surface.getPixel(j * 100 + i)[0] + surface.getPixel(j * 100 + i)[1] + surface.getPixel(j * 100 + i)[2]) / 3;
            this->surface[i][j] = average;
        }
    }
}

map::map(int level_global, player *p, image surface, std::map<int, mob> mobs)
{
    this->level_global = level_global;
    this->p = p;
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            int average = (surface.getPixel(j * 100 + i)[0] + surface.getPixel(j * 100 + i)[1] + surface.getPixel(j * 100 + i)[2]) / 3;
            this->surface[i][j] = average;
        }
    }
    this->mobs = mobs;
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

int map::getSurface(int xy)
{
    return this->surface[getY(xy)][getX(xy)];
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

void map::setSurface(int xy, int value)
{
    this->surface[getY(xy)][getX(xy)] = value;
}

void map::show(bool number)
{

    for (int i = 0; i < 64; i++)
    {
        for (int y = 0; y < 64; y++)
        {
            if(number) {
                std::cout << this->surface[i][y] << " ";
            } else {
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