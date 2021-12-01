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
#include "./include/CityObject.hpp"
#include "./include/Vehicle.hpp"
#include "./include/roadlineclass.hpp"
#include "./include/cityclass.hpp"
#include "./include/Car.hpp"
#include "./include/Navigator.hpp"
#include "./include/Building.hpp"
int main( int argc, char* argv[] )
{
	std::cout << "Hello, I am an empty main function for Traffic Simulator\n";

	/*-----------------------------------------------------------------------------
	 * RoadLineClass initial test, Alexey
	RoadLineClass road1{ 10, nullptr, nullptr };

	Vehicle a{ 1 };
	Vehicle b{ 3 };
	Vehicle c{ 1 };

	road1.takeVehicle( &a, nullptr );
	for ( int i{ 0 }; i < 5; ++i ){
		road1.performTimeStep();
	}
	road1.takeVehicle( &b, nullptr );
	for ( int i{ 0 }; i < 10; ++i ){
		road1.performTimeStep();
	}

	Obsolete 16.11.2021, Alexey
	 *-----------------------------------------------------------------------------*/

	/* Obsolete 26.11.2021, Alexey
	 * BuildingExitCrossroad initial test, Alexey
	 *-----------------------------------------------------------------------------
	BuildingExitCrossroad cross1{ 0, 0 };
	BuildingExitCrossroad cross2{ 10, 0};
	BuildingExitCrossroad cross3{ 110, 0 };

	RoadLineClass road1{ &cross1, &cross2 };
	RoadLineClass road2{ &cross2, &cross3 };

	std::vector<RoadLineClass*> route { &road1, &road2 };

	RecreationalBuilding building1( &cross2, 1 );
	CommercialBuilding building2( &cross3, 2 );

	Vehicle car1{ 1 };
	Vehicle car2{ 4 };

	car1.setRoute( route );
	route.resize( 1 );
	route[ 0 ] = &road2;
	car2.setRoute( route );

	car1.setDestination( &building2 );

	road1.takeVehicle( &car1, nullptr );
	building1.takeVehicle( &car2, nullptr);

	int i{};

	std::array<RoadObjectClass*, 5> smallCity { &cross1, &cross2, &cross3, &road1, &road2 };

	while ( i < 20 ) {
		for ( auto element : smallCity ){
			element->performTimeStep();
		}
		if ( i > 2 ) {
			building1.RemoveVehicle( &car2 );
		}
		++i;
	}
	*/

	/*-----------------------------------------------------------------------------
	 * UnregulatedCrossRoad tests, Alexey
	 *-----------------------------------------------------------------------------*/
/*<<<<<<< HEAD
	UnregulatedCrossroad center{ 0, 0 };
	UnregulatedCrossroad left{ -20, 0 };
	UnregulatedCrossroad right{ 20, 0 };
	UnregulatedCrossroad down{ 0, -20 };
	UnregulatedCrossroad up{ 0, 120 };
=======
	UnregulatedCrossroad center{ 0, 0, 1 };
	UnregulatedCrossroad left{ -20, 0, 2 };
	UnregulatedCrossroad right{ 20, 0, 3 };
	UnregulatedCrossroad down{ 0, -20, 4 };
	UnregulatedCrossroad up{ 0, 20, 5 };
>>>>>>> 289a1fc66be8bb6633a89f73ca26671e5f92a3ea

	RoadLineClass leftRoad{ &left, &center };
	RoadLineClass rightRoad{ &right, &center };
	RoadLineClass downRoad{ &down, &center };
	RoadLineClass upRoad{ &center, &up };

	std::vector<RoadLineClass*> route { &leftRoad, &upRoad };
	Vehicle leftCar1{ 1 };
	Vehicle leftCar2{ 1 };
	Vehicle leftCar3{ 1 };
	leftCar1.setRoute( route );
	leftCar2.setRoute( route );
	leftCar3.setRoute( route );
	leftRoad.takeVehicle( &leftCar1, nullptr );
	leftRoad.performTimeStep();
	leftRoad.takeVehicle( &leftCar2, nullptr );
	leftRoad.performTimeStep();
	leftRoad.takeVehicle( &leftCar3, nullptr );

	route[ 0 ] = &rightRoad;

	Vehicle rightCar1{ 1 };
	Vehicle rightCar2{ 1 };
	Vehicle rightCar3{ 1 };
	rightCar1.setRoute( route );
	rightCar2.setRoute( route );
	rightCar3.setRoute( route );
	rightRoad.takeVehicle( &rightCar1, nullptr );
	rightRoad.performTimeStep();
	rightRoad.takeVehicle( &rightCar2, nullptr );
	rightRoad.performTimeStep();
	rightRoad.takeVehicle( &rightCar3, nullptr );

	route[ 0 ] = &downRoad;

	Vehicle downCar1{ 1 };
	Vehicle downCar2{ 1 };
	Vehicle downCar3{ 1 };
	downCar1.setRoute( route );
	downCar2.setRoute( route );
	downCar3.setRoute( route );
	downRoad.takeVehicle( &downCar1, nullptr );
	downRoad.performTimeStep();
	downRoad.takeVehicle( &downCar2, nullptr );
	downRoad.performTimeStep();
	downRoad.takeVehicle( &downCar3, nullptr );

	std::vector<RoadObjectClass*> objects { &leftRoad, &rightRoad, &upRoad,
		&downRoad, &center };
	for ( int i{ 0 }; i < 15; ++i ){
		for ( auto& element : objects ){
			element->performTimeStep();
		}
	}

	std::cout << "Done\n";*/
	/*-----------------------------------------------------------------------------
	 * Navigator tests by Nikita
	 *-----------------------------------------------------------------------------*/


	/*std::vector<RoadLineClass*> map = {&leftRoad, &upRoad};
	std::vector<CrossroadClass*> crossroads = {&left, &center, &up};
	Navigator* n = new Navigator(map, crossroads);

	std::vector<RoadLineClass*> route2 = n->MakeRoute(left, up);


	/* CrossroadClass cr1;
	CrossroadClass cr2;
	RoadLineClass road2{ 15, &cr1, &cr2 };
	CrossroadClass cr3;
	RoadLineClass road3{ 20, &cr2, &cr3 };

	std::vector<RoadLineClass*> map = {&road2, &road3};
	Navigator* n = new Navigator(map);
	std::vector<RoadLineClass*> route = n->MakeRoute(cr1, cr2);
	Car d{3};
	d.setRoute(route);*/

	/*-----------------------------------------------------------------------------
	 * Building tests by Emma
	 *-----------------------------------------------------------------------------

	std::cout << building1.GetID() <<std::endl;
	std::cout << building2.GetID() <<std::endl;

	std::cout << building1.GetType() <<std::endl;
	std::cout << building2.GetType() <<std::endl;

	building2.takeVehicle( &car1, nullptr);
	building2.takeVehicle( &car2, nullptr);


	for (auto vehicle : building2.GetVehicles()){
		std::cout<< vehicle->GetSize()<<std::endl;
	}
	*/

	/*-----------------------------------------------------------------------------
	 * CityClass tests, Alexey
	 *-----------------------------------------------------------------------------*/
	std::string filename{ "../build/samplecity.txt" };
	CityClass testCity { filename };
	return 0;

}


