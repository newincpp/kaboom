//
// Wall.cpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Wed Jun  5 15:55:39 2013 Dorian Stroher
//

#include "Wall.hpp"

Wall::Wall(newin::SceneMgr *bbman, int col, int row)
{
  _obj = bbman->addModel("wall.obj", "Mur");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
}

void	Wall::moddifPos()
{

}

Wall::~Wall()
{

}
