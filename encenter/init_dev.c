/*
 * init_dev.c
 *
 *  Created on: 21.06.2013
 *      Author: V.Pavlov
 */


#include "init_dev.h"








void I2C_Mems_Write_Reg(unsigned int reg, unsigned int data)
{

         unsigned int i;

                while (UCB0CTL1 & UCTXSTP);             // Ensure stop condition got sent
                    UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition

                    while(!(UCB0IFG & UCTXIFG));    // wait TXFLAG

                    UCB0TXBUF = reg;


             for(i=0;i<50;i++);

                   while (UCB0CTL1 & UCTXSTT);  // wait ACK

                    UCB0TXBUF = data;

                        while (UCB0CTL1 & UCTXSTT);  // wait ACK
                        UCB0CTL1 |= UCTXSTP;         // stop condition


}


unsigned int I2C_Mems_Read_Reg(unsigned int reg)
{

            unsigned int  RXData;



            while (UCB0CTL1 & UCTXSTP);             // Ensure stop condition got sent
            UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition

            RXData =  UCB0RXBUF;  // clean the buffer

            while(!(UCB0IFG & UCTXIFG));    // wait TXFLAG
            UCB0TXBUF = reg;


            while (UCB0CTL1 & UCTXSTT);  // wait ACK

            UCB0CTL1 &= ~UCTR;                          // I2C RX
            UCB0CTL1 |= UCTXSTT;                        // I2C start condition


            while(!(UCB0IFG & UCRXIFG));   //  wait RXFLAG
            RXData = UCB0RXBUF;

            while (UCB0CTL1 & UCTXSTT);  // wait ACK
                UCB0CTL1 |= UCTXSTP;         // stop condition


            return  RXData;

}

void I2C_LIS3DH_Init(void)
{
                 CS_LIS3DH_ON;
                  UCB0CTL1 |= UCSWRST;                      // Enable SW reset
                  UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;     // I2C Master, synchronous mode,
                  UCB0CTL1 = UCSSEL_2  + UCSWRST; // Use SMCLK, keep SW reset + UCTR
                  UCB0STAT = 0x00;
                  UCB0BR0 = 12;                             // fSCL = SMCLK/12 = ~100kHz
                  UCB0BR1 = 0;
                  UCB0I2CSA = LIS3DH_ADDR;                  // Slave Address is 018h
                  UCB0I2COA = 0x01A5;                       // own address.
                  P1SEL |= UCB0SDA + UCB0SCL;
                  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
                //  UCB0IE |= UCTXIE + UCRXIE + UCNACKIFG;                // Enable TX and RX interrupt

}

void I2C_M24C64_Init(void)
{

                  CS_LIS3DH_OFF;
                  UCB0CTL1 |= UCSWRST;                      // Enable SW reset
                  UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;     // I2C Master, synchronous mode,
                  UCB0CTL1 = UCSSEL_2 /*+ UCTR*/ + UCSWRST; // Use SMCLK, keep SW reset
                  UCB0STAT = 0x00;
                  UCB0BR0 = 12;                             // fSCL = SMCLK/12 = ~100kHz
                  UCB0BR1 = 0;
                  UCB0I2CSA = M24C64_ADDR;                  // Slave Address is 018h
                  UCB0I2COA = 0x01A5;                       // own address.
                  P1SEL |= UCB0SDA + UCB0SCL;
                  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
                //  UCB0IE |= UCTXIE + UCRXIE + UCNACKIFG;                // Enable TX and RX interrupt

}

void LIS3DH_Config(void){

            I2C_Mems_Write_Reg(LIS3DH_CTRL_REG1, LIS3DHODR100Hz+LIS3DH_ZEN+LIS3DH_YEN+LIS3DH_XEN+LIS3DH_LPEN); //+LIS3DH_ZEN++ LIS3DH_ODR_25Hz

                            I2C_Mems_Write_Reg(LIS3DH_CTRL_REG2,0xc1);   //I2C_Mems_Write_Reg(LIS3DH_CTRL_REG2,0x00);  0xF1
                            I2C_Mems_Write_Reg(LIS3DH_CTRL_REG3,0x40);
                            I2C_Mems_Write_Reg(LIS3DH_CTRL_REG4,0x00);
                            I2C_Mems_Write_Reg(LIS3DH_CTRL_REG5,0x08);//0x08
                            I2C_Mems_Write_Reg(LIS3DH_INT_THS,0x02);                 // 0x03
                            I2C_Mems_Write_Reg(LIS3DH_INT1_DURATION,0x0d);           // 0x06  0x0d
                            I2C_Mems_Write_Reg(LIS3DH_INT1_CFG,0x20);//0x20
}





void LIS3DH_Start(void)
{
	for(k = 0; k<1000;k++);
	 LIS_INT1_INIT;
		 I2C_LIS3DH_Init();

	    LIS3DH_Config();


}





