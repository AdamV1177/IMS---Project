#include "OpeningTime.hpp"
#include "Constants.hpp"
#include "Waterpark.hpp"

void OpeningTime::Behavior() {
	// When the waterpark opens, activate as many processes as there are registers in that entry
	openQueue(&Waterpark::SmartRegisterQueue, MAIN_ENTRY_SMART_CNT);
	openQueue(&Waterpark::MainEntryQueue, MAIN_ENTRY_REGISTER_CNT);
	openQueue(&Waterpark::SummerEntryQueue, SUMMER_ENTRY_REGISTER_CNT);
}

void OpeningTime::openQueue(Queue *queue, int registers) {
	// Activate visitor processes until the queue is empty or
	// the number of activated processes is equal to the number of registers
	int toActivate = registers;
	while (toActivate-- > 0 && queue->Length() > 0)
		(queue->GetFirst())->Activate();
}