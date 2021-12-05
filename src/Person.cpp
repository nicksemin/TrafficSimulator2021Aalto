#include "./include/Person.hpp"
#include <random>


Person::Person(Navigator* n, Building* home, Building* fav_recreational,Building* fav_commercial, Building* work):navigator_(n), home_(home), fav_recreational_(fav_recreational), fav_commercial_(fav_commercial) {
    current_place_ = home;
    id_ = ++nextID_;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 192001);

    time_leaving_ = dist(rd) % 192000;//192 000 ticks in one day of the simulation, if tick is 0.45 seconds
    time_coming_ = dist(rd) % 192000;

    money_ = 500;
    hunger_ =1500;
    happiness_ = 1000;
    food_ = 100;

}

unsigned int Person::nextID_ = 0;

unsigned int Person::get_id() const{
    return id_;
}

void Person::set_current_place(Building* b){
    current_place_ = b;
}

Building* Person::get_destination() const{
    return destination_;
}

  Navigator* Person::getNavigator() {
      return navigator_;
  }

double Person::get_money() const{
    return money_;
}

int Person::get_happiness  () const{
    return happiness_;
}

int Person::get_food() const{
    return food_;
}

int Person::get_hunger() const{
    return hunger_;
}


bool Person::is_hungry() const {
    if (hunger_ > 0)
        return false;
    else
        return true;
}

bool Person::is_happy() const {
    if (happiness_ > 0)
        return true;
    else
        return false;
}

bool Person::has_money() const{
    if (money_ > 0)
        return true;
    else
        return false;
}

void Person::eat_food(int food){
    if (is_hungry()) {
        food_ -= food;
        hunger_ += food;
    }
}

void Person::add_food(int i){
    food_ += i;
}

void Person::remove_money(int money){
    money_ -= money;
}

void Person::add_money(int money){
    money_ += money;
}

void Person::increase_happiness(int i){
    happiness_ += i;
}

void Person::decrease_happiness(int i){
    happiness_ -= i;
}

int Person::get_time_leaving() const{
    return time_leaving_;
}

int Person::get_time_coming() const{
    return time_coming_;
}

Building* Person::get_current_place() const{
    return current_place_;
}









