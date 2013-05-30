#ifndef __LUASCRIPT__
# define __LUASCRIPT__

# include <iostream>
# include <exception>
# include <typeinfo>

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
        
        template <typename T, typename... U>
        void callFunReal(const T& head, const U&... tail);

        template <typename Z, typename T, typename... U>
        void callFun(const std::string& name, Z*, const T& head, const U&... tail);

        template <typename T, typename... U>
        void callFun(const std::string& name, const T& head, const U&... tail);

        template <typename T>
        void returnType(T);
 
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

# include "callFun.cpp"

#endif
