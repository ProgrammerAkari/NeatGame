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

//Constructor and the needed functions.
player::player()
{
  string input;
  choose_name();
  choose_sex();
  //cin.ignore(256, '\n');
  choose_class();
  cout << "Alright then. So you're " << name << " the " << class_sex() << " right?" << endl;
  cin >> input;
  if(yn(input))
  {
    cout << "Alreighty then. Thank ya for filling out the census form and I hope you have a hell of a time in Rolland." << endl;
  }
  //Allows one to change incorrect decisions in character select.
  else
  {
  	bool choice_made;
    cout << "My apologies then. Where'd I hear ya wrong?" << endl;
    cout << "  1. My name.\n" << "  2. My sex.\n" << "  3. My job.\n" << "  4. All of it!" << endl;
    cin >> input;
    while(!choice_made)
    {
      if(input == "1")
      {
        cin.ignore(256, '\n');
        choose_name();
        choice_made = 1;
      }
      if(input == "2")
      {
        choose_sex();
        choice_made = 1;
      }
      if(input == "3")
      {
        choose_class();
        choice_made = 1;
      }
      if(input == "4")
      {
        cin.ignore(256, '\n');
        choose_name();
        choose_sex();
        choose_class();
        choice_made = 1;
      }
      if(!choice_made)
      {
      	cout << "Sorry, I couldn't hear ya. What'd you say?" << endl;
      	cin >> input;
	  }
    }
  }
  return;
}

//Chooses a name for the player.
void player::choose_name(bool redo)
{
  string input;
  cout << "What's yer name?" << endl;
  if(redo)
    cin.ignore(256, '\n');
  getline(cin, name);
  if(name.length() >= 30)
    name = name.substr(0, 30);
  cout << "Yer name is... " << name << " then, right?" << endl;
  cin >> input;
  if(yn(input))
    return;
  else
  {
  	cout << "Sorry 'bout that, heard ya wrong. ";
    choose_name(1);
    return;
  }
}

//Chooses a sex for the player.

void player::choose_sex(bool redo)
{
  string input;
  cout << "An' what's yer sex? Male or female?" << endl;
  if(!redo)
    cin.ignore(256, '\n');
  getline(cin, input);
  boost::to_upper(input);
  if(input == "M" || input == "MALE" || input == "MAN" || input == "BOY")
  {
	sex = 1;
	return;
  }
  if(input == "F" || input == "FEMALE" || input == "WOMAN" || input == "GIRL")
  {
    sex = 0;
    return;
  }
  //It isn't.
  if(input == "TRAP")
  {
    cout << "No Tyler, that's not a real sex. I'll just make you male." << endl;
    sex = 1;
  }
  else
  {
	cout << "Sorry, I'm not sure what that is. ";
	choose_sex(1);
	return;
  }
  return;
}

//Chooses player class

void player::choose_class(bool redo)
{
  string input;
  cout << "Alright, and what's yer profession?" << endl;
  cout << "  1. Chef\n" << "  2. Strong" << man() << "\n  3. Mage." << endl;
  getline(cin, input);
  boost::to_upper(input);
  if(input == "1")
  {
    cout << "Oh, yer a chef?" << endl;
    cin >> input;
    if(yn(input))
    {
      p_class = "chef";
      return;
    }
  }
  if(input == "2")
  {
    cout << "Yer one of them strong" << man() << " that swings heavy stuff around then?" << endl;
    cin >> input;
    if(yn(input))
    {
      p_class = "strong";
      return;
    }
  }
  if(input == "3")
  {
    cout << "Oh? Yer a mage then, one of those spell-flingers?" << endl;
    cin >> input;
    if(yn(input))
    {
      p_class = "mage";
      return;
    }
  }
  //Should trigger if someone chooses no after selecting a valid class.
  if(input == "1" || input == "2" || input == "3")
  {
    cout << "Sorry, musta heard ya wrong. ";
    choose_class(1);
  }
  cout << "Er, I don't think that job's on tha list. Can you choose somethin' else? ";
  choose_class(1);
  return;
}
//Deconstructor

player::~player()
{
  return;
}

//Returns string dependent on sex and class.
string player::class_sex()
{
  if(p_class == "strong")
    return "strong" + man();
  else
    return p_class + " " + man();
}
//Returns strings dependent on sex.

string player::he()
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

string player::his()
{
  if(sex)
    return "his";
  return "her";
}
