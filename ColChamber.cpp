/****************************************************************************
* File Name: ColChamber.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the ColChamber
* 		(Colony Chamber) class, which represents a large room
* 		of people sleeping in stasis pods. It holds only Room
* 		class data members (nameR for the name of the room, and
* 		door1- door4 to represent connections to other room). The
* 		ColChamber class member function special1() and unlock2()
* 		are used to access unlocking a special event (waking
* 		Tennessee up). The talk() member function displays dialogue
* 		from Tenessee after he is unlocked. 
*************************************************************************/

#include <iostream>
#include "ColChamber.hpp"


//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets the nameR data member to the name of the room and sets
//		each door1- door4 pointer data member to null
ColChamber::ColChamber()
{
	nameR = "Colony Chamber";
	descChange = 0;

	door1 = NULL;
	door2 = NULL;
	door3 = NULL;
	door4 = NULL;

}



//Function name: showDesc()
//Parameters: none
//Return Value: none
//Description: Displays the description of this room
void ColChamber::showDescR()
{
	//display this description if Tennessee has not been unlocked yet
	if (descChange == 0)
	{
		std::cout << std::endl;
		std::cout << "The Colony Chamber, home to 2,000 souls in stasis.";
		std::cout << std::endl;
		std::cout << "It is a vast room, with  stasis pods strung up";
		std::cout << std::endl;
		std::cout << "on the walls as far as the eye can see. Daniels notices";
		std::cout << std::endl;
		std::cout << "her pilot, Tennessee, in one of the pods. He is still asleep.";
		std::cout << std::endl;
	}
	
	//display this description if Tennessee has been unlocked
	if (descChange == 1)
	{
		std::cout << std::endl;
		std::cout << "The Colony Chamber, home to 2,000 souls in stasis.";
		std::cout << std::endl;
		std::cout << "It is a vast room, with many stasis pods strung up";
		std::cout << std::endl;
		std::cout << "on the walls as far as the eye can see. Daniels notices";
		std::cout << std::endl;
		std::cout << "Tennessee doing his best to stay hidden while making the";
		std::cout << std::endl;
		std::cout << "medkits."; 
		std::cout << std::endl;
	}
		
}



//Function name: special1()
//Parameters: none
//Return Value: int (0 to tell the Game class to take a turn)
//Description: Displays a message stating that the player needs a code
//		to unlock this Tennnessee's pod (called when player does
//		not have code)
int ColChamber::special1()
{
	//display this when player tries to unlock pod without access key
	std::cout << std::endl;
	std::cout << "The stasis pod requires an access code to unlock...";
	std::cout << std::endl;
	
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	
	//return 0 so a turn is taken
	return 0;
}



//Function name: unlock2()
//Parameters: none
//Return Value: none
//Description: Displays a messge stating that Tennessee's pod has been opened
//		and sets the variable that keeps track of this event (called
//		when player has code)
void ColChamber::unlock2()
{
	//display this if player tires to open pod and has access key
	std::cout << std::endl;
	std::cout << "The stasis pod requires an access code to unlock...";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Daniels enters the access code she memorized, the pod";
	std::cout << std::endl << "opens and Tennessee wakes up...";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Tennessee: *groans* \"I always hate the long sleep.";
	std::cout << " Are we at Origae-6 already?\"";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Daniels explains the situation and Tennessee offers";
	std::cout << std::endl;
	std::cout << "to help by providing Medkits he can make at the";
	std::cout << std::endl;
	std::cout << "first aid pod. A Medkit will be delivered to Daniels";
	std::cout << std::endl;
	std::cout << "every 4th turn via the ship's built in delivery terminals...";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	std::cout << std::endl;

	// make variable that keeps track of if Tennessee has been unlocked = 1
	descChange = 1;
}



//Function name: talk()
//Parameters: none
//Return Value: none
//Description: Randomly displays 1 of 4 dialogues from Tennessee
void ColChamber::talk()
{
	//generate random number to choose dialogue
	int which = (rand()% 4 + 1);

	//outputs dialogue based on random number generated
	if (which ==1)
	{
		std::cout << std::endl;
		std::cout << "Tennessee: \"I'm a little busy right now...\"";
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	}

	if (which ==2)
	{
		std::cout << std::endl;
		std::cout << "Tennessee: \"How are those Medkits working?\"";
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	}

	if (which ==3)
	{
		std::cout << std::endl;
		std::cout << "Tennessee: \"Keep low and slow...\"";
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	}

	if (which ==4)
	{
		std::cout << std::endl;
		std::cout << "Tennessee: \"What else could go wrong...\"";
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();
	}
}



//Function name: special2()
//Parameters: none
//Return Value: Item* 
//Description: Does nothing (needed for making pure virtual function
//		in abstract class)
Item* ColChamber::special2()
{
	Item* item;
	return item;
}
