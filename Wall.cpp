//
// Wall.cpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Fri May 31 13:19:46 2013 Dorian Stroher
//

#include "Wall.hpp"
#define SIZECASE 10000

Wall::Wall(newin::SceneMgr *bbman, int col, int row)
{
  AObject*  tmp = bbman->addModel("test.obj", "vesseau");
  tmp->setPos(newin::Vector3D<GLfloat>(0.1, 1, 0.1));
  //tmp->setRot(newin::Vector3D<GLfloat>(0.1, 30, 0.1));
  tmp->setRot(newin::Vector3D<GLfloat>(0.1, row * SIZECASE, col*SIZECASE));
}


Wall::~Wall()
{

}
