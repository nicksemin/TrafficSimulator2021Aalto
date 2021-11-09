/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Traffic Simulator Group 1
 *
 *        Version:  0.01
 *        Created:  11/06/2021 08:47:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Authors:
 *	   Member 1 Nikita Tarutin
 *	   Member 2 Emma Rauhala
 *	   Member 3 Nikolai Semin
 *	   Member 4 Alexey Serous
 *	   Member 5 Lauri Sivuoja
 *
 *   Organization:  Aalto
 *
 * =====================================================================================
 */

//standard library include
#include <iostream>

//local inlude
#include "./include/CityObject.hpp"
#include "./include/Vehicle.hpp"
#include "./include/roadlineclass.hpp"

int main( int argc, char* argv[] )
{
	std::cout << "Hello, I am an empty main function for Traffic Simulator\n";

	/*-----------------------------------------------------------------------------
	 * RoadLineClass initial test, Alexey
	 *-----------------------------------------------------------------------------*/
	RoadLineClass road1{ 10, nullptr, nullptr };

	Vehicle a{ 1 };
	Vehicle b{ 3 };
	Vehicle c{ 1 };

	road1.takeVehicle( &a );
	for ( int i{ 0 }; i < 5; ++i ){
		road1.moveCars();
	}
	road1.takeVehicle( &b );
	for ( int i{ 0 }; i < 10; ++i ){
		road1.moveCars();
	}

	return 0;
}
