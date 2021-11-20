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

/*-----------------------------------------------------------------------------
 * Alexey's modifications, declared the RoadObjectClass
 *-----------------------------------------------------------------------------*/
class RoadObjectClass;
/*-----------------------------------------------------------------------------
 * Alexey's modifications end 
 *-----------------------------------------------------------------------------*/

class Vehicle{
public:

    Vehicle(int size);
    const int& GetSize() const;

     void setRoute( std::vector<RoadLineClass*> newRoute);
     //FindNextRoad defined in roadlineclass.cpp because of circular dependency

     /*-----------------------------------------------------------------------------
      * Alexey's modifications, changed the return type for RoadObjectClass*,
      * added the functions for destination
      *-----------------------------------------------------------------------------*/
     void setDestination( RoadObjectClass* ptrToBuilding );
     RoadObjectClass* getDestination();
     RoadObjectClass* FindNextRoad(CrossroadClass* currentCross);
private:
    //Navigator* navigator_;
    int size_;
    std::vector<RoadLineClass*> route_;

    /*-----------------------------------------------------------------------------
     * Alexey's modification, added the destination building
     *-----------------------------------------------------------------------------*/
    RoadObjectClass* destination_;
};

#endif
