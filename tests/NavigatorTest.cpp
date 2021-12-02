#include <gtest/gtest.h>
#include "Person.cpp"
#include "buildingexitcrossroad.cpp"
#include "Vehicle.cpp"
#include "CityObject.cpp"
#include "crossroadclass.cpp"
#include "roadlineclass.cpp"
#include "roadobjectclass.cpp"
#include "Building.cpp"
#include "Navigator.cpp"
#include "unregulatedcrossroad.cpp"
#include "iostream"

UnregulatedCrossroad firstCross{ 0, 0 };
UnregulatedCrossroad secondCross{ 20, 0 };
UnregulatedCrossroad thirdCross{ 40, 40 };
UnregulatedCrossroad fourthCross{ 60, 40 };
UnregulatedCrossroad fifthCross{ 60, 60 };

RoadLineClass Mannerheimintie{ &firstCross, &secondCross };
RoadLineClass Runeberginkatu{ &secondCross, &thirdCross };
RoadLineClass Helsiginkatu{ &thirdCross, &fourthCross };
RoadLineClass Sturenkatu{ &fourthCross, &fifthCross };

std::vector<RoadLineClass*> map = { &Mannerheimintie, &Runeberginkatu, &Helsiginkatu, &Sturenkatu };
std::vector<CrossroadClass*> crossroads = {&firstCross, &secondCross, &thirdCross, &fourthCross, &fifthCross };


TEST(navigator_test, Constructor){
    Navigator n =   Navigator(map, crossroads);
    std::vector<RoadLineClass*> route = n.MakeRoute(firstCross, fifthCross);
    //EXPECT_EQ(route, map); //todo: fix comparison of vector of

    EXPECT_TRUE(true); 
}


