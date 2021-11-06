#include "./include/Vehicle.hpp"

Vehicle::Vehicle(int size):size_(size) {    }

const int& Vehicle::GetSize(){
    return size_;
}