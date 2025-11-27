#include <simlib.h>

class OccupancySampler : public Event {
private:
    int hour = 0;
public:
    void Behavior();
};