#include <iostream>
#include <string>

class item
{

public:
    item();
    item(std::string name);
    item(std::string name, void (*function_to_apply)());
    void* getApply();

private:
    int id;
    std::string name;
    void (*apply)();
};