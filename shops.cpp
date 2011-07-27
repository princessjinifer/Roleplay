/*	Filename: shops.cpp
 *	Devs: Micah Butler (princessjinifer)
 *	Created: 5/10/2010
 *	A text based roleplaying game that I began writing on a boring car trip home from Grandma's house ^_^
 *	v.0 (first build)
*/

#include <iostream>
#include "roleplay.h"

int shop_number;
string talking_to_phil;

void shop_help ();

void the_shop ()
{
	if (visited_the_help == 1)
	{
		visited_the_help=0;
		goto beentothehelp;
	}
	cout << "You see a cheerful man inside, he greets you warmly\n";
	cout << "\"Hello there, welcome to Sam's General Store.\n";
	cout << "My name is Phil, my dad is Sam just in case you were\n";
	cout << "wondering where the name Sam came from.\"\n\n";
	what_to_do_2:
	cout << "What would you like to do? \n";
	cout << "talk to phil\n";
	cout << "look in the shop\n";
	cout << "leave the shop\n";
	beentothehelp:
	cout << ": ";
	getline (cin, what_to_do);
	if (what_to_do == "talk to phil")
	{
		talk_to_phil ();
	}
	if (what_to_do == "look in the shop")
	{
		the_shop_part2 ();
	}
	if (what_to_do == "leave the shop")
	{
		leave_the_building ();
	}
	if (what_to_do == "help")
	{
		shop_number=1;
		system("clear");
		shop_help ();
	}
	else
	{
		cout << "I don't recognize that, please enter one of the commands above\n";
		goto what_to_do_2;
	}
	exit (0);
}

void talk_to_phil ()
{
	if (visited_the_help == 1)
	{
		goto beentothehelp;
	}
	system("clear");
	the_conversation:
	cout << "What would you like to say? \n\n";
	cout << "where am i at?\n";
	cout << "where is your father?\n";
	cout << "where is everybody else at?\n";
	cout << "tell me about yourself\n";
	cout << "that is all for now\n";
	beentothehelp:
	cout << ": ";
	getline (cin, talking_to_phil);
	if (talking_to_phil == "where am i at?")
	{
		goto where_am_i_at;
	}
	if (talking_to_phil == "where is your father?")
	{
		goto where_is_your_father;
	}
	if (talking_to_phil == "where is everybody else at?")
	{
		goto where_is_everybody_else;
	}
	if (talking_to_phil == "tell me about yourself")
	{
		goto tell_me_about_yourself;
	}
	if (talking_to_phil == "that is all for now")
	{
		the_shop_2 ();
	}
	if (talking_to_phil == "help")
	{
		shop_number=101;
		system("clear");
		shop_help ();
	}
	else
	{
		cout << "that isn't one of the commands\n\n";
		goto the_conversation;
	}
	
	where_am_i_at:
	cout << "\n\nYou are in Brunswick, the forgotten town, we call it the forgotten town because\n";
	cout << "nobody comes here anymore, there are alot more bigger, and better towns, so they\n";
	cout << "always go to those instead of here.\n\n";
	goto the_conversation;
	
	where_is_your_father:
	cout << "\n\nHe left for The War 13 years ago, I was only 5 then, don't remember much about \n";
	cout << "him, I have not heard from him since.\n\n";
	goto the_conversation;
	
	where_is_everybody_else:
	cout << "\n\nFighting in The War, in dungeons, other bigger cities, or dead, once someone \n";
	cout << "leaves your eyesight, you never know if you will see them again. The mail system \n";
	cout << "is down so there is no communication between anybody long distance wise, if you \n";
	cout << "know where someone is, you could send your own messenger with a message for them,\n";
	cout << "that doesn't guarantee that you will ever see or hear from the messenger again.\n\n";
	goto the_conversation;
	
	tell_me_about_yourself:
	cout << "\n\nMy name is Philip, but everyone calls me Phil, I own this shop along with my\n";
	cout << "uncle who is asleep in the back right now, I am 18 years old, and have lived\n";
	cout << "here since I was 10, my uncle and I moved here after The War started taking\n";
	cout << "over our old village we found this one not too long after, and have lived here\n";
	cout << "ever since.\n\n";
	goto the_conversation;
}

void the_shop_part2 ()
{
	string shopping_actions;
	the_shop_2_retry:
	cout << "Here is where you get to shop: \n";
	cout << "You have " << gold_amount << " gold.\n\n";
	cout << "What do you want to do:\n";
	cout << "buy\n";
	cout << "sell\n";
	cout << "check prices\n";
	cout << ": ";
	getline(cin, shopping_actions);
	if (shopping_actions == "buy")
	{
		cout << "What would you like to buy? ";
		exit (0);
	}
	if (shopping_actions == "sell")
	{
		cout << "What would you like to sell? ";
		exit (0);
	}
	if (shopping_actions == "check prices")
	{
		cout << "What item in your inventory would you like to check the value on? ";
		exit (0);
	}
	else
	{
		cout << "That is not a command that I recognize, please use one from the list above\n\n";
		goto the_shop_2_retry;
	}
}

void the_shop_2 ()
{
	the_shop_2_retry:
	cout << "You return to Phil in the middle of the shop.\n\n";
	cout << "What do you want to do? \n";
	cout << "talk to phil\n";
	cout << "look in the shop\n";
	cout << "leave the shop\n";
	cout << ": ";
	getline (cin, what_to_do);
	if (what_to_do == "talk to phil")
	{
		talk_to_phil ();
	}
	if (what_to_do == "look in the shop")
	{
		the_shop_part2 ();
	}
	if (what_to_do == "leave the shop")
	{
		leave_the_building ();
	}
	else
	{
		cout << "I don't recognize that, please use one of the commands shown\n";
		goto the_shop_2_retry;
	}
}

void shop_help ()
{
	visited_the_help=0;
	visited_the_help++;
	if (shop_number == 1)
	{
		goto shopOne;
	}
	if (shop_number == 101)
	{
		goto shopOneOwner;
	}
	else
	{
		cout << "shop non-exsistent\n";
	}
	shopOne:
	cout << "Available commands:\n";
	cout << "talk to phil\n";
	cout << "look in the shop\n";
	cout << "leave the shop\n";
	the_shop ();
	shopOneOwner:
	cout << "Available commands:\n";
	cout << "where am i at?\n";
	cout << "where is your father?\n";
	cout << "where is everybody else at?\n";
	cout << "tell me about yourself\n";
	cout << "that is all for now\n";
	talk_to_phil ();
	}
