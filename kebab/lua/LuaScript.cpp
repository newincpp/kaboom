#include "LuaScript.h"

typedef const char* charity;

LuaScript::LuaScript()
{
    _L = lua_open();
    luaopen_base(_L);
    limiter = true;
}

LuaScript::~LuaScript()
{
    lua_close(_L);
}

void LuaScript::loadScript(const std::string& name)
{
    if ((luaL_dofile(_L, name.c_str())) == 1)
        throw Exception("cannot load file " + name);
}


/*
 * callFunReal specialization
 * iterates on every type that can be pushed on the lua stack
*/

template <>
void LuaScript::callFunReal<int>(const int& value)
{
    lua_pushnumber(_L, value);
}

template <>
void LuaScript::callFunReal<double>(const double& value)
{
    lua_pushnumber(_L, value);
}

template <>
void LuaScript::callFunReal<std::string>(const std::string& value)
{
    lua_pushstring(_L, value.c_str());
}

template <>
void LuaScript::callFunReal<charity>(const charity& value)
{
    lua_pushstring(_L, value);
}

template <>
void LuaScript::callFunReal<bool>(const bool& value)
{
    lua_pushboolean(_L, value);
}



/*
 * returnType
 * iterates on every known lua return type
*/

template <>
int LuaScript::returnType<int>()
{
    return (lua_tonumber(_L, -1));
}

template <>
double LuaScript::returnType<double>()
{
    return (lua_tonumber(_L, -1));
}

template <>
bool LuaScript::returnType<bool>()
{
    return (lua_toboolean(_L, -1));
}

template <>
char *LuaScript::returnType<char *>()
{
    return (const_cast<char*>(lua_tostring(_L, -1)));
}



/*
 * callFun specialization 
 * no parameters and no return type
*/

void LuaScript::callFun(const std::string& name)
{
    lua_getglobal(_L, name.c_str());
    lua_pcall(_L, 0, 0, 0);
    lua_pop(_L, 1);
}
