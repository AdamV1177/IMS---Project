#include "Visitor.hpp"
#include "Constants.hpp"
#include "Waterpark.hpp"
#include <iostream>

void Visitor::Behavior() {

    // Check if both waterpark enterances have an open register
    bool outsideOpen = Waterpark::SummerEntryCnt > 0 || Waterpark::SummerSmartRegisterEntryCnt > 0;
    bool insideOpen  = Waterpark::MainEntryCnt > 0 || Waterpark::SmartRegisterEntryCnt > 0;

	if (outsideOpen && insideOpen) {
        // Normal summer mode random choice
        if ((Waterpark::forceSummerEntry || Waterpark::summerMode) && Random() <= SUMMER_ENTRY_PROB)
            outsideEntry();
        else
            insideEntry();
    }
    else if (outsideOpen) {
        outsideEntry(); // Only outside entrance is open
    }
    else if (insideOpen) {
        insideEntry(); // Only inside entrance is open
    }
		
	inWaterpark(); // Visitor in waterpark

    // Return capacity after leaving and register departure statistic
	Leave(Waterpark::Capacity); 
	Waterpark::departureHist((int)Time / HOUR);

    // If some visitor is waiting for capacity to free up, activate
    if (Waterpark::CapacityQueue.Length() > 0)
        (Waterpark::CapacityQueue.GetFirst())->Activate();
}

double Visitor::getStayTime() {

    // Get gamma distribution values based on mode
	const double alpha = !Waterpark::summerMode ? 
		(Waterpark::holidayMode ? DEFAULT_WEEKEND_GAMMA_ALPHA : DEFAULT_GAMMA_ALPHA) : SUMMER_GAMMA_ALPHA;
	const double beta = !Waterpark::summerMode ? 
		(Waterpark::holidayMode ? DEFAULT_WEEKEND_GAMMA_BETA : DEFAULT_GAMMA_BETA) : SUMMER_GAMMA_BETA;

    // Limit visitors stay only up to closing time
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

    // Use only register group that is available
    if(Waterpark::SummerEntryCnt == 0){
        useRegister(Waterpark::SummerSmartRegisterEntry, &Waterpark::SummerSmartQueue, 
                    Waterpark::SummerSmartRegisterEntry.size(), ENTRY_SMART_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? ESHOP_PRICE : SALE_PRICE;
    }
    else if(Waterpark::SummerSmartRegisterEntryCnt == 0){
        useRegister(Waterpark::SummerEntry, &Waterpark::SummerEntryQueue, 
                    Waterpark::SummerEntry.size(), ENTRY_REGISTER_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? BASE_PRICE : SALE_PRICE;
    }

    // Otherwise normal random choice based on online ticket probability
    else{
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
}

void Visitor::insideEntry() {

    // Use only register group that is available
    if(Waterpark::MainEntryCnt == 0){
        useRegister(Waterpark::SmartRegisterEntry, &Waterpark::MainSmartQueue, 
                    Waterpark::SmartRegisterEntry.size(), ENTRY_SMART_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? ESHOP_PRICE : SALE_PRICE;
    }
    else if(Waterpark::SmartRegisterEntryCnt == 0){
        useRegister(Waterpark::MainEntry, &Waterpark::MainEntryQueue, 
                    Waterpark::MainEntry.size(), ENTRY_REGISTER_TIME);
        Waterpark::moneyMade += Time / HOUR < SALE_TIME ? BASE_PRICE : SALE_PRICE;
    }

    // Otherwise normal random choice based on online ticket probability
    else{
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
    
}

void Visitor::useRegister(std::vector<Facility*>& registers, Queue *queue, int count, double time) {

    // Get time of entering into queue and arrival hour
    QueueTimeEnter = Time;
    int arrivalHour = (int)(Time / HOUR);
    
    // Passivate process in the queue if the waterpark isnt open yet (gets activated later by OpeningTime event)
    if (Time < OPENING_TIME) {
        Into(*queue);
        Passivate();
    }

    int free = -1;
    while (free == -1) {

        // Look for free register
        for (int i = 0; i < count; i++) {
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

            // Take capacity and register time witing in queue
            Enter(Waterpark::Capacity);
            QueueTimeWait = Time - QueueTimeEnter;
            int hourIndex = arrivalHour - (int)(START_TIME_SIMULATION / HOUR);
            Waterpark::QueueWaitTime[hourIndex](QueueTimeWait);

            // Wait random time at register, after finished, release the facility and register time of entry
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