/****************************************************************************
 * File Name: menu.hpp
 * Author: David Ramirez
 * Date: 6/13/17
 * Description: This is the header file for the menu() functions. These 
 * 		functions provides user feedback to various Game class 
 * 		member functions in order for the user to control program input
 * 		as well as function execution.
 * *************************************************************************/


#ifndef MENU_HPP
#define MENU_HPP

#include "Room.hpp"
#include "ColChamber.hpp"
#include "MedBay.hpp"
#include "LoadBay.hpp"
#include "ComRoom.hpp"
#include "NavRoom.hpp"
#include "BioLab.hpp"



int menu1();
int menu2();
int menu3(Room* move);
int menuMed();
int menuInv();
int menuCom();
int menuHide();
int menuNav();
int menuCol();
int menuCol2();
int menuBio();
int menuLoad();

#endif
