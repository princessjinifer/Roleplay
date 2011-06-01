/*	Filename: roleplay.cpp
 *	Devs: Micah Butler (princessjinifer)
 *	Created: 5/10/2010
 *	A text based roleplaying game that I wrote on a boring car trip home from Grandma's house ^_^
 *	v.0 (first build)
*/

#include <iostream> // always included
#include <cstdlib> // included for the 'system("clear")'

using namespace std; // people say not to add this one, I don't want to type std:: in front of all my things, too much coding :D

string character_name; // at the beginning when they choose their character name, and used later on probably for saved games.*/
string what_to_do; // when the user is asked what they want to do, this is used for their input.
string are_you_sure;
int area_number; // this tells the plan_of_action which area you are in
int gold_amount = 0; // for handling how much gold the player has :)

void game_beginning (); // where the game actually begins
void game_beginning_part2 (); // after the 'plan_of_action' function
void plan_of_action (); // what is your plan of action?
void the_shop (); // After the user enters the shop, this is the function that takes effect
void the_hotel (); // This is the various hotels that the user can go to.
void the_fence (); // the electric fence when you first start off
void the_help (); // shows you the help, I will most likely take this one out
void wanting_to_quit (); // after the user types quit or exit it will take them here asking if they are sure.
void talk_to_phil (); // have a conversation with the first shop owner
void the_shop_part2 (); // where you buy/sell/check prices
void leave_the_building (); // after leaving any building
void the_shop_2 (); // after you talk to phil and use the shop
//void available_actions (); // I am not sure if I will use this one or not, probably not.

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
	if (what_to_do == "go to the shop")
	{
		system("clear");
		cout << "You make your way to the shop, and enter the door\n";
		the_shop ();
	}
	if (what_to_do == "go to the hotel")
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

void the_shop ()
{
	cout << "You see a cheerful man inside, he greets you warmly\n";
	cout << "\"Hello there, welcome to Sam's General Store.\n";
	cout << "My name is Phil, my dad is Sam just in case you were\n";
	cout << "wondering where the name Sam came from.\"\n\n";
	what_to_do_2:
	cout << "What would you like to do? \n";
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
		cout << "I don't recognize that, please enter one of the commands above\n";
		goto what_to_do_2;
	}
	exit (0);
}

void the_hotel ()
{
	cout << "As you go into the hotel, you don't see anybody around\n";
	cout << "except for the repair man in the corner doing his job.\n";
	cout << "There is a bell on the counter with a sign:\n";
	cout << "'Ring the bell for assistance'\n\n";
	exit (0);
}

void leave_the_building ()
{
	if (area_number == 1)
	{
		cout << "You step out of the building and see the same street you were on when you first awoke\n";
		plan_of_action ();
	}
}

void talk_to_phil ()
{
	system("clear");
	string talking_to_phil;
	the_conversation:
	cout << "What would you like to say? \n\n";
	cout << "where am i at?\n";
	cout << "where is your father?\n";
	cout << "where is everybody else at?\n";
	cout << "tell me about yourself\n";
	cout << "that is all for now\n";
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
	}
	areaOne:
	cout << "Available commands:\n";
	cout << "go to the shop\n";
	cout << "go to the hotel\n";
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
