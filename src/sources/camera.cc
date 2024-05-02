#include "../headers/camera.h"

camera::camera()
{
    for (int i = 0; i < var::C_HEIGHT; ++i)
    {
        for (int j = 0; j < var::C_WIDTH; ++j)
        {
            this->surface[i][j] = -1;
        }
    }
    this->origine = new map();
}

camera::camera(map *m)
{
    this->origine = m;

    int x = m->getPosPlayerX() / 50;
    int y = m->getPosPlayerY() / 50;

    int X_max_map = m->getWidth();
    int Y_max_map = m->getHeight();

    int startX = x - 16;
    int endX = x + 16;
    int startY = y - 9;
    int endY = y + 9;

    if (x - 16 < 0)
    {
        startX -= (x - 16);
        endX -= (x - 16);
    }
    else if (x + 16 > X_max_map)
    {
        startX += (X_max_map - x - 16);
        endX += (X_max_map - x - 16);
    }

    if (y - 9 < 0)
    {
        startY -= (y - 9);
        endY -= (y - 9);
    }
    else if (y + 9 > Y_max_map)
    {
        startY += (Y_max_map - y - 9);
        endY += (Y_max_map - y - 9);
    }

    for (int i = startY, a = 0; i < endY; a++, i++)
    {
        for (int z = startX, b = 0; z < endX; b++, z++)
        {
            this->surface[a][b] = m->getSurface(z, i);
        }
    }
}

void camera::update()
{
    int x = origine->getPosPlayerX() / 50;
    int y = origine->getPosPlayerY() / 50;

    int X_max_map = origine->getWidth();
    int Y_max_map = origine->getHeight();

    int startX = x - 16;
    int endX = x + 16;
    int startY = y - 9;
    int endY = y + 9;

    if (x - 16 < 0)
    {
        startX -= (x - 16);
        endX -= (x - 16);
    }
    else if (x + 16 > X_max_map)
    {
        startX += (X_max_map - x - 16);
        endX += (X_max_map - x - 16);
    }

    if (y - 9 < 0)
    {
        startY -= (y - 9);
        endY -= (y - 9);
    }
    else if (y + 9 > Y_max_map)
    {
        startY += (Y_max_map - y - 9);
        endY += (Y_max_map - y - 9);
    }

    std::cout << "pos Player: " << x << " " << y << std::endl;

    std::cout << "X: " << startX << " to " << endX << std::endl;
    std::cout << "Y: " << startY << " to " << endY << std::endl;


    for (int i = startY, a = 0; i < endY; a++, i++)
    {
        for (int z = startX, b = 0; z < endX; b++, z++)
        {
            this->surface[a][b] = origine->getSurface(z, i);
        }
    }
}

int camera::getSurface(int x, int y)
{
    return this->surface[y][x];
}
