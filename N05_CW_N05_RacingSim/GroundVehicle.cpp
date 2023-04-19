#include "GroundVehicle.h"


double GroundVehicle::get_relax_time(int relax_count) {
    double relax_time = 0;
    return relax_time;
}

double GroundVehicle::calculate_time(double distance) { // override {
    if (Vehicle::speed > 0) {
        double time = distance / Vehicle::speed;
        
        int relax_count = 0;
        
        if (before_relax_time != 0) {
            relax_count = static_cast<int>(time / before_relax_time);
        }

        if (relax_count == 0) {
            return time;
        }
        else {
            time = fmod(time, before_relax_time);
            
            for (int i = 1; i <= relax_count; i++) {
                time += (before_relax_time + get_relax_time(i));
            }
            return time;
        }
    }
}