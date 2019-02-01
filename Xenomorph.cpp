/****************************************************************************
* File Name: Xenomorph.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Xenomorph
* 		class, derived from the Enemy base class. This class
* 		represents a hostile alien (xenomorph) that moves around
* 		the ship, attacking the player. It has all data members 
* 		and member functions of the Enemy class. In addition, 
* 		it has a default constructor and an attack() function
* 		to simulate damage dealt to the player. 
*************************************************************************/

#include "Xenomorph.hpp"



//Function name: default constructor
//Parameters: none
//Return Value: none
//Description: sets nameE string data member to reflect enemy name and sets
//		enemy location to NULL
Xenomorph::Xenomorph()
{
	//set nameE data member to name of this enemy
	nameE = "Xenomorph";
	
	//set location to null
	location = NULL;
	
}



//Function name: attack()
//Parameters: none
//Return Value: int (amount of damage dealt)
//Description: This function generates a random number between 5 and 2 to
//		represent damage done. It then returns this number.
int Xenomorph::attack()
{
	//generate random number between 2 and 5 to simulate damage
	//when xenomorph attacks
	int atk = rand() % 4 + 2;
	
	//return generated number
	return atk;
}
