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
}

void Visitor::inWaterpark() {

	// Wait for some random time based on waterpark mode
	const double alpha = Waterpark::summerMode ? SUMMER_GAMMA_ALPHA : DEFAULT_GAMMA_ALPHA;
	const double beta = Waterpark::summerMode ? SUMMER_GAMMA_BETA : DEFAULT_GAMMA_BETA;
	Wait(Gamma(alpha, beta));
}

void Visitor::outsideEntry() {

	// Use summer entry with its queue
	useRegister(Waterpark::SummerEntry, &Waterpark::SummerEntryQueue, SUMMER_ENTRY_REGISTER_CNT, ENTRY_REGISTER_TIME);
	Waterpark::moneyMade += Time / HOUR < SALE_TIME ? BASE_PRICE : SALE_PRICE;
}

void Visitor::insideEntry() {

	// Chance of the visitor having a prebought ticket
	// Use either smart kiosks or the main registers with cashiers
	if (Random() <= ONLINE_TICKET_PROB) {
		useRegister(Waterpark::SmartRegisterEntry, &Waterpark::SmartRegisterQueue, SUMMER_ENTRY_REGISTER_CNT, MAIN_ENTRY_SMART_TIME);
		Waterpark::moneyMade += Time / HOUR < SALE_TIME ? ESHOP_PRICE : SALE_PRICE;
	} else {
		useRegister(Waterpark::MainEntry, &Waterpark::MainEntryQueue, MAIN_ENTRY_REGISTER_CNT, ENTRY_REGISTER_TIME);
		Waterpark::moneyMade += Time / HOUR < SALE_TIME ? BASE_PRICE : SALE_PRICE;
	}
}

void Visitor::useRegister(Facility *entry, Queue *queue, int count, double time) {

	// Get time of entering into queue and arrival hour
	double queueEnter = Time;
	int arrivalHour = (int)(Time / HOUR);
	
	int free = -1;
	while (free == -1) {

		// Passivate process in the queue if the waterpark isnt open yet
		if (Time < OPENING_TIME) {
			Into(*queue);
			Passivate();
		}

		// Look for free register
		for (int i = 0; i < count; i++) {
			if (!entry[i].Busy()) {
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

	// Log wait time in queue by arrival hour
	Waterpark::QueueWaitTime[arrivalHour - (int)(START_TIME_SIMULATION / HOUR)](Time - queueEnter);

	// Seize and use register
	Seize(entry[free]);
	Wait(Exponential(time));
	Release(entry[free]);

	// Take waterpark capacity on entry
	Enter(Waterpark::Capacity);

	// Activate process in Queue
	if (queue->Length() > 0)
		(queue->GetFirst())->Activate();
}
