#include "LastEntry.hpp"
#include "Waterpark.hpp"

void LastEntry::Behavior() {
	Waterpark::SummerEntryQueue.Clear();
	Waterpark::SummerSmartQueue.Clear();
	Waterpark::MainEntryQueue.Clear();
	Waterpark::MainSmartQueue.Clear();
	Waterpark::CapacityQueue.Clear();
}