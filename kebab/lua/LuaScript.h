#ifndef __LUASCRIPT__
# define __LUASCRIPT__

# include <iostream>
# include <exception>

extern "C" {
# include "lua.h"
# include "lualib.h"
# include "lauxlib.h"
}

class LuaScript {

    public:
        LuaScript();
        virtual ~LuaScript();

        void loadScript(const std::string&);
        void callFun(const std::string&);

        template <typename T>
        void callFunReal(const T& value)
        {
        }

        void callFunReal(int value)
        {
            lua_pushnumber(_L, value);
        }

        template <typename T, typename... U>
        void callFunReal(const T& head, const U&... tail)
        {
            callFunReal(head);
            callFunReal(tail...);
        }

        template <typename T, typename... U>
        void callFun(const std::string& name, const T& head, const U&... tail)
        {
            lua_getglobal(_L, name.c_str());
            
            callFunReal(head, tail...);

            lua_call(_L, 3, 1);
            std::cout << "Lua fun result: " << lua_tointeger(_L, -1) << std::endl;
            lua_pop(_L, 1);
        }

        // exception
        class Exception : public std::exception {

            public:
                Exception(const std::string& msg) : _msg(msg) {}
                virtual ~Exception() throw() {}
                virtual const char *what() const throw() { return (_msg.c_str()); }

            private:
                std::string _msg;

        };

    private:
        lua_State *_L;
        bool limiter;

};

/*# include "callFun.cpp"*/

#endif
