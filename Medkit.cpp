/****************************************************************************
* File Name: Medkit.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Medkit
* 		class, which is derived from the Item class.
* 		This class represents a medkit that the player can use
* 		to caryy in inventory and heal themselves.  This class
* 		holds Item data members and member function. In addition,
* 		this class has a default constructor.
*************************************************************************/

#include <iostream>
#include <string>
#include "Medkit.hpp"



//Function name: default constructor
//Parameters: none
//Return Value: none
//Description: set nameI variable to refect the name of the item
Medkit::Medkit()
{
	//set nameI data member to name of this item
	nameI = "Medkit";
}



//Function name: showDescI
//Parameters: none
//Return Value: none
//Description: not implemented due to time constraints
void Medkit::showDescI()
{
}
