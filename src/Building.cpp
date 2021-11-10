#include "./include/Building.hpp"

#include <algorithm>

/*Constructor*/
Building::Building(CrossroadClass* exitCrossRoad, unsigned int vehiclecapacity) {
    exitCrossRoad_ = exitCrossRoad;
    vehiclecapacity_ = vehiclecapacity;
}

/*Destructor MIGHT NOT BE NEEDED*/
//Building::~Building(){
    // for(auto it : vehicles_) {
    //     delete it;
    // }
    // for(auto it : people_) {
    //     delete it;
    // }
//}

/*Take in a vehicle*/
bool Building::TakeVehicle (Vehicle* vehicle){
    if (vehicles_.size()<vehiclecapacity_){
        vehicles_.push_back(vehicle);
        return true;
    }
    return false;
}

/*Remove a vehicle*/
bool Building::RemoveVehicle (Vehicle* vehicle){
    auto it = std::find(vehicles_.begin(), vehicles_.end(), vehicle);
    if (it != vehicles_.end()) { 
        vehicles_.erase(it);
        return true;
    }
    return false;
}

// /*Take in a person*/
// void Building::TakePerson(Person* person){
//     people_.push_back(person);
// }

// /*Remove a person*/
// bool Building::RemovePerson(Person* person){
//     auto it = std::find(people_.begin(), people_.end(), person);
//     if (it != people_.end()) { 
//         people_.erase(it);
//         return true;
//     }
//     return false;
// }


/*Get the CrossRoads through which the building is accessed*/
CrossroadClass* Building::GetExit() const{
    return exitCrossRoad_;
}

/*Get all vehicles currently in this building*/
std::vector<Vehicle*> Building::GetVehicles() const{
    return vehicles_;
}

/*Get all people currently in this building*/
// std::vector<Person*> Building::GetPeople() const{
//     return people_;
// }