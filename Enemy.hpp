/****************************************************************************
* File Name: Enemy.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Enemy class
* 		which is the base class for the Xenomorph class. The enemy
* 		class represents the enemies the player will encounter in 
* 		the game. It holds as data members a string nameE that holds
* 		the name of the enemy and a pointer to the room class 
* 		representing the curent location of the enemy. It holds
* 		as member functions move() (to move the enemy to a different
* 		room), setLocation() (to set the initial location of the 
* 		enemy), and getLocation() (to return the enemy current 
* 		location).
*************************************************************************/



#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <ctime>
#include <cstdlib>
#include "Room.hpp"
#include "BioLab.hpp"
#include "NavRoom.hpp"
#include "LoadBay.hpp"
#include "MedBay.hpp"
#include "ColChamber.hpp"
#include "ComRoom.hpp"


class Enemy
{
	protected:
		std::string nameE;
		Room* location;

	public:
		virtual std::string getNameE();
		virtual void setLocation (Room &current);
		virtual void move();
		virtual Room* getLocation();
};

#endif	
		
