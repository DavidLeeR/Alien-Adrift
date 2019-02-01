/****************************************************************************
* File Name: Xenomorph.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Xenomorph
* 		class, derived from the Enemy base class. This class
* 		represents a hostile alien (xenomorph) that moves around
* 		the ship, attacking the player. It has all data members 
* 		and member functions of the Enemy class. In addition, 
* 		it has a default constructor and an attack() function
* 		to simulate damage dealt to the player. 
*************************************************************************/

#ifndef XENOMORPH_HPP
#define XENOMORPH_HPP


#include <string>
#include <cstdlib>
#include <ctime>
#include "Enemy.hpp"

class Xenomorph: public Enemy
{
	public:
		Xenomorph();
		int attack();
	
};

#endif
