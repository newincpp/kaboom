#include "LuaScript.h"

typedef char* charity;

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

template <>
int LuaScript::callFunReal<int>(const int& value)
{
    lua_pushnumber(_L, value);
    return 0;
}

template <>
int LuaScript::callFunReal<double>(const double& value)
{
    lua_pushnumber(_L, value);
    return 0;
}

template <>
int LuaScript::callFunReal<std::string>(const std::string& value)
{
    lua_pushstring(_L, value.c_str());
    return 0;
}

template <>
int LuaScript::callFunReal<charity>(const charity& value)
{
    lua_pushstring(_L, value);
    return 0;
}

template <>
int LuaScript::callFunReal<bool>(const bool& value)
{
    lua_pushboolean(_L, value);
    return 0;
}

template <>
void LuaScript::returnType<double*>(double *type)
{
    *type = lua_tonumber(_L, -1);
}

template <>
void LuaScript::returnType<bool*>(bool *type)
{
    *type = lua_toboolean(_L, -1);
}

template <>
void LuaScript::returnType<char **>(char **type)
{
    *type = const_cast<char*>(lua_tostring(_L, -1));
}

/*template <std::string>
void LuaScript::callFun(const std::string& name)
{
    lua_getglobal(_L, name.c_str());
    lua_call(_L, 0, 1);
    lua_pop(_L, 1);
}*/
