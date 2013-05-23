#include "LoadSO.hh"

LoadSO::LoadSO(const std::string& name)
{
    if ((_handleSO = dlopen(name.c_str(), RTLD_NOW)) == NULL)
        throw (std::runtime_error(dlerror()));
}

void *LoadSO::callFunc(const std::string& fun)
{
    void *(*fct)(int, int);

    *(void**)(&fct) = dlsym(_handleSO, fun.c_str());
    if (fct == NULL)
        throw (std::runtime_error(dlerror()));
    _ret = (((*fct))(99999, 1));
    return (_ret);
}

LoadSO::~LoadSO()
{
    dlclose(_handleSO);
}
