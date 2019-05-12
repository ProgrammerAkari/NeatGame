#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "termcolor.hpp"

//Holds a single area's map.

class tile
{
  private:

  public:
    //Is the character the tile is displayed as.
    char display_char;
    //Name of the tile.
    string name;
    //Color of the tile.
    string color = "black";
    //Shows whether the tile is passable or not.
    bool passable;
    //Constructor
    tile(char display = 'p', string n = "placeholder", string c = "black", bool pass = true);

};

class tile_map
{
  private:
    int m_cols;
    int m_rows;
    //Tiles will be defined by characters.
    tile ** m_map;
  public:
    //Constructor
    tile_map(int cols, int rows);
    //Deconstructor
    ~tile_map();

    //Change tiles
    void map_fill(tile tile);
    void tile_range(int col1, int col2, int row1, int row2, tile tile);
    void tile_change(int col, int row, tile tile);

    //Prints the map
    void print();
};

//Default tile declarations
tile tree('T', "Tree", "green");
tile grass('g', "Grass", "green");
tile house('h', "House", "black", false);
tile door('d', "door");

#include "map.hpp"

#endif
