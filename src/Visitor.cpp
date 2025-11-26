#include "Visitor.hpp"
#include "Waterpark.hpp"
#include "Constants.hpp"
#include <iostream>

void Visitor::Behavior() {
  Enter(Waterpark::Capacity);   // Take waterpark capacity

  // Choose entry based on time of year and probability
  if (Waterpark::summerMode && Random() <= SUMMER_ENTRY_PROB)
    outsideEntry();
  else 
    insideEntry();

  inWaterpark();  // Visitor in waterpark

  Leave(Waterpark::Capacity);   // Return capacity after leaving
}

void Visitor::inWaterpark() {
  // Wait for some random time based on waterpark mode
  const double alpha = Waterpark::summerMode ? SUMMER_GAMMA_ALPHA : DEFAULT_GAMMA_ALPHA;
  const double beta = Waterpark::summerMode ? SUMMER_GAMMA_BETA : DEFAULT_GAMMA_BETA;
  Wait(Gamma(alpha, beta));
}

void Visitor::outsideEntry() {

  // Wait for free summer entry register
  int free = -1;
  while (free == -1) {

    // Look for free register
    for (int i = 0; i < SUMMER_ENTRY_REGISTER_CNT; i++) {
      if (!Waterpark::SummerEntry[i].Busy()){
        free = i;
        break;
      }
    }

    // No free register, enter queue and wait for activation
    if (free == -1) {
      Into(Waterpark::SummerEntryQueue);
      Passivate();
    }
  }
  
  // Seize and use register
  Seize(Waterpark::SummerEntry[free]);
  Wait(Exponential(SUMMER_ENTRY_REGISTER_TIME));
  Release(Waterpark::SummerEntry[free]);

  // Activate process in Queue
  if (Waterpark::SummerEntryQueue.Length() > 0)
    (Waterpark::SummerEntryQueue.GetFirst())->Activate();
}

void Visitor::insideEntry() {
  // TODO tady bude peknej bordel s pokladnama xD
  std::cerr << "TODO\n";
}
