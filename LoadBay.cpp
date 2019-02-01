/****************************************************************************
* File Name: LoadBay.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the LoadBay class,
* 		which is derived from the Room class. The LoadBay class
* 		represents a loading bay of a space ship, in which the player
* 		can scavenge parts to assemble a mining tool for defense.
* 		It holds only Room data members (nameR for the name of the room,
* 		and door1 - door4 to repesent connections to other rooms).
* 		The LoadBay class function special2() overrides the room
* 		pure virtual function to dynamically allocate and return
* 		a MineTool item (mining tool). 
*************************************************************************/

#include <iostream>
#include "LoadBay.hpp"



//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets the nameR data member to the name of the room and sets
//		each door1- door4 pointer data member to null
LoadBay::LoadBay()
{
	//set nameR data member to name of room
	nameR = "Loading Bay";

	//set all doors (pointers to room) to null
	door1 = NULL;
	door2 = NULL;
	door3 = NULL;
	door4 = NULL;

}




//Function name: showDescR()
//Parameters: none
//Return Value: none
//Description: Displays description of room
void LoadBay::showDescR()
{
	//output description of room
	std::cout << std::endl;
	std::cout << "It looks like a warzone in here. This must be where the";
	std::cout << std::endl;
	std::cout << "xenomorph dispatched David. Through the disarray, some";
	std::cout << std::endl;
	std::cout << "parts that could assemble a mining tool can be seen.";
	std::cout << std::endl;
	std::cout << "Daniels doesn't have much experience using a mining tool,";
	std::cout << std::endl;
	std::cout << "but it should provide some defense.";
	std::cout << std::endl;

}



//Function name: special2()
//Parameters: none
//Return Value: MineTool* (pointer to mining tool item)
//Description: Dynamiclly allocates new mining tool item and returns pointer
//		to item.
MineTool* LoadBay::special2()
{
	//dynamically allocate and return new mining tool
	MineTool* mineT = new MineTool();
	return mineT;
}




//Function name: special1()
//Parameters: none
//Return Value: int
//Description: Does nothing (needed for pure virtual function in abstract class)
int LoadBay::special1()
{
	return 0;
}
