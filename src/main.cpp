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
#include <QApplication>
#include <simulationview.h>

static int tickTime;

int main( int argc, char* argv[] )
{

	/*-----------------------------------------------------------------------------
	 * CityClass tests, Alexey (and Emma)
	 *-----------------------------------------------------------------------------*/

    std::string filename{ "/Users/nicksemin/Programming/traffic-simulator-1/input_file/samplecity.txt" };
    try{

        CityClass testCity { filename };
        // for (auto const& building : testCity.GetRESBuildings()){
        //     std::cout<< building.first<<std::endl;
        // }

        Simulation testSimulation{&testCity,2160,24,"output_file/output.csv","1"};
        QApplication a(argc, argv);
        SimulationView view;
        testSimulation.Init();
        testSimulation.Simulate();
        QObject::connect(&testCity, &CityClass::sendX, &view, &SimulationView::getCross);
        QObject::connect(&testCity, &CityClass::sendR, &view, &SimulationView::getRoads);
        testCity.sendCoords();
        view.drawCity();
        view.show();
        QApplication::exec();
    }
    catch( UserInputException& e ){
        std::cout << e.what() << e.getCustomMessage() << std::endl;
    }

    return 0;

}


