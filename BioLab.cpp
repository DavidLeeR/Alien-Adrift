/****************************************************************************
* File Name: BioLab.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the BioLab class,
* 		which is derived from the Room class. The BioLab class
* 		represents a biology laboratory room in which the player
* 		can make a concoction to avoid the enemy for some turns.
* 		It holds only Room data members (nameR for the name of the room,
* 		and door1 - door4 to repesent connections to other rooms).
* 		The BioLab class function special2() overrides the room
* 		pure virtual function to dynamically allocate and return
* 		a xenDet item (xenomorph deterrant). 
*************************************************************************/

#include <iostream>
#include "BioLab.hpp"
#include "Room.hpp"



//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets the nameR data member to the name of the room and sets
//		each door1- door4 pointer data member to null
BioLab::BioLab()
{
	//set name of bio lab
	nameR = "Biology Laboratory";
	
	//set all doors to NULL
	door1 = NULL;
	door2 = NULL;
	door3 = NULL;
	door4 = NULL;
}



//Function name: showDesc()
//Parameters: none
//Return Value: none
//Description: Displays the description of the room
void BioLab::showDescR()
{
	//output description of room
	std::cout << std::endl;
	std::cout << "The lab looks in good condition. All the glass vials";
	std::cout << std::endl;
	std::cout << "and beakers shine like new. Daniels notices a container";
	std::cout << std::endl;
	std::cout << "of liquid labeled \"deterrant\" in immaculate handwriting.";
	std::cout << std::endl;
	std::cout << "This must be David's creation. The liquid must not work";
	std::cout << std::endl;
	std::cout << "permanently, else he would still have control of the ship.";
	std::cout << std::endl;

}



//Function name: special2()
//Parameters: none
//Return Value: XenDet* (pointer to xenomorph deterrant item)
//Description: Dynamically allocates new xenomorph deterrant item and 
//		returns pointer to item.
XenDet* BioLab::special2()
{
	//create new xenomorph deterrant
	XenDet* det = new XenDet();
	//return new xenomorph deterrant
	return det;
}



//Function name: special1()
//Parameters: none
//Return Value: int 
//Description: Does nothing (needed for making pure virtual function
//		in abstract class)
int BioLab::special1()
{
	return 0;
}
		
