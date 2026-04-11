//***************************************/ 
//*******     Control Panel         *****/
 
#define IC_RL  0  //Red Left
#define IC_GL  1  //Green Left
#define IC_BTN 2
#define IC_SR1 3
#define IC_SR2 4
#define IC_SR3 5
#define IC_RR  6  //Red Right
#define IC_GR  7  //Green Right
#define IC_SR4 8
#define IC_SR5 9
#define IC_SL1 10
#define IC_SL2 11
#define IC_SL3 12
#define IC_SL4 13
#define IC_SL5 14
#define IC_V0  15
#define IC_V1  16
#define IC_V2  17
#define IC_V3  18
#define IC_V4  19

// turnout corner LEDs
#define IC_RUL 3   // Up Left
#define IC_GUL 4
#define IC_RUR 5   // up Right
#define IC_GUR 8
#define IC_RBR 9   // Bottom Right
#define IC_GBR 10
#define IC_RBL 11  // Bottom Left
#define IC_GBL 12


ALIAS(CP_SH_B,4000)   // ICBlock Signal
ALIAS(CP_SH_B_BTN,CP_SH_B+IC_BTN)
ALIAS(CP_SH_B_L,CP_SH_B+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_B_R,CP_SH_B+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_B_SB,CP_SH_B+IC_SR3)  // Signal Basic   (for Left or Right)
ALIAS(CP_SH_B_SE,CP_SH_B+IC_SR5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_A,4020)   // ICBlock Signal
ALIAS(CP_SH_A_BTN,CP_SH_A+IC_BTN)
ALIAS(CP_SH_A_L,CP_SH_A+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_A_R,CP_SH_A+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_A_SB,CP_SH_A+IC_SR3)  // Signal Basic   (for Left or Right)
ALIAS(CP_SH_A_SE,CP_SH_A+IC_SR5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_2,4040)   // ICBlock Multi
ALIAS(CP_SH_2_BTN,CP_SH_2+IC_BTN)
ALIAS(CP_SH_2_L,CP_SH_2+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_2_R,CP_SH_2+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_2_SB,CP_SH_2+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_2_SS,CP_SH_2+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_1,4060)   // ICBlock Multi
ALIAS(CP_SH_1_BTN,CP_SH_1+IC_BTN)
ALIAS(CP_SH_1_L,CP_SH_1+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_1_R,CP_SH_1+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_1_SB,CP_SH_1+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_1_SS,CP_SH_1+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W



ALIAS(CP_TN_1,4080)   // ICBlock 
// no button, depends on  virtual turnout TN_2 
ALIAS(CP_TN_1_L,CP_TN_1+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_1_R,CP_TN_1+IC_RR)   // Right (Occupancy and Route)

ALIAS(CP_TN_2,4100)   // ICBlock 
ALIAS(CP_TN_2_BTN,CP_TN_2+IC_BTN)
ALIAS(CP_TN_2_L,CP_TN_2+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_2_R,CP_TN_2+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_2_THROWN_A,CP_TN_2+IC_SR2) // Turnout thrown led A
ALIAS(CP_TN_2_THROWN_B,CP_TN_2+IC_SR5) // Turnout thrown led B
ALIAS(CP_TN_2_THROWN_C,CP_TN_1+IC_SL2) // Turnout thrown led C (on TN_26)
ALIAS(CP_TN_2_THROWN_D,CP_TN_1+IC_SL5) // Turnout thrown led D (on TN_26)
ALIAS(CP_TN_2_TRN,CP_TN_2+IC_V1)  //virtual Turnout


ALIAS(CP_TN_6,4120)   // ICBlock  Turnout
ALIAS(CP_TN_6_BTN,CP_TN_6+IC_BTN)
ALIAS(CP_TN_6_L,CP_TN_6+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_6_R,CP_TN_6+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_6_THROWN,CP_TN_6+IC_RUL) // Turnout thrown led
ALIAS(CP_TN_6_TRN,CP_TN_6+IC_V1)  //virtual Turnout
ALIAS(CP_TN_6_OCC,CP_TN_6+IC_V2)  //occupancy- SET doesnt work, LATCH causes ERROR - use SENSOR

ALIAS(CP_TN_5,4140)   // ICBlock 
ALIAS(CP_TN_5_BTN,CP_TN_5+IC_BTN)
ALIAS(CP_TN_5_L,CP_TN_5+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_5_R,CP_TN_5+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_5_THROWN,CP_TN_5+IC_SR3) // Turnout thrown led
ALIAS(CP_TN_5_TRN,CP_TN_5+IC_V1)  //virtual Turnout



ALIAS(CP_TN_8,4160)   // ICBlock 
ALIAS(CP_TN_8_BTN,CP_TN_8+IC_BTN)
ALIAS(CP_TN_8_L,CP_TN_8+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_8_R,CP_TN_8+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_8_THROWN,CP_TN_8+IC_RBL) // Turnout thrown led
ALIAS(CP_TN_8_TRN,CP_TN_8+IC_V1)  //virtual Turnout

ALIAS(CP_TN_7,4180)   // ICBlock 
ALIAS(CP_TN_7_BTN,CP_TN_7+IC_BTN)
ALIAS(CP_TN_7_L,CP_TN_7+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_7_R,CP_TN_7+IC_RUR)   // Right (Occupancy and Route) !Use 4 bits !!!
ALIAS(CP_TN_7_THROWN,CP_TN_7+IC_RBL) // Turnout thrown led
ALIAS(CP_TN_7_TRN,CP_TN_7+IC_V1)  //virtual Turnout


ALIAS(CP_SH_3,4200)   // ICBlock Multi
ALIAS(CP_SH_3_BTN,CP_SH_3+IC_BTN)
ALIAS(CP_SH_3_L,CP_SH_3+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_3_R,CP_SH_3+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_3_SB,CP_SH_3+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_3_SS,CP_SH_3+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_4,4220)   // ICBlock Multi
ALIAS(CP_SH_4_BTN,CP_SH_4+IC_BTN)
ALIAS(CP_SH_4_L,CP_SH_4+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_4_R,CP_SH_4+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_4_SB,CP_SH_4+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_4_SS,CP_SH_4+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W


ALIAS(CP_SH_D1,4240)   // ICBlock Signal
ALIAS(CP_SH_D1_BTN,CP_SH_D1+IC_BTN)
ALIAS(CP_SH_D1_L,CP_SH_D1+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_D1_R,CP_SH_D1+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_D1_SB,CP_SH_D1+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_D1_SE,CP_SH_D1+IC_SL5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_D2,4260)   // ICBlock Signal
ALIAS(CP_SH_D2_BTN,CP_SH_D2+IC_BTN)
ALIAS(CP_SH_D2_L,CP_SH_D2+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_D2_R,CP_SH_D2+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_D2_SB,CP_SH_D2+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_D2_SE,CP_SH_D2+IC_SL5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_D3,4280)   // ICBlock Signal
ALIAS(CP_SH_D3_BTN,CP_SH_D3+IC_BTN)
ALIAS(CP_SH_D3_L,CP_SH_D3+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_D3_R,CP_SH_D3+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_D3_SB,CP_SH_D3+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_D3_SE,CP_SH_D3+IC_SL5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_D4,4300)   // ICBlock Signal
ALIAS(CP_SH_D4_BTN,CP_SH_D4+IC_BTN)
ALIAS(CP_SH_D4_L,CP_SH_D4+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_D4_R,CP_SH_D4+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_D4_SB,CP_SH_D4+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_D4_SE,CP_SH_D4+IC_SL5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_11,4320)   // ICBlock Multi
ALIAS(CP_SH_11_BTN,CP_SH_11+IC_BTN)
ALIAS(CP_SH_11_L,CP_SH_11+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_11_R,CP_SH_11+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_11_SB,CP_SH_11+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_11_SS,CP_SH_11+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_12,4340)   // ICBlock Multi
ALIAS(CP_SH_12_BTN,CP_SH_12+IC_BTN)
ALIAS(CP_SH_12_L,CP_SH_12+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_12_R,CP_SH_12+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_12_SB,CP_SH_12+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_12_SS,CP_SH_12+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_G1,4360)   // ICBlock Signal
ALIAS(CP_SH_G1_BTN,CP_SH_G1+IC_BTN)
ALIAS(CP_SH_G1_L,CP_SH_G1+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_G1_R,CP_SH_G1+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_G1_SB,CP_SH_G1+IC_SR3)  // Signal Basic   (for Left or Right)
ALIAS(CP_SH_G1_SE,CP_SH_G1+IC_SR5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_G2,4380)   // ICBlock Signal
ALIAS(CP_SH_G2_BTN,CP_SH_G2+IC_BTN)
ALIAS(CP_SH_G2_L,CP_SH_G2+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_G2_R,CP_SH_G2+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_G2_SB,CP_SH_G2+IC_SR3)  // Signal Basic   (for Left or Right)
ALIAS(CP_SH_G2_SE,CP_SH_G2+IC_SR5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_G3,4400)   // ICBlock Signal
ALIAS(CP_SH_G3_BTN,CP_SH_G3+IC_BTN)
ALIAS(CP_SH_G3_L,CP_SH_G3+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_G3_R,CP_SH_G3+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_G3_SB,CP_SH_G3+IC_SR3)  // Signal Basic   (for Left or Right)
ALIAS(CP_SH_G3_SE,CP_SH_G3+IC_SR5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_G4,4420)   // ICBlock Signal
ALIAS(CP_SH_G4_BTN,CP_SH_G4+IC_BTN)
ALIAS(CP_SH_G4_L,CP_SH_G4+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_G4_R,CP_SH_G4+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_G4_SB,CP_SH_G4+IC_SR3)  // Signal Basic   (for Left or Right)
ALIAS(CP_SH_G4_SE,CP_SH_G4+IC_SR5)  // Signal Extended (for Left or Right)


ALIAS(CP_TN_21,4440)   // ICBlock 
ALIAS(CP_TN_21_BTN,CP_TN_21+IC_BTN)
ALIAS(CP_TN_21_L,CP_TN_21+IC_RUL)   // Left (Occupancy and Route)
ALIAS(CP_TN_21_R,CP_TN_21+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_21_THROWN,CP_TN_21+IC_RBR) // Turnout thrown led
ALIAS(CP_TN_21_TRN,CP_TN_21+IC_V1)  //virtual Turnout

ALIAS(CP_TN_22,4460)   // ICBlock
ALIAS(CP_TN_22_BTN,CP_TN_22+IC_BTN)
ALIAS(CP_TN_22_L,CP_TN_22+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_22_R,CP_TN_22+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_22_THROWN_L,CP_TN_22+IC_RUL) // Turnout thrown led
ALIAS(CP_TN_22_THROWN_R,CP_TN_22+IC_RBR) // Turnout thrown led
ALIAS(CP_TN_22_TRN,CP_TN_22+IC_V1)  //virtual Turnout 

ALIAS(CP_TN_23,4480)   // ICBlock 
ALIAS(CP_TN_23_BTN,CP_TN_23+IC_BTN)
ALIAS(CP_TN_23_L,CP_TN_23+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_23_R,CP_TN_23+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_23_THROWN,CP_TN_23+IC_RBL) // Turnout thrown led
ALIAS(CP_TN_23_TRN,CP_TN_23+IC_V1)  //virtual Turnout

ALIAS(CP_TN_25,4500)   // ICBlock 
ALIAS(CP_TN_25_BTN,CP_TN_25+IC_BTN)
ALIAS(CP_TN_25_L,CP_TN_25+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_25_R,CP_TN_25+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_25_THROWN_R,CP_TN_25+IC_RUR) // Turnout thrown led
ALIAS(CP_TN_25_THROWN_G,CP_TN_25+IC_GUR) // Turnout thrown led
ALIAS(CP_TN_25_TRN,CP_TN_25+IC_V1)  //virtual Turnout

ALIAS(CP_TN_24,4520)   // ICBlock 
ALIAS(CP_TN_24_BTN,CP_TN_24+IC_BTN)
ALIAS(CP_TN_24_L,CP_TN_24+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_24_R,CP_TN_24+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_24_THROWN,CP_TN_24+IC_RBR) // Turnout thrown led
ALIAS(CP_TN_24_TRN,CP_TN_24+IC_V1)  //virtual Turnout


ALIAS(CP_TN_26,4540)   // ICBlock 
// no button, depend on  virtual turnout Tn_27 

ALIAS(CP_TN_27,4560)   // ICBlock 
ALIAS(CP_TN_27_BTN,CP_TN_27+IC_BTN)
ALIAS(CP_TN_27_THROWN_A,CP_TN_27+IC_SR2) // Turnout thrown led A
ALIAS(CP_TN_27_THROWN_B,CP_TN_27+IC_SR5) // Turnout thrown led B
ALIAS(CP_TN_27_THROWN_C,CP_TN_26+IC_SL2) // Turnout thrown led C (on TN_26)
ALIAS(CP_TN_27_THROWN_D,CP_TN_26+IC_SL5) // Turnout thrown led D (on TN_26)
ALIAS(CP_TN_27_TRN,CP_TN_27+IC_V1)  //virtual Turnout

ALIAS(CP_TN_30,4580)   // ICBlock  Miulti jako rozjazd
ALIAS(CP_TN_30_BTN,CP_TN_30+IC_BTN)
ALIAS(CP_TN_30_L,CP_TN_30+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_TN_30_R,CP_TN_30+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_TN_30_THROWN,CP_TN_30+IC_SR1) // Turnout thrown led
ALIAS(CP_TN_30_TRN,CP_TN_30+IC_V1)  //virtual Turnout
ALIAS(CP_TN_30_OCC,CP_TN_30+IC_V2)  //occupancy- SET doesnt work, LATCH causes ERROR - use SENSOR



ALIAS(CP_SH_13,4600)   // ICBlock Multi
ALIAS(CP_SH_13_BTN,CP_SH_13+IC_BTN)
ALIAS(CP_SH_13_L,CP_SH_13+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_13_R,CP_SH_13+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_13_SB,CP_SH_13+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_13_SS,CP_SH_13+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_14,4620)   // ICBlock Multi
ALIAS(CP_SH_14_BTN,CP_SH_14+IC_BTN)
ALIAS(CP_SH_14_L,CP_SH_14+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_14_R,CP_SH_14+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_14_SB,CP_SH_14+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_14_SS,CP_SH_14+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_15,4640)   // ICBlock Multi
ALIAS(CP_SH_15_BTN,CP_SH_15+IC_BTN)
ALIAS(CP_SH_15_L,CP_SH_15+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_15_R,CP_SH_15+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_15_SB,CP_SH_15+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_15_SS,CP_SH_15+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_16,4680)   // ICBlock Multi
ALIAS(CP_SH_16_BTN,CP_SH_16+IC_BTN)
ALIAS(CP_SH_16_L,CP_SH_16+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_16_R,CP_SH_16+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_16_SB,CP_SH_16+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_16_SS,CP_SH_16+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W

ALIAS(CP_SH_17,4700)   // ICBlock Multi
ALIAS(CP_SH_17_BTN,CP_SH_17+IC_BTN)
ALIAS(CP_SH_17_L,CP_SH_17+IC_RL)    // Left (Occupancy and Route)
ALIAS(CP_SH_17_R,CP_SH_17+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_17_SB,CP_SH_17+IC_SR3) // Signal Basic  (for Left and Right) G,A,R
ALIAS(CP_SH_17_SS,CP_SH_17+IC_SR2) // Shunt Signal  (tarcza manewrowa) G=0,B,W


ALIAS(CP_SH_P,4720)   // ICBlock Signal
ALIAS(CP_SH_P_BTN,CP_SH_P+IC_BTN)
ALIAS(CP_SH_P_L,CP_SH_P+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_P_R,CP_SH_P+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_P_SB,CP_SH_P+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_P_SE,CP_SH_P+IC_SL5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_M,4740)   // ICBlock Signal
ALIAS(CP_SH_M_BTN,CP_SH_M+IC_BTN)
ALIAS(CP_SH_M_L,CP_SH_M+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_M_R,CP_SH_M+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_M_SB,CP_SH_M+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_M_SE,CP_SH_M+IC_SL5)  // Signal Extended (for Left or Right)

ALIAS(CP_SH_L,4760)   // ICBlock Signal
ALIAS(CP_SH_L_BTN,CP_SH_L+IC_BTN)
ALIAS(CP_SH_L_L,CP_SH_L+IC_RL)   // Left (Occupancy and Route)
ALIAS(CP_SH_L_R,CP_SH_L+IC_RR)   // Right (Occupancy and Route)
ALIAS(CP_SH_L_SB,CP_SH_L+IC_SL3)  // Signal Basic  (for Left or Right)
ALIAS(CP_SH_L_SE,CP_SH_L+IC_SL5)  // Signal Extended (for Left or Right)