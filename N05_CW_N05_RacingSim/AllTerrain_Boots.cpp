#include "AllTerrain_Boots.h"
double AllTerrain_Boots::get_relax_time(int relax_count) {
    double relax_time = 0;
    switch (relax_count) {
    case 1:
        relax_time = 10;
        break;
    default:
        relax_time = 5;
        break;
    }
    return relax_time;
}