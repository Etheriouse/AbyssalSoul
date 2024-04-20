#include <iostream>
#include "../headers/entity.h"

entity::entity() {
    this->healt = 20;
    this->max_healt = 20;
    this->damage = 2;
}

entity::entity(int max_healt, int damage) {
    this->healt = max_healt;
    this->max_healt = max_healt;
    this->damage = damage;
}

int entity::getMaxhealt() {
    return this->max_healt;
}

int entity::getHealt() {
    return this->healt;
}

int entity::getDamage() {
    return this->damage;
}