/****************************************************************************
* File Name: Game.cpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the function implementation file for the Game class,
* 		which instantiates and holds all other objects as data
* 		members. This class represents a game that the user plays.
* 		It also holds as data members integers that keep track of
* 		events that take place during the game. For member 
* 		function, it contains functions for the player to interact
* 		with the rooms, take turns, and be attacked by the enemy
* 		xenomorph.
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "menu.hpp"
#include "Game.hpp"
#include "Medkit.hpp"



//Function name: default constructor
//Parameters: none
//Return Value: none
//Description: sets all data members that track the status of the game
//		progression to their lowest value to begin the game
Game::Game()
{
	//set game to 18 turns once rescue called
	turnLimit = 18;
	//set turn counter to 1 for beginning of game
	turnNumber = 1;

	//set all game event counters to 0 for beginning of game
	lost = 0;
	code = 0;
	codeCheck = 0;
	contact = 0;
	gotAccess = 0;
	tenCheck =0;
	xenoDet = 0;
	activate = 0;
	quit = 0;
	madeXenDet = 0;
	madeMineTool =0;
	madeHeal =0;
	madeMedKit = 0;
	thirdSet = 0;
	oneMore = 0;

	//***These first 6 blocks set up the map***
	//set doorways for navigation room
	navR.setDoor1(loadR);
	navR.setDoor2(medR);
	navR.setDoor3(comR);
	navR.setDoor4(bioR);

	//set doorways for biology lab
	bioR.setDoor1(navR);
	bioR.setDoor2(loadR);
	bioR.setDoor3(comR);
	bioR.setDoor4(colR);

	//set doorways for loading bay
	loadR.setDoor1(navR);
	loadR.setDoor2(bioR);
	loadR.setDoor3(medR);
	loadR.setDoor4(colR);

	//set doorways for med bay
	medR.setDoor1(navR);
	medR.setDoor2(loadR);
	medR.setDoor3(colR);	
	medR.setDoor4(comR);

	//set doorways for communications room
	comR.setDoor1(navR);
	comR.setDoor2(bioR);
	comR.setDoor3(colR);
	comR.setDoor4(medR);

	//set doorways for colony chamber
	colR.setDoor1(medR);
	colR.setDoor2(comR);
	colR.setDoor3(bioR);
	colR.setDoor4(loadR);

	//set Daniels location to colony chamber
	danP.setLocation(colR);


	//set Xenomorph starting location to Loading Bay
	xenE.setLocation(loadR); 

	//set 2nd Xenomorph starting location to loading bay
	xenE2.setLocation(navR);
	
}



//Function name: preface()
//Parameters: none
//Return Value: none
//Description: displays the game preface
void Game::preface()
{
	//output title and created by statement
	space();
	std::cout << std::endl << std::endl;
	std::cout << "Alien: Adrift" << std::endl << std::endl;
	std::cout << "A fan fiction text based survival game based on the Alien franchise";
	std::cout << std::endl;
	std::cout << std::endl << "Game created by David Ramirez";
	std::cout << std::endl;
	std::cout << "This game is in no way affiliated with the Alien franchise";
	std::cout << std::endl << std::endl;
	std::cout << "(press Enter to navigate through text prompts)";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//output viewing experience prompt
	space();
	std::cout << "Make terminal fullscreen for best viewing experience";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//output note about the enemy
	space();
	std::cout << std::endl;
	std::cout << "It is worth noting that the xenomorph"; 
	std::cout << std::endl;
	std::cout << "moves independently of player objectives";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	
	//output premise of game and goal
	space();
	std::cout << std::endl;
	std::cout << "You (Daniels) are stranded on a star ship with a vicious alien";
	std::cout << std::endl;
	std::cout << "(xenomorph). You must communicate to HQ for rescue and survive";
	std::cout << std::endl;
	std::cout << "until the rescue ship arrives.";	
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	
	//output setting
	space();	
	std::cout << std::endl;
	std::cout << "Year: 2108 (4 years into stasis sleep)";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Location: Colony Ship Covenant";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
	std::cout << "After fleeing the xenomorph infested unknown planet,";
	std::cout << std::endl;
	std::cout << "Chief Terraform Officer Daniels and Pilot Tennessee";
	std::cout << std::endl;
	std::cout << "go into stasis sleep after realizing all too late that";
	std::cout << std::endl;
	std::cout << "the AI unit on board was not their's, but the sinister";
	std::cout << std::endl;
	std::cout << "AI, David, that was encountered on the unknown planet.";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//output backstory
	space();
	std::cout << std::endl;
	std::cout << "Officer Daniels is awoken from stasis sleep by the";
	std::cout << " ship.";
	std::cout << std::endl << std::endl;
	std::cout << "Speakers: \"Emergency, unknown life form detected on ";
	std::cout << "ship\"";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//output more backstory
	space();
	std::cout << "Something must have happened to David...";
	std::cout << std::endl;
	std::cout << "It appears he";
	std::cout << " is no longer in control of the ship.";
	std::cout << std::endl;
	std::cout << "One of his hatchling xenomorphs probably got a hold of him.";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//output first objective of game (also kept track of in HUD)
	space();
	std::cout << "Daniels knows that she must communicate to HQ in order to be rescued.";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();

	//output note about enemy
	space();
	std::cout << "Stay prepared, a xenomorph is lurking on the ship.";
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.clear();
}



//Function name: play()
//Parameters: none
//Return Value: none
//Description: facilitates the turns of the game and determines if the 
//		player has won or lost. The turn() function is used by this
//		function
void Game::play()
{
	//seed random number generator
	unsigned seed = time(0);
	srand(seed);	

	//while the player still must survive more turns to win 
	while (turnLimit > 0)
	{
		//if player has Tennessee unclocked, give 
		//player medkit every 4th turn
		if (turnNumber % 4 == 0)
		{
			//if tennessee unlocked and player 
			//has room in inventory
			if ((tenCheck ==1) && ((danP.getDet() + danP.getMine() + danP.getMeds()) < 5))
			{
				//dynamically allocate new medkit 
				//and place in player inventory
				danP.addItem(new Medkit);
			}
		}

		//if player has not used a xenomorph deterrant 
		//(or it has worn off) make chance for
		//xenomorph to attack daniels each turn
		if (xenoDet == 0)
		{	
		
		//if either of the 3 xenomorphs (third xenomorph 
		//unlocks when final 'survive' portion of game activated)
		//current location is the same as daniels and daniels has
		//moved last turn, initiate this attack sequence
		if (((xenE.getLocation() == danP.getLocation()) && (danP.getMoveTrack() == 1)) || ((xenE2.getLocation() == danP.getLocation()) && (danP.getMoveTrack() == 1))||((xenE3.getLocation() == danP.getLocation()) && (danP.getMoveTrack() == 1)))

		{
			//output enemy attaking prompt
			space();
			std::cout << std::endl;
			std::cout << "Daniels notices something in the corner";
			std::cout << " of the room...";
			std::cout << std::endl;

			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();

			std::cout << "HHHHIIIIISSSSSSS";
			std::cout << std::endl;
			std::cout << "The xenomorph slashes and claws...";
			std::cout << std::endl;

			//if daniels has no mining tools in 
			//inventory, take damage
			if (danP.getMine() == 0)
			{
				//get damage from xenomorph class
				int dam1 = xenE.attack();
				//move damage to player class (daniels)
				danP.damage(dam1);
			
				//output message describing amount of
				//hp damaged for
				std::cout << "Daniels has been hurt for " << dam1;
				std::cout << " HP, she runs away as fast as she can...";
				std::cout << std::endl;
			
				//wait for user to hit enter
				std::cin.clear();
				std::cin.ignore();
				std::cin.clear();
	
				//move player (running away)
				danP.move();
					
				//set variable that checks if player has 
				//moved in the last turn
				danP.setMoveTrack(1);
			}

			//if daniels has at least 1 mining tool in the inventory,
			//fight off xenomorph and dont take damage
			if (danP.getMine() >0)
			{
				//output fight off enemy message
				std::cout << "Daniels uses a mining tool to fight off the xenomorph...";
				std::cout << std::endl;
				std::cin.clear();
				std::cin.ignore();
				std::cin.clear();


				std::cout << "Temporarily...";
				std::cout << std::endl;
			
				//wait for user to hit enter
				std::cin.clear();
				std::cin.ignore();
				std::cin.clear();
			
				//remove mining tool from inventory after using
				danP.removeMine();

			}
		}

		//if either of the 3 xenomorphs (third xenomorph 
		//unlocks when final 'survive' portion of game activated)
		//current location is the same as daniels and daniels has
		//not moved last turn, initiate this attack sequence
		if (((xenE.getLocation() == danP.getLocation()) && (danP.getMoveTrack() == 0)) || ((xenE2.getLocation() == danP.getLocation()) && (danP.getMoveTrack() == 0))||((xenE3.getLocation() == danP.getLocation()) && (danP.getMoveTrack() == 0)))

		{
			//output enemy interaction prompt
			space();
			std::cout << std::endl;
			std::cout << "Daniels hears something enter the room...";
			std::cout << std::endl;

			//wait for user to hit enter
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();

			//get user input as to whether they would
			//like to hide or not (no chance to use
			//mining tool if you hide)
			int hideCheck = menuHide();

			//if player decides to stay in the open
			if (hideCheck == 2)
			{
				//display enemy attack prompt
				std::cout << "HHHHIIIIISSSSSSS";
				std::cout << std::endl;
				std::cout << "The xenomorph slashes and claws...";
				std::cout << std::endl;
				
				//if player has no mining tools in 
				//the inventory, take damage
				if (danP.getMine() == 0)
				{
					//get damage amount from enemy class
					int dam2 = xenE.attack();
	
					//move amount of damage to player class
					danP.damage(dam2);
			
					//output message describing damage done to player
					std::cout << "Daniels has been hurt for " << dam2;
					std::cout << " HP, she runs away as fast as she can...";
					std::cout << std::endl;
			
					//wait for user to hit enter
					std::cin.clear();
					std::cin.ignore();
					std::cin.clear();
						
					//move player (simulate running away)
					danP.move();
		
					//set variable that keeps track of if player
					//has moved last turn
					danP.setMoveTrack(1);
				}

				//if player has at least one mining tool in
				//inventory, use it as defense
				if (danP.getMine() >0)
				{
					//output use of mining tool message
					std::cout << "Daniels uses a mining tool to fight off the xenomorph...";
					std::cout << std::endl;
			
					//wait for user to hit enter
					std::cin.clear();
					std::cin.ignore();
					std::cin.clear();


					std::cout << "Temporarily...";
					std::cout << std::endl;
		
					//wait for user to hit enter
					std::cin.clear();
					std::cin.ignore();
					std::cin.clear();

					//remove mining tool after use
					danP.removeMine();
				}
			}
		
			//if player decides to hide
			else if (hideCheck == 1)
			{
				//generate random number from 1 to 100
				int hideChance = (rand()% 100 +1);

				//if generated number if above 60, enemy
				//does not notice player and no damage 
				//is done
				if (hideChance > 60)
				{
					//output hide success message
					std::cout << std::endl;
					std::cout << "Whatever it was, it went ";
					std::cout << "away...";
					std::cout << std::endl;

					//wait for user to hit enter
					std::cin.clear();
					std::cin.ignore();
					std::cin.clear();

					//set variable that checks if player has 
					//moved last turn to 0
					danP.setMoveTrack(0);
				}
				
				//else, if generated number is equal to 
				//or below 60, take damage
				else 
				{
					//output hide fail message
					std::cout << std::endl;
					std::cout << "The xenomorph sees Daniels...";
					std::cout << std::endl;

					//wait for user to hit enter
					std::cin.clear();
					std::cin.ignore();
					std::cin.clear();
	
					//output enemy attack prompt
					std::cout << "HHHHIIIIISSSSSSS";
					std::cout << std::endl;
					std::cout << "The xenomorph slashes and claws...";
					std::cout << std::endl;
			
					//get damage amount from enemy class
					int dam3 = xenE.attack();

					//move damage amount to player class
					danP.damage(dam3);
			
					//output damage description
					std::cout << "Daniels has been hurt for " << dam3;
					std::cout << " HP, she runs away as fast as she can...";
					std::cout << std::endl;
		
					//wait for user to hit enter
					std::cin.clear();
					std::cin.ignore();
					std::cin.clear();

					//move player (simulate running away
					danP.move();

					//set variable that tracks if player has moved
					//last turn
					danP.setMoveTrack(1);
				}
			}		
		}
		}
		
		//if player has health left
		if (danP.getHealth() >0)
		{
			//show turn number title
			space();
			std::cout << "** Turn " << turnNumber << " **";
			std::cout << std::endl;

			//wait for user to hit enter
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();
		}

		//if player has user xenodet and it is still
		//in effect
		if (xenoDet > 0)
		{
			//reduce amount of turns it takes effect for
			//by 1
			xenoDet --;
		}
		
		//provides functionality for losing the game
		//if player health below 1
		if (danP.getHealth() < 1)
		{
			//output losing message
			space();
			std::cout << std::endl;
			std::cout << "Daniels has succummed to her";
			std::cout << " injuries..." << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
			std::cout << std::endl;
			
			//set variable to 0 to end game
			turnLimit = 0;
	
			//set variable that keeps track of
			//if player has lost the game
			lost = 1;
		}
	
		//if player has not completed the first objective and it is turn
		//25, player loses the game
		if ((turnNumber >= 25) && (codeCheck == 0) && (contact ==0))
		{
			//output losing message
			space();
			std::cout << std::endl;
			std::cout << "You took too long to complete the first objective.";
			std::cout << std::endl;
			std::cout << "Daniels died of sheer boredom." << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
			std::cout << std::endl;

			//set variable to 0 to end game
			turnLimit = 0;
		
			//set variable that keeps track of
			//if player lost the game to 1
			lost = 1;
		}

		//if player has not yet lost the game
		if (lost == 0)
		{	
			//take a turn
			turn();

			//increment turn number
			turnNumber ++;

			//if player has made xenodet in recent
			//turn, dec amount of turns to make another
			if (madeXenDet >0)
			{
				madeXenDet --;
			}
			
			//if player has made mining tool in recent
			//turn, dec amount of turns to make another	
			if (madeMineTool > 0)
			{
				madeMineTool --;
			}

			//if player has healed daniels in recent
			//turn, dec amount of turns to make another
			if (madeHeal > 0)
			{
				madeHeal --;
			}

			//if player has completed last objective, 
			//countdown turn limit till winning game (starts at 18)
			if (activate == 1)
			{
				turnLimit --;
			}
	
	        	//xenomorph 1 moves every turn
			xenE.move();

			//2nd xenomorph moves after 2nd turn
			if (turnNumber % 2 == 0)
			{
				xenE2.move();
			}

			//xenomorph 3 enters the game a few turns after
			//the last objective is reached
			if (turnLimit < 16)
			{
				//if xenomorph 3 hasnt entered game yet, enter game
				if (thirdSet ==0)
				{
					xenE3.setLocation(medR);

					//increment variable that keeps track 
					//of if 3rd xenomorph is in game
					thirdSet =1;
				}
				
				//if 3rd xenomorph is in game already, move
				//him every turn
				else
				{
					xenE3.move();
				}
			}

			//if the 3rd xenomorph was just brought into the game,
			//display a comment warning player
			if ((thirdSet == 1) && (oneMore == 0) && (quit ==0))
			{
				//set variable that keeps track of if
				//this message has been displayed
				oneMore = 1;
				space();
				std::cout << "Speakers: \"Emergency, two unknown lifeforms detected ";
				std::cout << "on ship\"";
				std::cout << std::endl;

				//wait for user to hit enter
				std::cin.clear();
				std::cin.ignore();
				std::cin.clear();
	
				space();
				std::cout << "One more?" << std::endl;
				std::cout << "Daniels is going to be especially careful...";
				std::cout << std::endl;
		
				//wait for user to hit enter
				std::cin.clear();
				std::cin.ignore();
				std::cin.clear();
			}
		}	
	}

	//if the turnLimit variable runs to 0, the user has not chosen to 
	//quit, and the user has not lost the game, diaply winning message
	if ((quit != 1) && (lost ==0))
	{
		//display winning message
		space();
		std::cout << "Speaker: \"Attention Covenant, rescue ship now docking\"";
		std::cout << std::endl;

		//wait for user to hit enter
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();

		//if player unlocked Pilot Tennessee, output this message
		//when player has won
		if (tenCheck ==1)
		{
			std::cout << "Daniels and Tennessee are rescued and a marine squadron";
			std::cout << std::endl;
			std::cout << "is dispatched to eradicate the xenomorph.";
			std::cout << std::endl;
		}
	
		//if player has not unlocked Pilot Tennessee, output this message
		//when player has won
		if (tenCheck == 0)
		{
			std::cout << "Daniels narrowly makes it aboard the rescue ship with her life.";
			std::cout << std::endl;
			std::cout << "Her pilot Tennesse wasn't so lucky, the Covenant, him included,";
			std::cout << std::endl;
			std::cout << " had to be abandoned in deep space for the time being.";
			std::cout << std::endl;
			std::cout << "The risk of the xenomorph is too much to gamble with.";
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Congratulations, Daniels has survived.";
		std::cout << std::endl << std::endl;
		std::cout << "YOU WIN";
		std::cout << std::endl << std::endl;
	}

	//call function 5 times for the maximum number of items
	//in inventory
	danP.removeAll();
	danP.removeAll();
	danP.removeAll();
	danP.removeAll();
	danP.removeAll();
}



//Function name: turn()
//Parameters: none
//Return Value: none
//Description: Facilitates the taking of 1 turn by the player. Displays
//		the HUD for the player and takes any options the player
//		can make during a turn. 
void Game::turn()
{
	//make choice = -1 to inititate HUD and turn sequence
	int choice = -1;

	while (choice == -1)
	{
		space();
		//HUD
		//if player current location is colony chamber
		if (danP.getLocationName() == "Colony Chamber")
		{
			//show corresponding map
			map1();
		}
		else if (danP.getLocationName() == "Communications Room")
		{
			map2();
		}
		else if (danP.getLocationName() == "Medical Bay")
		{
			map3();
		}
		else if (danP.getLocationName() == "Loading Bay")
		{
			map4();
		}
		else if (danP.getLocationName() == "Biology Laboratory")
		{
			map5();
		}
		else if (danP.getLocationName() == "Navigation Room")
		{
			map6();
		}
		
		//display current player objective
		std::cout << std::endl;
		objective();	

		//display current player location
		std::cout << "Current Location: " << danP.getLocationName();
		std::cout << std::endl;
	
		//diplay current player health
		std::cout << "HP: " << danP.getHealth() << std::endl;

		//display current player turn number
		std::cout << "Turn Number: " << turnNumber << std::endl;

		//save user input in choice
		choice = menu1();

		//if input corresponds to move
		if (choice == 1)
		{
			//save user move input ot move choice
			int moveChoice = move();

			//if player chooses back
			if (moveChoice == -1)
			{
				//return -1 to rerun main turn menu
				//and not take a turn
				choice = -1;
			}
		}
	
		//if input corresponds to look around room
		if (choice == 2)
		{
			//if player location is medbay, display description
			//and options for medbay
			if (danP.getLocationName() == "Medical Bay")
			{
				space();
			
				//display room description
				medR.showDescR();
		
				//save output from med function to medchoice
				int medChoice = med();

				//if user decided to hit back in med function
				//make choice -1 to rerun main turn menu and not take turn
				if (medChoice == -1)
				{
					choice = -1;
				}
			}
		
			//if player location is comroom, display description 
			//and options for comroom
			else if (danP.getLocationName() == "Communications Room")
			{
				space();
				
				//display room description
				comR.showDescR();

				//save output from com function to comChoice
				int comChoice = com();

				//if user choooses back in com function, make choic -1
				//to rerun main turn menu and not take turrn
				if (comChoice == -1)
				{
					choice = -1;
				}
			}

			//if player location is navroom, display description 
			//and options for navroom
			else if (danP.getLocationName() == "Navigation Room")
			{
				space();
			
				//display room description
				navR.showDescR();
	
				//if user chooses back in nav function, make choice -1
				//to rerun main turn menu and not take turn
				int navChoice = nav();
				if (navChoice == -1)
				{
					choice = -1;
				}
			}

			//if player location is colony chamber,  display description 
			//and options for colony chamber
			else if (danP.getLocationName() == "Colony Chamber")
			{
				space();
				
				//display room description
				colR.showDescR();

				//save output from col function to colchoice
				int colChoice = col();

				//if user chooses back in col function, make choice -1
				//to rerun main turn menu and not take a turn
				if (colChoice == -1)
				{
					choice = -1;
				}
			}
		
			//if player location is comroom, display description 
			//and options for comroom
			if (danP.getLocationName() == "Biology Laboratory")
			{
				space();

				//display room description
				bioR.showDescR();

				//save output from bio function to biochoice
				int bioChoice = bio();
	
				//if user chooses back in bio function, make choice -1
				//to rerun main turn menu and not take turn
				if (bioChoice == -1)
				{
					choice = -1;
				}
			}
			//if player location is comroom, display description 
			//and options for comroom
			if (danP.getLocationName() == "Loading Bay")
			{
				space();

				//display room description
				loadR.showDescR();

				//save output from load function to loadchoice
				int loadChoice = load();

				//if user chooses back in load function, make choice
				//-1 to rerun main turn menu and not take a turn
				if (loadChoice == -1)
				{
					choice = -1;
				}
			}
		
		}
	
		//if player chooses to access inventory from 
		//main turn menu
		if (choice == 3)
		{
			space();
			
			//dsplay curren invrntoty
			danP.showInvent();
	
			//save user choice of inventory option to 
			//invchoice
			int invChoice = menuInv();
			
			//if user chooses to use medkit
			if (invChoice == 1)
			{
				//save output of useMedKit
				//to choice (-1 if successful)
				choice = danP.useMedkit();

				//if a medkit was used, take a turn
				if (choice != -1)
				{
					//set move tracker for player to 
					//0 showing they stood still
					//last turn
					danP.setMoveTrack(0);
				}	
			}

			//if user chooses to use xendet
			else if (invChoice == 2)
			{
				//save output from useXenDet() function
				//to choice (-1 if successful)
				choice = danP.useXenDet();

				//if player used xendet
				if (choice != -1)
				{
					//show player did not move last turn
					danP.setMoveTrack(0);
		
					//set counter for turns until
					//xenomorph ca attack player again
					xenoDet = 2;

					//make choice -1 so that no turn is 
					//taken and main turn menu is rerun
					choice = -1;
				}
			}
		
			//if user chooses back
			else if (invChoice == 3)
			{
				//make choice -1 so that no turn is
				//taken and main turn menu is rerun
				choice = -1;
			}
		}

		//if user chooses to quit
		if (choice == 4)
		{
			//ends the game
			turnLimit = 0;

			//keeps track of if user decided to quit so
			//win/loss messages are not displayed
			quit = 1;
			//breaks out of while loop for turn menu
			choice = 0;
		}
	}

}



//Function name: move()
//Parameters: none
//Return Value: none
//Description: uses the menu3 function to read user input and determines
//		which room to move the player to 
int Game::move()
{
	//saves choice of location to move to
	int doorNum;

	//save user input from menu that displays choices of 
	//rooms to move to based on player current location
	doorNum = menu3(danP.getLocation());

	//if user chooses first location to move to
	if (doorNum == 1)
	{
		//set player location to room behind door 1
		danP.setLocation(*(danP.getLocation()->getDoor1()));

		//show that player moved last turn
		danP.setMoveTrack(1);
	}
	
	//if user chooses second location to move to
	else if (doorNum == 2)
	{
		//set player location to room behind door 2
		danP.setLocation(*(danP.getLocation()->getDoor2()));

		//show that player moved last turn
		danP.setMoveTrack(1);

	}

	//if user chooses third location to move to
	else if (doorNum == 3)	
	{
		//set player location to room behind door 3
		danP.setLocation(*(danP.getLocation()->getDoor3()));

		//show that player moved last turn
		danP.setMoveTrack(1);

	}

	//if player chooses foruth location to move to
	else if (doorNum == 4)
	{
		//set player location to room behind door 4
		danP.setLocation(*(danP.getLocation()->getDoor4()));

		//show that player moved last turn
		danP.setMoveTrack(1);

	}

	//if player chooses back in movement menu
	else if (doorNum == 5)
	{
		//return -1 to not take turn and rerun main turn menu
		return -1;
	}
}



//Function name: med()
//Parameters: none
//Return Value: int (determines whether play function should take a turn)
//Description: uses the menuMed() function to read user input regarding
//		interacting with the medbay and calls the corresponding function
int Game::med()
{

	int medNum;

	//save player input from medmenu to mednum	
	medNum = menuMed();

	//if player chooses to heal 
	if (medNum == 1)
	{
		//if player has not healed recently
		if (madeHeal == 0)
		{
			//save output from heal function (-1 means
			//player is already at full health)
			int medCheck = medR.heal(danP);
		
			//if player was healed
			if (medCheck != -1)
			{	
				//make sure player cannot heal for 3 turns
				madeHeal = 3;
	
				//show player did not move last turn
				danP.setMoveTrack(0);
			}	

			//if player health already full
			if (medCheck == -1)
			{
				//sends -1 to main menu to reiterate without increasing
				//turn number
				return -1;
			}
		}

		//if the player has healed in a recent turn
		else if (madeHeal >0)
		{
			//display how many turns player must wait to heal
			std::cout << std::endl;
			std::cout << "Daniels is going to have to wait " << madeHeal;
			std::cout << " turn to use these meds to heal again...";
			std::cout << std::endl;
		
			//wait for player to hit enter
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();
			
			//return -1 so turn not taken and 
			//main turn menu rerun
			return -1;
		}
	}

	//if player chooses to make a medkit
	else if (medNum == 2)
	{
		//if player has not already made 4 medkits (limit)
		if (madeMedKit < 4)
		{
			//if player has room in inventory
			if ((danP.getDet() + danP.getMine() + danP.getMeds()) < 5)
			{
				//add medkit to inventory
				danP.addItem(medR.special2());

				//show that payer did not move last turn
				danP.setMoveTrack(0);

				//increment count of medkits made (4 max per game)
				madeMedKit ++;

				//return 0 to turn taken
				return 0;
			}
	
			//if inventory is full
			else 
			{
				//output full inventory message
				std::cout << std::endl;
				std::cout << "The inventory is full...";
				std::cout << std::endl;

				//wait for player to hit enter
				std::cin.clear();
				std::cin.ignore();
				std::cin.clear();
		
				//return -1 so turn not taken and 
				//main turn menu is rerun
				return -1;
			}	
		}

		//if player has already made 4 medkits
		else
		{
			//output message stating no more medkits to make
			std::cout << std::endl;
			std::cout << "Looks like there are no more supplies to make a"; 
			std::cout << std::endl;
			std::cout << "Medkit to go...";
			std::cout << std::endl;

			//wait for player to hit enter
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();
			
			//return -1 so no turn taken and main turn menu rerun
			return -1;
		}
	}

	//if user chooses back in medmenu
	else if (medNum == 3)
	{
		//return -1 so turn not taken and 
		//main turn menu rerun
		return -1;
	}
}



//Function name: com()
//Parameters: none
//Return Value: int (determines whether play function should take a turn)
//Description: uses the menuCom() function to read user input regarding
//		interacting with the ComRoom and calls the corresponding 
//		function
int Game::com()
{
	int comNum;
	
	//save user input from comms menu to comnum
	comNum = menuCom();

	//if player chose to access comm speaker
	if (comNum == 1)
	{
		//save output from coord() function to activate 
		//(1 if successful activation)
		activate = comR.coord(code,turnLimit);
	
		//if turn is to be taken (objective success)
		if (comR.getNoTurn() == 0)
		{
			//show player did not move last turn
			danP.setMoveTrack(0);
	
			//set variable that checks for this objective
			contact = 1;

			//return 0 to take turn
			return 0;
		}

		//if no turn is to be taken (objective not done yet)
		if (comR.getNoTurn() == 1)
		{
			//return -1 so no turn taken and main
			//turn menu rerun
			return -1;
		}
	}
	
	//if player chose to access terminal
	else if (comNum == 2)
	{
		//save output from special1() function to comcheck
		//(-1 if no new info here)
		int comCheck = comR.special1();

		//if the player has already accessed the terminal
		//and ther is no new info
		if (comCheck == -1)
		{
			//return -1 so no turn is taken and 
			//main turn menu rerun
			return -1;
		}
		
		//if player accessed this terminal for the first time
		else
		{
			//show player did not move last turn
			danP.setMoveTrack(0);

			//show player completed this objective
			gotAccess = 1;

			//return 0 to take turn
			return 0;
		}
	}

	//if player chose back in com menu
	else if (comNum == 3)
	{
		//return -1 so no turn taken and
		//main turn menu rerun
		return -1;
	}
}



//Function name: bio()
//Parameters: none
//Return Value: int (determines whether play function should take a turn)
//Description: uses the menuBio() function to read user input regarding
//		interacting with the bio lab and calls the corresponding 
//		function
int Game::bio()
{

	int bioNum;

	//save player input from bio menu to bionum	
	bioNum = menuBio();

	//if player chose to make xendet
	if (bioNum == 1)
	{
		//if player inventory not full
		if (((danP.getDet() + danP.getMine() + danP.getMeds()) < 5) && (madeXenDet == 0))
		{
			//add new nHxendet to player inventory
			danP.addItem(bioR.special2());

			//show player did not move last turn
			danP.setMoveTrack(0);

			//make player wait 5 turns to make another xendet
			madeXenDet = 5;

			//return 0 to take turn
			return 0;
		}
		
		//if player has made xendet in recent turn
		else if (madeXenDet > 0)
		{
			//output message for amount of turns to wait to make 
			//another
			std::cout << std::endl;
			std::cout << "Daniels is going to have to wait ";
			std::cout << madeXenDet << " more turns";
			std::cout << std::endl;
			std::cout << "to let the mysterious liquid replenish...";
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();

			//return -1 to not take turn and rerun
			//main turn menu
			return -1;	
		}
	
		//if inventory is full
		else 
		{
			//output full inventory message
			std::cout << std::endl;
			std::cout << "The inventory is full...";
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();

			//return -1 to not take turn and 
			//rerun main turn menu
			return -1;
		}
		
	}

	//if player chose to quit
	else if (bioNum == 2)
	{
		//return -1 so turn not taken and  
		//rerun main turn menu
		return -1;
	}
}



//Function name: load()
//Parameters: none
//Return Value: int (determines whether play function should take a turn)
//Description: uses the menuLoad() function to read user input regarding
//		interacting with the loading bay and calls the corresponding 
//		function
int Game::load()
{

	int loadNum;
	
	//save player input from load menu to loadnum
	loadNum = menuLoad();

	//if player chose to make mining tool
	if (loadNum == 1)
	{
		//if inventory has space and player has not made mining tool in recent turn
		if (((danP.getDet() + danP.getMine() + danP.getMeds()) < 5) &&(madeMineTool == 0))
		{
			//add new mining tool to inventory
			danP.addItem(loadR.special2());
			
			//show player did not move last turn
			danP.setMoveTrack(0);
	
			//make player wait 4 turns to make another
			//mining tool
			madeMineTool = 4;

			//return 0 to take turn
			return 0;
		}

		//if player has made mining tool in 
		//recent turn
		else if (madeMineTool > 0)
		{
			//output message for how may turns to 
			//wait till player can maek another
			std::cout << std::endl;
			std::cout << "Daniels is going to have to wait ";
			std::cout << madeMineTool << " more turns";
			std::cout <<std::endl;
			std::cout << "so she can gather parts...";	
			std::cin.clear();	
			std::cin.ignore();
			std::cin.clear();
			
			//return -1 so turn not taken and 
			//main turn menu rerun
			return -1;
		}

		//if inventory is full
		else 
		{
			//output full inventory message
			std::cout << std::endl;
			std::cout << "The inventory is full...";
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin.clear();
			return -1;
		}
		
	}

	//if player chose back
	else if (loadNum == 2)
	{
		//return -1 so turn not taken and
		//main turn menu rerun
		return -1;
	}
}



//Function name: nav()
//Parameters: none
//Return Value: int (determines whether play function should take a turn)
//Description: uses the menuNav() function to read user input regarding
//		interacting with the nav room and calls the corresponding 
//		function
int Game::nav()
{

	int navNum;
	
	//save player input from nav menu
	//to navnum
	navNum = menuNav();

	//if player chose to look at terminal
	if (navNum == 1)
	{	
		//if this is first time player chose
		//this option
		if (codeCheck == 0)
		{
			//save code generated from special1() function
			//to code variable
			code = navR.special1();
		
			//show player did not move last turn
			danP.setMoveTrack(0);

			//show that player has gotten
			//the code
			codeCheck =1;

			//return 0 to take turn
			return 0;
		}
		
		//if player has already gotten
		//the code
		if (codeCheck == 1)
		{
			//show no new info message from 
			//special1()
			trashCode = navR.special1();

			//return -1 so no turn taken
			//and main turn meu rerun
			return -1;
		}
	}
	
	//if player chose to look out window
	else if (navNum == 2)
	{
		space();

		//show graphic of window (changes
		//based on progression)
		navR.window(turnLimit);
		std::cin.clear();
		std::cin.ignore();
		std::cin.clear();

		//return -1 to not take turn and 
		//rerun main turn menu
		return -1;
	}

	//if player chose back
	else if (navNum == 3)
	{
		//return -1 to not take turn anf
		//rerun main turn menu
		return -1;
	}
}



//Function name: col()
//Parameters: none
//Return Value: int (determines whether play function should take a turn)
//Description: uses the menuCol() function to read user input regarding
//		interacting with the colony chamber and calls the corresponding
//		function
int Game::col()
{

	//declare integers for saving user input
	int colNum = 0;
	int colNum2 =0;

	//if tennessee has not been unlocked
	if (tenCheck == 0)	
	{
		//use this menu to save user input to
		//colnum
		colNum = menuCol();
	}

	//if tennessee has been unlocked
	if (tenCheck == 1)
	{
		//use this menu to save user input to
		//colnum2
		colNum2 = menuCol2();		
	}

	//if user chooses to open tennesee pod
	if (colNum == 1)
	{	
		//if player does not have access code from com room
		if (gotAccess == 0)
		{
			//do not let player unlock tennessee
			int col =colR.special1();

			//return -1 to not take
			//turn and rerun main turn menu
			return -1;
		}
	
		//if player has access code	
		if (gotAccess == 1)
		{
			//unlock tennessee and show prompt
			colR.unlock2();
	
			//show that tennessee has been unlocked
			tenCheck = 1;

			//show player did not move last turn
			danP.setMoveTrack(0);

			//return 0 to take turn
			return 0;
		}
	}

	//if player chooses back
	else if (colNum == 2)
	{
		//return -1 so turn not taken
		//and main turn menu rerun
		return -1;
	}

	//if player chooses to talk to tennessee
	if (colNum2 == 1)
	{
		//output any 1 of 4 dialogues from 
		//tennessee
		colR.talk();

		//return -1 so that turn not taken
		//and main turn menu rerun
		return -1;
	}
	
	//if player chose back
	else if (colNum2 == 2)
	{
		//return -1 so that turn not taken
		//and main turn menu rerun
		return -1;
	}
}



//Function name: map1()
//Parameters: none
//Return Value: none
//Description: displays the map showing the player in the colony
//		chamber
void Game::map1()
{
	//display map showing player in colony chamber
	std::cout << std::endl;
	std::cout <<"                   _______________" << std::endl;
	std::cout <<"                  |  Navigation   |"<< std::endl;
	std::cout <<"                  |     Room      |"<< std::endl;
	std::cout <<"                  |_______________|"<< std::endl;
	std::cout <<"                 /    |      |     \\" << std::endl;
	std::cout <<"                /     |      |      \\" <<std::endl;
	std::cout <<"               /  ____|_    _|____   \\" <<std::endl;
	std::cout <<"       _______/  | Med  |  | Comms|   \\_______" << std::endl;
	std::cout <<"      |Loading|  | Bay  |--| Room |   |  Bio  |" << std::endl;
	std::cout <<"      |  Bay  |--|______|  |______|---|  Lab  |" << std::endl;
	std::cout <<"      |_______|-----|---------|-------|_______|" << std::endl;
	std::cout <<"             \\      |         |        /       " << std::endl;
	std::cout <<"              \\_____|_________|_______/        " << std::endl;
	std::cout <<"              |        Colony         |        " << std::endl;
	std::cout <<"              |        Chamber        |        " << std::endl;
	std::cout <<"              |___________*___________|        " << std::endl;
	
}



//Function name: map2()
//Parameters: none
//Return Value: none
//Description: displays the map showing the player in the comms room
void Game::map2()
{
	//display map showing player in comms room 
	std::cout << std::endl;
	std::cout <<"                   _______________" << std::endl;
	std::cout <<"                  |  Navigation   |"<< std::endl;
	std::cout <<"                  |     Room      |"<< std::endl;
	std::cout <<"                  |_______________|"<< std::endl;
	std::cout <<"                 /    |      |     \\" << std::endl;
	std::cout <<"                /     |      |      \\" <<std::endl;
	std::cout <<"               /  ____|_    _|____   \\" <<std::endl;
	std::cout <<"       _______/  | Med  |  | Comms|   \\_______" << std::endl;
	std::cout <<"      |Loading|  | Bay  |--| Room |   |  Bio  |" << std::endl;
	std::cout <<"      |  Bay  |--|______|  |___*__|---|  Lab  |" << std::endl;
	std::cout <<"      |_______|-----|---------|-------|_______|" << std::endl;
	std::cout <<"             \\      |         |        /       " << std::endl;
	std::cout <<"              \\_____|_________|_______/        " << std::endl;
	std::cout <<"              |        Colony         |        " << std::endl;
	std::cout <<"              |        Chamber        |        " << std::endl;
	std::cout <<"              |_______________________|        " << std::endl;
	
}



//Function name: map3()
//Parameters: none
//Return Value: none
//Description: displays the map showing the player in the med bay
void Game::map3()
{
	//display map showing player in med bay
	std::cout << std::endl;
	std::cout <<"                   _______________" << std::endl;
	std::cout <<"                  |  Navigation   |"<< std::endl;
	std::cout <<"                  |     Room      |"<< std::endl;
	std::cout <<"                  |_______________|"<< std::endl;
	std::cout <<"                 /    |      |     \\" << std::endl;
	std::cout <<"                /     |      |      \\" <<std::endl;
	std::cout <<"               /  ____|_    _|____   \\" <<std::endl;
	std::cout <<"       _______/  | Med  |  | Comms|   \\_______" << std::endl;
	std::cout <<"      |Loading|  | Bay  |--| Room |   |  Bio  |" << std::endl;
	std::cout <<"      |  Bay  |--|__*___|  |______|---|  Lab  |" << std::endl;
	std::cout <<"      |_______|-----|---------|-------|_______|" << std::endl;
	std::cout <<"             \\      |         |        /       " << std::endl;
	std::cout <<"              \\_____|_________|_______/        " << std::endl;
	std::cout <<"              |        Colony         |        " << std::endl;
	std::cout <<"              |        Chamber        |        " << std::endl;
	std::cout <<"              |_______________________|        " << std::endl;
	
}



//Function name: map4()
//Parameters: none
//Return Value: none
//Description: displays the map showing the player in the loading bay
void Game::map4()
{
	//display map showing player in loading bay
	std::cout << std::endl;
	std::cout <<"                   _______________" << std::endl;
	std::cout <<"                  |  Navigation   |"<< std::endl;
	std::cout <<"                  |     Room      |"<< std::endl;
	std::cout <<"                  |_______________|"<< std::endl;
	std::cout <<"                 /    |      |     \\" << std::endl;
	std::cout <<"                /     |      |      \\" <<std::endl;
	std::cout <<"               /  ____|_    _|____   \\" <<std::endl;
	std::cout <<"       _______/  | Med  |  | Comms|   \\_______" << std::endl;
	std::cout <<"      |Loading|  | Bay  |--| Room |   |  Bio  |" << std::endl;
	std::cout <<"      |  Bay  |--|______|  |______|---|  Lab  |" << std::endl;
	std::cout <<"      |___*___|-----|---------|-------|_______|" << std::endl;
	std::cout <<"             \\      |         |        /       " << std::endl;
	std::cout <<"              \\_____|_________|_______/        " << std::endl;
	std::cout <<"              |        Colony         |        " << std::endl;
	std::cout <<"              |        Chamber        |        " << std::endl;
	std::cout <<"              |_______________________|        " << std::endl;
	
}



//Function name: map5()
//Parameters: none
//Return Value: none
//Description: displays the map showing the player in the bio lab
void Game::map5()
{
	//display map showing player in bio lab 
	std::cout << std::endl;
	std::cout <<"                   _______________" << std::endl;
	std::cout <<"                  |  Navigation   |"<< std::endl;
	std::cout <<"                  |     Room      |"<< std::endl;
	std::cout <<"                  |_______________|"<< std::endl;
	std::cout <<"                 /    |      |     \\" << std::endl;
	std::cout <<"                /     |      |      \\" <<std::endl;
	std::cout <<"               /  ____|_    _|____   \\" <<std::endl;
	std::cout <<"       _______/  | Med  |  | Comms|   \\_______" << std::endl;
	std::cout <<"      |Loading|  | Bay  |--| Room |   |  Bio  |" << std::endl;
	std::cout <<"      |  Bay  |--|______|  |______|---|  Lab  |" << std::endl;
	std::cout <<"      |_______|-----|---------|-------|___*___|" << std::endl;
	std::cout <<"             \\      |         |        /       " << std::endl;
	std::cout <<"              \\_____|_________|_______/        " << std::endl;
	std::cout <<"              |        Colony         |        " << std::endl;
	std::cout <<"              |        Chamber        |        " << std::endl;
	std::cout <<"              |_______________________|        " << std::endl;
}



//Function name: map6()
//Parameters: none
//Return Value: none
//Description: displays the map showing the player in the navigation room
void Game::map6()
{
	//display map showing player in navigation room 
	std::cout << std::endl;
	std::cout <<"                   _______________" << std::endl;
	std::cout <<"                  |  Navigation   |"<< std::endl;
	std::cout <<"                  |     Room      |"<< std::endl;
	std::cout <<"                  |_______*_______|"<< std::endl;
	std::cout <<"                 /    |      |     \\" << std::endl;
	std::cout <<"                /     |      |      \\" <<std::endl;
	std::cout <<"               /  ____|_    _|____   \\" <<std::endl;
	std::cout <<"       _______/  | Med  |  | Comms|   \\_______" << std::endl;
	std::cout <<"      |Loading|  | Bay  |--| Room |   |  Bio  |" << std::endl;
	std::cout <<"      |  Bay  |--|______|  |______|---|  Lab  |" << std::endl;
	std::cout <<"      |_______|-----|---------|-------|_______|" << std::endl;
	std::cout <<"             \\      |         |        /       " << std::endl;
	std::cout <<"              \\_____|_________|_______/        " << std::endl;
	std::cout <<"              |        Colony         |        " << std::endl;
	std::cout <<"              |        Chamber        |        " << std::endl;
	std::cout <<"              |_______________________|        " << std::endl;
	
}



//Function name: space()
//Parameters: none
//Return Value: none
//Description: displays 60 lines of blank space
void Game::space()
{
	//display 60 lines of blank space to simulate
	//clearing screen
	for (int x = 0; x < 60; x++)
	{
		std::cout << std::endl;
	}
}



//Function name: objective()
//Parameters: none
//Return Value: none
//Description: displays the player objective reflecting the players
//		game progress
void Game::objective()
{
	//show this objective based on certain objectives completed in game
	if ((contact == 0) && (activate == 0) && (codeCheck ==0))
	{
		std::cout << "Current Objective: communicate to HQ for rescue";
		std::cout << std::endl;
	}

	//show this objective based on certain objectives completed in game
	else if ((contact == 1) && (activate == 0) && (codeCheck == 0))
	{
		std::cout << "Current Objective: access current navigational coordinate code";
		std::cout << std::endl;
	}

	//show this objective based on certain objectives completed in game
	else if ((activate == 0) && (codeCheck == 1))
	{
		std::cout << "Current Objective: communicate the coordinate code to HQ";
		std::cout << std::endl;
	}

	//show this objective based on certain objectives completed in game
	else if ((contact == 1) && (activate == 1) && (codeCheck == 1))	
	{
		std::cout << "Current Objective: survive until rescue arrives";
		std::cout << std::endl;
	}
}


