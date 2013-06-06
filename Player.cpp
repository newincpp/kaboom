//
// Player.cpp for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:39 2013 Dorian Stroher
// Last update Wed Jun  5 16:35:10 2013 Dorian Stroher
//

#include <unistd.h>
#include "Player.hh"
#include "Mesh.hh"

Player::Player(newin::SceneMgr *bbman, int col, int row, Map *map)
{
  _obj = bbman->addModel("player.obj", "player");
  _obj->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _obj->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));

  _objARM = bbman->addModel("playerARM.obj", "playerCT");
  _objARM->setPos(newin::Vector3D<GLfloat>(col * SIZECASE, 0.1, row * SIZECASE));
  _objARM->setRot(newin::Vector3D<GLfloat>(0.1, 90, 0.1));
  ((newin::Mesh*)_objARM)->toogleWireframe();

  _map = map->getMap();
  std::cout << "New player" << std::endl;
  _obj->setPlayer(this);
  //_objARM->setPlayer(this);
  _life = 1;
  _pos.second = col;
  _pos.first = row;
}

void Player::moddifPos()
{

}

bool Player::moveRight()
{
  std::pair<int, int> newPos;

 return (true);
}

bool Player::moveLeft()
{
  return (true);

}

bool Player::moveUp()
{

  return (true);
}

bool Player::moveDown()
{

  return (true);
}

void Player::move(gdl::Input &i)
{
  if (i.isKeyDown(gdl::Keys::W) == true)
    {
      _pos.first = _pos.first + 1;
      _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      _objARM->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      usleep(100000);
    }
  if (i.isKeyDown(gdl::Keys::S) == true)
    {
      _pos.first = _pos.first - 1;
      _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      _objARM->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      usleep(100000);
    }
  if (i.isKeyDown(gdl::Keys::A) == true)
    {
      _pos.second = _pos.second - 1;
      _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      _objARM->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      usleep(100000);
    }
  if (i.isKeyDown(gdl::Keys::D) == true)
    {
      _pos.second = _pos.second + 1;
      _obj->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      _objARM->setPos(newin::Vector3D<GLfloat>( (_pos.second) * SIZECASE, 0.1,( _pos.first) * SIZECASE));
      usleep(100000);
    }
  return;
}

bool getObj(IObject *)
{
  return (true);
}
