#include "player.h"
#include "map.h"

int main()
{
  //Tracks whether the game has been exited.
  bool has_quit = false;
  /*player player;
  while(!has_quit)
  {
    string input;
    //Checks if a command has been executed.
    bool c_ex = 0;
    cin >> input;
    boost::to_upper(input);
    if(input == "S" || input == "STATUS")
    {
      status(player);
      c_ex = 1;
    }
    if(input == "H" || input == "HELP")
    {
      help();
      c_ex = 1;
    }
    if(input == "Q" || input == "QUIT")
    {
      quit(has_quit);
      c_ex = 1;
    }
    if(!c_ex)
      cout << input << " is an invalid command. Type help for a list of commands." << endl;
  }*/
  tile_map my_map(5, 5);
  my_map.map_fill('g');
  my_map.map_print();
  return 0;
}
