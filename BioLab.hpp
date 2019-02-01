/****************************************************************************
* File Name: BioLab.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the BioLab class,
* 		which is derived from the Room class. The BioLab class
* 		represents a biology laboratory room in which the player
* 		can make a concoction to avoid the enemy for some turns.
* 		It holds only Room data members (nameR for the name of the room,
* 		and door1 - door4 to repesent connections to other rooms).
* 		The BioLab class function special2() overrides the room
* 		pure virtual function to dynamically allocate and return
* 		a xenDet item (xenomorph deterrant). 
*************************************************************************/


#ifndef BIOLAB_HPP
#define BIOLAB_HPP

#include "Room.hpp"
#include "XenDet.hpp"
#include "Item.hpp"



class BioLab: public Room
{
	private:
	public:
		BioLab();
		void showDescR();
		XenDet* special2();

		//this function not used (ran out of time
		//to implement)
		int special1();	
		
};

#endif
		
