#include <iostream>
#include <stdlib.h>
#include "LoadSO.hh"

int main(void)
{
    try {
        LoadSO so("IA/ia.so");
        so.callFunc("zizi");
        std::cout << (char*)so.getRet() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        exit(0);
    }
}
