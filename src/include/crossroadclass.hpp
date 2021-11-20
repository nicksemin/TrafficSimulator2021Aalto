#ifndef CROSSROADCLASS_H
#define CROSSROADCLASS_H

#include <map>
#include <utility>
#include <vector>
#include <algorithm>

#include "roadobjectclass.hpp"

/*
 * =====================================================================================
 *        Class:  CrossroadClass
 *  Description:  The class acts as a moderator between the roads
 *  Consists of two containers
 *  1) <RoadObjectClass*, Vehicle*> for entry roads
 *  2) <RoadObjectClass*> for exit roads
 *  If there is currently no vehicle standing on the position of entry roads, then it is nullptr
 *
 *
 *  contact information - Alexey Serous
 * =====================================================================================
 */

class CrossroadClass : public RoadObjectClass
{
    public:
        CrossroadClass();

	bool takeVehicle( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject ) override;

	void performTimeStep() override;

	bool addEntryRoad ( const RoadObjectClass* ptrToEntryRoad );
	bool addExitRoad ( RoadObjectClass* ptrToExitRoad );


    protected:

        std::map<const RoadObjectClass*, Vehicle*> m_entryRoads;
	std::vector<RoadObjectClass*> m_exitRoads;

    private:
	
	//the main function of every particular crossroad type, defines if it is ok
	//for a car to go
	virtual bool checkRightToGo
		( const RoadObjectClass* ptrToEntry, RoadObjectClass* ptrToExit ) = 0;

	//coordinates
	int m_x;
	int m_y;

	//counter
	static std::size_t numOfCrossroads;
};

#endif // CROSSROADCLASS_H
