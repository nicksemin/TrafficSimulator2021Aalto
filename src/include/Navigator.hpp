#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include <vector>

#include "roadlineclass.hpp"

/* 
* Navigator class. Takes a map to be constructed.
* Has a method MakeRoute which creates a route from start crossroad to end crossroad.
* Contact info - Nikita
*/

class Navigator{
    public:
        Navigator(const std::vector<RoadLineClass*> roads_, const std::vector<CrossroadClass*> crossroads_);
        
        std::vector<RoadLineClass*>  MakeRoute(CrossroadClass& start, CrossroadClass& finish);
    private:
    std::vector<RoadLineClass*> roads_;
    std::vector<CrossroadClass*> crossroads_;
};

#endif