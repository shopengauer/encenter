/*
 * signal.h
 *
 *  Created on: 24.06.2013
 *      Author: V.Pavlov
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_

//#include "cc430x513x.h"
//void TIMER0_A0_INIT(unsigned int);
//void TIMER0_A1_INIT(unsigned int);
//void TIMER1_A0_INIT(unsigned int);
//void TIMER1_A1_INIT(unsigned int);

//const unsigned char TxBuffer[22]= {0x15, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xAA, 0xBB, 0xCC,
//0xDD, 0xEE, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xDD};
//const unsigned char TxBuffer[21]= {0x15, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E,0x3A, 0x3B, 0x3C, 0x3D, 0x3E };


 #define  bitrate_1200



//           32 byte  =  212ms                                32 byte  =  212ms      180ms    32 byte  =  212ms
//___________/^^^^^^^^^^^^^^^\________                 ________/^^^^^^^^^^^^^^^^\_____________/^^^^^^^^^^^^^^^\_______________
//
//                                                                             16 byte = 106 ms
//____________/^\________/^\_________/^^^^^^\                    __________________/^^^^^^^\__________/^\__________________________
//             2ms       2ms

//           Tcca        Tcca


#define      RDC     0  // Radiio duty cycling
#define      TRANS   1  // Transmiting the packets
#define      END_WAIT_AFTER_CARRERSENSE  2  //


#define    RDC_CARRERSENSE_1       0
#define    RDC_LITTLE_TIMEOUT      1
#define    RDC_CARRERSENSE_2       2
#define    RDC_BIG_TIMEOUT         3

#define  bitrate_38400


#ifdef bitrate_1200

/* ContikiMAC performs periodic channel checks. Each channel check
   consists of two or more CCA checks. CCA_COUNT_MAX is the number of
   CCAs to be done for each periodic channel check. The default is
   two.*/
#define CCA_COUNT_MAX                       2

 /* CCA_CHECK_TIME is the time it takes to perform a CCA check. */
#define CCA_CHECK_TIME                10//     Tcca  2ms

 /* CCA_SLEEP_TIME is the time between two successive CCA checks. */
#define CCA_SLEEP_TIME                 6553 // Tc 200 ms

 /* CHECK_TIME is the total time it takes to perform CCA_COUNT_MAX
    CCAs. */
#define CHECK_TIME                         (CCA_COUNT_MAX * (CCA_CHECK_TIME + CCA_SLEEP_TIME))

 /* LISTEN_TIME_AFTER_PACKET_DETECTED is the time that we keep checking
    for activity after a potential packet has been detected by a CCA
    check. */
#define LISTEN_TIME_AFTER_PACKET_DETECTED  32768  // 1 s

 /* MAX_SILENCE_PERIODS is the maximum amount of periods (a period is
    CCA_CHECK_TIME + CCA_SLEEP_TIME) that we allow to be silent before
    we turn of the radio. */
#define MAX_SILENCE_PERIODS                5

 /* MAX_NONACTIVITY_PERIODS is the maximum number of periods we allow
    the radio to be turned on without any packet being received, when
    WITH_FAST_SLEEP is enabled. */
#define MAX_NONACTIVITY_PERIODS            10



 /* STROBE_TIME is the maximum amount of time a transmitted packet
    should be repeatedly transmitted as part of a transmission. */
#define STROBE_TIME                        (CYCLE_TIME + 2 * CHECK_TIME)

 /* GUARD_TIME is the time before the expected phase of a neighbor that
    a transmitted should begin transmitting packets. */
#define GUARD_TIME                         11 * CHECK_TIME

 /* INTER_PACKET_INTERVAL is the interval between two successive packet transmissions */
#define INTER_PACKET_INTERVAL        6500//      5898 //     32768*0.18 s   Ti

 /* AFTER_ACK_DETECTECT_WAIT_TIME is the time to wait after a potential
    ACK packet has been detected until we can read it out from the
    radio. */
#define AFTER_ACK_DETECTECT_WAIT_TIME      RTIMER_ARCH_SECOND / 1500

 /* MAX_PHASE_STROBE_TIME is the time that we transmit repeated packets
    to a neighbor for which we have a phase lock. */
#define MAX_PHASE_STROBE_TIME              RTIMER_ARCH_SECOND / 60


 /* SHORTEST_PACKET_SIZE is the shortest packet that ContikiMAC
    allows. Packets have to be a certain size to be able to be detected
    by two consecutive CCA checks, and here is where we define this
    shortest size. */
#define SHORTEST_PACKET_SIZE               6946 // 212 ms

#define MAX_REICIVE_TIME_AFTERCARRERSENSE       32768 // 1s

 /* The cycle time for announcements. */
 #ifdef ANNOUNCEMENT_CONF_PERIOD
 #define ANNOUNCEMENT_PERIOD ANNOUNCEMENT_CONF_PERIOD
 #else /* ANNOUNCEMENT_CONF_PERIOD */
 #define ANNOUNCEMENT_PERIOD 1 * CLOCK_SECOND
 #endif /* ANNOUNCEMENT_CONF_PERIOD */

 /* The time before sending an announcement within one announcement
    cycle. */
#define ANNOUNCEMENT_TIME (random_rand() % (ANNOUNCEMENT_PERIOD))


#define ACK_LEN 3

#elif defined bitrate_38400

/* ContikiMAC performs periodic channel checks. Each channel check
   consists of two or more CCA checks. CCA_COUNT_MAX is the number of
   CCAs to be done for each periodic channel check. The default is
   two.*/
#define CCA_COUNT_MAX                      2

 /* CCA_CHECK_TIME is the time it takes to perform a CCA check. */
#define CCA_CHECK_TIME                10//     RTIMER_ARCH_SECOND / 8192

 /* CCA_SLEEP_TIME is the time between two successive CCA checks. */
#define CCA_SLEEP_TIME                 3100 //    RTIMER_ARCH_SECOND / 2000

 /* CHECK_TIME is the total time it takes to perform CCA_COUNT_MAX
    CCAs. */
#define CHECK_TIME                         (CCA_COUNT_MAX * (CCA_CHECK_TIME + CCA_SLEEP_TIME))

 /* LISTEN_TIME_AFTER_PACKET_DETECTED is the time that we keep checking
    for activity after a potential packet has been detected by a CCA
    check. */
#define LISTEN_TIME_AFTER_PACKET_DETECTED  CCA_CHECK_TIME*100

 /* MAX_SILENCE_PERIODS is the maximum amount of periods (a period is
    CCA_CHECK_TIME + CCA_SLEEP_TIME) that we allow to be silent before
    we turn of the radio. */
#define MAX_SILENCE_PERIODS                5

 /* MAX_NONACTIVITY_PERIODS is the maximum number of periods we allow
    the radio to be turned on without any packet being received, when
    WITH_FAST_SLEEP is enabled. */
#define MAX_NONACTIVITY_PERIODS            10



 /* STROBE_TIME is the maximum amount of time a transmitted packet
    should be repeatedly transmitted as part of a transmission. */
#define STROBE_TIME                        (CYCLE_TIME + 2 * CHECK_TIME)

 /* GUARD_TIME is the time before the expected phase of a neighbor that
    a transmitted should begin transmitting packets. */
#define GUARD_TIME                         11 * CHECK_TIME

 /* INTER_PACKET_INTERVAL is the interval between two successive packet transmissions */
#define INTER_PACKET_INTERVAL              RTIMER_ARCH_SECOND / 5000

 /* AFTER_ACK_DETECTECT_WAIT_TIME is the time to wait after a potential
    ACK packet has been detected until we can read it out from the
    radio. */
#define AFTER_ACK_DETECTECT_WAIT_TIME      RTIMER_ARCH_SECOND / 1500

 /* MAX_PHASE_STROBE_TIME is the time that we transmit repeated packets
    to a neighbor for which we have a phase lock. */
#define MAX_PHASE_STROBE_TIME              RTIMER_ARCH_SECOND / 60


 /* SHORTEST_PACKET_SIZE is the shortest packet that ContikiMAC
    allows. Packets have to be a certain size to be able to be detected
    by two consecutive CCA checks, and here is where we define this
    shortest size. */
#define SHORTEST_PACKET_SIZE               43



 /* The cycle time for announcements. */
 #ifdef ANNOUNCEMENT_CONF_PERIOD
 #define ANNOUNCEMENT_PERIOD ANNOUNCEMENT_CONF_PERIOD
 #else /* ANNOUNCEMENT_CONF_PERIOD */
 #define ANNOUNCEMENT_PERIOD 1 * CLOCK_SECOND
 #endif /* ANNOUNCEMENT_CONF_PERIOD */

 /* The time before sending an announcement within one announcement
    cycle. */
#define ANNOUNCEMENT_TIME (random_rand() % (ANNOUNCEMENT_PERIOD))


#define ACK_LEN 3

#endif

#endif /* SIGNAL_H_ */
