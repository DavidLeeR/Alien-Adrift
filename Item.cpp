/****************************************************************************
* File Name: Item.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Item class,
* 		which is the base class for the MineTool, Medkit, and
* 		XenDet classes. This class represents an item meant to 
* 		help the player survive the game. For data members, the 
* 		string nameI holds the name of the item. For member function,
* 		the Item class holds getNameI() to return the name of the
* 		item and showDescI() to show the description of the item.
*************************************************************************/

#include "Item.hpp"


//Function name: getNameI
//Parameters: none
//Return Value: string (representing item name)
//Description: return name of item
std::string Item::getNameI()
{
	//return nameI data member (string)
	return nameI;
}
