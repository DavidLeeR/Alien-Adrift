/****************************************************************************
* File Name: Room.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Room class,
* 		which is the base class for the 6 specific derived room
* 		classes. As data members, it holds the string nameR (holds
* 		the name of the specific room) and 4 pointers to the Room 
* 		class that represent 4 connections to other rooms. As
* 		member functions, it holds functions to set each room 
* 		pointer (door1 - door4) and to return a pointer to each
* 		room. It also has a member function to return the nameR
* 		string data member. 
*************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP


#include <string>
#include "Item.hpp"
#include "Medkit.hpp"
#include "MineTool.hpp"
#include "XenDet.hpp"


class Room
{
	protected:
		std::string nameR;
		Room* door1;
		Room* door2;
		Room* door3;
		Room* door4;
	public:
		virtual void setDoor1(Room &room1);
		virtual void setDoor2(Room &room2);
		virtual void setDoor3(Room &room3);
		virtual void setDoor4(Room &room4);
		virtual Room* getDoor1();
		virtual Room* getDoor2();
		virtual Room* getDoor3();
		virtual Room* getDoor4();
		virtual std::string getDoor1Name();
		virtual std::string getDoor2Name();
		virtual std::string getDoor3Name();
		virtual std::string getDoor4Name();
		virtual std::string getNameR();
		virtual void showDescR() = 0;	
		virtual int special1() = 0;
		virtual Item* special2() =0;
};

		
#endif


