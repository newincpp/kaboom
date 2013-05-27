#ifndef LOAD_SO_
#define LOAD_SO_

# include <stdexcept>
# include <dlfcn.h>

class LoadSO
{

    public:
        LoadSO(const std::string&);
        void *callFunc(const std::string&);
        virtual ~LoadSO();
        void *getRet() { return (_ret); }

    protected:
        void *_handleSO;
        void *_ret;

};

#endif /*LOAD_SO_*/

class Exhibitionniste
{

    public:
        int getZizi();
        void useCapote();

    protected:
        int zizi;

};
