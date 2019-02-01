/****************************************************************************
* File Name: Daniels.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Daniels class,
* 		which represents the player in the game (character is named
* 		Daniels). For data members, this class holds members to 
* 		keep track of the player inventory, player movement, 
* 		player locations, and player health. For member functions,
* 		the Daniels class holds functions to facilitate the 
* 		use and addition of items to and from the inventory,
* 		modify and display player health, and move the player.
*************************************************************************/

#ifndef DANIELS_HPP
#define DANIELS_HPP

#include <list>
#include "Item.hpp"
#include "Room.hpp"



class Daniels
{
	private:
		std::list <Item*> inventory;
		std::list <Item*>::iterator iter;
		int health;
		int medCheck;
		int det;
		int mine;
		int meds;
		int moveTrack;
		Room* location;
	public:
		Daniels();
		//param number of item in inventory
		Item* getItem(int);
		void addItem(Item*);
		void removeMine();
		void showInvent();
		void modHealth(int);
		int getHealth();
		void damage(int);
		void setLocation(Room &current);
		std::string getLocationName();
		Room* getLocation();
		int useMedkit();
		int useXenDet();	
		int getDet();
		int getMine();
		int getMeds();
		void move();
		int getMoveTrack();
		void setMoveTrack(int);
		void removeAll();
};

#endif
		
		
