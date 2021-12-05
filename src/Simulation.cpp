#include "./include/Simulation.hpp"


Simulation::Simulation(CityClass* city, unsigned int npeople, double endtime,std::string outputfile){ //outputfile
    city_ = city;
    npeople_ = npeople;
    endtime_ = endtime;
    outputfile_ = outputfile;
}


/*
* void Simulation::Init() initializes npeople number of people in random location in given city.
*/

void Simulation::Init(){
    std::vector<std::pair<std::string,Building*>>  residentBuildings = city_ -> GetRESBuildings();
    std::vector<std::pair<std::string,Building*>>  recreationalBuildings = city_ -> GetRECBuildings();
    std::vector<std::pair<std::string,Building*>>  commercialBuildings = city_ -> GetCOMBuildings();
    std::vector<std::pair<std::string,Building*>>  industrialBuildings = city_ -> GetINDBuildings();

    int peopleToSettle = npeople_;
    while (peopleToSettle > 0) {

        //TODO: THINK OF SCENARIO WHEN MAXIMUM BUILDING'S CAPACITY IS REACHED
        int randomRESBuildingIndex = rand() % residentBuildings.size();
        int randomRECBuildingIndex = rand() % recreationalBuildings.size();
        int randomINDBuildingIndex = rand() % industrialBuildings.size();
        int randomComBuildingIndex = rand() % commercialBuildings.size();

        int carSize =  rand() % 5 + 1;
        bool fitting = residentBuildings[randomRESBuildingIndex].second->takeVehicle(new Car(carSize), nullptr); 
        if (fitting) {
            Building* home = residentBuildings[randomRESBuildingIndex].second;
            Building* recreational = recreationalBuildings[randomRECBuildingIndex].second;
            Building* commercial = commercialBuildings[randomINDBuildingIndex].second;
            Building* work = industrialBuildings[randomComBuildingIndex].second;
            Person* newperson = new Person(home, recreational, commercial, work);
            residentBuildings[randomRESBuildingIndex].second->TakePerson(newperson); 
            people_.push_back(newperson);
            }
            peopleToSettle --;
        
    }
}

void Simulation::Simulate(){
    unsigned int tickindex = 0;
    double tick = 0.45; // seconds
    double time = 0.0; // in seconds
    double endseconds = endtime_*60.0*60.0;

    // at each tick of an hour, sum the amount of cards on each road into this, then average and clear hourly.
    std::vector<double> outputline (city_->GetRoads().size(), 0.0); 
    

    while (time <= endseconds) {
        //iterate through crossroads                
        for (auto [name, crossroad] : city_->GetCrossroads()){
            crossroad->performTimeStep();
        }
        //iterate through roads
        for (auto [name, road] : city_->GetRoads()){
            road->performTimeStep();
        }
        //iterate through RESbuildings
        for (auto [name, building] : city_->GetRESBuildings()){
            building->performTimeStep();
        }
        //iterate through RECbuildings
        for (auto [name, building] : city_->GetRECBuildings()){
            building->performTimeStep();
        }
        //iterate through INDbuildings
        for (auto [name, building] : city_->GetINDBuildings()){
            building->performTimeStep();
        }
        //iterate through COMbuildings
        for (auto [name, building] : city_->GetCOMBuildings()){
            building->performTimeStep();
        }
        //iterate through people
        for (auto person : people_){
            person->performTimeStep(tickindex);
        }
        
        
        // Get the amount of cars on each road
        std::vector<size_t> newline(city_->GetRoads().size());
        std::vector<std::pair<std::string,RoadLineClass*>> roads = city_->GetRoads();
        std::transform(roads.cbegin(), roads.cend(),std::back_inserter(newline),[](std::pair<std::string,RoadLineClass*> pair) {return pair.second->getNumberOfCars(); });
        
        // Add up to the hourly sum
        std::transform (outputline.begin(), outputline.end(), newline.begin(), outputline.begin(), std::plus<double>());
        newline.clear();
        
        // hourly averagin
        if(tickindex % 8000-1 == 0){ //8000 ticks in an hour            
            //TO DO: average (divide outputline by 8000) and write output

            // then clear the outputvector
            //std::fill(outputline.begin(), outputline.end(), 0.0);
        }

        std::cout<<"At tickindex "<<tickindex<<std::endl;
        time += tick;
        tickindex += 1;

    }
}
