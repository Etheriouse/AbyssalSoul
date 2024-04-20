#include <iostream>
#include <vector>

#include "entity.h"
#include "item.h"

class player : entity {

public:
    player();

private:
    std::vector<item> inventory;
    item weapons_selected;
    item object_selected;
    item objects[5];
    item weapons[5];
    item rings[5];
};