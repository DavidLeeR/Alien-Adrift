/****************************************************************************
* File Name: LoadBay.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the LoadBay class,
* 		which is derived from the Room class. The LoadBay class
* 		represents a loading bay of a space ship, in which the player
* 		can scavenge parts to assemble a mining tool for defense.
* 		It holds only Room data members (nameR for the name of the room,
* 		and door1 - door4 to repesent connections to other rooms).
* 		The LoadBay class function special2() overrides the room
* 		pure virtual function to dynamically allocate and return
* 		a MineTool item (mining tool). 
*************************************************************************/



#ifndef LOADBAY_HPP
#define LOADBAY_HPP

#include "Room.hpp"
#include "MineTool.hpp"



class LoadBay: public Room
{
	public:
		LoadBay();
		void showDescR();
		MineTool* special2();

		//this function not used (ran out
		//of time to implement)
		int special1();
		
		
};

#endif
		
