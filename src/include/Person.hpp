#ifndef PERSON_HPP
#define PERSON_HPP
/*
 * =====================================================================================
 *        Class:  Person
 *  Description:  Base class for persons inhabiting a city. Might become abstract when scaling
 * Contact info - Nikolai.
 * =====================================================================================
 */
#include <string>
#include "./include/Vehicle.hpp"
#include "./include/Building.hpp"
class Person{
private:

    Vehicle* ownVehicle;
    Building* livingPlace;
    std::string name_;
    //int age_; is not needed now
    int happiness_;
    bool occupied_;
    std::string occupation_;
    double money_;
    bool drivingLicense_;//will not be needed for the first iteration; will be used when pedestrians
    int hunger_;
    int food_;
    int tiredness_;
    Vehicle* own_vehicle;
    int time_leaving_;
    int time_coming_;
public:
    Person(const std::string& name, const std::string& occupation);

    const std::string& get_name() const;

    const std::string& get_occupation() const;

    bool is_tired() const;

    bool is_hungry() const;

    bool is_unhappy() const;

    bool has_money() const;

    void eat_food(int);

    void add_food(int);

    void add_money(int);

    void remove_money(int);

    void increase_happiness(int);

    void decrease_happiness(int);

    void increase_tiredeness(int);

    void decrease_tiredeness(int);

    Building* leave_home() const;
};
#endif