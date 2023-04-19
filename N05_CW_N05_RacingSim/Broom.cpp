#include "Broom.h"
double Broom::get_reduction_factor(double distance) {
    double reduction_factor = 0.0;
    reduction_factor = (static_cast<int>(distance / 1000)) * 0.01;
    return reduction_factor;
}