#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include <vector>

#include "roadlineclass.hpp"

/* 
* Navigator class. Can be embedded into a vehicle.
*/

class Navigator{
    public:
        Navigator(std::vector<RoadLineClass*> map);
        
        void MakeRoute(CrossroadClass& start, CrossroadClass& end);
        const RoadLineClass* FindNextRoad(CrossroadClass& currentCross) const;
    private:
        std::vector<RoadLineClass*> route_ = {};
        std::vector<RoadLineClass*> map_;  
};

#endif