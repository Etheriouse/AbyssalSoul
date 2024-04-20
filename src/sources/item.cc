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

item::item(std::string name, void (*function_to_apply)())
{
    this->name = name;
    this->id = 0;
    this->apply = apply;
}

void *item::getApply() {
    return this->apply;
}