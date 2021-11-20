#ifndef ROADOBJECTCLASS_H
#define ROADOBJECTCLASS_H

#include "Vehicle.hpp"


/*
 * =====================================================================================
 *        Class:  RoadObjectClass
 *  Description:  An interface to be inherited by the RoadLineClass and CrossroadClass
 *  contact information - Alexey Serous
 * =====================================================================================
 */

class RoadObjectClass
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		RoadObjectClass ();                             /* constructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		virtual bool takeVehicle( Vehicle* ptrToCar, const RoadObjectClass* ptrToRoadObject ) = 0;

		virtual void performTimeStep() = 0;

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class RoadObjectClass  ----- */

#endif // ROADOBJECTCLASS_H
