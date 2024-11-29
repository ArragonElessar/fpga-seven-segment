#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

#include <stdint.h>
#include "xil_io.h"

#define SS_ZERO  0b11000000  // Segments A, B, C, D, E, F
#define SS_ONE   0b11111001  // Segments B, C
#define SS_TWO   0b10100100  // Segments A, B, D, E, G
#define SS_THREE 0b10110000  // Segments A, B, C, D, G
#define SS_FOUR  0b10011001  // Segments B, C, F, G
#define SS_FIVE  0b10010010  // Segments A, C, D, F, G
#define SS_SIX   0b10000010  // Segments A, C, D, E, F, G
#define SS_SEVEN 0b11111000  // Segments A, B, C
#define SS_EIGHT 0b10000000  // All segments
#define SS_NINE  0b10010000  // Segments A, B, C, D, F, G


// Function prototypes
uint8_t getSevenSegmentValue(int digit);
void displaySevenSegment(int val, int mseconds, UINTPTR ss_anode_base_addr, UINTPTR ss_cathode_base_addr);

// Base address for Cathodes (data) and Anodes 

#endif


