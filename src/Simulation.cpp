#include "./include/Simulation.hpp"

/*-----------------------------------------------------------------------------
 * Alexey's tests. Commented std::cout At tick, ticks fine, not needed now
 * because it occupies other info output by the console.
 * Added the console output of the car number for every road after every tick, if there
 * are cars, line 100
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Alexey's edit: added exceptions, so that it is possible to figure out
 * where the error happened
 *-----------------------------------------------------------------------------*/

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

    std::vector<std::pair<std::string,RoadLineClass*>> roadMap = city_->GetRoads();

    std::map<std::string,CrossroadClass*> crossroadClassMap = city_->GetCrossroads();

    std::vector<RoadLineClass*> roads;
    for(std::vector<std::pair<std::string,RoadLineClass*>>::iterator it = roadMap.begin(); it != roadMap.end(); ++it) {
    roads.push_back(it->second);
    }

    std::vector<CrossroadClass*> crossRoads;
    for(std::map<std::string,CrossroadClass*>::iterator it = crossroadClassMap.begin(); it != crossroadClassMap.end(); ++it) {
    crossRoads.push_back(it->second);
    }

    Navigator* navigator= new Navigator(roads, crossRoads);

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
        int randomCOMBuildingIndex = rand() % commercialBuildings.size();

        int carSize =  rand() % 5 + 1;
        bool fitting = residentBuildings[randomRESBuildingIndex].second->takeVehicle(new Car(carSize), nullptr);
        if (fitting) {
            Building* home = residentBuildings[randomRESBuildingIndex].second;
            Building* recreational = recreationalBuildings[randomRECBuildingIndex].second;
            Building* commercial = commercialBuildings[randomCOMBuildingIndex].second;
            Building* work = industrialBuildings[randomINDBuildingIndex].second;
            Person* newperson = new Person(navigator, home, recreational, commercial, work);
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


    try{
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
		std::vector<size_t> newline;
		std::vector<std::pair<std::string,RoadLineClass*>> roads = city_->GetRoads();
		std::transform(roads.cbegin(), roads.cend(),std::back_inserter(newline),[](std::pair<std::string,RoadLineClass*> pair) {return pair.second->getNumberOfCars(); });

		/*-----------------------------------------------------------------------------
		 * Alexey's test
		 *-----------------------------------------------------------------------------*/
		for ( const auto& element : city_->GetRoads() ){
			if ( element.second->getNumberOfCars() != 0 ){
				std::cout << "The road " << element.first << " has " << element.second->getNumberOfCars() << " cars at tick "
					<< tickindex << std::endl;
			}
		}

		// Add up to the hourly sum
		std::transform (outputline.begin(), outputline.end(), newline.begin(), outputline.begin(), std::plus<double>());
		newline.clear();

		// hourly averagin
		if(tickindex % 8000-1 == 0){ //8000 ticks in an hour
		    //TO DO: average (divide outputline by 8000) and write output

		    // then clear the outputvector
		    //std::fill(outputline.begin(), outputline.end(), 0.0);
		}

		//std::cout<<"At tickindex "<<tickindex<<std::endl;

		time += tick;
		tickindex += 1;
	    }
    }
	catch ( NavigatorException& e ){
		//find the crossroad that caused an error
		auto it{ std::find_if( city_->GetCrossroads().begin(), city_->GetCrossroads().end(),
				[ &e ]( auto& element ) -> bool
				{
					return element.second == e.getErrorObject();
				} ) };
		std::cout << "Error: " << e.what() <<
			" for the crossroad " << ( it == city_->GetCrossroads().end() ?
			"that cannot be located" : it->first ) << std::endl;
	}
	catch ( BuildingRemovePersonException& e ){
		std::cout << e.what() << std::endl;
	}
	catch ( NullPtrException& e ){
		std::cout << e.what() << '\n' << e.getCustomMessage() << std::endl;
	}
	catch ( UserInputException& e ){
		std::cout << e.what() << e.getCustomMessage() << std::endl;
	}

}
