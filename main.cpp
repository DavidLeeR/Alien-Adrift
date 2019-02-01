/****************************************************************************
* File Name: main.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the main() 
* 		function. This function declares a Game class object
* 		and calls Game class member functions to facilitate the
* 		playing of the game. 
*************************************************************************/

#include <cstdlib>
#include <ctime>
#include "Game.hpp"



int main()	
{
	unsigned seed = time(0);
	srand(seed);	
	Game game1;
	game1.preface();
	game1.play();

	
	return 0;
}
