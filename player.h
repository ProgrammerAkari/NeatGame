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
};

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
  	inventory p_inventory;

  public:
    //Current position
  	int pos[2] = {0, 0};
  	//Constructors
  	player();
    player(string n, bool s, string ass);
    //User in the constructor.
    void choose_name(bool redo = 0);
    void choose_sex(bool redo = 0);
    void choose_class(bool redo = 0);

  	//Deconstructor
  	~player();

  	//Sets private variables.
  	void s_name(string new_name);
  	void s_sex(bool new_sex);
  	void s_class(string new_class);

  	//Returns private variables.
  	string g_name();
  	bool g_sex();
  	string g_class();

    //Returns a class and sex.
    string class_sex();

  	//Returns he/she
  	string he();

  	//Returns his/her
  	string his();

  	//Returns man/woman
  	string man();

    //Returns male/female
    string male();

     //Moves the player.
     void move(int row, int col);

};

bool yn(string input);

#include "player.hpp"
#include "status.hpp"

#endif


