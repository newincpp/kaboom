//
// Map.hh for Map in /home/strohe_d/Svn/kaboom/Valentin
// 
// Made by Dorian Stroher
// Login   <strohe_d@epitech.net>
// 
// Started on  Mon May 27 16:50:23 2013 Dorian Stroher
// Last update Fri May 31 13:01:05 2013 Dorian Stroher
//

#ifndef __MAP_HH__
#define __MAP_HH__

#include <iostream>
#include <map>
#include "Wall.hpp"
#include "Scene.hh"

class Map
{
public:
  Map(int row, int col, newin::SceneMgr bbman);
  ~Map();
  std::map<std::pair<int, int>, IBonus *>  getMap();
private:
  std::map<std::pair<int, int>, IBonus *> _map;
  int _row;
  int _col;
};

#endif
