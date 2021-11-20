#include "./include/crossroadclass.hpp"


/*-----------------------------------------------------------------------------
 * For the description, see the include file
 * contact info - Alexey Serous 
 *-----------------------------------------------------------------------------*/

std::size_t CrossroadClass::numOfCrossroads{ 0 };

CrossroadClass::CrossroadClass()
{
    //ctor
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  takeVehicle
 *  Description:  takes a Vehicle* from an entry road, checks if there is space
 *  and decides whether to accept it. A Building may use nullptr for RoadObjectClass*
 *  argument
 * =====================================================================================
 */
	bool
CrossroadClass::takeVehicle ( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject )
{
	if ( m_entryRoads[ ptrToRoadObject ] == nullptr ) {
		m_entryRoads[ ptrToRoadObject ] = ptrToCar;
		return true;
	}
	else {
		return false;
	}
}		/* -----  end of function takeVehicle  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CrossroadClass::performTimeStep
 *  Description:  
 * =====================================================================================
 */
	void
CrossroadClass::performTimeStep ()
{
	//check what cars have the right to go
	std::map<const RoadObjectClass*, bool> hasRightToGo{};
	for ( const auto& element : m_entryRoads ){
		//but only if there is a car standing
		if ( element.second ) {
			hasRightToGo[ element.first ] = checkRightToGo( element.first, element.second->FindNextRoad( this ) );
		}
	}
	
	//for every car that has the right to go
	for ( auto& element : m_entryRoads ){
		//if there is a car... 
		if ( element.second ) {
			//... and it is allowed to go + the exit road accepts it
			if ( hasRightToGo[ element.first ] && element.second->FindNextRoad( this )->takeVehicle( element.second, this ) ) {
				element.second = nullptr;
			}
		}
	}
}		/* -----  end of function CrossroadClass::performTimeStep  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CrossroadClass::addEntryRoad
 *  Description:  does what is specified by the name, returns true if succeeded
 * =====================================================================================
 */
	bool
CrossroadClass::addEntryRoad ( const RoadObjectClass* ptrToEntryRoad )
{
	//add an entry road with no car currently
	//m_entryRoads.insert( std::make_pair( ptrToEntryRoad, nullptr ) );
	m_entryRoads[ ptrToEntryRoad ] = nullptr;
	return true;
}		/* -----  end of function CrossroadClass::addEntryRoad  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CrossroadClass::addExitRoad
 *  Description:  does what is described in the name
 * =====================================================================================
 */
	bool
CrossroadClass::addExitRoad ( RoadObjectClass* ptrToExitRoad )
{
	m_exitRoads.push_back( ptrToExitRoad );
	return true;
}		/* -----  end of function CrossroadClass::addExitRoad  ----- */
