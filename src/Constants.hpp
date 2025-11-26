#ifndef CONSTANTS_H
#define CONSTANTS_H

#define HOUR 60.0

// Probabilities
#define SUMMER_ENTRY_PROB 0.4         // ??? Probablity of visitor entry through the summer entrance
#define ONLINE_TICKET_PROB 0.6        // ??? Probability of visitor having an online ticket

// Capacities
#define SUMMER_CAPACITY 6500          // System capacity in summer mode
#define DEFAULT_CAPACITY 3000         // Default system capacity (outside of summer mode)

// Register capacities
#define SUMMER_ENTRY_REGISTER_CNT 3   // ??? Number of registers at the summer entry
#define MAIN_ENTRY_SMART_CNT 2        // ??? Number of smart registers at the main entry
#define MAIN_ENTRY_REGISTER_CNT 5     // ??? Number of registers at main entry

// Register times in minutes
#define SUMMER_ENTRY_REGISTER_TIME 3  // ??? Average time at the summer entry register 
#define MAIN_ENTRY_SMART_TIME 2       // Average time at the smart register
#define MAIN_ENTRY_REGISTER_TIME 3    // ??? Average time at the main entry register

// Visitor stay time
#define SUMMER_STAY_AVG 6*HOUR              // Average time of stay in the summer mode
#define DEFAULT_STAY_AVG 4.5*HOUR           // Average time of stay outside summer mode
#define SUMMER_GAMMA_ALPHA 9                // ??? Alpha value of gamma distribution for summer mode
#define SUMMER_GAMMA_BETA \                 
  SUMMER_STAY_AVG/SUMMER_GAMMA_ALPHA        // Beta value of gamma distribution for summer mode
#define DEFAULT_GAMMA_ALPHA 10              // ??? Alpha value of gamma distribution outside of summer mode
#define DEFAULT_GAMMA_BETA \                 
  DEFAULT_STAY_AVG/DEFAULT_GAMMA_ALPHA      // Beta value of gamma distribution outside of summer mode

#endif