#include "./include/Simulation.hpp"
#include <stdlib.h>

Simulation::Simulation(CityClass* city, unsigned int npeople, unsigned int starttime, unsigned int endtime){ //outputfile
    city_ = city;
    npeople_ = npeople;
    starttime_ = starttime;
    endtime_ = endtime;
}


/*
* void Simulation::Init() initializes npeople number of people in random location in given city.
*/

void Simulation::Init(){
    std::vector<std::pair<std::string,Building*>>  allCityBuildings = city_ -> GetBuildings();

    int peopleToSettle = npeople_;
    while (peopleToSettle > 0) {
        int randomBuildingIndex = rand() % allCityBuildings.size();
        int carSize =  rand() % 5 + 1;
        bool fitting = allCityBuildings[randomBuildingIndex].second->takeVehicle(new Car(carSize), nullptr); 
        if (fitting)  allCityBuildings[randomBuildingIndex].second->TakePerson(new Person()); {
             peopleToSettle --;
        }
    }
}

void Simulate(){
    // time =starttime;

    //     while(time<endtime){
            
    //         -call performTimestep for CityClassmembers
    //         -call performTimeStep for People (give "time" as a parameter)

    //         -write curent traffic situation to outputfile

    //         time += tick;
    //     }

}
