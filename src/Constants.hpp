#ifndef CONSTANTS_H
#define CONSTANTS_H

#define HOUR 60.0
#define MINUTE 1

// Probabilities
#define SUMMER_ENTRY_PROB 0.25  // Probablity of visitor entry through the summer entrance

// More people with online ticket
#define ONLINE_TICKET_PROB 0.6 // Probability of visitor having an online ticket

// Capacities
#define SUMMER_CAPACITY 6500  // System capacity in summer mode
#define DEFAULT_CAPACITY 3000 // Default system capacity (outside of summer mode)

// Register capacities
#define SUMMER_ENTRY_REGISTER_CNT 3 // Number of registers at the summer entry
#define SUMMER_ENTRY_SMART_CNT 3    // Number of smart register at the summer entry
#define MAIN_ENTRY_SMART_CNT 8      // Number of smart registers at the main entry
#define MAIN_ENTRY_REGISTER_CNT 6   // Number of registers at main entry

// Register times in minutes
#define ENTRY_REGISTER_TIME 0.7     // Average time at a register
#define ENTRY_SMART_TIME 0.5        // Average time at the smart register

// Visitor stay time coefficients
#define SUMMER_STAY 7 * HOUR    
#define DEFAULT_WEEKEND_STAY 6 * HOUR  
#define DEFAULT_STAY 5 * HOUR  

// Summer gamma distribution values
#define SUMMER_GAMMA_ALPHA 10        // Alpha value of gamma distribution for summer mode
#define SUMMER_GAMMA_BETA \
	SUMMER_STAY / SUMMER_GAMMA_ALPHA // Beta value of gamma distribution for summer mode

// Normal day gamma distribution values
#define DEFAULT_GAMMA_ALPHA 10      // Alpha value of gamma distribution outside of summer mode
#define DEFAULT_GAMMA_BETA \
	DEFAULT_STAY / DEFAULT_GAMMA_ALPHA // Beta value of gamma distribution outside of summer mode

// Weekend gamma distribution values
#define DEFAULT_WEEKEND_GAMMA_ALPHA 15        // Alpha value of gamma distribution for weekend
#define DEFAULT_WEEKEND_GAMMA_BETA \
    DEFAULT_WEEKEND_STAY / DEFAULT_WEEKEND_GAMMA_ALPHA  // Beta value of gamma distribution for weekend

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
#define LAST_ENTRY_TIME 19.5 * HOUR
#define SIM_HOURS (int)(END_TIME_SIMULATION - START_TIME_SIMULATION) / 60

// Summer weekday - visitor arrivals
static const double SUMMER_WEEKDAY[16] = {
    380, 550,        // 9-10
    290, 210, 210,   // 11-13
    170, 170, 170,   // 14-16
    290, 40, 30,     // 17-19
    0, 0, 0, 0       // 20-23
};

// Summer weekend - visitor arrivals
static const double SUMMER_WEEKEND[16] = {
    1500, 1900,        // 9-10 
    850, 450, 400,    // 11-13 
    400, 250, 150,    // 14-16 
    300, 100, 60,     // 17-19 
    0, 0, 0, 0        // 20-23
};  

// Regular weekday (winter) - visitor arrivals
static const double DEFAULT_WEEKDAY[16] = {
    100, 250,        // 9-10 
    190, 180, 170,  // 11-13 
    160, 150, 100,    // 14-16 
    150, 50, 30,   // 17-19 
    0, 0, 0, 0      // 20-23
}; 

// Regular weekend (winter) - visitor arrivals
static const double DEFAULT_WEEKEND[16] = {
    450, 650,        // 9-10 
    350, 250, 250,  // 11-13 
    200, 200, 200,  // 14-16 
    350, 50, 30,  // 17-19 
    0, 0, 0, 0      // 20-23
};  
#endif