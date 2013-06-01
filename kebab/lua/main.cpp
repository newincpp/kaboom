#include "LuaScript.h"

int main(void)
{
    LuaScript l;

    try {
        l.loadScript("script.lua");

        std::cout << l.callFun<int>("addition", 40, 1, 1) << std::endl << std::endl;
        std::cout << l.callFun<char *>("is_true", true) << std::endl << std::endl;
        std::cout << l.callFun<char *>("is_true", false) << std::endl << std::endl;
        std::cout << l.callFun<char *>("hello_string", std::string("yuyuko")) << std::endl << std::endl;
        std::cout << l.callFun<char *>("no_param") << std::endl << std::endl;
        l.callFun("no_param2");
        //l.callFun("show_string", std::string("this string is cool"));
    }
    catch (const LuaScript::Exception& e) {
        std::cout << "LuaScript error: " << e.what() << std::endl;
    }
}
