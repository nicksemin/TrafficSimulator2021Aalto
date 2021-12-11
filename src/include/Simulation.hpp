
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "cityclass.hpp"
#include "Vehicle.hpp"
#include "Person.hpp"

#include <stdlib.h>

class Simulation : public QObject{

    Q_OBJECT
 signals:
   void sendStatus(double);

public:

    Simulation(CityClass* city, unsigned int npeople, double endtime, std::string outputfile, std::string RoadToAnalyze); //outputfile

    void Init();

    double progressStatus;

    void Simulate();

private:
    std::vector<Person*> people_;
    CityClass* city_;
    unsigned int npeople_;
    double endtime_;
    std::string outputfile_;
    std::string RoadToAnalyze_;
};


#endif