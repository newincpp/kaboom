//
// Player.cpp for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:39 2013 Dorian Stroher
// Last update Thu Jun  6 17:02:50 2013 Dorian Stroher
//

#include <unistd.h>
#include "Player.hh"

Player::Player(newin::SceneMgr *bbman, int col, int row, Map *map)
{
  _obj = bbman->addModel("wall.obj", "Mur");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  bbman->setCamPos(newin::Vector3D<GLfloat>((col * SIZECASE )-2, 5, (row * SIZECASE) -2));
  //_obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  std::cout << "New player" << std::endl;
  _obj->setPlayer(this);
  _life = 1;
  _pos.second = col;
  _pos.first = row;
  _map = map->getMap();
}

void Player::moddifPos()
{

}

void Player::move(gdl::Input &i)
{
  if (i.isKeyDown(gdl::Keys::W) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.first = _pos.first + 1;
      if (checkMove((*_map)[_pos]) == true)
	{
	  _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
	  usleep(100000);
	  (*_map)[_pos] = this;
	}
      else
	{
	_pos.first = _pos.first - 1;
	(*_map)[_pos] = this;
	}
    }
  if (i.isKeyDown(gdl::Keys::S) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.first = _pos.first - 1;
      if (checkMove((*_map)[_pos]) == true)
	{
	  _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
	  usleep(100000);
	  (*_map)[_pos] = this;
	}
      else
	{
	_pos.first = _pos.first + 1;
	(*_map)[_pos] = this;
	}
    }
  if (i.isKeyDown(gdl::Keys::A) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.second = _pos.second - 1;
      if (checkMove((*_map)[_pos]) == true)
	{
	  _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
	  usleep(100000);
	  (*_map)[_pos] = this;
	}
      else
	{
	_pos.second = _pos.second + 1;
	(*_map)[_pos] = this;
	}
    }
  if (i.isKeyDown(gdl::Keys::D) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.second = _pos.second + 1;
      if (checkMove((*_map)[_pos]) == true)
	{
	  _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
	  usleep(100000);
	  (*_map)[_pos] = this;
	}
      else
	{
	_pos.second = _pos.second - 1;
	(*_map)[_pos] = this;
	}
    }
  return;
}

bool Player::checkMove(IObject *toto)
{
  if (toto != NULL)
    if (toto->getType() == type__Wall || toto->getType() == type__Player)
      return (false);
  return (true);
}
