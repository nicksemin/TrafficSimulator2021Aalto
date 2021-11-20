#include "./include/roadlineclass.hpp"
#include <cmath>

/*-----------------------------------------------------------------------------
 * RoadLineClass, for the description see the header file
 * contact info - Alexey Serous
 *-----------------------------------------------------------------------------*/

std::size_t RoadLineClass::cellSize{ 5 };
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RoadLineClass::RoadLineClass
 *  Description:  The constructor, currently cannot define the size automatically
 * =====================================================================================
 */
RoadLineClass::RoadLineClass ( CrossroadClass* start, CrossroadClass* end ) :
	m_start{ start }, m_end{ end }
{
	//add the road to start and end crossroads
	start->addExitRoad( this );
	end->addEntryRoad( this );
	//add the end road being the only entry road for a building exit cross-road
	end->setOnlyEntryRoad( this );

	//define the size

	//make the cell vector to have required number of elements
	std::size_t size{ static_cast<std::size_t>(
			pow( pow( start->getX() - end->getX(), 2.00 ) + pow( start->getY() - end->getY(), 2.00 ), 0.50 ) ) / cellSize };
	m_cells.resize( size );

	//initially, there are no cars, so every cell is a nullptr
	for ( auto element : m_cells )
	{
		element = nullptr;
	}
}		/* -----  end of function RoadLineClass::RoadLineClass  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RoadLineClass::isEnoughSpace
 *  Description:  check if there is enough space for a desired car in the desired
 *  location
 * =====================================================================================
 */
	bool
RoadLineClass::isEnoughSpace ( std::size_t index, std::size_t size )
{
	bool valid{ true };

	for ( std::size_t i{ index }; i < size; ++i ){
		if ( m_cells.at( i ) != nullptr ) {
			valid = false;
		}
	}
	return valid;
}		/* -----  end of function RoadLineClass::isEnoughSpace  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RoadLineClass::takeVehicle
 *  Description:  takes a car and puts it to the begining of the road
 *  if the first cell (or needed number of cells based on the car's size)
 *  is occupied, then returns false and denies to accept the car.
 *  If there is space, then returns true
 * =====================================================================================
 */
	bool
RoadLineClass::takeVehicle ( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject )
{
	//if there is enough space, occupy all the required cells with the car
	if ( isEnoughSpace( 0, ptrToCar->GetSize() ) ) {
		for ( int i{ 0 }; i < ptrToCar->GetSize(); ++i ){
			m_cells.at( i ) = ptrToCar;
		}
		return true;
	}
	else {
		return false;
	}
}		/* -----  end of function RoadLineClass::takeVehicle  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  RoadLineClass::performTimeStep
 *  Description:  Starting from the end, moves all cars one cell up
 *  To be modified later after the crossroad class is defined
 * =====================================================================================
 */
	void
RoadLineClass::performTimeStep ()
{
	//if the last cell is occupied, try to send the car to a crossroad:
	if ( m_cells.at( m_cells.size() - 1 ) != nullptr ) {
		//if the road has a cross road, try to push a car:
		//if succeeded:
		if ( m_end->takeVehicle( m_cells.at( m_cells.size() - 1 ), this ) ){
			//delete all the cells that the end car occupies:
			int ii{ m_cells.at( m_cells.size() - 1 )->GetSize() };
			for ( std::size_t i{ 0 }; i < ii; ++i ){
				m_cells.at( m_cells.size() - 1 - i ) = nullptr;
			}
		}
	}

	//finally, starting from the last but one position, push all the cars forward
	//the loop is constructed to forbid unidentified behavior
	std::size_t i { m_cells.size() };
	while ( i > 1 ) {
		//if the next cell is empty, put there a car from the previous cell
		if ( m_cells.at( i - 1 ) == nullptr ) {
			m_cells.at( i - 1 ) = m_cells.at( i - 2 );
			m_cells.at( i - 2 ) = nullptr;
		}
		--i;
	}
}		/* -----  end of function RoadLineClass::performTimeStep  ----- */

RoadObjectClass* Vehicle::FindNextRoad(CrossroadClass* currentCross)  {
    //returns a road from route_, which starts with given crossroad
    std::vector<RoadLineClass*>::iterator it = std::find_if(route_.begin(), route_.end(), [=] (RoadLineClass* r) {return r->GetStart() == currentCross;});
    if ( it == route_.end() ) {
	    return destination_;
    }
    return *it;
};
