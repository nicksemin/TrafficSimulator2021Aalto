#ifndef CAR_HPP
#define CAR_HPP

#include "Vehicle.hpp"
#include "Navigator.hpp"

/* 
* Car class, inherited from Vehicle and Navigator classes.
* Methods: 
* - GetSize()
* - MakeRoute(CrossroadClass start, CrossroadClass end)
* - FindNextRoad(CrossroadClass* currentCross)
*/

class Car: public Vehicle, public Navigator{
public:
    Car(int size, std::vector<RoadLineClass*> map);
};

#endif