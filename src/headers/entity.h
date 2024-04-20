#include <iostream>

class entity {

public:
    entity();
    entity(int max_healt, int damage);
    int getMaxhealt();
    int getHealt();
    int getDamage();

private:
    int healt;
    int max_healt;
    int damage;

};