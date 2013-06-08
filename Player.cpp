//
// Player.cpp for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:39 2013 Dorian Stroher
// Last update Sat Jun  8 03:49:58 2013 Dorian Stroher
//

#include <unistd.h>
#include "Player.hh"
#include "Mesh.hh"
#define DISTANCE 9
#define DISTANCELUM 2
#define LUMINTENSITY 0.4

Player::Player(newin::SceneMgr *bbman, int col, int row, Map *map)
{
  _bbman = bbman;
  _light = bbman->getLight(0);
  _obj = bbman->addModel("player.obj", "player");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _cam = bbman->getCam();
  _cam->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, DISTANCE, row * SIZECASE));
  _light->setIntensity(LUMINTENSITY);
  _light->setDiff(1);
  _light->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, DISTANCELUM, row * SIZECASE));
  _cam->setRot(newin::Vector3D<GLfloat>(90, 0.1, 0.1));
  _light->setRot(newin::Vector3D<GLfloat>(60, 0.1, 0.1));
  //_obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  _objARM = bbman->addModel("playerARM.obj", "player");
  _objARM->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _objARM->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  ((newin::Mesh*)_objARM)->toogleWireframe();
  _map = map->getMap();
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
  std::pair<int, int> prevpos;
  float x;
  newin::Mesh *test;

  prevpos = _pos;
  if (i.isKeyDown(gdl::Keys::S) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.first = _pos.first + 1;
        }
  else if (i.isKeyDown(gdl::Keys::W) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.first = _pos.first - 1;
        }
  else if (i.isKeyDown(gdl::Keys::A) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.second = _pos.second - 1;
    }
  else if (i.isKeyDown(gdl::Keys::D) == true)
    {
      (*_map)[_pos] = NULL;
      _pos.second = _pos.second + 1;
    }
  if (checkMove((*_map)[_pos]) == true)
    {
      /*      for (x = _pos.first -1; x < _pos.first; x = x + 0.1)
	{
	usleep(1000000);
	  }*/
      _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0,(_pos.first) * SIZECASE));
      _objARM->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0,(_pos.first) * SIZECASE));
      _cam->setPos(newin::Vector3D<GLfloat>((_pos.second) * SIZECASE, DISTANCE,(_pos.first) * SIZECASE));
      _light->setPos(newin::Vector3D<GLfloat>((_pos.second) * SIZECASE, DISTANCELUM,(_pos.first) * SIZECASE));
      (*_map)[_pos] = this;
      usleep(75000);
    }
  else
    {
      _pos = prevpos;
    (*_map)[prevpos] = this;
    }
  if (i.isKeyDown(gdl::Keys::Space) == true)
    {
      std::cout << "Je pose une bombe" << std::endl;
      usleep(500000);
    }
  return;
}

bool Player::checkMove(IObject *toto)
{
  if (toto != NULL)
    if (toto->getType() == type__Wall || toto->getType() == type__Player || toto->getType() == type__Wall2 )
      return (false);
  return (true);
}
