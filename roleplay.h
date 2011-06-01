/*	Filename: roleplay.h
 *	Devs: Micah Butler (princessjinifer)
 *	Created: 5/10/2010
 *	A text based roleplaying game that I wrote on a boring car trip home from Grandma's house ^_^
 *	v.0 (first build)
*/

//#ifndef ROLEPLAY_H
#define ROLEPLAY_H

#include <cstdlib> // included for the 'system("clear")'

using namespace std; // people say not to add this one, I don't want to type std:: in front of all my things, too much coding :D

extern string character_name; // at the beginning when they choose their character name, and used later on probably for saved games.*/
extern string are_you_sure;
extern string what_to_do; // when the user is asked what they want to do, this is used for their input.
extern int area_number; // this tells the plan_of_action which area you are in
extern int gold_amount; // for handling how much gold the player has :)

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
void talk_to_repair_man_1 (); // talking to the repair man in the first hotel
void ring_the_bell_1 (); // the assistance bell in the first hotel
//void available_actions (); // I am not sure if I will use this one or not, probably not.
