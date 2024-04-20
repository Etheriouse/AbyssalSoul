#ifndef Object_h
#define Object_h

#include <iostream>

#include "item.h"
#include "entity.h"

class object : public item {

public:
    object();
    object(std::string name);
    object(std::string name, void (*function_to_apply)(entity *target, entity *source));

};

#endif