/****************************************************************************
* File Name: Enemy.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Enemy class
* 		which is the base class for the Xenomorph class. The enemy
* 		class represents the enemies the player will encounter in 
* 		the game. It holds as data members a string nameE that holds
* 		the name of the enemy and a pointer to the room class 
* 		representing the curent location of the enemy. It holds
* 		as member functions move() (to move the enemy to a different
* 		room), setLocation() (to set the initial location of the 
* 		enemy), and getLocation() (to return the enemy current 
* 		location).
*************************************************************************/

#include "Enemy.hpp"
#include <string>
#include <cstdlib>
#include <ctime>



//Function name: getNameE
//Parameters: none
//Return Value: string (representing enemy name)
//Description: return name of enemy
std::string Enemy::getNameE()
{
	//return nameE data member
	return nameE;
}



//Function name: setLocation()
//Parameters: Room& (room to set enemy location to)
//Return Value: none
//Description: Sets enemy location pointer to passed room address
void Enemy::setLocation(Room &current)
{
	//set location pointer to passed room address
	location = &current;
}



//Function name: move()
//Parameters: none
//Return Value: none
//Description: Moves enemy randomly through door1, door2, door3, or door4
void Enemy::move()
{
	//generate random number to choose which room to move to
	int next = (rand() % 4 +1);

	//if random number ==1, move through door 1
	if (next == 1)
	{
		setLocation(*(location->getDoor1()));
	}

	//if random number ==2, move through door 2
	else if (next ==2)
	{
		setLocation(*(location->getDoor2()));

	}

	//if random number ==3, move through door 3
	else if (next == 3)
	{
		setLocation(*(location->getDoor3()));

	}

	//if random number ==4, move through door 4
	else if (next ==4)
	{
		setLocation(*(location->getDoor4()));
	}
}



//Function name: getLocation()
//Parameters: none
//Return Value: Room* (pointer to currnet enemy room location)
//Description: Returns a pointer to the current room location of the enemy
Room* Enemy::getLocation()
{
	//return pointer to current room location
	return location;
}
