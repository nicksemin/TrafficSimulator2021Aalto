#include "./include/Navigator.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <limits>   
#include <iostream>   
#include <math.h>
#include <functional>
#include <queue>

Navigator::Navigator(std::vector<RoadLineClass*> roads, std::vector<CrossroadClass*> crossroads):roads_(roads), crossroads_(crossroads){ }


// # A PRIVATE HELPER FUNCTION: Find the possible successors of given state, that is, the allowed (on-route) locations 
// # that are one step away from given location.
// # Return the location with corresponding direction
std::vector<std::pair<CrossroadClass*,RoadLineClass*>> Navigator::successors(CrossroadClass* crossroad){
    std::vector<std::pair<CrossroadClass*,RoadLineClass*>> result;
    for (auto road : roads_){
        if(road->GetStart()==crossroad){
            result.push_back(std::make_pair(road->GetEnd(),road));
            // // find the corresponding backward road
            // CrossroadClass* end = road->GetEnd();
            // for (auto backroad : roads_){
            //     if(backroad->GetStart()==end && backroad->GetEnd()==crossroad){
            //         result.push_back(std::make_pair(end,backroad));
            //     }
            // }
            
        }
    
    }
    return result;
}


std::vector<RoadLineClass*> Navigator::MakeRoute(CrossroadClass* start, CrossroadClass* finish) {    
    std::cout<<"Calling makeroute for navigator to go from: "<<start<< " to " <<finish <<std::endl;

    std::vector<RoadLineClass*> actions;

    if(start==finish){
        std::cout<<"start is equal to finish"<<std::endl;
        return actions;
    }
    // # A dictionary to keep up with predecessors of each expanded state and the action that 
    // # took us there
    std::map<CrossroadClass*,std::pair<RoadLineClass*,CrossroadClass*>> predecessors;
    //predecessors = {} # dict(tuple(x,y) --> tuple(action,predecessors))

    // # A dictionary to keep up with the length of the shortest route found to given location 
    // # (so far)
    std::map<CrossroadClass*,double> pathlength;
    

    // # A priority queue to guide the search. Priority of each entry (search node) is the 
    // # estimated distance to a goal state as returned by est_dist
    //auto cmp = [](CrossroadClass* crossroad) { return 1/(pathlength[crossroad] + sqrt(1.0*pow((crossroad->getX()-finish->getX()),2)+1.0*pow((crossroad->getY()-finish->getY()),2))); };
    //auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<std::pair<double,CrossroadClass*>> Q;

    // # Variables to keep up with the best path to goal state found
    double bestpath_length = std::numeric_limits<double>::max();
    //bestpath_end = None # the location (x,y) in the finishing area


// ##################################### Begin search #####################################

    // # Put start state in queue
    Q.push(std::make_pair(0.0,start));

    // # and in pathlength- and predecessors-dictionaries
    pathlength[start] = 0.0;
    predecessors[start] = std::make_pair(nullptr,nullptr);

    // # While the queue is non-empty do:
    while (not Q.empty()){
        // std::cout<<"In while loop, queue length: "<<Q.size()<<std::endl;
        // # Take out the search node with the highest priority = lowest estimated distance
        std::pair<double,CrossroadClass*> currpair = Q.top();
        Q.pop();
        // std::cout<<"Here1"<<std::endl;
        CrossroadClass* curr = currpair.second;
        double est_dist = currpair.first;//pathlength[curr] + sqrt(1.0*pow((curr->getX()-finish->getX()),2)+1.0*pow((curr->getY()-finish->getY()),2));
        // std::cout<<"Here2"<<std::endl;
        // # Only if the estimated distance (lower bound) is shorter than the current best 
        // # path to goal state do:
        if (est_dist < bestpath_length){
            // std::cout<<"Here3"<<std::endl;
            // std::cout<<"Entering for-loop, successors length: "<<successors(curr).size()<<std::endl;
            // # go through all the possible successor-locations
            for (auto [succ,act] : successors(curr)){
                // std::cout<<"In for loop, successors length: "<<successors(curr).size()<<std::endl;
                // # if the location has not yet been expanded, or this new path is shorter 
                // # than the one found previously
                bool first = (not pathlength.count(succ));
                bool second = ((pathlength[curr]+ act->GetSize()*5) < pathlength[succ]); //times 5 to mach with the coordinates
                // std::cout<<"This is the combination: "<< (first || second) <<std::endl;
                if ((first || second)){
                    //# update pathlength and predecessors
                    pathlength[succ]=pathlength[curr]+act->GetSize()*5; //times 5 to mach with the coordinates
                    // std::cout<<"This is the curr: "<<curr<<std::endl;
                    predecessors[succ] = std::make_pair(act,curr);
                    // # if the location is not a goal location, add it in queue    
                    if (not (succ==finish)){
                        Q.push(std::make_pair((1/(pathlength[succ] + sqrt(1.0*pow((succ->getX()-finish->getX()),2)+1.0*pow((succ->getY()-finish->getY()),2)))),succ));
                    }
                    // # and if it is a goal location, see if it's better than the previous 
                    // # best and update when needed
                    else if (pathlength[succ]<bestpath_length){
                        bestpath_length = pathlength[succ];
                    }
                }
            }
        }
    }
    // std::cout<<"Exited while"<<std::endl;
    // # Recursively follow the predecessors to reconstruct the solution
    

    // # Start from the goal
    CrossroadClass* currstate = finish;
    
    // # Move backwards until reaching start-state
    while (currstate != start && currstate != nullptr){
        // std::cout<<"In backward while with currstate: "<<currstate<<std::endl;
        //std::cout<<"In backward while loop"<<std::endl;
        std::pair<RoadLineClass*,CrossroadClass*> predecessor = predecessors[currstate];
        // # collect actions
        actions.insert(actions.begin(),predecessor.first);
        currstate = predecessor.second;
        if (currstate==nullptr){
            //std::cout<<"currstate is nullptr"<<std::endl;
            //break;
        }
    }
    //std::cout<<"Exited backward while"<<std::endl;
    // std::cout << "PATH:" << std::endl;

    // for (RoadLineClass* action : actions){
    //     std::cout << "----ROAD START------" << std::endl;
    //     std::cout << "Start crossroad:" << action->GetStart() << std::endl;
    //     std::cout << "End crossroad:" << action->GetEnd()<< std::endl;
    //     //std::cout << "Road:" << action<< std::endl;
    //     std::cout << "----ROAD END------" << std::endl;
    // }
    //actions.erase(actions.begin());
    return actions;
}
