/****************************************************************************
 * File Name: menu.hpp
 * Author: David Ramirez
 * Date: 6/13/17
 * Description: This is the implementation file for the menu() functions. These 
 * 		functions provides user feedback to various Game class 
 * 		member functions in order for the user to control program input
 * 		as well as function execution.
 * *************************************************************************/



#include <string>
#include <iostream>
#include "inputVal.hpp"
#include "menu.hpp"



//Function Name: menu()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute and returns an integer representing this choice
int menu1()
{
	int choose;
	std::string input;
	char* last;

	//display main menu
	std::cout << std::endl;
	std::cout << "Enter a choice from the menu:";
	std::cout << std::endl;		
	std::cout << "1: move Daniels to another room (1 turn)" << std::endl;
	std::cout << "2: look around the room" << std::endl;
	std::cout << "3: access inventory" << std::endl;
	std::cout << "4: quit" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 4))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try agian.";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to move to another room
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to look around room
	if (choose == 2)
	{
		return 2;	
	}
	
	//corresponds to access inventory
	if (choose == 3)
	{
		return 3;	

	}
	//corresponds to quit
	if (choose == 4)
	{
		return 4;	

	}	
}



//Function Name: menu3()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding moving the player and returns an integer 
//		representing this choice
int menu3(Room* move)
{
	int choose;
	std::string input;
	char* last;


	//display list of rooms to move to
	std::cout << std::endl;		
	std::cout << "1: move to " << (*move).getDoor1Name() <<  std::endl;
	std::cout << "2: move to " << (*move).getDoor2Name() << std::endl;
	std::cout << "3: move to " << (*move).getDoor3Name() << std::endl;
	std::cout << "4: move to " << (*move).getDoor4Name() << std::endl;
	std::cout << "5: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 5))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to door1
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to door2
	if (choose == 2)
	{
		return 2;
	}
	
	//corresponds to door3
	if (choose == 3)
	{
		return 3;

	}
	//corresponds to door4
	if (choose == 4)
	{
		return 4;	

	}

	//corresponds to back
	if (choose ==5)
	{
		return 5;	

	}
}



//Function Name: menuMed()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the medbay and returns an integer 
//		representing this choice
int menuMed()
{
	int choose;
	std::string input;
	char* last;


	//display list of Med bay options
	std::cout << std::endl;		
	std::cout << "1: heal Daniels (1 turn)" <<  std::endl;
	std::cout << "2: create a Medkit (1 turn)" << std::endl;
	std::cout << "3: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 3))
	{	
		//display invalid input message
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to heal 
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to make medkit
	if (choose == 2)
	{
		return 2;	
	}
	
	//corresponds to back
	if (choose == 3)
	{
		return 3;

	}	
}



//Function Name: menuInv()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the inventory and returns an integer 
//		representing this choice
int menuInv()
{
	int choose;
	std::string input;
	char* last;


	//display inventory options
	std::cout << std::endl;		
	std::cout << "1: use Medkit (1 turn)" <<  std::endl;
	std::cout << "2: use Xenomorph Deterrant" << std::endl;
	std::cout << "3: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 3))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is inivalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to use medkit
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to use xenomorph deterrant
	if (choose == 2)
	{
		return 2;	
	}
	
	//corresponds to back
	if (choose == 3)
	{
		return 3;	

	}	
}



//Function Name: menuCom()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the com room and returns an integer 
//		representing this choice
int menuCom()
{
	int choose;
	std::string input;
	char* last;


	//display communications room options
	std::cout << std::endl;		
	std::cout << "1: access comm speaker (1 turn)" <<  std::endl;
	std::cout << "2: access computer terminal (1 turn)" << std::endl;
	std::cout << "3: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 3))
	{	
		//display invalid input message
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds access comm speaker
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to access comp terminal
	if (choose == 2)
	{
		return 2;	
	}
	
	//corresponds to back
	if (choose == 3)
	{
		return 3;	

	}	
}



//Function Name: menuHide()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding hiding and returns an integer 
//		representing this choice
int menuHide()
{
	int choose;
	std::string input;
	char* last;


	//display options when found by xenomorph
	std::cout << std::endl;		
	std::cout << "1: hide (no chance to use mining tool defense if seen)" <<  std::endl;
	std::cout << "2: stay in the open" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 2))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to hide
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to stay in open
	if (choose == 2)
	{
		return 2;	
	}	
}



//Function Name: menuNav()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the nav room and returns an integer 
//		representing this choice
int menuNav()
{
	int choose;
	std::string input;
	char* last;


	//display navigation room options
	std::cout << std::endl;		
	std::cout << "1: access the navigation computer terminal (1 turn)" <<  std::endl;
	std::cout << "2: look out cockpit window" << std::endl; 
	std::cout << "3: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 3))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds access nagivation comp terminal
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to look out window
	if (choose == 2)
	{
		return 2;
	}
	
	if (choose ==3)
	{
		return 3;
	}
}



//Function Name: menuCol()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the colony chamber and returns an integer 
//		representing this choice
int menuCol()
{
	int choose;
	std::string input;
	char* last;


	//display colony chamber options
	std::cout << std::endl;		
	std::cout << "1: open Tennessee's stasis pod" <<  std::endl;
	std::cout << "2: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 2))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to open Tennessee pod
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to back
	if (choose == 2)
	{
		return 2;	
	}
}



//Function Name: menuCol2()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the colony chamber and returns an integer 
//		representing this choice
int menuCol2()
{
	int choose;
	std::string input;
	char* last;


	//display colony chamber options after tennessee unlocked
	std::cout << std::endl;		
	std::cout << "1: talk to Tennessee" <<  std::endl;
	std::cout << "2: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 2))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to talk to tennessee
	if (choose == 1)
	{
		return 1;
	}

	//corresponds to back
	if (choose == 2)
	{
		return 2;	
	}
}



//Function Name: menuBio()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the bio lab and returns an integer 
//		representing this choice
int menuBio()
{
	int choose;
	std::string input;
	char* last;


	//display options for biology lab
	std::cout << std::endl;		
	std::cout << "1: create xenomorph deterrant (1 turn)" <<  std::endl;
	std::cout << "2: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 2))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to make xenomorph deterrant
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to back
	if (choose == 2)
	{
		return 2;	
	}
}



//Function Name: menuLoad()
//Parameters: none
//Return Value: integer (integer representing user choice in program 
//		next function execution)
//Description: Prompts the user with options for the functions the program
//		can execute regarding the loading bay and returns an integer 
//		representing this choice
int menuLoad()
{
	int choose;
	std::string input;
	char* last;


	//display loading bay options
	std::cout << std::endl;		
	std::cout << "1: assemble a mining tool (1 turn)" <<  std::endl;
	std::cout << "2: back" << std::endl;
	
	getline(std::cin, input);
	std::cout << std::endl;
		
	std::cin.clear();
		
	//validates user input to be an integer and in bounds
	while ((inputVal(input) == false ) || 
	    (strtol(input.c_str(), &last, 10) < 1)||
	    (strtol(input.c_str(), &last, 10) > 2))
	{	
		//display invalid input message 
		std::cout << std::endl;
		std::cout << "The input entered is invalid, try again";
		std::cout << std::endl;
		
		//save input in string for data validation
		getline(std::cin, input);
		std::cout << std::endl;

	}
	//save user choice after data validation
	choose = strtol(input.c_str(), &last, 10);	
			
	//corresponds to make mining tool
	if (choose == 1)
	{
		return 1;	
	}

	//corresponds to back
	if (choose == 2)
	{
		return 2;	
	}
}


