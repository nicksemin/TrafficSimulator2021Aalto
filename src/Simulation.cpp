#include "./include/Simulation.hpp"

Simulation::Simulation(CityClass* city, unsigned int npeople, unsigned int starttime, unsigned int endtime){ //outputfile
    city_ = city;
    npeople_ = npeople;
    starttime_ = starttime;
    endtime_ = endtime;
}

void Init(){
    // TO DO AT LEAST:
    //  -create random people 
    // -create the same amount of vehicles
    
    // -assign people homes
    // -assign people and their vehicles initial locations
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
