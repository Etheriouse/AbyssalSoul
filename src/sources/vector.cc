#include "../headers/vector.h"

vector::vector()
{
    this->x = 0;
    this->y = 0;
}

vector::vector(int x, int y)
{
    this->x = x;
    this->y = y;
}

vector::vector(vector *v)
{
    this->x = v->x;
    this->y = v->y;
}

void vector::productLambda(int l)
{
    this->x *= l;
    this->y *= l;
}

void vector::productLambda(double l)
{
    this->x *= l;
    this->y *= l;
}

void vector::productVector(vector v)
{
    this->x *= v.x;
    this->y *= v.y;
}

void vector::additionLambda(double l)
{
    this->x += l;
    this->y += l;
}

void vector::additionLambda(int l)
{
    this->x += l;
    this->y += l;
}

void vector::additionVector(vector v)
{
    this->x += v.x;
    this->y += v.y;
}
