/*
 * main.c
 */

#include "cc430x513x.h"
//#include "init_dev.c"


void main(void)
{

	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

	 SetVCore(2);
	 //PMMCTL0_H = 0xA5;
	// PMMCTL0_L |= PMMHPMRE_L;
	// PMMCTL0_H = 0x00;
	 PORT_Init();
//	 UCS_Init();
	 LIS3DH_Start();

	//SetVCore(2);



	    __bis_SR_register(GIE);//+
	    __bis_SR_register(LPM3);

	  while (1);

	
}


