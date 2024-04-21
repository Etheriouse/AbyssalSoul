#ifndef Entity_h
#define Entity_h

#include <iostream>

class entity {

public:
    entity();
    entity(int max_healt);
    int getMaxhealt();
    int getHealt();

    void setMaxhealt(int h);
    void setHealt(int h);

protected:
    int healt;
    int max_healt;

};

#endif // Entity_h