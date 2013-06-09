//
// Map.cpp for Mao in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Mon May 27 16:53:04 2013 Dorian Stroher
// Last update Sun Jun  9 06:43:03 2013 Dorian Stroher
//

#include "Map.hh"
#include "Mesh.hh"
#include "Player.hh"
#include "BonusBomb.hh"
#include "BonusMouv.hh"
#include "BonusLife.hh"
#include "BonusRange.hh"
#include "Wall2.hh"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Map::Map(int row, int col, newin::SceneMgr bbman)
{
    std::pair<int, int> it;

    /*  AObject* tmp = bbman.addModel("plane.obj", "map");
	tmp->setPos(newin::Vector3D<GLfloat>(0.1,0.1,0.1));*/
    srand (time(NULL));
    AObject *tmp;

    _row = row;
    _col = col;
    it.first = 0;
    it.second = 0;
    while (it.first != row)
    {
	while (it.second != col)
	{
	  _map[it] = NULL;
	  if (rand()%5 == 0 && it.second != 0 && it.first != 0 && it.second != (col - 1) && it.first != (row - 1) )
	    _map[it] = new Wall2(&bbman, it.second, it.first);
	  if (rand()%20 == 0 && it.second != 0 && it.first != 0 && it.second != (col - 1) && it.first != (row - 1) )
	    {
	      delete (_map[it]);
	    _map[it] = new BonusBomb(&bbman, it.second, it.first);
	    }
	  if (rand()%20 == 0 && it.second != 0 && it.first != 0 && it.second != (col - 1) && it.first != (row - 1) )
	    {
	      delete (_map[it]);
	      _map[it] = new BonusRange(&bbman, it.second, it.first);
	    }
	  if (rand()%15 == 0 && it.second != 0 && it.first != 0 && it.second != (col - 1) && it.first != (row - 1) )
	    {
	      delete (_map[it]);
	    _map[it] = new BonusMouv(&bbman, it.second, it.first);
	    }
	  if (it.second == col/2 && it.first == row/2)
	    {
	      delete (_map[it]);
	      _map[it] = new BonusLife(&bbman, it.second, it.first);
	    }
	  if (it.second == 0 || it.first == 0)
	    _map[it] = new Wall(&bbman, it.second, it.first);
	  else if (it.first == (row -1) || it.second == (col - 1))
	    _map[it] = new Wall(&bbman, it.second, it.first);
	  it.second = it.second + 1;
	  tmp = bbman.addModel("grid.obj", "Grille");
	  tmp->setPos(newin::Vector3D<GLfloat>(it.second, 0.1, it.first));
	  ((newin::Mesh*)(tmp))->toogleWireframe();
	}
	it.second = 0;
	it.first = it.first + 1;
    }
    it.first = 3;
    it.second = 7;
    if (_map[it] != NULL)
    {
	delete(_map[it]);
	_map[it] = NULL;
    }
    _map[it] = new Player(&bbman, it.second, it.first, this, false);
    /*  delete (_map[it]);
	_map[it] = NULL;*/
    it.first = 5;
    it.second = 7;
    if (_map[it] != NULL)
    {
	delete(_map[it]);
	_map[it] = NULL;
    }
    _map[it] = new Player(&bbman, it.second, it.first, this, true);
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
