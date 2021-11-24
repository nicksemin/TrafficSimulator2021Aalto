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
#include "./include/CityObject.hpp"
#include "./include/Vehicle.hpp"
#include "./include/roadlineclass.hpp"
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

	/*-----------------------------------------------------------------------------
	 * BuildingExitCrossroad initial test, Alexey
	 *-----------------------------------------------------------------------------*/
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

	/*-----------------------------------------------------------------------------
	 * Navigator tests by Nikita
	 *-----------------------------------------------------------------------------*/

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

	return 0;
	
}
