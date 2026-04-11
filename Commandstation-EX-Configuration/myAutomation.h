#include "myAliases.h"
#include "myDevices.h"
//#include "myAutomation_Selftest.h"
#include "myAutomation_CV_PGM.h"
#include "myAutomation_CP_Przymorze.h"

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
    CALL(PROC_RESET_CP)
DONE // This just ends the startup thread, leaving 2 others running.

// reset Turnouts and signals
SEQUENCE(PROC_RESET)
    CLOSE(TRN_01)
    CLOSE(TRN_05)
    CLOSE(TRN_06)
    CLOSE(TRN_07)
    CLOSE(TRN_08)
    CLOSE(TRN_21)
    CLOSE(TRN_22a)
    CLOSE(TRN_22b)
    CLOSE(TRN_25)
    CLOSE(TRN_24)
    CLOSE(TRN_26)
    CLOSE(TRN_23)
    CLOSE(TRN_30)
RETURN


// reset dashboard (control panel) signals using i2c expanders 
SEQUENCE(PROC_RESET_CP)
    
    // SH_B
    //GREEN(CP_SH_B_SB) 
    RED(CP_SH_B_SB) 
    //AMBER(CP_SH_B_SB)  
    GREEN(CP_SH_B_SE) // off
    //REF(CP_SH_B_SE) //white
    //AMBER(CP_SH_B_SE) // amber2 
    SET(CP_SH_B_L,2)    //OFF
    // RED(CP_SH_B_L)  // red
    SET(CP_SH_B_R,2)    //OFF
    //AMBER(CP_SH_B_R)  // route

    //  SH_A    
    RED(CP_SH_A_SB)    //red
    //RED(CP_SH_A_SE)  //white
    GREEN(CP_SH_A_SE)   // off
    SET(CP_SH_A_L,2)    //OFF
    //RED(CP_SH_A_L)    //occupied
     //AMBER(CP_SH_A_L) // route
    SET(CP_SH_A_R,2)    //OFF
    //REF(CP_SH_A_R)    //occupied
    //AMBER(CP_SH_A_R)  //route

    //  SH_2
    RED(CP_SH_2_SS)  // blue
    //GREEN(CP_SH_2_SS)  //shunt signal  off
    SET(CP_SH_2_L,2)    //OFF
    SET(CP_SH_2_R,2)    //OFF
  
     //  SH_1
    RED(CP_SH_1_SS)  
    SET(CP_SH_1_L,2)    //OFF
    SET(CP_SH_1_R,2)    //OFF

    SET(CP_TN_1_L,2)    //OFF
    SET(CP_TN_1_R,2)    //OFF 
    SET(CP_TN_2_L,2)    //OFF
    SET(CP_TN_2_R,2)    //OFF 
    CLOSE(CP_TN_2_TRN)   //(Weinert)

    //  SH_4
    RED(CP_SH_4_SS)  
    SET(CP_SH_4_L,2)    //OFF
    SET(CP_SH_4_R,2)    //OFF
    //  SH_3
    RED(CP_SH_3_SS)  
    SET(CP_SH_3_L,2)    //OFF
    SET(CP_SH_3_R,2)    //OFF

    SET(CP_TN_6_L,2)    //OFF
    SET(CP_TN_6_R,2)    //OFF
    //RESET(CP_TN_6_L,2)  // CLOSED  lit On
    //SET(CP_TN_6_THROWN,2)   // TRHOWN
    SET(CP_TN_6_OCC)   //it  doesnt work  use SENSOR
    CLOSE(CP_TN_6_TRN)
    
    SET(CP_TN_5_L,2)    //OFF
    SET(CP_TN_5_R,2)    //OFF 
    CLOSE(CP_TN_5_TRN)

    SET(CP_TN_8_L,2)    //OFF
    SET(CP_TN_8_R,2)    //OFF
    CLOSE(CP_TN_8_TRN)

    SET(CP_TN_7_L,2)    //OFF
    SET(CP_TN_7_R,4)    //OFF !exceptional 
    CLOSE(CP_TN_7_TRN)

    // SH_D1
    RED(CP_SH_D1_SB) 
    GREEN(CP_SH_D1_SE)   //OFF
    SET(CP_SH_D1_L,2)    //OFF
    SET(CP_SH_D1_R,2)    //OFF

    // SH_D2
    RED(CP_SH_D2_SB) 
    GREEN(CP_SH_D2_SE)   //OFF
    SET(CP_SH_D2_L,2)    //OFF
    SET(CP_SH_D2_R,2)    //OFF

    // SH_D3
    RED(CP_SH_D3_SB) 
    GREEN(CP_SH_D3_SE)   //OFF
    SET(CP_SH_D3_L,2)    //OFF
    SET(CP_SH_D3_R,2)    //OFF

    // SH_D4
    RED(CP_SH_D4_SB) 
    GREEN(CP_SH_D4_SE)   //OFF
    SET(CP_SH_D4_L,2)    //OFF
    SET(CP_SH_D4_R,2)    //OFF

    // SH_12
    RED(CP_SH_12_SS)  // blue
    SET(CP_SH_12_L,2)    //OFF
    SET(CP_SH_12_R,2)    //OFF
  
     //  SH_11
    RED(CP_SH_11_SS)  
    SET(CP_SH_11_L,2)    //OFF
    SET(CP_SH_11_R,2)    //OFF

    // SH_G1
    RED(CP_SH_G1_SB) 
    GREEN(CP_SH_G1_SE)   //OFF
    SET(CP_SH_G1_L,2)    //OFF
    SET(CP_SH_G1_R,2)    //OFF
 
    // SH_G2
    RED(CP_SH_G2_SB) 
    GREEN(CP_SH_G2_SE)   //OFF
    SET(CP_SH_G2_L,2)    //OFF
    SET(CP_SH_G2_R,2)    //OFF

    // SH_G3
    RED(CP_SH_G3_SB) 
    GREEN(CP_SH_G3_SE)   //OFF
    SET(CP_SH_G3_L,2)    //OFF
    SET(CP_SH_G3_R,2)    //OFF

    // SH_G4
    RED(CP_SH_G4_SB) 
    GREEN(CP_SH_G4_SE)   //OFF
    SET(CP_SH_G4_L,2)    //OFF
    SET(CP_SH_G4_R,2)    //OFF


    SET(CP_TN_21_L,2)    //OFF
    SET(CP_TN_21_R,2)    //OFF
    CLOSE(CP_TN_21_TRN)

    SET(CP_TN_22_L,2)    //OFF
    SET(CP_TN_22_R,2)    //OFF
    CLOSE(CP_TN_22_TRN)

    SET(CP_TN_25_L,2)    //OFF
    SET(CP_TN_25_R,2)    //OFF
    CLOSE(CP_TN_25_TRN)

    SET(CP_TN_24_L,2)    //OFF
    SET(CP_TN_24_R,2)    //OFF
    CLOSE(CP_TN_24_TRN)

    CLOSE(CP_TN_27_TRN)  //(Weinert)

    SET(CP_TN_23_L,2)    //OFF
    SET(CP_TN_23_R,2)    //OFF
    CLOSE(CP_TN_23_TRN)
    
    SET(CP_TN_30_L,2)    //OFF
    SET(CP_TN_30_R,2)    //OFF
    //RESET(CP_TN_30_L,2)  // CLOSED  lit On
    //SET(CP_TN_30_THROWN)   // TRHOWN
    SET(CP_TN_30_OCC)   //it  doesnt work  use SENSOR
    CLOSE(CP_TN_30_TRN)
    


    //  SH_17
    RED(CP_SH_17_SS)  
    SET(CP_SH_17_L,2)    //OFF
    SET(CP_SH_17_R,2)    //OFF
    //  SH_16
    RED(CP_SH_16_SS)  
    SET(CP_SH_16_L,2)    //OFF
    SET(CP_SH_16_R,2)    //OFF
    //  SH_15
    RED(CP_SH_15_SS)  
    SET(CP_SH_15_L,2)    //OFF
    SET(CP_SH_15_R,2)    //OFF
    //  SH_14
    RED(CP_SH_14_SS)  
    SET(CP_SH_14_L,2)    //OFF
    SET(CP_SH_14_R,2)    //OFF
    //  SH_13
    RED(CP_SH_13_SS)  
    SET(CP_SH_13_L,2)    //OFF
    SET(CP_SH_13_R,2)    //OFF


    // SH_P
    RED(CP_SH_P_SB) 
    GREEN(CP_SH_P_SE)   //OFF
    SET(CP_SH_P_L,2)    //OFF
    SET(CP_SH_P_R,2)    //OFF

    // SH_M
    RED(CP_SH_M_SB) 
    GREEN(CP_SH_M_SE)   //OFF
    SET(CP_SH_M_L,2)    //OFF
    SET(CP_SH_M_R,2)    //OFF

    // SH_L
    RED(CP_SH_L_SB) 
    GREEN(CP_SH_L_SE)   //OFF
    SET(CP_SH_L_L,2)    //OFF
    SET(CP_SH_L_R,2)    //OFF

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


