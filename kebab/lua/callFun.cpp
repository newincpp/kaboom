template <typename T>
void LuaScript::callFunReal(const T& value)
{
}

template <typename T>
void LuaScript::callFunReal(int value)
{
    lua_pushnumber(_L, value);
}

template <typename T, typename... U>
void LuaScript::callFunReal(const T& head, const U&... tail)
{
    callFunReal(head);
    callFunReal(tail...);
}

template <typename T, typename... U>
void LuaScript::callFun(const std::string& name, const T& head, const U&... tail)
{
    lua_getglobal(_L, name.c_str());

    callFunReal(head, tail...);

    lua_call(_L, 3, 1);
    std::cout << "Lua fun result: " << lua_tointeger(_L, -1) << std::endl;
    lua_pop(_L, 1);
}

