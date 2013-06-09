#include <iostream>
#include <exception>
#include <cstdlib>
#include <list>
#include "Scene.hh"
#include "Map.hh"
#include "AudioPlayer.hh"

static pthread_t t;

static void *EntryPoint(void * music)
{
 static_cast<AudioPlayer*>(music)->play();
 return NULL;
}

int main() {
  AudioPlayer *music = new  AudioPlayer;
  music->loadFile("resources/music/tron.flac");
    newin::SceneMgr bbman;
  try {
    pthread_create(&t, NULL, EntryPoint, music);
    Map map1(20, 20, bbman);
    music->destroySource();
    music->cleanUp();
  } catch (const std::exception& e) {
    std::cerr << "\033[1;31m FATAL ERROR : " << std::endl << e.what() << std::endl;
  }
  /* try {
     * AObject* tmp = bbman.addModel("plane.obj", "map");
     * tmp->setPos(newin::Vector3D<GLfloat>(0.1,0.1,0.1));
     *
     * tmp = bbman.addModel("player.obj", "player");
     * tmp = bbman.addModel("playerArm.obj", "playerout");
     * ((newin::Mesh*)tmp)->toogleWireframe();
     *
     * tmp = bbman.addModel("wall.obj", "wall");
     *
     * newin::Camera* c = bbman.getCam();
     * c->setPos(newin::Vector3D<GLfloat>(100,100,100));
     *
     * bbman.run();
     * } catch (const std::exception& e) {
     * std::cerr << "\033[1;31m FATAL ERROR : " << std::endl << e.what() << std::endl;
     * }*/
    return EXIT_SUCCESS;
}
