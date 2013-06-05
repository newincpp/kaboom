#include <iostream>
#include <exception>
#include <cstdlib>
#include <list>
#include "Scene.hh"
#include "Map.hh"

int main() {
    newin::SceneMgr bbman;
    Map map1(10, 10, bbman);

    try {
      /*	AObject* tmp = bbman.addModel("plane.obj", "map");
	tmp->setPos(newin::Vector3D<GLfloat>(0.1,0.1,0.1));

	tmp = bbman.addModel("test.obj", "vesseau");
	tmp->setPos(newin::Vector3D<GLfloat>(0.1, 1, 0.1));
	tmp->setRot(newin::Vector3D<GLfloat>(0.1, 30, 0.1));

	tmp = bbman.addModel("sphere.obj", "sphere");
	tmp->setPos(newin::Vector3D<GLfloat>(3.1, 1.1, 0.1));

	bbman.run();*/
    } catch (const std::exception& e) {
	std::cerr << "\033[1;31m FATAL ERROR : " << std::endl << e.what() << std::endl;
    }
    return EXIT_SUCCESS;

}
