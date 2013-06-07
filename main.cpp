#ifndef __DWIDTH
#define __DHEIGHT 800
#define __DWIDTH 600
#endif
#include <iostream>
#include <exception>
#include <cstdlib>
#include <list>
#include "Scene.hh"
#include "Map.hh"

int main() {
    newin::SceneMgr bbman;
    Map map1(50, 50, bbman);

    try {
      /*	AObject* tmp = bbman.addModel("plane.obj", "map");
	tmp->setPos(newin::Vector3D<GLfloat>(0.1,0.1,0.1));

	tmp = bbman.addModel("player.obj", "player");
	tmp = bbman.addModel("playerArm.obj", "playerout");
	((newin::Mesh*)tmp)->toogleWireframe();

	tmp = bbman.addModel("playerArm.obj", "playerout");
	((newin::Mesh*)tmp)->toogleWireframe();

	tmp = bbman.addModel("wall.obj", "wall");

	bbman.run();*/
    } catch (const std::exception& e) {
	std::cerr << "\033[1;31m FATAL ERROR : " << std::endl << e.what() << std::endl;
    }
    return EXIT_SUCCESS;

}
