/****************************************************************************
 * File Name: XendDet.cpp
 * Author: David Ramirez
 * Date: 6/13/17
 * Description: This is the function implentation file for the 
 * 		XenDet (xenomorph deterrant) class. This class represents a 
 * 		XenDet item that the player can use for defense. 
 * 		It contains all Item data members and member functions.
 * *************************************************************************/

#ifndef XENDET_HPP
#define XENDET_HPP


#include "Item.hpp"

class XenDet:public Item
{
	public:
		XenDet();
		void showDescI();
};

#endif
