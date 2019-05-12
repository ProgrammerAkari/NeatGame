#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "termcolor.hpp"

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

    //Change tiles
    void map_fill(char tile);
    void tile_range(int col1, int col2, int row1, int row2, char tile);
    void tile_change(int col, int row, char tile);

    //Prints the map
    void print();
};

#include "map.hpp"

#endif
