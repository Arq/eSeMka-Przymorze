

ONBUTTON(CP_SH_B_BTN)   
  DELAY(250)     // delays doesnt work
  IFRED(CP_SH_B_SB)
    // check dependency
    //IFTHROWN()
      //AMBER(CP_SH_B_SB)
    //ELSE
    GREEN(CP_SH_B_SB)
	  GREEN(CP_SH_B_SE)
    //ENDIF
  ELSE
    RED(CP_SH_B_SB)
    GREEN(CP_SH_B_SE) // off
  ENDIF  
  DELAY(250)  // delay before issuing command  to next servo
DONE


ONBUTTON(CP_SH_A_BTN)   
  IFRED(CP_SH_A_SB)
    GREEN(CP_SH_A_SB)
	  GREEN(CP_SH_A_SE)  
  ELSE
    RED(CP_SH_A_SB)  
    GREEN(CP_SH_A_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE


ONBUTTON(CP_SH_2_BTN)    // delays doesnt work
  IFGREEN(CP_SH_2_SS)  //is off
    RED(CP_SH_2_SS)
  ELSE
    IFRED(CP_SH_2_SS)
      AMBER(CP_SH_2_SS)
    ELSE
      //GREEN(CP_SH_2_SS)  //off  should never happend
	    RED(CP_SH_2_SS)
    ENDIF  
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE


ONBUTTON(CP_SH_1_BTN)   
  IFGREEN(CP_SH_1_SS)  //is off
    RED(CP_SH_1_SS)
  ELSE
    IFRED(CP_SH_1_SS)
      AMBER(CP_SH_1_SS)
    ELSE  
	    RED(CP_SH_1_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_TN_6_BTN)
  IFCLOSED(CP_TN_6_TRN) 
     THROW(CP_TN_6_TRN)
  ELSE
     CLOSE(CP_TN_6_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_6_TRN)
  CALL(CP_REFRESH)
DONE

ONTHROW(CP_TN_6_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_TN_5_BTN)
  IFCLOSED(CP_TN_5_TRN) 
     THROW(CP_TN_5_TRN)
  ELSE
     CLOSE(CP_TN_5_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_5_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_5_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_TN_8_BTN)
  IFCLOSED(CP_TN_8_TRN) 
     THROW(CP_TN_8_TRN)
  ELSE
     CLOSE(CP_TN_8_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_8_TRN)
  CALL(CP_REFRESH)
DONE

ONTHROW(CP_TN_8_TRN)
  CALL(CP_REFRESH)
DONE


ONBUTTON(CP_TN_7_BTN)
  IFCLOSED(CP_TN_7_TRN) 
     THROW(CP_TN_7_TRN)
  ELSE
     CLOSE(CP_TN_7_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_7_TRN)
  CALL(CP_REFRESH)
DONE

ONTHROW(CP_TN_7_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_SH_D1_BTN)   
  IFRED(CP_SH_D1_SB)
    GREEN(CP_SH_D1_SB)
	  GREEN(CP_SH_D1_SE)  
  ELSE
    RED(CP_SH_D1_SB)  
    GREEN(CP_SH_D1_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_D2_BTN)   
  IFRED(CP_SH_D2_SB)
    GREEN(CP_SH_D2_SB)
	  GREEN(CP_SH_D2_SE)  
  ELSE
    RED(CP_SH_D2_SB)  
    GREEN(CP_SH_D2_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_D3_BTN)   
  IFRED(CP_SH_D3_SB)
    GREEN(CP_SH_D3_SB)
	  GREEN(CP_SH_D3_SE)  
  ELSE
    RED(CP_SH_D3_SB)  
    GREEN(CP_SH_D3_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_D4_BTN)   
  IFRED(CP_SH_D4_SB)
    GREEN(CP_SH_D4_SB)
	  GREEN(CP_SH_D4_SE)  
  ELSE
    RED(CP_SH_D4_SB)  
    GREEN(CP_SH_D4_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_TN_2_BTN)
  IFCLOSED(CP_TN_2_TRN) 
     THROW(CP_TN_2_TRN)
  ELSE
     CLOSE(CP_TN_2_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_2_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_2_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_SH_4_BTN)    // delays doesnt work
  IFGREEN(CP_SH_4_SS)  //is off
    RED(CP_SH_4_SS)
  ELSE
    IFRED(CP_SH_4_SS)
      AMBER(CP_SH_4_SS)
    ELSE
      //GREEN(CP_SH_4_SS)  //off  should never happend
	    RED(CP_SH_4_SS)
    ENDIF  
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_3_BTN)    // delays doesnt work
  IFGREEN(CP_SH_3_SS)  //is off
    RED(CP_SH_3_SS)
  ELSE
    IFRED(CP_SH_3_SS)
      AMBER(CP_SH_3_SS)
    ELSE
      //GREEN(CP_SH_3_SS)  //off  should never happend
	    RED(CP_SH_3_SS)
    ENDIF  
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE


ONBUTTON(CP_SH_12_BTN)    // delays doesnt work
  IFGREEN(CP_SH_12_SS)  //is off
    RED(CP_SH_12_SS)
  ELSE
    IFRED(CP_SH_12_SS)
      AMBER(CP_SH_12_SS)
    ELSE
      //GREEN(CP_SH_2_SS)  //off  should never happend
	    RED(CP_SH_12_SS)
    ENDIF  
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE


ONBUTTON(CP_SH_11_BTN)   
  IFGREEN(CP_SH_11_SS)  //is off
    RED(CP_SH_11_SS)
  ELSE
    IFRED(CP_SH_11_SS)
      AMBER(CP_SH_11_SS)
    ELSE  
	    RED(CP_SH_11_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_SH_G1_BTN)   
  IFRED(CP_SH_G1_SB)
    GREEN(CP_SH_G1_SB)
	  GREEN(CP_SH_G1_SE)  
  ELSE
    RED(CP_SH_G1_SB)  
    GREEN(CP_SH_G1_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_G2_BTN)   
  IFRED(CP_SH_G2_SB)
    GREEN(CP_SH_G2_SB)
	  GREEN(CP_SH_G2_SE)  
  ELSE
    RED(CP_SH_G2_SB)  
    GREEN(CP_SH_G2_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_G3_BTN)   
  IFRED(CP_SH_G3_SB)
    GREEN(CP_SH_G3_SB)
	  GREEN(CP_SH_G3_SE)  
  ELSE
    RED(CP_SH_G3_SB)  
    GREEN(CP_SH_G3_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_G4_BTN)   
  IFRED(CP_SH_G4_SB)
    GREEN(CP_SH_G4_SB)
	  GREEN(CP_SH_G4_SE)  
  ELSE
    RED(CP_SH_G4_SB)  
    GREEN(CP_SH_G4_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_TN_21_BTN)
  IFCLOSED(CP_TN_21_TRN) 
     THROW(CP_TN_21_TRN)
  ELSE
     CLOSE(CP_TN_21_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_21_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_21_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_TN_22_BTN)
  IFCLOSED(CP_TN_22_TRN) 
     THROW(CP_TN_22_TRN)
  ELSE
     CLOSE(CP_TN_22_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_22_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_22_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_TN_23_BTN)
  IFCLOSED(CP_TN_23_TRN) 
     THROW(CP_TN_23_TRN)
  ELSE
     CLOSE(CP_TN_23_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_23_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_23_TRN)
  CALL(CP_REFRESH)
DONE


ONBUTTON(CP_TN_24_BTN)
  IFCLOSED(CP_TN_24_TRN) 
     THROW(CP_TN_24_TRN)
  ELSE
     CLOSE(CP_TN_24_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_24_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_24_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_TN_25_BTN)
  IFCLOSED(CP_TN_25_TRN) 
     THROW(CP_TN_25_TRN)
  ELSE
     CLOSE(CP_TN_25_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_25_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_25_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_TN_27_BTN)
  IFCLOSED(CP_TN_27_TRN) 
     THROW(CP_TN_27_TRN)
  ELSE
     CLOSE(CP_TN_27_TRN)
  ENDIF   
DONE

ONCLOSE(CP_TN_27_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_27_TRN)
  CALL(CP_REFRESH)
DONE



ONBUTTON(CP_TN_30_BTN)
  IFCLOSED(CP_TN_30_TRN) 
     THROW(CP_TN_30_TRN)
  ELSE
     CLOSE(CP_TN_30_TRN)
  ENDIF   
  CALL(CP_REFRESH)
DONE

ONCLOSE(CP_TN_30_TRN)
  CALL(CP_REFRESH)  
DONE

ONTHROW(CP_TN_30_TRN)
  CALL(CP_REFRESH)
DONE

ONBUTTON(CP_SH_17_BTN)   
  IFGREEN(CP_SH_17_SS)  //is off
    RED(CP_SH_17_SS)
  ELSE
    IFRED(CP_SH_17_SS)
      AMBER(CP_SH_17_SS)
    ELSE  
	    RED(CP_SH_17_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_SH_16_BTN)   
  IFGREEN(CP_SH_16_SS)  //is off
    RED(CP_SH_16_SS)
  ELSE
    IFRED(CP_SH_16_SS)
      AMBER(CP_SH_16_SS)
    ELSE  
	    RED(CP_SH_16_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_SH_15_BTN)   
  IFGREEN(CP_SH_15_SS)  //is off
    RED(CP_SH_15_SS)
  ELSE
    IFRED(CP_SH_15_SS)
      AMBER(CP_SH_15_SS)
    ELSE  
	    RED(CP_SH_15_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_SH_14_BTN)   
  IFGREEN(CP_SH_14_SS)  //is off
    RED(CP_SH_14_SS)
  ELSE
    IFRED(CP_SH_14_SS)
      AMBER(CP_SH_14_SS)
    ELSE  
	    RED(CP_SH_14_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_SH_13_BTN)   
  IFGREEN(CP_SH_13_SS)  //is off
    RED(CP_SH_13_SS)
  ELSE
    IFRED(CP_SH_13_SS)
      AMBER(CP_SH_13_SS)
    ELSE  
	    RED(CP_SH_13_SS)
    ENDIF  
  ENDIF
  DELAY(250)  
DONE

ONBUTTON(CP_SH_P_BTN)   
  IFRED(CP_SH_P_SB)
    GREEN(CP_SH_P_SB)
	  GREEN(CP_SH_P_SE)  
  ELSE
    RED(CP_SH_P_SB)  
    GREEN(CP_SH_P_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_M_BTN)   
  IFRED(CP_SH_M_SB)
    GREEN(CP_SH_M_SB)
	  GREEN(CP_SH_M_SE)  
  ELSE
    RED(CP_SH_M_SB)  
    GREEN(CP_SH_M_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE

ONBUTTON(CP_SH_L_BTN)   
  IFRED(CP_SH_L_SB)
    GREEN(CP_SH_L_SB)
	  GREEN(CP_SH_L_SE)  
  ELSE
    RED(CP_SH_L_SB)  
    GREEN(CP_SH_L_SE) // off
  ENDIF
  DELAY(250)  // delay before issuing command  to next servo
DONE


// Dasboard routes an occupancy refersh
SEQUENCE(CP_REFRESH)

  RESET(CP_SH_B_L,2) 
  RESET(CP_SH_B_R,2)
  RESET(CP_SH_1_L,2) 

  RESET(CP_SH_A_L,2) 
  RESET(CP_SH_A_R,2)
  RESET(CP_SH_2_L,2) 

  IFCLOSED(CP_TN_2_TRN)
      SET(CP_TN_2_THROWN_A,1)  // off
      SET(CP_TN_2_THROWN_B,1)  
      SET(CP_TN_2_THROWN_C,1)  // off
      SET(CP_TN_2_THROWN_D,1)  
  ENDIF
  
  IFTHROWN(CP_TN_2_TRN)
      RESET(CP_TN_2_THROWN_A,1)  // lit on 
      RESET(CP_TN_2_THROWN_B,1)  // lit on 
      RESET(CP_TN_2_THROWN_C,1)  // lit on 
      RESET(CP_TN_2_THROWN_D,1)  // lit on 
  ENDIF

  IFCLOSED(CP_TN_6_TRN)
    IF(CP_TN_6_OCC)     //use ONSENSOR  instead 
      RESET(CP_TN_6_L,1)   //red led lights
      SET(CP_TN_6_THROWN,2)  //off (G&R)
      SET(CP_SH_D3_R,2) // off
      SET(CP_SH_D3_L,2) // off
      // oposite side
      RESET(CP_TN_6_R,1)  //red led lights
      RESET(CP_SH_D1_L,1)   // R&G
    ELSE
      RESET(CP_TN_6_L,2)  // R&G
      SET(CP_TN_6_THROWN,2)  //off (G&R)
      SET(CP_SH_D3_R,2)  // off
      SET(CP_SH_D3_L,2) // off
      // oposite side
      RESET(CP_TN_6_R,2)   // R&G
      RESET(CP_SH_D1_L,2)   // R&G
    ENDIF
  ENDIF

  IFTHROWN(CP_TN_6_TRN)
    SET(CP_TN_6_L,2)       // off
    RESET(CP_TN_6_THROWN,2)  // lit on R&G
    RESET(CP_SH_D3_R,2) // lit on R&G
    RESET(CP_SH_D3_L,2) // lit on R&G
    SET(CP_SH_D1_L,2)   // off
    // oposite side
    IF(CP_TN_6_OCC)    //use ONSENSOR instead 
      RESET(CP_TN_6_R,1)  // Red
    ELSE
      RESET(CP_TN_6_R,2)  // R&G
    ENDIF  
  ENDIF  

  IFCLOSED(CP_TN_5_TRN)
      RESET(CP_TN_5_L,2)  // R&G
      SET(CP_TN_5_THROWN,1)  //off (A)
      SET(CP_TN_7_R,4)
      // oposite side
      RESET(CP_TN_5_R,2)     // R&G
  ENDIF

  IFTHROWN(CP_TN_5_TRN)
    SET(CP_TN_5_L,2)       // off
    RESET(CP_TN_5_THROWN,1)  // lit on A
    RESET(CP_TN_7_R,4)
    // oposite side
    RESET(CP_TN_5_R,2)   // R&G
  ENDIF 

  IFCLOSED(CP_TN_8_TRN)
      RESET(CP_TN_8_L,2)  // R&G
      SET(CP_TN_8_THROWN,2)  //off (G&R)
      RESET(CP_SH_D2_R,2)  // lit on R&G
      RESET(CP_SH_D2_L,2)  // lit on R&G
      SET(CP_SH_D4_R,2)    // off
      SET(CP_SH_D4_L,2)    // off
  ENDIF

  IFTHROWN(CP_TN_8_TRN)
    SET(CP_TN_8_L,2)       // off
    RESET(CP_TN_8_THROWN,2)  // lit on R&G
    SET(CP_SH_D2_R,2)  // off
    SET(CP_SH_D2_L,2) // off
    RESET(CP_SH_D4_R,2) // lit on R&G
    RESET(CP_SH_D4_L,2) // lit on R&G
  ENDIF 

  IFCLOSED(CP_TN_7_TRN)
      RESET(CP_TN_7_L,2)  // R&G
      SET(CP_TN_7_THROWN,2)  //off (G&R)
      SET(CP_SH_3_R,2)  // off
      SET(CP_SH_3_L,2) // off
      RESET(CP_SH_4_L,2)   // R&G
  ENDIF

  IFTHROWN(CP_TN_7_TRN)
      SET(CP_TN_7_L,2)       // off
      RESET(CP_TN_7_THROWN,2)  // lit on R&G
      RESET(CP_SH_3_R,2) // lit on R&G
      RESET(CP_SH_3_L,2) // lit on R&G
      SET(CP_SH_4_L,2)   // off
  ENDIF

  IFCLOSED(CP_TN_21_TRN)
      RESET(CP_TN_21_R,2)  // R&G
      SET(CP_TN_21_THROWN,2)  //off (G&R)
      RESET(CP_SH_12_R,2)   // R&G
      SET(CP_SH_11_L,2)   // R&G
      SET(CP_SH_11_R,2)   // R&G
  ENDIF
  
  IFTHROWN(CP_TN_21_TRN)
      SET(CP_TN_21_R,2)       // off
      RESET(CP_TN_21_THROWN,2)  // lit on R&G
      SET(CP_SH_12_R,2)   // R&G
      RESET(CP_SH_11_L,2)   // R&G
      RESET(CP_SH_11_R,2)   // R&G
  ENDIF

  IFCLOSED(CP_TN_22_TRN)
      RESET(CP_TN_22_R,2)  // R&G
      SET(CP_TN_22_THROWN_R,2)  //off (G&R)
      RESET(CP_SH_G4_R,2)   // R&G
      SET(CP_TN_21_L,2)   // 
  ENDIF
  
  IFTHROWN(CP_TN_22_TRN)
      SET(CP_TN_22_R,2)       // off
      RESET(CP_TN_22_THROWN_R,2)  // lit on R&G
      SET(CP_SH_G4_R,2)   //off
      RESET(CP_TN_21_L,2)   // R&G
  ENDIF

  IFCLOSED(CP_TN_25_TRN)
      RESET(CP_TN_25_R,2)  // R&G
      SET(CP_TN_25_THROWN_R,1)  //off R
      SET(CP_TN_25_THROWN_G,1)  //off G
      RESET(CP_TN_25_L,2)  // R&G
      SET(CP_SH_G3_L,2)   // 
      SET(CP_SH_G3_R,2)   // 
      RESET(CP_SH_G1_R,2)   // R&G
  ENDIF
  
  IFTHROWN(CP_TN_25_TRN)
      SET(CP_TN_25_R,2)       // off
      RESET(CP_TN_25_THROWN_R,1)  // lit on R
      RESET(CP_TN_25_THROWN_G,1)  // lit on G
      RESET(CP_TN_25_L,2)  // R&G
      RESET(CP_SH_G3_L,2)   // R&G
      RESET(CP_SH_G3_R,2)   // R&G
      SET(CP_SH_G1_R,2)   // 
  ENDIF

  IFCLOSED(CP_TN_24_TRN)
      RESET(CP_TN_24_R,2)  // R&G
      SET(CP_TN_24_THROWN,2)  //off R&G
      RESET(CP_TN_24_L,2)  // R&G
      SET(CP_TN_22_THROWN_L,2)
      RESET(CP_TN_22_L,2)  // R&G
      RESET(CP_SH_G2_R,2)   // R&G
      // reset signals
      RED(CP_SH_G2_SB)
      GREEN(CP_SH_G2_SE)   //OFF
      RED(CP_SH_G4_SB)
      GREEN(CP_SH_G4_SE)   //OFF
      RED(CP_SH_L_SB) 
      GREEN(CP_SH_L_SE)   //OFF
      RED(CP_SH_15_SS)
  ENDIF
  
  IFTHROWN(CP_TN_24_TRN)
      SET(CP_TN_24_R,2)       // off
      RESET(CP_TN_24_THROWN,2)  // lit on R&G
      RESET(CP_TN_24_L,2)  // R&G
      RESET(CP_TN_22_THROWN_L,2)
      SET(CP_TN_22_L,2)  // R&G
      SET(CP_SH_G2_R,2)   // 
      // reset signals
      RED(CP_SH_G2_SB)
      GREEN(CP_SH_G2_SE)   //OFF
      RED(CP_SH_G4_SB)
      GREEN(CP_SH_G4_SE)   //OFF
      RED(CP_SH_L_SB) 
      GREEN(CP_SH_L_SE)   //OFF
      RED(CP_SH_15_SS)  
  ENDIF

  IFCLOSED(CP_TN_27_TRN)
      SET(CP_TN_27_THROWN_A,1)  // off
      SET(CP_TN_27_THROWN_B,1)  
      SET(CP_TN_27_THROWN_C,1)  // off
      SET(CP_TN_27_THROWN_D,1)  
  ENDIF
  
  IFTHROWN(CP_TN_27_TRN)
      RESET(CP_TN_27_THROWN_A,1)  // lit on 
      RESET(CP_TN_27_THROWN_B,1)  // lit on 
      RESET(CP_TN_27_THROWN_C,1)  // lit on 
      RESET(CP_TN_27_THROWN_D,1)  // lit on 
  ENDIF



  IFCLOSED(CP_TN_23_TRN)
      RESET(CP_TN_23_L,2)  // R&G
      SET(CP_TN_23_THROWN,2)  //off (G&R)
      SET(CP_SH_13_R,2)  // off
      SET(CP_SH_13_L,2)  // off
      RESET(CP_SH_14_L,2) // lit on R&G
  ENDIF

  IFTHROWN(CP_TN_23_TRN)
      SET(CP_TN_23_L,2)       // off
      RESET(CP_TN_23_THROWN,2)  // lit on R&G
      RESET(CP_SH_13_R,2) // lit on R&G
      RESET(CP_SH_13_L,2) // lit on R&G
      SET(CP_SH_14_L,2)  // off
  ENDIF

  IFCLOSED(CP_TN_30_TRN)
    IF(CP_TN_30_OCC)     //use ONSENSOR  instead 
      RESET(CP_TN_30_L,1)   //red led lights
      SET(CP_TN_30_THROWN)  //off (single amber led)
      // oposite side
      RESET(CP_TN_30_R,1)  // //red led lights
      RESET(CP_SH_16_L,1)
      SET(CP_SH_16_L+1,1)
    ELSE
      RESET(CP_TN_30_L,2)  //red&green led lights
      SET(CP_TN_30_THROWN)  //off (single amber led)
      // oposite side
      RESET(CP_TN_30_R,2)   //red&green led lights
      RESET(CP_SH_16_L,2)
    ENDIF
    SET(CP_SH_17_L,2) //off
    SET(CP_SH_17_R,2) //off
  ENDIF

  IFTHROWN(CP_TN_30_TRN)
    SET(CP_TN_30_L,2)       // off
    RESET(CP_TN_30_THROWN)  // lit on (single amber led)
    RESET(CP_SH_17_L,2) //on
    RESET(CP_SH_17_R,2) //on
    SET(CP_SH_16_L,2) //off
    // oposite side
    IF(CP_TN_30_OCC)    //use ONSENSOR  instead 
      RESET(CP_TN_30_R,1)  //red
    ELSE
      RESET(CP_TN_30_R,2)  //red&gree
    ENDIF
    
  ENDIF  

  RESET(CP_SH_15_L,2) 
  RESET(CP_SH_15_R,2) 

  RESET(CP_SH_P_L,2) 
  RESET(CP_SH_M_L,2)
  RESET(CP_SH_L_L,2) 

RETURN