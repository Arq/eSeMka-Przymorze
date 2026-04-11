#include "myAliases.h"
#include "myDevices.h"
//#include "myAutomation_Selftest.h"
#include "myAutomation_CV_PGM.h"


/* This is an automation 
 *  
 */
 		
// Macro to flash a signal's amber aspect - assumes amber is the next vpin from the red vpin
#define FLASHAMBER(signal) \
  AMBER(signal) \
  BLINK(signal+1,500,500)

AUTOSTART
POWERON         // turn on track power
    DELAY(1000) // delay required after Power ON
    // LCD(0, "16x2 LCD Display") // Display message on LCD
    // SCREEN(DSP_MAIN, 0, " Hello ") // Display message on OLED
    // SCREEN(DSP_MAIN, 1, "--------------------")
    CALL(PROC_PGM_CLOSE)
    CALL(PROC_01)
    SETLOCO(1022)   // select some loco to enable
    FWD(10)
    CALL(PROC_RESET)
DONE // This just ends the startup thread, leaving 2 others running.

// signals on i2c expanders have to be initialized so others also
SEQUENCE(PROC_RESET)
    CLOSE(TRN_01)
    CLOSE(TRN_05)
    CLOSE(TRN_06)
    CLOSE(TRN_07)
    CLOSE(TRN_08)
    CLOSE(TRN_09)
    CLOSE(TRN_13)
    CLOSE(TRN_14)
    CLOSE(TRN_15)
    CLOSE(TRN_16)
    CLOSE(TRN_17)
    CLOSE(TRN_21)
    CLOSE(TRN_22)
RETURN


ROUTE(RT_01, "Tor_2-A Stop")
    CALL(PROC_01)
DONE

SEQUENCE(PROC_01)
    RED(SH1)
    CLOSE(TRN_01)
    ROUTE_ACTIVE(RT_01)
    ROUTE_INACTIVE(RT_02)
RETURN

ROUTE(RT_02, "Tor_2-A GO")
    GREEN(SH1)
    THROW(TRN_01)
    ROUTE_ACTIVE(RT_02)
    ROUTE_INACTIVE(RT_01)
DONE


