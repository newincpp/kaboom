#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "displayManager.hh"

int main() {
    try {
	newin::Display e;
	//char *fb = new char[e.lenAlloc()];
	//e >> fb;
	e.run();
    } catch (std::exception& e) {
	std::cerr << e.what() << std::endl;
	return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
