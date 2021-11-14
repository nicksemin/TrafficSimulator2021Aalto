#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include <vector>

/* 
* An abstract vehicle class. Vehicle objects are stored within city objects, occupying their load capacity with the value of size_. 
*/

class Vehicle{
public:

    Vehicle(int size);
    const int& GetSize() const;

    //RoadLineClass* ChooseRoad(CrossroadClass* crossRoad);

private:
    //Navigator* navigator_;
    int size_;
   
};

#endif
