//
// Map.cpp for Mao in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Mon May 27 16:53:04 2013 Dorian Stroher
// Last update Fri May 31 16:41:11 2013 Dorian Stroher
//

#include "Map.hh"

Map::Map(int row, int col, newin::SceneMgr bbman)
{
  std::pair<int, int> it;

  /*  AObject* tmp = bbman.addModel("plane.obj", "map");
      tmp->setPos(newin::Vector3D<GLfloat>(0.1,0.1,0.1));*/
  _row = row;
  _col = col;
  it.first = 0;
  it.second = 0;
  while (it.first != row)
    {
      while (it.second != col)
	{
	  _map[it] = NULL;
	  if (it.second == 0 || it.first == 0)
	    _map[it] = new Wall(&bbman, it.second, it.first);
	  else if (it.first == (row -1) || it.second == (col - 1))
	    _map[it] = new Wall(&bbman, it.second, it.first);
	  it.second = it.second + 1;
	}
      it.second = 0;
      it.first = it.first + 1;
    }
  bbman.run();
}

std::map<std::pair<int, int>, IObject *> *Map::getMap()
{
  return (&_map);
}

Map::~Map()
{
  std::pair<int, int> it;

  it.first = 0;
  it.second = 0;
  while (it.first != _row)
    {
      while (it.second != _col)
	{
	  if (_map[it] != NULL)
	    delete (_map[it]);
	  it.second = it.second + 1;
	}
      it.second = 0;
      it.first = it.first + 1;
    }
}
