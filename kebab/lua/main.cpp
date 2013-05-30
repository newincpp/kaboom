#include "LuaScript.h"

int main(int ac, char **av)
{
    LuaScript l;
    try {
        l.loadScript("script.lua");
        l.callFun("additionazi", 40, 1, 1);
        l.callFun("additionazi", 40, 1, 1);
    }
    catch (const LuaScript::Exception& e) {
        std::cout << "LuaScript error: " << e.what() << std::endl;
    }
}
