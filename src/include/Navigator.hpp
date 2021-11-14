#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include <vector>

#include "roadlineclass.hpp"

/* 
* Navigator class.
*/

class Navigator{
    public:
        Navigator(const std::vector<RoadLineClass*> map);
        
        void MakeRoute(CrossroadClass& start, CrossroadClass& end);
        RoadLineClass* FindNextRoad(CrossroadClass* currentCross) ;
    private:
    std::vector<RoadLineClass*> route_;
    std::vector<RoadLineClass*> map_; 
};

#endif