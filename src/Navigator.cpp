#include "./include/Navigator.hpp"

#include <algorithm>


Navigator::Navigator(std::vector<RoadLineClass*> map):map_(map){ }

std::vector<RoadLineClass*>  Navigator::MakeRoute(CrossroadClass& start, CrossroadClass& end) {
    //TODO: Implement pathfinding based on A* algorithm
    std::vector<RoadLineClass*> v;
    return v;
};
