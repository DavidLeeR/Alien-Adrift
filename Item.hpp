/****************************************************************************
* File Name: Item.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Item class,
* 		which is the base class for the MineTool, Medkit, and
* 		XenDet classes. This class represents an item meant to 
* 		help the player survive the game. For data members, the 
* 		string nameI holds the name of the item. For member function,
* 		the Item class holds getNameI() to return the name of the
* 		item and showDescI() to show the description of the item.
*************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP



#include <string>

class Item
{
	protected:
		std::string nameI;
		
	public:
		virtual std::string getNameI();
		virtual void showDescI()=0;
};

#endif
