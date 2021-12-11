#include "./include/Building.hpp"

#include <algorithm>
#include <string>

/*-----------------------------------------------------------------------------
 * For the changes made by Alexey's merge request see the header file
 *-----------------------------------------------------------------------------*/

/*Constructor*/
Building::Building(  CrossroadClass* exitCrossRoad, unsigned int vehiclecapacity, const std::string& type ) {
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
        for(auto person : ptrToCar->getPassengers()) {
            this->TakePerson(person);
            ptrToCar->removePassenger(person);
        }
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
		++BuildingExitCrossroad::carsLeftHome;
		return true;
	}
    }
    return false;
}

// /*Take in a person*/
void Building::TakePerson(Person* person){
    people_.push_back(person);
    person->set_current_place(this);
    person->reset_destination();
 }

// /*Remove a person*/

bool Building::RemovePerson(Person* person){
    auto it = std::find(this->people_.begin(), this->people_.end(), person);
    if (it != people_.end()) {
        Navigator* n = person->getNavigator();

        Building* start = person->get_current_place();

        Building* end = person->get_destination();
        if ( !start || !end ) {
            throw BuildingRemovePersonException( this, person );
        }
        CrossroadClass* startCr = start -> GetExit();

        CrossroadClass* endCr = end -> GetExit();
        if ( !startCr || !endCr ) {
            throw BuildingRemovePersonException( this, person );
        }

        std::vector<RoadLineClass*> route = n->MakeRoute(startCr, endCr);



        vehicles_[0]->takePassenger(person);
        vehicles_[0]->setRoute(route);
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

unsigned int Building::GetVehicleCapacity() const{
    return vehiclecapacity_;
}

const std::string& Building::GetType() const{
    return type_;
}

/*Get the CrossRoads through which the building is accessed*/
CrossroadClass* Building::GetExit() const{
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

void Person::set_destination(unsigned int tickTime){

    if(current_place_ == nullptr){ // Means a person is on the road, can't change their mind
        return;
    }
    if(tickTime % 192000 == time_leaving_){ // ELSE if they are in any other building, but it's their time to go to work, they will do it no matter what
        destination_ = work_;
        current_place_->RemovePerson(this);
        return;
    }
    if((tickTime % 192000 == time_coming_) || (current_place_ != work_) ){ // if they are not at work or it's their time to leave work, they may go according to their needs.
        if(this->is_hungry() && (this->get_food() <= 0 && this->get_money()>5)){ // => if they are hungry, have no food but have enough money, they WILL go shopping
            // check if they are already there and set only if needed
            if(current_place_ != fav_commercial_){
                destination_ = fav_commercial_;
                current_place_->RemovePerson(this);
                return;
            }else{ // IF they are, they just stay
                return;
            }
        }
        if( !(this->is_happy()) && this->get_money()>10){ // => else, if they are unhappy, and have enough of money, they WILL go to recreational
            // check if they are already there and set only if needed
            if(current_place_ != fav_recreational_){
                destination_ = fav_recreational_;
                current_place_->RemovePerson(this);
                return;
            }else{ // IF they are, they just stay
                return;
            }
        }
        if(current_place_ != home_){  // => and finally, if they have no needs to be filled and are not yet at home, they just go home, or stay home
            destination_ = home_;
            current_place_->RemovePerson(this);
            return;
        }else{ // IF they are, they just stay
            return;
        }
    }
    // if we come here, it means they are at work, and their time to leave has not come, so they will stay at work
    return;
}

void Person::performTimeStep(unsigned int tickTime){
    this->set_destination(tickTime);
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
         person->increase_hunger(1);
     }
}

void ResidentialBuilding::performTimeStep(){
     for(auto person : people_) {
         person->increase_happiness(10);
         person->eat_food(1);
         person->increase_hunger(1);
     }
}

void IndustrialBuilding::performTimeStep(){
    for(auto person : people_) {
         person->decrease_happiness(15);
         person->add_money(30);
         person->increase_hunger(1);
     }
}

void CommercialBuilding::performTimeStep(){
     for(auto person : people_) {
        person->add_food(5);
        person->remove_money(5);
        person->increase_hunger(1);
     }
}
