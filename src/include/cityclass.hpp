#ifndef CITYCLASS_HPP
#define CITYCLASS_HPP

/*-----------------------------------------------------------------------------
 *  A class that represents a city with roads, crossroads, buildings, etc.
 *  Contact info - Alexey
 *-----------------------------------------------------------------------------*/

//global include
#include <fstream>
#include <iostream>
#include <sstream>
//local inlude
#include "./include/buildingexitcrossroad.hpp"
#include "./include/unregulatedcrossroad.hpp"
#include "./include/Vehicle.hpp"
#include "./include/roadlineclass.hpp"
#include "./include/Car.hpp"
#include "./include/Navigator.hpp"
#include "./include/Building.hpp"

class CityClass
{
    public:
        CityClass(std::string fileName);
        std::vector<std::pair<std::string,Building*>> GetBuildings() const;

    protected:

    private:
        std::string m_fileName;
	std::map<std::string, CrossroadClass*> m_crossroads;
	std::map<std::string, RoadLineClass*> m_roads;
    std::vector<std::pair<std::string,Building*>> m_buildings;
};

#endif // CITYCLASS_
