#include "LuaScript.h"

int main(void)
{
    LuaScript l;
    double d;
    bool b;
    char *c;

    try {
        l.loadScript("script.lua");

        l.callFun("additionazi", &d, 40, 1, 1);
        std::cout << "return: " << d << std::endl;

        l.callFun("test_bool", &b, true);
        std::cout << "return: " << b << std::endl;

        l.callFun("print_char", &c, std::string("zizi"));
        std::cout << c << std::endl; 

        l.callFun("giraul", std::string("poireaux"));

        //l.callFun("zizi", NULL);
    }
    catch (const LuaScript::Exception& e) {
        std::cout << "LuaScript error: " << e.what() << std::endl;
    }
}
