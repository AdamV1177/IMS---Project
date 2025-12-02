#include "Visitor.hpp"
#include "Constants.hpp"
#include "Waterpark.hpp"
#include <iostream>

void Visitor::Behavior() {

	// Choose entry based on time of year and probability
	if (Waterpark::summerMode && Random() <= SUMMER_ENTRY_PROB)
		outsideEntry();
	else
		insideEntry();
		
	inWaterpark(); // Visitor in waterpark

	Leave(Waterpark::Capacity); // Return capacity after leaving
	Waterpark::departureHist((int)Time / HOUR);
    if (Waterpark::CapacityQueue.Length() > 0)
        (Waterpark::CapacityQueue.GetFirst())->Activate();
}

double Visitor::getStayTime() {
	const double alpha = !Waterpark::summerMode ? 
		(Waterpark::holidayMode ? DEFAULT_WEEKEND_GAMMA_ALPHA : DEFAULT_GAMMA_ALPHA) : SUMMER_GAMMA_ALPHA;

	const double beta = !Waterpark::summerMode ? 
		(Waterpark::holidayMode ? DEFAULT_WEEKEND_GAMMA_BETA : DEFAULT_GAMMA_BETA) : SUMMER_GAMMA_BETA;

	return std::min(Gamma(alpha, beta), CLOSING_TIME - Time);
}

void Visitor::inWaterpark() {

	const double entryTime = Time;	// Record time of entry into waterpark

	// Wait until the visitors random stay time elapses of the waterpark closes
	double stayTime = getStayTime();
	Wait(stayTime);

	Waterpark::TimeInWaterpark((Time - entryTime) / HOUR); // Record time spent inside
}

void Visitor::outsideEntry() {

    // Chance of the visitor having a prebought ticket
    if (Random() <= ONLINE_TICKET_PROB) {
        useRegister(Waterpark::SummerSmartRegisterEntry, &Waterpark::SummerSmartQueue, 
                    Waterpark::SummerSmartRegisterEntry.size(), ENTRY_SMART_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? ESHOP_PRICE : SALE_PRICE;
    } else {
        useRegister(Waterpark::SummerEntry, &Waterpark::SummerEntryQueue, 
                    Waterpark::SummerEntry.size(), ENTRY_REGISTER_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? BASE_PRICE : SALE_PRICE;
    }
}

void Visitor::insideEntry() {
    // Chance of the visitor having a prebought ticket
    if (Random() <= ONLINE_TICKET_PROB) {
        useRegister(Waterpark::SmartRegisterEntry, &Waterpark::MainSmartQueue, 
                    Waterpark::SmartRegisterEntry.size(), ENTRY_SMART_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? ESHOP_PRICE : SALE_PRICE;
    } else {
        useRegister(Waterpark::MainEntry, &Waterpark::MainEntryQueue, 
                    Waterpark::MainEntry.size(), ENTRY_REGISTER_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? BASE_PRICE : SALE_PRICE;
    }
}

void Visitor::useRegister(std::vector<Facility*>& registers, Queue *queue, int count, double time) {

    // Get time of entering into queue and arrival hour
    double queueEnter = Time;
    int arrivalHour = (int)(Time / HOUR);
    
    // Passivate process in the queue if the waterpark isnt open yet
    if (Time < OPENING_TIME) {
        Into(*queue);
        Passivate();
    }

    int free = -1;
    while (free == -1) {

        // Look for free register
        for (int i = 0; i < count; i++) {
            // UPDATED: Use -> because registers[i] is a pointer
            if (!registers[i]->Busy()) {
                free = i;
                break;
            }
        }

        // No free register, enter queue and wait for activation
        if (free == -1) {
            Into(*queue);
            Passivate();
        }
    }

    // Seize the found free register
    Seize(*registers[free]);

    while (true) {

        // If the waterpark is not at capacity, enter through found free register
        if (!Waterpark::Capacity.Full()) {
            Enter(Waterpark::Capacity);
            Waterpark::QueueWaitTime[arrivalHour - (int)(START_TIME_SIMULATION / HOUR)](Time - queueEnter);
            Wait(Exponential(time));
            Release(*registers[free]);
            Waterpark::entryHist((int)Time / HOUR);
            break;
        }

        // Otherwise wait for capacity to free up, but keep the found free register seized
        else {
            Into(Waterpark::CapacityQueue);
            Passivate();
        }
    }
    
    // Activate next process in Queue
    if (queue->Length() > 0)
        (queue->GetFirst())->Activate();
}