#include "./include/Person.hpp"
 const std::string& Person::get_name() const {return name_;}

 const std::string& Person::get_occupation() const {return occupation_;}

Person::Person(const std::string& name, const std::string& occupation) {
    name_ = name;
    occupation_ = occupation;
}
/*
 * THE CLASS IS NOT YET TESTED AND THE TESTING WILL BE DONE WITH GOOGLE TESTS BY/ON MONDAY
 *
 * FOR CONSTRUCTOR ILL ALSO ADD RANDOM GENERATOR FOR TIME LEAVING AND COMING
 */
 bool Person::is_tired() const {
    if (tiredness_ > 0)
        return false;
    else
            return true;
}

bool Person::is_hungry() const {
    if (hunger_ > 0)
        return false;
    else
        return true;
}

bool Person::is_unhappy() const {
    if (hunger_ > 0)
        return false;
    else
        return true;
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

void Person::increase_tiredeness(int i){
    tiredness_ += i;
}

void Person::decrease_tiredeness(int i) {
    tiredness_ -= i;
}

Building* Person::leave_home() const {
    Building* work_place;
    if (is_hungry() && is_tired() && is_unhappy()){
        /* for loop that is looking for a building with same name as Person's occupation
         * and assigns work_place with it. For now it is just nullptr
         */
        work_place = nullptr;
    }
    else
        work_place = nullptr;

    return work_place;





