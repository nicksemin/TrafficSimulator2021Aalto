#include "./include/Simulation.hpp"


Simulation::Simulation(CityClass* city, unsigned int npeople, double endtime){ //outputfile
    city_ = city;
    npeople_ = npeople;
    endtime_ = endtime;
}


/*
* void Simulation::Init() initializes npeople number of people in random location in given city.
*/

void Simulation::Init(){
    std::vector<std::pair<std::string,Building*>>  allCityBuildings = city_ -> GetRESBuildings();

    int peopleToSettle = npeople_;
    while (peopleToSettle > 0) { //This has to be redefined to set the Person's required fields (initial location, home, workplace, preferred shopping place etc.) accordingly
        int randomBuildingIndex = rand() % allCityBuildings.size();
        int carSize =  rand() % 5 + 1;
        bool fitting = allCityBuildings[randomBuildingIndex].second->takeVehicle(new Car(carSize), nullptr); 
        Person* newperson = new Person();
        if (fitting)  allCityBuildings[randomBuildingIndex].second->TakePerson(newperson); {
            peopleToSettle --;
            people_.push_back(newperson);
        }
    }
}

void Simulation::Simulate(){
    unsigned int tickindex = 0;
    double tick = 0.45; // seconds
    double time = 0.0; // in seconds

    // at each tick of an hour, sum the amount of cards on each road into this, then average and clear hourly.
    //std::vector<double> outputline (city_->GetRoads.size(), 0.0); 

    while (time <= endtime_) {
        //iterate through crossroads                
        // for (auto [name, crossroad] : city_->GetCrossroad()){
        //     crossroad->performTimeStep();
        // }
        //iterate through roads
        // for (auto [name, road] : city_->GetRoads()){
        //     road->performTimeStep();
        // }
        //iterate through buildings
        // for (auto [name, building] : city_->GetBuildings()){
        //     building->performTimeStep();
        // }
        //iterate through people
        for (auto person : people_){
            person->performTimeStep(tickindex);
        }


    // hourly averagin
    if(tickindex % 8000-1 == 0){ //8000 ticks in an hour
        //TO DO: average (divide by 8000) and write output

        // then clear the outputvector
        //std::fill(outputline.begin(), outputline.end(), 0.0);
    }
    
    time += tick;
    tickindex += 1;

    }
}
