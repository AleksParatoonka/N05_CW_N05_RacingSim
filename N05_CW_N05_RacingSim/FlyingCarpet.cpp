#include "FlyingCarpet.h"
double FlyingCarpet::get_reduction_factor(double distance) {
    double reduction_factor = 0.0;
    if (distance >= 10000) {
        reduction_factor = 0.05;
    }
    else if (distance < 10000 && distance >= 5000) {
        reduction_factor = 0.1;
    }
    else if (distance < 5000 && distance >= 1000) {
        reduction_factor = 0.03;
    }
    else {
        reduction_factor = 0.0;
    }
    return reduction_factor;
}