//
// Bomb.cpp for Bomb in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Wed May 22 15:51:26 2013 Dorian Stroher
// Last update Sun Jun  9 01:05:58 2013 Dorian Stroher
//

#include "Bomb.hh"
#include "Mesh.hh"

Bomb::Bomb(newin::SceneMgr *bbman, int col, int row, int power)
{
  _row = row;
  _col = col;
  _power = power;
  _obj = bbman->addModel("bomb.obj", "Mur");
  _objARM = bbman->addModel("bombARM.obj", "Mur");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _objARM->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _objARM->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  ((newin::Mesh*)_objARM)->toogleWireframe();
  _myClock.play();
 }

void	Bomb::moddifPos()
{

}

void	Bomb::deleteOBJ()
{
  delete(this);
}

bool Bomb::explode(std::map<std::pair<int, int>, IObject *>  *_map)
{
  std::pair<int, int> it;

  _myClock.update();
  if (_myClock.getTotalElapsedTime() >= 2)
    {
      delete(this);
      it.first = _row;
      it.second = _col;
      while (it.first < _row + _power)
	{
	  if ((*_map)[it] != NULL)
	    if (((*_map)[it])->getType() == type__Wall2)
	      {
		delete((*_map)[it]);
		(*_map)[it] = NULL;
	    break;
	      }
      if ((*_map)[it] != NULL)
	if (((*_map)[it])->getType() == type__Wall)
	  break;
      it.first++;
	}
      it.first = _row;
      it.second = _col;
      while (it.second < _col + _power)
	{
	  if ((*_map)[it] != NULL)
	    if (((*_map)[it])->getType() == type__Wall2 || ((*_map)[it])->getType() == type__Player)
	      {
		((*_map)[it])->deleteOBJ();
		(*_map)[it] = NULL;
		break;
	      }
	  if ((*_map)[it] != NULL)
	    if (((*_map)[it])->getType() == type__Wall)
	      break;
	  it.second++;
	}
      it.first = _row;
      it.second = _col;
      return (true);
    }
  /*  if ((*_map)[it] != NULL)
    {
    delete((*_map)[it]);
    (*_map)[it] = NULL;
    }*/
  return (false);
}

Bomb::~Bomb()
{
  _obj->toogleRendering();
  _objARM->toogleRendering();
  //  delete (_obj);
}
