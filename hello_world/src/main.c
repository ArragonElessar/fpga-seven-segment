/******************************************************************************
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include "platform.h"
#include "xparameters.h"
#include "seven_segment.h"


#define SEVEN_SEG_ANODE_BA XPAR_AXI_GPIO_0_BASEADDR
#define SEVEN_SEG_DATA_BA XPAR_AXI_GPIO_1_BASEADDR
#define PUSH_BUTTON_BA XPAR_AXI_GPIO_2_BASEADDR


int main()
{
    init_platform();
    
    for(int i = 0; i < 100; i++){
        displaySevenSegment(i, 250, SEVEN_SEG_ANODE_BA, SEVEN_SEG_DATA_BA);
    }
    
    cleanup_platform();
    return 0;
}
