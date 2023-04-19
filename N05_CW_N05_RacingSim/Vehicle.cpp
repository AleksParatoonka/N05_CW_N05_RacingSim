#include "Vehicle.h"

//virtual double Vehicle::calculate_time(double distance) { if (speed > 0) return distance / speed; };
double Vehicle::calculate_time(double distance) { if (speed > 0) return distance / speed; };
double Vehicle::get_time() { return time; }
std::string Vehicle::get_name() { return name; }
int Vehicle::get_num() { return num; }