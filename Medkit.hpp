/****************************************************************************
* File Name: Medkit.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Medkit
* 		class, which is derived from the Item class.
* 		This class represents a medkit that the player can use
* 		to caryy in inventory and heal themselves.  This class
* 		holds Item data members and member function. In addition,
* 		this class has a default constructor.
*************************************************************************/



#ifndef MEDKIT_HPP
#define MEDKIT_HPP


#include "Item.hpp"

class Medkit:public Item
{
	public:
		Medkit();
		void showDescI();
};

#endif
