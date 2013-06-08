//
// Wall2.cpp for Wall2 in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Sun Jun  9 00:46:34 2013 Dorian Stroher
//

#include "Wall2.hh"
#include "Mesh.hh"

Wall2::Wall2(newin::SceneMgr *bbman, int col, int row)
{
  _objARM = bbman->addModel("wallARM.obj", "Mur");
  _obj = bbman->addModel("wall.obj", "Mur");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _obj->setColor(newin::Vector3D<GLfloat>(0.1, 0.1, 180));
  _objARM->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _objARM->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _objARM->setColor(newin::Vector3D<GLfloat>(0.1, 0.1, 180));
  ((newin::Mesh*)_objARM)->toogleWireframe();
 }

void    Wall2::deleteOBJ()
{
  delete(this);
}

void	Wall2::moddifPos()
{

}

Wall2::~Wall2()
{
  _obj->toogleRendering();
  _objARM->toogleRendering();
  //  delete (_obj);
}
