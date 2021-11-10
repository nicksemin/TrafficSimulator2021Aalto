#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Vehicle.hpp"
#include "roadlineclass.hpp"
// #include "Person.hpp"
// #include "Crossroad.hpp" REPLACED BY ALEXEYs TEMPORARY CrossroadClass FOR NOW

#include <string>
#include <vector>

class Building{
public:
    /*Constructor*/
    Building(CrossroadClass* exitCrossRoad, unsigned int vehiclecapacity); //name?

    /*Destructor MIGHT NOT BE NEEDED*/
    //~Building();

    /*Take in a vehicle*/
    bool TakeVehicle (Vehicle* vehicle);

    /*Remove a vehicle*/
    bool RemoveVehicle (Vehicle* vehicle);

    // /*Take in a person*/
    // void TakePerson(Person* person);

    // /*Remove a person*/
    // bool RemovePerson(Person* person);

    /*Get the CrossRoads through which the building is accessed*/
    CrossroadClass* GetExit() const;

    /*Get all vehicles currently in this building*/
    std::vector<Vehicle*> GetVehicles() const;

    /*Get all people currently in this building*/
    // std::vector<Person*> GetPeople() const;

private:
    /*Get the CrossRoads through which the building is accessed*/
    CrossroadClass* exitCrossRoad_;
    /*The maximum number of vehicles that fit inside the building*/
    unsigned int vehiclecapacity_;
    /*All vehicles currently in this building*/
    std::vector<Vehicle*> vehicles_;
    /*All people currently in this building*/
    // std::vector<Person*> people_;
};

#endif