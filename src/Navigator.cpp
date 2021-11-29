#include "./include/Navigator.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <limits>   
#include <iostream>   


Navigator::Navigator(std::vector<RoadLineClass*> roads, std::vector<CrossroadClass*> crossroads):roads_(roads), crossroads_(crossroads){ }

struct Distance{
        CrossroadClass* crossroad;
        int distance;
        CrossroadClass* parent;
    };

Distance findMinDistance(std::vector<Distance> distances){
     Distance min = distances.front();

for (std::vector<Distance>::iterator it = distances.begin(); it!= distances.end();){
        if (it -> distance < min.distance) min = *it;
        it++;
    }
    return min;
}

std::vector<std::pair<Distance, int>> FindAdjacentNodes(Distance currentDistance, std::vector<Distance> distances,  std::vector<RoadLineClass*> roads){

    std::vector<std::pair<Distance, int>> result;


     for (std::vector<RoadLineClass*>::iterator it = roads.begin(); it!= roads.end();){
         RoadLineClass* r = *it;
         size_t s = r->GetSize();
         if (r->GetStart() == currentDistance.crossroad){
             std::vector<Distance>::iterator d = find_if(distances.begin(), distances.end(),[&r] (const Distance& d) {return d.crossroad == r->GetEnd();} );
             Distance dd = *d;
             std::pair<Distance, int> pair = std::make_pair(*d, r->GetSize());
             std::cout << "road size :;;;;; "<< r->GetSize() << std::endl;
             result.push_back(pair);
         }
         it++;
      }
      return result;
}

std::vector<RoadLineClass*> Navigator::MakeRoute(CrossroadClass& start, CrossroadClass& finish) {
    //TODO: Implement pathfinding based on Dijkstra algorithm
    /*
     node = crossroads, roads = links
     map is a graph: std::vector<RoadLineClass*> map, every RoadLineClass has start and end crossroads
     from every crossroad it's possible to get to a road for which this crossroad is start crossroad
     start

    adjacent crossroad to source crossroad s: end crossroads of roads, for which s is start crossroad
    

    The implementation plan:
    I. Create Shortest Path Tree

    1) create spt vector = empty

    2) Initialize distance variables to all crossroads, set to infinite
        possible structure: std::tuple<&CrossroadClass, int (distance), &CrossroadClass(parent)> tpl;
        distance to sourse is 0 so it's picked first

    3) while sptSet doesn't have all crossroads:
         from pickup a crossroad with minimum distance which is not in sptSet
         include it to sptSet
         Update distances to adjustant crossroads:
            iterate through crossroads c:
                if distance s -c is less than current distance value, update it with road size and itself as a parent
    
    II. Find a path: in sptSet, find destination, and go up by parent
    */

    std::vector<Distance> spt; //shortest path tree

    std::vector<Distance> distances; 

   int infinity = std::numeric_limits<int>::max();

    for (std::vector<CrossroadClass*>::iterator it = crossroads_.begin(); it!= crossroads_.end();){
            if (**it == start) {
                Distance dist = {*it, 0, nullptr};
                distances.push_back(dist);
            }
            else {
            Distance dist = {*it, infinity, nullptr};
            distances.push_back(dist);
            }
            it++;
    }


     int count = distances.size();
          
    
    while (count != 0) {
        Distance current = findMinDistance(distances);
        spt.push_back(current);

        //1. find adjacent nodes: search in map roads that start with current crossroad, then collect crossroads where those roads end
        //2. find their distance in distances. if it's bigger than size of the road connecting current crossroad and adjustent node, update it and parent

        std::vector<std::pair<Distance, int>> adjustent_nodes = FindAdjacentNodes(current, distances, roads_); // adjacent Distance struct, distance to it from the current node 
        for (std::vector<std::pair<Distance, int>>::iterator it4 = adjustent_nodes.begin(); it4!= adjustent_nodes.end();){

        std::pair<Distance, int> r = *it4;
        it4++;
    }
        for ( std::vector<std::pair<Distance, int>>::iterator it1 = adjustent_nodes.begin(); it1!= adjustent_nodes.end();){
           int distanceViaCurrentNode = current.distance + it1->second;
           if (it1->first.distance > distanceViaCurrentNode){
               auto it2 = find_if(distances.begin(), distances.end(), [=] (const Distance& d) {return d.crossroad == current.crossroad;});
               auto index = std::distance(distances.begin(), it2);
               Distance newD = {it1->first.crossroad, distanceViaCurrentNode, current.crossroad};
               distances[index] =newD;
           }
         
           it1++;
        }   
        count--;  
    }

    Distance d2 = spt[2];

    Distance d0 = spt[0];

    for ( std::vector<Distance>::iterator it = spt.begin(); it!= spt.end();){
        Distance d = *it;      
        it++;
    }

    std::vector<Distance>::iterator it = std::find_if(spt.begin(), spt.end(), [&finish] (const Distance d) {return *d.crossroad == finish;});
    Distance currentDist= (*it);

    std::cout << "calculating path.." << std::endl;

    std::vector<RoadLineClass*> result;

    while (currentDist.crossroad != &start){
        std::vector<RoadLineClass*>::iterator r = std::find_if(roads_.begin(), roads_.end(), [=](const RoadLineClass* r) {return r->GetStart() == currentDist.parent;});
        result.push_back(*r);
        std::vector<Distance>::iterator d_it = std::find_if(spt.begin(), spt.end(), [=] (const Distance d) {return d.crossroad == currentDist.parent;});
        currentDist = *d_it;
    }

    std::cout << "printlng shortest path tree:" << std::endl;
    for ( std::vector<Distance>::iterator it = spt.begin(); it!= spt.end();){
        Distance d = *it;
        std::cout << "Crossroad: " << *(d.crossroad) <<std::endl;
        std::cout << "Distance: " << (d.distance) <<std::endl;
       
        it++;
    }

     std::cout << "PATH:" << std::endl;

      for ( std::vector<RoadLineClass*>::iterator it = result.begin(); it!= result.end();){
        RoadLineClass* r= *it;
        std::cout << "----ROAD START------" << std::endl;
        std::cout << "Start crossroad:" << *((*r).GetStart()) << std::endl;
        std::cout << "End crossroad:" << *((*r).GetEnd()) << std::endl;
        std::cout << "----ROAD END------" << std::endl;
        it++;
    }

    return result;
};
