#include "LastEntry.hpp"
#include "Waterpark.hpp"
#include "Visitor.hpp"
#include <simlib.h>

void LastEntry::Behavior() {

    // Clear all queues 
    ClearQueue(Waterpark::SummerEntryQueue);
    ClearQueue(Waterpark::SummerSmartQueue);
    ClearQueue(Waterpark::MainEntryQueue);
    ClearQueue(Waterpark::MainSmartQueue);
    ClearQueue(Waterpark::CapacityQueue);
}

void LastEntry::ClearQueue(Queue& queue) {

    // Log statistic of wait time in queue for visitors leaving because of last entry time
    while (queue.Length() > 0) {
        Visitor* v = static_cast<Visitor*>(queue.GetFirst());
        if (v) {
            v->QueueTimeWait = Time - v->QueueTimeEnter;
            int arrivalHour = (int)(v->QueueTimeEnter / HOUR);
            int i = arrivalHour - (int)(START_TIME_SIMULATION / HOUR);
            Waterpark::QueueWaitTime[i](v->QueueTimeWait);
        }
    }
}