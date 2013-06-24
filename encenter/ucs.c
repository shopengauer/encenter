/*
 * ucs.c
 *
 *  Created on: 24.06.2013
 *      Author: V.Pavlov
 */


#include "ucs.h"

void UCS_Init(void)
{

    UCSCTL6 |= SMCLKOFF;
    UCSCTL6 |= XCAP_3;                        // Internal load cap
    // UCSCTL6 &= ~XT2OFF;                       // Turn on XT2 even if RF core in SLEEP
    UCSCTL6 &= ~XT1OFF;
    UCSCTL6 &= ~XT1DRIVE_3;

   // Loop until XT1,XT2 & DCO stabilizes
     do
     {
       UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
                                               // Clear XT2,XT1,DCO fault flags
       SFRIFG1 &= ~OFIFG;                      // Clear fault flags
     }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

     // Select SMCLK, ACLK source and DCO source
     UCSCTL4 = SELA__XT1CLK + SELS__DCOCLKDIV + SELM__DCOCLKDIV;

}
