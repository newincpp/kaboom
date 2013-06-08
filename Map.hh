//
// Map.hh for Map in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Mon May 27 16:50:23 2013 Dorian Stroher
// Last update Sat Jun  8 03:28:41 2013 Dorian Stroher
//

#ifndef __MAP_HH__
#define __MAP_HH__

#include <iostream>
#include <map>
#include "Wall.hh"
#include "Scene.hh"

class Map
{
public:
  Map(int row, int col, newin::SceneMgr bbman);
  ~Map();
  std::map<std::pair<int, int>, IObject *>  *getMap();
private:
  std::map<std::pair<int, int>, IObject *> _map;
  int _row;
  int _col;
};

#endif
