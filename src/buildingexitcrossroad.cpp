#include "./include/buildingexitcrossroad.hpp"

/*-----------------------------------------------------------------------------
 * For the description see the header file 
 *-----------------------------------------------------------------------------*/

BuildingExitCrossroad::BuildingExitCrossroad( int x, int y, size_t id ) :
	CrossroadClass( x, y, id )
{
    //ctor
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BuildingExitCrossroad::checkRightToGo
 *  Description:  The entry road has the priority, cars coming out of buildings have
 *  to wait.
 * =====================================================================================
 */
	bool
BuildingExitCrossroad::checkRightToGo ( const RoadObjectClass* ptrToEntry, RoadObjectClass* ptrToExit )
{
	//if a car comes from the entry road, it is allowed to go
	if ( ptrToEntry == m_onlyEntryRoad ) {
		return true;
	}
	//else, we need to check if there is a car in the entry road
	return !( m_entryRoads[ m_onlyEntryRoad ] );
}		/* -----  end of function BuildingExitCrossroad::checkRightToGo  ----- */
