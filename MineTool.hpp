/****************************************************************************
 * File Name: MineTool.hpp
 * Author: David Ramirez
 * Date: 6/13/17
 * Description: This is the header file for the 
 * 		MineTool (mining tool) class. This class represents a 
 * 		mining tool item that the player can use for defense. 
 * 		It contains all Item data members and member functions.
 * *************************************************************************/

#ifndef MINETOOL_HPP
#define MINETOOL_HPP


#include "Item.hpp"

class MineTool:public Item
{
	public:
		MineTool();
		void showDescI();
};

#endif
