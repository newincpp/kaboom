#include "LuaScript.h"

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
