#ifndef __LUASCRIPT__
# define __LUASCRIPT__

# include <iostream>
# include <exception>
# include <vector>
//# include <typeinfo>

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
        void callFunReal(const T& value);

        template <typename T>
        void callFunReal(const std::vector<T>& value);
        
        template <typename T, typename... U>
        void callFunReal(const T& head, const U&... tail);

        template <typename Z, typename... T>
        Z callFun(const std::string&, const T&...);

        template <typename Z>
        Z callFun(const std::string&);

        /*
        template <typename... T>
        void callFun(const std::string&, const T&...);
        */

        template <typename T>
        T returnType();
 
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
        bool limiter;
        lua_State *_L;

};

# include "callFun.cpp"

#endif
