#ifndef CONSTANTS_H
#define CONSTANTS_H

#define HOUR 60.0

// Probabilities
#define SUMMER_ENTRY_PROB 0.2  // ??? Probablity of visitor entry through the summer entrance
#define ONLINE_TICKET_PROB 0.6 // ??? Probability of visitor having an online ticket

// Capacities
#define SUMMER_CAPACITY 6500  // System capacity in summer mode
#define DEFAULT_CAPACITY 3000 // Default system capacity (outside of summer mode)

// Register capacities
#define SUMMER_ENTRY_REGISTER_CNT 3 // ??? Number of registers at the summer entry
#define MAIN_ENTRY_SMART_CNT 7      // Number of smart registers at the main entry
#define MAIN_ENTRY_REGISTER_CNT 3   // ??? Number of registers at main entry

// Register times in minutes
#define ENTRY_REGISTER_TIME 3   // ??? Average time at a register
#define MAIN_ENTRY_SMART_TIME 2 // Average time at the smart register

// Visitor stay time
#define SUMMER_STAY_AVG 6 * HOUR    // Average time of stay in the summer mode
#define DEFAULT_STAY_AVG 4.5 * HOUR // Average time of stay outside summer mode
#define SUMMER_GAMMA_ALPHA 9        // ??? Alpha value of gamma distribution for summer mode
#define SUMMER_GAMMA_BETA \
	SUMMER_STAY_AVG / SUMMER_GAMMA_ALPHA // Beta value of gamma distribution for summer mode
#define DEFAULT_GAMMA_ALPHA 10        // ??? Alpha value of gamma distribution outside of summer mode
#define DEFAULT_GAMMA_BETA \
	DEFAULT_STAY_AVG / DEFAULT_GAMMA_ALPHA // Beta value of gamma distribution outside of summer mode

// Prices
#define BASE_PRICE 899
#define ESHOP_PRICE 799
#define SALE_PRICE 499

// System timings
#define START_TIME_SIMULATION 9 * HOUR
#define END_TIME_SIMULATION 22 * HOUR
#define OPENING_TIME 10 * HOUR
#define SALE_TIME 17.0
#define LAST_ENTRY_TIME 19.5

// Summer weekday - visitor arrivals
static const double SUMMER_WEEKDAY[16] = {
    300, 700,        // 9-10 
    300, 220, 190,  // 11-13 
    190, 190, 130,  // 14-16 
    480, 190, 50,  // 17-19 
    0, 0, 0, 0      // 20-23 
};  

// Summer weekend - visitor arrivals
static const double SUMMER_WEEKEND[16] = {
    400, 1000,       // 9-10 
    350, 320, 280,  // 11-13 
    200, 200, 130,  // 14-16
    600, 360, 240,  // 17-19 
    0, 0, 0, 0      // 20-23 
};  

// Regular weekday (winter) - visitor arrivals
static const double DEFAULT_WEEKDAY[16] = {
    40, 200,        // 9-10 
    160, 160, 145,  // 11-13 
    120, 95, 65,    // 14-16 
    240, 145, 95,   // 17-19 
    0, 0, 0, 0      // 20-23
}; 

// Regular weekend (winter) - visitor arrivals
static const double DEFAULT_WEEKEND[16] = {
    200, 540,        // 9-10 
    300, 240, 220,  // 11-13 
    180, 140, 100,  // 14-16 
    360, 220, 140,  // 17-19 
    0, 0, 0, 0      // 20-23
};  
#endif