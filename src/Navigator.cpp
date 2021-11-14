#include "./include/Navigator.hpp"

#include <algorithm>


Navigator::Navigator(std::vector<RoadLineClass*> map):map_(map){ 
    std::vector<RoadLineClass*> v;
    route_ = v;
    }

void Navigator::MakeRoute(CrossroadClass& start, CrossroadClass& end) {
    //here an A* algorithm should override route_ with new vector of roads that a vehicle should take to make its way to the destination
};

  RoadLineClass* Navigator::FindNextRoad(CrossroadClass* currentCross)  {
    //returns a road from route_, which starts with given crossroad
    std::vector<RoadLineClass*>::iterator it = std::find_if(route_.begin(), route_.end(), [=] (RoadLineClass* r) {return r ->GetStart() == currentCross;});
    return *it;
};
