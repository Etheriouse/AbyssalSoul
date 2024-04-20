#include <iostream>
#include "../headers/function.h"
#include "../headers/item.h"
#include "../headers/object.h"
#include "../headers/entity.h"

using namespace std;

void EstusFunction(entity *target, entity *source) {
    int dammageSource = source->getDamage();
    target->setHealt(target->getHealt()-dammageSource);
}

int main(int argc, char const *argv[])
{
    entity *player = new entity(20, 2);
    entity *mob = new entity(20, 2);

    object *bomba = new object("bomba", &EstusFunction);
    item test = item("test");
    bomba->apply(mob, player);
    //bomba->apply(mob, player);
    cout << mob->getHealt() << endl;
    cout << "Project work!" << endl;
    return 1;
}
