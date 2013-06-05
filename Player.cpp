//
// Player.cpp for Player in /home/strohe_d/Svn/kaboom
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Fri May 31 14:46:39 2013 Dorian Stroher
// Last update Mon Jun  3 17:33:08 2013 Dorian Stroher
//

#include "Player.hh"

Player::Player(newin::SceneMgr *bbman, std::pair<int, int> pos, Map *map)
{
  _obj = bbman->addModel("test.obj", "Mur");/**Init le pointeur sur fonction**/
  //  _obj->setPtr(&Player::Move); POUR PILOU
  _obj->setPos(newin::Vector3D<GLfloat>(pos.first * SIZECASE, 0.1, pos.second * SIZECASE));
  _map = map->getMap();
  _life = 1;
  _pos = pos;
}

void Player::moddifPos()
{

}

bool Player::moveRight()
{
  std::pair<int, int> newPos;

 _map[]
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

/*bool Player::move(gdl::Input &i)
{

POUR PILOU
}*/

bool getObj(IObject *)
{

  return (true);
}
