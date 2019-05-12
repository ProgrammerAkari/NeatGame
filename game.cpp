#include "player.h"
#include "map.h"

int main()
{
  //Tracks whether the game has been exited.
  /*bool has_quit = false;
  player player;
  while(!has_quit)
  {
    string input;
    cin >> input;
    check_input(input, player, has_quit);
  }*/
  tile_map home(20, 20);
  home.map_fill(t_tree);
  home.tile_range(5, 14, 5, 14, t_grass);
  home.tile_range(8, 12, 8, 12, t_house);
  home.tile_change(8 ,10, t_door);
  home.print();
  return 0;
}
