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
#include <array>

//local inlude
#include "./include/buildingexitcrossroad.hpp"
#include "./include/unregulatedcrossroad.hpp"
#include "./include/trafficlightcrossroad.hpp"
#include "./include/CityObject.hpp"
#include "./include/Vehicle.hpp"
#include "./include/roadlineclass.hpp"
#include "./include/cityclass.hpp"
#include "./include/Car.hpp"
#include "./include/Navigator.hpp"
#include "./include/Building.hpp"
#include "./include/Simulation.hpp"

static int tickTime;

int main( int argc, char* argv[] )
{

	/*-----------------------------------------------------------------------------
	 * CityClass tests, Alexey (and Emma)
	 *-----------------------------------------------------------------------------*/
    //std::string filename{ "../input_file/samplecity.txt" };
	std::string fileName{};
	std::string outputFile{};
	std::string road{};
	unsigned int population{};
	double time{};
	if ( argc == 6 ) {
		std::stringstream convert{};
		fileName = argv[ 1 ];
		convert << argv[ 2 ] << ' ' << argv[ 3 ];
		convert >> population >> time;
		outputFile = argv[ 4 ];
		road = argv[ 5 ];
		std::cout << "The input data was passed by parameters:\n" << fileName << ';' <<
			population << ';' << time << ';' << outputFile << ';' << road <<'\n';

	}
	else {
		std::cout << "Please input the filename that contains the information about a city\n";
		std::cin >> fileName;
		std::cout << "Please input the desired population\n";
		std::cin >> population;
		std::cout << "Please input the desired simulation time in hours\n";
		std::cin >> time;
		std::cout << "Please input the desired output file\n";
		std::cin >> outputFile;
		std::cout << "Please input the desired road name for output\n";
		std::cin >> road;
	}
	try{
		CityClass testCity { fileName };
		Simulation testSimulation{&testCity, population, time, outputFile, road};
		testSimulation.Init();
		testSimulation.Simulate();
	}
	catch( UserInputException& e ){
		std::cout << e.what() << e.getCustomMessage() << std::endl;
	}
	return 0;
}


