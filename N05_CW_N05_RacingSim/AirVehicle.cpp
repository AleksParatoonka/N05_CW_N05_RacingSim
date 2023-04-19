#include "AirVehicle.h"

double AirVehicle::get_reduction_factor(double distance) {
    double reduction_factor = 0.0;

    return reduction_factor;
}

double AirVehicle::calculate_time(double distance) {//override {
    double time = 0.0;
    if (AirVehicle::speed > 0) {
        time = distance * (1 - get_reduction_factor(distance)) / speed;
        //time =  get_reduction_factor(distance);
    }
    return time;
}