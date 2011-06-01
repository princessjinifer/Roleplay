/*	Filename: roleplay.cpp
 *	Devs: Micah Butler (princessjinifer)
 *	Created: 5/10/2010
 *	A text based roleplaying game that I wrote on a boring car trip home from Grandma's house ^_^
 *	v.0 (first build)
*/
#define MAIN
#include <iostream> // always included
#include "roleplay.h"

string character_name; // at the beginning when they choose their character name, and used later on probably for saved games.*/
string are_you_sure;
string what_to_do; // when the user is asked what they want to do, this is used for their input.
int area_number; // this tells the plan_of_action which area you are in
int gold_amount = 0; // for handling how much gold the player has :)

int main () // introduction and name picking
{
/* Explains what it is, who made it, and what is going on */
	system("clear");
	cout << "Welcome to Roleplay, a simple text based roleplaying game written \n";
	cout << "by Princessjinifer\n\n";
	cout << "All you have to do is type in basic commands, they shouldn't be too hard, like \n";
	cout << "if you want to pickup a sword you would type 'pickup sword', so you shouldn't \n";
	cout << "be too confused on what to type. If you ever do need help, and it is saying \n";
	cout << "'unknown command', just type help, it will show you what all there is to type :)\n";
	cout << "I also forgot to mention that all commands are in lower case, just like they \n";
	cout << "are in the help :)\n\n";
	cout << "So, when you are ready to start, press ENTER";
	cin.get();
	system("clear");
/* here is where it actually starts, they choose their character here */
	cout << "Alright! Here is when it gets fun ^_^\n";
	cout << "What would you like to name your character? ";
	getline(cin, character_name);
	are_you_sure_retry:
	cout << character_name << "; are you sure? ";
	sure_number_2:
	getline(cin, are_you_sure);
	if (are_you_sure == "yes" || are_you_sure == "yep" || are_you_sure == "y" || are_you_sure == "yeah" || are_you_sure == "mhmm" || are_you_sure == "yup" || are_you_sure == "sure")
	{
		cout << "Schweet! I like " << character_name << "! :D\n";
		cout << "Press ENTER to start the game\n";
		cin.get();
		system("clear");
		game_beginning ();
	}
	if (are_you_sure == "no" || are_you_sure == "nope" || are_you_sure == "nah" || are_you_sure == "nome")
	{
		cout << "Okay, pick your new name: ";
		goto name_picking_2;
	}
	else
	{
		cout << "I don't recognize that, retry please\n";
		goto are_you_sure_retry;
	}

	name_picking_2:
	getline(cin, character_name);
	cout << "Now you are sure about this one? ";
	goto sure_number_2;

	return 0;
}

void game_beginning ()
{
	cout << "You find yourself in the middle of the streets, no body is around, and it is \n";
	cout << "silent. It is in the middle of the night, and there are a few places around. \n";
	cout << "There is a shop on the left, a hotel on the right and a sign quite aways ahead \n";
	cout << "of you, behind you, you find a fence, barbed wire, and electically charged.\n\n";
	area_number=0;
	area_number++;
	plan_of_action ();
}

void game_beginning_part2 ()
{
	getline(cin, what_to_do);
	if (what_to_do == "go in to shop")
	{
		system("clear");
		cout << "You make your way to the shop, and enter the door\n";
		the_shop ();
	}
	if (what_to_do == "go in to hotel")
	{
		system("clear");
		cout << "You see that the hotel is open, and decide to go check it out\n";
		the_hotel ();
	}
	if (what_to_do == "go to the fence")
	{
		system("clear");
		cout << "As you approach the fence, you can hear what sounds like electric buzzing\n";
		the_fence ();
	}
	if (what_to_do == "exit" || what_to_do == "quit")
	{
		wanting_to_quit ();
	}
	if (what_to_do == "help")
	{
		the_help ();
	}
	else
	{
		cout << "I don't recognize that, type something different\n";
		cout << "hint: type 'help' to see a list of commands.\n";
		plan_of_action ();
	}
}

void plan_of_action ()
{
	cout << "What do you want to do? ";
	if (area_number == 1)
	{
		game_beginning_part2();
	}
	else
	{
		cout << "area non exsistent";
		game_beginning ();
	}
}

void leave_the_building ()
{
	system("clear");
	if (area_number == 1)
	{
		cout << "\nYou step out of the building and see the same street you were on when you first awoke\n";
		plan_of_action ();
	}
}

void the_fence ()
{
	string restart_the_game;
	cout << "The closer you get the more nervous you get,\n";
	cout << "you reach out and touch it, feel a sharp pain in your hand then everything goes \n";
	cout << "black.\n\n";
	cout << "You have just died, do you want to restart? ";
	getline(cin, restart_the_game);
	if (restart_the_game == "yes")
	{
		system("clear");
		game_beginning ();
	}
	if (restart_the_game == "no")
	{
		system("clear");
		wanting_to_quit ();
	}
}

void the_help ()
{
	if (area_number == 1)
	{
		goto areaOne;
	}
	else
	{
		cout << "area non exsistent";
		game_beginning ();
	}
	areaOne:
	cout << "Available commands:\n";
	cout << "go in to shop\n";
	cout << "go in to hotel\n";
	cout << "go to the fence\n\n";
	plan_of_action ();	
}

void wanting_to_quit ()
{
	cout << "Are you sure you want to quit? ";
	getline(cin, are_you_sure);
	if (are_you_sure == "yes" || are_you_sure == "yep" || are_you_sure == "y" || are_you_sure == "yeah" || are_you_sure == "mhmm" || are_you_sure == "yup" || are_you_sure == "sure")
	{
		cout << "fun playing with you!\n";
		exit (0);
	}
	else
	{
		cout << "okay, that was just a mistake\n\n";
		plan_of_action ();
	}
}
