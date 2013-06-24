/*
 * rf1aSettings.h
 *
 *  Created on: 24.06.2013
 *      Author: V.Pavlov
 */

/* Deviation = 5.157471 */
/* Base frequency = 867.999939 */
/* Carrier frequency = 867.999939 */
/* Channel number = 0 */
/* Carrier frequency = 867.999939 */
/* Modulated = true */
/* Modulation format = 2-GFSK */
/* Manchester enable = false */
/* Sync word qualifier mode = 30/32 sync word bits detected */
/* Preamble count = 4 */
/* Channel spacing = 199.951172 */
/* Carrier frequency = 867.999939 */
/* Data rate = 1.19948 */
/* RX filter BW = 58.035714 */
/* Data format = Normal mode */
/* CRC enable = true */
/* Device address = 0 */
/* Address config = No address check */
/* CRC autoflush = false */
/* PA ramping = false */
/* TX power = 0 */
/* RF settings SoC */
/***************************************************************
 *  SmartRF Studio(tm) Export
 *
 *  Radio register settings specifed with C-code
 *  compatible #define statements.
 *
 ***************************************************************/



#define SMARTRF_RADIO_CC430

#define SMARTRF_SETTING_IOCFG2        0x29  // RF_RDYn
#define SMARTRF_SETTING_IOCFG1        0x1E  // IOCFG1: GDO1 signals on RSSI_VALID
#define SMARTRF_SETTING_IOCFG0        0x06  // Asserts when sync word has been sent or received, and deasserts at the end of the packet
#define SMARTRF_SETTING_FIFOTHR       0x48
#define SMARTRF_SETTING_SYNC1         0xD3  // 8 MSB of 16-bit sync word
#define SMARTRF_SETTING_SYNC0         0x91  // 8 LSB of 16-bit sync word
#define SMARTRF_SETTING_PKTLEN        0x15 //0xFF  //  If variable packet length mode is used, this value indicates the maximum packet length allowed

#define SMARTRF_SETTING_PKTCTRL1      0x04 // two status bytes are appended to the payload of the packet. The status bytes contain RSSI and LQI

#define SMARTRF_SETTING_PKTCTRL0      0x05  // 1: CRC calculation in TX and CRC check in RX enabled
                                            // Variable packet length mode. Packet length configured by the first byte after sync word

#define SMARTRF_SETTING_ADDR          0x00  //
#define SMARTRF_SETTING_CHANNR        0x00
#define SMARTRF_SETTING_FSCTRL1       0x06
#define SMARTRF_SETTING_FSCTRL0       0x00
#define SMARTRF_SETTING_FREQ2         0x21
#define SMARTRF_SETTING_FREQ1         0x62
#define SMARTRF_SETTING_FREQ0         0x76
#define SMARTRF_SETTING_MDMCFG4       0xF5
#define SMARTRF_SETTING_MDMCFG3       0x83
#define SMARTRF_SETTING_MDMCFG2       0x13   //   - 30/32 sync word bits detected
#define SMARTRF_SETTING_MDMCFG1       0x22   //    -  4   Number of Preamble Bytes
#define SMARTRF_SETTING_MDMCFG0       0xF8   //
#define SMARTRF_SETTING_DEVIATN       0x15


#define SMARTRF_SETTING_MCSM2         0x07 //
#define SMARTRF_SETTING_MCSM1         0x30 //
#define SMARTRF_SETTING_MCSM0         0x11 //


#define SMARTRF_SETTING_FOCCFG        0x16
#define SMARTRF_SETTING_BSCFG         0x6C
#define SMARTRF_SETTING_AGCCTRL2      0x03      //0x03
#define SMARTRF_SETTING_AGCCTRL1      0x40
#define SMARTRF_SETTING_AGCCTRL0      0x91

#define SMARTRF_SETTING_WOREVT1       0x80 //
#define SMARTRF_SETTING_WOREVT0       0x00 //
#define SMARTRF_SETTING_WORCTRL       0xfb     //0x80 //  Tevent1 = 0.122 ms   WOR_RES = 0(max timeout = 2 s)
                                           //
#define SMARTRF_SETTING_FREND1        0x56
#define SMARTRF_SETTING_FREND0        0x10
#define SMARTRF_SETTING_FSCAL3        0xE9
#define SMARTRF_SETTING_FSCAL2        0x2A
#define SMARTRF_SETTING_FSCAL1        0x00
#define SMARTRF_SETTING_FSCAL0        0x1F
#define SMARTRF_SETTING_FSTEST        0x59
#define SMARTRF_SETTING_PTEST         0x7F
#define SMARTRF_SETTING_AGCTEST       0x3F
#define SMARTRF_SETTING_TEST2         0x81
#define SMARTRF_SETTING_TEST1         0x35
#define SMARTRF_SETTING_TEST0         0x09
#define SMARTRF_SETTING_PARTNUM       0x00
#define SMARTRF_SETTING_VERSION       0x06
#define SMARTRF_SETTING_FREQEST       0x00
#define SMARTRF_SETTING_LQI           0x00
#define SMARTRF_SETTING_RSSI          0x00
#define SMARTRF_SETTING_MARCSTATE     0x00
#define SMARTRF_SETTING_WORTIME1      0x00
#define SMARTRF_SETTING_WORTIME0      0x00
#define SMARTRF_SETTING_PKTSTATUS     0x00
#define SMARTRF_SETTING_VCO_VC_DAC    0x00
#define SMARTRF_SETTING_TXBYTES       0x00
#define SMARTRF_SETTING_RXBYTES       0x00
#define SMARTRF_SETTING_RF1AIFCTL0    0x00
#define SMARTRF_SETTING_RF1AIFCTL1    0x00
#define SMARTRF_SETTING_RF1AIFCTL2    0x00
#define SMARTRF_SETTING_RF1AIFERR     0x00
#define SMARTRF_SETTING_RF1AIFERRV    0x00
#define SMARTRF_SETTING_RF1AIFIV      0x00
#define SMARTRF_SETTING_RF1AINSTRW    0x00
#define SMARTRF_SETTING_RF1AINSTR1W   0x00
#define SMARTRF_SETTING_RF1AINSTR2W   0x00
#define SMARTRF_SETTING_RF1ADINW      0x00
#define SMARTRF_SETTING_RF1ASTAT0W    0x00
#define SMARTRF_SETTING_RF1ASTAT1W    0x00
#define SMARTRF_SETTING_RF1ASTAT2W    0x00
#define SMARTRF_SETTING_RF1ADOUT0W    0x00
#define SMARTRF_SETTING_RF1ADOUT1W    0x00
#define SMARTRF_SETTING_RF1ADOUT2W    0x00
#define SMARTRF_SETTING_RF1AIN        0x00
#define SMARTRF_SETTING_RF1AIFG       0x00
#define SMARTRF_SETTING_RF1AIES       0x00
#define SMARTRF_SETTING_RF1AIE        0x00
#define SMARTRF_SETTING_RF1AIV        0x00
#define SMARTRF_SETTING_RF1ARXFIFO    0x00
#define SMARTRF_SETTING_RF1ATXFIFO    0x00
