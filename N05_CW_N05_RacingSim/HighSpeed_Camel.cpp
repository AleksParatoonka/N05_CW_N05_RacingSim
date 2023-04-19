#include "HighSpeed_Camel.h"
double HighSpeed_Camel::get_relax_time(int relax_count) {
    double relax_time = 0;
    switch (relax_count) {
    case 1:
        relax_time = 5;
        break;
    case 2:
        relax_time = 6.5;
        break;
    default:
        relax_time = 8;
        break;
    }
    return relax_time;
}