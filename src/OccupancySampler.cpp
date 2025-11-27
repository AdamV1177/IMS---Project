#include "OccupancySampler.hpp"
#include "Constants.hpp"
#include "Waterpark.hpp"

void OccupancySampler::Behavior() {
    int used = Waterpark::Capacity.Used();  // Get number of people inside
    Waterpark::Occupancy[this->hour++] = used;  // Store in the current hours occupancy
    Activate(Time + HOUR);  // Sample again in the next hour
}