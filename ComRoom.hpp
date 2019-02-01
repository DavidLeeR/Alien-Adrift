/****************************************************************************
* File Name: ComRoom.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the ComRoom class,
* 		which represents a communications room in a space ship. 
* 		It holds Room data members (nameR for the name of the room,
* 		and door1-door4 to represent connections to other rooms).
* 		In addition, it holds data members that keep track of 
* 		events accessed by the player in this room. The member
* 		functions are used to facilitate the accessing of 
* 		special events in the game (in this room) by the player.
*************************************************************************/

#ifndef COMROOM_HPP
#define COMROOM_HPP

#include "Room.hpp"
#include "Item.hpp"



class ComRoom: public Room
{
	private:
		int compAccess;
		int speaker;
		int code;
		int noTurn;
	public:
		ComRoom();
		void showDescR();
		int coord(int,int);
		int special1(); 
		int getNoTurn();
		int getSpeaker();
		Item* special2();
		
};

#endif
		
