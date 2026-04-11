#ifndef MYDEVICES_H
//#define MYDEVICES_H

#include "IO_HALDisplay.h"
#include "myAliases.h"

// Control Panel devices are defined in myDevicesCP_*.h
#include "myDevices_CP_Przymorze.h"

//****  HAL Devices   ****//
//    HAL(device, parameters) 
//HAL(PCA9685,100, 16, 0x40)  // defined by default  in IODevice.cpp
/*  Examples  
* HAL(PCA9685,116, 16, 0x41)  
* HAL(MCP23017,164, 16, 0x20)
* HAL(MCP23017,180, 16, 0x21)
*/ 
//HAL(PCF8574,BTN1, 8, 0x20)  	// 8 bit io
//HAL(PCF8575,ICBS_J, 16, 0x21)   //ICBlock Semaphore

// Define additional displays apart from display 0 defined in config.h
//HAL(HALDisplay<OLED>,DSP_STATION, 0x3c, 128, 64)

//****  TURNOUTS   ****//
// TURNOUT(id, adr[0-511], subaddr[0-3])

TURNOUT(TRN_01,0,0,"T1")  //Weineret na Mod.10
//TURNOUT(TRN_02,0,1,"T2")
//TURNOUT(TRN_03,0,2,"T3")
//TURNOUT(TRN_04,0,3,"T4")
TURNOUT(TRN_05,1,0,"T5")  // Mod.8 tor
TURNOUT(TRN_06,1,1,"T6")  // Mod.8 tor
TURNOUT(TRN_08,1,2,"T8")  // Mod.8 tor  zmiana miejscami z T7
TURNOUT(TRN_07,1,3,"T7")  // Mod.8 tor  zmiana miejscami z T8

TURNOUT(TRN_21,2,0,"T21")  // Mod.4 tor  zmiana z T9
//TURNOUT(TRN_10,2,1,"T10")  
//TURNOUT(TRN_11,2,2,"T11")
//TURNOUT(TRN_12,2,2,"T12")
TURNOUT(TRN_22a,3,0,"T22a")  // Mod.3 anglik zmiana z T13
TURNOUT(TRN_22b,3,1,"T22b")  // Mod.3 anglik zmiana z T14 
TURNOUT(TRN_25,3,2,"T25")  // Mod.3 tor    zmiana z T15
TURNOUT(TRN_24,3,3,"T24")  // Mod.3 tor    zmiana z T16
TURNOUT(TRN_26,4,0,"T26")  //Weineret na Mod.2 zmiana z T17

TURNOUT(TRN_23,5,0,"T23")  // Mod.3 tor zmiana z T21
TURNOUT(TRN_30,5,1,"T30")  // Mod.2 tor zmiana z T22


//TURNOUT(SH1  ,20,0,"SH1-S1_S2")
//TURNOUT(SH1+1,20,1,"SH1-S3_S4")
//TURNOUT(SH1+2,20,2,"SH1-S5-S10")
//TURNOUT(SH1+3,20,3,"SH1-S11-SZ")
//TURNOUT(SH1+4,21,0,"SH1-S12-S13")
//TURNOUT(SH2 ,21,1,"SH2-S1-S2")
//TURNOUT(SH2a,21,2,"SH2-S3-S5")




//SERVO_TURNOUT(109,100,200,400,Fast,HIDDEN)
//SERVO_TURNOUT(110,101,200,400,Fast,"ST110")

//VIRTUAL_TURNOUT(201)
//VIRTUAL_TURNOUT(202)

// Caution: Pin turnout pins defined here my conflict with sensiors and outputs in mySetup.h
//PIN_TURNOUT(226,26,"PT26")
//PIN_TURNOUT(227,27,"PT27") 


//****  SIGNALS   ****//
// four aspects in two groups for unisemaf - only RED/GREEN comand for every aspect
// DCC_SIGNAL( id, addr, sub_addr ) - Define a DCC accessory signal

DCC_SIGNAL(SH1,20,0)    
DCC_SIGNAL(SH1a,20,1)
DCC_SIGNAL(SH1b,20,2)
DCC_SIGNAL(SH1c,20,3)

//VIRTUAL_SIGNAL(401)  //hidden




//****  SENSORS   ****//
//****  OUTPUTS   ****//


// DASHBOARD SIGNALS
//SIGNAL(ICBS_J,0,ICBS_J+1)   //R,RG,G

#endif