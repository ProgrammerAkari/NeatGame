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
  public:
    tile ** m_map;
    //Constructor
    tile_map(int cols, int rows);
    //Deconstructor
    ~tile_map();
    //Returns private variables
    int cols();
    int rows();

    //Change tiles
    void map_fill(tile &tile);
    void tile_range(int row1, int row2, int col1, int col2, tile &tile);
    void tile_change(int row, int col, tile &tile);

    //Prints the map
    void print(int player_pos[2]);
};

//Default tile declarations
tile t_tree('T', "Tree", "green");
tile t_grass('g', "Grass", "green");
tile t_house('h', "House", "black", false);
tile t_door('d', "door");

//Default map declarations

tile_map map_home(20, 20);
#include "map.hpp"

#endif
