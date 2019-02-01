/****************************************************************************
* File Name: Room.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Room class,
* 		which is the base class for the 6 specific derived room
* 		classes. As data members, it holds the string nameR (holds
* 		the name of the specific room) and 4 pointers to the Room 
* 		class that represent 4 connections to other rooms. As
* 		member functions, it holds functions to set each room 
* 		pointer (door1 - door4) and to return a pointer to each
* 		room. It also has a member function to return the nameR
* 		string data member. 
*************************************************************************/

#include "Room.hpp"
#include <string>



//Function name: setDoor1()
//Parameters: none
//Return Value: none
//Description: Sets the door1 pointer to point towards the room passed
//		by reference in the parameter
void Room::setDoor1(Room &room1)
{
	//set door1 to point to address of parameter room
	door1 = &room1;
}




//Function name: setDoor2()
//Parameters: none
//Return Value: none
//Description: Sets the door2 pointer to point towards the room passed
//		by reference in the parameter
void Room::setDoor2(Room &room2)
{
	//set door2 to point to address of parameter room
	door2 = &room2;
}




//Function name: setDoor3()
//Parameters: none
//Return Value: none
//Description: Sets the door3 pointer to point towards the room passed
//		by reference in the parameter
void Room::setDoor3(Room &room3)
{
	//set door3 to point to address of parameter room
	door3 = &room3;
}




//Function name: setDoor4()
//Parameters: none
//Return Value: none
//Description: Sets the door4 pointer to point towards the room passed
//		by reference in the parameter
void Room::setDoor4(Room &room4)
{
	//set door4 to point to address of parameter room
	door4 = &room4;
}



//Function name: getDoor1()
//Parameters: none
//Return Value: Room* (pointer to room behind door 1)
//Description: returns a pointer held by the door1 data member
Room* Room::getDoor1()
{
	//return pointer to room behind door1
	return door1;
}



//Function name: getDoor2()
//Parameters: none
//Return Value: Room* (pointer to room behind door 2)
//Description: returns a pointer held by the door2 data member
Room* Room::getDoor2()
{
	//return pointer to room behind door2
	return door2;
}



//Function name: getDoor3()
//Parameters: none
//Return Value: Room* (pointer to room behind door 1)
//Description: returns a pointer held by the door3 data member
Room* Room::getDoor3()
{
	//return pointer to room behind door3
	return door3;
}



//Function name: getDoor4()
//Parameters: none
//Return Value: Room* (pointer to room behind door 4)
//Description: returns a pointer held by the door4 data member
Room* Room::getDoor4()
{
	//return pointer to room behind door4
	return door4;
}



//Function name: getDoor1Name()
//Parameters: none
//Return Value: string (name of room)
//Description: returns the name of the room pointed to by door1
std::string Room::getDoor1Name()
{
	//return name of room pointed to by door1
	return (*door1).getNameR();

}



//Function name: getDoor2Name()
//Parameters: none
//Return Value: string (mname of room)
//Description: returns the name of the room pointed to by door2
std::string Room::getDoor2Name()
{
	//return name of room pointed to by door2
	return (*door2).getNameR();
}



//Function name: getDoor3Name()
//Parameters: none
//Return Value: string (name of room)
//Description: returns the name of the room pointed to by door3
std::string Room::getDoor3Name()
{
	//return name of room pointed to by door3
	return (*door3).getNameR();
}



//Function name: getDoor4Name()
//Parameters: none
//Return Value: string (name of room)
//Description: returns the name of the room pointed to by door4
std::string Room::getDoor4Name()
{
	//return name of room pointed to by door4
	return (*door4).getNameR();
}



//Function name: getNameR()
//Parameters: none
//Return Value: string (name of room)
//Description: returns the name of the room
std::string Room::getNameR()
{
	//return data member nameR (string) 
	return nameR;
}

