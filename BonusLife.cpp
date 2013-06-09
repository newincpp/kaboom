 //
// BonusLife.cpp for BonusLife in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Sun Jun  9 06:46:10 2013 Dorian Stroher
//

#include "BonusLife.hh"
#include "Mesh.hh"

BonusLife::BonusLife(newin::SceneMgr *bbman, int col, int row)
{
  _obj = bbman->addModel("bonus.obj", "Mur");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 0.1, 0.1));
  _obj->setColor(newin::Vector3D<GLfloat>(80, 80, 80));
  /*  _obj = bbman->addModel("bonus.obj", "Bon");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setColor(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));*/
}

void	BonusLife::moddifPos()
{
}

void	BonusLife::deleteOBJ()
{
  //delete(this);
}

BonusLife::~BonusLife()
{
  _obj->toogleRendering();
  //  _objARM->toogleRendering();
  //  delete (_obj);
}
