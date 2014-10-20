// bcm2835.h
    2 //
    3 // C and C++ support for Broadcom BCM 2835 as used in Raspberry Pi
    4 //
    5 // Author: Mike McCauley
    6 // Copyright (C) 2011-2013 Mike McCauley
    7 // $Id: bcm2835.h,v 1.14 2014/08/21 01:26:42 mikem Exp mikem $
    8 //
  314 
  315 
  316 
  317 // Defines for BCM2835
  318 #ifndef BCM2835_H
  319 #define BCM2835_H
  320 
  321 #include <stdint.h>
  322 
  326 
  327 
  329 #define HIGH 0x1
  330 #define LOW  0x0
  332 
  334 #define BCM2835_CORE_CLK_HZ                             250000000       
  335 
  336 // Physical addresses for various peripheral register sets
  338 #define BCM2835_PERI_BASE               0x20000000
  339 #define BCM2835_ST_BASE                 (BCM2835_PERI_BASE + 0x3000)
  341 #define BCM2835_GPIO_PADS               (BCM2835_PERI_BASE + 0x100000)
  343 #define BCM2835_CLOCK_BASE              (BCM2835_PERI_BASE + 0x101000)
  345 #define BCM2835_GPIO_BASE               (BCM2835_PERI_BASE + 0x200000)
  347 #define BCM2835_SPI0_BASE               (BCM2835_PERI_BASE + 0x204000)
  349 #define BCM2835_BSC0_BASE               (BCM2835_PERI_BASE + 0x205000)
  351 #define BCM2835_GPIO_PWM                (BCM2835_PERI_BASE + 0x20C000)
  353 #define BCM2835_BSC1_BASE               (BCM2835_PERI_BASE + 0x804000)
  355 
  356 
  359 extern volatile uint32_t *bcm2835_st;
  360 
  363 extern volatile uint32_t *bcm2835_gpio;
  364 
  367 extern volatile uint32_t *bcm2835_pwm;
  368 
  371 extern volatile uint32_t *bcm2835_clk;
  372 
  375 extern volatile uint32_t *bcm2835_pads;
  376 
  379 extern volatile uint32_t *bcm2835_spi0;
  380 
  383 extern volatile uint32_t *bcm2835_bsc0;
  384 
  387 extern volatile uint32_t *bcm2835_bsc1;
  388 
  390 #define BCM2835_PAGE_SIZE               (4*1024)
  391 #define BCM2835_BLOCK_SIZE              (4*1024)
  393 
  394 
  395 // Defines for GPIO
  396 // The BCM2835 has 54 GPIO pins.
  397 //      BCM2835 data sheet, Page 90 onwards.
  399 #define BCM2835_GPFSEL0                      0x0000 
  400 #define BCM2835_GPFSEL1                      0x0004 
  401 #define BCM2835_GPFSEL2                      0x0008 
  402 #define BCM2835_GPFSEL3                      0x000c 
  403 #define BCM2835_GPFSEL4                      0x0010 
  404 #define BCM2835_GPFSEL5                      0x0014 
  405 #define BCM2835_GPSET0                       0x001c 
  406 #define BCM2835_GPSET1                       0x0020 
  407 #define BCM2835_GPCLR0                       0x0028 
  408 #define BCM2835_GPCLR1                       0x002c 
  409 #define BCM2835_GPLEV0                       0x0034 
  410 #define BCM2835_GPLEV1                       0x0038 
  411 #define BCM2835_GPEDS0                       0x0040 
  412 #define BCM2835_GPEDS1                       0x0044 
  413 #define BCM2835_GPREN0                       0x004c 
  414 #define BCM2835_GPREN1                       0x0050 
  415 #define BCM2835_GPFEN0                       0x0058 
  416 #define BCM2835_GPFEN1                       0x005c 
  417 #define BCM2835_GPHEN0                       0x0064 
  418 #define BCM2835_GPHEN1                       0x0068 
  419 #define BCM2835_GPLEN0                       0x0070 
  420 #define BCM2835_GPLEN1                       0x0074 
  421 #define BCM2835_GPAREN0                      0x007c 
  422 #define BCM2835_GPAREN1                      0x0080 
  423 #define BCM2835_GPAFEN0                      0x0088 
  424 #define BCM2835_GPAFEN1                      0x008c 
  425 #define BCM2835_GPPUD                        0x0094 
  426 #define BCM2835_GPPUDCLK0                    0x0098 
  427 #define BCM2835_GPPUDCLK1                    0x009c 
  428 
  429 typedef enum
  432 {
  433     BCM2835_GPIO_FSEL_INPT  = 0b000,   
  434     BCM2835_GPIO_FSEL_OUTP  = 0b001,   
  435     BCM2835_GPIO_FSEL_ALT0  = 0b100,   
  436     BCM2835_GPIO_FSEL_ALT1  = 0b101,   
  437     BCM2835_GPIO_FSEL_ALT2  = 0b110,   
  438     BCM2835_GPIO_FSEL_ALT3  = 0b111,   
  439     BCM2835_GPIO_FSEL_ALT4  = 0b011,   
  440     BCM2835_GPIO_FSEL_ALT5  = 0b010,   
  441     BCM2835_GPIO_FSEL_MASK  = 0b111    
  442 } bcm2835FunctionSelect;
  443 
  446 typedef enum
  447 {
  448     BCM2835_GPIO_PUD_OFF     = 0b00,   
  449     BCM2835_GPIO_PUD_DOWN    = 0b01,   
  450     BCM2835_GPIO_PUD_UP      = 0b10    
  451 } bcm2835PUDControl;
  452 
  454 #define BCM2835_PADS_GPIO_0_27               0x002c 
  455 #define BCM2835_PADS_GPIO_28_45              0x0030 
  456 #define BCM2835_PADS_GPIO_46_53              0x0034 
  457 
  458 #define BCM2835_PAD_PASSWRD                  (0x5A << 24)  
  460 #define BCM2835_PAD_SLEW_RATE_UNLIMITED      0x10 
  461 #define BCM2835_PAD_HYSTERESIS_ENABLED       0x08 
  462 #define BCM2835_PAD_DRIVE_2mA                0x00 
  463 #define BCM2835_PAD_DRIVE_4mA                0x01 
  464 #define BCM2835_PAD_DRIVE_6mA                0x02 
  465 #define BCM2835_PAD_DRIVE_8mA                0x03 
  466 #define BCM2835_PAD_DRIVE_10mA               0x04 
  467 #define BCM2835_PAD_DRIVE_12mA               0x05 
  468 #define BCM2835_PAD_DRIVE_14mA               0x06 
  469 #define BCM2835_PAD_DRIVE_16mA               0x07 
  470 
  471 typedef enum
  474 {
  475     BCM2835_PAD_GROUP_GPIO_0_27         = 0, 
  476     BCM2835_PAD_GROUP_GPIO_28_45        = 1, 
  477     BCM2835_PAD_GROUP_GPIO_46_53        = 2  
  478 } bcm2835PadGroup;
  479 
  493 typedef enum
  494 {
  495     RPI_GPIO_P1_03        =  0,  
  496     RPI_GPIO_P1_05        =  1,  
  497     RPI_GPIO_P1_07        =  4,  
  498     RPI_GPIO_P1_08        = 14,  
  499     RPI_GPIO_P1_10        = 15,  
  500     RPI_GPIO_P1_11        = 17,  
  501     RPI_GPIO_P1_12        = 18,  
  502     RPI_GPIO_P1_13        = 21,  
  503     RPI_GPIO_P1_15        = 22,  
  504     RPI_GPIO_P1_16        = 23,  
  505     RPI_GPIO_P1_18        = 24,  
  506     RPI_GPIO_P1_19        = 10,  
  507     RPI_GPIO_P1_21        =  9,  
  508     RPI_GPIO_P1_22        = 25,  
  509     RPI_GPIO_P1_23        = 11,  
  510     RPI_GPIO_P1_24        =  8,  
  511     RPI_GPIO_P1_26        =  7,  
  512 
  513     // RPi Version 2
  514     RPI_V2_GPIO_P1_03     =  2,  
  515     RPI_V2_GPIO_P1_05     =  3,  
  516     RPI_V2_GPIO_P1_07     =  4,  
  517     RPI_V2_GPIO_P1_08     = 14,  
  518     RPI_V2_GPIO_P1_10     = 15,  
  519     RPI_V2_GPIO_P1_11     = 17,  
  520     RPI_V2_GPIO_P1_12     = 18,  
  521     RPI_V2_GPIO_P1_13     = 27,  
  522     RPI_V2_GPIO_P1_15     = 22,  
  523     RPI_V2_GPIO_P1_16     = 23,  
  524     RPI_V2_GPIO_P1_18     = 24,  
  525     RPI_V2_GPIO_P1_19     = 10,  
  526     RPI_V2_GPIO_P1_21     =  9,  
  527     RPI_V2_GPIO_P1_22     = 25,  
  528     RPI_V2_GPIO_P1_23     = 11,  
  529     RPI_V2_GPIO_P1_24     =  8,  
  530     RPI_V2_GPIO_P1_26     =  7,  
  531 
  532     // RPi Version 2, new plug P5
  533     RPI_V2_GPIO_P5_03     = 28,  
  534     RPI_V2_GPIO_P5_04     = 29,  
  535     RPI_V2_GPIO_P5_05     = 30,  
  536     RPI_V2_GPIO_P5_06     = 31,  
  537 
  538     // RPi B+ J8 header
  539     RPI_BPLUS_GPIO_J8_03     =  2,  
  540     RPI_BPLUS_GPIO_J8_05     =  3,  
  541     RPI_BPLUS_GPIO_J8_07     =  4,  
  542     RPI_BPLUS_GPIO_J8_08     = 14,  
  543     RPI_BPLUS_GPIO_J8_10     = 15,  
  544     RPI_BPLUS_GPIO_J8_11     = 17,  
  545     RPI_BPLUS_GPIO_J8_12     = 18,  
  546     RPI_BPLUS_GPIO_J8_13     = 27,  
  547     RPI_BPLUS_GPIO_J8_15     = 22,  
  548     RPI_BPLUS_GPIO_J8_16     = 23,  
  549     RPI_BPLUS_GPIO_J8_18     = 24,  
  550     RPI_BPLUS_GPIO_J8_19     = 10,  
  551     RPI_BPLUS_GPIO_J8_21     =  9,  
  552     RPI_BPLUS_GPIO_J8_22     = 25,  
  553     RPI_BPLUS_GPIO_J8_23     = 11,  
  554     RPI_BPLUS_GPIO_J8_24     =  8,  
  555     RPI_BPLUS_GPIO_J8_26     =  7,  
  556     RPI_BPLUS_GPIO_J8_29     =  5,  
  557     RPI_BPLUS_GPIO_J8_31     =  6,  
  558     RPI_BPLUS_GPIO_J8_32     =  12, 
  559     RPI_BPLUS_GPIO_J8_33     =  13, 
  560     RPI_BPLUS_GPIO_J8_35     =  19, 
  561     RPI_BPLUS_GPIO_J8_36     =  16, 
  562     RPI_BPLUS_GPIO_J8_37     =  26, 
  563     RPI_BPLUS_GPIO_J8_38     =  20, 
  564     RPI_BPLUS_GPIO_J8_40     =  21, 
  565 } RPiGPIOPin;
  566 
  567 // Defines for SPI
  568 // GPIO register offsets from BCM2835_SPI0_BASE. 
  569 // Offsets into the SPI Peripheral block in bytes per 10.5 SPI Register Map
  570 #define BCM2835_SPI0_CS                      0x0000 
  571 #define BCM2835_SPI0_FIFO                    0x0004 
  572 #define BCM2835_SPI0_CLK                     0x0008 
  573 #define BCM2835_SPI0_DLEN                    0x000c 
  574 #define BCM2835_SPI0_LTOH                    0x0010 
  575 #define BCM2835_SPI0_DC                      0x0014 
  576 
  577 // Register masks for SPI0_CS
  578 #define BCM2835_SPI0_CS_LEN_LONG             0x02000000 
  579 #define BCM2835_SPI0_CS_DMA_LEN              0x01000000 
  580 #define BCM2835_SPI0_CS_CSPOL2               0x00800000 
  581 #define BCM2835_SPI0_CS_CSPOL1               0x00400000 
  582 #define BCM2835_SPI0_CS_CSPOL0               0x00200000 
  583 #define BCM2835_SPI0_CS_RXF                  0x00100000 
  584 #define BCM2835_SPI0_CS_RXR                  0x00080000 
  585 #define BCM2835_SPI0_CS_TXD                  0x00040000 
  586 #define BCM2835_SPI0_CS_RXD                  0x00020000 
  587 #define BCM2835_SPI0_CS_DONE                 0x00010000 
  588 #define BCM2835_SPI0_CS_TE_EN                0x00008000 
  589 #define BCM2835_SPI0_CS_LMONO                0x00004000 
  590 #define BCM2835_SPI0_CS_LEN                  0x00002000 
  591 #define BCM2835_SPI0_CS_REN                  0x00001000 
  592 #define BCM2835_SPI0_CS_ADCS                 0x00000800 
  593 #define BCM2835_SPI0_CS_INTR                 0x00000400 
  594 #define BCM2835_SPI0_CS_INTD                 0x00000200 
  595 #define BCM2835_SPI0_CS_DMAEN                0x00000100 
  596 #define BCM2835_SPI0_CS_TA                   0x00000080 
  597 #define BCM2835_SPI0_CS_CSPOL                0x00000040 
  598 #define BCM2835_SPI0_CS_CLEAR                0x00000030 
  599 #define BCM2835_SPI0_CS_CLEAR_RX             0x00000020 
  600 #define BCM2835_SPI0_CS_CLEAR_TX             0x00000010 
  601 #define BCM2835_SPI0_CS_CPOL                 0x00000008 
  602 #define BCM2835_SPI0_CS_CPHA                 0x00000004 
  603 #define BCM2835_SPI0_CS_CS                   0x00000003 
  604 
  605 typedef enum
  608 {
  609     BCM2835_SPI_BIT_ORDER_LSBFIRST = 0,  
  610     BCM2835_SPI_BIT_ORDER_MSBFIRST = 1   
  611 }bcm2835SPIBitOrder;
  612 
  615 typedef enum
  616 {
  617     BCM2835_SPI_MODE0 = 0,  
  618     BCM2835_SPI_MODE1 = 1,  
  619     BCM2835_SPI_MODE2 = 2,  
  620     BCM2835_SPI_MODE3 = 3,  
  621 }bcm2835SPIMode;
  622 
  625 typedef enum
  626 {
  627     BCM2835_SPI_CS0 = 0,     
  628     BCM2835_SPI_CS1 = 1,     
  629     BCM2835_SPI_CS2 = 2,     
  630     BCM2835_SPI_CS_NONE = 3, 
  631 } bcm2835SPIChipSelect;
  632 
  639 typedef enum
  640 {
  641     BCM2835_SPI_CLOCK_DIVIDER_65536 = 0,       
  642     BCM2835_SPI_CLOCK_DIVIDER_32768 = 32768,   
  643     BCM2835_SPI_CLOCK_DIVIDER_16384 = 16384,   
  644     BCM2835_SPI_CLOCK_DIVIDER_8192  = 8192,    
  645     BCM2835_SPI_CLOCK_DIVIDER_4096  = 4096,    
  646     BCM2835_SPI_CLOCK_DIVIDER_2048  = 2048,    
  647     BCM2835_SPI_CLOCK_DIVIDER_1024  = 1024,    
  648     BCM2835_SPI_CLOCK_DIVIDER_512   = 512,     
  649     BCM2835_SPI_CLOCK_DIVIDER_256   = 256,     
  650     BCM2835_SPI_CLOCK_DIVIDER_128   = 128,     
  651     BCM2835_SPI_CLOCK_DIVIDER_64    = 64,      
  652     BCM2835_SPI_CLOCK_DIVIDER_32    = 32,      
  653     BCM2835_SPI_CLOCK_DIVIDER_16    = 16,      
  654     BCM2835_SPI_CLOCK_DIVIDER_8     = 8,       
  655     BCM2835_SPI_CLOCK_DIVIDER_4     = 4,       
  656     BCM2835_SPI_CLOCK_DIVIDER_2     = 2,       
  657     BCM2835_SPI_CLOCK_DIVIDER_1     = 1,       
  658 } bcm2835SPIClockDivider;
  659 
  660 // Defines for I2C
  661 // GPIO register offsets from BCM2835_BSC*_BASE.
  662 // Offsets into the BSC Peripheral block in bytes per 3.1 BSC Register Map
  663 #define BCM2835_BSC_C                                                   0x0000 
  664 #define BCM2835_BSC_S                                                   0x0004 
  665 #define BCM2835_BSC_DLEN                                                0x0008 
  666 #define BCM2835_BSC_A                                                   0x000c 
  667 #define BCM2835_BSC_FIFO                                                0x0010 
  668 #define BCM2835_BSC_DIV                                                 0x0014 
  669 #define BCM2835_BSC_DEL                                                 0x0018 
  670 #define BCM2835_BSC_CLKT                                                0x001c 
  671 
  672 // Register masks for BSC_C
  673 #define BCM2835_BSC_C_I2CEN                                     0x00008000 
  674 #define BCM2835_BSC_C_INTR                                              0x00000400 
  675 #define BCM2835_BSC_C_INTT                                              0x00000200 
  676 #define BCM2835_BSC_C_INTD                                              0x00000100 
  677 #define BCM2835_BSC_C_ST                                                0x00000080 
  678 #define BCM2835_BSC_C_CLEAR_1                                   0x00000020 
  679 #define BCM2835_BSC_C_CLEAR_2                                   0x00000010 
  680 #define BCM2835_BSC_C_READ                                              0x00000001 
  681 
  682 // Register masks for BSC_S
  683 #define BCM2835_BSC_S_CLKT                                              0x00000200 
  684 #define BCM2835_BSC_S_ERR                                               0x00000100 
  685 #define BCM2835_BSC_S_RXF                                               0x00000080 
  686 #define BCM2835_BSC_S_TXE                                               0x00000040 
  687 #define BCM2835_BSC_S_RXD                                               0x00000020 
  688 #define BCM2835_BSC_S_TXD                                               0x00000010 
  689 #define BCM2835_BSC_S_RXR                                               0x00000008 
  690 #define BCM2835_BSC_S_TXW                                               0x00000004 
  691 #define BCM2835_BSC_S_DONE                                              0x00000002 
  692 #define BCM2835_BSC_S_TA                                                0x00000001 
  693 
  694 #define BCM2835_BSC_FIFO_SIZE                                   16 
  695 
  696 typedef enum
  700 {
  701     BCM2835_I2C_CLOCK_DIVIDER_2500   = 2500,      
  702     BCM2835_I2C_CLOCK_DIVIDER_626    = 626,       
  703     BCM2835_I2C_CLOCK_DIVIDER_150    = 150,       
  704     BCM2835_I2C_CLOCK_DIVIDER_148    = 148,       
  705 } bcm2835I2CClockDivider;
  706 
  709 typedef enum
  710 {
  711     BCM2835_I2C_REASON_OK            = 0x00,      
  712     BCM2835_I2C_REASON_ERROR_NACK    = 0x01,      
  713     BCM2835_I2C_REASON_ERROR_CLKT    = 0x02,      
  714     BCM2835_I2C_REASON_ERROR_DATA    = 0x04,      
  715 } bcm2835I2CReasonCodes;
  716 
  717 // Defines for ST
  718 // GPIO register offsets from BCM2835_ST_BASE.
  719 // Offsets into the ST Peripheral block in bytes per 12.1 System Timer Registers
  720 // The System Timer peripheral provides four 32-bit timer channels and a single 64-bit free running counter.
  721 // BCM2835_ST_CLO is the System Timer Counter Lower bits register.
  722 // The system timer free-running counter lower register is a read-only register that returns the current value
  723 // of the lower 32-bits of the free running counter.
  724 // BCM2835_ST_CHI is the System Timer Counter Upper bits register.
  725 // The system timer free-running counter upper register is a read-only register that returns the current value
  726 // of the upper 32-bits of the free running counter.
  727 #define BCM2835_ST_CS                                                   0x0000 
  728 #define BCM2835_ST_CLO                                                  0x0004 
  729 #define BCM2835_ST_CHI                                                  0x0008 
  730 
  731 
  733 
  734 // Defines for PWM, word offsets (ie 4 byte multiples)
  735 #define BCM2835_PWM_CONTROL 0
  736 #define BCM2835_PWM_STATUS  1
  737 #define BCM2835_PWM_DMAC    2
  738 #define BCM2835_PWM0_RANGE  4
  739 #define BCM2835_PWM0_DATA   5
  740 #define BCM2835_PWM_FIF1    6
  741 #define BCM2835_PWM1_RANGE  8
  742 #define BCM2835_PWM1_DATA   9
  743 
  744 // Defines for PWM Clock, word offsets (ie 4 byte multiples)
  745 #define BCM2835_PWMCLK_CNTL     40
  746 #define BCM2835_PWMCLK_DIV      41
  747 #define BCM2835_PWM_PASSWRD     (0x5A << 24)  
  748 
  749 #define BCM2835_PWM1_MS_MODE    0x8000  
  750 #define BCM2835_PWM1_USEFIFO    0x2000  
  751 #define BCM2835_PWM1_REVPOLAR   0x1000  
  752 #define BCM2835_PWM1_OFFSTATE   0x0800  
  753 #define BCM2835_PWM1_REPEATFF   0x0400  
  754 #define BCM2835_PWM1_SERIAL     0x0200  
  755 #define BCM2835_PWM1_ENABLE     0x0100  
  756 
  757 #define BCM2835_PWM0_MS_MODE    0x0080  
  758 #define BCM2835_PWM_CLEAR_FIFO  0x0040  
  759 #define BCM2835_PWM0_USEFIFO    0x0020  
  760 #define BCM2835_PWM0_REVPOLAR   0x0010  
  761 #define BCM2835_PWM0_OFFSTATE   0x0008  
  762 #define BCM2835_PWM0_REPEATFF   0x0004  
  763 #define BCM2835_PWM0_SERIAL     0x0002  
  764 #define BCM2835_PWM0_ENABLE     0x0001  
  765 
  766 typedef enum
  772 {
  773     BCM2835_PWM_CLOCK_DIVIDER_32768 = 32768,   
  774     BCM2835_PWM_CLOCK_DIVIDER_16384 = 16384,   
  775     BCM2835_PWM_CLOCK_DIVIDER_8192  = 8192,    
  776     BCM2835_PWM_CLOCK_DIVIDER_4096  = 4096,    
  777     BCM2835_PWM_CLOCK_DIVIDER_2048  = 2048,    
  778     BCM2835_PWM_CLOCK_DIVIDER_1024  = 1024,    
  779     BCM2835_PWM_CLOCK_DIVIDER_512   = 512,     
  780     BCM2835_PWM_CLOCK_DIVIDER_256   = 256,     
  781     BCM2835_PWM_CLOCK_DIVIDER_128   = 128,     
  782     BCM2835_PWM_CLOCK_DIVIDER_64    = 64,      
  783     BCM2835_PWM_CLOCK_DIVIDER_32    = 32,      
  784     BCM2835_PWM_CLOCK_DIVIDER_16    = 16,      
  785     BCM2835_PWM_CLOCK_DIVIDER_8     = 8,       
  786     BCM2835_PWM_CLOCK_DIVIDER_4     = 4,       
  787     BCM2835_PWM_CLOCK_DIVIDER_2     = 2,       
  788     BCM2835_PWM_CLOCK_DIVIDER_1     = 1,       
  789 } bcm2835PWMClockDivider;
  790 
  791 // Historical name compatibility
  792 #ifndef BCM2835_NO_DELAY_COMPATIBILITY
  793 #define delay(x) bcm2835_delay(x)
  794 #define delayMicroseconds(x) bcm2835_delayMicroseconds(x)
  795 #endif
  796 
  797 #ifdef __cplusplus
  798 extern "C" {
  799 #endif
  800 
  804 
  813     extern int bcm2835_init(void);
  814 
  817     extern int bcm2835_close(void);
  818 
  825     extern void  bcm2835_set_debug(uint8_t debug);
  826 
  828 
  834 
  841     extern uint32_t bcm2835_peri_read(volatile uint32_t* paddr);
  842 
  843 
  850     extern uint32_t bcm2835_peri_read_nb(volatile uint32_t* paddr);
  851 
  852 
  859     extern void bcm2835_peri_write(volatile uint32_t* paddr, uint32_t value);
  860 
  867     extern void bcm2835_peri_write_nb(volatile uint32_t* paddr, uint32_t value);
  868 
  880     extern void bcm2835_peri_set_bits(volatile uint32_t* paddr, uint32_t value, uint32_t mask);
  882 
  887 
  892     extern void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode);
  893 
  898     extern void bcm2835_gpio_set(uint8_t pin);
  899 
  904     extern void bcm2835_gpio_clr(uint8_t pin);
  905 
  910     extern void bcm2835_gpio_set_multi(uint32_t mask);
  911 
  916     extern void bcm2835_gpio_clr_multi(uint32_t mask);
  917 
  923     extern uint8_t bcm2835_gpio_lev(uint8_t pin);
  924 
  932     extern uint8_t bcm2835_gpio_eds(uint8_t pin);
  933 
  938     extern void bcm2835_gpio_set_eds(uint8_t pin);
  939 
  947     extern void bcm2835_gpio_ren(uint8_t pin);
  948 
  951     extern void bcm2835_gpio_clr_ren(uint8_t pin);
  952 
  960     extern void bcm2835_gpio_fen(uint8_t pin);
  961 
  964     extern void bcm2835_gpio_clr_fen(uint8_t pin);
  965 
  969     extern void bcm2835_gpio_hen(uint8_t pin);
  970 
  973     extern void bcm2835_gpio_clr_hen(uint8_t pin);
  974 
  978     extern void bcm2835_gpio_len(uint8_t pin);
  979 
  982     extern void bcm2835_gpio_clr_len(uint8_t pin);
  983 
  989     extern void bcm2835_gpio_aren(uint8_t pin);
  990 
  993     extern void bcm2835_gpio_clr_aren(uint8_t pin);
  994 
 1000     extern void bcm2835_gpio_afen(uint8_t pin);
 1001 
 1004     extern void bcm2835_gpio_clr_afen(uint8_t pin);
 1005 
 1011     extern void bcm2835_gpio_pud(uint8_t pud);
 1012 
 1018     extern void bcm2835_gpio_pudclk(uint8_t pin, uint8_t on);
 1019 
 1023     extern uint32_t bcm2835_gpio_pad(uint8_t group);
 1024 
 1030     extern void bcm2835_gpio_set_pad(uint8_t group, uint32_t control);
 1031 
 1041     extern void bcm2835_delay (unsigned int millis);
 1042 
 1055     extern void bcm2835_delayMicroseconds (uint64_t micros);
 1056 
 1060     extern void bcm2835_gpio_write(uint8_t pin, uint8_t on);
 1061 
 1065     extern void bcm2835_gpio_write_multi(uint32_t mask, uint8_t on);
 1066 
 1070     extern void bcm2835_gpio_write_mask(uint32_t value, uint32_t mask);
 1071 
 1076     extern void bcm2835_gpio_set_pud(uint8_t pin, uint8_t pud);
 1077 
 1079 
 1084 
 1091     extern void bcm2835_spi_begin(void);
 1092 
 1096     extern void bcm2835_spi_end(void);
 1097 
 1103     extern void bcm2835_spi_setBitOrder(uint8_t order);
 1104 
 1109     extern void bcm2835_spi_setClockDivider(uint16_t divider);
 1110 
 1115     extern void bcm2835_spi_setDataMode(uint8_t mode);
 1116 
 1122     extern void bcm2835_spi_chipSelect(uint8_t cs);
 1123 
 1131     extern void bcm2835_spi_setChipSelectPolarity(uint8_t cs, uint8_t active);
 1132 
 1142     extern uint8_t bcm2835_spi_transfer(uint8_t value);
 1143     
 1154     extern void bcm2835_spi_transfernb(char* tbuf, char* rbuf, uint32_t len);
 1155 
 1162     extern void bcm2835_spi_transfern(char* buf, uint32_t len);
 1163 
 1169     extern void bcm2835_spi_writenb(char* buf, uint32_t len);
 1170 
 1172 
 1177 
 1184     extern void bcm2835_i2c_begin(void);
 1185 
 1189     extern void bcm2835_i2c_end(void);
 1190 
 1193     extern void bcm2835_i2c_setSlaveAddress(uint8_t addr);
 1194 
 1198     extern void bcm2835_i2c_setClockDivider(uint16_t divider);
 1199 
 1205     extern void bcm2835_i2c_set_baudrate(uint32_t baudrate);
 1206 
 1212     extern uint8_t bcm2835_i2c_write(const char * buf, uint32_t len);
 1213 
 1219     extern uint8_t bcm2835_i2c_read(char* buf, uint32_t len);
 1220 
 1234     extern uint8_t bcm2835_i2c_read_register_rs(char* regaddr, char* buf, uint32_t len);
 1235 
 1245     extern uint8_t bcm2835_i2c_write_read_rs(char* cmds, uint32_t cmds_len, char* buf, uint32_t buf_len);
 1246 
 1248 
 1252 
 1255     extern uint64_t bcm2835_st_read(void);
 1256 
 1260     extern void bcm2835_st_delay(uint64_t offset_micros, uint64_t micros);
 1261 
 1263 
 1270 
 1275     extern void bcm2835_pwm_set_clock(uint32_t divisor);
 1276     
 1282     extern void bcm2835_pwm_set_mode(uint8_t channel, uint8_t markspace, uint8_t enabled);
 1283 
 1288     extern void bcm2835_pwm_set_range(uint8_t channel, uint32_t range);
 1289     
 1295     extern void bcm2835_pwm_set_data(uint8_t channel, uint32_t data);
 1296 
 1298 #ifdef __cplusplus
 1299 }
 1300 #endif
 1301 
 1302 #endif // BCM2835_H
 1303 
