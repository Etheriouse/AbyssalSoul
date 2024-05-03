#include "../headers/rectangle.h"

rectangle::rectangle()
{
    this->a = 0;
    this->b = 0;
    this->c = 1;
    this->d = 1;
}

rectangle::rectangle(int x, int y, int z, int t)
{
    this->a = x;
    this->b = y;
    this->c = z;
    this->d = t;
}

rectangle::rectangle(vector v1, vector v2)
{
    this->a = v1.x;
    this->b = v1.y;
    this->c = v2.x;
    this->d = v2.y;
}

rectangle::rectangle(rectangle *r)
{
    this->a = r->a;
    this->b = r->b;
    this->c = r->c;
    this->d = r->d;
}