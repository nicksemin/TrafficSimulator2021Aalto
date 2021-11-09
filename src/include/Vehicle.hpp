#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

/* 
* An abstract vehicle class. Vehicle object are stored within city objects, occupying their load capacity with the value of size_. 
*/

class Vehicle{
public:

    Vehicle(int size);

    const int& GetSize() const;
private:
    int size_;
};

#endif
