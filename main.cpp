#include <iostream>
#include <exception>
#include <cstdlib>

//#include "libgdl_gl-2012.4/include/Clock.hpp"
//#include "libgdl_gl-2012.4/include/Color.hpp"
//#include "libgdl_gl-2012.4/include/Game.hpp"
//#include "libgdl_gl-2012.4/include/GameClock.hpp"
//#include "libgdl_gl-2012.4/include/Image.hpp"
//#include "libgdl_gl-2012.4/include/Input.hpp"
//#include "libgdl_gl-2012.4/include/Model.hpp"
//#include "libgdl_gl-2012.4/include/Window.hpp"

#include "App.hh"

int main() {
    App bbman;

    try {
	bbman.run();
    } catch (const std::exception& e) {
	std::cerr << "\033[1;31m FATAL ERROR : " << std::endl << e.what() << std::endl;
    }
    return EXIT_SUCCESS;

}
