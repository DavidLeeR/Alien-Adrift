/****************************************************************************
* File Name: ComRoom.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation for the ComRoom class,
* 		which represents a communications room in a space ship. 
* 		It holds Room data members (nameR for the name of the room,
* 		and door1-door4 to represent connections to other rooms).
* 		In addition, it holds data members that keep track of 
* 		events accessed by the player in this room. The member
* 		functions are used to facilitate the accessing of 
* 		special events in the game (in this room) by the player.
*************************************************************************/

#include <iostream>
#include "ComRoom.hpp"



//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets the nameR data member to the name of the room and sets
//		each door1- door4 pointer data member to null. Also sets
//		each variable that keeps track of room events to 0.
ComRoom::ComRoom()
{
	//set name of room
	nameR = "Communications Room";

	//set variables that keep track of actions in room to 0
	compAccess =0;
	code = 0;
	speaker = 0;
	noTurn = 0;

	//set all doors to null
	door1 = NULL;
	door2 = NULL;
	door3 = NULL;
	door4 = NULL;

}



//Function name: showDescR()
//Parameters: none
//Return Value: none
//Description: Displays the description of this room
void ComRoom::showDescR()
{
	//display description of room
	std::cout << std::endl;
	std::cout << "The Communications Room still look operational.";
	std::cout << std::endl;
	std::cout << "The indicator by the comm speaker is flashing, showing";
	std::cout << std::endl;
	std::cout << "that HQ is attempting to get in contact with the Covenant.";
	std::cout << std::endl;
	std::cout << "Daniels notices that a nearby computer terminal is logged";
	std::cout << std::endl;
	std::cout << "in with the top level credentials, it may yield valuable information.";
	std::cout << std::endl;
}



//Function name: coord()
//Parameters: code (int representing the code the player needs to enter),
//		turns (int representing number of turns left till rescue)
//Return Value: int (representing whether or not to take a turn)
//Description: Allows the user to enter a specific code to activate
//		the turn countdown until the game is won. Returns 0 if
//		a turn is to be taken, -1 if not. If the player has already
//		entered the code, this function displays the number of turns
//		until rescue arrives.
int ComRoom::coord(int code, int turns)
{
	//if this is the first time displaying this and if the coordinate
	//code has not been accessed by the play yet
	if ((speaker == 0)&&(code < 100))
	{	

		//output prompt to get coordinate code
		std::cout << std::endl;
		std::cout << "Daniels accesses the communications intercom...";
		std::cout  << std::endl << std::endl;
		std::cout << "Speaker: \"Officer Daniels, we have a rescue ship ready";
		std::cout << std::endl;
		std::cout << "to be deplyed to your location, but HQ needs your current";
		std::cout << std::endl;
		std::cout << "navigational coordinate code in order to do so.\"";
		std::cout << std::endl;
	
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	
		//set variable that keeps track of # of displays of this message = 1
		speaker = 1;
	
		return 0;
	}

	//if this is the second time accessing this option or coord code has 
	//been accessed and this is not the third time accessing this option
	if (((speaker == 1) || (code > 100)) && (speaker !=2))
	{
		int userCode;

		//display prompt to enter coord code
		std::cout << std::endl;
		std::cout << "Speaker: \"HQ needs those coordinates to get to you, Daniels...\"";
		std::cout << std::endl;
		std::cout << "Enter the coordinate code:";
		std::cin >> userCode;

		//if coord code matches generated coord code
		if (userCode == code)
		{
			//output prompt that rescue is coming
			std::cout << std::endl;
			std::cout << "Speaker: \"Those coordinates look good,";
			std::cout << "rescue is on the way...\"";
			std::cout << std::endl;
			std::cout << "Rescue will reach the covenant in " << turns << " turns...";
			std::cout << std::endl;
			//set variable that keeps track of displays of this
			//option to 2
			speaker = 2;

			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();

		
			return 1;
		}
	
		//if user does not enter right coord code
		if (userCode != code)
		{
			//output wrong code message
			std::cout << std::endl;
			std::cout << "Speaker: \"That code points straight to a"; 
			std::cout << " star, it can't be correct...";
			std::cout << std::endl;
			speaker = 1;
			noTurn = 0;
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();

			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();
		
			return 0;
		}
	}
	
	//if rescue has been sent for by user
	if (speaker == 2)
	{
		//display how long it will take rescue to arrive
		std::cout << std::endl;
		std::cout << "Rescue will arrive in " << turns << " turns";
		std::cout << std:: endl;

		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
		
		//set variable that Game checks to make sure not to 
		//take a turn
		noTurn = 1;
		return 1;
	}
}



//Function name: special1()
//Parameters: none
//Return Value: none
//Description: Displays a message stating that the player has found an
//		access code and sets the variable for this event. 
int ComRoom::special1()
{       
	//if this is the first time accessing this options
	if (compAccess == 0)
	{
		//output got access code message
		std::cout <<std::endl;
		std::cout << "Daniels accesses the computer terminal...";
		std::cout << std::endl << std::endl;
		std::cout << "The computer seems to be logged in with the ";
		std::cout << std::endl;
		std::cout << "the Commanders credentials. Daniels finds and ";
		std::cout << std::endl;
		std::cout << "memorizes the Commanders access code, it could ";
		std::cout << std::endl;
		std::cout << "be useful for the locks on the ship.";	
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
		//set variable that Game checks to make sure userr has 
		//access code to 1
		compAccess = 1;
		return 0;
	}
	
	//if this is the second time accessing this option
	else if (compAccess == 1)
	{
		//output no info message
		std::cout << std::endl;
		std::cout << "There is no new information on the screen...";
		std::cout << std::endl;

		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
		//make sure Game does not increase turn
		return -1;
	}
}



//Function name: getNoTurn()
//Parameters: none
//Return Value: int (representing whether a turn is to be taken or not)
//Description: Returns the data member that keeps track of whether a turn
//		is to be taken
int ComRoom::getNoTurn()
{
	//return variable that tells Game not to take a turn for option 1
	return noTurn;
}



//Function name: default contructor
//Parameters: none
//Return Value: int
//Description: Returns the variable that keeps track of how many times
//		player has accessed option 1
int ComRoom::getSpeaker()
{
	//return variable that tells Game how many times user has accessed
	//option 1
	return speaker;
}



//Function name: special2()
//Parameters: none
//Return Value: Item*
//Description: Does nothing (needed for pure virtual function in abstract class
//		Room)
Item* ComRoom::special2()
{
	Item* item;
	return item;
}
