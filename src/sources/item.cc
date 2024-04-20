#include <iostream>
#include <string>

#include "../headers/item.h"

item::item()
{
    this->name="none";
    this->id=-1;
}

item::item(std::string name)
{
    this->name=name;
    this->id=0;
}

item::item(std::string name, void (*function_to_apply)(entity *target, entity *source))
{
    this->name = name;
    this->id = 0;
    this->toExecute = function_to_apply;
}

//void (*item::getApply())() {
//    return this->apply;
//}

void item::apply(entity *target, entity *source) {
    this->toExecute(target, source);
}