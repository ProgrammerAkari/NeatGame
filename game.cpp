#include "player.h"
#include "map.h"

int main()
{
  //Tracks whether the game has been exited.
  bool has_quit = false;
  player player("Tyler", 1, "Chef");
  //Initializes the home map.
  map_home.map_fill(t_tree);
  map_home.tile_range(5, 14, 5, 14, t_grass);
  map_home.tile_range(8, 12, 8, 12, t_house);
  map_home.tile_change(10 , 8, t_door);
  tile_map *current_map = nullptr;
  current_map = &map_home;
  while(!has_quit)
  {
    string input;
    cin >> input;
    check_input(input, player, current_map, has_quit);
  }
  return 0;
}
