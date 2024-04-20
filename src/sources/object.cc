#include <iostream>

#include "../headers/object.h"
#include "../headers/entity.h"
#include "../headers/item.h"

object::object() {
    this->id  = 0;
    this->name = "none";
}

object::object(std::string name)
{
    this->name=name;
    this->id=0;
}

object::object(std::string name, void (*function_to_apply)(entity *target, entity *source))
{
    this->name = name;
    this->id = 0;
    this->toExecute = function_to_apply;
}
