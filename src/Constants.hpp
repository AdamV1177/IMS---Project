#ifndef CONSTANTS_H
#define CONSTANTS_H

#define HOUR 60.0
#define MINUTE 1

// Probabilities
#define SUMMER_ENTRY_PROB 0.2  // ??? Probablity of visitor entry through the summer entrance

// TODO more people with online ticket
#define ONLINE_TICKET_PROB 0.6 // ??? Probability of visitor having an online ticket

// Capacities
#define SUMMER_CAPACITY 6500  // System capacity in summer mode
#define DEFAULT_CAPACITY 3000 // Default system capacity (outside of summer mode)

// Register capacities
// TODO add summer entry smart
#define SUMMER_ENTRY_REGISTER_CNT 3 // ??? Number of registers at the summer entry
#define MAIN_ENTRY_SMART_CNT 8      // Number of smart registers at the main entry
#define MAIN_ENTRY_REGISTER_CNT 6   // ??? Number of registers at main entry

// Register times in minutes
// TODO lower times, account for families
#define ENTRY_REGISTER_TIME 0.4  // ??? Average time at a register
#define MAIN_ENTRY_SMART_TIME 0.3 // Average time at the smart register

// Visitor stay time
#define SUMMER_STAY_AVG 6 * HOUR    // Average time of stay in the summer mode
#define DEFAULT_STAY_AVG 6 * HOUR // Average time of stay outside summer mode
#define SUMMER_GAMMA_ALPHA 9        // ??? Alpha value of gamma distribution for summer mode
#define SUMMER_GAMMA_BETA \
	SUMMER_STAY_AVG / SUMMER_GAMMA_ALPHA // Beta value of gamma distribution for summer mode
#define DEFAULT_GAMMA_ALPHA 5       // ??? Alpha value of gamma distribution outside of summer mode
#define DEFAULT_GAMMA_BETA \
	DEFAULT_STAY_AVG / DEFAULT_GAMMA_ALPHA // Beta value of gamma distribution outside of summer mode

// Prices
#define BASE_PRICE 899
#define ESHOP_PRICE 799
#define SALE_PRICE 499

// System timings
#define START_HOUR 9 
#define START_TIME_SIMULATION START_HOUR * HOUR
#define END_TIME_SIMULATION 22 * HOUR
#define OPENING_TIME 10 * HOUR
#define CLOSING_TIME 21 * HOUR
#define SALE_TIME 17.0
#define LAST_ENTRY_TIME 19.5
#define SIM_HOURS (int)(END_TIME_SIMULATION - START_TIME_SIMULATION) / 60

// Summer weekday - visitor arrivals
static const double SUMMER_WEEKDAY[16] = {
    300, 700,        // 9-10 
    200, 220, 190,  // 11-13 
    190, 190, 130,  // 14-16 
    480, 190, 50,  // 17-19 
    0, 0, 0, 0      // 20-23 
};  

// Summer weekend - visitor arrivals
static const double SUMMER_WEEKEND[16] = {
    300, 600,       // 9-10 
    200, 250, 250,  // 11-13 
    250, 200, 130,  // 14-16
    600, 360, 240,  // 17-19 
    0, 0, 0, 0      // 20-23 
};  

// Regular weekday (winter) - visitor arrivals
static const double DEFAULT_WEEKDAY[16] = {
    100, 300,        // 9-10 
    150, 150, 150,  // 11-13 
    150, 150, 65,    // 14-16 
    240, 145, 95,   // 17-19 
    0, 0, 0, 0      // 20-23
}; 

// Regular weekend (winter) - visitor arrivals
static const double DEFAULT_WEEKEND[16] = {
    550, 950,        // 9-10 
    650, 550, 350,  // 11-13 
    300, 200, 200,  // 14-16 
    350, 50, 30,  // 17-19 
    0, 0, 0, 0      // 20-23
};  
#endif