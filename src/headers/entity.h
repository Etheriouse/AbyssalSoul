#ifndef Entity_h
#define Entity_h

#include <iostream>

class entity {

public:
    entity();
    entity(int max_healt, int damage);
    int getMaxhealt();
    int getHealt();
    int getDamage();

    void setMaxhealt(int h);
    void setHealt(int h);
    void setDamage(int d);

protected:
    int healt;
    int max_healt;
    int damage;

};

#endif // Entity_h