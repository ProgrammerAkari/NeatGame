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
