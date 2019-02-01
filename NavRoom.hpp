/****************************************************************************
* File Name: NavRoom.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the NavRoom
* 		class, which represents the navigation room in a space ship.
* 		It holds Room data members (nameR for the name of the room,
* 		and door1- door4 to represent connections to other rooms).
* 		It overrides the Room special1() function to control the access
* 		of an in game event. In addition, the NavRoom class holds
* 		the member function window() that displays a graphic
* 		of the outside of the ship.  
*************************************************************************/



#ifndef NAVROOM_HPP
#define NAVROOM_HPP

#include "Room.hpp"
#include "Item.hpp"



class NavRoom: public Room
{
	private:
		int coordGot;
	public:
		NavRoom();
		void showDescR();
		Item* special2();
		int special1();
		void window (int);
		
};

#endif
		
