#ifndef MAP_H
#define MAP_H

#include <iostream>

//Holds a single area's map.
class tile_map
{
  private:
    int m_cols;
    int m_rows;
    //Tiles will be defined by characters.
    char ** m_map;
  public:
    //Constructor
    tile_map(int cols, int rows);
    //Deconstructor
    ~tile_map();

    void map_fill(char tile);

    void map_print();
};

#include "map.hpp"

#endif
