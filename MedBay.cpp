/****************************************************************************
* File Name: MedBay.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the MedBay class,
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



#include <iostream>
#include "MedBay.hpp"
#include "Daniels.hpp"



//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets the nameR data member to the name of the room and sets
//		each door1- door4 pointer data member to null
MedBay::MedBay()
{
	//set data member nameR to name of this room
	nameR = "Medical Bay";

	//set each door (pointer to room) to null
	door1 = NULL;
	door2 = NULL;
	door3 = NULL;
	door4 = NULL;

}



//Function name: showDescR()
//Parameters: none
//Return Value: none
//Description: Displays the description of this room
void MedBay::showDescR()
{
	//output room description
	std::cout << std::endl;
	std::cout << "It looks like the xenomorph was in here, it's a mess.";
	std::cout << std::endl;
	std::cout << "The cabinet doors are shatterred and meds are everywhere.";
	std::cout << std::endl;
	std::cout << "Daniels should be able to patch herself up here, as well as make a kit to go.";
	std::cout << std::endl;
	std::cout << "That first aid class in the academy had to count for something.";
	std::cout << std::endl;

}



//Function name: heal()
//Parameters: Daniels& (Daniels class object passed by reference)
//Return Value: int (representing whether or not to take a turn)
//Description: Heals player for max of 4 hp. Displays message if 
//		player health already at max.
int MedBay::heal(Daniels &danR)
{
	//if daniels has 10 or more health
	if (danR.getHealth() >= 10)
	{
		//output already at full health statement
		std::cout << std::endl;
		std::cout <<"Daniels is already at full health" << std::endl;

		//wait for user to hit enter
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
		
		//return -1 so that turn is not taken
		return -1;
	}

	//else, if daniels health is below 10
	else
	{
		//calculate how much health is missing
		int diff = (10 - (danR.getHealth()));
		
		//cannot heal for more than 4 hp each time, so
		//if health missing is more than 4, heal for 4
		if (diff > 4)
		{
			diff = 4;
		}
		
		//heal for amount of hp missing (max 4)
		danR.modHealth(diff);
	
		//output healed message
		std::cout << std::endl;
		std::cout << "Daniels regained " << diff << " HP" << std::endl;

		//wait for user to hit enter
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
		
		//return 0 so that a turn is taken
		return 0;
	}
}




//Function name: special2()
//Parameters: none
//Return Value: Medkit*
//Description: Dynamically allocates new Medkit item and returns pointer to 
//		item.
Medkit* MedBay::special2()
{
	//dynamically allocate and return a new Medkit
	Medkit* kit = new Medkit();
	return kit;
}



//Function name: special1()
//Parameters: none
//Return Value: none
//Description: Does nothing (needed for pure virtual function in abstract class)
int MedBay::special1()
{
	return 0;
}
