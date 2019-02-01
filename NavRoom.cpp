/****************************************************************************
* File Name: NavRoom.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the NavRoom
* 		class, which represents the navigation room in a space ship.
* 		It holds Room data members (nameR for the name of the room,
* 		and door1- door4 to represent connections to other rooms).
* 		It overrides the Room special1() function to control the access
* 		of an in game event. In addition, the NavRoom class holds
* 		the member function window() that displays a graphic
* 		of the outside of the ship.  
*************************************************************************/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "NavRoom.hpp"



//Function name: default contructor
//Parameters: none
//Return Value: none
//Description: Sets the nameR data member to the name of the room and sets
//		each door1- door4 pointer data member to null. Also sets
//		each variable that keeps track of room events to 0.
NavRoom::NavRoom()
{
	//set nameR data member to name of this room
	nameR = "Navigation Room";

	//set all doors (pointers to room) to null
	door1 = NULL;
	door2 = NULL;
	door3 = NULL;
	door4 = NULL;

	//set variable that keeps track of if the user has accessed
	//the coordinates (random generated number) yet to 0
	coordGot = 0;

}



//Function name: showDescR()
//Parameters: none
//Return Value: none
//Description: Displays the description of the room
void NavRoom::showDescR()
{
	//output description of room
	std::cout << std::endl;
	std::cout << "There are emergency alerts and lights going off like mad.";
	std::cout << std::endl;
	std::cout << "Daniels has no idea what to do to stop them, she has never";
	std::cout << std::endl;
	std::cout << "piloted a ship, besides it looks like the engines are down.";
	std::cout << std::endl;
	std::cout << "There is a computer terminal that looks like it is still";
	std::cout << std::endl;
	std::cout << "operating normally, maybe its worth a look...";
	std::cout << std::endl;

}



//Function name: special1()
//Parameters: none
//Return Value: int (returns the code the player must remember)
//Description: Allows the player to access the navigational terminal
//		option of the navigation room. A code is outputted and
//		saved that represents the players navigational 
//		coordinates they must relay to HQ for rescue. The code
//		is randomly generated.
int NavRoom::special1()
{
	//if the player has not accessed the coordinates yet 
	if( coordGot == 0)
	{
		//generate large random number as "navigational coordinates"
		int coordCode = (rand()% 999999 + 100000);

		//output getting coordinates message
		std::cout << std::endl;
		std::cout << "Daniels accesses the navigation terminal...";
		std::cout << std::endl;
		std::cout << "The screen shows the coordinate code:";
		std::cout << std::endl;
		std::cout << coordCode;

		//wait for user to hit enter
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();

		//increment variable to show that player has accessed the 
		//coordinate code
		coordGot = 1;

		//return 1 to indicate amount of player completion for navroom
		//menus
		return coordCode;
	}

	//if player has already accessed the coordinate code
	if (coordGot == 1)
	{
		//show player there is nothing here
		std::cout << std::endl;
		std::cout << "There is no new information here...";
		std::cout << std::endl;

		//wait for user to hit enter
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();

		//return -1 so that turn is not taken
		return -1;
	}
}



//Function name: special2()
//Parameters: none
//Return Value: none
//Description: Does nothing (needed for pure virtual function in abstract class)
Item* NavRoom::special2()
{
	Item* item;
	return item;
}



//Function name: window()
//Parameters: none
//Return Value: none
//Description: Displays a graphic that shows the outside of the ship
void NavRoom::window(int turnL)
{
	//if there are more than 14 turns left, show default image
	if (turnL > 14)
	{
		std::cout <<"___________________________________________________________________";
		std::cout << std::endl;
		std::cout <<"|           *                               *                      |";
		std::cout << std::endl;
		std::cout <<"|         *                                                 *      |";
		std::cout << std::endl;
		std::cout <<"|          \\           *                *                          |";
		std::cout << std::endl;
		std::cout <<"|           \\                                       *              |";
		std::cout << std::endl;
		std::cout <<"|                                       *                          |";
		std::cout << std::endl;
		std::cout <<"|         *                                          /             |";
		std::cout << std::endl;
		std::cout <<"|                                                   /              |";
		std::cout << std::endl;
		std::cout <<"|                                                  *               |";
		std::cout << std::endl;
		std::cout <<"|      *                                                           |";
		std::cout << std::endl;
		std::cout <<"|                 *                                         *      |";
		std::cout << std::endl;
		std::cout <<"|                 *                         *                      |";
		std::cout << std::endl;
		std::cout <<"|                             *              *                     |";
		std::cout << std::endl;
		std::cout <<"|*                                                                 |";
		std::cout << std::endl;
		std::cout <<"|                    *                                             |";
		std::cout << std::endl;
		std::cout <<"|__________________________________________________________________|";
		std::cout << std::endl;
	}

	//if there are less that 10 turns left, show image 2 (rescue ship getting closer)
	else if (turnL > 10)
	{	std::cout <<"___________________________________________________________________";
		std::cout << std::endl;
		std::cout <<"|            *                                *                    |";
		std::cout << std::endl;
		std::cout <<"|         *                                                 *      |";
		std::cout << std::endl;
		std::cout <<"|                      *                *                          |";
		std::cout << std::endl;
		std::cout <<"|                                                   *              |";
		std::cout << std::endl;
		std::cout <<"|                                       *                          |";
		std::cout << std::endl;
		std::cout <<"|         *                                                        |";
		std::cout << std::endl;
		std::cout <<"|                              .                                   |";
		std::cout << std::endl;
		std::cout <<"|      *                                           *               |";
		std::cout << std::endl;
		std::cout <<"|                                                                  |";
		std::cout << std::endl;
		std::cout <<"|                 *                                         *      |";
		std::cout << std::endl;
		std::cout <<"|                 *                         *                      |";
		std::cout << std::endl;
		std::cout <<"|                             *              *                     |";
		std::cout << std::endl;
		std::cout <<"|*                                                                 |";
		std::cout << std::endl;
		std::cout <<"|                    *                                             |";
		std::cout << std::endl;
		std::cout <<"|__________________________________________________________________|";
		std::cout << std::endl;

	}

	//if there are less than 7 turns left, show image 3 (rescue ship closer)
	else if (turnL > 7)
	{	std::cout <<"___________________________________________________________________";
		std::cout << std::endl;
		std::cout <<"|               *                                  *               |";
		std::cout << std::endl;
		std::cout <<"|         *                                                 *      |";
		std::cout << std::endl;
		std::cout <<"|                      *                *                          |";
		std::cout << std::endl;
		std::cout <<"|                           __________              *              |";
		std::cout << std::endl;
		std::cout <<"|                         /|          |\\  *                        |";
		std::cout << std::endl;
		std::cout <<"|         *              [  {  |  |  }  ]                          |";
		std::cout << std::endl;	
		std::cout <<"|                         \\___________/  \\                         |";
		std::cout << std::endl;
		std::cout <<"|     *                     \\         \\  \\         *               |";
		std::cout << std::endl;
		std::cout <<"|                            \\_________\\/                          |";
		std::cout << std::endl;
		std::cout <<"|                 *                                         *      |";
		std::cout << std::endl;
		std::cout <<"|                 *                         *                      |";
		std::cout << std::endl;
		std::cout <<"|                             *              *                     |";
		std::cout << std::endl;
		std::cout <<"|*                                                                 |";
		std::cout << std::endl;
		std::cout <<"|                    *                                             |";
		std::cout << std::endl;
		std::cout <<"|__________________________________________________________________|";
		std::cout << std::endl;

	}
	
	//if there are less than 4 turns left, show image 4 (rescue ship closest)
	else if (turnL >= 4)
	{
		std::cout <<"___________________________________________________________________";
		std::cout << std::endl;
		std::cout <<"|    \\                    |             |             |            |";
		std::cout << std::endl;
		std::cout <<"|     \\                   |             |             |            |";
		std::cout << std::endl;
		std::cout <<"|      \\                  |             |             |            |";
		std::cout << std::endl;
		std::cout <<"|       \\                 |             |             |            |";
		std::cout << std::endl;
		std::cout <<"|        \\                                                         |";
		std::cout << std::endl;
		std::cout <<"|         \\                                                        |";
		std::cout << std::endl;
		std::cout <<"|     *    \\_______________________________________________________|";
		std::cout << std::endl;
		std::cout <<"|                        \\                                         |";
		std::cout << std::endl;
		std::cout <<"|                         \\                                        |";
		std::cout << std::endl;
		std::cout <<"|                 *        \\                                       |";
		std::cout << std::endl;
		std::cout <<"|                 *         \\                                      |";
		std::cout << std::endl;
		std::cout <<"|                            \\                                     |";
		std::cout << std::endl;
		std::cout <<"|*                            \\                                    |";
		std::cout << std::endl;
		std::cout <<"|                    *         \\                                   |";
		std::cout << std::endl;
		std::cout <<"|__________________________________________________________________|";
		std::cout << std::endl;

	}
}
