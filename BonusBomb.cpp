//
// Bomb.cpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Sun Jun  9 05:40:05 2013 Dorian Stroher
//

#include "BonusBomb.hh"
#include "Mesh.hh"

BonusBomb::BonusBomb(newin::SceneMgr *bbman, int col, int row)
{
  _obj = bbman->addModel("bonus.obj", "Bomb");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setColor(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
}

void	BonusBomb::moddifPos()
{
}

void	BonusBomb::deleteOBJ()
{
  delete(this);
}

BonusBomb::~BonusBomb()
{
  _obj->toogleRendering();
  //  _objARM->toogleRendering();
  //  delete (_obj);
}
