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
#include "Vehicle.hpp"
#include "Building.hpp"
class Person{
private:

    Building* home_;
    std::string name_;
    int happiness_;
    bool occupied_;
    std::string occupation_;
    double money_;
    bool drivingLicense_;//will not be needed for the first iteration; will be used when pedestrians
    int hunger_;
    int food_;
    Vehicle* own_vehicle_;
    int time_leaving_;
    int time_coming_;
public:
    Person(const std::string& name, const std::string& occupation);

    const std::string& get_name() const;

    const std::string& get_occupation() const;

    double get_money() const;

    int get_time_leaving() const;

    int get_time_coming() const;

    int get_happiness() const;

    int get_food() const;

    int get_hunger() const;

    bool is_hungry() const;

    bool is_happy() const;

    bool has_money() const;

    bool shouldLeave() const;

    void eat_food(int);

    void add_food(int);

    void add_money(int);

    void remove_money(int);

    void increase_happiness(int);

    void decrease_happiness(int);

};
#endif