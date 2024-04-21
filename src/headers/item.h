#ifndef Item_h
#define Item_h

#include <iostream>
#include <string>

#include "entity.h"

class item
{

public:
    item();
    item(std::string name);
    item(std::string name, std::string description);
    item(std::string name, void (*function_to_apply)(entity *target, entity *source));
    item(std::string name, std::string description, void (*function_to_apply)(entity *target, entity *source));
    //void (*getApply())();
    void apply(entity *target, entity *source);

protected:
    int id;
    std::string name;
    std::string description;
    void (*toExecute)(entity *target, entity *source);
};

#endif