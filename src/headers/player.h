#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>

#include "entity.h"
#include "item.h"
#include "weapon.h"
#include "object.h"
#include "ring.h"

class player : public entity {

public:
    player();
    player(int vitality);
    player(int vitality, int endurance, int strength, int dexterity, int faith);
    int* getStat();
    weapon getWeapons_selected();
    object getObject_selected();
    weapon* getWeapons();
    object* getObjects();
    ring* getRings();
    std::vector<item> getIventory();

    void setWeaponsSelected(weapon w);
    void setObjectSelected(object o);
    void setObjects(object o, int index);
    void setWeapons(weapon w, int index);
    void setRings(ring r, int index);
    void setInventory(item i, int index);

private:
    int vitality; //-> up healt -> log(vitalitypoint)/log(30)*1000
    int endurance; // -> up nb action by round
    int strength; // -> up damage in function of weapons
    int dexterity; // -> up damage in function of weapons
    int faith; // -> up damage in function of weapons
    std::vector<item> inventory;
    weapon weapons_selected;
    object object_selected;
    weapon weapons[5];
    object objects[5];
    ring rings[5];
};

#endif