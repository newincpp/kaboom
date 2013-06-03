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
        std::cout << std::endl;
        
        std::vector<std::string> vec;
        vec.push_back("one string");
        vec.push_back("two string");
        vec.push_back("templates are cools");
        vec.push_back("final string!");
        std::cout << l.callFun<char *>("third_arg_table", vec) << std::endl;
        
    }
    catch (const LuaScript::Exception& e) {
        std::cout << "LuaScript error: " << e.what() << std::endl;
    }
}
