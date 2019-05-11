//Constructor and the needed functions.
player::player()
{
  string input;
  choose_name();
  choose_sex();
  //Implement choose_class() here.
  cout << "Alright then. So you're " << name << " the " << p_class << man() << endl;
  cout << "Y\N" << endl;
  cin >> input;
  if(yn(input))
  {
    cout << "Alreighty then. Thank ya for filling out the census form and I hope you have a hell of a time in Rolland." << endl;
    data_confirmed = 1;
  }
  else
  {
  	bool choice_made;
    cout << "My apologies then. Where'd I hear ya wrong?" << endl;
    cout << "  1. My name.\n" << "  2. My sex.\n" << " 3. NOT YET IMPLEMENTED" << "  4. All of it!" << endl;
    cin >> input;
    while(!choice_made)
    {
      if(input == '1')
      {
        choose_name();
        choice_made = 1;
      } 
      if(input == '2')
      {
        choose_sex();
        choice_made = 1;
      }
      //Choose class
      if(input == '4')
      {
        choose_name()
        choose_sex()
        //Choose class
        choice_made = 1;
      }
      else
      {
      	cout << "Sorry, I couldn't hear ya. What'd you say?" << endl;
      	cin >> input;
	  }
   }
  }
  return;
}

//Chooses a name for the player.
void player::choose_name()
{
  string input;
  cout << "What's yer name?" << endl;
  cin.ignore(256, \n);
  getline(cin, name);
  if(name.length() >= 30)
    name = name.substr(0, name.length() - 1);
  cout << "Yer name is... " << name << " then, right?" << endl;
  cin >> input;
  if(yn(input))
    return;
  else
  {
  	cout << "Sorry 'bout that, heard ya wrong. "
    choose_name();
    return;
  }
}

//Chooses a sex for the player.

void player::choose_sex()
{
  string input;
  cout << "An' what's yer sex? Male or female?" << endl;
  cin >> input;
  boost::to_upper(input);
  if(input == "M" || input == "MALE" || input == "MAN" || input == "BOY")
	sex = 1;
  if(input == "F" || input == "FEMALE" || input == "WOMAN" || input == "GIRL")
	sex = 0;
  if(input == "TRAP")
  {
    cout << "No Tyler, that's not a real sex. I'll just make you male." << endl;
    sex = 1;
  }
  else
  {
	cout << "Sorry, I'm not sure what that is. "  << endl;
	choose_sex();
	return;
  }
  return;
}

//Returns strings dependent on sex.

sring player::he()
{
  if(sex)
    return "he";
  return "she";
}

string player::man()
{
  if(sex)
    return "man";
  return "woman";
}

string player::his
{
  if(sex)
    return "his";
  return "her";
}

//Checks yes/no responses

bool yn(string input)
{
  boost::to_upper(input);
  //Maybe I should just make an array of valid yes inputs, but either way I'm only typing it once.
  if(input == "Y" || input == "YES" || input == "YE" || input == "YA" || input == "YEAH" || input == "OK" || input == "YEP" || input == "YUP")
    return true;
  if(input == "N" || input == "NO" || input == "NOPE" || input == "NAH")
    return false;
  else
  {
  	cout << "Invalid response to a yes/no prompt. Please try again." << endl;
  	cin >> input;
	return yn(input);
  }
}
