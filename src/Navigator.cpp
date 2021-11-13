#include "./include/Navigator.hpp"

Navigator::Navigator(std::vector<RoadLineClass*> map):map_(map){    }

void Navigator::MakeRoute(CrossroadClass& start, CrossroadClass& end) {
    //A* algorithm overrides route_
};

 const RoadLineClass* Navigator::FindNextRoad(CrossroadClass& currentCross) const {
     // implement: find road in route_ that begins with currentCross
    return route_.front();
};
