#include "./include/Building.hpp"

#include <algorithm>

/*-----------------------------------------------------------------------------
 * For the changes made by Alexey's merge request see the header file
 *-----------------------------------------------------------------------------*/

/*Constructor*/
Building::Building(  BuildingExitCrossroad* exitCrossRoad, unsigned int vehiclecapacity ) {
    if ( exitCrossRoad->addExitRoad( this ) && exitCrossRoad->addEntryRoad( this ) ) {
	    exitCrossRoad_ = exitCrossRoad;
    }
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
bool Building::takeVehicle( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject ){
    if (vehicles_.size()<vehiclecapacity_){
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
BuildingExitCrossroad* Building::GetExit() const{
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Building::performTimeStep
 *  Description:  
 * =====================================================================================
 */
	void
Building::performTimeStep ()
{
}		/* -----  end of function Building::performTimeStep  ----- */
