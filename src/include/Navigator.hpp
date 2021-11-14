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
        
        std::vector<RoadLineClass*>  MakeRoute(CrossroadClass& start, CrossroadClass& end);
    private:
    std::vector<RoadLineClass*> map_;
};

#endif