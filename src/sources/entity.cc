#include <iostream>
#include "../headers/entity.h"

entity::entity()
{
    this->healt = 20;
    this->max_healt = 20;
}

entity::entity(int max_healt)
{
    this->healt = max_healt;
    this->max_healt = max_healt;
}

int entity::getMaxhealt()
{
    return this->max_healt;
}

int entity::getHealt()
{
    return this->healt;
}

void entity::setMaxhealt(int h)
{
    this->max_healt = h;
}

void entity::setHealt(int h)
{
    this->healt = h;
}
