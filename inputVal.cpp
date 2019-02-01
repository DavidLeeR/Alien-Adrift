/****************************************************************************
 * File Name: inputVal.cpp
 * Author: David Ramirez
 * Date: 6/13/17
 * Description: This is the inplementation file for the 2 inputVal functions.
 * 		The inputVal function makes certain that the input passed
 * 		to it by the main function is an integer, in which case
 * 		the inputVal function returns true. If the input is found
 * 		not to be an integers, the inputVal function returns false.
 * 		The inputValF function completes the same task, except 
 * 		it makes certain the input is a float value.
 * *************************************************************************/

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <string>
#include <cmath>
#include "inputVal.hpp"



//Function name: inputVal
//Parameters: input (string holding user input)
//Return Value: bool 
//Description: Returns true if input passed is an integer, returns false if not
bool inputVal(std::string input)
{

	//This input validation function is modified code from a 
	//tutorial post on dreamincode.net by author "Tapas Bose".
	//www.dreamincode.net/forums/topic/162924-inout-validation-of-integer-
	//and-floating-point-number-using-strtol-a/
	char *last;

	//if there is no input
	if (input.empty())
	{ 
		return false; 
	}
	
	errno = 0;	//keeps track of underflow or overflow of int type
	int integerVal = strtol(input.c_str(), &last, 10);		
	
	
	//if overflow or underflow or if any input conversion error 
	if (((errno == ERANGE) && 	
	    (integerVal == INT_MAX || integerVal == INT_MIN)) || 
	    (errno != 0 && integerVal == 0)) 
	{
			 
		return false; 
	}
	
	//if input string contains a character
	else if (last == input || *last != '\0') 
	{		
		return false; 
	}

	return true;		
}



//Function name: inputValF
//Parameters: input2 (string holding user input)
//Return Value: bool 
//Description: Returns true if input passed is float, returns false if not
bool inputValF(std::string input2)
{
	char* last4;

	//if there is no input
	if (input2.empty()) 
	{
		return false;
	}

	errno = 0;      //keeps track of underflow or overflow of float type
	double floatVal = strtod(input2.c_str(), &last4);

	//if overflow or underflow or if any input conversion error
	if ((errno == ERANGE && (floatVal == HUGE_VALF || floatVal == 
	     HUGE_VALL)) || (errno != 0 && floatVal == 0))
	{
		return false;
	}

	//if input string contains a character
	else if (last4 == input2 || *last4 != '\0')
	{
		return false;
	}

	return true;
}
