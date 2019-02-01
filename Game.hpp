/****************************************************************************
* File Name: Game.hpp
* Author: David Ramirez
* Date: 6/13/17
* Description: This is the header file for the Game class,
* 		which instantiates and holds all other objects as data
* 		members. This class represents a game that the user plays.
* 		It also holds as data members integers that keep track of
* 		events that take place during the game. For member 
* 		function, it contains functions for the player to interact
* 		with the rooms, take turns, and be attacked by the enemy
* 		xenomorph.
*************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <ctime>
#include "Daniels.hpp"
#include "NavRoom.hpp"
#include "BioLab.hpp"
#include "LoadBay.hpp"
#include "MedBay.hpp"
#include "ComRoom.hpp"
#include "ColChamber.hpp"
#include "Xenomorph.hpp"
#include "menu.hpp"



class Game
{
	private:
		ColChamber colR;
		ComRoom comR;
		LoadBay loadR;
		MedBay medR;
		NavRoom navR;
		Daniels danP;
		BioLab bioR;
		Xenomorph xenE;
		Xenomorph xenE2;	
		Xenomorph xenE3;
		int turnLimit;
		int turnNumber;
		int lost;
		int code;
		int contact;
		int trashCode;
		int codeCheck;
		int activate;   //starts round countdown to win
		int gotAccess;	//keeps track if you have Commanders access =1 
		int tenCheck;		// if yes
		int xenoDet;
		int quit;
		int madeXenDet;
		int madeMineTool;
		int madeHeal;
		int madeMedKit;
		int thirdSet;
		int oneMore;
	public:
		Game();
		void preface();
		void play();
		void turn();
		int move();
		void map1();
		void map2();
		void map3();
		void map4();
		void map5();
		void map6();
		int med();
		int com();
		int nav();
		int col();
		int bio();
		int load();
		void space();
		void objective();
		
};

#endif



