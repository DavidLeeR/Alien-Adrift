
/****************************************************************************
* File Name: Daniels.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Daniels class,
* 		which represents the player in the game (character is named
* 		Daniels). For data members, this class holds members to 
* 		keep track of the player inventory, player movement, 
* 		player locations, and player health. For member functions,
* 		the Daniels class holds functions to facilitate the 
* 		use and addition of items to and from the inventory,
* 		modify and display player health, and move the player.
*************************************************************************/

#include <iostream>
#include "Item.hpp"
#include "Daniels.hpp"



//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets health to 10, location to null, movement tracker to 0 to
//		show no movement, and all inventory variables to 0 representing 
//		an empty inventory
Daniels::Daniels()
{
	health = 10;
	location = NULL;
	medCheck = 0;
	det = 0;	//keeps track of # of xeno deterrants in inventory
	mine = 0;	//keeps track of # of mining tools in inventory
	meds = 0;	//keeps track of # of medkits in inventory
	moveTrack =0;	//0 if player has not moved this turn, 1 if has moved
	
}



//Function name: modHealth()
//Parameters: int (representing how much to add to health)
//Return Value: none
//Description: Adds amount of health passed by parameter to payer health
void Daniels::modHealth(int inc)
{
	//add inc to health
	health += inc;
	
	//make sure health is never above 10
	if (health > 10)
	{
		//set variable that keeps track of if part of medkit was wasted
		//to 1
		health = 10;
		medCheck = 1;
		
	}
}



//Function name: addItem()
//Parameters: Item* (pointer to the item to be added to inventory)
//Return Value: none
//Description: Adds a pointer to an item to the inventory and displays
//		a message about which item was added
void Daniels::addItem(Item* newI)
{
	//add item pointer to inventory
	inventory.push_front(newI);

	//display message for item added
	std::cout << (*newI).getNameI() << " has been added to the inventory";
	std::cout << std::endl;

	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//if item pointer added points to xeno det
	if ((*newI).getNameI() == "Xenomorph Deterrant")
	{
		//increase variable that keeps track of xeno det #
		det += 1;
	}

	//if item pointer added points to mining tool
	if ((*newI).getNameI() == "Mining Tool")
	{
		//increase variable that keeps track of mining tool # 
		mine += 1;
	}
	
	//if item pointer added points to medkit
	if ((*newI).getNameI() == "Medkit")	
	{
		//increase variable that keeps track of medkit #
		meds += 1;
	}
}



//Function name: removeMine()
//Parameters: none
//Return Value: none
//Description: Removes pointer to a mining tool item from inventory (called
//		after mining tool has been used)
void Daniels::removeMine()
{
	int mineCheck = 0;
	//remove mining tool from inventory
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		//makes sure only 1 mining tool removed
		if (mineCheck == 0)
		{
			//step through inventory and check for mining tool
			if ((*iter)->getNameI() == "Mining Tool")
			{
				//delete mining tool
				delete (*iter);
				//decrement variable for mine tool counter
				mine -= 1;
				//make variable that makes sure only 1 mining
				//tool used =1
				mineCheck = 1;
				iter =inventory.erase(iter);	
			}
		}
	}
}



//Function name: showInvent()
//Parameters: none
//Return Value: none
//Description: Displays the current player inventory
void Daniels::showInvent()
{
	
	std::cout << std::endl;
	std::cout << "Inventory (max 5):";
	std::cout << std::endl;
	
	//if inventory is empty, display this
	if (inventory.size() == 0)
	{
		std::cout << "There are no items in the inventory";
		std::cout << std::endl;
	}

	//if inventory is not empty, display it
	else
	{
		std::cout << std::endl;

		//step through and display inventory
		for (iter = inventory.begin(); iter != inventory.end(); iter++)
		{
			std::cout << (*iter)->getNameI() << std::endl;
		
		}
	}
}



//Function name: setLocation()
//Parameters: Room& (address of room to set player location to)
//Return Value: none
//Description: Sets player location to room passed by reference parameter
void Daniels::setLocation(Room &current)
{
	//set current location of player
	location = &current;
}



//Function name: getHealth()
//Parameters: none
//Return Value: int (representing player health)
//Description: returns the curren player health
int Daniels::getHealth()
{
	//return health of player
	return health;
}



//Function name: damage()
//Parameters: int (representing amount of damage done to player)
//Return Value: none
//Description: Decreases player health by amount passed in parameter
void Daniels::damage(int dmg)
{
	//take damage dealt by xenomorph
	health -= dmg;
}



//Function name: getLocationName()
//Parameters: none
//Return Value: string (location name)
//Description: Returns the name of the current location of the player
std::string Daniels::getLocationName()
{
	//return name of current location
	return ((*location).getNameR());
}



//Function name: getLocation()
//Parameters: none
//Return Value: Room* (pointer to room)
//Description: Returns a pointer to the room that is the players current 
//		location.
Room* Daniels::getLocation()
{
	//return pointer to current location
	return location;
}



//Function name: useMedkit()
//Parameters: none
//Return Value: int (representing whether the Game class should take a turn)
//Description: Uses a medkit from player inventory to heal player
int Daniels::useMedkit()
{
	//variable used to make sure only 1 medkit used
	int kitCheck = 0;
	//calculate how much health is missing
	int diff = (10 - health);

	//make sure 3 HP at most is healed per medkit
	if (diff > 3)
	{
		diff = 3;
	}

	//go through inventory
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		//make sure only 1 medkit is used
		if (kitCheck != 1)
		{
			//if medkit found
			if ((*iter)->getNameI() == "Medkit")
			{
				//make = 1 so no more medkits are deleted
				kitCheck = 1;
				//add 3 to player health 
				modHealth(3);
		
				//if some of medkit has been wasted
				if (medCheck == 1)
				{
					//output medkit wasted message
					std::cout << std::endl;
					std::cout << "Part of a Medkit has been wasted...";
					std::cout << std::endl;
					medCheck = 0;
				}
	
				//delete medkit
				delete (*iter);
				//decrement med #
				meds -= 1;
				iter =inventory.erase(iter);	
			}
		}
	}
	
	//if no medkits were found in inventory					
	if (kitCheck == 0)
	{
		//display no medkits message
		std::cout << std::endl;
		std::cout << "There are no Medkits in the inventory" <<std::endl;
	
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	
		//return -1 so turn number not incremented
		return -1;
	}
	
	//if medkit was found in inventory
	else 
	{
		//display how much HP regained
		std::cout << "Daniels regained " << diff << " HP" << std::endl;
		
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	
		//return 0 so turn number incremented
		return 0;
	}
}



//Function name: useXenDet()
//Parameters: none
//Return Value: int (representing of the Game class should take a turn)
//Description: Uses a xenomorph deterrant from the player inventory to 
//		protect the pllayer from the xenomorph for 2 turns
int Daniels::useXenDet()
{
	//keeps track of xen det used so only 1 used
	int xenCheck = 0;

	//step through inventory
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
		//if xen det has not been found and used yet
		if (xenCheck != 1)
		{
			//if item name is xen det
			if ((*iter)->getNameI() == "Xenomorph Deterrant")
			{
				//make variable that makes sure only 1 xen det 
				//used = 1
				xenCheck = 1;
				//delete xen det
				delete (*iter);
				//decrease xen det #
				det -= 1;
				iter =inventory.erase(iter);	
			}
		}
	}
	//if no xen det found in inventory					
	if (xenCheck == 0)
	{
		//output no xen det message
		std::cout << std::endl;
		std::cout << "There are no Xenomorph Deterrants in the inventory" <<std::endl;
	
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();

		//return -1 so turn not taken
		return -1;
	}
	
	//if xen det found and used
	else 
	{
		//output used xen det message
		std::cout << std::endl;
		std::cout << "Daniels used the Xenomorph Deterrant..." << std::endl;
		std::cout << "She is safe from attacks for 2 turns...";
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();	

		//return 0 so turn taken
		return 0;
	}
}



//Function name: getDet()
//Parameters: none
//Return Value: int (representing number of xendet in inventory)
//Description: Returns the number of xenomorph deterrants in the player 
//		inventory
int Daniels::getDet()
{
	//return # of xen dets in inventory
	return det;
}



//Function name: getMine()
//Parameters: none
//Return Value: int (representing number of mining tools in inventory)
//Description: Returns the number of mining tools in the player 
//		inventory
int Daniels::getMine()
{
	//return # of mining tools in inventory
	return mine;
}



//Function name: getMeds()
//Parameters: none
//Return Value: int (representing number of medkits in inventory)
//Description: Returns the number of Medkits in the player 
//		inventory
int Daniels::getMeds()
{
	//return # of medkits in inventory
	return meds;
}



//Function name: move()
//Parameters: none
//Return Value: none
//Description: Moves player to room represented by door1 (only used when
//		player runs away after attack)

void Daniels::move()
{
		//move daniels to location behind door 1 of current location
		//(used when xenomorph encountered to simulate running away)
		setLocation(*(location->getDoor1()));
	
}



//Function name: getMoveTrack()
//Parameters: none
//Return Value: int (representing if the player has moved last turn)
//Description: Returns 1 if the player has moved last turn or 0 if
//		player has not moved last turn (in form of moveTrack
//		variable)
int Daniels::getMoveTrack()
{
	//return integer that keeps track of if player moved this turn
	return moveTrack;
}



//Function name: setMoveTrack()
//Parameters: int (1 for movement, 0 for no movement)
//Return Value: none
//Description: Allows the moveTrack variable to be set to reflect player 
//		movement 
void Daniels::setMoveTrack(int set)
{
	//set moveTrack data member to parameter
	moveTrack = set;
}



//Function name: removeAll()
//Parameters: none
//Return Value: none
//Description: Deletes all dynamically allocated items in inventory
void Daniels::removeAll()
{
	//remove mining tool from inventory
	for (iter = inventory.begin(); iter != inventory.end(); iter++)
	{
			//step through inventory and check for mining tool
		if (((*iter)->getNameI() == "Mining Tool") || ((*iter)->getNameI() == "Medkit") || ((*iter)->getNameI() == "Xenomorph Deterrant"))
		{
			//delete mining tool
			delete (*iter);				
			iter =inventory.erase(iter);	
		}
	}
}
