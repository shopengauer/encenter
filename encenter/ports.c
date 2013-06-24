/*
 * ports.c
 *
 *  Created on: 24.06.2013
 *      Author: V.Pavlov
 */

#include "ports.h"



void PORT_Init(void)
{

	   P1DIR = 0x1c; // Led out
	   P1OUT = 0x1c;

	   PJOUT = 0x00;////////////////////////0x00
	   PJDIR = 0xff;//////////////////////// 0xff

	   P2SEL = 0x00;
	   P2OUT = 0x08;
	   P2DIR = 0xff;
	   P2REN = 0x00;


	   P3DIR = 0x00;
	   P3OUT = 0xff;

	  // P5SEL = 0x03;
	 //  P5DIR = 0x03;
	 //  P3OUT = 0x00;


	   // PMMCTL0_H = 0xA5;
	   //   SVSMHCTL = 0;
	   //   SVSMLCTL = 0;
	   //   PMMCTL0_H = 0x00;

	      P5SEL |= 0x03;                            // Port select XT1

}


#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
	int Inner0;

  switch(__even_in_range(P1IV, 16))
  {
    case  0: break;
    case  2:

              Inner0 = I2C_Mems_Read_Reg(LIS3DH_INT1_SRC);
              I2C_Mems_Write_Reg(LIS3DH_INT1_CFG,0x20);
              redLED1TOGG;
              p++;

        break;                         // P2.0 IFG
    case  4: break;                         // P2.1 IFG

    case  6: break;                         // P2.2 IFG
    case  8: break;                         // P2.3 IFG
    case 10: break;                         // P2.4 IFG
    case 12: break;                         // P2.5 IFG
    case 14: break;                         // P2.6 IFG
    case 16: break;                         // P2.7 IFG

  }
}










