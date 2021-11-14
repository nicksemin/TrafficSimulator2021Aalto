#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include <vector>

/* 
* A base Vehicle class. Vehicle objects are stored within city objects, occupying their load capacity with the value of size_. 
* Contact info - Nikita
*/
class RoadLineClass;
class CrossroadClass;
class Vehicle{
public:

    Vehicle(int size);
    const int& GetSize() const;

     void setRoute( std::vector<RoadLineClass*> newRoute);
     //FindNextRoad defined in roadlineclass.cpp because of circular dependency
     RoadLineClass* FindNextRoad(CrossroadClass* currentCross);
private:
    //Navigator* navigator_;
    int size_;
    std::vector<RoadLineClass*> route_;
};

#endif
