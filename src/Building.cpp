#include "./include/Building.hpp"

#include <algorithm>
#include <string>

/*-----------------------------------------------------------------------------
 * For the changes made by Alexey's merge request see the header file
 *-----------------------------------------------------------------------------*/

/*Constructor*/
Building::Building(  BuildingExitCrossroad* exitCrossRoad, unsigned int vehiclecapacity, const std::string& type ) {
    if ( exitCrossRoad->addExitRoad( this ) && exitCrossRoad->addEntryRoad( this ) ) {
	    exitCrossRoad_ = exitCrossRoad;
    }
    vehiclecapacity_ = vehiclecapacity;
    id_ = ++nextID;
    type_ = type;
}

unsigned int Building::nextID = 0;


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
bool Building::takeVehicle( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject ){
    if (vehicles_.size() < vehiclecapacity_){
        vehicles_.push_back( ptrToCar );
        return true;
    }
    return false;
}

/*Remove a vehicle*/
bool Building::RemoveVehicle (Vehicle* vehicle){
    auto it = std::find(vehicles_.begin(), vehicles_.end(), vehicle);
    if (it != vehicles_.end()) { 
    //send the vehicle to the crossroad and erase it only if the crossroad accepts it
	if ( exitCrossRoad_->takeVehicle( *it, this ) ) {
		vehicles_.erase(it);
		return true;
	}
    }
    return false;
}

// /*Take in a person*/
void Building::TakePerson(Person* person){
    people_.push_back(person);
 }

// /*Remove a person*/

bool Building::RemovePerson(Person* person){
    auto it = std::find(people_.begin(), people_.end(), person);
    if (it != people_.end()) {
        vehicles_[0]->takePassenger(person);
        vehicles_[0]->setDestination(person->get_destination());
        people_.erase(it);
        this->RemoveVehicle(vehicles_[0]);
        person->set_current_place(nullptr);
        return true;
    }
    return false;
}

unsigned int Building::GetID() const{
    return id_;
}

const std::string& Building::GetType() const{
    return type_;
}

/*Get the CrossRoads through which the building is accessed*/
BuildingExitCrossroad* Building::GetExit() const{
    return exitCrossRoad_;
}

/*Get all vehicles currently in this building*/
std::vector<Vehicle*> Building::GetVehicles() const{
    return vehicles_;
}

/*Get all people currently in this building*/
 std::vector<Person*> Building::GetPeople() const{
    return people_;
 }

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:    performTimestep
 *  Description:    Implemented for each building type (subclass) separately, according to
 *                  what is supposed to happen to people in that specific type of building
 * =====================================================================================
 */

void RecreationalBuilding::performTimeStep(){
     for(auto person : people_) {
         person->increase_happiness(20);
         person->remove_money(10);
     }
}

void ResidentialBuilding::performTimeStep(){
     for(auto person : people_) {
         person->increase_happiness(10);
         person->eat_food(1);
     }
}

void IndustrialBuilding::performTimeStep(){
    for(auto person : people_) {
         person->decrease_happiness(15);
         person->add_money(30);
     }
}

void CommercialBuilding::performTimeStep(){
     for(auto person : people_) {
         person->add_food(5);
         person->remove_money(5);
     }
}