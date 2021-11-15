#ifndef ROADLINECLASS_H
#define ROADLINECLASS_H

#include <vector>

#include "Vehicle.hpp"

/*-----------------------------------------------------------------------------
 * RoadLineClass
 * Alexey Serous
 * One line of a road, a piece between two crossroads
 * In case there is no crossroad (e.g. a road starts), then it is nullptr
 *
 * The road is divided in cells (total number of m_size)
 * Every cell contains a pointer to a car. If the cell is currently empty,
 * then the value is nullptr
 *
 * When moved by a timestep, every car starting from the end is moved
 * one cell to the next one towards the end. If a cell is occupied (e.g. the
 * end cross road is busy, red-traffic light), no movement is performed.
 * The end car is gived to the end cross-road as a start of the moving function
 *-----------------------------------------------------------------------------*/

//for abstract purposes, to be deleted after the real class is implemented

class CrossroadClass{
	public:
		bool takeVehicle( const Vehicle* ptrToVehicle )
		{
		return true;
		}
};

class RoadLineClass
{
    public:
        RoadLineClass( std::size_t size, CrossroadClass* start, CrossroadClass* end );

	bool takeVehicle( const Vehicle* ptrToCar );

	void moveCars();

	const CrossroadClass* GetStart() const {
		return m_start;
	}

    protected:

    private:
	bool isEnoughSpace( std::size_t index, std::size_t size );

	std::size_t m_size;

	std::vector<const Vehicle*> m_cells;

	CrossroadClass* m_start;
	CrossroadClass* m_end;

};

#endif // ROADLINECLASS_H
