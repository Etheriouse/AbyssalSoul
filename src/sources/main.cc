#include <iostream>
#include <cmath>

#include "../headers/function.h"
#include "../headers/item.h"
#include "../headers/object.h"
#include "../headers/entity.h"
#include "../headers/player.h"
#include "../headers/function.h"

using namespace std;

void EstusFunction(entity *target, entity *source) {
}

int main(int argc, char const *argv[])
{
    player *p = new player(10);
    int* stat = p->getStat();
    cout << "vitality: " << stat[0] << endl;
    delete[] stat;

    cout << "1478: " << getY(1478) << endl;
    cout << "Project work!" << endl;
    return 1;
}
