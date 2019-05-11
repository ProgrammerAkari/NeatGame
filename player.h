#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Inventory
class inventory
{
  private:
  	
  public:
}

//Holds the player
class player
{
  private:
  	//Member variable declarations
  	string name;
  	//Class
  	string p_class = "placeholder";
  	//1 = male, 0 = female
  	bool sex;
  	//Stats
  	int s_hp;
  	int s_mp;
  	int s_cha;
  	int s_str;
  	int s_dex;
  	int s_per;
  	int s_int;
  	int s_con;
  	int s_will;
  	//Inv
  	inventory inventory;
  	
  public:
  	//Constructor
  	player();
  	
  	//Deconstructor
  	~player();
  	
  	//Sets name
  	s_name(string name);
  	
	  //Sets gender
  	s_gender(bool gender);
  	
  	//Returns name
  	string name();
  	
  	//Returns gender
  	bool gender();
  	
  	//Returns he/she
  	string he();
  	
  	//Returns his/her
  	string his();
  	
  	//Returns man/woman
  	string man();
  	
  	
}

#include "player.hpp"

#endif

