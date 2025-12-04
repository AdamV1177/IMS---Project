#include <simlib.h>

// Class sampling occupency of the aquapark per hour
class OccupancySampler : public Event {
private:
    int hour = 0;
public:
    void Behavior();
};