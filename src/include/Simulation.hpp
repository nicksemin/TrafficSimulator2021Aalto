
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "cityclass.hpp"
#include "Vehicle.hpp"
#include "Person.hpp"

#include <stdlib.h>

/*A class to enable the simulation flow. First initializes the simulation by creating random people and placing them in building. Then runs
a loop over a user specified range of time, advancing time of the objects
in the city, and produces output*/
class Simulation{

public:

    /*Constructor: takes as input the Inrastructure of the city to be simulated (a pointer to a CityClass-object),
    the user specified number of city residents, maximum simulation time, output filename and a user specified 
    roadname to analyze.*/
    Simulation(CityClass* city, unsigned int npeople, double endtime, std::string outputfile, std::string RoadToAnalyze); //outputfile

    /*Initializes the city with it's residents: Creates npeople new people, assigns their to their respective buildings and vehicles.*/
    void Init();
    
    /*Starts the simulation: runs a for loop over endtime*8000 simulation ticks, produces hourly output and writes it in to
    the outputfile. Prints more advanced details of the RoadToAnalyze into cout*/
    void Simulate();

private:
    /*People of the city*/
    std::vector<Person*> people_;
    /*Pointer to the CityClass object that contains the infrastructure of the city*/
    CityClass* city_;
    /*Number of people in the simulation*/
    unsigned int npeople_;
    /*Endtime of simulation in hours = the hours simulated*/
    double endtime_;
    /*Output filename*/
    std::string outputfile_;
    /*Name of the road to be analyzed more specifically*/
    std::string RoadToAnalyze_;
};


#endif