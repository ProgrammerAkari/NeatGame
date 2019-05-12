//Outputs the player's current status and info.
void status(player player)
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
  cout << "q OR quit exits the game" << endl;
  return;
}

//Checks to see if an input is valid.
void check_input(string input, player player, bool &has_quit)
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
  cout << input << " is an invalid command. Type help for a list of commands." << endl;
}
