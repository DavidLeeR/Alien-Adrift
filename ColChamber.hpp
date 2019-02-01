/****************************************************************************
* File Name: ColChamber.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the ColChamber
* 		(Colony Chamber) class, which represents a large room
* 		of people sleeping in stasis pods. It holds only Room
* 		class data members (nameR for the name of the room, and
* 		door1- door4 to represent connections to other room). The
* 		ColChamber class member function special1() and unlock2()
* 		are used to access unlocking a special event (waking
* 		Tennessee up). The talk() member function displays dialogue
* 		from Tenessee after he is unlocked. 
*************************************************************************/



#ifndef COLCHAMBER_HPP
#define COLCHAMBER_HPP

#include "Room.hpp"
#include "Item.hpp"



class ColChamber: public Room
{
	private:
		int descChange;
	public:
		ColChamber();
		void showDescR();
		Item* special2();
		int special1();
		void unlock2();
		void talk();
		
};

#endif
		
