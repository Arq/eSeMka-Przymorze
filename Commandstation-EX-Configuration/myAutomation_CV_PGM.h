// Defines Routes for light semaphores CV Programming

// Called from AUTOSTART - it defines which Commands(Routes) will be visible in 
SEQUENCE(PROC_PGM_CLOSE)
    ROUTE_HIDDEN(RT_PGM_CLOSE)
    ROUTE_INACTIVE(RT_PGM_OPEN)
    ROUTE_HIDDEN(RT_PGM_US1_5_3)
    ROUTE_HIDDEN(RT_PGM_US2_5)
RETURN

// CV Programming
ROUTE(RT_PGM_OPEN, "Open CV PGM")
    CALL(PROC_PGM_OPEN)
    DONE

ROUTE(RT_PGM_CLOSE, "Close CV PGM")
    CALL(PROC_PGM_CLOSE)
    DONE

SEQUENCE(PROC_PGM_OPEN)
    ROUTE_HIDDEN(RT_PGM_OPEN)
    ROUTE_INACTIVE(RT_PGM_CLOSE)
    ROUTE_INACTIVE(RT_PGM_US1_5_3)
    ROUTE_INACTIVE(RT_PGM_US2_5)
RETURN

#define CV_PROG_DELAY DELAY(2000)
    // UniSemaf  Semafor 5 i 3 komorowy
ROUTE(RT_PGM_US1_5_3, "PGM_UniSemaf1_5_3")
    // Aspect 1+ S1
    PARSE("<W 547 31>")
        CV_PROG_DELAY
    PARSE("<W 548 4>")
        CV_PROG_DELAY
    PARSE("<W 549 0>")
        CV_PROG_DELAY
    PARSE("<W 550 0>")
        DELAY(2000)
    // Aspect 1- S2
    PARSE("<W 551 31>")
        CV_PROG_DELAY
    PARSE("<W 552 1>")
        CV_PROG_DELAY
    PARSE("<W 553 0>")
        CV_PROG_DELAY
    PARSE("<W 554 0>")
        CV_PROG_DELAY
    // Aspect 2+ S3
    PARSE("<W 555 31>")
        CV_PROG_DELAY
    PARSE("<W 556 1>")
        CV_PROG_DELAY
    PARSE("<W 557 1>")
        CV_PROG_DELAY
    PARSE("<W 558 0>")
        CV_PROG_DELAY
    // Aspect 2- S4
    PARSE("<W 559 31>")
        CV_PROG_DELAY
    PARSE("<W 560 2>")
        CV_PROG_DELAY
    PARSE("<W 561 2>")
        CV_PROG_DELAY
    PARSE("<W 562 0>")
        CV_PROG_DELAY
    // Aspect 3+ S5
    PARSE("<W 563 31>")
        CV_PROG_DELAY
    PARSE("<W 564 2>")
        CV_PROG_DELAY
    PARSE("<W 565 0>")
        CV_PROG_DELAY
    PARSE("<W 566 0>")
        CV_PROG_DELAY
    // Aspect 3- S10
    PARSE("<W 567 31>")
        CV_PROG_DELAY
    PARSE("<W 568 9>")
        CV_PROG_DELAY
    PARSE("<W 569 0>")
        CV_PROG_DELAY
    PARSE("<W 570 0>")
        CV_PROG_DELAY
    // Aspect 4+ S11
    PARSE("<W 571 31>")
        CV_PROG_DELAY
    PARSE("<W 572 9>")
        CV_PROG_DELAY
    PARSE("<W 573 8>")
        CV_PROG_DELAY
    PARSE("<W 574 0>")
        CV_PROG_DELAY
    // Aspect 4- SZ
    PARSE("<W 575 31>")
        CV_PROG_DELAY
    PARSE("<W 576 20>")
        CV_PROG_DELAY
    PARSE("<W 577 16>")
        CV_PROG_DELAY
    PARSE("<W 578 0>")
        CV_PROG_DELAY
    CV_PROG_DELAY
    // Aspect 5+ S12
    PARSE("<W 579 31>")
        CV_PROG_DELAY
    PARSE("<W 580 10>")
        CV_PROG_DELAY
    PARSE("<W 581 2>")
        CV_PROG_DELAY
    PARSE("<W 582 0>")
        CV_PROG_DELAY
    // Aspect 5- S13
    PARSE("<W 583 31>")
        CV_PROG_DELAY
    PARSE("<W 584 10>")
        CV_PROG_DELAY
    PARSE("<W 585 0>")
        CV_PROG_DELAY
    PARSE("<W 586 0>")
        CV_PROG_DELAY
    // Aspect 6+ S1
    PARSE("<W 587 224>")
        CV_PROG_DELAY
    PARSE("<W 588 64>")
        CV_PROG_DELAY
    PARSE("<W 589 0>")
        CV_PROG_DELAY
    PARSE("<W 590 0>")
        CV_PROG_DELAY
    // Aspect 6- S2
    PARSE("<W 591 224>")
        CV_PROG_DELAY
    PARSE("<W 592 32>")
        CV_PROG_DELAY
    PARSE("<W 593 0>")
        CV_PROG_DELAY
    PARSE("<W 594 0>")
        CV_PROG_DELAY
    // Aspect 7+ S3
    PARSE("<W 595 224>")
        CV_PROG_DELAY
    PARSE("<W 596 32>")
        CV_PROG_DELAY
    PARSE("<W 597 32>")
        CV_PROG_DELAY
    PARSE("<W 598 0>")
        CV_PROG_DELAY
    // Aspect 7- S5
    PARSE("<W 599 224>")
        CV_PROG_DELAY
    PARSE("<W 600 128>")
        CV_PROG_DELAY
    PARSE("<W 601 0>")
        CV_PROG_DELAY
    PARSE("<W 602 0>")
        CV_PROG_DELAY
DONE

// UniSemaf2.5  Semafor 5 komorowy
// G=32, Yg=16, R=1, Yd=2,W=4
ROUTE(RT_PGM_US2_5, "PGM_UniSemaf2_5")
    // Aspect 1- S1
    PARSE("<W 35 55>")
        CV_PROG_DELAY
    PARSE("<W 36 1>")
        CV_PROG_DELAY
    PARSE("<W 37 0>")
        CV_PROG_DELAY
    PARSE("<W 38 0>")
        DELAY(2000)
    // Aspect 1+ S2
    PARSE("<W 39 55>")
        CV_PROG_DELAY
    PARSE("<W 40 32>")
        CV_PROG_DELAY
    PARSE("<W 41 0>")
        CV_PROG_DELAY
    PARSE("<W 42 0>")
        CV_PROG_DELAY
    // Aspect 2- S3
    PARSE("<W 43 55>")
        CV_PROG_DELAY
    PARSE("<W 44 32>")
        CV_PROG_DELAY
    PARSE("<W 45 32>")
        CV_PROG_DELAY
    PARSE("<W 46 0>")
        CV_PROG_DELAY
    // Aspect 2+ S4
    PARSE("<W 47 55>")
        CV_PROG_DELAY
    PARSE("<W 48 16>")
        CV_PROG_DELAY
    PARSE("<W 49 16>")
        CV_PROG_DELAY
    PARSE("<W 50 0>")
        CV_PROG_DELAY
    // Aspect 3- S5
    PARSE("<W 51 55>")
        CV_PROG_DELAY
    PARSE("<W 52 16>")
        CV_PROG_DELAY
    PARSE("<W 53 0>")
        CV_PROG_DELAY
    PARSE("<W 54 0>")
        CV_PROG_DELAY
    // Aspect 3+ S10
    PARSE("<W 55 55>")
        CV_PROG_DELAY
    PARSE("<W 56 34>")
        CV_PROG_DELAY
    PARSE("<W 57 0>")
        CV_PROG_DELAY
    PARSE("<W 58 0>")
        CV_PROG_DELAY
    // Aspect 4- S11
    PARSE("<W 59 55>")
        CV_PROG_DELAY
    PARSE("<W 60 34>")
        CV_PROG_DELAY
    PARSE("<W 61 2>")
        CV_PROG_DELAY
    PARSE("<W 62 0>")
        CV_PROG_DELAY
    // Aspect 4+ SZ
    PARSE("<W 63 55>")
        CV_PROG_DELAY
    PARSE("<W 64 5>")
        CV_PROG_DELAY
    PARSE("<W 65 4>")
        CV_PROG_DELAY
    PARSE("<W 66 0>")
        CV_PROG_DELAY
DONE