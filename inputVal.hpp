/****************************************************************************
 * File Name: inputVal.hpp
 * Author: David Ramirez
 * Date: 6/13/17
 * Description: This is the header file for the 2 inputVal functions.
 * 		The inputVal function makes certain that the input passed
 * 		to it by the main function is an integer, in which case
 * 		the inputVal function returns true. If the input is found
 * 		not to be an integers, the inputVal function returns false.
 * 		The inputValF function completes the same task, except 
 * 		it makes certain the input is a float value.
 * *************************************************************************/

#ifndef INPUT_VAL_HPP
#define INPUT_VAL_HPP

#include <string>



bool inputVal(std::string);

bool inputValF(std::string);


#endif
