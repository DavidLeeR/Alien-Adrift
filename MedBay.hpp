/****************************************************************************
* File Name: MedBay.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the MedBay class,
* 		which is derived from the Room class. The MedBay class
* 		represents a medical bay of a space ship, in which the player
* 		can heal themselves as well as make a medkit to go.
* 		It holds only Room data members (nameR for the name of the room,
* 		and door1 - door4 to repesent connections to other rooms).
* 		The MedBay class function special2() overrides the room
* 		pure virtual function to dynamically allocate and return
* 		a Medkit item. The MedBay Class also has a member function
* 		named heal, which is used to heal the player.  
*************************************************************************/



#ifndef MEDBAY_HPP
#define MEDBAY_HPP

#include "Room.hpp"
#include "Daniels.hpp"
#include "Medkit.hpp"


class MedBay: public Room
{
	public:
		MedBay();
		void showDescR();
		int heal(Daniels &danR);
		Medkit* special2();
		int special1();
		
		
};

#endif
		
