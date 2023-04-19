#include "Race.h"

int Race::get_max() { return max_count; }
int Race::get_registration_count() { return registration_count; }
void Race::add_registration_count(int increment) { registration_count += increment; }
void Race::get_winner() {
    bool numb_swap;
    do {
        numb_swap = 0;
        for (int i = 1; i < registration_count; i++) {
            if (vehicle_array[i - 1].get_time() > vehicle_array[i].get_time()) {
                ResultVehicle tmp = vehicle_array[i - 1];
                vehicle_array[i - 1] = vehicle_array[i];
                vehicle_array[i] = tmp;
                numb_swap = 1;
            }
        }
    } while (numb_swap);
}