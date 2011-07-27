/*	Filename: shops.cpp
 *	Devs: Micah Butler (princessjinifer)
 *	Created: 5/10/2010
 *	A text based roleplaying game that I began writing on a boring car trip home from Grandma's house ^_^
 *	v.0 (first build)
*/

#include <iostream>
#include "roleplay.h"

int hotel_number;
int finished1;
int talked_to_him;

void hotel_help ();
void finished_1 ();

void the_hotel ()
{
	if (visited_the_help == 1)
	{
		visited_the_help=0;
		goto been_to_the_help;
	}
	if (finished1 == 1)
	{
		goto what_to_do_2;
	}
	cout << "As you go into the hotel, you don't see anybody around\n";
	cout << "except for the repair man in the corner doing his job.\n";
	cout << "There is a bell on the counter with a sign:\n";
	cout << "'Ring the bell for assistance'\n\n";
	hotel_number=0;
	hotel_number++;
	what_to_do_2:
	cout << "What would you like to do? \n";
	cout << "talk to repair man\n";
	cout << "ring the bell\n";
	cout << "leave the hotel\n";
	been_to_the_help:
	cout << ": ";
	getline (cin, what_to_do);
	if (what_to_do == "talk to repair man")
	{
		talk_to_repair_man_1 ();
	}
	if (what_to_do == "ring the bell")
	{
		ring_the_bell_1 ();
	}
	if (what_to_do == "leave the hotel")
	{
		leave_the_building ();
	}
	else
	{
		cout << "please enter one of these commands or type 'help'\n";
		goto what_to_do_2;
	}
}

void talk_to_repair_man_1 ()
{
	system("clear");
	cout << "He looks up at you, his face is really dirty, and he \n";
	cout << "doens't seem happy. He says \"What do you want\" in a \n";
	cout << "deep scratchy voice\n\n";
	what_to_do_2:
	the_conversation:
	cout << "I was just wondering where everybody is (command: wondering)\n";
	cout << "who are you? \n";
	cout << "where am i at?\n";
	cout << "that is all for now\n";
	cout << ": ";
	getline (cin, what_to_do);
	if (what_to_do == "wondering")
	{
		goto wondering_1;
	}
	if (what_to_do == "who are you?")
	{
		goto who_are_you_rm_1;
	}
	if (what_to_do == "where am i at?")
	{
		goto where_am_i_at_1;
	}
	if (what_to_do == "that is all for now")
	{
		talked_to_him=1;
		finished_1 ();
	}
	if (what_to_do == "help")
	{
		hotel_number=101;
		system("clear");
		hotel_help ();
	}
	else
	{
		cout << "I don't recognize that, use 'help' for a list of commands\n";
		goto what_to_do_2;
	}
	wondering_1:
	cout << "\n\nThey are gone, the only 2 people here are me and the owner, \n";
	cout << "ring the bell if you want to talk to the owner\n\n";
	goto the_conversation;
	who_are_you_rm_1:
	cout << "\n\nI am the repair man, now go away and leave me alone\n\n";
	goto the_conversation;
	where_am_i_at_1:
	cout << "\n\nThe Brunswick Hotel\n\n";
	goto the_conversation;
}

void ring_the_bell_1 ()
{
	if (visited_the_help == 1)
	{
		visited_the_help=0;
		goto been_to_the_help;
	}
	cout << "It makes a high pitched 'ding'\n";
	cout << "you hear some noise in the back of the hotel, behind the desk\n";
	cout << "and a man comes out wearing a nametag the reads \'Jimmie\' he says\n";
	cout << "\"Hello there, do you need something?\"\n\n";
	what_to_do_2:
	cout << "who are you?\n";
	cout << "what is this?\n";
	cout << "where am i supposed to go? (command: where to go)\n";
	cout << "no, I will just be going (command: i will just go)\n";
	been_to_the_help:
	cout << ": ";
	getline (cin, what_to_do);
	if (what_to_do == "who are you?")
	{
		goto who_are_you_1;
	}
	if (what_to_do == "what is this?")
	{
		goto what_is_this_1;
	}
	if (what_to_do == "where to go")
	{
		goto where_to_go_1;
	}
	if (what_to_do == "i will just go")
	{
		talked_to_him=2;
		finished_1 ();
	}
	if (what_to_do == "help")
	{
		hotel_number=102;
		hotel_help ();
	}
	else
	{
		cout << "I do not recognize that, please use 'help'\n";
		goto what_to_do_2;
	}
	who_are_you_1:
	cout << "\n\nI am the owner of the hotel, my name is Jimmie\n\n";
	goto what_to_do_2;
	what_is_this_1:
	cout << "\n\nThis is the main hotel in Brunswick, I haven't had a customer \n";
	cout << "in nearly 7 years, so me and my maintenance guy have been the only ones\n\n";
	goto what_to_do_2;
	where_to_go_1:
	cout << "\n\nThere are lots of cities around here, the one you will probably want to \n";
	cout << "go to first is Sharighm, it is the biggest city closest to this one, only 13 \n";
	cout << "miles away, you cannot go anywhere without a map though, and you can get one \n";
	cout << "if you complete a quest for me.\n\n";
	goto what_to_do_2;
}

void finished_1 ()
{
	if (talked_to_him == 1)
	{
		goto done_with_rm;
	}
	else
	{
		cout << "\n\nYou came from an unknown place, sorry";
		the_hotel ();
	}
	done_with_rm:
	cout << "\n\nYou leave the dude alone to his duties, and decide to go\n";
	cout << "back to the center of the lobby, the only other things there\n";
	cout << "are the door, the desk and the bell, plus the dusty elevators\n";
	cout << "which have \'out of order\' signs on them \n\n";
	finished1=1;
	the_hotel ();
}

void hotel_help ()
{
	visited_the_help=0;
	visited_the_help++;
	if (hotel_number == 1)
	{
		goto hotelOne;
	}
	if (hotel_number == 101)
	{
		goto hotelOneRepairMan;
	}
	if (hotel_number == 102)
	{
		goto hotelOneOwner;
	}
	else
	{
		cout << "hotel non-exsistent\n";
		the_hotel ();
	}
	hotelOne:
	cout << "Available commands:\n";
	cout << "talk to repair man\n";
	cout << "ring the bell\n";
	cout << "leave the hotel\n\n";
	the_hotel ();
	hotelOneRepairMan:
	cout << "Available commands:\n";
	cout << "wondering\n";
	cout << "who are you? \n";
	cout << "where am i at?\n";
	cout << "that is all for now\n\n";
	talk_to_repair_man_1 ();
	hotelOneOwner:
	cout << "Available commands:\n";
	cout << "who are you?\n";
	cout << "what is this?\n";
	cout << "where to go\n";
	cout << "i will just go\n\n";
	ring_the_bell_1 ();
}
