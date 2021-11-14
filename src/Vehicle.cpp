
#include "./include/Vehicle.hpp"

Vehicle::Vehicle(int size):size_(size) {
    std::vector<RoadLineClass*> r;
    route_ = r;
   }

const int& Vehicle::GetSize() const{
    return size_;
}

void Vehicle::setRoute( std::vector<RoadLineClass*> newRoute){
    route_ = newRoute;
}


