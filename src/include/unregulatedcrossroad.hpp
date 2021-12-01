#ifndef UNREGULATEDCROSSROAD_HPP
#define UNREGULATEDCROSSROAD_HPP

#include "crossroadclass.hpp"

/*-----------------------------------------------------------------------------
 *  A crossroad that has no traffic lights and uses the right hand rule to
 *  decide the priority.
 *  Contact info - Alexey
 *-----------------------------------------------------------------------------*/

class UnregulatedCrossroad : public CrossroadClass
{
    public:
        UnregulatedCrossroad( int x, int y );

    protected:

    private:

	bool checkRightToGo
		( const RoadObjectClass* ptrToEntry, RoadObjectClass* ptrToExit ) override;
};

#endif // UNREGULATEDCROSSROAD_
