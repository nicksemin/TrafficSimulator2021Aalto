#ifndef BUILDING_HPP
#define BUILDING_HPP

/*-----------------------------------------------------------------------------
 * Alexey's changes for merge request
 * the class now inherits RoadObjectClass
 * added required override functions to satisfy RoadObject interfaces
 * modified the constructor for correct interraction with crossroads
 * changed the type of crossroad inside the container
 * modified Remove function to send a vehicle to the road
 *
 * CrossroadClass and RoadLineClass do not know about buildings to avoid
 * cross-dependency. They can treat buildings as RoadObjecClass* via virtual
 * functions
 *-----------------------------------------------------------------------------*/

#include "buildingexitcrossroad.hpp" //already includes vehicle and road object

// #include "Person.hpp"

#include <string>
#include <vector>

class Building : public RoadObjectClass
{
public:
    /*Constructor*/
    Building( BuildingExitCrossroad* exitCrossRoad, unsigned int vehiclecapacity); //name?

    /*Destructor MIGHT NOT BE NEEDED*/
    //~Building();

    /*Take in a vehicle*/
    bool takeVehicle( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject ) override;

    //perform actions during a time step, implemented as an empty function for now
    void performTimeStep() override;

    /*Remove a vehicle*/
    bool RemoveVehicle (Vehicle* vehicle);

    // /*Take in a person*/
    // void TakePerson(Person* person);

    // /*Remove a person*/
    // bool RemovePerson(Person* person);

    /*Get the CrossRoads through which the building is accessed*/
    BuildingExitCrossroad* GetExit() const;

    /*Get all vehicles currently in this building*/
    std::vector<Vehicle*> GetVehicles() const;

    /*Get all people currently in this building*/
    // std::vector<Person*> GetPeople() const;

private:
    /*Get the CrossRoads through which the building is accessed*/
    BuildingExitCrossroad* exitCrossRoad_;
    /*The maximum number of vehicles that fit inside the building*/
    unsigned int vehiclecapacity_;
    /*All vehicles currently in this building*/
    std::vector<Vehicle*> vehicles_;
    /*All people currently in this building*/
    // std::vector<Person*> people_;
};

#endif
