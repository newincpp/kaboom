template <typename T>
void LuaScript::callFunReal(const T& value)
{
}

// recursive variadic template.
// iterates with specialization to push arguments to the lua stack.
template <typename T, typename... U>
void LuaScript::callFunReal(const T& head, const U&... tail)
{
    callFunReal(head);
    callFunReal(tail...);
}

template <typename Z, typename... T>
Z LuaScript::callFun(const std::string& name, const T&... args)
{
    Z ret;

    // the function is now registered to later be called
    lua_getglobal(_L, name.c_str());
    // this will push the arguments to the lua stack
    callFunReal(args...);
    // the function with be called [sizeof...(args) = number of arguments]
    lua_call(_L, sizeof...(args), 1);
    // returning depending of the type passed on parameter
    ret = returnType<Z>();
    lua_pop(_L, 1);
    return (ret);
}

template <typename Z>
Z LuaScript::callFun(const std::string& name)
{
    Z ret;

    lua_getglobal(_L, name.c_str());
    lua_pcall(_L, 0, 1, 0);
    ret = returnType<Z>();
    lua_pop(_L, 1);
    return (ret);
}

template <typename T>
T LuaScript::returnType()
{
    throw Exception("warning: no return defined");
}
