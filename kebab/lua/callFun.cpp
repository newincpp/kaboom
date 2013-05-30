template <typename T>
void LuaScript::callFunReal(const T& value)
{
    std::cout << "no type... :/" << std::endl;
}

template <typename T, typename... U>
void LuaScript::callFunReal(const T& head, const U&... tail)
{
    callFunReal(head);
    callFunReal(tail...);
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
    callFunReal(head, tail...);
    lua_call(_L, (sizeof...(tail) + 1), 1);
    lua_pop(_L, 1);
}

template <typename T>
void LuaScript::returnType(T type)
{
    std::cout << "Warning: no return defined." << std::endl;
}
