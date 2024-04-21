#include <iostream>
#include <cmath>

#include "../headers/player.h"
#include "../headers/weapon.h"
#include "../headers/object.h"
#include "../headers/ring.h"
#include "../headers/item.h"

player::player(int vitality)
{
    this->healt = (int)(log(this->vitality) / log(30)) * 1000;
    this->max_healt = (int)(log(this->vitality) / log(30)) * 1000;
    this->vitality = vitality;
    this->endurance = 1;
    this->dexterity = 1;
    this->strength = 1;
    this->faith = 1;
}

player::player(int vitality, int endurance, int strength, int dexterity, int faith)
{
    this->healt = (int)(log(this->vitality) / log(30)) * 1000;
    this->max_healt = (int)(log(this->vitality) / log(30)) * 1000;
    this->vitality = vitality;
    this->endurance = endurance;
    this->dexterity = dexterity;
    this->strength = strength;
    this->faith = faith;
}

/**
 * @return un tableau dynamique contenant les statistique du joueur
 * @note ne pas oublier de delete le tableau pour liberer la memoire
 */
int *player::getStat()
{
    return new int[5]{5, 6, 6, 6, 6};
}

weapon player::getWeapons_selected()
{
    return this->weapons_selected;
}

object player::getObject_selected()
{
    return this->object_selected;
}

object *player::getObjects()
{
    return this->objects;
}

weapon *player::getWeapons()
{
    return this->weapons;
}

ring *player::getRings()
{
    return this->rings;
}

std::vector<item> player::getIventory()
{
    return this->inventory;
}

void player::setWeaponsSelected(weapon w)
{
    this->weapons_selected = w;
}

void player::setObjectSelected(object o)
{
    this->object_selected = o;
}

void player::setObjects(object o, int index)
{
    this->objects[index] = o;
}

void player::setWeapons(weapon w, int index)
{
    this->weapons[index] = w;
}

void player::setRings(ring r, int index)
{
    this->rings[index] = r;
}

void player::setInventory(item i, int index)
{
    this->inventory[index] = i;
}