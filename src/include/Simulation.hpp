
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "cityclass.hpp"
#include "Vehicle.hpp"
#include "Person.hpp"

class Simulation{

public:

    Simulation(CityClass* city, unsigned int npeople, unsigned int starttime, unsigned int endtime); //outputfile

    void Init();

    void Simulate();

private:
    CityClass* city_;
    unsigned int npeople_;
    unsigned int starttime_;
    unsigned int endtime_;
};


#endif