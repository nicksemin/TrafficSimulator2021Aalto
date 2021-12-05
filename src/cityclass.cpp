#include "./include/cityclass.hpp"

/*-----------------------------------------------------------------------------
 *  For the description see the include header file
 *-----------------------------------------------------------------------------*/

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  CityClass::CityClass
 *  Description:  A constructor that takes the file name as a parameter
 *  1) Imports the crossroads
 *  2) Imports the roads
 *  3) Imports somethings else, please start from here
 * =====================================================================================
 */
CityClass::CityClass(std::string fileName) : m_fileName{ fileName }
{
	std::ifstream input{ fileName };
	if ( !input ) {
		std::cerr << "Error! The file " << fileName << " cannot be accessed\n";
	}

	std::string fileLine{};
	//import the crossroads
	int x{};
	int y{};
	char crossRoadType{};
	std::string objectName{};
	std::stringstream parameters{};
	double trafficLightTime{};
	//get to the file section with crossroads
	while ( fileLine != "CROSSROADS" && !input.eof() ) {
		std::getline( input, fileLine );
	}

	//import the first crossroad
	std::getline( input, fileLine );

	//start constructing of the crossroad container
	while ( fileLine != "ROADS" && !input.eof() ) {
		parameters.str( fileLine );
		parameters >> crossRoadType >> objectName >> x >> y >> trafficLightTime;
		//depending on the type (Unregulated, building exit, etc...)
		switch ( crossRoadType ){
			case 'U':
				m_crossroads.insert(
						std::make_pair( objectName, new UnregulatedCrossroad{ UnregulatedCrossroad( x, y ) } )
						);
				break;
			case 'B':
				m_crossroads.insert(
						std::make_pair( objectName, new BuildingExitCrossroad{ BuildingExitCrossroad( x, y ) } )
						);
				break;
			case 'T':
				m_crossroads.insert(
						std::make_pair( objectName, new TrafficLightCrossroad{ TrafficLightCrossroad( x, y,
						       ( trafficLightTime == 0 ? TrafficLightCrossroad::defaultTrafficLightTime : trafficLightTime )
						       ) } ) );
				break;
			default:
				m_crossroads.insert(
						std::make_pair( objectName, new UnregulatedCrossroad{ UnregulatedCrossroad( x, y ) } )
						);
		}
		parameters.clear();
		trafficLightTime = 0;
		std::getline( input, fileLine );
	}
	//import the roads
	std::string start{};
	std::string end{};
	std::string hasTriangle{};
	std::getline( input, fileLine );
	while ( fileLine != "BUILDINGS" && !input.eof() ) {
		parameters.str( fileLine );
		parameters >> objectName >> start >> end >> hasTriangle;
		m_roads.push_back(
				std::make_pair( objectName, new RoadLineClass{ RoadLineClass( m_crossroads.at( start ), m_crossroads.at( end ),
						( hasTriangle == "HASTRIANGLE" ? true : false ) ) } )
			      );
		std::getline( input, fileLine );
		parameters.clear();
		hasTriangle = "";
	}


	std::getline( input, fileLine );

	std::string buildingType{};
	std::string exitCrossroad{};
	int capacity{};
	//start constructing of the building container
	while ( fileLine != "NEXT_SETTING_NAME" && !input.eof() ) {
		parameters.str( fileLine );
		parameters >> buildingType >> objectName >> exitCrossroad >> capacity;
		//depending on the type (Recreational, Residential...)
		if (buildingType == "REC"){
			m_RECbuildings.push_back(
					std::make_pair( objectName, new RecreationalBuilding{ RecreationalBuilding( m_crossroads[exitCrossroad], capacity ) } )
			);
		}else if (buildingType=="RES"){
			m_RESbuildings.push_back(
					std::make_pair( objectName, new ResidentialBuilding{ ResidentialBuilding( m_crossroads[exitCrossroad], capacity ) } )
					);
		}else if (buildingType == "IND"){
			m_INDbuildings.push_back(
					std::make_pair( objectName, new IndustrialBuilding{ IndustrialBuilding( m_crossroads[exitCrossroad], capacity ) } )
					);
		}else if (buildingType == "COM"){
			m_COMbuildings.push_back(
					std::make_pair( objectName, new CommercialBuilding{ CommercialBuilding( m_crossroads[exitCrossroad], capacity ) } )
					);
		}
		parameters.clear();
		std::getline( input, fileLine );
	}
}
std::map<std::string,CrossroadClass*> CityClass::GetCrossroads() const{
	return m_crossroads;
}
std::vector<std::pair<std::string,RoadLineClass*>> CityClass::GetRoads() const{
	return m_roads;
}
std::vector<std::pair<std::string,Building*>> CityClass::GetRESBuildings() const{
	return m_RESbuildings;
}
std::vector<std::pair<std::string,Building*>> CityClass::GetRECBuildings() const{
	return m_RESbuildings;
}
std::vector<std::pair<std::string,Building*>> CityClass::GetINDBuildings() const{
	return m_RESbuildings;
}
std::vector<std::pair<std::string,Building*>> CityClass::GetCOMBuildings() const{
	return m_RESbuildings;
}
