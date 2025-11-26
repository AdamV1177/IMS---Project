#include "Visitor.hpp"
#include "Constants.hpp"
#include "Waterpark.hpp"
#include <iostream>

void Visitor::Behavior() {
	Enter(Waterpark::Capacity); // Take waterpark capacity

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
}

void Visitor::insideEntry() {

	// Chance of the visitor having a prebought ticket
	// Use either smart kiosks or the main registers with cashiers
	if (Random() <= ONLINE_TICKET_PROB)
		useRegister(Waterpark::SmartRegisterEntry, &Waterpark::SmartRegisterQueue, SUMMER_ENTRY_REGISTER_CNT, ENTRY_REGISTER_TIME);
	else
		useRegister(Waterpark::MainEntry, &Waterpark::MainEntryQueue, MAIN_ENTRY_REGISTER_CNT, ENTRY_REGISTER_TIME);
}

void Visitor::useRegister(Facility *entry, Queue *queue, int count, double time) {
	int free = -1;
	while (free == -1) {

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

	// Seize and use register
	Seize(entry[free]);
	Wait(Exponential(time));
	Release(entry[free]);

	// Activate process in Queue
	if (queue->Length() > 0)
		(queue->GetFirst())->Activate();
}
