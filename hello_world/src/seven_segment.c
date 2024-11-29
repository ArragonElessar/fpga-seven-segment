#include "seven_segment.h"
#include <stdio.h>
#include <unistd.h>
#include <xil_types.h>

uint8_t getSevenSegmentValue(int digit) {
    // Use #defined values for digits 0-9, -1 for clearing an anode
    switch (digit) {
        case 0: return SS_ZERO;
        case 1: return SS_ONE;
        case 2: return SS_TWO;
        case 3: return SS_THREE;
        case 4: return SS_FOUR;
        case 5: return SS_FIVE;
        case 6: return SS_SIX;
        case 7: return SS_SEVEN;
        case 8: return SS_EIGHT;
        case 9: return SS_NINE;
        default:
            printf("Error: Invalid digit. Enter a number between 0 and 9.\n");
            return 0xFF; // Return a value that indicates an error
    }
}

void displaySevenSegment(int val, int mseconds, UINTPTR ss_anode_base_addr, UINTPTR ss_cathode_base_addr) {
    if (val < 0 || val > 9999) {
        xil_printf("\n[ERROR] Cannot display %d since only 4-digit non-zero numbers are allowed.\n", val);
        return;
    }

    if (mseconds < 4) {
        xil_printf("\n[ERROR] Cannot display %d for less than %d microseconds.\n", val, mseconds);
        return;
    }

    xil_printf("\nPrinting %d on 7-segment display.", val);
    

    uint8_t anode[4] = {0x01, 0x02, 0x04, 0x08}; // thousands, hundreds, tens, ones - anode selectors
    int digit[4] = {0, 0, 0, 0};

    digit[3] = val % 10;         // Extract the ones digit
    digit[2] = (val / 10) % 10;  // Extract the tens digit
    digit[1] = (val / 100) % 10; // Extract the hundreds digit
    digit[0] = (val / 1000);     // Extract the thousands digit

    // Display the digits[i]th value on anode[i] -> this segment should use 4ms
    for (int t = 0; t < mseconds / 4; t++) {
        for (int i = 0; i < 4; i++) {
            // Select the anode
            Xil_Out8(ss_anode_base_addr, anode[i]);
            // Set the cathodes
            Xil_Out8(ss_cathode_base_addr, getSevenSegmentValue(digit[i]));

            usleep(1000);
        }
    }

    // Shut down all the segments for all anodes
    Xil_Out8(ss_anode_base_addr, 0x00);
}
