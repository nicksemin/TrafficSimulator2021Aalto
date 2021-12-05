#ifndef ROADOBJECTCLASS_H
#define ROADOBJECTCLASS_H

#include "Vehicle.hpp"
#include <iostream>

const double PI{ 3.14 };
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
		RoadObjectClass ( bool hasTriangle = false );                             /* constructor */

		/* ====================  ACCESSORS     ======================================= */
		bool hasTriangle() const;

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
		bool m_hasTriangle;

}; /* -----  end of class RoadObjectClass  ----- */

#endif // ROADOBJECTCLASS_H
