
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Vehicle::getDestination
 *  Description:  added by Alexey, returns the destination building
 * =====================================================================================
 */
RoadObjectClass* Vehicle::getDestination ()
{
	return destination_;
}
/* -----  end of function Vehicle::getDestination  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Vehicle::setDestination
 *  Description:  added by Alexey, sets the destination
 * =====================================================================================
 */
void Vehicle::setDestination ( RoadObjectClass* ptrToBuilding )
{
	destination_ = ptrToBuilding;
}
/* -----  end of function Vehicle::setDestination  ----- */
