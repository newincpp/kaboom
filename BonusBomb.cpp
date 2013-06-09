//
// Bomb.cpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Sun Jun  9 02:51:45 2013 Dorian Stroher
//

#include "BonusBomb.hh"
#include "Mesh.hh"

BonusBomb::BonusBomb(newin::SceneMgr *bbman, int col, int row)
{

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
