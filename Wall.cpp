//
// Wall.cpp for Wall in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Fri Jun  7 18:12:09 2013 Dorian Stroher
//

#include "Wall.hpp"
#include "Mesh.hh"

Wall::Wall(newin::SceneMgr *bbman, int col, int row)
{
 _objARM = bbman->addModel("wallARM.obj", "Mur");
  _obj = bbman->addModel("wall.obj", "Mur");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _objARM->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _objARM->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  ((newin::Mesh*)_objARM)->toogleWireframe();
 }

void	Wall::moddifPos()
{

}

Wall::~Wall()
{
  _obj->toogleRendering();
  _objARM->toogleRendering();
  //  delete (_obj);
}
