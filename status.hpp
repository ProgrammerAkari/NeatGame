#include "map.h"
#include "player.h"

//Outputs the player's current status and info.
void status(player &player)
{
  cout << "Name: " << player.g_name() << endl;
  //Formats player sex.
  string sex = player.male();
  sex[0] = toupper(sex[0]);
  cout << "Sex: " << sex << endl;
  cout << "Class: " << player.g_class() << endl;
  return;
}

//Exits the game
void quit(bool &has_quit)
{
  has_quit = true;
}

//Outputs a list of commands.
void help()
{
  cout << "h OR help brings up a list of commands" << endl;
  cout << "s OR status outputs the player's current status" << endl;
  cout << "m OR map prints out the current map" << endl;
  cout << "left OR l, right OR r, up OR u, and down OR d move your character in that direction." << endl;
  cout << "ul (up left), ur (up right), dl (down left), and dr (down right) will move your character diagonally." << endl;
  cout << "q OR quit exits the game" << endl;
  return;
}

//Checks if a mvoe is valid

bool check_move(int row, int col, tile_map &map)
{
  string err = "Invalid move.\n";
  //Checks if you're attempting to move off the map.
  if(row < 0 || row >= map.rows())
  {
    cout << err;
    return false;
  }
  if(col < 0 || col >= map.cols())
  {
    cout << err;
    return false;
  }
  //Checks if the tile is passable or not.
  if(!map.m_map[row][col].passable)
  {
    cout << err;
    return false;
  }
  //Otherwise...
  return true;
}

//Checks to see if an input is valid.
void check_input(string input, player &player, tile_map * &current_map, bool &has_quit)
{
  boost::to_upper(input);
  if(input == "S" || input == "STATUS")
  {
    status(player);
    return;
  }
  if(input == "H" || input == "HELP")
  {
    help();
    return;
  }
  if(input == "Q" || input == "QUIT")
  {
    quit(has_quit);
    return;
  }
  if(input == "M" || input == "MAP")
  {
    current_map->print(player.pos);
    return;
  }
  if(input == "D" || input == "DOWN")
  {
    int row = player.pos[0] + 1;
    int col = player.pos[1];
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "U" || input == "UP")
  {
    int row = player.pos[0] - 1;
    int col = player.pos[1];
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "R" || input == "RIGHT")
  {
    int row = player.pos[0];
    int col = player.pos[1] + 1;
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "L" || input == "LEFT")
  {
    int row = player.pos[0];
    int col = player.pos[1] - 1;
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "DL")
  {
    int row = player.pos[0] + 1;
    int col = player.pos[1] - 1;
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "DR")
  {
    int row = player.pos[0] + 1;
    int col = player.pos[1] + 1;
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "UR")
  {
    int row = player.pos[0] - 1;
    int col = player.pos[1] + 1;
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  if(input == "UL")
  {
    int row = player.pos[0] - 1;
    int col = player.pos[1] - 1;
    if(check_move(row, col, *current_map))
    {
      player.move(row, col);
      current_map->print(player.pos);
    }
    return;
  }
  cout << input << " is an invalid command. Type help for a list of commands." << endl;
}
