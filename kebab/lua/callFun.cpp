template <typename T>
int LuaScript::callFunReal(const T& value)
{
    return 1;
}

template <typename T, typename... U>
int LuaScript::callFunReal(const T& head, const U&... tail)
{
    int ret = 0;

    if (callFunReal(head) == 1)
        ret = 1;
    if (callFunReal(tail...) == 1)
        ret = 1;
    return ret;
}

template <typename Z, typename T, typename... U>
void LuaScript::callFun(const std::string& name, Z* ret, const T& head, const U&... tail)
{
    lua_getglobal(_L, name.c_str());
    callFunReal(head, tail...);
    lua_call(_L, (sizeof...(tail) + 1), 1);
    returnType(ret);
    lua_pop(_L, 1);
}

template <typename T, typename... U>
void LuaScript::callFun(const std::string& name, const T& head, const U&... tail)
{
    lua_getglobal(_L, name.c_str());
    if (callFunReal(head, tail...) == 1)
        lua_pcall(_L, 0, 0, 0);
    else
        lua_call(_L, (sizeof...(tail) + 1), 0);
    lua_pop(_L, 1);
}

template <typename T>
void LuaScript::returnType(T type)
{
    std::cout << "Warning: no return defined." << std::endl;
}
