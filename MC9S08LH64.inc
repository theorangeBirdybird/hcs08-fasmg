; Based on CPU DB MC9S08LH64_80, version 3.00.036 (RegistersPrg V2.32)

; ###################################################################
;     Filename   mc9s08lh64.inc
;     Processor  MC9S08LH64CLK
;     FileFormat V2.32
;     DataSheet  MC9S08LH64RM Rev. 4 03/2009
;     Compiler   CodeWarrior compiler
;     Date/Time  5.10.2010, 1341
;     Abstract  
;         This header implements the mapping of I/O devices.
;
;     Copyright  1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
;     
;     http       www.freescale.com
;     mail       support@freescale.com
;
;     CPU Registers Revisions
;      - 20.02.2009, V3.00.0
;              - Renamed VREFx module registers VREFTRMx -> VREFxTRM, VREFSCx -> VREFxSC.
;              -   REASON Changes in the Reference Manual (from Rev. 2 7/2008 to Rev.3 12/2008). 
;      - 27.11.2009, V3.00.3
;              - Removed XA16 bit from PPAGE register. Updated the register DBGCAX, DBGCBX, DBGCCX. Added DBGFX register.
;              -   REASON Bug-Fix (#6683 in Issue Manager).
;
;     File-Format-Revisions
;      - 17.3.2009, V2.27 
;               - Merged bit-group is not generated, if the name matches with another bit name in the register
;      - 6.4.2009, V2.28 
;               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
;      - 3.8.2009, V2.29 
;               - If there is just one bits group matching register name, single bits are not generated
;      - 10.9.2009, V2.30 
;               - Fixed generation of registers arrays.
;      - 15.10.2009, V2.31 
;               - HCS08 family Bits and bit-groups are published for 16-bit registers 8-bit overlay registers are required.
;      - 18.05.2010, V2.32 
;               - MISRA compliance U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
;
;     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
;     derivative device. To avoid extra current drain from floating input pins, the user’s reset
;     initialization routine in the application program must either enable on-chip pull-up devices
;     or change the direction of unconnected pins to outputs so the pins do not float.
; ###################################################################

;*** Memory Map and Interrupt Vectors
;******************************************
ROMStart           equ   $000018A1
ROMEnd             equ   $00007FFF
Z_RAMStart         equ   $00000060
Z_RAMEnd           equ   $000000FF
RAMStart           equ   $00000100
RAMEnd             equ   $00000FFF
ROM1Start          equ   $0000103C
ROM1End            equ   $000017FF
ROM2Start          equ   $0000C000
ROM2End            equ   $0000FFAB
ROM3Start          equ   $0000FFC0
ROM3End            equ   $0000FFD1
PPAGE_0Start       equ   $00008000
PPAGE_0End         equ   $0000903B
PPAGE_0_1Start     equ   $00009800
PPAGE_0_1End       equ   $000098A0
PPAGE_2Start       equ   $00028000
PPAGE_2End         equ   $0002BFFF
;
Vsci2tx            equ   $0000FFD2
Vsci2rx            equ   $0000FFD4
Vsci2err           equ   $0000FFD6
Vtod               equ   $0000FFD8
Vacmp              equ   $0000FFDA
Vadc               equ   $0000FFDC
Vkeyboard          equ   $0000FFDE
Viic               equ   $0000FFE0
Vsci1tx            equ   $0000FFE2
Vsci1rx            equ   $0000FFE4
Vsci1err           equ   $0000FFE6
Vspi               equ   $0000FFE8
Vlcd               equ   $0000FFEA
Vtpm2ovf           equ   $0000FFEC
Vtpm2ch1           equ   $0000FFEE
Vtpm2ch0           equ   $0000FFF0
Vtpm1ovf           equ   $0000FFF2
Vtpm1ch1           equ   $0000FFF4
Vtpm1ch0           equ   $0000FFF6
Vlvd               equ   $0000FFF8
Virq               equ   $0000FFFA
Vswi               equ   $0000FFFC
Vreset             equ   $0000FFFE
;


;*** PTAD - Port A Data Register; 0x00000000 ***
PTAD               equ    $00000000                                ;*** PTAD - Port A Data Register; 0x00000000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAD_PTAD0         equ    0                                         ; Port A Data Register Bit 0
PTAD_PTAD1         equ    1                                         ; Port A Data Register Bit 1
PTAD_PTAD2         equ    2                                         ; Port A Data Register Bit 2
PTAD_PTAD3         equ    3                                         ; Port A Data Register Bit 3
PTAD_PTAD4         equ    4                                         ; Port A Data Register Bit 4
PTAD_PTAD5         equ    5                                         ; Port A Data Register Bit 5
PTAD_PTAD6         equ    6                                         ; Port A Data Register Bit 6
PTAD_PTAD7         equ    7                                         ; Port A Data Register Bit 7
; bit position masks
mPTAD_PTAD0        equ    00000001b
mPTAD_PTAD1        equ    00000010b
mPTAD_PTAD2        equ    00000100b
mPTAD_PTAD3        equ    00001000b
mPTAD_PTAD4        equ    00010000b
mPTAD_PTAD5        equ    00100000b
mPTAD_PTAD6        equ    01000000b
mPTAD_PTAD7        equ    10000000b


;*** PTADD - Port A Data Direction Register; 0x00000001 ***
PTADD              equ    $00000001                                ;*** PTADD - Port A Data Direction Register; 0x00000001 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADD_PTADD0       equ    0                                         ; Data Direction for Port A Bit 0
PTADD_PTADD1       equ    1                                         ; Data Direction for Port A Bit 1
PTADD_PTADD2       equ    2                                         ; Data Direction for Port A Bit 2
PTADD_PTADD3       equ    3                                         ; Data Direction for Port A Bit 3
PTADD_PTADD4       equ    4                                         ; Data Direction for Port A Bit 4
PTADD_PTADD5       equ    5                                         ; Data Direction for Port A Bit 5
PTADD_PTADD6       equ    6                                         ; Data Direction for Port A Bit 6
PTADD_PTADD7       equ    7                                         ; Data Direction for Port A Bit 7
; bit position masks
mPTADD_PTADD0      equ    00000001b
mPTADD_PTADD1      equ    00000010b
mPTADD_PTADD2      equ    00000100b
mPTADD_PTADD3      equ    00001000b
mPTADD_PTADD4      equ    00010000b
mPTADD_PTADD5      equ    00100000b
mPTADD_PTADD6      equ    01000000b
mPTADD_PTADD7      equ    10000000b


;*** PTBD - Port B Data Register; 0x00000002 ***
PTBD               equ    $00000002                                ;*** PTBD - Port B Data Register; 0x00000002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBD_PTBD0         equ    0                                         ; Port B Data Register Bit 0
PTBD_PTBD1         equ    1                                         ; Port B Data Register Bit 1
PTBD_PTBD2         equ    2                                         ; Port B Data Register Bit 2
PTBD_PTBD4         equ    4                                         ; Port B Data Register Bit 4
PTBD_PTBD5         equ    5                                         ; Port B Data Register Bit 5
PTBD_PTBD6         equ    6                                         ; Port B Data Register Bit 6
PTBD_PTBD7         equ    7                                         ; Port B Data Register Bit 7
; bit position masks
mPTBD_PTBD0        equ    00000001b
mPTBD_PTBD1        equ    00000010b
mPTBD_PTBD2        equ    00000100b
mPTBD_PTBD4        equ    00010000b
mPTBD_PTBD5        equ    00100000b
mPTBD_PTBD6        equ    01000000b
mPTBD_PTBD7        equ    10000000b


;*** PTBDD - Port B Data Direction Register; 0x00000003 ***
PTBDD              equ    $00000003                                ;*** PTBDD - Port B Data Direction Register; 0x00000003 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDD_PTBDD0       equ    0                                         ; Data Direction for Port B Bit 0
PTBDD_PTBDD1       equ    1                                         ; Data Direction for Port B Bit 1
PTBDD_PTBDD2       equ    2                                         ; Data Direction for Port B Bit 2
PTBDD_PTBDD4       equ    4                                         ; Data Direction for Port B Bit 4
PTBDD_PTBDD5       equ    5                                         ; Data Direction for Port B Bit 5
PTBDD_PTBDD6       equ    6                                         ; Data Direction for Port B Bit 6
PTBDD_PTBDD7       equ    7                                         ; Data Direction for Port B Bit 7
; bit position masks
mPTBDD_PTBDD0      equ    00000001b
mPTBDD_PTBDD1      equ    00000010b
mPTBDD_PTBDD2      equ    00000100b
mPTBDD_PTBDD4      equ    00010000b
mPTBDD_PTBDD5      equ    00100000b
mPTBDD_PTBDD6      equ    01000000b
mPTBDD_PTBDD7      equ    10000000b


;*** PTCD - Port C Data Register; 0x00000004 ***
PTCD               equ    $00000004                                ;*** PTCD - Port C Data Register; 0x00000004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCD_PTCD0         equ    0                                         ; Port C Data Register Bit 0
PTCD_PTCD1         equ    1                                         ; Port C Data Register Bit 1
PTCD_PTCD2         equ    2                                         ; Port C Data Register Bit 2
PTCD_PTCD3         equ    3                                         ; Port C Data Register Bit 3
PTCD_PTCD4         equ    4                                         ; Port C Data Register Bit 4
PTCD_PTCD5         equ    5                                         ; Port C Data Register Bit 5
PTCD_PTCD6         equ    6                                         ; Port C Data Register Bit 6
PTCD_PTCD7         equ    7                                         ; Port C Data Register Bit 7
; bit position masks
mPTCD_PTCD0        equ    00000001b
mPTCD_PTCD1        equ    00000010b
mPTCD_PTCD2        equ    00000100b
mPTCD_PTCD3        equ    00001000b
mPTCD_PTCD4        equ    00010000b
mPTCD_PTCD5        equ    00100000b
mPTCD_PTCD6        equ    01000000b
mPTCD_PTCD7        equ    10000000b


;*** PTCDD - Port C Data Direction Register; 0x00000005 ***
PTCDD              equ    $00000005                                ;*** PTCDD - Port C Data Direction Register; 0x00000005 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDD_PTCDD0       equ    0                                         ; Data Direction for Port C Bit 0
PTCDD_PTCDD1       equ    1                                         ; Data Direction for Port C Bit 1
PTCDD_PTCDD2       equ    2                                         ; Data Direction for Port C Bit 2
PTCDD_PTCDD3       equ    3                                         ; Data Direction for Port C Bit 3
PTCDD_PTCDD4       equ    4                                         ; Data Direction for Port C Bit 4
PTCDD_PTCDD5       equ    5                                         ; Data Direction for Port C Bit 5
PTCDD_PTCDD6       equ    6                                         ; Data Direction for Port C Bit 6
PTCDD_PTCDD7       equ    7                                         ; Data Direction for Port C Bit 7
; bit position masks
mPTCDD_PTCDD0      equ    00000001b
mPTCDD_PTCDD1      equ    00000010b
mPTCDD_PTCDD2      equ    00000100b
mPTCDD_PTCDD3      equ    00001000b
mPTCDD_PTCDD4      equ    00010000b
mPTCDD_PTCDD5      equ    00100000b
mPTCDD_PTCDD6      equ    01000000b
mPTCDD_PTCDD7      equ    10000000b


;*** PTDD - Port D Data Register; 0x00000006 ***
PTDD               equ    $00000006                                ;*** PTDD - Port D Data Register; 0x00000006 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDD_PTDD0         equ    0                                         ; Port D Data Register Bit 0
PTDD_PTDD1         equ    1                                         ; Port D Data Register Bit 1
PTDD_PTDD2         equ    2                                         ; Port D Data Register Bit 2
PTDD_PTDD3         equ    3                                         ; Port D Data Register Bit 3
PTDD_PTDD4         equ    4                                         ; Port D Data Register Bit 4
PTDD_PTDD5         equ    5                                         ; Port D Data Register Bit 5
PTDD_PTDD6         equ    6                                         ; Port D Data Register Bit 6
PTDD_PTDD7         equ    7                                         ; Port D Data Register Bit 7
; bit position masks
mPTDD_PTDD0        equ    00000001b
mPTDD_PTDD1        equ    00000010b
mPTDD_PTDD2        equ    00000100b
mPTDD_PTDD3        equ    00001000b
mPTDD_PTDD4        equ    00010000b
mPTDD_PTDD5        equ    00100000b
mPTDD_PTDD6        equ    01000000b
mPTDD_PTDD7        equ    10000000b


;*** PTDDD - Port D Data Direction Register; 0x00000007 ***
PTDDD              equ    $00000007                                ;*** PTDDD - Port D Data Direction Register; 0x00000007 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDD_PTDDD0       equ    0                                         ; Data Direction for Port D Bit 0
PTDDD_PTDDD1       equ    1                                         ; Data Direction for Port D Bit 1
PTDDD_PTDDD2       equ    2                                         ; Data Direction for Port D Bit 2
PTDDD_PTDDD3       equ    3                                         ; Data Direction for Port D Bit 3
PTDDD_PTDDD4       equ    4                                         ; Data Direction for Port D Bit 4
PTDDD_PTDDD5       equ    5                                         ; Data Direction for Port D Bit 5
PTDDD_PTDDD6       equ    6                                         ; Data Direction for Port D Bit 6
PTDDD_PTDDD7       equ    7                                         ; Data Direction for Port D Bit 7
; bit position masks
mPTDDD_PTDDD0      equ    00000001b
mPTDDD_PTDDD1      equ    00000010b
mPTDDD_PTDDD2      equ    00000100b
mPTDDD_PTDDD3      equ    00001000b
mPTDDD_PTDDD4      equ    00010000b
mPTDDD_PTDDD5      equ    00100000b
mPTDDD_PTDDD6      equ    01000000b
mPTDDD_PTDDD7      equ    10000000b


;*** PTED - Port E Data Register; 0x00000008 ***
PTED               equ    $00000008                                ;*** PTED - Port E Data Register; 0x00000008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTED_PTED0         equ    0                                         ; Port E Data Register Bit 0
PTED_PTED1         equ    1                                         ; Port E Data Register Bit 1
PTED_PTED2         equ    2                                         ; Port E Data Register Bit 2
PTED_PTED3         equ    3                                         ; Port E Data Register Bit 3
PTED_PTED4         equ    4                                         ; Port E Data Register Bit 4
PTED_PTED5         equ    5                                         ; Port E Data Register Bit 5
PTED_PTED6         equ    6                                         ; Port E Data Register Bit 6
PTED_PTED7         equ    7                                         ; Port E Data Register Bit 7
; bit position masks
mPTED_PTED0        equ    00000001b
mPTED_PTED1        equ    00000010b
mPTED_PTED2        equ    00000100b
mPTED_PTED3        equ    00001000b
mPTED_PTED4        equ    00010000b
mPTED_PTED5        equ    00100000b
mPTED_PTED6        equ    01000000b
mPTED_PTED7        equ    10000000b


;*** PTEDD - Port E Data Direction Register; 0x00000009 ***
PTEDD              equ    $00000009                                ;*** PTEDD - Port E Data Direction Register; 0x00000009 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDD_PTEDD0       equ    0                                         ; Data Direction for Port E Bit 0
PTEDD_PTEDD1       equ    1                                         ; Data Direction for Port E Bit 1
PTEDD_PTEDD2       equ    2                                         ; Data Direction for Port E Bit 2
PTEDD_PTEDD3       equ    3                                         ; Data Direction for Port E Bit 3
PTEDD_PTEDD4       equ    4                                         ; Data Direction for Port E Bit 4
PTEDD_PTEDD5       equ    5                                         ; Data Direction for Port E Bit 5
PTEDD_PTEDD6       equ    6                                         ; Data Direction for Port E Bit 6
PTEDD_PTEDD7       equ    7                                         ; Data Direction for Port E Bit 7
; bit position masks
mPTEDD_PTEDD0      equ    00000001b
mPTEDD_PTEDD1      equ    00000010b
mPTEDD_PTEDD2      equ    00000100b
mPTEDD_PTEDD3      equ    00001000b
mPTEDD_PTEDD4      equ    00010000b
mPTEDD_PTEDD5      equ    00100000b
mPTEDD_PTEDD6      equ    01000000b
mPTEDD_PTEDD7      equ    10000000b


;*** KBISC - KBI Status and Control Register; 0x0000000C ***
KBISC              equ    $0000000C                                ;*** KBISC - KBI Status and Control Register; 0x0000000C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBISC_KBIMOD       equ    0                                         ; Keyboard Detection Mode
KBISC_KBIE         equ    1                                         ; Keyboard Interrupt Enable
KBISC_KBACK        equ    2                                         ; Keyboard Interrupt Acknowledge
KBISC_KBF          equ    3                                         ; Keyboard Interrupt Flag
; bit position masks
mKBISC_KBIMOD      equ    00000001b
mKBISC_KBIE        equ    00000010b
mKBISC_KBACK       equ    00000100b
mKBISC_KBF         equ    00001000b


;*** KBIPE - KBI Pin Enable Register; 0x0000000D ***
KBIPE              equ    $0000000D                                ;*** KBIPE - KBI Pin Enable Register; 0x0000000D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIPE_KBIPE0       equ    0                                         ; Keyboard Pin Enable for KBI Port Bit 0
KBIPE_KBIPE1       equ    1                                         ; Keyboard Pin Enable for KBI Port Bit 1
KBIPE_KBIPE2       equ    2                                         ; Keyboard Pin Enable for KBI Port Bit 2
KBIPE_KBIPE3       equ    3                                         ; Keyboard Pin Enable for KBI Port Bit 3
KBIPE_KBIPE4       equ    4                                         ; Keyboard Pin Enable for KBI Port Bit 4
KBIPE_KBIPE5       equ    5                                         ; Keyboard Pin Enable for KBI Port Bit 5
KBIPE_KBIPE6       equ    6                                         ; Keyboard Pin Enable for KBI Port Bit 6
KBIPE_KBIPE7       equ    7                                         ; Keyboard Pin Enable for KBI Port Bit 7
; bit position masks
mKBIPE_KBIPE0      equ    00000001b
mKBIPE_KBIPE1      equ    00000010b
mKBIPE_KBIPE2      equ    00000100b
mKBIPE_KBIPE3      equ    00001000b
mKBIPE_KBIPE4      equ    00010000b
mKBIPE_KBIPE5      equ    00100000b
mKBIPE_KBIPE6      equ    01000000b
mKBIPE_KBIPE7      equ    10000000b


;*** KBIES - KBI Edge Select Register; 0x0000000E ***
KBIES              equ    $0000000E                                ;*** KBIES - KBI Edge Select Register; 0x0000000E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
KBIES_KBEDG0       equ    0                                         ; Keyboard Edge Select Bit 0
KBIES_KBEDG1       equ    1                                         ; Keyboard Edge Select Bit 1
KBIES_KBEDG2       equ    2                                         ; Keyboard Edge Select Bit 2
KBIES_KBEDG3       equ    3                                         ; Keyboard Edge Select Bit 3
KBIES_KBEDG4       equ    4                                         ; Keyboard Edge Select Bit 4
KBIES_KBEDG5       equ    5                                         ; Keyboard Edge Select Bit 5
KBIES_KBEDG6       equ    6                                         ; Keyboard Edge Select Bit 6
KBIES_KBEDG7       equ    7                                         ; Keyboard Edge Select Bit 7
; bit position masks
mKBIES_KBEDG0      equ    00000001b
mKBIES_KBEDG1      equ    00000010b
mKBIES_KBEDG2      equ    00000100b
mKBIES_KBEDG3      equ    00001000b
mKBIES_KBEDG4      equ    00010000b
mKBIES_KBEDG5      equ    00100000b
mKBIES_KBEDG6      equ    01000000b
mKBIES_KBEDG7      equ    10000000b


;*** IRQSC - Interrupt request status and control register; 0x0000000F ***
IRQSC              equ    $0000000F                                ;*** IRQSC - Interrupt request status and control register; 0x0000000F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IRQSC_IRQMOD       equ    0                                         ; IRQ Detection Mode
IRQSC_IRQIE        equ    1                                         ; IRQ Interrupt Enable
IRQSC_IRQACK       equ    2                                         ; IRQ Acknowledge
IRQSC_IRQF         equ    3                                         ; IRQ Flag
IRQSC_IRQPE        equ    4                                         ; IRQ Pin Enable
IRQSC_IRQEDG       equ    5                                         ; IRQ Edge Select
IRQSC_IRQPDD       equ    6                                         ; IRQ Pull Device Disable
; bit position masks
mIRQSC_IRQMOD      equ    00000001b
mIRQSC_IRQIE       equ    00000010b
mIRQSC_IRQACK      equ    00000100b
mIRQSC_IRQF        equ    00001000b
mIRQSC_IRQPE       equ    00010000b
mIRQSC_IRQEDG      equ    00100000b
mIRQSC_IRQPDD      equ    01000000b


;*** ADCSC1A - Status and Control Register 1A; 0x00000010 ***
ADCSC1A            equ    $00000010                                ;*** ADCSC1A - Status and Control Register 1A; 0x00000010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1A_ADCHA0     equ    0                                         ; Input Channel Select Bit 0
ADCSC1A_ADCHA1     equ    1                                         ; Input Channel Select Bit 1
ADCSC1A_ADCHA2     equ    2                                         ; Input Channel Select Bit 2
ADCSC1A_ADCHA3     equ    3                                         ; Input Channel Select Bit 3
ADCSC1A_ADCHA4     equ    4                                         ; Input Channel Select Bit 4
ADCSC1A_DIFFA      equ    5                                         ; Differential Mode Enable - DIFFA configures the ADC to operate in differential mode
ADCSC1A_AIENA      equ    6                                         ; Interrupt Enable - AIENA enables conversion complete interrupts. When COCOA becomes set while the respective AIENA is high, an interrupt is asserted
ADCSC1A_COCOA      equ    7                                         ; Conversion Complete Flag
; bit position masks
mADCSC1A_ADCHA0    equ    00000001b
mADCSC1A_ADCHA1    equ    00000010b
mADCSC1A_ADCHA2    equ    00000100b
mADCSC1A_ADCHA3    equ    00001000b
mADCSC1A_ADCHA4    equ    00010000b
mADCSC1A_DIFFA     equ    00100000b
mADCSC1A_AIENA     equ    01000000b
mADCSC1A_COCOA     equ    10000000b


;*** ADCSC1B - Status and Control Register 1B; 0x00000011 ***
ADCSC1B            equ    $00000011                                ;*** ADCSC1B - Status and Control Register 1B; 0x00000011 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC1B_ADCHB0     equ    0                                         ; Input Channel Select Bit 0
ADCSC1B_ADCHB1     equ    1                                         ; Input Channel Select Bit 1
ADCSC1B_ADCHB2     equ    2                                         ; Input Channel Select Bit 2
ADCSC1B_ADCHB3     equ    3                                         ; Input Channel Select Bit 3
ADCSC1B_ADCHB4     equ    4                                         ; Input Channel Select Bit 4
ADCSC1B_DIFFB      equ    5                                         ; Differential Mode Enable - DIFFB configures the ADC to operate in differential mode
ADCSC1B_AIENB      equ    6                                         ; Interrupt Enable - AIENB enables conversion complete interrupts. When COCOB becomes set while the respective AIENB is high, an interrupt is asserted
ADCSC1B_COCOB      equ    7                                         ; Conversion Complete Flag
; bit position masks
mADCSC1B_ADCHB0    equ    00000001b
mADCSC1B_ADCHB1    equ    00000010b
mADCSC1B_ADCHB2    equ    00000100b
mADCSC1B_ADCHB3    equ    00001000b
mADCSC1B_ADCHB4    equ    00010000b
mADCSC1B_DIFFB     equ    00100000b
mADCSC1B_AIENB     equ    01000000b
mADCSC1B_COCOB     equ    10000000b


;*** ADCCFG1 - Configuration Register 1; 0x00000012 ***
ADCCFG1            equ    $00000012                                ;*** ADCCFG1 - Configuration Register 1; 0x00000012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG1_ADICLK0    equ    0                                         ; Input Clock Select Bit 0
ADCCFG1_ADICLK1    equ    1                                         ; Input Clock Select Bit 1
ADCCFG1_MODE0      equ    2                                         ; Conversion Mode Selection Bit 0
ADCCFG1_MODE1      equ    3                                         ; Conversion Mode Selection Bit 1
ADCCFG1_ADLSMP     equ    4                                         ; Long Sample Time Configuration
ADCCFG1_ADIV0      equ    5                                         ; Clock Divide Select Bit 0
ADCCFG1_ADIV1      equ    6                                         ; Clock Divide Select Bit 1
ADCCFG1_ADLPC      equ    7                                         ; Low Power Configuration
; bit position masks
mADCCFG1_ADICLK0   equ    00000001b
mADCCFG1_ADICLK1   equ    00000010b
mADCCFG1_MODE0     equ    00000100b
mADCCFG1_MODE1     equ    00001000b
mADCCFG1_ADLSMP    equ    00010000b
mADCCFG1_ADIV0     equ    00100000b
mADCCFG1_ADIV1     equ    01000000b
mADCCFG1_ADLPC     equ    10000000b


;*** ADCCFG2 - Configuration Register 2; 0x00000013 ***
ADCCFG2            equ    $00000013                                ;*** ADCCFG2 - Configuration Register 2; 0x00000013 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCFG2_ADLSTS0    equ    0                                         ; Long Sample Time Select Bit 0
ADCCFG2_ADLSTS1    equ    1                                         ; Long Sample Time Select Bit 1
ADCCFG2_ADHSC      equ    2                                         ; High Speed Configuration
ADCCFG2_ADACKEN    equ    3                                         ; Asynchronous Clock Output Enable
; bit position masks
mADCCFG2_ADLSTS0   equ    00000001b
mADCCFG2_ADLSTS1   equ    00000010b
mADCCFG2_ADHSC     equ    00000100b
mADCCFG2_ADACKEN   equ    00001000b


;*** ADCRA - Data Result Register A; 0x00000014 ***
ADCRA              equ    $00000014                                ;*** ADCRA - Data Result Register A; 0x00000014 ***


;*** ADCRHA - Data Result High Register A; 0x00000014 ***
ADCRHA             equ    $00000014                                ;*** ADCRHA - Data Result High Register A; 0x00000014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHA_D8          equ    0                                         ; ADC Result Data Bit 8
ADCRHA_D9          equ    1                                         ; ADC Result Data Bit 9
ADCRHA_D10         equ    2                                         ; ADC Result Data Bit 10
ADCRHA_D11         equ    3                                         ; ADC Result Data Bit 11
ADCRHA_D12         equ    4                                         ; ADC Result Data Bit 12
ADCRHA_D13         equ    5                                         ; ADC Result Data Bit 13
ADCRHA_D14         equ    6                                         ; ADC Result Data Bit 14
ADCRHA_D15         equ    7                                         ; ADC Result Data Bit 15
; bit position masks
mADCRHA_D8         equ    00000001b
mADCRHA_D9         equ    00000010b
mADCRHA_D10        equ    00000100b
mADCRHA_D11        equ    00001000b
mADCRHA_D12        equ    00010000b
mADCRHA_D13        equ    00100000b
mADCRHA_D14        equ    01000000b
mADCRHA_D15        equ    10000000b


;*** ADCRLA - Data Result Low Register A; 0x00000015 ***
ADCRLA             equ    $00000015                                ;*** ADCRLA - Data Result Low Register A; 0x00000015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLA_D0          equ    0                                         ; ADC Result Data Bit 0
ADCRLA_D1          equ    1                                         ; ADC Result Data Bit 1
ADCRLA_D2          equ    2                                         ; ADC Result Data Bit 2
ADCRLA_D3          equ    3                                         ; ADC Result Data Bit 3
ADCRLA_D4          equ    4                                         ; ADC Result Data Bit 4
ADCRLA_D5          equ    5                                         ; ADC Result Data Bit 5
ADCRLA_D6          equ    6                                         ; ADC Result Data Bit 6
ADCRLA_D7          equ    7                                         ; ADC Result Data Bit 7
; bit position masks
mADCRLA_D0         equ    00000001b
mADCRLA_D1         equ    00000010b
mADCRLA_D2         equ    00000100b
mADCRLA_D3         equ    00001000b
mADCRLA_D4         equ    00010000b
mADCRLA_D5         equ    00100000b
mADCRLA_D6         equ    01000000b
mADCRLA_D7         equ    10000000b


;*** ADCRB - Data Result Register B; 0x00000016 ***
ADCRB              equ    $00000016                                ;*** ADCRB - Data Result Register B; 0x00000016 ***


;*** ADCRHB - Data Result High Register B; 0x00000016 ***
ADCRHB             equ    $00000016                                ;*** ADCRHB - Data Result High Register B; 0x00000016 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRHB_D8          equ    0                                         ; ADC Result Data Bit 8
ADCRHB_D9          equ    1                                         ; ADC Result Data Bit 9
ADCRHB_D10         equ    2                                         ; ADC Result Data Bit 10
ADCRHB_D11         equ    3                                         ; ADC Result Data Bit 11
ADCRHB_D12         equ    4                                         ; ADC Result Data Bit 12
ADCRHB_D13         equ    5                                         ; ADC Result Data Bit 13
ADCRHB_D14         equ    6                                         ; ADC Result Data Bit 14
ADCRHB_D15         equ    7                                         ; ADC Result Data Bit 15
; bit position masks
mADCRHB_D8         equ    00000001b
mADCRHB_D9         equ    00000010b
mADCRHB_D10        equ    00000100b
mADCRHB_D11        equ    00001000b
mADCRHB_D12        equ    00010000b
mADCRHB_D13        equ    00100000b
mADCRHB_D14        equ    01000000b
mADCRHB_D15        equ    10000000b


;*** ADCRLB - Data Result Low Register B; 0x00000017 ***
ADCRLB             equ    $00000017                                ;*** ADCRLB - Data Result Low Register B; 0x00000017 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCRLB_D0          equ    0                                         ; ADC Result Data Bit 0
ADCRLB_D1          equ    1                                         ; ADC Result Data Bit 1
ADCRLB_D2          equ    2                                         ; ADC Result Data Bit 2
ADCRLB_D3          equ    3                                         ; ADC Result Data Bit 3
ADCRLB_D4          equ    4                                         ; ADC Result Data Bit 4
ADCRLB_D5          equ    5                                         ; ADC Result Data Bit 5
ADCRLB_D6          equ    6                                         ; ADC Result Data Bit 6
ADCRLB_D7          equ    7                                         ; ADC Result Data Bit 7
; bit position masks
mADCRLB_D0         equ    00000001b
mADCRLB_D1         equ    00000010b
mADCRLB_D2         equ    00000100b
mADCRLB_D3         equ    00001000b
mADCRLB_D4         equ    00010000b
mADCRLB_D5         equ    00100000b
mADCRLB_D6         equ    01000000b
mADCRLB_D7         equ    10000000b


;*** LCDC0 - LCD Control Register 0; 0x00000018 ***
LCDC0              equ    $00000018                                ;*** LCDC0 - LCD Control Register 0; 0x00000018 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDC0_DUTY0        equ    0                                         ; LCD Duty Select Bit 0
LCDC0_DUTY1        equ    1                                         ; LCD Duty Select Bit 1
LCDC0_DUTY2        equ    2                                         ; LCD Duty Select Bit 2
LCDC0_LCLK0        equ    3                                         ; LCD Clock Prescaler Bit 0
LCDC0_LCLK1        equ    4                                         ; LCD Clock Prescaler Bit 1
LCDC0_LCLK2        equ    5                                         ; LCD Clock Prescaler Bit 2
LCDC0_SOURCE       equ    6                                         ; LCD Clock Source Select
LCDC0_LCDEN        equ    7                                         ; LCD Driver Enable
; bit position masks
mLCDC0_DUTY0       equ    00000001b
mLCDC0_DUTY1       equ    00000010b
mLCDC0_DUTY2       equ    00000100b
mLCDC0_LCLK0       equ    00001000b
mLCDC0_LCLK1       equ    00010000b
mLCDC0_LCLK2       equ    00100000b
mLCDC0_SOURCE      equ    01000000b
mLCDC0_LCDEN       equ    10000000b


;*** LCDC1 - LCD Control Register 1; 0x00000019 ***
LCDC1              equ    $00000019                                ;*** LCDC1 - LCD Control Register 1; 0x00000019 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDC1_LCDSTP       equ    0                                         ; LCD Module Driver and Charge Pump Stop While in Stop2 or Stop3 Mode
LCDC1_LCDWAI       equ    1                                         ; LCD Module Driver and Charge Pump Stop While in Wait Mode
LCDC1_FCDEN        equ    2                                         ; Full Complementary Drive Enable
LCDC1_LCDIEN       equ    7                                         ; LCD Module Frame Frequency Interrupt Enable
; bit position masks
mLCDC1_LCDSTP      equ    00000001b
mLCDC1_LCDWAI      equ    00000010b
mLCDC1_FCDEN       equ    00000100b
mLCDC1_LCDIEN      equ    10000000b


;*** LCDSUPPLY - LCD Voltage Supply Register; 0x0000001A ***
LCDSUPPLY          equ    $0000001A                                ;*** LCDSUPPLY - LCD Voltage Supply Register; 0x0000001A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDSUPPLY_VSUPPLY0 equ    0                                         ; Voltage Supply Control Bit 0
LCDSUPPLY_VSUPPLY1 equ    1                                         ; Voltage Supply Control Bit 1
LCDSUPPLY_BBYPASS  equ    2                                         ; Op Amp Control
LCDSUPPLY_LADJ0    equ    4                                         ; LCD Module Load Adjust Bit 0
LCDSUPPLY_LADJ1    equ    5                                         ; LCD Module Load Adjust Bit 1
LCDSUPPLY_HREFSEL  equ    6                                         ; High Reference Select
LCDSUPPLY_CPSEL    equ    7                                         ; Charge Pump or Resistor Bias Select
; bit position masks
mLCDSUPPLY_VSUPPLY0 equ    00000001b
mLCDSUPPLY_VSUPPLY1 equ    00000010b
mLCDSUPPLY_BBYPASS equ    00000100b
mLCDSUPPLY_LADJ0   equ    00010000b
mLCDSUPPLY_LADJ1   equ    00100000b
mLCDSUPPLY_HREFSEL equ    01000000b
mLCDSUPPLY_CPSEL   equ    10000000b


;*** LCDRVC - LCD Regulated Voltage Control Register; 0x0000001B ***
LCDRVC             equ    $0000001B                                ;*** LCDRVC - LCD Regulated Voltage Control Register; 0x0000001B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDRVC_RVTRIM0     equ    0                                         ; Regulated Voltage Trim Bit 0
LCDRVC_RVTRIM1     equ    1                                         ; Regulated Voltage Trim Bit 1
LCDRVC_RVTRIM2     equ    2                                         ; Regulated Voltage Trim Bit 2
LCDRVC_RVTRIM3     equ    3                                         ; Regulated Voltage Trim Bit 3
LCDRVC_RVEN        equ    7                                         ; Regulated Voltage Enable
; bit position masks
mLCDRVC_RVTRIM0    equ    00000001b
mLCDRVC_RVTRIM1    equ    00000010b
mLCDRVC_RVTRIM2    equ    00000100b
mLCDRVC_RVTRIM3    equ    00001000b
mLCDRVC_RVEN       equ    10000000b


;*** LCDBCTL - LCD Blink Control Register; 0x0000001C ***
LCDBCTL            equ    $0000001C                                ;*** LCDBCTL - LCD Blink Control Register; 0x0000001C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBCTL_BRATE0     equ    0                                         ; Blink-Rate Configuration Bit 0
LCDBCTL_BRATE1     equ    1                                         ; Blink-Rate Configuration Bit 1
LCDBCTL_BRATE2     equ    2                                         ; Blink-Rate Configuration Bit 2
LCDBCTL_BMODE      equ    3                                         ; Blink Mode
LCDBCTL_BLANK      equ    5                                         ; Blank Display Mode
LCDBCTL_ALT        equ    6                                         ; Alternate Display Mode
LCDBCTL_BLINK      equ    7                                         ; Blink Command
; bit position masks
mLCDBCTL_BRATE0    equ    00000001b
mLCDBCTL_BRATE1    equ    00000010b
mLCDBCTL_BRATE2    equ    00000100b
mLCDBCTL_BMODE     equ    00001000b
mLCDBCTL_BLANK     equ    00100000b
mLCDBCTL_ALT       equ    01000000b
mLCDBCTL_BLINK     equ    10000000b


;*** LCDS - LCD Status Register; 0x0000001D ***
LCDS               equ    $0000001D                                ;*** LCDS - LCD Status Register; 0x0000001D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDS_LCDIF         equ    7                                         ; LCD Interrupt Flag
; bit position masks
mLCDS_LCDIF        equ    10000000b


;*** ACMPSC - ACMP Status and Control Register; 0x0000001F ***
ACMPSC             equ    $0000001F                                ;*** ACMPSC - ACMP Status and Control Register; 0x0000001F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ACMPSC_ACMOD0      equ    0                                         ; Analog Comparator Mode Bit 0
ACMPSC_ACMOD1      equ    1                                         ; Analog Comparator Mode Bit 1
ACMPSC_ACOPE       equ    2                                         ; Analog Comparator Output Pin Enable
ACMPSC_ACO         equ    3                                         ; Analog Comparator Output
ACMPSC_ACIE        equ    4                                         ; Analog Comparator Interrupt Enable
ACMPSC_ACF         equ    5                                         ; Analog Comparator Flag
ACMPSC_ACBGS       equ    6                                         ; Analog Comparator Bandgap Select
ACMPSC_ACME        equ    7                                         ; Analog Comparator Module Enable
; bit position masks
mACMPSC_ACMOD0     equ    00000001b
mACMPSC_ACMOD1     equ    00000010b
mACMPSC_ACOPE      equ    00000100b
mACMPSC_ACO        equ    00001000b
mACMPSC_ACIE       equ    00010000b
mACMPSC_ACF        equ    00100000b
mACMPSC_ACBGS      equ    01000000b
mACMPSC_ACME       equ    10000000b


;*** SCI1BD - SCI1 Baud Rate Register; 0x00000020 ***
SCI1BD             equ    $00000020                                ;*** SCI1BD - SCI1 Baud Rate Register; 0x00000020 ***


;*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000020 ***
SCI1BDH            equ    $00000020                                ;*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000020 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDH_SBR8       equ    0                                         ; Baud Rate Modulo Divisor Bit 8
SCI1BDH_SBR9       equ    1                                         ; Baud Rate Modulo Divisor Bit 9
SCI1BDH_SBR10      equ    2                                         ; Baud Rate Modulo Divisor Bit 10
SCI1BDH_SBR11      equ    3                                         ; Baud Rate Modulo Divisor Bit 11
SCI1BDH_SBR12      equ    4                                         ; Baud Rate Modulo Divisor Bit 12
SCI1BDH_RXEDGIE    equ    6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI1BDH_LBKDIE     equ    7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI1BDH_SBR8      equ    00000001b
mSCI1BDH_SBR9      equ    00000010b
mSCI1BDH_SBR10     equ    00000100b
mSCI1BDH_SBR11     equ    00001000b
mSCI1BDH_SBR12     equ    00010000b
mSCI1BDH_RXEDGIE   equ    01000000b
mSCI1BDH_LBKDIE    equ    10000000b


;*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000021 ***
SCI1BDL            equ    $00000021                                ;*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000021 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1BDL_SBR0       equ    0                                         ; Baud Rate Modulo Divisor Bit 0
SCI1BDL_SBR1       equ    1                                         ; Baud Rate Modulo Divisor Bit 1
SCI1BDL_SBR2       equ    2                                         ; Baud Rate Modulo Divisor Bit 2
SCI1BDL_SBR3       equ    3                                         ; Baud Rate Modulo Divisor Bit 3
SCI1BDL_SBR4       equ    4                                         ; Baud Rate Modulo Divisor Bit 4
SCI1BDL_SBR5       equ    5                                         ; Baud Rate Modulo Divisor Bit 5
SCI1BDL_SBR6       equ    6                                         ; Baud Rate Modulo Divisor Bit 6
SCI1BDL_SBR7       equ    7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI1BDL_SBR0      equ    00000001b
mSCI1BDL_SBR1      equ    00000010b
mSCI1BDL_SBR2      equ    00000100b
mSCI1BDL_SBR3      equ    00001000b
mSCI1BDL_SBR4      equ    00010000b
mSCI1BDL_SBR5      equ    00100000b
mSCI1BDL_SBR6      equ    01000000b
mSCI1BDL_SBR7      equ    10000000b


;*** SCI1C1 - SCI1 Control Register 1; 0x00000022 ***
SCI1C1             equ    $00000022                                ;*** SCI1C1 - SCI1 Control Register 1; 0x00000022 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C1_PT          equ    0                                         ; Parity Type
SCI1C1_PE          equ    1                                         ; Parity Enable
SCI1C1_ILT         equ    2                                         ; Idle Line Type Select
SCI1C1_WAKE        equ    3                                         ; Receiver Wakeup Method Select
SCI1C1_M           equ    4                                         ; 9-Bit or 8-Bit Mode Select
SCI1C1_RSRC        equ    5                                         ; Receiver Source Select
SCI1C1_SCISWAI     equ    6                                         ; SCI Stops in Wait Mode
SCI1C1_LOOPS       equ    7                                         ; Loop Mode Select
; bit position masks
mSCI1C1_PT         equ    00000001b
mSCI1C1_PE         equ    00000010b
mSCI1C1_ILT        equ    00000100b
mSCI1C1_WAKE       equ    00001000b
mSCI1C1_M          equ    00010000b
mSCI1C1_RSRC       equ    00100000b
mSCI1C1_SCISWAI    equ    01000000b
mSCI1C1_LOOPS      equ    10000000b


;*** SCI1C2 - SCI1 Control Register 2; 0x00000023 ***
SCI1C2             equ    $00000023                                ;*** SCI1C2 - SCI1 Control Register 2; 0x00000023 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C2_SBK         equ    0                                         ; Send Break
SCI1C2_RWU         equ    1                                         ; Receiver Wakeup Control
SCI1C2_RE          equ    2                                         ; Receiver Enable
SCI1C2_TE          equ    3                                         ; Transmitter Enable
SCI1C2_ILIE        equ    4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI1C2_RIE         equ    5                                         ; Receiver Interrupt Enable (for RDRF)
SCI1C2_TCIE        equ    6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI1C2_TIE         equ    7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI1C2_SBK        equ    00000001b
mSCI1C2_RWU        equ    00000010b
mSCI1C2_RE         equ    00000100b
mSCI1C2_TE         equ    00001000b
mSCI1C2_ILIE       equ    00010000b
mSCI1C2_RIE        equ    00100000b
mSCI1C2_TCIE       equ    01000000b
mSCI1C2_TIE        equ    10000000b


;*** SCI1S1 - SCI1 Status Register 1; 0x00000024 ***
SCI1S1             equ    $00000024                                ;*** SCI1S1 - SCI1 Status Register 1; 0x00000024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S1_PF          equ    0                                         ; Parity Error Flag
SCI1S1_FE          equ    1                                         ; Framing Error Flag
SCI1S1_NF          equ    2                                         ; Noise Flag
SCI1S1_OR          equ    3                                         ; Receiver Overrun Flag
SCI1S1_IDLE        equ    4                                         ; Idle Line Flag
SCI1S1_RDRF        equ    5                                         ; Receive Data Register Full Flag
SCI1S1_TC          equ    6                                         ; Transmission Complete Flag
SCI1S1_TDRE        equ    7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI1S1_PF         equ    00000001b
mSCI1S1_FE         equ    00000010b
mSCI1S1_NF         equ    00000100b
mSCI1S1_OR         equ    00001000b
mSCI1S1_IDLE       equ    00010000b
mSCI1S1_RDRF       equ    00100000b
mSCI1S1_TC         equ    01000000b
mSCI1S1_TDRE       equ    10000000b


;*** SCI1S2 - SCI1 Status Register 2; 0x00000025 ***
SCI1S2             equ    $00000025                                ;*** SCI1S2 - SCI1 Status Register 2; 0x00000025 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1S2_RAF         equ    0                                         ; Receiver Active Flag
SCI1S2_LBKDE       equ    1                                         ; LIN Break Detection Enable
SCI1S2_BRK13       equ    2                                         ; Break Character Generation Length
SCI1S2_RWUID       equ    3                                         ; Receive Wake Up Idle Detect
SCI1S2_RXINV       equ    4                                         ; Receive Data Inversion
SCI1S2_RXEDGIF     equ    6                                         ; RxD Pin Active Edge Interrupt Flag
SCI1S2_LBKDIF      equ    7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI1S2_RAF        equ    00000001b
mSCI1S2_LBKDE      equ    00000010b
mSCI1S2_BRK13      equ    00000100b
mSCI1S2_RWUID      equ    00001000b
mSCI1S2_RXINV      equ    00010000b
mSCI1S2_RXEDGIF    equ    01000000b
mSCI1S2_LBKDIF     equ    10000000b


;*** SCI1C3 - SCI1 Control Register 3; 0x00000026 ***
SCI1C3             equ    $00000026                                ;*** SCI1C3 - SCI1 Control Register 3; 0x00000026 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1C3_PEIE        equ    0                                         ; Parity Error Interrupt Enable
SCI1C3_FEIE        equ    1                                         ; Framing Error Interrupt Enable
SCI1C3_NEIE        equ    2                                         ; Noise Error Interrupt Enable
SCI1C3_ORIE        equ    3                                         ; Overrun Interrupt Enable
SCI1C3_TXINV       equ    4                                         ; Transmit Data Inversion
SCI1C3_TXDIR       equ    5                                         ; TxD Pin Direction in Single-Wire Mode
SCI1C3_T8          equ    6                                         ; Ninth Data Bit for Transmitter
SCI1C3_R8          equ    7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI1C3_PEIE       equ    00000001b
mSCI1C3_FEIE       equ    00000010b
mSCI1C3_NEIE       equ    00000100b
mSCI1C3_ORIE       equ    00001000b
mSCI1C3_TXINV      equ    00010000b
mSCI1C3_TXDIR      equ    00100000b
mSCI1C3_T8         equ    01000000b
mSCI1C3_R8         equ    10000000b


;*** SCI1D - SCI1 Data Register; 0x00000027 ***
SCI1D              equ    $00000027                                ;*** SCI1D - SCI1 Data Register; 0x00000027 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI1D_R0_T0        equ    0                                         ; Receive/Transmit Data Bit 0
SCI1D_R1_T1        equ    1                                         ; Receive/Transmit Data Bit 1
SCI1D_R2_T2        equ    2                                         ; Receive/Transmit Data Bit 2
SCI1D_R3_T3        equ    3                                         ; Receive/Transmit Data Bit 3
SCI1D_R4_T4        equ    4                                         ; Receive/Transmit Data Bit 4
SCI1D_R5_T5        equ    5                                         ; Receive/Transmit Data Bit 5
SCI1D_R6_T6        equ    6                                         ; Receive/Transmit Data Bit 6
SCI1D_R7_T7        equ    7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI1D_R0_T0       equ    00000001b
mSCI1D_R1_T1       equ    00000010b
mSCI1D_R2_T2       equ    00000100b
mSCI1D_R3_T3       equ    00001000b
mSCI1D_R4_T4       equ    00010000b
mSCI1D_R5_T5       equ    00100000b
mSCI1D_R6_T6       equ    01000000b
mSCI1D_R7_T7       equ    10000000b


;*** SPIC1 - SPI Control Register 1; 0x00000028 ***
SPIC1              equ    $00000028                                ;*** SPIC1 - SPI Control Register 1; 0x00000028 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC1_LSBFE        equ    0                                         ; LSB First (Shifter Direction)
SPIC1_SSOE         equ    1                                         ; Slave Select Output Enable
SPIC1_CPHA         equ    2                                         ; Clock Phase
SPIC1_CPOL         equ    3                                         ; Clock Polarity
SPIC1_MSTR         equ    4                                         ; Master/Slave Mode Select
SPIC1_SPTIE        equ    5                                         ; SPI Transmit Interrupt Enable
SPIC1_SPE          equ    6                                         ; SPI System Enable
SPIC1_SPIE         equ    7                                         ; SPI Interrupt Enable (for SPRF and MODF)
; bit position masks
mSPIC1_LSBFE       equ    00000001b
mSPIC1_SSOE        equ    00000010b
mSPIC1_CPHA        equ    00000100b
mSPIC1_CPOL        equ    00001000b
mSPIC1_MSTR        equ    00010000b
mSPIC1_SPTIE       equ    00100000b
mSPIC1_SPE         equ    01000000b
mSPIC1_SPIE        equ    10000000b


;*** SPIC2 - SPI Control Register 2; 0x00000029 ***
SPIC2              equ    $00000029                                ;*** SPIC2 - SPI Control Register 2; 0x00000029 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIC2_SPC0         equ    0                                         ; SPI Pin Control 0
SPIC2_SPISWAI      equ    1                                         ; SPI Stop in Wait Mode
SPIC2_BIDIROE      equ    3                                         ; Bidirectional Mode Output Enable
SPIC2_MODFEN       equ    4                                         ; Master Mode-Fault Function Enable
; bit position masks
mSPIC2_SPC0        equ    00000001b
mSPIC2_SPISWAI     equ    00000010b
mSPIC2_BIDIROE     equ    00001000b
mSPIC2_MODFEN      equ    00010000b


;*** SPIBR - SPI Baud Rate Register; 0x0000002A ***
SPIBR              equ    $0000002A                                ;*** SPIBR - SPI Baud Rate Register; 0x0000002A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIBR_SPR0         equ    0                                         ; SPI Baud Rate Divisor Bit 0
SPIBR_SPR1         equ    1                                         ; SPI Baud Rate Divisor Bit 1
SPIBR_SPR2         equ    2                                         ; SPI Baud Rate Divisor Bit 2
SPIBR_SPR3         equ    3                                         ; SPI Baud Rate Divisor Bit 3
SPIBR_SPPR0        equ    4                                         ; SPI Baud Rate Prescale Divisor Bit 0
SPIBR_SPPR1        equ    5                                         ; SPI Baud Rate Prescale Divisor Bit 1
SPIBR_SPPR2        equ    6                                         ; SPI Baud Rate Prescale Divisor Bit 2
; bit position masks
mSPIBR_SPR0        equ    00000001b
mSPIBR_SPR1        equ    00000010b
mSPIBR_SPR2        equ    00000100b
mSPIBR_SPR3        equ    00001000b
mSPIBR_SPPR0       equ    00010000b
mSPIBR_SPPR1       equ    00100000b
mSPIBR_SPPR2       equ    01000000b


;*** SPIS - SPI Status Register; 0x0000002B ***
SPIS               equ    $0000002B                                ;*** SPIS - SPI Status Register; 0x0000002B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPIS_MODF          equ    4                                         ; Master Mode Fault Flag
SPIS_SPTEF         equ    5                                         ; SPI Transmit Buffer Empty Flag
SPIS_SPRF          equ    7                                         ; SPI Read Buffer Full Flag
; bit position masks
mSPIS_MODF         equ    00010000b
mSPIS_SPTEF        equ    00100000b
mSPIS_SPRF         equ    10000000b


;*** SPID - SPI Data Register; 0x0000002D ***
SPID               equ    $0000002D                                ;*** SPID - SPI Data Register; 0x0000002D ***


;*** PPAGE - Program Page Register; 0x00000030 ***
PPAGE              equ    $00000030                                ;*** PPAGE - Program Page Register; 0x00000030 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PPAGE_XA14         equ    0                                         ; Extended address, bit 14
PPAGE_XA15         equ    1                                         ; Extended address, bit 15
; bit position masks
mPPAGE_XA14        equ    00000001b
mPPAGE_XA15        equ    00000010b


;*** LAP2 - Linear Address Pointer Register 2; 0x00000031 ***
LAP2               equ    $00000031                                ;*** LAP2 - Linear Address Pointer Register 2; 0x00000031 ***


;*** LAP1 - Linear Address Pointer Register 1; 0x00000032 ***
LAP1               equ    $00000032                                ;*** LAP1 - Linear Address Pointer Register 1; 0x00000032 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP1_LA8           equ    0                                         ; Linear address pointer, bit 8
LAP1_LA9           equ    1                                         ; Linear address pointer, bit 9
LAP1_LA10          equ    2                                         ; Linear address pointer, bit 10
LAP1_LA11          equ    3                                         ; Linear address pointer, bit 11
LAP1_LA12          equ    4                                         ; Linear address pointer, bit 12
LAP1_LA13          equ    5                                         ; Linear address pointer, bit 13
LAP1_LA14          equ    6                                         ; Linear address pointer, bit 14
LAP1_LA15          equ    7                                         ; Linear address pointer, bit 15
; bit position masks
mLAP1_LA8          equ    00000001b
mLAP1_LA9          equ    00000010b
mLAP1_LA10         equ    00000100b
mLAP1_LA11         equ    00001000b
mLAP1_LA12         equ    00010000b
mLAP1_LA13         equ    00100000b
mLAP1_LA14         equ    01000000b
mLAP1_LA15         equ    10000000b


;*** LAP0 - Linear Address Pointer Register 0; 0x00000033 ***
LAP0               equ    $00000033                                ;*** LAP0 - Linear Address Pointer Register 0; 0x00000033 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAP0_LA0           equ    0                                         ; Linear address pointer, bit 0
LAP0_LA1           equ    1                                         ; Linear address pointer, bit 1
LAP0_LA2           equ    2                                         ; Linear address pointer, bit 2
LAP0_LA3           equ    3                                         ; Linear address pointer, bit 3
LAP0_LA4           equ    4                                         ; Linear address pointer, bit 4
LAP0_LA5           equ    5                                         ; Linear address pointer, bit 5
LAP0_LA6           equ    6                                         ; Linear address pointer, bit 6
LAP0_LA7           equ    7                                         ; Linear address pointer, bit 7
; bit position masks
mLAP0_LA0          equ    00000001b
mLAP0_LA1          equ    00000010b
mLAP0_LA2          equ    00000100b
mLAP0_LA3          equ    00001000b
mLAP0_LA4          equ    00010000b
mLAP0_LA5          equ    00100000b
mLAP0_LA6          equ    01000000b
mLAP0_LA7          equ    10000000b


;*** LWP - Linear Word Post Increment Register; 0x00000034 ***
LWP                equ    $00000034                                ;*** LWP - Linear Word Post Increment Register; 0x00000034 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LWP_D0             equ    0                                         ; Data value bit 0
LWP_D1             equ    1                                         ; Data value bit 1
LWP_D2             equ    2                                         ; Data value bit 2
LWP_D3             equ    3                                         ; Data value bit 3
LWP_D4             equ    4                                         ; Data value bit 4
LWP_D5             equ    5                                         ; Data value bit 5
LWP_D6             equ    6                                         ; Data value bit 6
LWP_D7             equ    7                                         ; Data value bit 7
; bit position masks
mLWP_D0            equ    00000001b
mLWP_D1            equ    00000010b
mLWP_D2            equ    00000100b
mLWP_D3            equ    00001000b
mLWP_D4            equ    00010000b
mLWP_D5            equ    00100000b
mLWP_D6            equ    01000000b
mLWP_D7            equ    10000000b


;*** LBP - Linear Byte Post Increment Register; 0x00000035 ***
LBP                equ    $00000035                                ;*** LBP - Linear Byte Post Increment Register; 0x00000035 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LBP_D0             equ    0                                         ; Data value bit 0
LBP_D1             equ    1                                         ; Data value bit 1
LBP_D2             equ    2                                         ; Data value bit 2
LBP_D3             equ    3                                         ; Data value bit 3
LBP_D4             equ    4                                         ; Data value bit 4
LBP_D5             equ    5                                         ; Data value bit 5
LBP_D6             equ    6                                         ; Data value bit 6
LBP_D7             equ    7                                         ; Data value bit 7
; bit position masks
mLBP_D0            equ    00000001b
mLBP_D1            equ    00000010b
mLBP_D2            equ    00000100b
mLBP_D3            equ    00001000b
mLBP_D4            equ    00010000b
mLBP_D5            equ    00100000b
mLBP_D6            equ    01000000b
mLBP_D7            equ    10000000b


;*** LB - Linear Byte Register; 0x00000036 ***
LB                 equ    $00000036                                ;*** LB - Linear Byte Register; 0x00000036 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LB_D0              equ    0                                         ; Data value bit 0
LB_D1              equ    1                                         ; Data value bit 1
LB_D2              equ    2                                         ; Data value bit 2
LB_D3              equ    3                                         ; Data value bit 3
LB_D4              equ    4                                         ; Data value bit 4
LB_D5              equ    5                                         ; Data value bit 5
LB_D6              equ    6                                         ; Data value bit 6
LB_D7              equ    7                                         ; Data value bit 7
; bit position masks
mLB_D0             equ    00000001b
mLB_D1             equ    00000010b
mLB_D2             equ    00000100b
mLB_D3             equ    00001000b
mLB_D4             equ    00010000b
mLB_D5             equ    00100000b
mLB_D6             equ    01000000b
mLB_D7             equ    10000000b


;*** LAPAB - Linear Address Pointer Add Byte Register; 0x00000037 ***
LAPAB              equ    $00000037                                ;*** LAPAB - Linear Address Pointer Add Byte Register; 0x00000037 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LAPAB_D0           equ    0                                         ; Data value bit 0
LAPAB_D1           equ    1                                         ; Data value bit 1
LAPAB_D2           equ    2                                         ; Data value bit 2
LAPAB_D3           equ    3                                         ; Data value bit 3
LAPAB_D4           equ    4                                         ; Data value bit 4
LAPAB_D5           equ    5                                         ; Data value bit 5
LAPAB_D6           equ    6                                         ; Data value bit 6
LAPAB_D7           equ    7                                         ; Data value bit 7
; bit position masks
mLAPAB_D0          equ    00000001b
mLAPAB_D1          equ    00000010b
mLAPAB_D2          equ    00000100b
mLAPAB_D3          equ    00001000b
mLAPAB_D4          equ    00010000b
mLAPAB_D5          equ    00100000b
mLAPAB_D6          equ    01000000b
mLAPAB_D7          equ    10000000b


;*** ICSC1 - ICS Control Register 1; 0x00000038 ***
ICSC1              equ    $00000038                                ;*** ICSC1 - ICS Control Register 1; 0x00000038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC1_IREFSTEN     equ    0                                         ; Internal Reference Stop Enable
ICSC1_IRCLKEN      equ    1                                         ; Internal Reference Clock Enable
ICSC1_IREFS        equ    2                                         ; Internal Reference Select
ICSC1_RDIV0        equ    3                                         ; Reference Divider, bit 0
ICSC1_RDIV1        equ    4                                         ; Reference Divider, bit 1
ICSC1_RDIV2        equ    5                                         ; Reference Divider, bit 2
ICSC1_CLKS0        equ    6                                         ; Clock Source Select, bit 0
ICSC1_CLKS1        equ    7                                         ; Clock Source Select, bit 1
; bit position masks
mICSC1_IREFSTEN    equ    00000001b
mICSC1_IRCLKEN     equ    00000010b
mICSC1_IREFS       equ    00000100b
mICSC1_RDIV0       equ    00001000b
mICSC1_RDIV1       equ    00010000b
mICSC1_RDIV2       equ    00100000b
mICSC1_CLKS0       equ    01000000b
mICSC1_CLKS1       equ    10000000b


;*** ICSC2 - ICS Control Register 2; 0x00000039 ***
ICSC2              equ    $00000039                                ;*** ICSC2 - ICS Control Register 2; 0x00000039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSC2_EREFSTEN     equ    0                                         ; External Reference Stop Enable
ICSC2_ERCLKEN      equ    1                                         ; External Reference Enable
ICSC2_EREFS        equ    2                                         ; External Reference Select
ICSC2_LP           equ    3                                         ; Low Power Select
ICSC2_HGO          equ    4                                         ; High Gain Oscillator Select
ICSC2_RANGE        equ    5                                         ; Frequency Range Select
ICSC2_BDIV0        equ    6                                         ; Bus Frequency Divider, bit 0
ICSC2_BDIV1        equ    7                                         ; Bus Frequency Divider, bit 1
; bit position masks
mICSC2_EREFSTEN    equ    00000001b
mICSC2_ERCLKEN     equ    00000010b
mICSC2_EREFS       equ    00000100b
mICSC2_LP          equ    00001000b
mICSC2_HGO         equ    00010000b
mICSC2_RANGE       equ    00100000b
mICSC2_BDIV0       equ    01000000b
mICSC2_BDIV1       equ    10000000b


;*** ICSTRM - ICS Trim Register; 0x0000003A ***
ICSTRM             equ    $0000003A                                ;*** ICSTRM - ICS Trim Register; 0x0000003A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSTRM_TRIM0       equ    0                                         ; ICS Trim Setting, bit 0
ICSTRM_TRIM1       equ    1                                         ; ICS Trim Setting, bit 1
ICSTRM_TRIM2       equ    2                                         ; ICS Trim Setting, bit 2
ICSTRM_TRIM3       equ    3                                         ; ICS Trim Setting, bit 3
ICSTRM_TRIM4       equ    4                                         ; ICS Trim Setting, bit 4
ICSTRM_TRIM5       equ    5                                         ; ICS Trim Setting, bit 5
ICSTRM_TRIM6       equ    6                                         ; ICS Trim Setting, bit 6
ICSTRM_TRIM7       equ    7                                         ; ICS Trim Setting, bit 7
; bit position masks
mICSTRM_TRIM0      equ    00000001b
mICSTRM_TRIM1      equ    00000010b
mICSTRM_TRIM2      equ    00000100b
mICSTRM_TRIM3      equ    00001000b
mICSTRM_TRIM4      equ    00010000b
mICSTRM_TRIM5      equ    00100000b
mICSTRM_TRIM6      equ    01000000b
mICSTRM_TRIM7      equ    10000000b


;*** ICSSC - ICS Status and Control Register; 0x0000003B ***
ICSSC              equ    $0000003B                                ;*** ICSSC - ICS Status and Control Register; 0x0000003B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ICSSC_FTRIM        equ    0                                         ; ICS Fine Trim
ICSSC_OSCINIT      equ    1                                         ; OSC Initialization
ICSSC_CLKST0       equ    2                                         ; Clock Mode Status, bit 0
ICSSC_CLKST1       equ    3                                         ; Clock Mode Status, bit 1
ICSSC_IREFST       equ    4                                         ; Internal Reference Status
ICSSC_DMX32        equ    5                                         ; DCO Maximum frequency with 32.768 kHz reference
ICSSC_DRST_DRS0    equ    6                                         ; DCO Range Status/Range Select, bit 0
ICSSC_DRST_DRS1    equ    7                                         ; DCO Range Status/Range Select, bit 1
; bit position masks
mICSSC_FTRIM       equ    00000001b
mICSSC_OSCINIT     equ    00000010b
mICSSC_CLKST0      equ    00000100b
mICSSC_CLKST1      equ    00001000b
mICSSC_IREFST      equ    00010000b
mICSSC_DMX32       equ    00100000b
mICSSC_DRST_DRS0   equ    01000000b
mICSSC_DRST_DRS1   equ    10000000b


;*** TPM1SC - TPM1 Status and Control Register; 0x00000040 ***
TPM1SC             equ    $00000040                                ;*** TPM1SC - TPM1 Status and Control Register; 0x00000040 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1SC_PS0         equ    0                                         ; Prescale Divisor Select Bit 0
TPM1SC_PS1         equ    1                                         ; Prescale Divisor Select Bit 1
TPM1SC_PS2         equ    2                                         ; Prescale Divisor Select Bit 2
TPM1SC_CLKSA       equ    3                                         ; Clock Source Select A
TPM1SC_CLKSB       equ    4                                         ; Clock Source Select B
TPM1SC_CPWMS       equ    5                                         ; Center-Aligned PWM Select
TPM1SC_TOIE        equ    6                                         ; Timer Overflow Interrupt Enable
TPM1SC_TOF         equ    7                                         ; Timer Overflow Flag
; bit position masks
mTPM1SC_PS0        equ    00000001b
mTPM1SC_PS1        equ    00000010b
mTPM1SC_PS2        equ    00000100b
mTPM1SC_CLKSA      equ    00001000b
mTPM1SC_CLKSB      equ    00010000b
mTPM1SC_CPWMS      equ    00100000b
mTPM1SC_TOIE       equ    01000000b
mTPM1SC_TOF        equ    10000000b


;*** TPM1CNT - TPM1 Timer Counter Register; 0x00000041 ***
TPM1CNT            equ    $00000041                                ;*** TPM1CNT - TPM1 Timer Counter Register; 0x00000041 ***


;*** TPM1CNTH - TPM1 Timer Counter Register High; 0x00000041 ***
TPM1CNTH           equ    $00000041                                ;*** TPM1CNTH - TPM1 Timer Counter Register High; 0x00000041 ***


;*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x00000042 ***
TPM1CNTL           equ    $00000042                                ;*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x00000042 ***


;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000043 ***
TPM1MOD            equ    $00000043                                ;*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000043 ***


;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000043 ***
TPM1MODH           equ    $00000043                                ;*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000043 ***


;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000044 ***
TPM1MODL           equ    $00000044                                ;*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000044 ***


;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000045 ***
TPM1C0SC           equ    $00000045                                ;*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000045 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C0SC_ELS0A     equ    2                                         ; Edge/Level Select Bit A
TPM1C0SC_ELS0B     equ    3                                         ; Edge/Level Select Bit B
TPM1C0SC_MS0A      equ    4                                         ; Mode Select A for TPM Channel 0
TPM1C0SC_MS0B      equ    5                                         ; Mode Select B for TPM Channel 0
TPM1C0SC_CH0IE     equ    6                                         ; Channel 0 Interrupt Enable
TPM1C0SC_CH0F      equ    7                                         ; Channel 0 Flag
; bit position masks
mTPM1C0SC_ELS0A    equ    00000100b
mTPM1C0SC_ELS0B    equ    00001000b
mTPM1C0SC_MS0A     equ    00010000b
mTPM1C0SC_MS0B     equ    00100000b
mTPM1C0SC_CH0IE    equ    01000000b
mTPM1C0SC_CH0F     equ    10000000b


;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000046 ***
TPM1C0V            equ    $00000046                                ;*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000046 ***


;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000046 ***
TPM1C0VH           equ    $00000046                                ;*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000046 ***


;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000047 ***
TPM1C0VL           equ    $00000047                                ;*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000047 ***


;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000048 ***
TPM1C1SC           equ    $00000048                                ;*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000048 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM1C1SC_ELS1A     equ    2                                         ; Edge/Level Select Bit A
TPM1C1SC_ELS1B     equ    3                                         ; Edge/Level Select Bit B
TPM1C1SC_MS1A      equ    4                                         ; Mode Select A for TPM Channel 1
TPM1C1SC_MS1B      equ    5                                         ; Mode Select B for TPM Channel 1
TPM1C1SC_CH1IE     equ    6                                         ; Channel 1 Interrupt Enable
TPM1C1SC_CH1F      equ    7                                         ; Channel 1 Flag
; bit position masks
mTPM1C1SC_ELS1A    equ    00000100b
mTPM1C1SC_ELS1B    equ    00001000b
mTPM1C1SC_MS1A     equ    00010000b
mTPM1C1SC_MS1B     equ    00100000b
mTPM1C1SC_CH1IE    equ    01000000b
mTPM1C1SC_CH1F     equ    10000000b


;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000049 ***
TPM1C1V            equ    $00000049                                ;*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000049 ***


;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000049 ***
TPM1C1VH           equ    $00000049                                ;*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000049 ***


;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000004A ***
TPM1C1VL           equ    $0000004A                                ;*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000004A ***


;*** TPM2SC - TPM2 Status and Control Register; 0x00000050 ***
TPM2SC             equ    $00000050                                ;*** TPM2SC - TPM2 Status and Control Register; 0x00000050 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2SC_PS0         equ    0                                         ; Prescale Divisor Select Bit 0
TPM2SC_PS1         equ    1                                         ; Prescale Divisor Select Bit 1
TPM2SC_PS2         equ    2                                         ; Prescale Divisor Select Bit 2
TPM2SC_CLKSA       equ    3                                         ; Clock Source Select A
TPM2SC_CLKSB       equ    4                                         ; Clock Source Select B
TPM2SC_CPWMS       equ    5                                         ; Center-Aligned PWM Select
TPM2SC_TOIE        equ    6                                         ; Timer Overflow Interrupt Enable
TPM2SC_TOF         equ    7                                         ; Timer Overflow Flag
; bit position masks
mTPM2SC_PS0        equ    00000001b
mTPM2SC_PS1        equ    00000010b
mTPM2SC_PS2        equ    00000100b
mTPM2SC_CLKSA      equ    00001000b
mTPM2SC_CLKSB      equ    00010000b
mTPM2SC_CPWMS      equ    00100000b
mTPM2SC_TOIE       equ    01000000b
mTPM2SC_TOF        equ    10000000b


;*** TPM2CNT - TPM2 Timer Counter Register; 0x00000051 ***
TPM2CNT            equ    $00000051                                ;*** TPM2CNT - TPM2 Timer Counter Register; 0x00000051 ***


;*** TPM2CNTH - TPM2 Timer Counter Register High; 0x00000051 ***
TPM2CNTH           equ    $00000051                                ;*** TPM2CNTH - TPM2 Timer Counter Register High; 0x00000051 ***


;*** TPM2CNTL - TPM2 Timer Counter Register Low; 0x00000052 ***
TPM2CNTL           equ    $00000052                                ;*** TPM2CNTL - TPM2 Timer Counter Register Low; 0x00000052 ***


;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000053 ***
TPM2MOD            equ    $00000053                                ;*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000053 ***


;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000053 ***
TPM2MODH           equ    $00000053                                ;*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000053 ***


;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000054 ***
TPM2MODL           equ    $00000054                                ;*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000054 ***


;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000055 ***
TPM2C0SC           equ    $00000055                                ;*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000055 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C0SC_ELS0A     equ    2                                         ; Edge/Level Select Bit A
TPM2C0SC_ELS0B     equ    3                                         ; Edge/Level Select Bit B
TPM2C0SC_MS0A      equ    4                                         ; Mode Select A for TPM Channel 0
TPM2C0SC_MS0B      equ    5                                         ; Mode Select B for TPM Channel 0
TPM2C0SC_CH0IE     equ    6                                         ; Channel 0 Interrupt Enable
TPM2C0SC_CH0F      equ    7                                         ; Channel 0 Flag
; bit position masks
mTPM2C0SC_ELS0A    equ    00000100b
mTPM2C0SC_ELS0B    equ    00001000b
mTPM2C0SC_MS0A     equ    00010000b
mTPM2C0SC_MS0B     equ    00100000b
mTPM2C0SC_CH0IE    equ    01000000b
mTPM2C0SC_CH0F     equ    10000000b


;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000056 ***
TPM2C0V            equ    $00000056                                ;*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000056 ***


;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000056 ***
TPM2C0VH           equ    $00000056                                ;*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000056 ***


;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000057 ***
TPM2C0VL           equ    $00000057                                ;*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000057 ***


;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0x00000058 ***
TPM2C1SC           equ    $00000058                                ;*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0x00000058 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TPM2C1SC_ELS1A     equ    2                                         ; Edge/Level Select Bit A
TPM2C1SC_ELS1B     equ    3                                         ; Edge/Level Select Bit B
TPM2C1SC_MS1A      equ    4                                         ; Mode Select A for TPM Channel 1
TPM2C1SC_MS1B      equ    5                                         ; Mode Select B for TPM Channel 1
TPM2C1SC_CH1IE     equ    6                                         ; Channel 1 Interrupt Enable
TPM2C1SC_CH1F      equ    7                                         ; Channel 1 Flag
; bit position masks
mTPM2C1SC_ELS1A    equ    00000100b
mTPM2C1SC_ELS1B    equ    00001000b
mTPM2C1SC_MS1A     equ    00010000b
mTPM2C1SC_MS1B     equ    00100000b
mTPM2C1SC_CH1IE    equ    01000000b
mTPM2C1SC_CH1F     equ    10000000b


;*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0x00000059 ***
TPM2C1V            equ    $00000059                                ;*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0x00000059 ***


;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0x00000059 ***
TPM2C1VH           equ    $00000059                                ;*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0x00000059 ***


;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0x0000005A ***
TPM2C1VL           equ    $0000005A                                ;*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0x0000005A ***


;*** VREF1TRM - VREF Trim Register; 0x0000005C ***
VREF1TRM           equ    $0000005C                                ;*** VREF1TRM - VREF Trim Register; 0x0000005C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREF1TRM_TRM0      equ    0                                         ; Trim Bits, bit 0
VREF1TRM_TRM1      equ    1                                         ; Trim Bits, bit 1
VREF1TRM_TRM2      equ    2                                         ; Trim Bits, bit 2
VREF1TRM_TRM3      equ    3                                         ; Trim Bits, bit 3
VREF1TRM_TRM4      equ    4                                         ; Trim Bits, bit 4
VREF1TRM_TRM5      equ    5                                         ; Trim Bits, bit 5
VREF1TRM_TRM6      equ    6                                         ; Trim Bits, bit 6
VREF1TRM_TRM7      equ    7                                         ; Trim Bits, bit 7
; bit position masks
mVREF1TRM_TRM0     equ    00000001b
mVREF1TRM_TRM1     equ    00000010b
mVREF1TRM_TRM2     equ    00000100b
mVREF1TRM_TRM3     equ    00001000b
mVREF1TRM_TRM4     equ    00010000b
mVREF1TRM_TRM5     equ    00100000b
mVREF1TRM_TRM6     equ    01000000b
mVREF1TRM_TRM7     equ    10000000b


;*** VREF1SC - VREF Control Register; 0x0000005D ***
VREF1SC            equ    $0000005D                                ;*** VREF1SC - VREF Control Register; 0x0000005D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREF1SC_MODE0      equ    0                                         ; Mode selection, bit 0
VREF1SC_MODE1      equ    1                                         ; Mode selection, bit 1
VREF1SC_VREFST     equ    2                                         ; Internal Voltage Reference Stable
VREF1SC_VREFEN     equ    7                                         ; Internal Voltage Reference Enable
; bit position masks
mVREF1SC_MODE0     equ    00000001b
mVREF1SC_MODE1     equ    00000010b
mVREF1SC_VREFST    equ    00000100b
mVREF1SC_VREFEN    equ    10000000b


;*** VREF2TRM - VREF Trim Register; 0x0000005E ***
VREF2TRM           equ    $0000005E                                ;*** VREF2TRM - VREF Trim Register; 0x0000005E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREF2TRM_TRM0      equ    0                                         ; Trim Bits, bit 0
VREF2TRM_TRM1      equ    1                                         ; Trim Bits, bit 1
VREF2TRM_TRM2      equ    2                                         ; Trim Bits, bit 2
VREF2TRM_TRM3      equ    3                                         ; Trim Bits, bit 3
VREF2TRM_TRM4      equ    4                                         ; Trim Bits, bit 4
VREF2TRM_TRM5      equ    5                                         ; Trim Bits, bit 5
VREF2TRM_TRM6      equ    6                                         ; Trim Bits, bit 6
VREF2TRM_TRM7      equ    7                                         ; Trim Bits, bit 7
; bit position masks
mVREF2TRM_TRM0     equ    00000001b
mVREF2TRM_TRM1     equ    00000010b
mVREF2TRM_TRM2     equ    00000100b
mVREF2TRM_TRM3     equ    00001000b
mVREF2TRM_TRM4     equ    00010000b
mVREF2TRM_TRM5     equ    00100000b
mVREF2TRM_TRM6     equ    01000000b
mVREF2TRM_TRM7     equ    10000000b


;*** VREF2SC - VREF Control Register; 0x0000005F ***
VREF2SC            equ    $0000005F                                ;*** VREF2SC - VREF Control Register; 0x0000005F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
VREF2SC_MODE0      equ    0                                         ; Mode selection, bit 0
VREF2SC_MODE1      equ    1                                         ; Mode selection, bit 1
VREF2SC_VREFST     equ    2                                         ; Internal Voltage Reference Stable
VREF2SC_VREFEN     equ    7                                         ; Internal Voltage Reference Enable
; bit position masks
mVREF2SC_MODE0     equ    00000001b
mVREF2SC_MODE1     equ    00000010b
mVREF2SC_VREFST    equ    00000100b
mVREF2SC_VREFEN    equ    10000000b


;*** LCDPEN0 - LCD Pin Enable Register 0; 0x00001000 ***
LCDPEN0            equ    $00001000                                ;*** LCDPEN0 - LCD Pin Enable Register 0; 0x00001000 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN0_PEN0       equ    0                                         ; Enable LCD pin 0 for LCD operation
LCDPEN0_PEN1       equ    1                                         ; Enable LCD pin 1 for LCD operation
LCDPEN0_PEN2       equ    2                                         ; Enable LCD pin 2 for LCD operation
LCDPEN0_PEN3       equ    3                                         ; Enable LCD pin 3 for LCD operation
LCDPEN0_PEN4       equ    4                                         ; Enable LCD pin 4 for LCD operation
LCDPEN0_PEN5       equ    5                                         ; Enable LCD pin 5 for LCD operation
LCDPEN0_PEN6       equ    6                                         ; Enable LCD pin 6 for LCD operation
LCDPEN0_PEN7       equ    7                                         ; Enable LCD pin 7 for LCD operation
; bit position masks
mLCDPEN0_PEN0      equ    00000001b
mLCDPEN0_PEN1      equ    00000010b
mLCDPEN0_PEN2      equ    00000100b
mLCDPEN0_PEN3      equ    00001000b
mLCDPEN0_PEN4      equ    00010000b
mLCDPEN0_PEN5      equ    00100000b
mLCDPEN0_PEN6      equ    01000000b
mLCDPEN0_PEN7      equ    10000000b


;*** LCDPEN1 - LCD Pin Enable Register 1; 0x00001001 ***
LCDPEN1            equ    $00001001                                ;*** LCDPEN1 - LCD Pin Enable Register 1; 0x00001001 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN1_PEN8       equ    0                                         ; Enable LCD pin 8 for LCD operation
LCDPEN1_PEN9       equ    1                                         ; Enable LCD pin 9 for LCD operation
LCDPEN1_PEN10      equ    2                                         ; Enable LCD pin 10 for LCD operation
LCDPEN1_PEN11      equ    3                                         ; Enable LCD pin 11 for LCD operation
LCDPEN1_PEN12      equ    4                                         ; Enable LCD pin 12 for LCD operation
LCDPEN1_PEN13      equ    5                                         ; Enable LCD pin 13 for LCD operation
LCDPEN1_PEN14      equ    6                                         ; Enable LCD pin 14 for LCD operation
LCDPEN1_PEN15      equ    7                                         ; Enable LCD pin 15 for LCD operation
; bit position masks
mLCDPEN1_PEN8      equ    00000001b
mLCDPEN1_PEN9      equ    00000010b
mLCDPEN1_PEN10     equ    00000100b
mLCDPEN1_PEN11     equ    00001000b
mLCDPEN1_PEN12     equ    00010000b
mLCDPEN1_PEN13     equ    00100000b
mLCDPEN1_PEN14     equ    01000000b
mLCDPEN1_PEN15     equ    10000000b


;*** LCDPEN2 - LCD Pin Enable Register 2; 0x00001002 ***
LCDPEN2            equ    $00001002                                ;*** LCDPEN2 - LCD Pin Enable Register 2; 0x00001002 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN2_PEN16      equ    0                                         ; Enable LCD pin 16 for LCD operation
LCDPEN2_PEN17      equ    1                                         ; Enable LCD pin 17 for LCD operation
LCDPEN2_PEN18      equ    2                                         ; Enable LCD pin 18 for LCD operation
LCDPEN2_PEN19      equ    3                                         ; Enable LCD pin 19 for LCD operation
LCDPEN2_PEN20      equ    4                                         ; Enable LCD pin 20 for LCD operation
LCDPEN2_PEN21      equ    5                                         ; Enable LCD pin 21 for LCD operation
LCDPEN2_PEN22      equ    6                                         ; Enable LCD pin 22 for LCD operation
LCDPEN2_PEN23      equ    7                                         ; Enable LCD pin 23 for LCD operation
; bit position masks
mLCDPEN2_PEN16     equ    00000001b
mLCDPEN2_PEN17     equ    00000010b
mLCDPEN2_PEN18     equ    00000100b
mLCDPEN2_PEN19     equ    00001000b
mLCDPEN2_PEN20     equ    00010000b
mLCDPEN2_PEN21     equ    00100000b
mLCDPEN2_PEN22     equ    01000000b
mLCDPEN2_PEN23     equ    10000000b


;*** LCDPEN3 - LCD Pin Enable Register 3; 0x00001003 ***
LCDPEN3            equ    $00001003                                ;*** LCDPEN3 - LCD Pin Enable Register 3; 0x00001003 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN3_PEN24      equ    0                                         ; Enable LCD pin 24 for LCD operation
LCDPEN3_PEN25      equ    1                                         ; Enable LCD pin 25 for LCD operation
LCDPEN3_PEN26      equ    2                                         ; Enable LCD pin 26 for LCD operation
LCDPEN3_PEN27      equ    3                                         ; Enable LCD pin 27 for LCD operation
LCDPEN3_PEN28      equ    4                                         ; Enable LCD pin 28 for LCD operation
LCDPEN3_PEN29      equ    5                                         ; Enable LCD pin 29 for LCD operation
LCDPEN3_PEN30      equ    6                                         ; Enable LCD pin 30 for LCD operation
LCDPEN3_PEN31      equ    7                                         ; Enable LCD pin 31 for LCD operation
; bit position masks
mLCDPEN3_PEN24     equ    00000001b
mLCDPEN3_PEN25     equ    00000010b
mLCDPEN3_PEN26     equ    00000100b
mLCDPEN3_PEN27     equ    00001000b
mLCDPEN3_PEN28     equ    00010000b
mLCDPEN3_PEN29     equ    00100000b
mLCDPEN3_PEN30     equ    01000000b
mLCDPEN3_PEN31     equ    10000000b


;*** LCDPEN4 - LCD Pin Enable Register 4; 0x00001004 ***
LCDPEN4            equ    $00001004                                ;*** LCDPEN4 - LCD Pin Enable Register 4; 0x00001004 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN4_PEN32      equ    0                                         ; Enable LCD pin 32 for LCD operation
LCDPEN4_PEN33      equ    1                                         ; Enable LCD pin 33 for LCD operation
LCDPEN4_PEN34      equ    2                                         ; Enable LCD pin 34 for LCD operation
LCDPEN4_PEN35      equ    3                                         ; Enable LCD pin 35 for LCD operation
LCDPEN4_PEN36      equ    4                                         ; Enable LCD pin 36 for LCD operation
LCDPEN4_PEN37      equ    5                                         ; Enable LCD pin 37 for LCD operation
LCDPEN4_PEN38      equ    6                                         ; Enable LCD pin 38 for LCD operation
LCDPEN4_PEN39      equ    7                                         ; Enable LCD pin 39 for LCD operation
; bit position masks
mLCDPEN4_PEN32     equ    00000001b
mLCDPEN4_PEN33     equ    00000010b
mLCDPEN4_PEN34     equ    00000100b
mLCDPEN4_PEN35     equ    00001000b
mLCDPEN4_PEN36     equ    00010000b
mLCDPEN4_PEN37     equ    00100000b
mLCDPEN4_PEN38     equ    01000000b
mLCDPEN4_PEN39     equ    10000000b


;*** LCDPEN5 - LCD Pin Enable Register 5; 0x00001005 ***
LCDPEN5            equ    $00001005                                ;*** LCDPEN5 - LCD Pin Enable Register 5; 0x00001005 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDPEN5_PEN40      equ    0                                         ; Enable LCD pin 40 for LCD operation
LCDPEN5_PEN41      equ    1                                         ; Enable LCD pin 41 for LCD operation
LCDPEN5_PEN42      equ    2                                         ; Enable LCD pin 42 for LCD operation
LCDPEN5_PEN43      equ    3                                         ; Enable LCD pin 43 for LCD operation
; bit position masks
mLCDPEN5_PEN40     equ    00000001b
mLCDPEN5_PEN41     equ    00000010b
mLCDPEN5_PEN42     equ    00000100b
mLCDPEN5_PEN43     equ    00001000b


;*** LCDBPEN0 - LCD Backplane Enable Register 0; 0x00001008 ***
LCDBPEN0           equ    $00001008                                ;*** LCDBPEN0 - LCD Backplane Enable Register 0; 0x00001008 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN0_BPEN0     equ    0                                         ; Enable LCD pin 0 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN1     equ    1                                         ; Enable LCD pin 1 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN2     equ    2                                         ; Enable LCD pin 2 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN3     equ    3                                         ; Enable LCD pin 3 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN4     equ    4                                         ; Enable LCD pin 4 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN5     equ    5                                         ; Enable LCD pin 5 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN6     equ    6                                         ; Enable LCD pin 6 to operate as an LCD backplane or an LCD frontplane
LCDBPEN0_BPEN7     equ    7                                         ; Enable LCD pin 7 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN0_BPEN0    equ    00000001b
mLCDBPEN0_BPEN1    equ    00000010b
mLCDBPEN0_BPEN2    equ    00000100b
mLCDBPEN0_BPEN3    equ    00001000b
mLCDBPEN0_BPEN4    equ    00010000b
mLCDBPEN0_BPEN5    equ    00100000b
mLCDBPEN0_BPEN6    equ    01000000b
mLCDBPEN0_BPEN7    equ    10000000b


;*** LCDBPEN1 - LCD Backplane Enable Register 1; 0x00001009 ***
LCDBPEN1           equ    $00001009                                ;*** LCDBPEN1 - LCD Backplane Enable Register 1; 0x00001009 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN1_BPEN8     equ    0                                         ; Enable LCD pin 8 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN9     equ    1                                         ; Enable LCD pin 9 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN10    equ    2                                         ; Enable LCD pin 10 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN11    equ    3                                         ; Enable LCD pin 11 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN12    equ    4                                         ; Enable LCD pin 12 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN13    equ    5                                         ; Enable LCD pin 13 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN14    equ    6                                         ; Enable LCD pin 14 to operate as an LCD backplane or an LCD frontplane
LCDBPEN1_BPEN15    equ    7                                         ; Enable LCD pin 15 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN1_BPEN8    equ    00000001b
mLCDBPEN1_BPEN9    equ    00000010b
mLCDBPEN1_BPEN10   equ    00000100b
mLCDBPEN1_BPEN11   equ    00001000b
mLCDBPEN1_BPEN12   equ    00010000b
mLCDBPEN1_BPEN13   equ    00100000b
mLCDBPEN1_BPEN14   equ    01000000b
mLCDBPEN1_BPEN15   equ    10000000b


;*** LCDBPEN2 - LCD Backplane Enable Register 2; 0x0000100A ***
LCDBPEN2           equ    $0000100A                                ;*** LCDBPEN2 - LCD Backplane Enable Register 2; 0x0000100A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN2_BPEN16    equ    0                                         ; Enable LCD pin 16 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN17    equ    1                                         ; Enable LCD pin 17 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN18    equ    2                                         ; Enable LCD pin 18 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN19    equ    3                                         ; Enable LCD pin 19 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN20    equ    4                                         ; Enable LCD pin 20 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN21    equ    5                                         ; Enable LCD pin 21 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN22    equ    6                                         ; Enable LCD pin 22 to operate as an LCD backplane or an LCD frontplane
LCDBPEN2_BPEN23    equ    7                                         ; Enable LCD pin 23 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN2_BPEN16   equ    00000001b
mLCDBPEN2_BPEN17   equ    00000010b
mLCDBPEN2_BPEN18   equ    00000100b
mLCDBPEN2_BPEN19   equ    00001000b
mLCDBPEN2_BPEN20   equ    00010000b
mLCDBPEN2_BPEN21   equ    00100000b
mLCDBPEN2_BPEN22   equ    01000000b
mLCDBPEN2_BPEN23   equ    10000000b


;*** LCDBPEN3 - LCD Backplane Enable Register 3; 0x0000100B ***
LCDBPEN3           equ    $0000100B                                ;*** LCDBPEN3 - LCD Backplane Enable Register 3; 0x0000100B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN3_BPEN24    equ    0                                         ; Enable LCD pin 24 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN25    equ    1                                         ; Enable LCD pin 25 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN26    equ    2                                         ; Enable LCD pin 26 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN27    equ    3                                         ; Enable LCD pin 27 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN28    equ    4                                         ; Enable LCD pin 28 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN29    equ    5                                         ; Enable LCD pin 29 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN30    equ    6                                         ; Enable LCD pin 30 to operate as an LCD backplane or an LCD frontplane
LCDBPEN3_BPEN31    equ    7                                         ; Enable LCD pin 31 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN3_BPEN24   equ    00000001b
mLCDBPEN3_BPEN25   equ    00000010b
mLCDBPEN3_BPEN26   equ    00000100b
mLCDBPEN3_BPEN27   equ    00001000b
mLCDBPEN3_BPEN28   equ    00010000b
mLCDBPEN3_BPEN29   equ    00100000b
mLCDBPEN3_BPEN30   equ    01000000b
mLCDBPEN3_BPEN31   equ    10000000b


;*** LCDBPEN4 - LCD Backplane Enable Register 4; 0x0000100C ***
LCDBPEN4           equ    $0000100C                                ;*** LCDBPEN4 - LCD Backplane Enable Register 4; 0x0000100C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN4_BPEN32    equ    0                                         ; Enable LCD pin 32 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN33    equ    1                                         ; Enable LCD pin 33 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN34    equ    2                                         ; Enable LCD pin 34 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN35    equ    3                                         ; Enable LCD pin 35 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN36    equ    4                                         ; Enable LCD pin 36 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN37    equ    5                                         ; Enable LCD pin 37 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN38    equ    6                                         ; Enable LCD pin 38 to operate as an LCD backplane or an LCD frontplane
LCDBPEN4_BPEN39    equ    7                                         ; Enable LCD pin 39 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN4_BPEN32   equ    00000001b
mLCDBPEN4_BPEN33   equ    00000010b
mLCDBPEN4_BPEN34   equ    00000100b
mLCDBPEN4_BPEN35   equ    00001000b
mLCDBPEN4_BPEN36   equ    00010000b
mLCDBPEN4_BPEN37   equ    00100000b
mLCDBPEN4_BPEN38   equ    01000000b
mLCDBPEN4_BPEN39   equ    10000000b


;*** LCDBPEN5 - LCD Backplane Enable Register 5; 0x0000100D ***
LCDBPEN5           equ    $0000100D                                ;*** LCDBPEN5 - LCD Backplane Enable Register 5; 0x0000100D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDBPEN5_BPEN40    equ    0                                         ; Enable LCD pin 40 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN41    equ    1                                         ; Enable LCD pin 41 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN42    equ    2                                         ; Enable LCD pin 42 to operate as an LCD backplane or an LCD frontplane
LCDBPEN5_BPEN43    equ    3                                         ; Enable LCD pin 43 to operate as an LCD backplane or an LCD frontplane
; bit position masks
mLCDBPEN5_BPEN40   equ    00000001b
mLCDBPEN5_BPEN41   equ    00000010b
mLCDBPEN5_BPEN42   equ    00000100b
mLCDBPEN5_BPEN43   equ    00001000b


;*** LCDWF0 - LCD Waveform Register 0; 0x00001010 ***
LCDWF0             equ    $00001010                                ;*** LCDWF0 - LCD Waveform Register 0; 0x00001010 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF0_BPALCD0     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPBLCD0     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPCLCD0     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPDLCD0     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPELCD0     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPFLCD0     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPGLCD0     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF0_BPHLCD0     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF0_BPALCD0    equ    00000001b
mLCDWF0_BPBLCD0    equ    00000010b
mLCDWF0_BPCLCD0    equ    00000100b
mLCDWF0_BPDLCD0    equ    00001000b
mLCDWF0_BPELCD0    equ    00010000b
mLCDWF0_BPFLCD0    equ    00100000b
mLCDWF0_BPGLCD0    equ    01000000b
mLCDWF0_BPHLCD0    equ    10000000b


;*** LCDWF1 - LCD Waveform Register 1; 0x00001011 ***
LCDWF1             equ    $00001011                                ;*** LCDWF1 - LCD Waveform Register 1; 0x00001011 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF1_BPALCD1     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPBLCD1     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPCLCD1     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPDLCD1     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPELCD1     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPFLCD1     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPGLCD1     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF1_BPHLCD1     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF1_BPALCD1    equ    00000001b
mLCDWF1_BPBLCD1    equ    00000010b
mLCDWF1_BPCLCD1    equ    00000100b
mLCDWF1_BPDLCD1    equ    00001000b
mLCDWF1_BPELCD1    equ    00010000b
mLCDWF1_BPFLCD1    equ    00100000b
mLCDWF1_BPGLCD1    equ    01000000b
mLCDWF1_BPHLCD1    equ    10000000b


;*** LCDWF2 - LCD Waveform Register 2; 0x00001012 ***
LCDWF2             equ    $00001012                                ;*** LCDWF2 - LCD Waveform Register 2; 0x00001012 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF2_BPALCD2     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPBLCD2     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPCLCD2     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPDLCD2     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPELCD2     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPFLCD2     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPGLCD2     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF2_BPHLCD2     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF2_BPALCD2    equ    00000001b
mLCDWF2_BPBLCD2    equ    00000010b
mLCDWF2_BPCLCD2    equ    00000100b
mLCDWF2_BPDLCD2    equ    00001000b
mLCDWF2_BPELCD2    equ    00010000b
mLCDWF2_BPFLCD2    equ    00100000b
mLCDWF2_BPGLCD2    equ    01000000b
mLCDWF2_BPHLCD2    equ    10000000b


;*** LCDWF3 - LCD Waveform Register 3; 0x00001013 ***
LCDWF3             equ    $00001013                                ;*** LCDWF3 - LCD Waveform Register 3; 0x00001013 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF3_BPALCD3     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPBLCD3     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPCLCD3     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPDLCD3     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPELCD3     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPFLCD3     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPGLCD3     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF3_BPHLCD3     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF3_BPALCD3    equ    00000001b
mLCDWF3_BPBLCD3    equ    00000010b
mLCDWF3_BPCLCD3    equ    00000100b
mLCDWF3_BPDLCD3    equ    00001000b
mLCDWF3_BPELCD3    equ    00010000b
mLCDWF3_BPFLCD3    equ    00100000b
mLCDWF3_BPGLCD3    equ    01000000b
mLCDWF3_BPHLCD3    equ    10000000b


;*** LCDWF4 - LCD Waveform Register 4; 0x00001014 ***
LCDWF4             equ    $00001014                                ;*** LCDWF4 - LCD Waveform Register 4; 0x00001014 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF4_BPALCD4     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPBLCD4     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPCLCD4     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPDLCD4     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPELCD4     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPFLCD4     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPGLCD4     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF4_BPHLCD4     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF4_BPALCD4    equ    00000001b
mLCDWF4_BPBLCD4    equ    00000010b
mLCDWF4_BPCLCD4    equ    00000100b
mLCDWF4_BPDLCD4    equ    00001000b
mLCDWF4_BPELCD4    equ    00010000b
mLCDWF4_BPFLCD4    equ    00100000b
mLCDWF4_BPGLCD4    equ    01000000b
mLCDWF4_BPHLCD4    equ    10000000b


;*** LCDWF5 - LCD Waveform Register 5; 0x00001015 ***
LCDWF5             equ    $00001015                                ;*** LCDWF5 - LCD Waveform Register 5; 0x00001015 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF5_BPALCD5     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPBLCD5     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPCLCD5     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPDLCD5     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPELCD5     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPFLCD5     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPGLCD5     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF5_BPHLCD5     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF5_BPALCD5    equ    00000001b
mLCDWF5_BPBLCD5    equ    00000010b
mLCDWF5_BPCLCD5    equ    00000100b
mLCDWF5_BPDLCD5    equ    00001000b
mLCDWF5_BPELCD5    equ    00010000b
mLCDWF5_BPFLCD5    equ    00100000b
mLCDWF5_BPGLCD5    equ    01000000b
mLCDWF5_BPHLCD5    equ    10000000b


;*** LCDWF6 - LCD Waveform Register 6; 0x00001016 ***
LCDWF6             equ    $00001016                                ;*** LCDWF6 - LCD Waveform Register 6; 0x00001016 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF6_BPALCD6     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPBLCD6     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPCLCD6     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPDLCD6     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPELCD6     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPFLCD6     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPGLCD6     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF6_BPHLCD6     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF6_BPALCD6    equ    00000001b
mLCDWF6_BPBLCD6    equ    00000010b
mLCDWF6_BPCLCD6    equ    00000100b
mLCDWF6_BPDLCD6    equ    00001000b
mLCDWF6_BPELCD6    equ    00010000b
mLCDWF6_BPFLCD6    equ    00100000b
mLCDWF6_BPGLCD6    equ    01000000b
mLCDWF6_BPHLCD6    equ    10000000b


;*** LCDWF7 - LCD Waveform Register 7; 0x00001017 ***
LCDWF7             equ    $00001017                                ;*** LCDWF7 - LCD Waveform Register 7; 0x00001017 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF7_BPALCD7     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPBLCD7     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPCLCD7     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPDLCD7     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPELCD7     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPFLCD7     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPGLCD7     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF7_BPHLCD7     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF7_BPALCD7    equ    00000001b
mLCDWF7_BPBLCD7    equ    00000010b
mLCDWF7_BPCLCD7    equ    00000100b
mLCDWF7_BPDLCD7    equ    00001000b
mLCDWF7_BPELCD7    equ    00010000b
mLCDWF7_BPFLCD7    equ    00100000b
mLCDWF7_BPGLCD7    equ    01000000b
mLCDWF7_BPHLCD7    equ    10000000b


;*** LCDWF8 - LCD Waveform Register 8; 0x00001018 ***
LCDWF8             equ    $00001018                                ;*** LCDWF8 - LCD Waveform Register 8; 0x00001018 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF8_BPALCD8     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPBLCD8     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPCLCD8     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPDLCD8     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPELCD8     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPFLCD8     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPGLCD8     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF8_BPHLCD8     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF8_BPALCD8    equ    00000001b
mLCDWF8_BPBLCD8    equ    00000010b
mLCDWF8_BPCLCD8    equ    00000100b
mLCDWF8_BPDLCD8    equ    00001000b
mLCDWF8_BPELCD8    equ    00010000b
mLCDWF8_BPFLCD8    equ    00100000b
mLCDWF8_BPGLCD8    equ    01000000b
mLCDWF8_BPHLCD8    equ    10000000b


;*** LCDWF9 - LCD Waveform Register 9; 0x00001019 ***
LCDWF9             equ    $00001019                                ;*** LCDWF9 - LCD Waveform Register 9; 0x00001019 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF9_BPALCD9     equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPBLCD9     equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPCLCD9     equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPDLCD9     equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPELCD9     equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPFLCD9     equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPGLCD9     equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF9_BPHLCD9     equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF9_BPALCD9    equ    00000001b
mLCDWF9_BPBLCD9    equ    00000010b
mLCDWF9_BPCLCD9    equ    00000100b
mLCDWF9_BPDLCD9    equ    00001000b
mLCDWF9_BPELCD9    equ    00010000b
mLCDWF9_BPFLCD9    equ    00100000b
mLCDWF9_BPGLCD9    equ    01000000b
mLCDWF9_BPHLCD9    equ    10000000b


;*** LCDWF10 - LCD Waveform Register 10; 0x0000101A ***
LCDWF10            equ    $0000101A                                ;*** LCDWF10 - LCD Waveform Register 10; 0x0000101A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF10_BPALCD10   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPBLCD10   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPCLCD10   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPDLCD10   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPELCD10   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPFLCD10   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPGLCD10   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF10_BPHLCD10   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF10_BPALCD10  equ    00000001b
mLCDWF10_BPBLCD10  equ    00000010b
mLCDWF10_BPCLCD10  equ    00000100b
mLCDWF10_BPDLCD10  equ    00001000b
mLCDWF10_BPELCD10  equ    00010000b
mLCDWF10_BPFLCD10  equ    00100000b
mLCDWF10_BPGLCD10  equ    01000000b
mLCDWF10_BPHLCD10  equ    10000000b


;*** LCDWF11 - LCD Waveform Register 11; 0x0000101B ***
LCDWF11            equ    $0000101B                                ;*** LCDWF11 - LCD Waveform Register 11; 0x0000101B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF11_BPALCD11   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPBLCD11   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPCLCD11   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPDLCD11   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPELCD11   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPFLCD11   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPGLCD11   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF11_BPHLCD11   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF11_BPALCD11  equ    00000001b
mLCDWF11_BPBLCD11  equ    00000010b
mLCDWF11_BPCLCD11  equ    00000100b
mLCDWF11_BPDLCD11  equ    00001000b
mLCDWF11_BPELCD11  equ    00010000b
mLCDWF11_BPFLCD11  equ    00100000b
mLCDWF11_BPGLCD11  equ    01000000b
mLCDWF11_BPHLCD11  equ    10000000b


;*** LCDWF12 - LCD Waveform Register 12; 0x0000101C ***
LCDWF12            equ    $0000101C                                ;*** LCDWF12 - LCD Waveform Register 12; 0x0000101C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF12_BPALCD12   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPBLCD12   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPCLCD12   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPDLCD12   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPELCD12   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPFLCD12   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPGLCD12   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF12_BPHLCD12   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF12_BPALCD12  equ    00000001b
mLCDWF12_BPBLCD12  equ    00000010b
mLCDWF12_BPCLCD12  equ    00000100b
mLCDWF12_BPDLCD12  equ    00001000b
mLCDWF12_BPELCD12  equ    00010000b
mLCDWF12_BPFLCD12  equ    00100000b
mLCDWF12_BPGLCD12  equ    01000000b
mLCDWF12_BPHLCD12  equ    10000000b


;*** LCDWF13 - LCD Waveform Register 13; 0x0000101D ***
LCDWF13            equ    $0000101D                                ;*** LCDWF13 - LCD Waveform Register 13; 0x0000101D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF13_BPALCD13   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPBLCD13   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPCLCD13   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPDLCD13   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPELCD13   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPFLCD13   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPGLCD13   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF13_BPHLCD13   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF13_BPALCD13  equ    00000001b
mLCDWF13_BPBLCD13  equ    00000010b
mLCDWF13_BPCLCD13  equ    00000100b
mLCDWF13_BPDLCD13  equ    00001000b
mLCDWF13_BPELCD13  equ    00010000b
mLCDWF13_BPFLCD13  equ    00100000b
mLCDWF13_BPGLCD13  equ    01000000b
mLCDWF13_BPHLCD13  equ    10000000b


;*** LCDWF14 - LCD Waveform Register 14; 0x0000101E ***
LCDWF14            equ    $0000101E                                ;*** LCDWF14 - LCD Waveform Register 14; 0x0000101E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF14_BPALCD14   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPBLCD14   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPCLCD14   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPDLCD14   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPELCD14   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPFLCD14   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPGLCD14   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF14_BPHLCD14   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF14_BPALCD14  equ    00000001b
mLCDWF14_BPBLCD14  equ    00000010b
mLCDWF14_BPCLCD14  equ    00000100b
mLCDWF14_BPDLCD14  equ    00001000b
mLCDWF14_BPELCD14  equ    00010000b
mLCDWF14_BPFLCD14  equ    00100000b
mLCDWF14_BPGLCD14  equ    01000000b
mLCDWF14_BPHLCD14  equ    10000000b


;*** LCDWF15 - LCD Waveform Register 15; 0x0000101F ***
LCDWF15            equ    $0000101F                                ;*** LCDWF15 - LCD Waveform Register 15; 0x0000101F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF15_BPALCD15   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPBLCD15   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPCLCD15   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPDLCD15   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPELCD15   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPFLCD15   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPGLCD15   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF15_BPHLCD15   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF15_BPALCD15  equ    00000001b
mLCDWF15_BPBLCD15  equ    00000010b
mLCDWF15_BPCLCD15  equ    00000100b
mLCDWF15_BPDLCD15  equ    00001000b
mLCDWF15_BPELCD15  equ    00010000b
mLCDWF15_BPFLCD15  equ    00100000b
mLCDWF15_BPGLCD15  equ    01000000b
mLCDWF15_BPHLCD15  equ    10000000b


;*** LCDWF16 - LCD Waveform Register 16; 0x00001020 ***
LCDWF16            equ    $00001020                                ;*** LCDWF16 - LCD Waveform Register 16; 0x00001020 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF16_BPALCD16   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPBLCD16   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPCLCD16   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPDLCD16   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPELCD16   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPFLCD16   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPGLCD16   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF16_BPHLCD16   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF16_BPALCD16  equ    00000001b
mLCDWF16_BPBLCD16  equ    00000010b
mLCDWF16_BPCLCD16  equ    00000100b
mLCDWF16_BPDLCD16  equ    00001000b
mLCDWF16_BPELCD16  equ    00010000b
mLCDWF16_BPFLCD16  equ    00100000b
mLCDWF16_BPGLCD16  equ    01000000b
mLCDWF16_BPHLCD16  equ    10000000b


;*** LCDWF17 - LCD Waveform Register 17; 0x00001021 ***
LCDWF17            equ    $00001021                                ;*** LCDWF17 - LCD Waveform Register 17; 0x00001021 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF17_BPALCD17   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPBLCD17   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPCLCD17   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPDLCD17   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPELCD17   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPFLCD17   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPGLCD17   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF17_BPHLCD17   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF17_BPALCD17  equ    00000001b
mLCDWF17_BPBLCD17  equ    00000010b
mLCDWF17_BPCLCD17  equ    00000100b
mLCDWF17_BPDLCD17  equ    00001000b
mLCDWF17_BPELCD17  equ    00010000b
mLCDWF17_BPFLCD17  equ    00100000b
mLCDWF17_BPGLCD17  equ    01000000b
mLCDWF17_BPHLCD17  equ    10000000b


;*** LCDWF18 - LCD Waveform Register 18; 0x00001022 ***
LCDWF18            equ    $00001022                                ;*** LCDWF18 - LCD Waveform Register 18; 0x00001022 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF18_BPALCD18   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPBLCD18   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPCLCD18   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPDLCD18   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPELCD18   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPFLCD18   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPGLCD18   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF18_BPHLCD18   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF18_BPALCD18  equ    00000001b
mLCDWF18_BPBLCD18  equ    00000010b
mLCDWF18_BPCLCD18  equ    00000100b
mLCDWF18_BPDLCD18  equ    00001000b
mLCDWF18_BPELCD18  equ    00010000b
mLCDWF18_BPFLCD18  equ    00100000b
mLCDWF18_BPGLCD18  equ    01000000b
mLCDWF18_BPHLCD18  equ    10000000b


;*** LCDWF19 - LCD Waveform Register 19; 0x00001023 ***
LCDWF19            equ    $00001023                                ;*** LCDWF19 - LCD Waveform Register 19; 0x00001023 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF19_BPALCD19   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPBLCD19   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPCLCD19   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPDLCD19   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPELCD19   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPFLCD19   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPGLCD19   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF19_BPHLCD19   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF19_BPALCD19  equ    00000001b
mLCDWF19_BPBLCD19  equ    00000010b
mLCDWF19_BPCLCD19  equ    00000100b
mLCDWF19_BPDLCD19  equ    00001000b
mLCDWF19_BPELCD19  equ    00010000b
mLCDWF19_BPFLCD19  equ    00100000b
mLCDWF19_BPGLCD19  equ    01000000b
mLCDWF19_BPHLCD19  equ    10000000b


;*** LCDWF20 - LCD Waveform Register 20; 0x00001024 ***
LCDWF20            equ    $00001024                                ;*** LCDWF20 - LCD Waveform Register 20; 0x00001024 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF20_BPALCD20   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPBLCD20   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPCLCD20   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPDLCD20   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPELCD20   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPFLCD20   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPGLCD20   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF20_BPHLCD20   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF20_BPALCD20  equ    00000001b
mLCDWF20_BPBLCD20  equ    00000010b
mLCDWF20_BPCLCD20  equ    00000100b
mLCDWF20_BPDLCD20  equ    00001000b
mLCDWF20_BPELCD20  equ    00010000b
mLCDWF20_BPFLCD20  equ    00100000b
mLCDWF20_BPGLCD20  equ    01000000b
mLCDWF20_BPHLCD20  equ    10000000b


;*** LCDWF21 - LCD Waveform Register 21; 0x00001025 ***
LCDWF21            equ    $00001025                                ;*** LCDWF21 - LCD Waveform Register 21; 0x00001025 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF21_BPALCD21   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPBLCD21   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPCLCD21   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPDLCD21   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPELCD21   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPFLCD21   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPGLCD21   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF21_BPHLCD21   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF21_BPALCD21  equ    00000001b
mLCDWF21_BPBLCD21  equ    00000010b
mLCDWF21_BPCLCD21  equ    00000100b
mLCDWF21_BPDLCD21  equ    00001000b
mLCDWF21_BPELCD21  equ    00010000b
mLCDWF21_BPFLCD21  equ    00100000b
mLCDWF21_BPGLCD21  equ    01000000b
mLCDWF21_BPHLCD21  equ    10000000b


;*** LCDWF22 - LCD Waveform Register 22; 0x00001026 ***
LCDWF22            equ    $00001026                                ;*** LCDWF22 - LCD Waveform Register 22; 0x00001026 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF22_BPALCD22   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPBLCD22   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPCLCD22   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPDLCD22   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPELCD22   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPFLCD22   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPGLCD22   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF22_BPHLCD22   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF22_BPALCD22  equ    00000001b
mLCDWF22_BPBLCD22  equ    00000010b
mLCDWF22_BPCLCD22  equ    00000100b
mLCDWF22_BPDLCD22  equ    00001000b
mLCDWF22_BPELCD22  equ    00010000b
mLCDWF22_BPFLCD22  equ    00100000b
mLCDWF22_BPGLCD22  equ    01000000b
mLCDWF22_BPHLCD22  equ    10000000b


;*** LCDWF23 - LCD Waveform Register 23; 0x00001027 ***
LCDWF23            equ    $00001027                                ;*** LCDWF23 - LCD Waveform Register 23; 0x00001027 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF23_BPALCD23   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPBLCD23   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPCLCD23   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPDLCD23   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPELCD23   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPFLCD23   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPGLCD23   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF23_BPHLCD23   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF23_BPALCD23  equ    00000001b
mLCDWF23_BPBLCD23  equ    00000010b
mLCDWF23_BPCLCD23  equ    00000100b
mLCDWF23_BPDLCD23  equ    00001000b
mLCDWF23_BPELCD23  equ    00010000b
mLCDWF23_BPFLCD23  equ    00100000b
mLCDWF23_BPGLCD23  equ    01000000b
mLCDWF23_BPHLCD23  equ    10000000b


;*** LCDWF24 - LCD Waveform Register 24; 0x00001028 ***
LCDWF24            equ    $00001028                                ;*** LCDWF24 - LCD Waveform Register 24; 0x00001028 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF24_BPALCD24   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPBLCD24   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPCLCD24   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPDLCD24   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPELCD24   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPFLCD24   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPGLCD24   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF24_BPHLCD24   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF24_BPALCD24  equ    00000001b
mLCDWF24_BPBLCD24  equ    00000010b
mLCDWF24_BPCLCD24  equ    00000100b
mLCDWF24_BPDLCD24  equ    00001000b
mLCDWF24_BPELCD24  equ    00010000b
mLCDWF24_BPFLCD24  equ    00100000b
mLCDWF24_BPGLCD24  equ    01000000b
mLCDWF24_BPHLCD24  equ    10000000b


;*** LCDWF25 - LCD Waveform Register 25; 0x00001029 ***
LCDWF25            equ    $00001029                                ;*** LCDWF25 - LCD Waveform Register 25; 0x00001029 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF25_BPALCD25   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPBLCD25   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPCLCD25   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPDLCD25   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPELCD25   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPFLCD25   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPGLCD25   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF25_BPHLCD25   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF25_BPALCD25  equ    00000001b
mLCDWF25_BPBLCD25  equ    00000010b
mLCDWF25_BPCLCD25  equ    00000100b
mLCDWF25_BPDLCD25  equ    00001000b
mLCDWF25_BPELCD25  equ    00010000b
mLCDWF25_BPFLCD25  equ    00100000b
mLCDWF25_BPGLCD25  equ    01000000b
mLCDWF25_BPHLCD25  equ    10000000b


;*** LCDWF26 - LCD Waveform Register 26; 0x0000102A ***
LCDWF26            equ    $0000102A                                ;*** LCDWF26 - LCD Waveform Register 26; 0x0000102A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF26_BPALCD26   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPBLCD26   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPCLCD26   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPDLCD26   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPELCD26   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPFLCD26   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPGLCD26   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF26_BPHLCD26   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF26_BPALCD26  equ    00000001b
mLCDWF26_BPBLCD26  equ    00000010b
mLCDWF26_BPCLCD26  equ    00000100b
mLCDWF26_BPDLCD26  equ    00001000b
mLCDWF26_BPELCD26  equ    00010000b
mLCDWF26_BPFLCD26  equ    00100000b
mLCDWF26_BPGLCD26  equ    01000000b
mLCDWF26_BPHLCD26  equ    10000000b


;*** LCDWF27 - LCD Waveform Register 27; 0x0000102B ***
LCDWF27            equ    $0000102B                                ;*** LCDWF27 - LCD Waveform Register 27; 0x0000102B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF27_BPALCD27   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPBLCD27   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPCLCD27   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPDLCD27   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPELCD27   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPFLCD27   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPGLCD27   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF27_BPHLCD27   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF27_BPALCD27  equ    00000001b
mLCDWF27_BPBLCD27  equ    00000010b
mLCDWF27_BPCLCD27  equ    00000100b
mLCDWF27_BPDLCD27  equ    00001000b
mLCDWF27_BPELCD27  equ    00010000b
mLCDWF27_BPFLCD27  equ    00100000b
mLCDWF27_BPGLCD27  equ    01000000b
mLCDWF27_BPHLCD27  equ    10000000b


;*** LCDWF28 - LCD Waveform Register 28; 0x0000102C ***
LCDWF28            equ    $0000102C                                ;*** LCDWF28 - LCD Waveform Register 28; 0x0000102C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF28_BPALCD28   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPBLCD28   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPCLCD28   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPDLCD28   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPELCD28   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPFLCD28   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPGLCD28   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF28_BPHLCD28   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF28_BPALCD28  equ    00000001b
mLCDWF28_BPBLCD28  equ    00000010b
mLCDWF28_BPCLCD28  equ    00000100b
mLCDWF28_BPDLCD28  equ    00001000b
mLCDWF28_BPELCD28  equ    00010000b
mLCDWF28_BPFLCD28  equ    00100000b
mLCDWF28_BPGLCD28  equ    01000000b
mLCDWF28_BPHLCD28  equ    10000000b


;*** LCDWF29 - LCD Waveform Register 29; 0x0000102D ***
LCDWF29            equ    $0000102D                                ;*** LCDWF29 - LCD Waveform Register 29; 0x0000102D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF29_BPALCD29   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPBLCD29   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPCLCD29   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPDLCD29   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPELCD29   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPFLCD29   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPGLCD29   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF29_BPHLCD29   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF29_BPALCD29  equ    00000001b
mLCDWF29_BPBLCD29  equ    00000010b
mLCDWF29_BPCLCD29  equ    00000100b
mLCDWF29_BPDLCD29  equ    00001000b
mLCDWF29_BPELCD29  equ    00010000b
mLCDWF29_BPFLCD29  equ    00100000b
mLCDWF29_BPGLCD29  equ    01000000b
mLCDWF29_BPHLCD29  equ    10000000b


;*** LCDWF30 - LCD Waveform Register 30; 0x0000102E ***
LCDWF30            equ    $0000102E                                ;*** LCDWF30 - LCD Waveform Register 30; 0x0000102E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF30_BPALCD30   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPBLCD30   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPCLCD30   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPDLCD30   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPELCD30   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPFLCD30   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPGLCD30   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF30_BPHLCD30   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF30_BPALCD30  equ    00000001b
mLCDWF30_BPBLCD30  equ    00000010b
mLCDWF30_BPCLCD30  equ    00000100b
mLCDWF30_BPDLCD30  equ    00001000b
mLCDWF30_BPELCD30  equ    00010000b
mLCDWF30_BPFLCD30  equ    00100000b
mLCDWF30_BPGLCD30  equ    01000000b
mLCDWF30_BPHLCD30  equ    10000000b


;*** LCDWF31 - LCD Waveform Register 31; 0x0000102F ***
LCDWF31            equ    $0000102F                                ;*** LCDWF31 - LCD Waveform Register 31; 0x0000102F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF31_BPALCD31   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPBLCD31   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPCLCD31   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPDLCD31   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPELCD31   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPFLCD31   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPGLCD31   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF31_BPHLCD31   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF31_BPALCD31  equ    00000001b
mLCDWF31_BPBLCD31  equ    00000010b
mLCDWF31_BPCLCD31  equ    00000100b
mLCDWF31_BPDLCD31  equ    00001000b
mLCDWF31_BPELCD31  equ    00010000b
mLCDWF31_BPFLCD31  equ    00100000b
mLCDWF31_BPGLCD31  equ    01000000b
mLCDWF31_BPHLCD31  equ    10000000b


;*** LCDWF32 - LCD Waveform Register 32; 0x00001030 ***
LCDWF32            equ    $00001030                                ;*** LCDWF32 - LCD Waveform Register 32; 0x00001030 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF32_BPALCD32   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPBLCD32   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPCLCD32   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPDLCD32   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPELCD32   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPFLCD32   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPGLCD32   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF32_BPHLCD32   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF32_BPALCD32  equ    00000001b
mLCDWF32_BPBLCD32  equ    00000010b
mLCDWF32_BPCLCD32  equ    00000100b
mLCDWF32_BPDLCD32  equ    00001000b
mLCDWF32_BPELCD32  equ    00010000b
mLCDWF32_BPFLCD32  equ    00100000b
mLCDWF32_BPGLCD32  equ    01000000b
mLCDWF32_BPHLCD32  equ    10000000b


;*** LCDWF33 - LCD Waveform Register 33; 0x00001031 ***
LCDWF33            equ    $00001031                                ;*** LCDWF33 - LCD Waveform Register 33; 0x00001031 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF33_BPALCD33   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPBLCD33   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPCLCD33   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPDLCD33   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPELCD33   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPFLCD33   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPGLCD33   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF33_BPHLCD33   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF33_BPALCD33  equ    00000001b
mLCDWF33_BPBLCD33  equ    00000010b
mLCDWF33_BPCLCD33  equ    00000100b
mLCDWF33_BPDLCD33  equ    00001000b
mLCDWF33_BPELCD33  equ    00010000b
mLCDWF33_BPFLCD33  equ    00100000b
mLCDWF33_BPGLCD33  equ    01000000b
mLCDWF33_BPHLCD33  equ    10000000b


;*** LCDWF34 - LCD Waveform Register 34; 0x00001032 ***
LCDWF34            equ    $00001032                                ;*** LCDWF34 - LCD Waveform Register 34; 0x00001032 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF34_BPALCD34   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPBLCD34   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPCLCD34   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPDLCD34   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPELCD34   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPFLCD34   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPGLCD34   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF34_BPHLCD34   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF34_BPALCD34  equ    00000001b
mLCDWF34_BPBLCD34  equ    00000010b
mLCDWF34_BPCLCD34  equ    00000100b
mLCDWF34_BPDLCD34  equ    00001000b
mLCDWF34_BPELCD34  equ    00010000b
mLCDWF34_BPFLCD34  equ    00100000b
mLCDWF34_BPGLCD34  equ    01000000b
mLCDWF34_BPHLCD34  equ    10000000b


;*** LCDWF35 - LCD Waveform Register 35; 0x00001033 ***
LCDWF35            equ    $00001033                                ;*** LCDWF35 - LCD Waveform Register 35; 0x00001033 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF35_BPALCD35   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPBLCD35   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPCLCD35   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPDLCD35   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPELCD35   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPFLCD35   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPGLCD35   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF35_BPHLCD35   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF35_BPALCD35  equ    00000001b
mLCDWF35_BPBLCD35  equ    00000010b
mLCDWF35_BPCLCD35  equ    00000100b
mLCDWF35_BPDLCD35  equ    00001000b
mLCDWF35_BPELCD35  equ    00010000b
mLCDWF35_BPFLCD35  equ    00100000b
mLCDWF35_BPGLCD35  equ    01000000b
mLCDWF35_BPHLCD35  equ    10000000b


;*** LCDWF36 - LCD Waveform Register 36; 0x00001034 ***
LCDWF36            equ    $00001034                                ;*** LCDWF36 - LCD Waveform Register 36; 0x00001034 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF36_BPALCD36   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPBLCD36   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPCLCD36   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPDLCD36   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPELCD36   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPFLCD36   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPGLCD36   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF36_BPHLCD36   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF36_BPALCD36  equ    00000001b
mLCDWF36_BPBLCD36  equ    00000010b
mLCDWF36_BPCLCD36  equ    00000100b
mLCDWF36_BPDLCD36  equ    00001000b
mLCDWF36_BPELCD36  equ    00010000b
mLCDWF36_BPFLCD36  equ    00100000b
mLCDWF36_BPGLCD36  equ    01000000b
mLCDWF36_BPHLCD36  equ    10000000b


;*** LCDWF37 - LCD Waveform Register 37; 0x00001035 ***
LCDWF37            equ    $00001035                                ;*** LCDWF37 - LCD Waveform Register 37; 0x00001035 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF37_BPALCD37   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPBLCD37   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPCLCD37   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPDLCD37   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPELCD37   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPFLCD37   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPGLCD37   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF37_BPHLCD37   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF37_BPALCD37  equ    00000001b
mLCDWF37_BPBLCD37  equ    00000010b
mLCDWF37_BPCLCD37  equ    00000100b
mLCDWF37_BPDLCD37  equ    00001000b
mLCDWF37_BPELCD37  equ    00010000b
mLCDWF37_BPFLCD37  equ    00100000b
mLCDWF37_BPGLCD37  equ    01000000b
mLCDWF37_BPHLCD37  equ    10000000b


;*** LCDWF38 - LCD Waveform Register 38; 0x00001036 ***
LCDWF38            equ    $00001036                                ;*** LCDWF38 - LCD Waveform Register 38; 0x00001036 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF38_BPALCD38   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPBLCD38   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPCLCD38   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPDLCD38   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPELCD38   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPFLCD38   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPGLCD38   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF38_BPHLCD38   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF38_BPALCD38  equ    00000001b
mLCDWF38_BPBLCD38  equ    00000010b
mLCDWF38_BPCLCD38  equ    00000100b
mLCDWF38_BPDLCD38  equ    00001000b
mLCDWF38_BPELCD38  equ    00010000b
mLCDWF38_BPFLCD38  equ    00100000b
mLCDWF38_BPGLCD38  equ    01000000b
mLCDWF38_BPHLCD38  equ    10000000b


;*** LCDWF39 - LCD Waveform Register 39; 0x00001037 ***
LCDWF39            equ    $00001037                                ;*** LCDWF39 - LCD Waveform Register 39; 0x00001037 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF39_BPALCD39   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPBLCD39   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPCLCD39   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPDLCD39   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPELCD39   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPFLCD39   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPGLCD39   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF39_BPHLCD39   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF39_BPALCD39  equ    00000001b
mLCDWF39_BPBLCD39  equ    00000010b
mLCDWF39_BPCLCD39  equ    00000100b
mLCDWF39_BPDLCD39  equ    00001000b
mLCDWF39_BPELCD39  equ    00010000b
mLCDWF39_BPFLCD39  equ    00100000b
mLCDWF39_BPGLCD39  equ    01000000b
mLCDWF39_BPHLCD39  equ    10000000b


;*** LCDWF40 - LCD Waveform Register 40; 0x00001038 ***
LCDWF40            equ    $00001038                                ;*** LCDWF40 - LCD Waveform Register 40; 0x00001038 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF40_BPALCD40   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPBLCD40   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPCLCD40   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPDLCD40   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPELCD40   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPFLCD40   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPGLCD40   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF40_BPHLCD40   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF40_BPALCD40  equ    00000001b
mLCDWF40_BPBLCD40  equ    00000010b
mLCDWF40_BPCLCD40  equ    00000100b
mLCDWF40_BPDLCD40  equ    00001000b
mLCDWF40_BPELCD40  equ    00010000b
mLCDWF40_BPFLCD40  equ    00100000b
mLCDWF40_BPGLCD40  equ    01000000b
mLCDWF40_BPHLCD40  equ    10000000b


;*** LCDWF41 - LCD Waveform Register 41; 0x00001039 ***
LCDWF41            equ    $00001039                                ;*** LCDWF41 - LCD Waveform Register 41; 0x00001039 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF41_BPALCD41   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPBLCD41   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPCLCD41   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPDLCD41   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPELCD41   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPFLCD41   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPGLCD41   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF41_BPHLCD41   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF41_BPALCD41  equ    00000001b
mLCDWF41_BPBLCD41  equ    00000010b
mLCDWF41_BPCLCD41  equ    00000100b
mLCDWF41_BPDLCD41  equ    00001000b
mLCDWF41_BPELCD41  equ    00010000b
mLCDWF41_BPFLCD41  equ    00100000b
mLCDWF41_BPGLCD41  equ    01000000b
mLCDWF41_BPHLCD41  equ    10000000b


;*** LCDWF42 - LCD Waveform Register 42; 0x0000103A ***
LCDWF42            equ    $0000103A                                ;*** LCDWF42 - LCD Waveform Register 42; 0x0000103A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF42_BPALCD42   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPBLCD42   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPCLCD42   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPDLCD42   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPELCD42   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPFLCD42   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPGLCD42   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF42_BPHLCD42   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF42_BPALCD42  equ    00000001b
mLCDWF42_BPBLCD42  equ    00000010b
mLCDWF42_BPCLCD42  equ    00000100b
mLCDWF42_BPDLCD42  equ    00001000b
mLCDWF42_BPELCD42  equ    00010000b
mLCDWF42_BPFLCD42  equ    00100000b
mLCDWF42_BPGLCD42  equ    01000000b
mLCDWF42_BPHLCD42  equ    10000000b


;*** LCDWF43 - LCD Waveform Register 43; 0x0000103B ***
LCDWF43            equ    $0000103B                                ;*** LCDWF43 - LCD Waveform Register 43; 0x0000103B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
LCDWF43_BPALCD43   equ    0                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPBLCD43   equ    1                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPCLCD43   equ    2                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPDLCD43   equ    3                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPELCD43   equ    4                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPFLCD43   equ    5                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPGLCD43   equ    6                                         ; Segment on/off Frontplane/Backplane Operation
LCDWF43_BPHLCD43   equ    7                                         ; Segment on/off Frontplane/Backplane Operation
; bit position masks
mLCDWF43_BPALCD43  equ    00000001b
mLCDWF43_BPBLCD43  equ    00000010b
mLCDWF43_BPCLCD43  equ    00000100b
mLCDWF43_BPDLCD43  equ    00001000b
mLCDWF43_BPELCD43  equ    00010000b
mLCDWF43_BPFLCD43  equ    00100000b
mLCDWF43_BPGLCD43  equ    01000000b
mLCDWF43_BPHLCD43  equ    10000000b


;*** SRS - System Reset Status Register; 0x00001800 ***
SRS                equ    $00001800                                ;*** SRS - System Reset Status Register; 0x00001800 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SRS_LVD            equ    1                                         ; Low Voltage Detect
SRS_ILAD           equ    3                                         ; Illegal Address
SRS_ILOP           equ    4                                         ; Illegal Opcode
SRS_COP            equ    5                                         ; Computer Operating Properly (COP) Watchdog
SRS_PIN            equ    6                                         ; External Reset Pin
SRS_POR            equ    7                                         ; Power-On Reset
; bit position masks
mSRS_LVD           equ    00000010b
mSRS_ILAD          equ    00001000b
mSRS_ILOP          equ    00010000b
mSRS_COP           equ    00100000b
mSRS_PIN           equ    01000000b
mSRS_POR           equ    10000000b


;*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***
SBDFR              equ    $00001801                                ;*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SBDFR_BDFR         equ    0                                         ; Background Debug Force Reset
; bit position masks
mSBDFR_BDFR        equ    00000001b


;*** SOPT1 - System Options Register 1; 0x00001802 ***
SOPT1              equ    $00001802                                ;*** SOPT1 - System Options Register 1; 0x00001802 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT1_RSTPE        equ    0                                         ; RESET Pin Enable
SOPT1_BKGDPE       equ    1                                         ; Background Debug Mode Pin Enable
SOPT1_STOPE        equ    5                                         ; Stop Mode Enable
SOPT1_COPT         equ    6                                         ; COP Watchdog Timeout
SOPT1_COPE         equ    7                                         ; COP Watchdog Enable
; bit position masks
mSOPT1_RSTPE       equ    00000001b
mSOPT1_BKGDPE      equ    00000010b
mSOPT1_STOPE       equ    00100000b
mSOPT1_COPT        equ    01000000b
mSOPT1_COPE        equ    10000000b


;*** SOPT2 - System Options Register 2; 0x00001803 ***
SOPT2              equ    $00001803                                ;*** SOPT2 - System Options Register 2; 0x00001803 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SOPT2_ACIC         equ    0                                         ; Analog Comparator to Input Capture Enable
SOPT2_IICPS        equ    1                                         ; IIC Pin Select
SOPT2_SPIPS        equ    2                                         ; SPI Pin Select
SOPT2_ADCTRS       equ    3                                         ; ADC Trigger Select
SOPT2_COPCLKS      equ    7                                         ; COP Watchdog Clock Select
; bit position masks
mSOPT2_ACIC        equ    00000001b
mSOPT2_IICPS       equ    00000010b
mSOPT2_SPIPS       equ    00000100b
mSOPT2_ADCTRS      equ    00001000b
mSOPT2_COPCLKS     equ    10000000b


;*** SDID - System Device Identification Register; 0x00001806 ***
SDID               equ    $00001806                                ;*** SDID - System Device Identification Register; 0x00001806 ***


;*** SDIDH - System Device Identification Register High; 0x00001806 ***
SDIDH              equ    $00001806                                ;*** SDIDH - System Device Identification Register High; 0x00001806 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDH_ID8          equ    0                                         ; Part Identification Number, bit 8
SDIDH_ID9          equ    1                                         ; Part Identification Number, bit 9
SDIDH_ID10         equ    2                                         ; Part Identification Number, bit 10
SDIDH_ID11         equ    3                                         ; Part Identification Number, bit 11
; bit position masks
mSDIDH_ID8         equ    00000001b
mSDIDH_ID9         equ    00000010b
mSDIDH_ID10        equ    00000100b
mSDIDH_ID11        equ    00001000b


;*** SDIDL - System Device Identification Register Low; 0x00001807 ***
SDIDL              equ    $00001807                                ;*** SDIDL - System Device Identification Register Low; 0x00001807 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SDIDL_ID0          equ    0                                         ; Part Identification Number, bit 0
SDIDL_ID1          equ    1                                         ; Part Identification Number, bit 1
SDIDL_ID2          equ    2                                         ; Part Identification Number, bit 2
SDIDL_ID3          equ    3                                         ; Part Identification Number, bit 3
SDIDL_ID4          equ    4                                         ; Part Identification Number, bit 4
SDIDL_ID5          equ    5                                         ; Part Identification Number, bit 5
SDIDL_ID6          equ    6                                         ; Part Identification Number, bit 6
SDIDL_ID7          equ    7                                         ; Part Identification Number, bit 7
; bit position masks
mSDIDL_ID0         equ    00000001b
mSDIDL_ID1         equ    00000010b
mSDIDL_ID2         equ    00000100b
mSDIDL_ID3         equ    00001000b
mSDIDL_ID4         equ    00010000b
mSDIDL_ID5         equ    00100000b
mSDIDL_ID6         equ    01000000b
mSDIDL_ID7         equ    10000000b


;*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001808 ***
SPMSC1             equ    $00001808                                ;*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001808 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC1_BGBE        equ    0                                         ; Bandgap Buffer Enable
SPMSC1_BGBDS       equ    1                                         ; Bandgap Buffer Drive Select
SPMSC1_LVDE        equ    2                                         ; Low-Voltage Detect Enable
SPMSC1_LVDSE       equ    3                                         ; Low-Voltage Detect Stop Enable
SPMSC1_LVDRE       equ    4                                         ; Low-Voltage Detect Reset Enable
SPMSC1_LVDIE       equ    5                                         ; Low-Voltage Detect Interrupt Enable
SPMSC1_LVDACK      equ    6                                         ; Low-Voltage Detect Acknowledge
SPMSC1_LVDF        equ    7                                         ; Low-Voltage Detect Flag
; bit position masks
mSPMSC1_BGBE       equ    00000001b
mSPMSC1_BGBDS      equ    00000010b
mSPMSC1_LVDE       equ    00000100b
mSPMSC1_LVDSE      equ    00001000b
mSPMSC1_LVDRE      equ    00010000b
mSPMSC1_LVDIE      equ    00100000b
mSPMSC1_LVDACK     equ    01000000b
mSPMSC1_LVDF       equ    10000000b


;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x00001809 ***
SPMSC2             equ    $00001809                                ;*** SPMSC2 - System Power Management Status and Control 2 Register; 0x00001809 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC2_PPDC        equ    0                                         ; Partial Power Down Control
SPMSC2_PPDE        equ    1                                         ; Partial Power-Down Enable
SPMSC2_PPDACK      equ    2                                         ; Partial Power Down Acknowledge
SPMSC2_PPDF        equ    3                                         ; Partial Power Down Flag
SPMSC2_LPWUI       equ    5                                         ; Low Power Wake Up on Interrupt
SPMSC2_LPRS        equ    6                                         ; Low Power Regulator Status
SPMSC2_LPR         equ    7                                         ; Low Power Regulator Control
; bit position masks
mSPMSC2_PPDC       equ    00000001b
mSPMSC2_PPDE       equ    00000010b
mSPMSC2_PPDACK     equ    00000100b
mSPMSC2_PPDF       equ    00001000b
mSPMSC2_LPWUI      equ    00100000b
mSPMSC2_LPRS       equ    01000000b
mSPMSC2_LPR        equ    10000000b


;*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000180B ***
SPMSC3             equ    $0000180B                                ;*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000180B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SPMSC3_LVWIE       equ    3                                         ; Low-Voltage Warning Interrupt Enable
SPMSC3_LVWV        equ    4                                         ; Low-Voltage Warning Voltage Select
SPMSC3_LVDV        equ    5                                         ; Low-Voltage Detect Voltage Select
SPMSC3_LVWACK      equ    6                                         ; Low-Voltage Warning Acknowledge
SPMSC3_LVWF        equ    7                                         ; Low-Voltage Warning Flag
; bit position masks
mSPMSC3_LVWIE      equ    00001000b
mSPMSC3_LVWV       equ    00010000b
mSPMSC3_LVDV       equ    00100000b
mSPMSC3_LVWACK     equ    01000000b
mSPMSC3_LVWF       equ    10000000b


;*** SCGC1 - System Clock Gating Control 1 Register; 0x0000180E ***
SCGC1              equ    $0000180E                                ;*** SCGC1 - System Clock Gating Control 1 Register; 0x0000180E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC1_SCI1         equ    0                                         ; SCI1 Clock Gate Control
SCGC1_SCI2         equ    1                                         ; SCI2 Clock Gate Control
SCGC1_IIC          equ    2                                         ; IIC Clock Gate Control
SCGC1_VREF1        equ    3                                         ; VREF1 Clock Gate Control
SCGC1_ADC          equ    4                                         ; ADC Clock Gate Control
SCGC1_TPM1         equ    5                                         ; TPM1 Clock Gate Control
SCGC1_TPM2         equ    6                                         ; TPM2 Clock Gate Control
SCGC1_VREF2        equ    7                                         ; VREF2 Clock Gate Control
; bit position masks
mSCGC1_SCI1        equ    00000001b
mSCGC1_SCI2        equ    00000010b
mSCGC1_IIC         equ    00000100b
mSCGC1_VREF1       equ    00001000b
mSCGC1_ADC         equ    00010000b
mSCGC1_TPM1        equ    00100000b
mSCGC1_TPM2        equ    01000000b
mSCGC1_VREF2       equ    10000000b


;*** SCGC2 - System Clock Gating Control 2 Register; 0x0000180F ***
SCGC2              equ    $0000180F                                ;*** SCGC2 - System Clock Gating Control 2 Register; 0x0000180F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCGC2_SPI          equ    0                                         ; SPI Clock Gate Control
SCGC2_LCD          equ    1                                         ; LCD Clock Gate Control
SCGC2_TOD          equ    2                                         ; TOD Clock Gate Control
SCGC2_ACMP         equ    3                                         ; ACMP Clock Gate Control
SCGC2_KBI          equ    4                                         ; KBI Clock Gate Control
SCGC2_IRQ          equ    5                                         ; IRQ Clock Gate Control
SCGC2_FLS          equ    6                                         ; FLASH Register Clock Gate Control
SCGC2_DBG          equ    7                                         ; DBG Clock Gate Control
; bit position masks
mSCGC2_SPI         equ    00000001b
mSCGC2_LCD         equ    00000010b
mSCGC2_TOD         equ    00000100b
mSCGC2_ACMP        equ    00001000b
mSCGC2_KBI         equ    00010000b
mSCGC2_IRQ         equ    00100000b
mSCGC2_FLS         equ    01000000b
mSCGC2_DBG         equ    10000000b


;*** DBGCA - Debug Comparator A Register; 0x00001810 ***
DBGCA              equ    $00001810                                ;*** DBGCA - Debug Comparator A Register; 0x00001810 ***


;*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***
DBGCAH             equ    $00001810                                ;*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAH_Bit8        equ    0                                         ; Comparator A High Compare Bit 8
DBGCAH_Bit9        equ    1                                         ; Comparator A High Compare Bit 9
DBGCAH_Bit10       equ    2                                         ; Comparator A High Compare Bit 10
DBGCAH_Bit11       equ    3                                         ; Comparator A High Compare Bit 11
DBGCAH_Bit12       equ    4                                         ; Comparator A High Compare Bit 12
DBGCAH_Bit13       equ    5                                         ; Comparator A High Compare Bit 13
DBGCAH_Bit14       equ    6                                         ; Comparator A High Compare Bit 14
DBGCAH_Bit15       equ    7                                         ; Comparator A High Compare Bit 15
; bit position masks
mDBGCAH_Bit8       equ    00000001b
mDBGCAH_Bit9       equ    00000010b
mDBGCAH_Bit10      equ    00000100b
mDBGCAH_Bit11      equ    00001000b
mDBGCAH_Bit12      equ    00010000b
mDBGCAH_Bit13      equ    00100000b
mDBGCAH_Bit14      equ    01000000b
mDBGCAH_Bit15      equ    10000000b


;*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***
DBGCAL             equ    $00001811                                ;*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAL_Bit0        equ    0                                         ; Comparator A Low Compare Bit 0
DBGCAL_Bit1        equ    1                                         ; Comparator A Low Compare Bit 1
DBGCAL_Bit2        equ    2                                         ; Comparator A Low Compare Bit 2
DBGCAL_Bit3        equ    3                                         ; Comparator A Low Compare Bit 3
DBGCAL_Bit4        equ    4                                         ; Comparator A Low Compare Bit 4
DBGCAL_Bit5        equ    5                                         ; Comparator A Low Compare Bit 5
DBGCAL_Bit6        equ    6                                         ; Comparator A Low Compare Bit 6
DBGCAL_Bit7        equ    7                                         ; Comparator A Low Compare Bit 7
; bit position masks
mDBGCAL_Bit0       equ    00000001b
mDBGCAL_Bit1       equ    00000010b
mDBGCAL_Bit2       equ    00000100b
mDBGCAL_Bit3       equ    00001000b
mDBGCAL_Bit4       equ    00010000b
mDBGCAL_Bit5       equ    00100000b
mDBGCAL_Bit6       equ    01000000b
mDBGCAL_Bit7       equ    10000000b


;*** DBGCB - Debug Comparator B Register; 0x00001812 ***
DBGCB              equ    $00001812                                ;*** DBGCB - Debug Comparator B Register; 0x00001812 ***


;*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***
DBGCBH             equ    $00001812                                ;*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBH_Bit8        equ    0                                         ; Comparator B High Compare Bit 8
DBGCBH_Bit9        equ    1                                         ; Comparator B High Compare Bit 9
DBGCBH_Bit10       equ    2                                         ; Comparator B High Compare Bit 10
DBGCBH_Bit11       equ    3                                         ; Comparator B High Compare Bit 11
DBGCBH_Bit12       equ    4                                         ; Comparator B High Compare Bit 12
DBGCBH_Bit13       equ    5                                         ; Comparator B High Compare Bit 13
DBGCBH_Bit14       equ    6                                         ; Comparator B High Compare Bit 14
DBGCBH_Bit15       equ    7                                         ; Comparator B High Compare Bit 15
; bit position masks
mDBGCBH_Bit8       equ    00000001b
mDBGCBH_Bit9       equ    00000010b
mDBGCBH_Bit10      equ    00000100b
mDBGCBH_Bit11      equ    00001000b
mDBGCBH_Bit12      equ    00010000b
mDBGCBH_Bit13      equ    00100000b
mDBGCBH_Bit14      equ    01000000b
mDBGCBH_Bit15      equ    10000000b


;*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***
DBGCBL             equ    $00001813                                ;*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBL_Bit0        equ    0                                         ; Comparator B Low Compare Bit 0
DBGCBL_Bit1        equ    1                                         ; Comparator B Low Compare Bit 1
DBGCBL_Bit2        equ    2                                         ; Comparator B Low Compare Bit 2
DBGCBL_Bit3        equ    3                                         ; Comparator B Low Compare Bit 3
DBGCBL_Bit4        equ    4                                         ; Comparator B Low Compare Bit 4
DBGCBL_Bit5        equ    5                                         ; Comparator B Low Compare Bit 5
DBGCBL_Bit6        equ    6                                         ; Comparator B Low Compare Bit 6
DBGCBL_Bit7        equ    7                                         ; Comparator B Low Compare Bit 7
; bit position masks
mDBGCBL_Bit0       equ    00000001b
mDBGCBL_Bit1       equ    00000010b
mDBGCBL_Bit2       equ    00000100b
mDBGCBL_Bit3       equ    00001000b
mDBGCBL_Bit4       equ    00010000b
mDBGCBL_Bit5       equ    00100000b
mDBGCBL_Bit6       equ    01000000b
mDBGCBL_Bit7       equ    10000000b


;*** DBGCC - Debug Comparator C Register; 0x00001814 ***
DBGCC              equ    $00001814                                ;*** DBGCC - Debug Comparator C Register; 0x00001814 ***


;*** DBGCCH - Debug Comparator C High Register; 0x00001814 ***
DBGCCH             equ    $00001814                                ;*** DBGCCH - Debug Comparator C High Register; 0x00001814 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCH_Bit8        equ    0                                         ; Comparator C High Compare Bit 8
DBGCCH_Bit9        equ    1                                         ; Comparator C High Compare Bit 9
DBGCCH_Bit10       equ    2                                         ; Comparator C High Compare Bit 10
DBGCCH_Bit11       equ    3                                         ; Comparator C High Compare Bit 11
DBGCCH_Bit12       equ    4                                         ; Comparator C High Compare Bit 12
DBGCCH_Bit13       equ    5                                         ; Comparator C High Compare Bit 13
DBGCCH_Bit14       equ    6                                         ; Comparator C High Compare Bit 14
DBGCCH_Bit15       equ    7                                         ; Comparator C High Compare Bit 15
; bit position masks
mDBGCCH_Bit8       equ    00000001b
mDBGCCH_Bit9       equ    00000010b
mDBGCCH_Bit10      equ    00000100b
mDBGCCH_Bit11      equ    00001000b
mDBGCCH_Bit12      equ    00010000b
mDBGCCH_Bit13      equ    00100000b
mDBGCCH_Bit14      equ    01000000b
mDBGCCH_Bit15      equ    10000000b


;*** DBGCCL - Debug Comparator C Low Register; 0x00001815 ***
DBGCCL             equ    $00001815                                ;*** DBGCCL - Debug Comparator C Low Register; 0x00001815 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCL_Bit0        equ    0                                         ; Comparator C Low Compare Bit 0
DBGCCL_Bit1        equ    1                                         ; Comparator C Low Compare Bit 1
DBGCCL_Bit2        equ    2                                         ; Comparator C Low Compare Bit 2
DBGCCL_Bit3        equ    3                                         ; Comparator C Low Compare Bit 3
DBGCCL_Bit4        equ    4                                         ; Comparator C Low Compare Bit 4
DBGCCL_Bit5        equ    5                                         ; Comparator C Low Compare Bit 5
DBGCCL_Bit6        equ    6                                         ; Comparator C Low Compare Bit 6
DBGCCL_Bit7        equ    7                                         ; Comparator C Low Compare Bit 7
; bit position masks
mDBGCCL_Bit0       equ    00000001b
mDBGCCL_Bit1       equ    00000010b
mDBGCCL_Bit2       equ    00000100b
mDBGCCL_Bit3       equ    00001000b
mDBGCCL_Bit4       equ    00010000b
mDBGCCL_Bit5       equ    00100000b
mDBGCCL_Bit6       equ    01000000b
mDBGCCL_Bit7       equ    10000000b


;*** DBGF - Debug FIFO Register; 0x00001816 ***
DBGF               equ    $00001816                                ;*** DBGF - Debug FIFO Register; 0x00001816 ***


;*** DBGFH - Debug FIFO High Register; 0x00001816 ***
DBGFH              equ    $00001816                                ;*** DBGFH - Debug FIFO High Register; 0x00001816 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFH_Bit8         equ    0                                         ; FIFO High Data Bit 8
DBGFH_Bit9         equ    1                                         ; FIFO High Data Bit 9
DBGFH_Bit10        equ    2                                         ; FIFO High Data Bit 10
DBGFH_Bit11        equ    3                                         ; FIFO High Data Bit 11
DBGFH_Bit12        equ    4                                         ; FIFO High Data Bit 12
DBGFH_Bit13        equ    5                                         ; FIFO High Data Bit 13
DBGFH_Bit14        equ    6                                         ; FIFO High Data Bit 14
DBGFH_Bit15        equ    7                                         ; FIFO High Data Bit 15
; bit position masks
mDBGFH_Bit8        equ    00000001b
mDBGFH_Bit9        equ    00000010b
mDBGFH_Bit10       equ    00000100b
mDBGFH_Bit11       equ    00001000b
mDBGFH_Bit12       equ    00010000b
mDBGFH_Bit13       equ    00100000b
mDBGFH_Bit14       equ    01000000b
mDBGFH_Bit15       equ    10000000b


;*** DBGFL - Debug FIFO Low Register; 0x00001817 ***
DBGFL              equ    $00001817                                ;*** DBGFL - Debug FIFO Low Register; 0x00001817 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFL_Bit0         equ    0                                         ; FIFO Low Data Bit 0
DBGFL_Bit1         equ    1                                         ; FIFO Low Data Bit 1
DBGFL_Bit2         equ    2                                         ; FIFO Low Data Bit 2
DBGFL_Bit3         equ    3                                         ; FIFO Low Data Bit 3
DBGFL_Bit4         equ    4                                         ; FIFO Low Data Bit 4
DBGFL_Bit5         equ    5                                         ; FIFO Low Data Bit 5
DBGFL_Bit6         equ    6                                         ; FIFO Low Data Bit 6
DBGFL_Bit7         equ    7                                         ; FIFO Low Data Bit 7
; bit position masks
mDBGFL_Bit0        equ    00000001b
mDBGFL_Bit1        equ    00000010b
mDBGFL_Bit2        equ    00000100b
mDBGFL_Bit3        equ    00001000b
mDBGFL_Bit4        equ    00010000b
mDBGFL_Bit5        equ    00100000b
mDBGFL_Bit6        equ    01000000b
mDBGFL_Bit7        equ    10000000b


;*** DBGCAX - Debug Comparator A Extension Register; 0x00001818 ***
DBGCAX             equ    $00001818                                ;*** DBGCAX - Debug Comparator A Extension Register; 0x00001818 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCAX_Bit16       equ    0                                         ; omparator A Extended Address Bit 16 Compare Bit
DBGCAX_PAGSEL      equ    5                                         ; Comparator A Page Select Bit
DBGCAX_RWA         equ    6                                         ; Read/Write Comparator A Value Bit
DBGCAX_RWAEN       equ    7                                         ; Read/Write Comparator A Enable Bit
; bit position masks
mDBGCAX_Bit16      equ    00000001b
mDBGCAX_PAGSEL     equ    00100000b
mDBGCAX_RWA        equ    01000000b
mDBGCAX_RWAEN      equ    10000000b


;*** DBGCBX - Debug Comparator B Extension Register; 0x00001819 ***
DBGCBX             equ    $00001819                                ;*** DBGCBX - Debug Comparator B Extension Register; 0x00001819 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCBX_Bit16       equ    0                                         ; omparator B Extended Address Bit 16 Compare Bit
DBGCBX_PAGSEL      equ    5                                         ; Comparator B Page Select Bit
DBGCBX_RWB         equ    6                                         ; Read/Write Comparator B Value Bit
DBGCBX_RWBEN       equ    7                                         ; Read/Write Comparator B Enable Bit
; bit position masks
mDBGCBX_Bit16      equ    00000001b
mDBGCBX_PAGSEL     equ    00100000b
mDBGCBX_RWB        equ    01000000b
mDBGCBX_RWBEN      equ    10000000b


;*** DBGCCX - Debug Comparator C Extension Register; 0x0000181A ***
DBGCCX             equ    $0000181A                                ;*** DBGCCX - Debug Comparator C Extension Register; 0x0000181A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCCX_Bit16       equ    0                                         ; omparator C Extended Address Bit 16 Compare Bit
DBGCCX_PAGSEL      equ    5                                         ; Comparator C Page Select Bit
DBGCCX_RWC         equ    6                                         ; Read/Write Comparator C Value Bit
DBGCCX_RWCEN       equ    7                                         ; Read/Write Comparator C Enable Bit
; bit position masks
mDBGCCX_Bit16      equ    00000001b
mDBGCCX_PAGSEL     equ    00100000b
mDBGCCX_RWC        equ    01000000b
mDBGCCX_RWCEN      equ    10000000b


;*** DBGFX - Debug FIFO Extended Information Register; 0x0000181B ***
DBGFX              equ    $0000181B                                ;*** DBGFX - Debug FIFO Extended Information Register; 0x0000181B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGFX_Bit16        equ    0                                         ; Extended Address Bit 16
DBGFX_PPACC        equ    7                                         ; PPAGE Access Indicator Bit
; bit position masks
mDBGFX_Bit16       equ    00000001b
mDBGFX_PPACC       equ    10000000b


;*** DBGC - Debug Control Register; 0x0000181C ***
DBGC               equ    $0000181C                                ;*** DBGC - Debug Control Register; 0x0000181C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGC_LOOP1         equ    0                                         ; Select LOOP1 Capture Mode
DBGC_BRKEN         equ    4                                         ; Break Enable Bit
DBGC_TAG           equ    5                                         ; Tag or Force Bit
DBGC_ARM           equ    6                                         ; Arm Bit
DBGC_DBGEN         equ    7                                         ; DBG Module Enable Bit
; bit position masks
mDBGC_LOOP1        equ    00000001b
mDBGC_BRKEN        equ    00010000b
mDBGC_TAG          equ    00100000b
mDBGC_ARM          equ    01000000b
mDBGC_DBGEN        equ    10000000b


;*** DBGT - Debug Trigger Register; 0x0000181D ***
DBGT               equ    $0000181D                                ;*** DBGT - Debug Trigger Register; 0x0000181D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGT_TRG0          equ    0                                         ; Trigger Mode Bit 0
DBGT_TRG1          equ    1                                         ; Trigger Mode Bit 1
DBGT_TRG2          equ    2                                         ; Trigger Mode Bit 2
DBGT_TRG3          equ    3                                         ; Trigger Mode Bit 3
DBGT_BEGIN         equ    6                                         ; Begin/End Trigger Bit
DBGT_TRGSEL        equ    7                                         ; Trigger Selection Bit
; bit position masks
mDBGT_TRG0         equ    00000001b
mDBGT_TRG1         equ    00000010b
mDBGT_TRG2         equ    00000100b
mDBGT_TRG3         equ    00001000b
mDBGT_BEGIN        equ    01000000b
mDBGT_TRGSEL       equ    10000000b


;*** DBGS - Debug Status Register; 0x0000181E ***
DBGS               equ    $0000181E                                ;*** DBGS - Debug Status Register; 0x0000181E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGS_ARMF          equ    0                                         ; Arm Flag Bit
DBGS_CF            equ    5                                         ; Trigger C Match Bit
DBGS_BF            equ    6                                         ; Trigger B Match Bit
DBGS_AF            equ    7                                         ; Trigger A Match Bit
; bit position masks
mDBGS_ARMF         equ    00000001b
mDBGS_CF           equ    00100000b
mDBGS_BF           equ    01000000b
mDBGS_AF           equ    10000000b


;*** DBGCNT - Debug Count Status Register; 0x0000181F ***
DBGCNT             equ    $0000181F                                ;*** DBGCNT - Debug Count Status Register; 0x0000181F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
DBGCNT_CNT0        equ    0                                         ; FIFO Valid Count Bits, bit 0
DBGCNT_CNT1        equ    1                                         ; FIFO Valid Count Bits, bit 1
DBGCNT_CNT2        equ    2                                         ; FIFO Valid Count Bits, bit 2
DBGCNT_CNT3        equ    3                                         ; FIFO Valid Count Bits, bit 3
; bit position masks
mDBGCNT_CNT0       equ    00000001b
mDBGCNT_CNT1       equ    00000010b
mDBGCNT_CNT2       equ    00000100b
mDBGCNT_CNT3       equ    00001000b


;*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***
FCDIV              equ    $00001820                                ;*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCDIV_DIV0         equ    0                                         ; Divisor for FLASH Clock Divider, bit 0
FCDIV_DIV1         equ    1                                         ; Divisor for FLASH Clock Divider, bit 1
FCDIV_DIV2         equ    2                                         ; Divisor for FLASH Clock Divider, bit 2
FCDIV_DIV3         equ    3                                         ; Divisor for FLASH Clock Divider, bit 3
FCDIV_DIV4         equ    4                                         ; Divisor for FLASH Clock Divider, bit 4
FCDIV_DIV5         equ    5                                         ; Divisor for FLASH Clock Divider, bit 5
FCDIV_PRDIV8       equ    6                                         ; Prescale (Divide) FLASH Clock by 8
FCDIV_DIVLD        equ    7                                         ; Divisor Loaded Status Flag
; bit position masks
mFCDIV_DIV0        equ    00000001b
mFCDIV_DIV1        equ    00000010b
mFCDIV_DIV2        equ    00000100b
mFCDIV_DIV3        equ    00001000b
mFCDIV_DIV4        equ    00010000b
mFCDIV_DIV5        equ    00100000b
mFCDIV_PRDIV8      equ    01000000b
mFCDIV_DIVLD       equ    10000000b


;*** FOPT - Flash Options Register; 0x00001821 ***
FOPT               equ    $00001821                                ;*** FOPT - Flash Options Register; 0x00001821 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FOPT_SEC0          equ    0                                         ; Flash Security Bit 0
FOPT_SEC1          equ    1                                         ; Flash Security Bit 1
FOPT_FNORED        equ    6                                         ; Vector Redirection Disable
FOPT_KEYEN         equ    7                                         ; Enable Security Key Writing
; bit position masks
mFOPT_SEC0         equ    00000001b
mFOPT_SEC1         equ    00000010b
mFOPT_FNORED       equ    01000000b
mFOPT_KEYEN        equ    10000000b


;*** FCNFG - Flash Configuration Register; 0x00001823 ***
FCNFG              equ    $00001823                                ;*** FCNFG - Flash Configuration Register; 0x00001823 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCNFG_KEYACC       equ    5                                         ; Enable Security Key Writing
; bit position masks
mFCNFG_KEYACC      equ    00100000b


;*** FPROT - Flash Protection Register; 0x00001824 ***
FPROT              equ    $00001824                                ;*** FPROT - Flash Protection Register; 0x00001824 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FPROT_FPDIS        equ    0                                         ; Flash Protection Disable
FPROT_FPS0         equ    1                                         ; Flash Protection Size, bit 0
FPROT_FPS1         equ    2                                         ; Flash Protection Size, bit 1
FPROT_FPS2         equ    3                                         ; Flash Protection Size, bit 2
FPROT_FPS3         equ    4                                         ; Flash Protection Size, bit 3
FPROT_FPS4         equ    5                                         ; Flash Protection Size, bit 4
FPROT_FPS5         equ    6                                         ; Flash Protection Size, bit 5
FPROT_FPS6         equ    7                                         ; Flash Protection Size, bit 6
; bit position masks
mFPROT_FPDIS       equ    00000001b
mFPROT_FPS0        equ    00000010b
mFPROT_FPS1        equ    00000100b
mFPROT_FPS2        equ    00001000b
mFPROT_FPS3        equ    00010000b
mFPROT_FPS4        equ    00100000b
mFPROT_FPS5        equ    01000000b
mFPROT_FPS6        equ    10000000b


;*** FSTAT - Flash Status Register; 0x00001825 ***
FSTAT              equ    $00001825                                ;*** FSTAT - Flash Status Register; 0x00001825 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FSTAT_FBLANK       equ    2                                         ; FLASH Flag Indicating the Erase Verify Operation Status
FSTAT_FACCERR      equ    4                                         ; FLASH Access Error Flag
FSTAT_FPVIOL       equ    5                                         ; FLASH Protection Violation Flag
FSTAT_FCCF         equ    6                                         ; FLASH Command Complete Interrupt Flag
FSTAT_FCBEF        equ    7                                         ; FLASH Command Buffer Empty Flag
; bit position masks
mFSTAT_FBLANK      equ    00000100b
mFSTAT_FACCERR     equ    00010000b
mFSTAT_FPVIOL      equ    00100000b
mFSTAT_FCCF        equ    01000000b
mFSTAT_FCBEF       equ    10000000b


;*** FCMD - Flash Command Register; 0x00001826 ***
FCMD               equ    $00001826                                ;*** FCMD - Flash Command Register; 0x00001826 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
FCMD_FCMD0         equ    0                                         ; Flash Command, bit 0
FCMD_FCMD1         equ    1                                         ; Flash Command, bit 1
FCMD_FCMD2         equ    2                                         ; Flash Command, bit 2
FCMD_FCMD3         equ    3                                         ; Flash Command, bit 3
FCMD_FCMD4         equ    4                                         ; Flash Command, bit 4
FCMD_FCMD5         equ    5                                         ; Flash Command, bit 5
FCMD_FCMD6         equ    6                                         ; Flash Command, bit 6
FCMD_FCMD7         equ    7                                         ; Flash Command, bit 7
; bit position masks
mFCMD_FCMD0        equ    00000001b
mFCMD_FCMD1        equ    00000010b
mFCMD_FCMD2        equ    00000100b
mFCMD_FCMD3        equ    00001000b
mFCMD_FCMD4        equ    00010000b
mFCMD_FCMD5        equ    00100000b
mFCMD_FCMD6        equ    01000000b
mFCMD_FCMD7        equ    10000000b


;*** TODC - TOD Control Register; 0x00001830 ***
TODC               equ    $00001830                                ;*** TODC - TOD Control Register; 0x00001830 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TODC_TODPS0        equ    0                                         ; TOD Prescaler Bits, bit 0
TODC_TODPS1        equ    1                                         ; TOD Prescaler Bits, bit 1
TODC_TODPS2        equ    2                                         ; TOD Prescaler Bits, bit 2
TODC_TODCLKEN      equ    3                                         ; TOD Clock Enable
TODC_TODR          equ    4                                         ; TOD Reset
TODC_TODCLKS0      equ    5                                         ; TOD Clock Source, bit 0
TODC_TODCLKS1      equ    6                                         ; TOD Clock Source, bit 1
TODC_TODEN         equ    7                                         ; Time of Day Enable
; bit position masks
mTODC_TODPS0       equ    00000001b
mTODC_TODPS1       equ    00000010b
mTODC_TODPS2       equ    00000100b
mTODC_TODCLKEN     equ    00001000b
mTODC_TODR         equ    00010000b
mTODC_TODCLKS0     equ    00100000b
mTODC_TODCLKS1     equ    01000000b
mTODC_TODEN        equ    10000000b


;*** TODSC - TOD Status and Control Register; 0x00001831 ***
TODSC              equ    $00001831                                ;*** TODSC - TOD Status and Control Register; 0x00001831 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TODSC_MTCHWC       equ    0                                         ; Match Write Complete
TODSC_MTCHEN       equ    1                                         ; Match Function Enable
TODSC_MTCHIE       equ    2                                         ; Match Interrupt Enable
TODSC_SECIE        equ    3                                         ; Second Interrupt Enable
TODSC_QSECIE       equ    4                                         ; Quarter-Second Interrupt Enable
TODSC_MTCHF        equ    5                                         ; Match Interrupt Flag
TODSC_SECF         equ    6                                         ; Second Interrupt Flag
TODSC_QSECF        equ    7                                         ; Quarter-Second Interrupt Flag
; bit position masks
mTODSC_MTCHWC      equ    00000001b
mTODSC_MTCHEN      equ    00000010b
mTODSC_MTCHIE      equ    00000100b
mTODSC_SECIE       equ    00001000b
mTODSC_QSECIE      equ    00010000b
mTODSC_MTCHF       equ    00100000b
mTODSC_SECF        equ    01000000b
mTODSC_QSECF       equ    10000000b


;*** TODM - TOD Match Register; 0x00001832 ***
TODM               equ    $00001832                                ;*** TODM - TOD Match Register; 0x00001832 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
TODM_MQSEC0        equ    0                                         ; Match Quarter-Second Bits, bit 0
TODM_MQSEC1        equ    1                                         ; Match Quarter-Second Bits, bit 1
TODM_TODM0         equ    2                                         ; TOD Match Value, bit 0
TODM_TODM1         equ    3                                         ; TOD Match Value, bit 1
TODM_TODM2         equ    4                                         ; TOD Match Value, bit 2
TODM_TODM3         equ    5                                         ; TOD Match Value, bit 3
TODM_TODM4         equ    6                                         ; TOD Match Value, bit 4
TODM_TODM5         equ    7                                         ; TOD Match Value, bit 5
; bit position masks
mTODM_MQSEC0       equ    00000001b
mTODM_MQSEC1       equ    00000010b
mTODM_TODM0        equ    00000100b
mTODM_TODM1        equ    00001000b
mTODM_TODM2        equ    00010000b
mTODM_TODM3        equ    00100000b
mTODM_TODM4        equ    01000000b
mTODM_TODM5        equ    10000000b


;*** TODCNT - TOD Counter Register; 0x00001833 ***
TODCNT             equ    $00001833                                ;*** TODCNT - TOD Counter Register; 0x00001833 ***


;*** PTAPE - Port A Pull Enable Register; 0x00001840 ***
PTAPE              equ    $00001840                                ;*** PTAPE - Port A Pull Enable Register; 0x00001840 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTAPE_PTAPE0       equ    0                                         ; Internal Pull Enable for Port A Bit 0
PTAPE_PTAPE1       equ    1                                         ; Internal Pull Enable for Port A Bit 1
PTAPE_PTAPE2       equ    2                                         ; Internal Pull Enable for Port A Bit 2
PTAPE_PTAPE3       equ    3                                         ; Internal Pull Enable for Port A Bit 3
PTAPE_PTAPE4       equ    4                                         ; Internal Pull Enable for Port A Bit 4
PTAPE_PTAPE5       equ    5                                         ; Internal Pull Enable for Port A Bit 5
PTAPE_PTAPE6       equ    6                                         ; Internal Pull Enable for Port A Bit 6
PTAPE_PTAPE7       equ    7                                         ; Internal Pull Enable for Port A Bit 7
; bit position masks
mPTAPE_PTAPE0      equ    00000001b
mPTAPE_PTAPE1      equ    00000010b
mPTAPE_PTAPE2      equ    00000100b
mPTAPE_PTAPE3      equ    00001000b
mPTAPE_PTAPE4      equ    00010000b
mPTAPE_PTAPE5      equ    00100000b
mPTAPE_PTAPE6      equ    01000000b
mPTAPE_PTAPE7      equ    10000000b


;*** PTASE - Port A Slew Rate Enable Register; 0x00001841 ***
PTASE              equ    $00001841                                ;*** PTASE - Port A Slew Rate Enable Register; 0x00001841 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTASE_PTASE0       equ    0                                         ; Output Slew Rate Enable for Port A Bit 0
PTASE_PTASE1       equ    1                                         ; Output Slew Rate Enable for Port A Bit 1
PTASE_PTASE2       equ    2                                         ; Output Slew Rate Enable for Port A Bit 2
PTASE_PTASE3       equ    3                                         ; Output Slew Rate Enable for Port A Bit 3
PTASE_PTASE4       equ    4                                         ; Output Slew Rate Enable for Port A Bit 4
PTASE_PTASE5       equ    5                                         ; Output Slew Rate Enable for Port A Bit 5
PTASE_PTASE6       equ    6                                         ; Output Slew Rate Enable for Port A Bit 6
PTASE_PTASE7       equ    7                                         ; Output Slew Rate Enable for Port A Bit 7
; bit position masks
mPTASE_PTASE0      equ    00000001b
mPTASE_PTASE1      equ    00000010b
mPTASE_PTASE2      equ    00000100b
mPTASE_PTASE3      equ    00001000b
mPTASE_PTASE4      equ    00010000b
mPTASE_PTASE5      equ    00100000b
mPTASE_PTASE6      equ    01000000b
mPTASE_PTASE7      equ    10000000b


;*** PTADS - Port A Drive Strength Selection Register; 0x00001842 ***
PTADS              equ    $00001842                                ;*** PTADS - Port A Drive Strength Selection Register; 0x00001842 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTADS_PTADS0       equ    0                                         ; Output Drive Strength Selection for Port A Bit 0
PTADS_PTADS1       equ    1                                         ; Output Drive Strength Selection for Port A Bit 1
PTADS_PTADS2       equ    2                                         ; Output Drive Strength Selection for Port A Bit 2
PTADS_PTADS3       equ    3                                         ; Output Drive Strength Selection for Port A Bit 3
PTADS_PTADS4       equ    4                                         ; Output Drive Strength Selection for Port A Bit 4
PTADS_PTADS5       equ    5                                         ; Output Drive Strength Selection for Port A Bit 5
PTADS_PTADS6       equ    6                                         ; Output Drive Strength Selection for Port A Bit 6
PTADS_PTADS7       equ    7                                         ; Output Drive Strength Selection for Port A Bit 7
; bit position masks
mPTADS_PTADS0      equ    00000001b
mPTADS_PTADS1      equ    00000010b
mPTADS_PTADS2      equ    00000100b
mPTADS_PTADS3      equ    00001000b
mPTADS_PTADS4      equ    00010000b
mPTADS_PTADS5      equ    00100000b
mPTADS_PTADS6      equ    01000000b
mPTADS_PTADS7      equ    10000000b


;*** PTBPE - Port B Pull Enable Register; 0x00001844 ***
PTBPE              equ    $00001844                                ;*** PTBPE - Port B Pull Enable Register; 0x00001844 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBPE_PTBPE0       equ    0                                         ; Internal Pull Enable for Port B Bit 0
PTBPE_PTBPE1       equ    1                                         ; Internal Pull Enable for Port B Bit 1
PTBPE_PTBPE2       equ    2                                         ; Internal Pull Enable for Port B Bit 2
PTBPE_PTBPE4       equ    4                                         ; Internal Pull Enable for Port B Bit 4
PTBPE_PTBPE5       equ    5                                         ; Internal Pull Enable for Port B Bit 5
PTBPE_PTBPE6       equ    6                                         ; Internal Pull Enable for Port B Bit 6
PTBPE_PTBPE7       equ    7                                         ; Internal Pull Enable for Port B Bit 7
; bit position masks
mPTBPE_PTBPE0      equ    00000001b
mPTBPE_PTBPE1      equ    00000010b
mPTBPE_PTBPE2      equ    00000100b
mPTBPE_PTBPE4      equ    00010000b
mPTBPE_PTBPE5      equ    00100000b
mPTBPE_PTBPE6      equ    01000000b
mPTBPE_PTBPE7      equ    10000000b


;*** PTBSE - Port B Slew Rate Enable Register; 0x00001845 ***
PTBSE              equ    $00001845                                ;*** PTBSE - Port B Slew Rate Enable Register; 0x00001845 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBSE_PTBSE0       equ    0                                         ; Output Slew Rate Enable for Port B Bit 0
PTBSE_PTBSE1       equ    1                                         ; Output Slew Rate Enable for Port B Bit 1
PTBSE_PTBSE2       equ    2                                         ; Output Slew Rate Enable for Port B Bit 2
PTBSE_PTBSE4       equ    4                                         ; Output Slew Rate Enable for Port B Bit 4
PTBSE_PTBSE5       equ    5                                         ; Output Slew Rate Enable for Port B Bit 5
PTBSE_PTBSE6       equ    6                                         ; Output Slew Rate Enable for Port B Bit 6
PTBSE_PTBSE7       equ    7                                         ; Output Slew Rate Enable for Port B Bit 7
; bit position masks
mPTBSE_PTBSE0      equ    00000001b
mPTBSE_PTBSE1      equ    00000010b
mPTBSE_PTBSE2      equ    00000100b
mPTBSE_PTBSE4      equ    00010000b
mPTBSE_PTBSE5      equ    00100000b
mPTBSE_PTBSE6      equ    01000000b
mPTBSE_PTBSE7      equ    10000000b


;*** PTBDS - Port B Drive Strength Selection Register; 0x00001846 ***
PTBDS              equ    $00001846                                ;*** PTBDS - Port B Drive Strength Selection Register; 0x00001846 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTBDS_PTBDS0       equ    0                                         ; Output Drive Strength Selection for Port B Bit 0
PTBDS_PTBDS1       equ    1                                         ; Output Drive Strength Selection for Port B Bit 1
PTBDS_PTBDS2       equ    2                                         ; Output Drive Strength Selection for Port B Bit 2
PTBDS_PTBDS4       equ    4                                         ; Output Drive Strength Selection for Port B Bit 4
PTBDS_PTBDS5       equ    5                                         ; Output Drive Strength Selection for Port B Bit 5
PTBDS_PTBDS6       equ    6                                         ; Output Drive Strength Selection for Port B Bit 6
PTBDS_PTBDS7       equ    7                                         ; Output Drive Strength Selection for Port B Bit 7
; bit position masks
mPTBDS_PTBDS0      equ    00000001b
mPTBDS_PTBDS1      equ    00000010b
mPTBDS_PTBDS2      equ    00000100b
mPTBDS_PTBDS4      equ    00010000b
mPTBDS_PTBDS5      equ    00100000b
mPTBDS_PTBDS6      equ    01000000b
mPTBDS_PTBDS7      equ    10000000b


;*** PTCPE - Port C Pull Enable Register; 0x00001848 ***
PTCPE              equ    $00001848                                ;*** PTCPE - Port C Pull Enable Register; 0x00001848 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCPE_PTCPE0       equ    0                                         ; Internal Pull Enable for Port C Bit 0
PTCPE_PTCPE1       equ    1                                         ; Internal Pull Enable for Port C Bit 1
PTCPE_PTCPE2       equ    2                                         ; Internal Pull Enable for Port C Bit 2
PTCPE_PTCPE3       equ    3                                         ; Internal Pull Enable for Port C Bit 3
PTCPE_PTCPE4       equ    4                                         ; Internal Pull Enable for Port C Bit 4
PTCPE_PTCPE5       equ    5                                         ; Internal Pull Enable for Port C Bit 5
PTCPE_PTCPE6       equ    6                                         ; Internal Pull Enable for Port C Bit 6
PTCPE_PTCPE7       equ    7                                         ; Internal Pull Enable for Port C Bit 7
; bit position masks
mPTCPE_PTCPE0      equ    00000001b
mPTCPE_PTCPE1      equ    00000010b
mPTCPE_PTCPE2      equ    00000100b
mPTCPE_PTCPE3      equ    00001000b
mPTCPE_PTCPE4      equ    00010000b
mPTCPE_PTCPE5      equ    00100000b
mPTCPE_PTCPE6      equ    01000000b
mPTCPE_PTCPE7      equ    10000000b


;*** PTCSE - Port C Slew Rate Enable Register; 0x00001849 ***
PTCSE              equ    $00001849                                ;*** PTCSE - Port C Slew Rate Enable Register; 0x00001849 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCSE_PTCSE0       equ    0                                         ; Output Slew Rate Enable for Port C Bit 0
PTCSE_PTCSE1       equ    1                                         ; Output Slew Rate Enable for Port C Bit 1
PTCSE_PTCSE2       equ    2                                         ; Output Slew Rate Enable for Port C Bit 2
PTCSE_PTCSE3       equ    3                                         ; Output Slew Rate Enable for Port C Bit 3
PTCSE_PTCSE4       equ    4                                         ; Output Slew Rate Enable for Port C Bit 4
PTCSE_PTCSE5       equ    5                                         ; Output Slew Rate Enable for Port C Bit 5
PTCSE_PTCSE6       equ    6                                         ; Output Slew Rate Enable for Port C Bit 6
PTCSE_PTCSE7       equ    7                                         ; Output Slew Rate Enable for Port C Bit 7
; bit position masks
mPTCSE_PTCSE0      equ    00000001b
mPTCSE_PTCSE1      equ    00000010b
mPTCSE_PTCSE2      equ    00000100b
mPTCSE_PTCSE3      equ    00001000b
mPTCSE_PTCSE4      equ    00010000b
mPTCSE_PTCSE5      equ    00100000b
mPTCSE_PTCSE6      equ    01000000b
mPTCSE_PTCSE7      equ    10000000b


;*** PTCDS - Port C Drive Strength Selection Register; 0x0000184A ***
PTCDS              equ    $0000184A                                ;*** PTCDS - Port C Drive Strength Selection Register; 0x0000184A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTCDS_PTCDS0       equ    0                                         ; Output Drive Strength Selection for Port C Bit 0
PTCDS_PTCDS1       equ    1                                         ; Output Drive Strength Selection for Port C Bit 1
PTCDS_PTCDS2       equ    2                                         ; Output Drive Strength Selection for Port C Bit 2
PTCDS_PTCDS3       equ    3                                         ; Output Drive Strength Selection for Port C Bit 3
PTCDS_PTCDS4       equ    4                                         ; Output Drive Strength Selection for Port C Bit 4
PTCDS_PTCDS5       equ    5                                         ; Output Drive Strength Selection for Port C Bit 5
PTCDS_PTCDS6       equ    6                                         ; Output Drive Strength Selection for Port C Bit 6
PTCDS_PTCDS7       equ    7                                         ; Output Drive Strength Selection for Port C Bit 7
; bit position masks
mPTCDS_PTCDS0      equ    00000001b
mPTCDS_PTCDS1      equ    00000010b
mPTCDS_PTCDS2      equ    00000100b
mPTCDS_PTCDS3      equ    00001000b
mPTCDS_PTCDS4      equ    00010000b
mPTCDS_PTCDS5      equ    00100000b
mPTCDS_PTCDS6      equ    01000000b
mPTCDS_PTCDS7      equ    10000000b


;*** PTDPE - Port D Pull Enable Register; 0x0000184C ***
PTDPE              equ    $0000184C                                ;*** PTDPE - Port D Pull Enable Register; 0x0000184C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDPE_PTDPE0       equ    0                                         ; Internal Pull Enable for Port D Bit 0
PTDPE_PTDPE1       equ    1                                         ; Internal Pull Enable for Port D Bit 1
PTDPE_PTDPE2       equ    2                                         ; Internal Pull Enable for Port D Bit 2
PTDPE_PTDPE3       equ    3                                         ; Internal Pull Enable for Port D Bit 3
PTDPE_PTDPE4       equ    4                                         ; Internal Pull Enable for Port D Bit 4
PTDPE_PTDPE5       equ    5                                         ; Internal Pull Enable for Port D Bit 5
PTDPE_PTDPE6       equ    6                                         ; Internal Pull Enable for Port D Bit 6
PTDPE_PTDPE7       equ    7                                         ; Internal Pull Enable for Port D Bit 7
; bit position masks
mPTDPE_PTDPE0      equ    00000001b
mPTDPE_PTDPE1      equ    00000010b
mPTDPE_PTDPE2      equ    00000100b
mPTDPE_PTDPE3      equ    00001000b
mPTDPE_PTDPE4      equ    00010000b
mPTDPE_PTDPE5      equ    00100000b
mPTDPE_PTDPE6      equ    01000000b
mPTDPE_PTDPE7      equ    10000000b


;*** PTDSE - Port D Slew Rate Enable Register; 0x0000184D ***
PTDSE              equ    $0000184D                                ;*** PTDSE - Port D Slew Rate Enable Register; 0x0000184D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDSE_PTDSE0       equ    0                                         ; Output Slew Rate Enable for Port D Bit 0
PTDSE_PTDSE1       equ    1                                         ; Output Slew Rate Enable for Port D Bit 1
PTDSE_PTDSE2       equ    2                                         ; Output Slew Rate Enable for Port D Bit 2
PTDSE_PTDSE3       equ    3                                         ; Output Slew Rate Enable for Port D Bit 3
PTDSE_PTDSE4       equ    4                                         ; Output Slew Rate Enable for Port D Bit 4
PTDSE_PTDSE5       equ    5                                         ; Output Slew Rate Enable for Port D Bit 5
PTDSE_PTDSE6       equ    6                                         ; Output Slew Rate Enable for Port D Bit 6
PTDSE_PTDSE7       equ    7                                         ; Output Slew Rate Enable for Port D Bit 7
; bit position masks
mPTDSE_PTDSE0      equ    00000001b
mPTDSE_PTDSE1      equ    00000010b
mPTDSE_PTDSE2      equ    00000100b
mPTDSE_PTDSE3      equ    00001000b
mPTDSE_PTDSE4      equ    00010000b
mPTDSE_PTDSE5      equ    00100000b
mPTDSE_PTDSE6      equ    01000000b
mPTDSE_PTDSE7      equ    10000000b


;*** PTDDS - Port D Drive Strength Selection Register; 0x0000184E ***
PTDDS              equ    $0000184E                                ;*** PTDDS - Port D Drive Strength Selection Register; 0x0000184E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTDDS_PTDDS0       equ    0                                         ; Output Drive Strength Selection for Port D Bit 0
PTDDS_PTDDS1       equ    1                                         ; Output Drive Strength Selection for Port D Bit 1
PTDDS_PTDDS2       equ    2                                         ; Output Drive Strength Selection for Port D Bit 2
PTDDS_PTDDS3       equ    3                                         ; Output Drive Strength Selection for Port D Bit 3
PTDDS_PTDDS4       equ    4                                         ; Output Drive Strength Selection for Port D Bit 4
PTDDS_PTDDS5       equ    5                                         ; Output Drive Strength Selection for Port D Bit 5
PTDDS_PTDDS6       equ    6                                         ; Output Drive Strength Selection for Port D Bit 6
PTDDS_PTDDS7       equ    7                                         ; Output Drive Strength Selection for Port D Bit 7
; bit position masks
mPTDDS_PTDDS0      equ    00000001b
mPTDDS_PTDDS1      equ    00000010b
mPTDDS_PTDDS2      equ    00000100b
mPTDDS_PTDDS3      equ    00001000b
mPTDDS_PTDDS4      equ    00010000b
mPTDDS_PTDDS5      equ    00100000b
mPTDDS_PTDDS6      equ    01000000b
mPTDDS_PTDDS7      equ    10000000b


;*** PTEPE - Port E Pull Enable Register; 0x00001850 ***
PTEPE              equ    $00001850                                ;*** PTEPE - Port E Pull Enable Register; 0x00001850 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEPE_PTEPE0       equ    0                                         ; Internal Pull Enable for Port E Bit 0
PTEPE_PTEPE1       equ    1                                         ; Internal Pull Enable for Port E Bit 1
PTEPE_PTEPE2       equ    2                                         ; Internal Pull Enable for Port E Bit 2
PTEPE_PTEPE3       equ    3                                         ; Internal Pull Enable for Port E Bit 3
PTEPE_PTEPE4       equ    4                                         ; Internal Pull Enable for Port E Bit 4
PTEPE_PTEPE5       equ    5                                         ; Internal Pull Enable for Port E Bit 5
PTEPE_PTEPE6       equ    6                                         ; Internal Pull Enable for Port E Bit 6
PTEPE_PTEPE7       equ    7                                         ; Internal Pull Enable for Port E Bit 7
; bit position masks
mPTEPE_PTEPE0      equ    00000001b
mPTEPE_PTEPE1      equ    00000010b
mPTEPE_PTEPE2      equ    00000100b
mPTEPE_PTEPE3      equ    00001000b
mPTEPE_PTEPE4      equ    00010000b
mPTEPE_PTEPE5      equ    00100000b
mPTEPE_PTEPE6      equ    01000000b
mPTEPE_PTEPE7      equ    10000000b


;*** PTESE - Port E Slew Rate Enable Register; 0x00001851 ***
PTESE              equ    $00001851                                ;*** PTESE - Port E Slew Rate Enable Register; 0x00001851 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTESE_PTESE0       equ    0                                         ; Output Slew Rate Enable for Port E Bit 0
PTESE_PTESE1       equ    1                                         ; Output Slew Rate Enable for Port E Bit 1
PTESE_PTESE2       equ    2                                         ; Output Slew Rate Enable for Port E Bit 2
PTESE_PTESE3       equ    3                                         ; Output Slew Rate Enable for Port E Bit 3
PTESE_PTESE4       equ    4                                         ; Output Slew Rate Enable for Port E Bit 4
PTESE_PTESE5       equ    5                                         ; Output Slew Rate Enable for Port E Bit 5
PTESE_PTESE6       equ    6                                         ; Output Slew Rate Enable for Port E Bit 6
PTESE_PTESE7       equ    7                                         ; Output Slew Rate Enable for Port E Bit 7
; bit position masks
mPTESE_PTESE0      equ    00000001b
mPTESE_PTESE1      equ    00000010b
mPTESE_PTESE2      equ    00000100b
mPTESE_PTESE3      equ    00001000b
mPTESE_PTESE4      equ    00010000b
mPTESE_PTESE5      equ    00100000b
mPTESE_PTESE6      equ    01000000b
mPTESE_PTESE7      equ    10000000b


;*** PTEDS - Port E Drive Strength Selection Register; 0x00001852 ***
PTEDS              equ    $00001852                                ;*** PTEDS - Port E Drive Strength Selection Register; 0x00001852 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
PTEDS_PTEDS0       equ    0                                         ; Output Drive Strength Selection for Port E Bit 0
PTEDS_PTEDS1       equ    1                                         ; Output Drive Strength Selection for Port E Bit 1
PTEDS_PTEDS2       equ    2                                         ; Output Drive Strength Selection for Port E Bit 2
PTEDS_PTEDS3       equ    3                                         ; Output Drive Strength Selection for Port E Bit 3
PTEDS_PTEDS4       equ    4                                         ; Output Drive Strength Selection for Port E Bit 4
PTEDS_PTEDS5       equ    5                                         ; Output Drive Strength Selection for Port E Bit 5
PTEDS_PTEDS6       equ    6                                         ; Output Drive Strength Selection for Port E Bit 6
PTEDS_PTEDS7       equ    7                                         ; Output Drive Strength Selection for Port E Bit 7
; bit position masks
mPTEDS_PTEDS0      equ    00000001b
mPTEDS_PTEDS1      equ    00000010b
mPTEDS_PTEDS2      equ    00000100b
mPTEDS_PTEDS3      equ    00001000b
mPTEDS_PTEDS4      equ    00010000b
mPTEDS_PTEDS5      equ    00100000b
mPTEDS_PTEDS6      equ    01000000b
mPTEDS_PTEDS7      equ    10000000b


;*** SCI2BD - SCI2 Baud Rate Register; 0x00001858 ***
SCI2BD             equ    $00001858                                ;*** SCI2BD - SCI2 Baud Rate Register; 0x00001858 ***


;*** SCI2BDH - SCI2 Baud Rate Register High; 0x00001858 ***
SCI2BDH            equ    $00001858                                ;*** SCI2BDH - SCI2 Baud Rate Register High; 0x00001858 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDH_SBR8       equ    0                                         ; Baud Rate Modulo Divisor Bit 8
SCI2BDH_SBR9       equ    1                                         ; Baud Rate Modulo Divisor Bit 9
SCI2BDH_SBR10      equ    2                                         ; Baud Rate Modulo Divisor Bit 10
SCI2BDH_SBR11      equ    3                                         ; Baud Rate Modulo Divisor Bit 11
SCI2BDH_SBR12      equ    4                                         ; Baud Rate Modulo Divisor Bit 12
SCI2BDH_RXEDGIE    equ    6                                         ; RxD Input Active Edge Interrupt Enable (for RXEDGIF)
SCI2BDH_LBKDIE     equ    7                                         ; LIN Break Detect Interrupt Enable (for LBKDIF)
; bit position masks
mSCI2BDH_SBR8      equ    00000001b
mSCI2BDH_SBR9      equ    00000010b
mSCI2BDH_SBR10     equ    00000100b
mSCI2BDH_SBR11     equ    00001000b
mSCI2BDH_SBR12     equ    00010000b
mSCI2BDH_RXEDGIE   equ    01000000b
mSCI2BDH_LBKDIE    equ    10000000b


;*** SCI2BDL - SCI2 Baud Rate Register Low; 0x00001859 ***
SCI2BDL            equ    $00001859                                ;*** SCI2BDL - SCI2 Baud Rate Register Low; 0x00001859 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2BDL_SBR0       equ    0                                         ; Baud Rate Modulo Divisor Bit 0
SCI2BDL_SBR1       equ    1                                         ; Baud Rate Modulo Divisor Bit 1
SCI2BDL_SBR2       equ    2                                         ; Baud Rate Modulo Divisor Bit 2
SCI2BDL_SBR3       equ    3                                         ; Baud Rate Modulo Divisor Bit 3
SCI2BDL_SBR4       equ    4                                         ; Baud Rate Modulo Divisor Bit 4
SCI2BDL_SBR5       equ    5                                         ; Baud Rate Modulo Divisor Bit 5
SCI2BDL_SBR6       equ    6                                         ; Baud Rate Modulo Divisor Bit 6
SCI2BDL_SBR7       equ    7                                         ; Baud Rate Modulo Divisor Bit 7
; bit position masks
mSCI2BDL_SBR0      equ    00000001b
mSCI2BDL_SBR1      equ    00000010b
mSCI2BDL_SBR2      equ    00000100b
mSCI2BDL_SBR3      equ    00001000b
mSCI2BDL_SBR4      equ    00010000b
mSCI2BDL_SBR5      equ    00100000b
mSCI2BDL_SBR6      equ    01000000b
mSCI2BDL_SBR7      equ    10000000b


;*** SCI2C1 - SCI2 Control Register 1; 0x0000185A ***
SCI2C1             equ    $0000185A                                ;*** SCI2C1 - SCI2 Control Register 1; 0x0000185A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C1_PT          equ    0                                         ; Parity Type
SCI2C1_PE          equ    1                                         ; Parity Enable
SCI2C1_ILT         equ    2                                         ; Idle Line Type Select
SCI2C1_WAKE        equ    3                                         ; Receiver Wakeup Method Select
SCI2C1_M           equ    4                                         ; 9-Bit or 8-Bit Mode Select
SCI2C1_RSRC        equ    5                                         ; Receiver Source Select
SCI2C1_SCISWAI     equ    6                                         ; SCI Stops in Wait Mode
SCI2C1_LOOPS       equ    7                                         ; Loop Mode Select
; bit position masks
mSCI2C1_PT         equ    00000001b
mSCI2C1_PE         equ    00000010b
mSCI2C1_ILT        equ    00000100b
mSCI2C1_WAKE       equ    00001000b
mSCI2C1_M          equ    00010000b
mSCI2C1_RSRC       equ    00100000b
mSCI2C1_SCISWAI    equ    01000000b
mSCI2C1_LOOPS      equ    10000000b


;*** SCI2C2 - SCI2 Control Register 2; 0x0000185B ***
SCI2C2             equ    $0000185B                                ;*** SCI2C2 - SCI2 Control Register 2; 0x0000185B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C2_SBK         equ    0                                         ; Send Break
SCI2C2_RWU         equ    1                                         ; Receiver Wakeup Control
SCI2C2_RE          equ    2                                         ; Receiver Enable
SCI2C2_TE          equ    3                                         ; Transmitter Enable
SCI2C2_ILIE        equ    4                                         ; Idle Line Interrupt Enable (for IDLE)
SCI2C2_RIE         equ    5                                         ; Receiver Interrupt Enable (for RDRF)
SCI2C2_TCIE        equ    6                                         ; Transmission Complete Interrupt Enable (for TC)
SCI2C2_TIE         equ    7                                         ; Transmit Interrupt Enable (for TDRE)
; bit position masks
mSCI2C2_SBK        equ    00000001b
mSCI2C2_RWU        equ    00000010b
mSCI2C2_RE         equ    00000100b
mSCI2C2_TE         equ    00001000b
mSCI2C2_ILIE       equ    00010000b
mSCI2C2_RIE        equ    00100000b
mSCI2C2_TCIE       equ    01000000b
mSCI2C2_TIE        equ    10000000b


;*** SCI2S1 - SCI2 Status Register 1; 0x0000185C ***
SCI2S1             equ    $0000185C                                ;*** SCI2S1 - SCI2 Status Register 1; 0x0000185C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S1_PF          equ    0                                         ; Parity Error Flag
SCI2S1_FE          equ    1                                         ; Framing Error Flag
SCI2S1_NF          equ    2                                         ; Noise Flag
SCI2S1_OR          equ    3                                         ; Receiver Overrun Flag
SCI2S1_IDLE        equ    4                                         ; Idle Line Flag
SCI2S1_RDRF        equ    5                                         ; Receive Data Register Full Flag
SCI2S1_TC          equ    6                                         ; Transmission Complete Flag
SCI2S1_TDRE        equ    7                                         ; Transmit Data Register Empty Flag
; bit position masks
mSCI2S1_PF         equ    00000001b
mSCI2S1_FE         equ    00000010b
mSCI2S1_NF         equ    00000100b
mSCI2S1_OR         equ    00001000b
mSCI2S1_IDLE       equ    00010000b
mSCI2S1_RDRF       equ    00100000b
mSCI2S1_TC         equ    01000000b
mSCI2S1_TDRE       equ    10000000b


;*** SCI2S2 - SCI2 Status Register 2; 0x0000185D ***
SCI2S2             equ    $0000185D                                ;*** SCI2S2 - SCI2 Status Register 2; 0x0000185D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2S2_RAF         equ    0                                         ; Receiver Active Flag
SCI2S2_LBKDE       equ    1                                         ; LIN Break Detection Enable
SCI2S2_BRK13       equ    2                                         ; Break Character Generation Length
SCI2S2_RWUID       equ    3                                         ; Receive Wake Up Idle Detect
SCI2S2_RXINV       equ    4                                         ; Receive Data Inversion
SCI2S2_RXEDGIF     equ    6                                         ; RxD Pin Active Edge Interrupt Flag
SCI2S2_LBKDIF      equ    7                                         ; LIN Break Detect Interrupt Flag
; bit position masks
mSCI2S2_RAF        equ    00000001b
mSCI2S2_LBKDE      equ    00000010b
mSCI2S2_BRK13      equ    00000100b
mSCI2S2_RWUID      equ    00001000b
mSCI2S2_RXINV      equ    00010000b
mSCI2S2_RXEDGIF    equ    01000000b
mSCI2S2_LBKDIF     equ    10000000b


;*** SCI2C3 - SCI2 Control Register 3; 0x0000185E ***
SCI2C3             equ    $0000185E                                ;*** SCI2C3 - SCI2 Control Register 3; 0x0000185E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2C3_PEIE        equ    0                                         ; Parity Error Interrupt Enable
SCI2C3_FEIE        equ    1                                         ; Framing Error Interrupt Enable
SCI2C3_NEIE        equ    2                                         ; Noise Error Interrupt Enable
SCI2C3_ORIE        equ    3                                         ; Overrun Interrupt Enable
SCI2C3_TXINV       equ    4                                         ; Transmit Data Inversion
SCI2C3_TXDIR       equ    5                                         ; TxD Pin Direction in Single-Wire Mode
SCI2C3_T8          equ    6                                         ; Ninth Data Bit for Transmitter
SCI2C3_R8          equ    7                                         ; Ninth Data Bit for Receiver
; bit position masks
mSCI2C3_PEIE       equ    00000001b
mSCI2C3_FEIE       equ    00000010b
mSCI2C3_NEIE       equ    00000100b
mSCI2C3_ORIE       equ    00001000b
mSCI2C3_TXINV      equ    00010000b
mSCI2C3_TXDIR      equ    00100000b
mSCI2C3_T8         equ    01000000b
mSCI2C3_R8         equ    10000000b


;*** SCI2D - SCI2 Data Register; 0x0000185F ***
SCI2D              equ    $0000185F                                ;*** SCI2D - SCI2 Data Register; 0x0000185F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
SCI2D_R0_T0        equ    0                                         ; Receive/Transmit Data Bit 0
SCI2D_R1_T1        equ    1                                         ; Receive/Transmit Data Bit 1
SCI2D_R2_T2        equ    2                                         ; Receive/Transmit Data Bit 2
SCI2D_R3_T3        equ    3                                         ; Receive/Transmit Data Bit 3
SCI2D_R4_T4        equ    4                                         ; Receive/Transmit Data Bit 4
SCI2D_R5_T5        equ    5                                         ; Receive/Transmit Data Bit 5
SCI2D_R6_T6        equ    6                                         ; Receive/Transmit Data Bit 6
SCI2D_R7_T7        equ    7                                         ; Receive/Transmit Data Bit 7
; bit position masks
mSCI2D_R0_T0       equ    00000001b
mSCI2D_R1_T1       equ    00000010b
mSCI2D_R2_T2       equ    00000100b
mSCI2D_R3_T3       equ    00001000b
mSCI2D_R4_T4       equ    00010000b
mSCI2D_R5_T5       equ    00100000b
mSCI2D_R6_T6       equ    01000000b
mSCI2D_R7_T7       equ    10000000b


;*** IICA - IIC Address Register; 0x00001860 ***
IICA               equ    $00001860                                ;*** IICA - IIC Address Register; 0x00001860 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICA_AD1           equ    1                                         ; Slave Address Bit 1
IICA_AD2           equ    2                                         ; Slave Address Bit 2
IICA_AD3           equ    3                                         ; Slave Address Bit 3
IICA_AD4           equ    4                                         ; Slave Address Bit 4
IICA_AD5           equ    5                                         ; Slave Address Bit 5
IICA_AD6           equ    6                                         ; Slave Address Bit 6
IICA_AD7           equ    7                                         ; Slave Address Bit 7
; bit position masks
mIICA_AD1          equ    00000010b
mIICA_AD2          equ    00000100b
mIICA_AD3          equ    00001000b
mIICA_AD4          equ    00010000b
mIICA_AD5          equ    00100000b
mIICA_AD6          equ    01000000b
mIICA_AD7          equ    10000000b


;*** IICF - IIC Frequency Divider Register; 0x00001861 ***
IICF               equ    $00001861                                ;*** IICF - IIC Frequency Divider Register; 0x00001861 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICF_ICR0          equ    0                                         ; IIC Clock Rate Bit 0
IICF_ICR1          equ    1                                         ; IIC Clock Rate Bit 1
IICF_ICR2          equ    2                                         ; IIC Clock Rate Bit 2
IICF_ICR3          equ    3                                         ; IIC Clock Rate Bit 3
IICF_ICR4          equ    4                                         ; IIC Clock Rate Bit 4
IICF_ICR5          equ    5                                         ; IIC Clock Rate Bit 5
IICF_MULT0         equ    6                                         ; Multiplier Factor Bit 0
IICF_MULT1         equ    7                                         ; Multiplier Factor Bit 1
; bit position masks
mIICF_ICR0         equ    00000001b
mIICF_ICR1         equ    00000010b
mIICF_ICR2         equ    00000100b
mIICF_ICR3         equ    00001000b
mIICF_ICR4         equ    00010000b
mIICF_ICR5         equ    00100000b
mIICF_MULT0        equ    01000000b
mIICF_MULT1        equ    10000000b


;*** IICC1 - IIC Control Register 1; 0x00001862 ***
IICC1              equ    $00001862                                ;*** IICC1 - IIC Control Register 1; 0x00001862 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC1_RSTA         equ    2                                         ; Repeat START
IICC1_TXAK         equ    3                                         ; Transmit Acknowledge Enable
IICC1_TX           equ    4                                         ; Transmit Mode Select
IICC1_MST          equ    5                                         ; Master Mode Select
IICC1_IICIE        equ    6                                         ; IIC Interrupt Enable
IICC1_IICEN        equ    7                                         ; IIC Enable
; bit position masks
mIICC1_RSTA        equ    00000100b
mIICC1_TXAK        equ    00001000b
mIICC1_TX          equ    00010000b
mIICC1_MST         equ    00100000b
mIICC1_IICIE       equ    01000000b
mIICC1_IICEN       equ    10000000b


;*** IICC - IIC Control Register; 0x00001862 ***
IICC               equ    $00001862                                ;*** IICC - IIC Control Register; 0x00001862 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC_RSTA          equ    2                                         ; Repeat START
IICC_TXAK          equ    3                                         ; Transmit Acknowledge Enable
IICC_TX            equ    4                                         ; Transmit Mode Select
IICC_MST           equ    5                                         ; Master Mode Select
IICC_IICIE         equ    6                                         ; IIC Interrupt Enable
IICC_IICEN         equ    7                                         ; IIC Enable
; bit position masks
mIICC_RSTA         equ    00000100b
mIICC_TXAK         equ    00001000b
mIICC_TX           equ    00010000b
mIICC_MST          equ    00100000b
mIICC_IICIE        equ    01000000b
mIICC_IICEN        equ    10000000b


;*** IICS - IIC Status Register; 0x00001863 ***
IICS               equ    $00001863                                ;*** IICS - IIC Status Register; 0x00001863 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICS_RXAK          equ    0                                         ; Receive Acknowledge
IICS_IICIF         equ    1                                         ; IIC Interrupt Flag
IICS_SRW           equ    2                                         ; Slave Read/Write
IICS_ARBL          equ    4                                         ; Arbitration Lost
IICS_BUSY          equ    5                                         ; Bus Busy
IICS_IAAS          equ    6                                         ; Addressed as a Slave
IICS_TCF           equ    7                                         ; Transfer Complete Flag
; bit position masks
mIICS_RXAK         equ    00000001b
mIICS_IICIF        equ    00000010b
mIICS_SRW          equ    00000100b
mIICS_ARBL         equ    00010000b
mIICS_BUSY         equ    00100000b
mIICS_IAAS         equ    01000000b
mIICS_TCF          equ    10000000b


;*** IICD - IIC Data I/O Register; 0x00001864 ***
IICD               equ    $00001864                                ;*** IICD - IIC Data I/O Register; 0x00001864 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICD_DATA0         equ    0                                         ; IIC Data Bit 0
IICD_DATA1         equ    1                                         ; IIC Data Bit 1
IICD_DATA2         equ    2                                         ; IIC Data Bit 2
IICD_DATA3         equ    3                                         ; IIC Data Bit 3
IICD_DATA4         equ    4                                         ; IIC Data Bit 4
IICD_DATA5         equ    5                                         ; IIC Data Bit 5
IICD_DATA6         equ    6                                         ; IIC Data Bit 6
IICD_DATA7         equ    7                                         ; IIC Data Bit 7
; bit position masks
mIICD_DATA0        equ    00000001b
mIICD_DATA1        equ    00000010b
mIICD_DATA2        equ    00000100b
mIICD_DATA3        equ    00001000b
mIICD_DATA4        equ    00010000b
mIICD_DATA5        equ    00100000b
mIICD_DATA6        equ    01000000b
mIICD_DATA7        equ    10000000b


;*** IICC2 - IIC Control Register 2; 0x00001865 ***
IICC2              equ    $00001865                                ;*** IICC2 - IIC Control Register 2; 0x00001865 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
IICC2_AD8          equ    0                                         ; Slave Address Bit 8
IICC2_AD9          equ    1                                         ; Slave Address Bit 9
IICC2_AD10         equ    2                                         ; Slave Address Bit 10
IICC2_ADEXT        equ    6                                         ; Address Extension
IICC2_GCAEN        equ    7                                         ; General Call Address Enable
; bit position masks
mIICC2_AD8         equ    00000001b
mIICC2_AD9         equ    00000010b
mIICC2_AD10        equ    00000100b
mIICC2_ADEXT       equ    01000000b
mIICC2_GCAEN       equ    10000000b


;*** ADCCV1 - Compare Value 1 Register; 0x00001880 ***
ADCCV1             equ    $00001880                                ;*** ADCCV1 - Compare Value 1 Register; 0x00001880 ***


;*** ADCCV1H - Compare Value 1 High Register; 0x00001880 ***
ADCCV1H            equ    $00001880                                ;*** ADCCV1H - Compare Value 1 High Register; 0x00001880 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV1H_CV18       equ    0                                         ; Compare Function Value 8
ADCCV1H_CV19       equ    1                                         ; Compare Function Value 9
ADCCV1H_CV110      equ    2                                         ; Compare Function Value 10
ADCCV1H_CV111      equ    3                                         ; Compare Function Value 11
ADCCV1H_CV112      equ    4                                         ; Compare Function Value 12
ADCCV1H_CV113      equ    5                                         ; Compare Function Value 13
ADCCV1H_CV114      equ    6                                         ; Compare Function Value 14
ADCCV1H_CV115      equ    7                                         ; Compare Function Value 15
; bit position masks
mADCCV1H_CV18      equ    00000001b
mADCCV1H_CV19      equ    00000010b
mADCCV1H_CV110     equ    00000100b
mADCCV1H_CV111     equ    00001000b
mADCCV1H_CV112     equ    00010000b
mADCCV1H_CV113     equ    00100000b
mADCCV1H_CV114     equ    01000000b
mADCCV1H_CV115     equ    10000000b


;*** ADCCV1L - Compare Value 1 Low Register; 0x00001881 ***
ADCCV1L            equ    $00001881                                ;*** ADCCV1L - Compare Value 1 Low Register; 0x00001881 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV1L_CV10       equ    0                                         ; Compare Function Value 0
ADCCV1L_CV11       equ    1                                         ; Compare Function Value 1
ADCCV1L_CV12       equ    2                                         ; Compare Function Value 2
ADCCV1L_CV13       equ    3                                         ; Compare Function Value 3
ADCCV1L_CV14       equ    4                                         ; Compare Function Value 4
ADCCV1L_CV15       equ    5                                         ; Compare Function Value 5
ADCCV1L_CV16       equ    6                                         ; Compare Function Value 6
ADCCV1L_CV17       equ    7                                         ; Compare Function Value 7
; bit position masks
mADCCV1L_CV10      equ    00000001b
mADCCV1L_CV11      equ    00000010b
mADCCV1L_CV12      equ    00000100b
mADCCV1L_CV13      equ    00001000b
mADCCV1L_CV14      equ    00010000b
mADCCV1L_CV15      equ    00100000b
mADCCV1L_CV16      equ    01000000b
mADCCV1L_CV17      equ    10000000b


;*** ADCCV2 - Compare Value 2 Register; 0x00001882 ***
ADCCV2             equ    $00001882                                ;*** ADCCV2 - Compare Value 2 Register; 0x00001882 ***


;*** ADCCV2H - Compare Value 2 High Register; 0x00001882 ***
ADCCV2H            equ    $00001882                                ;*** ADCCV2H - Compare Value 2 High Register; 0x00001882 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV2H_CV28       equ    0                                         ; Compare Function Value 8
ADCCV2H_CV29       equ    1                                         ; Compare Function Value 9
ADCCV2H_CV210      equ    2                                         ; Compare Function Value 10
ADCCV2H_CV211      equ    3                                         ; Compare Function Value 11
ADCCV2H_CV212      equ    4                                         ; Compare Function Value 12
ADCCV2H_CV213      equ    5                                         ; Compare Function Value 13
ADCCV2H_CV214      equ    6                                         ; Compare Function Value 14
ADCCV2H_CV215      equ    7                                         ; Compare Function Value 15
; bit position masks
mADCCV2H_CV28      equ    00000001b
mADCCV2H_CV29      equ    00000010b
mADCCV2H_CV210     equ    00000100b
mADCCV2H_CV211     equ    00001000b
mADCCV2H_CV212     equ    00010000b
mADCCV2H_CV213     equ    00100000b
mADCCV2H_CV214     equ    01000000b
mADCCV2H_CV215     equ    10000000b


;*** ADCCV2L - Compare Value 2 Low Register; 0x00001883 ***
ADCCV2L            equ    $00001883                                ;*** ADCCV2L - Compare Value 2 Low Register; 0x00001883 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCV2L_CV20       equ    0                                         ; Compare Function Value 0
ADCCV2L_CV21       equ    1                                         ; Compare Function Value 1
ADCCV2L_CV22       equ    2                                         ; Compare Function Value 2
ADCCV2L_CV23       equ    3                                         ; Compare Function Value 3
ADCCV2L_CV24       equ    4                                         ; Compare Function Value 4
ADCCV2L_CV25       equ    5                                         ; Compare Function Value 5
ADCCV2L_CV26       equ    6                                         ; Compare Function Value 6
ADCCV2L_CV27       equ    7                                         ; Compare Function Value 7
; bit position masks
mADCCV2L_CV20      equ    00000001b
mADCCV2L_CV21      equ    00000010b
mADCCV2L_CV22      equ    00000100b
mADCCV2L_CV23      equ    00001000b
mADCCV2L_CV24      equ    00010000b
mADCCV2L_CV25      equ    00100000b
mADCCV2L_CV26      equ    01000000b
mADCCV2L_CV27      equ    10000000b


;*** ADCSC2 - Status and Control Register 2; 0x00001884 ***
ADCSC2             equ    $00001884                                ;*** ADCSC2 - Status and Control Register 2; 0x00001884 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC2_REFSEL0     equ    0                                         ; Voltage Reference Selection, bit 0
ADCSC2_REFSEL1     equ    1                                         ; Voltage Reference Selection, bit 1
ADCSC2_ACREN       equ    3                                         ; Compare Function Range Enable
ADCSC2_ACFGT       equ    4                                         ; Compare Function Greater Than Enable
ADCSC2_ACFE        equ    5                                         ; Compare Function Enable - ACFE is used to enable the compare function
ADCSC2_ADTRG       equ    6                                         ; Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion
ADCSC2_ADACT       equ    7                                         ; Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted
; bit position masks
mADCSC2_REFSEL0    equ    00000001b
mADCSC2_REFSEL1    equ    00000010b
mADCSC2_ACREN      equ    00001000b
mADCSC2_ACFGT      equ    00010000b
mADCSC2_ACFE       equ    00100000b
mADCSC2_ADTRG      equ    01000000b
mADCSC2_ADACT      equ    10000000b


;*** ADCSC3 - Status and Control Register 3; 0x00001885 ***
ADCSC3             equ    $00001885                                ;*** ADCSC3 - Status and Control Register 3; 0x00001885 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCSC3_AVGS0       equ    0                                         ; Hardware Average select, bit 0
ADCSC3_AVGS1       equ    1                                         ; Hardware Average select, bit 1
ADCSC3_AVGE        equ    2                                         ; Hardware average enable - AVGE enables the hardware average function of the ADC
ADCSC3_ADCO        equ    3                                         ; Continuous Conversion Enable - ADCO enables continuous conversions
ADCSC3_CALF        equ    6                                         ; Calibration Failed Flag - CALF displays the result of the calibration sequence
ADCSC3_CAL         equ    7                                         ; Calibration - CAL begins the calibration sequence when set
; bit position masks
mADCSC3_AVGS0      equ    00000001b
mADCSC3_AVGS1      equ    00000010b
mADCSC3_AVGE       equ    00000100b
mADCSC3_ADCO       equ    00001000b
mADCSC3_CALF       equ    01000000b
mADCSC3_CAL        equ    10000000b


;*** ADCOFS - Offset Correction Register; 0x00001886 ***
ADCOFS             equ    $00001886                                ;*** ADCOFS - Offset Correction Register; 0x00001886 ***


;*** ADCOFSH - Offset Correction High Register; 0x00001886 ***
ADCOFSH            equ    $00001886                                ;*** ADCOFSH - Offset Correction High Register; 0x00001886 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCOFSH_OFS8       equ    0                                         ; Offset error correction value bit 8
ADCOFSH_OFS9       equ    1                                         ; Offset error correction value bit 9
ADCOFSH_OFS10      equ    2                                         ; Offset error correction value bit 10
ADCOFSH_OFS11      equ    3                                         ; Offset error correction value bit 11
ADCOFSH_OFS12      equ    4                                         ; Offset error correction value bit 12
ADCOFSH_OFS13      equ    5                                         ; Offset error correction value bit 13
ADCOFSH_OFS14      equ    6                                         ; Offset error correction value bit 14
ADCOFSH_OFS15      equ    7                                         ; Offset error correction value bit 15
; bit position masks
mADCOFSH_OFS8      equ    00000001b
mADCOFSH_OFS9      equ    00000010b
mADCOFSH_OFS10     equ    00000100b
mADCOFSH_OFS11     equ    00001000b
mADCOFSH_OFS12     equ    00010000b
mADCOFSH_OFS13     equ    00100000b
mADCOFSH_OFS14     equ    01000000b
mADCOFSH_OFS15     equ    10000000b


;*** ADCOFSL - Offset Correction Low Register; 0x00001887 ***
ADCOFSL            equ    $00001887                                ;*** ADCOFSL - Offset Correction Low Register; 0x00001887 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCOFSL_OFS0       equ    0                                         ; Offset error correction value bit 0
ADCOFSL_OFS1       equ    1                                         ; Offset error correction value bit 1
ADCOFSL_OFS2       equ    2                                         ; Offset error correction value bit 2
ADCOFSL_OFS3       equ    3                                         ; Offset error correction value bit 3
ADCOFSL_OFS4       equ    4                                         ; Offset error correction value bit 4
ADCOFSL_OFS5       equ    5                                         ; Offset error correction value bit 5
ADCOFSL_OFS6       equ    6                                         ; Offset error correction value bit 6
ADCOFSL_OFS7       equ    7                                         ; Offset error correction value bit 7
; bit position masks
mADCOFSL_OFS0      equ    00000001b
mADCOFSL_OFS1      equ    00000010b
mADCOFSL_OFS2      equ    00000100b
mADCOFSL_OFS3      equ    00001000b
mADCOFSL_OFS4      equ    00010000b
mADCOFSL_OFS5      equ    00100000b
mADCOFSL_OFS6      equ    01000000b
mADCOFSL_OFS7      equ    10000000b


;*** ADCPG - Plus-Side Gain Register; 0x00001888 ***
ADCPG              equ    $00001888                                ;*** ADCPG - Plus-Side Gain Register; 0x00001888 ***


;*** ADCPGH - Plus-Side Gain High Register; 0x00001888 ***
ADCPGH             equ    $00001888                                ;*** ADCPGH - Plus-Side Gain High Register; 0x00001888 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCPGH_PG8         equ    0                                         ; Gain error correction for the plus-side input value bit 8
ADCPGH_PG9         equ    1                                         ; Gain error correction for the plus-side input value bit 9
ADCPGH_PG10        equ    2                                         ; Gain error correction for the plus-side input value bit 10
ADCPGH_PG11        equ    3                                         ; Gain error correction for the plus-side input value bit 11
ADCPGH_PG12        equ    4                                         ; Gain error correction for the plus-side input value bit 12
ADCPGH_PG13        equ    5                                         ; Gain error correction for the plus-side input value bit 13
ADCPGH_PG14        equ    6                                         ; Gain error correction for the plus-side input value bit 14
ADCPGH_PG15        equ    7                                         ; Gain error correction for the plus-side input value bit 15
; bit position masks
mADCPGH_PG8        equ    00000001b
mADCPGH_PG9        equ    00000010b
mADCPGH_PG10       equ    00000100b
mADCPGH_PG11       equ    00001000b
mADCPGH_PG12       equ    00010000b
mADCPGH_PG13       equ    00100000b
mADCPGH_PG14       equ    01000000b
mADCPGH_PG15       equ    10000000b


;*** ADCPGL - Plus-Side Gain Low Register; 0x00001889 ***
ADCPGL             equ    $00001889                                ;*** ADCPGL - Plus-Side Gain Low Register; 0x00001889 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCPGL_PG0         equ    0                                         ; Gain error correction for the plus-side input value bit 0
ADCPGL_PG1         equ    1                                         ; Gain error correction for the plus-side input value bit 1
ADCPGL_PG2         equ    2                                         ; Gain error correction for the plus-side input value bit 2
ADCPGL_PG3         equ    3                                         ; Gain error correction for the plus-side input value bit 3
ADCPGL_PG4         equ    4                                         ; Gain error correction for the plus-side input value bit 4
ADCPGL_PG5         equ    5                                         ; Gain error correction for the plus-side input value bit 5
ADCPGL_PG6         equ    6                                         ; Gain error correction for the plus-side input value bit 6
ADCPGL_PG7         equ    7                                         ; Gain error correction for the plus-side input value bit 7
; bit position masks
mADCPGL_PG0        equ    00000001b
mADCPGL_PG1        equ    00000010b
mADCPGL_PG2        equ    00000100b
mADCPGL_PG3        equ    00001000b
mADCPGL_PG4        equ    00010000b
mADCPGL_PG5        equ    00100000b
mADCPGL_PG6        equ    01000000b
mADCPGL_PG7        equ    10000000b


;*** ADCMG - Minus-Side Gain Register; 0x0000188A ***
ADCMG              equ    $0000188A                                ;*** ADCMG - Minus-Side Gain Register; 0x0000188A ***


;*** ADCMGH - Minus-Side Gain High Register; 0x0000188A ***
ADCMGH             equ    $0000188A                                ;*** ADCMGH - Minus-Side Gain High Register; 0x0000188A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCMGH_MG8         equ    0                                         ; Gain error correction for the minus-side input value bit 8
ADCMGH_MG9         equ    1                                         ; Gain error correction for the minus-side input value bit 9
ADCMGH_MG10        equ    2                                         ; Gain error correction for the minus-side input value bit 10
ADCMGH_MG11        equ    3                                         ; Gain error correction for the minus-side input value bit 11
ADCMGH_MG12        equ    4                                         ; Gain error correction for the minus-side input value bit 12
ADCMGH_MG13        equ    5                                         ; Gain error correction for the minus-side input value bit 13
ADCMGH_MG14        equ    6                                         ; Gain error correction for the minus-side input value bit 14
ADCMGH_MG15        equ    7                                         ; Gain error correction for the minus-side input value bit 15
; bit position masks
mADCMGH_MG8        equ    00000001b
mADCMGH_MG9        equ    00000010b
mADCMGH_MG10       equ    00000100b
mADCMGH_MG11       equ    00001000b
mADCMGH_MG12       equ    00010000b
mADCMGH_MG13       equ    00100000b
mADCMGH_MG14       equ    01000000b
mADCMGH_MG15       equ    10000000b


;*** ADCMGL - Minus-Side Gain Low Register; 0x0000188B ***
ADCMGL             equ    $0000188B                                ;*** ADCMGL - Minus-Side Gain Low Register; 0x0000188B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCMGL_MG0         equ    0                                         ; Gain error correction for the minus-side input value bit 0
ADCMGL_MG1         equ    1                                         ; Gain error correction for the minus-side input value bit 1
ADCMGL_MG2         equ    2                                         ; Gain error correction for the minus-side input value bit 2
ADCMGL_MG3         equ    3                                         ; Gain error correction for the minus-side input value bit 3
ADCMGL_MG4         equ    4                                         ; Gain error correction for the minus-side input value bit 4
ADCMGL_MG5         equ    5                                         ; Gain error correction for the minus-side input value bit 5
ADCMGL_MG6         equ    6                                         ; Gain error correction for the minus-side input value bit 6
ADCMGL_MG7         equ    7                                         ; Gain error correction for the minus-side input value bit 7
; bit position masks
mADCMGL_MG0        equ    00000001b
mADCMGL_MG1        equ    00000010b
mADCMGL_MG2        equ    00000100b
mADCMGL_MG3        equ    00001000b
mADCMGL_MG4        equ    00010000b
mADCMGL_MG5        equ    00100000b
mADCMGL_MG6        equ    01000000b
mADCMGL_MG7        equ    10000000b


;*** ADCCLPD - Plus-Side General Calibration Value D Register; 0x0000188C ***
ADCCLPD            equ    $0000188C                                ;*** ADCCLPD - Plus-Side General Calibration Value D Register; 0x0000188C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLPD_CLPD0      equ    0                                         ; Plus-Side General Calibration Value D bit 0
ADCCLPD_CLPD1      equ    1                                         ; Plus-Side General Calibration Value D bit 1
ADCCLPD_CLPD2      equ    2                                         ; Plus-Side General Calibration Value D bit 2
ADCCLPD_CLPD3      equ    3                                         ; Plus-Side General Calibration Value D bit 3
ADCCLPD_CLPD4      equ    4                                         ; Plus-Side General Calibration Value D bit 4
ADCCLPD_CLPD5      equ    5                                         ; Plus-Side General Calibration Value D bit 5
; bit position masks
mADCCLPD_CLPD0     equ    00000001b
mADCCLPD_CLPD1     equ    00000010b
mADCCLPD_CLPD2     equ    00000100b
mADCCLPD_CLPD3     equ    00001000b
mADCCLPD_CLPD4     equ    00010000b
mADCCLPD_CLPD5     equ    00100000b


;*** ADCCLPS - Plus-Side General Calibration Value S Register; 0x0000188D ***
ADCCLPS            equ    $0000188D                                ;*** ADCCLPS - Plus-Side General Calibration Value S Register; 0x0000188D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLPS_CLPS0      equ    0                                         ; Plus-Side General Calibration Value S bit 0
ADCCLPS_CLPS1      equ    1                                         ; Plus-Side General Calibration Value S bit 1
ADCCLPS_CLPS2      equ    2                                         ; Plus-Side General Calibration Value S bit 2
ADCCLPS_CLPS3      equ    3                                         ; Plus-Side General Calibration Value S bit 3
ADCCLPS_CLPS4      equ    4                                         ; Plus-Side General Calibration Value S bit 4
ADCCLPS_CLPS5      equ    5                                         ; Plus-Side General Calibration Value S bit 5
; bit position masks
mADCCLPS_CLPS0     equ    00000001b
mADCCLPS_CLPS1     equ    00000010b
mADCCLPS_CLPS2     equ    00000100b
mADCCLPS_CLPS3     equ    00001000b
mADCCLPS_CLPS4     equ    00010000b
mADCCLPS_CLPS5     equ    00100000b


;*** ADCCLP4 - Plus-Side General Calibration Value 4 Register; 0x0000188E ***
ADCCLP4            equ    $0000188E                                ;*** ADCCLP4 - Plus-Side General Calibration Value 4 Register; 0x0000188E ***


;*** ADCCLP4H - Plus-Side General Calibration Value 4 High Register; 0x0000188E ***
ADCCLP4H           equ    $0000188E                                ;*** ADCCLP4H - Plus-Side General Calibration Value 4 High Register; 0x0000188E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP4H_CLP48     equ    0                                         ; Plus-Side General Calibration Value 4 bit 8
ADCCLP4H_CLP49     equ    1                                         ; Plus-Side General Calibration Value 4 bit 9
; bit position masks
mADCCLP4H_CLP48    equ    00000001b
mADCCLP4H_CLP49    equ    00000010b


;*** ADCCLP4L - Plus-Side General Calibration Value 4 Low Register; 0x0000188F ***
ADCCLP4L           equ    $0000188F                                ;*** ADCCLP4L - Plus-Side General Calibration Value 4 Low Register; 0x0000188F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP4L_CLP40     equ    0                                         ; Plus-Side General Calibration Value 4 bit 0
ADCCLP4L_CLP41     equ    1                                         ; Plus-Side General Calibration Value 4 bit 1
ADCCLP4L_CLP42     equ    2                                         ; Plus-Side General Calibration Value 4 bit 2
ADCCLP4L_CLP43     equ    3                                         ; Plus-Side General Calibration Value 4 bit 3
ADCCLP4L_CLP44     equ    4                                         ; Plus-Side General Calibration Value 4 bit 4
ADCCLP4L_CLP45     equ    5                                         ; Plus-Side General Calibration Value 4 bit 5
ADCCLP4L_CLP46     equ    6                                         ; Plus-Side General Calibration Value 4 bit 6
ADCCLP4L_CLP47     equ    7                                         ; Plus-Side General Calibration Value 4 bit 7
; bit position masks
mADCCLP4L_CLP40    equ    00000001b
mADCCLP4L_CLP41    equ    00000010b
mADCCLP4L_CLP42    equ    00000100b
mADCCLP4L_CLP43    equ    00001000b
mADCCLP4L_CLP44    equ    00010000b
mADCCLP4L_CLP45    equ    00100000b
mADCCLP4L_CLP46    equ    01000000b
mADCCLP4L_CLP47    equ    10000000b


;*** ADCCLP3 - Plus-Side General Calibration Value 3 Register; 0x00001890 ***
ADCCLP3            equ    $00001890                                ;*** ADCCLP3 - Plus-Side General Calibration Value 3 Register; 0x00001890 ***


;*** ADCCLP3H - Plus-Side General Calibration Value 3 High Register; 0x00001890 ***
ADCCLP3H           equ    $00001890                                ;*** ADCCLP3H - Plus-Side General Calibration Value 3 High Register; 0x00001890 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP3H_CLP38     equ    0                                         ; Plus-Side General Calibration Value 3 bits
; bit position masks
mADCCLP3H_CLP38    equ    00000001b


;*** ADCCLP3L - Plus-Side General Calibration Value 3 Low Register; 0x00001891 ***
ADCCLP3L           equ    $00001891                                ;*** ADCCLP3L - Plus-Side General Calibration Value 3 Low Register; 0x00001891 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP3L_CLP30     equ    0                                         ; Plus-Side General Calibration Value 3 bit 0
ADCCLP3L_CLP31     equ    1                                         ; Plus-Side General Calibration Value 3 bit 1
ADCCLP3L_CLP32     equ    2                                         ; Plus-Side General Calibration Value 3 bit 2
ADCCLP3L_CLP33     equ    3                                         ; Plus-Side General Calibration Value 3 bit 3
ADCCLP3L_CLP34     equ    4                                         ; Plus-Side General Calibration Value 3 bit 4
ADCCLP3L_CLP35     equ    5                                         ; Plus-Side General Calibration Value 3 bit 5
ADCCLP3L_CLP36     equ    6                                         ; Plus-Side General Calibration Value 3 bit 6
ADCCLP3L_CLP37     equ    7                                         ; Plus-Side General Calibration Value 3 bit 7
; bit position masks
mADCCLP3L_CLP30    equ    00000001b
mADCCLP3L_CLP31    equ    00000010b
mADCCLP3L_CLP32    equ    00000100b
mADCCLP3L_CLP33    equ    00001000b
mADCCLP3L_CLP34    equ    00010000b
mADCCLP3L_CLP35    equ    00100000b
mADCCLP3L_CLP36    equ    01000000b
mADCCLP3L_CLP37    equ    10000000b


;*** ADCCLP2 - Plus-Side General Calibration Value 2 Register; 0x00001892 ***
ADCCLP2            equ    $00001892                                ;*** ADCCLP2 - Plus-Side General Calibration Value 2 Register; 0x00001892 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP2_CLP20      equ    0                                         ; Plus-Side General Calibration Value 2 bit 0
ADCCLP2_CLP21      equ    1                                         ; Plus-Side General Calibration Value 2 bit 1
ADCCLP2_CLP22      equ    2                                         ; Plus-Side General Calibration Value 2 bit 2
ADCCLP2_CLP23      equ    3                                         ; Plus-Side General Calibration Value 2 bit 3
ADCCLP2_CLP24      equ    4                                         ; Plus-Side General Calibration Value 2 bit 4
ADCCLP2_CLP25      equ    5                                         ; Plus-Side General Calibration Value 2 bit 5
ADCCLP2_CLP26      equ    6                                         ; Plus-Side General Calibration Value 2 bit 6
ADCCLP2_CLP27      equ    7                                         ; Plus-Side General Calibration Value 2 bit 7
; bit position masks
mADCCLP2_CLP20     equ    00000001b
mADCCLP2_CLP21     equ    00000010b
mADCCLP2_CLP22     equ    00000100b
mADCCLP2_CLP23     equ    00001000b
mADCCLP2_CLP24     equ    00010000b
mADCCLP2_CLP25     equ    00100000b
mADCCLP2_CLP26     equ    01000000b
mADCCLP2_CLP27     equ    10000000b


;*** ADCCLP1 - Plus-Side General Calibration Value 1 Register; 0x00001893 ***
ADCCLP1            equ    $00001893                                ;*** ADCCLP1 - Plus-Side General Calibration Value 1 Register; 0x00001893 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP1_CLP10      equ    0                                         ; Plus-Side General Calibration Value 1 bit 0
ADCCLP1_CLP11      equ    1                                         ; Plus-Side General Calibration Value 1 bit 1
ADCCLP1_CLP12      equ    2                                         ; Plus-Side General Calibration Value 1 bit 2
ADCCLP1_CLP13      equ    3                                         ; Plus-Side General Calibration Value 1 bit 3
ADCCLP1_CLP14      equ    4                                         ; Plus-Side General Calibration Value 1 bit 4
ADCCLP1_CLP15      equ    5                                         ; Plus-Side General Calibration Value 1 bit 5
ADCCLP1_CLP16      equ    6                                         ; Plus-Side General Calibration Value 1 bit 6
; bit position masks
mADCCLP1_CLP10     equ    00000001b
mADCCLP1_CLP11     equ    00000010b
mADCCLP1_CLP12     equ    00000100b
mADCCLP1_CLP13     equ    00001000b
mADCCLP1_CLP14     equ    00010000b
mADCCLP1_CLP15     equ    00100000b
mADCCLP1_CLP16     equ    01000000b


;*** ADCCLP0 - Plus-Side General Calibration Value 0 Register; 0x00001894 ***
ADCCLP0            equ    $00001894                                ;*** ADCCLP0 - Plus-Side General Calibration Value 0 Register; 0x00001894 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLP0_CLP00      equ    0                                         ; Plus-Side General Calibration Value 0 bit 0
ADCCLP0_CLP01      equ    1                                         ; Plus-Side General Calibration Value 0 bit 1
ADCCLP0_CLP02      equ    2                                         ; Plus-Side General Calibration Value 0 bit 2
ADCCLP0_CLP03      equ    3                                         ; Plus-Side General Calibration Value 0 bit 3
ADCCLP0_CLP04      equ    4                                         ; Plus-Side General Calibration Value 0 bit 4
ADCCLP0_CLP05      equ    5                                         ; Plus-Side General Calibration Value 0 bit 5
; bit position masks
mADCCLP0_CLP00     equ    00000001b
mADCCLP0_CLP01     equ    00000010b
mADCCLP0_CLP02     equ    00000100b
mADCCLP0_CLP03     equ    00001000b
mADCCLP0_CLP04     equ    00010000b
mADCCLP0_CLP05     equ    00100000b


;*** ADCCLMD - Minus-Side General Calibration Value D Register; 0x00001896 ***
ADCCLMD            equ    $00001896                                ;*** ADCCLMD - Minus-Side General Calibration Value D Register; 0x00001896 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLMD_CLMD0      equ    0                                         ; Minus-Side General Calibration Value D bit 0
ADCCLMD_CLMD1      equ    1                                         ; Minus-Side General Calibration Value D bit 1
ADCCLMD_CLMD2      equ    2                                         ; Minus-Side General Calibration Value D bit 2
ADCCLMD_CLMD3      equ    3                                         ; Minus-Side General Calibration Value D bit 3
ADCCLMD_CLMD4      equ    4                                         ; Minus-Side General Calibration Value D bit 4
ADCCLMD_CLMD5      equ    5                                         ; Minus-Side General Calibration Value D bit 5
; bit position masks
mADCCLMD_CLMD0     equ    00000001b
mADCCLMD_CLMD1     equ    00000010b
mADCCLMD_CLMD2     equ    00000100b
mADCCLMD_CLMD3     equ    00001000b
mADCCLMD_CLMD4     equ    00010000b
mADCCLMD_CLMD5     equ    00100000b


;*** ADCCLMS - Minus-Side General Calibration Value S Register; 0x00001897 ***
ADCCLMS            equ    $00001897                                ;*** ADCCLMS - Minus-Side General Calibration Value S Register; 0x00001897 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLMS_CLMS0      equ    0                                         ; Minus-Side General Calibration Value S bit 0
ADCCLMS_CLMS1      equ    1                                         ; Minus-Side General Calibration Value S bit 1
ADCCLMS_CLMS2      equ    2                                         ; Minus-Side General Calibration Value S bit 2
ADCCLMS_CLMS3      equ    3                                         ; Minus-Side General Calibration Value S bit 3
ADCCLMS_CLMS4      equ    4                                         ; Minus-Side General Calibration Value S bit 4
ADCCLMS_CLMS5      equ    5                                         ; Minus-Side General Calibration Value S bit 5
; bit position masks
mADCCLMS_CLMS0     equ    00000001b
mADCCLMS_CLMS1     equ    00000010b
mADCCLMS_CLMS2     equ    00000100b
mADCCLMS_CLMS3     equ    00001000b
mADCCLMS_CLMS4     equ    00010000b
mADCCLMS_CLMS5     equ    00100000b


;*** ADCCLM4 - Minus-Side General Calibration Value 4 Register; 0x00001898 ***
ADCCLM4            equ    $00001898                                ;*** ADCCLM4 - Minus-Side General Calibration Value 4 Register; 0x00001898 ***


;*** ADCCLM4H - Minus-Side General Calibration Value 4 High Register; 0x00001898 ***
ADCCLM4H           equ    $00001898                                ;*** ADCCLM4H - Minus-Side General Calibration Value 4 High Register; 0x00001898 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM4H_CLM48     equ    0                                         ; Minus-Side General Calibration Value 4 bit 8
ADCCLM4H_CLM49     equ    1                                         ; Minus-Side General Calibration Value 4 bit 9
; bit position masks
mADCCLM4H_CLM48    equ    00000001b
mADCCLM4H_CLM49    equ    00000010b


;*** ADCCLM4L - Minus-Side General Calibration Value 4 Low Register; 0x00001899 ***
ADCCLM4L           equ    $00001899                                ;*** ADCCLM4L - Minus-Side General Calibration Value 4 Low Register; 0x00001899 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM4L_CLM40     equ    0                                         ; Minus-Side General Calibration Value 4 bit 0
ADCCLM4L_CLM41     equ    1                                         ; Minus-Side General Calibration Value 4 bit 1
ADCCLM4L_CLM42     equ    2                                         ; Minus-Side General Calibration Value 4 bit 2
ADCCLM4L_CLM43     equ    3                                         ; Minus-Side General Calibration Value 4 bit 3
ADCCLM4L_CLM44     equ    4                                         ; Minus-Side General Calibration Value 4 bit 4
ADCCLM4L_CLM45     equ    5                                         ; Minus-Side General Calibration Value 4 bit 5
ADCCLM4L_CLM46     equ    6                                         ; Minus-Side General Calibration Value 4 bit 6
ADCCLM4L_CLM47     equ    7                                         ; Minus-Side General Calibration Value 4 bit 7
; bit position masks
mADCCLM4L_CLM40    equ    00000001b
mADCCLM4L_CLM41    equ    00000010b
mADCCLM4L_CLM42    equ    00000100b
mADCCLM4L_CLM43    equ    00001000b
mADCCLM4L_CLM44    equ    00010000b
mADCCLM4L_CLM45    equ    00100000b
mADCCLM4L_CLM46    equ    01000000b
mADCCLM4L_CLM47    equ    10000000b


;*** ADCCLM3 - Minus-Side General Calibration Value 3 Register; 0x0000189A ***
ADCCLM3            equ    $0000189A                                ;*** ADCCLM3 - Minus-Side General Calibration Value 3 Register; 0x0000189A ***


;*** ADCCLM3H - Minus-Side General Calibration Value 3 High Register; 0x0000189A ***
ADCCLM3H           equ    $0000189A                                ;*** ADCCLM3H - Minus-Side General Calibration Value 3 High Register; 0x0000189A ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM3H_CLM38     equ    0                                         ; Minus-Side General Calibration Value 3 bits
; bit position masks
mADCCLM3H_CLM38    equ    00000001b


;*** ADCCLM3L - Minus-Side General Calibration Value 3 Low Register; 0x0000189B ***
ADCCLM3L           equ    $0000189B                                ;*** ADCCLM3L - Minus-Side General Calibration Value 3 Low Register; 0x0000189B ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM3L_CLM30     equ    0                                         ; Minus-Side General Calibration Value 3 bit 0
ADCCLM3L_CLM31     equ    1                                         ; Minus-Side General Calibration Value 3 bit 1
ADCCLM3L_CLM32     equ    2                                         ; Minus-Side General Calibration Value 3 bit 2
ADCCLM3L_CLM33     equ    3                                         ; Minus-Side General Calibration Value 3 bit 3
ADCCLM3L_CLM34     equ    4                                         ; Minus-Side General Calibration Value 3 bit 4
ADCCLM3L_CLM35     equ    5                                         ; Minus-Side General Calibration Value 3 bit 5
ADCCLM3L_CLM36     equ    6                                         ; Minus-Side General Calibration Value 3 bit 6
ADCCLM3L_CLM37     equ    7                                         ; Minus-Side General Calibration Value 3 bit 7
; bit position masks
mADCCLM3L_CLM30    equ    00000001b
mADCCLM3L_CLM31    equ    00000010b
mADCCLM3L_CLM32    equ    00000100b
mADCCLM3L_CLM33    equ    00001000b
mADCCLM3L_CLM34    equ    00010000b
mADCCLM3L_CLM35    equ    00100000b
mADCCLM3L_CLM36    equ    01000000b
mADCCLM3L_CLM37    equ    10000000b


;*** ADCCLM2 - Minus-Side General Calibration Value 2 Register; 0x0000189C ***
ADCCLM2            equ    $0000189C                                ;*** ADCCLM2 - Minus-Side General Calibration Value 2 Register; 0x0000189C ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM2_CLM20      equ    0                                         ; Minus-Side General Calibration Value 2 bit 0
ADCCLM2_CLM21      equ    1                                         ; Minus-Side General Calibration Value 2 bit 1
ADCCLM2_CLM22      equ    2                                         ; Minus-Side General Calibration Value 2 bit 2
ADCCLM2_CLM23      equ    3                                         ; Minus-Side General Calibration Value 2 bit 3
ADCCLM2_CLM24      equ    4                                         ; Minus-Side General Calibration Value 2 bit 4
ADCCLM2_CLM25      equ    5                                         ; Minus-Side General Calibration Value 2 bit 5
ADCCLM2_CLM26      equ    6                                         ; Minus-Side General Calibration Value 2 bit 6
ADCCLM2_CLM27      equ    7                                         ; Minus-Side General Calibration Value 2 bit 7
; bit position masks
mADCCLM2_CLM20     equ    00000001b
mADCCLM2_CLM21     equ    00000010b
mADCCLM2_CLM22     equ    00000100b
mADCCLM2_CLM23     equ    00001000b
mADCCLM2_CLM24     equ    00010000b
mADCCLM2_CLM25     equ    00100000b
mADCCLM2_CLM26     equ    01000000b
mADCCLM2_CLM27     equ    10000000b


;*** ADCCLM1 - Minus-Side General Calibration Value 1 Register; 0x0000189D ***
ADCCLM1            equ    $0000189D                                ;*** ADCCLM1 - Minus-Side General Calibration Value 1 Register; 0x0000189D ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM1_CLM10      equ    0                                         ; Minus-Side General Calibration Value 1 bit 0
ADCCLM1_CLM11      equ    1                                         ; Minus-Side General Calibration Value 1 bit 1
ADCCLM1_CLM12      equ    2                                         ; Minus-Side General Calibration Value 1 bit 2
ADCCLM1_CLM13      equ    3                                         ; Minus-Side General Calibration Value 1 bit 3
ADCCLM1_CLM14      equ    4                                         ; Minus-Side General Calibration Value 1 bit 4
ADCCLM1_CLM15      equ    5                                         ; Minus-Side General Calibration Value 1 bit 5
ADCCLM1_CLM16      equ    6                                         ; Minus-Side General Calibration Value 1 bit 6
; bit position masks
mADCCLM1_CLM10     equ    00000001b
mADCCLM1_CLM11     equ    00000010b
mADCCLM1_CLM12     equ    00000100b
mADCCLM1_CLM13     equ    00001000b
mADCCLM1_CLM14     equ    00010000b
mADCCLM1_CLM15     equ    00100000b
mADCCLM1_CLM16     equ    01000000b


;*** ADCCLM0 - Minus-Side General Calibration Value 0 Register; 0x0000189E ***
ADCCLM0            equ    $0000189E                                ;*** ADCCLM0 - Minus-Side General Calibration Value 0 Register; 0x0000189E ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
ADCCLM0_CLM00      equ    0                                         ; Minus-Side General Calibration Value 0 bit 0
ADCCLM0_CLM01      equ    1                                         ; Minus-Side General Calibration Value 0 bit 1
ADCCLM0_CLM02      equ    2                                         ; Minus-Side General Calibration Value 0 bit 2
ADCCLM0_CLM03      equ    3                                         ; Minus-Side General Calibration Value 0 bit 3
ADCCLM0_CLM04      equ    4                                         ; Minus-Side General Calibration Value 0 bit 4
ADCCLM0_CLM05      equ    5                                         ; Minus-Side General Calibration Value 0 bit 5
; bit position masks
mADCCLM0_CLM00     equ    00000001b
mADCCLM0_CLM01     equ    00000010b
mADCCLM0_CLM02     equ    00000100b
mADCCLM0_CLM03     equ    00001000b
mADCCLM0_CLM04     equ    00010000b
mADCCLM0_CLM05     equ    00100000b


;*** APCTL1 - Pin Control 1 Register; 0x0000189F ***
APCTL1             equ    $0000189F                                ;*** APCTL1 - Pin Control 1 Register; 0x0000189F ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL1_ADPC0       equ    0                                         ; ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0
APCTL1_ADPC4       equ    4                                         ; ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4
APCTL1_ADPC5       equ    5                                         ; ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5
APCTL1_ADPC6       equ    6                                         ; ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6
APCTL1_ADPC7       equ    7                                         ; ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7
; bit position masks
mAPCTL1_ADPC0      equ    00000001b
mAPCTL1_ADPC4      equ    00010000b
mAPCTL1_ADPC5      equ    00100000b
mAPCTL1_ADPC6      equ    01000000b
mAPCTL1_ADPC7      equ    10000000b


;*** APCTL2 - Pin Control 2 Register; 0x000018A0 ***
APCTL2             equ    $000018A0                                ;*** APCTL2 - Pin Control 2 Register; 0x000018A0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
APCTL2_ADPC8       equ    0                                         ; ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8
APCTL2_ADPC9       equ    1                                         ; ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9
APCTL2_ADPC10      equ    2                                         ; ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10
APCTL2_ADPC11      equ    3                                         ; ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11
; bit position masks
mAPCTL2_ADPC8      equ    00000001b
mAPCTL2_ADPC9      equ    00000010b
mAPCTL2_ADPC10     equ    00000100b
mAPCTL2_ADPC11     equ    00001000b


;*** NVVREF1TRM - Non-volatile VREF Trim Register; 0x0000FFAC ***
NVVREF1TRM         equ    $0000FFAC                                ;*** NVVREF1TRM - Non-volatile VREF Trim Register; 0x0000FFAC ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVVREF1TRM_TRM0    equ    0                                         ; Trim Bit 0, bit 0
NVVREF1TRM_TRM1    equ    1                                         ; Trim Bit 0, bit 1
NVVREF1TRM_TRM2    equ    2                                         ; Trim Bit 0, bit 2
NVVREF1TRM_TRM3    equ    3                                         ; Trim Bit 0, bit 3
NVVREF1TRM_TRM4    equ    4                                         ; Trim Bit 0, bit 4
NVVREF1TRM_TRM5    equ    5                                         ; Trim Bit 0, bit 5
NVVREF1TRM_TRM6    equ    6                                         ; Trim Bit 0, bit 6
NVVREF1TRM_TRM7    equ    7                                         ; Trim Bit 0, bit 7
; bit position masks
mNVVREF1TRM_TRM0   equ    00000001b
mNVVREF1TRM_TRM1   equ    00000010b
mNVVREF1TRM_TRM2   equ    00000100b
mNVVREF1TRM_TRM3   equ    00001000b
mNVVREF1TRM_TRM4   equ    00010000b
mNVVREF1TRM_TRM5   equ    00100000b
mNVVREF1TRM_TRM6   equ    01000000b
mNVVREF1TRM_TRM7   equ    10000000b


;*** NVVREF2TRM - Non-volatile VREF Trim Register; 0x0000FFAD ***
NVVREF2TRM         equ    $0000FFAD                                ;*** NVVREF2TRM - Non-volatile VREF Trim Register; 0x0000FFAD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVVREF2TRM_TRM0    equ    0                                         ; Trim Bit 0, bit 0
NVVREF2TRM_TRM1    equ    1                                         ; Trim Bit 0, bit 1
NVVREF2TRM_TRM2    equ    2                                         ; Trim Bit 0, bit 2
NVVREF2TRM_TRM3    equ    3                                         ; Trim Bit 0, bit 3
NVVREF2TRM_TRM4    equ    4                                         ; Trim Bit 0, bit 4
NVVREF2TRM_TRM5    equ    5                                         ; Trim Bit 0, bit 5
NVVREF2TRM_TRM6    equ    6                                         ; Trim Bit 0, bit 6
NVVREF2TRM_TRM7    equ    7                                         ; Trim Bit 0, bit 7
; bit position masks
mNVVREF2TRM_TRM0   equ    00000001b
mNVVREF2TRM_TRM1   equ    00000010b
mNVVREF2TRM_TRM2   equ    00000100b
mNVVREF2TRM_TRM3   equ    00001000b
mNVVREF2TRM_TRM4   equ    00010000b
mNVVREF2TRM_TRM5   equ    00100000b
mNVVREF2TRM_TRM6   equ    01000000b
mNVVREF2TRM_TRM7   equ    10000000b


;*** NVFTRIM - Nonvolatile ICS Fine Trim; 0x0000FFAE ***
NVFTRIM            equ    $0000FFAE                                ;*** NVFTRIM - Nonvolatile ICS Fine Trim; 0x0000FFAE ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVFTRIM_FTRIM      equ    0                                         ; ICS Fine Trim
; bit position masks
mNVFTRIM_FTRIM     equ    00000001b


;*** NVICSTRM - Nonvolatile ICS Trim Register; 0x0000FFAF ***
NVICSTRM           equ    $0000FFAF                                ;*** NVICSTRM - Nonvolatile ICS Trim Register; 0x0000FFAF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVICSTRM_TRIM0     equ    0                                         ; ICS Trim Setting, bit 0
NVICSTRM_TRIM1     equ    1                                         ; ICS Trim Setting, bit 1
NVICSTRM_TRIM2     equ    2                                         ; ICS Trim Setting, bit 2
NVICSTRM_TRIM3     equ    3                                         ; ICS Trim Setting, bit 3
NVICSTRM_TRIM4     equ    4                                         ; ICS Trim Setting, bit 4
NVICSTRM_TRIM5     equ    5                                         ; ICS Trim Setting, bit 5
NVICSTRM_TRIM6     equ    6                                         ; ICS Trim Setting, bit 6
NVICSTRM_TRIM7     equ    7                                         ; ICS Trim Setting, bit 7
; bit position masks
mNVICSTRM_TRIM0    equ    00000001b
mNVICSTRM_TRIM1    equ    00000010b
mNVICSTRM_TRIM2    equ    00000100b
mNVICSTRM_TRIM3    equ    00001000b
mNVICSTRM_TRIM4    equ    00010000b
mNVICSTRM_TRIM5    equ    00100000b
mNVICSTRM_TRIM6    equ    01000000b
mNVICSTRM_TRIM7    equ    10000000b


;*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***
NVBACKKEY0         equ    $0000FFB0                                ;*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY0_KEY0    equ    0                                         ; Backdoor Comparison Key 0 Bits, bit 0
NVBACKKEY0_KEY1    equ    1                                         ; Backdoor Comparison Key 0 Bits, bit 1
NVBACKKEY0_KEY2    equ    2                                         ; Backdoor Comparison Key 0 Bits, bit 2
NVBACKKEY0_KEY3    equ    3                                         ; Backdoor Comparison Key 0 Bits, bit 3
NVBACKKEY0_KEY4    equ    4                                         ; Backdoor Comparison Key 0 Bits, bit 4
NVBACKKEY0_KEY5    equ    5                                         ; Backdoor Comparison Key 0 Bits, bit 5
NVBACKKEY0_KEY6    equ    6                                         ; Backdoor Comparison Key 0 Bits, bit 6
NVBACKKEY0_KEY7    equ    7                                         ; Backdoor Comparison Key 0 Bits, bit 7
; bit position masks
mNVBACKKEY0_KEY0   equ    00000001b
mNVBACKKEY0_KEY1   equ    00000010b
mNVBACKKEY0_KEY2   equ    00000100b
mNVBACKKEY0_KEY3   equ    00001000b
mNVBACKKEY0_KEY4   equ    00010000b
mNVBACKKEY0_KEY5   equ    00100000b
mNVBACKKEY0_KEY6   equ    01000000b
mNVBACKKEY0_KEY7   equ    10000000b


;*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***
NVBACKKEY1         equ    $0000FFB1                                ;*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY1_KEY0    equ    0                                         ; Backdoor Comparison Key 1 Bits, bit 0
NVBACKKEY1_KEY1    equ    1                                         ; Backdoor Comparison Key 1 Bits, bit 1
NVBACKKEY1_KEY2    equ    2                                         ; Backdoor Comparison Key 1 Bits, bit 2
NVBACKKEY1_KEY3    equ    3                                         ; Backdoor Comparison Key 1 Bits, bit 3
NVBACKKEY1_KEY4    equ    4                                         ; Backdoor Comparison Key 1 Bits, bit 4
NVBACKKEY1_KEY5    equ    5                                         ; Backdoor Comparison Key 1 Bits, bit 5
NVBACKKEY1_KEY6    equ    6                                         ; Backdoor Comparison Key 1 Bits, bit 6
NVBACKKEY1_KEY7    equ    7                                         ; Backdoor Comparison Key 1 Bits, bit 7
; bit position masks
mNVBACKKEY1_KEY0   equ    00000001b
mNVBACKKEY1_KEY1   equ    00000010b
mNVBACKKEY1_KEY2   equ    00000100b
mNVBACKKEY1_KEY3   equ    00001000b
mNVBACKKEY1_KEY4   equ    00010000b
mNVBACKKEY1_KEY5   equ    00100000b
mNVBACKKEY1_KEY6   equ    01000000b
mNVBACKKEY1_KEY7   equ    10000000b


;*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***
NVBACKKEY2         equ    $0000FFB2                                ;*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY2_KEY0    equ    0                                         ; Backdoor Comparison Key 2 Bits, bit 0
NVBACKKEY2_KEY1    equ    1                                         ; Backdoor Comparison Key 2 Bits, bit 1
NVBACKKEY2_KEY2    equ    2                                         ; Backdoor Comparison Key 2 Bits, bit 2
NVBACKKEY2_KEY3    equ    3                                         ; Backdoor Comparison Key 2 Bits, bit 3
NVBACKKEY2_KEY4    equ    4                                         ; Backdoor Comparison Key 2 Bits, bit 4
NVBACKKEY2_KEY5    equ    5                                         ; Backdoor Comparison Key 2 Bits, bit 5
NVBACKKEY2_KEY6    equ    6                                         ; Backdoor Comparison Key 2 Bits, bit 6
NVBACKKEY2_KEY7    equ    7                                         ; Backdoor Comparison Key 2 Bits, bit 7
; bit position masks
mNVBACKKEY2_KEY0   equ    00000001b
mNVBACKKEY2_KEY1   equ    00000010b
mNVBACKKEY2_KEY2   equ    00000100b
mNVBACKKEY2_KEY3   equ    00001000b
mNVBACKKEY2_KEY4   equ    00010000b
mNVBACKKEY2_KEY5   equ    00100000b
mNVBACKKEY2_KEY6   equ    01000000b
mNVBACKKEY2_KEY7   equ    10000000b


;*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***
NVBACKKEY3         equ    $0000FFB3                                ;*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY3_KEY0    equ    0                                         ; Backdoor Comparison Key 3 Bits, bit 0
NVBACKKEY3_KEY1    equ    1                                         ; Backdoor Comparison Key 3 Bits, bit 1
NVBACKKEY3_KEY2    equ    2                                         ; Backdoor Comparison Key 3 Bits, bit 2
NVBACKKEY3_KEY3    equ    3                                         ; Backdoor Comparison Key 3 Bits, bit 3
NVBACKKEY3_KEY4    equ    4                                         ; Backdoor Comparison Key 3 Bits, bit 4
NVBACKKEY3_KEY5    equ    5                                         ; Backdoor Comparison Key 3 Bits, bit 5
NVBACKKEY3_KEY6    equ    6                                         ; Backdoor Comparison Key 3 Bits, bit 6
NVBACKKEY3_KEY7    equ    7                                         ; Backdoor Comparison Key 3 Bits, bit 7
; bit position masks
mNVBACKKEY3_KEY0   equ    00000001b
mNVBACKKEY3_KEY1   equ    00000010b
mNVBACKKEY3_KEY2   equ    00000100b
mNVBACKKEY3_KEY3   equ    00001000b
mNVBACKKEY3_KEY4   equ    00010000b
mNVBACKKEY3_KEY5   equ    00100000b
mNVBACKKEY3_KEY6   equ    01000000b
mNVBACKKEY3_KEY7   equ    10000000b


;*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***
NVBACKKEY4         equ    $0000FFB4                                ;*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY4_KEY0    equ    0                                         ; Backdoor Comparison Key 4 Bits, bit 0
NVBACKKEY4_KEY1    equ    1                                         ; Backdoor Comparison Key 4 Bits, bit 1
NVBACKKEY4_KEY2    equ    2                                         ; Backdoor Comparison Key 4 Bits, bit 2
NVBACKKEY4_KEY3    equ    3                                         ; Backdoor Comparison Key 4 Bits, bit 3
NVBACKKEY4_KEY4    equ    4                                         ; Backdoor Comparison Key 4 Bits, bit 4
NVBACKKEY4_KEY5    equ    5                                         ; Backdoor Comparison Key 4 Bits, bit 5
NVBACKKEY4_KEY6    equ    6                                         ; Backdoor Comparison Key 4 Bits, bit 6
NVBACKKEY4_KEY7    equ    7                                         ; Backdoor Comparison Key 4 Bits, bit 7
; bit position masks
mNVBACKKEY4_KEY0   equ    00000001b
mNVBACKKEY4_KEY1   equ    00000010b
mNVBACKKEY4_KEY2   equ    00000100b
mNVBACKKEY4_KEY3   equ    00001000b
mNVBACKKEY4_KEY4   equ    00010000b
mNVBACKKEY4_KEY5   equ    00100000b
mNVBACKKEY4_KEY6   equ    01000000b
mNVBACKKEY4_KEY7   equ    10000000b


;*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***
NVBACKKEY5         equ    $0000FFB5                                ;*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY5_KEY0    equ    0                                         ; Backdoor Comparison Key 5 Bits, bit 0
NVBACKKEY5_KEY1    equ    1                                         ; Backdoor Comparison Key 5 Bits, bit 1
NVBACKKEY5_KEY2    equ    2                                         ; Backdoor Comparison Key 5 Bits, bit 2
NVBACKKEY5_KEY3    equ    3                                         ; Backdoor Comparison Key 5 Bits, bit 3
NVBACKKEY5_KEY4    equ    4                                         ; Backdoor Comparison Key 5 Bits, bit 4
NVBACKKEY5_KEY5    equ    5                                         ; Backdoor Comparison Key 5 Bits, bit 5
NVBACKKEY5_KEY6    equ    6                                         ; Backdoor Comparison Key 5 Bits, bit 6
NVBACKKEY5_KEY7    equ    7                                         ; Backdoor Comparison Key 5 Bits, bit 7
; bit position masks
mNVBACKKEY5_KEY0   equ    00000001b
mNVBACKKEY5_KEY1   equ    00000010b
mNVBACKKEY5_KEY2   equ    00000100b
mNVBACKKEY5_KEY3   equ    00001000b
mNVBACKKEY5_KEY4   equ    00010000b
mNVBACKKEY5_KEY5   equ    00100000b
mNVBACKKEY5_KEY6   equ    01000000b
mNVBACKKEY5_KEY7   equ    10000000b


;*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***
NVBACKKEY6         equ    $0000FFB6                                ;*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY6_KEY0    equ    0                                         ; Backdoor Comparison Key 6 Bits, bit 0
NVBACKKEY6_KEY1    equ    1                                         ; Backdoor Comparison Key 6 Bits, bit 1
NVBACKKEY6_KEY2    equ    2                                         ; Backdoor Comparison Key 6 Bits, bit 2
NVBACKKEY6_KEY3    equ    3                                         ; Backdoor Comparison Key 6 Bits, bit 3
NVBACKKEY6_KEY4    equ    4                                         ; Backdoor Comparison Key 6 Bits, bit 4
NVBACKKEY6_KEY5    equ    5                                         ; Backdoor Comparison Key 6 Bits, bit 5
NVBACKKEY6_KEY6    equ    6                                         ; Backdoor Comparison Key 6 Bits, bit 6
NVBACKKEY6_KEY7    equ    7                                         ; Backdoor Comparison Key 6 Bits, bit 7
; bit position masks
mNVBACKKEY6_KEY0   equ    00000001b
mNVBACKKEY6_KEY1   equ    00000010b
mNVBACKKEY6_KEY2   equ    00000100b
mNVBACKKEY6_KEY3   equ    00001000b
mNVBACKKEY6_KEY4   equ    00010000b
mNVBACKKEY6_KEY5   equ    00100000b
mNVBACKKEY6_KEY6   equ    01000000b
mNVBACKKEY6_KEY7   equ    10000000b


;*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***
NVBACKKEY7         equ    $0000FFB7                                ;*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVBACKKEY7_KEY0    equ    0                                         ; Backdoor Comparison Key 7 Bits, bit 0
NVBACKKEY7_KEY1    equ    1                                         ; Backdoor Comparison Key 7 Bits, bit 1
NVBACKKEY7_KEY2    equ    2                                         ; Backdoor Comparison Key 7 Bits, bit 2
NVBACKKEY7_KEY3    equ    3                                         ; Backdoor Comparison Key 7 Bits, bit 3
NVBACKKEY7_KEY4    equ    4                                         ; Backdoor Comparison Key 7 Bits, bit 4
NVBACKKEY7_KEY5    equ    5                                         ; Backdoor Comparison Key 7 Bits, bit 5
NVBACKKEY7_KEY6    equ    6                                         ; Backdoor Comparison Key 7 Bits, bit 6
NVBACKKEY7_KEY7    equ    7                                         ; Backdoor Comparison Key 7 Bits, bit 7
; bit position masks
mNVBACKKEY7_KEY0   equ    00000001b
mNVBACKKEY7_KEY1   equ    00000010b
mNVBACKKEY7_KEY2   equ    00000100b
mNVBACKKEY7_KEY3   equ    00001000b
mNVBACKKEY7_KEY4   equ    00010000b
mNVBACKKEY7_KEY5   equ    00100000b
mNVBACKKEY7_KEY6   equ    01000000b
mNVBACKKEY7_KEY7   equ    10000000b


;*** NVPROT - Nonvolatile Flash Protection Register; 0x0000FFBD ***
NVPROT             equ    $0000FFBD                                ;*** NVPROT - Nonvolatile Flash Protection Register; 0x0000FFBD ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVPROT_FPDIS       equ    0                                         ; Flash Protection Disable
NVPROT_FPS0        equ    1                                         ; Flash Protection Size, bit 0
NVPROT_FPS1        equ    2                                         ; Flash Protection Size, bit 1
NVPROT_FPS2        equ    3                                         ; Flash Protection Size, bit 2
NVPROT_FPS3        equ    4                                         ; Flash Protection Size, bit 3
NVPROT_FPS4        equ    5                                         ; Flash Protection Size, bit 4
NVPROT_FPS5        equ    6                                         ; Flash Protection Size, bit 5
NVPROT_FPS6        equ    7                                         ; Flash Protection Size, bit 6
; bit position masks
mNVPROT_FPDIS      equ    00000001b
mNVPROT_FPS0       equ    00000010b
mNVPROT_FPS1       equ    00000100b
mNVPROT_FPS2       equ    00001000b
mNVPROT_FPS3       equ    00010000b
mNVPROT_FPS4       equ    00100000b
mNVPROT_FPS5       equ    01000000b
mNVPROT_FPS6       equ    10000000b


;*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***
NVOPT              equ    $0000FFBF                                ;*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***
; bit numbers for usage in BCLR, BSET, BRCLR and BRSET
NVOPT_SEC0         equ    0                                         ; Flash Security Bit 0
NVOPT_SEC1         equ    1                                         ; Flash Security Bit 1
NVOPT_FNORED       equ    6                                         ; Vector Redirection Disable
NVOPT_KEYEN        equ    7                                         ; Backdoor Key Security Enable
; bit position masks
mNVOPT_SEC0        equ    00000001b
mNVOPT_SEC1        equ    00000010b
mNVOPT_FNORED      equ    01000000b
mNVOPT_KEYEN       equ    10000000b



; Flash commands
mBlank             equ     $05
mBurstProg         equ     $25
mByteProg          equ     $20
mMassErase         equ     $41
mPageErase         equ     $40


;***********************************************
;**   D E P R E C I A T E D   S Y M B O L S   **
;***********************************************

; ---------------------------------------------------------------------------
; The following symbols were removed, because they were invalid or irrelevant
; ---------------------------------------------------------------------------



; **** 19.2.2009 172235

VREFTRM1                                equ        VREF1TRM
VREFTRM1_TRM10                          equ        VREF1TRM_TRM0
VREFTRM1_TRM11                          equ        VREF1TRM_TRM1
VREFTRM1_TRM12                          equ        VREF1TRM_TRM2
VREFTRM1_TRM13                          equ        VREF1TRM_TRM3
VREFTRM1_TRM14                          equ        VREF1TRM_TRM4
VREFTRM1_TRM15                          equ        VREF1TRM_TRM5
VREFTRM1_TRM16                          equ        VREF1TRM_TRM6
VREFTRM1_TRM17                          equ        VREF1TRM_TRM7
mVREFTRM1_TRM10                         equ        mVREF1TRM_TRM0
mVREFTRM1_TRM11                         equ        mVREF1TRM_TRM1
mVREFTRM1_TRM12                         equ        mVREF1TRM_TRM2
mVREFTRM1_TRM13                         equ        mVREF1TRM_TRM3
mVREFTRM1_TRM14                         equ        mVREF1TRM_TRM4
mVREFTRM1_TRM15                         equ        mVREF1TRM_TRM5
mVREFTRM1_TRM16                         equ        mVREF1TRM_TRM6
mVREFTRM1_TRM17                         equ        mVREF1TRM_TRM7
VREFSC1                                 equ        VREF1SC
VREFSC1_MODE10                          equ        VREF1SC_MODE0
VREFSC1_MODE11                          equ        VREF1SC_MODE1
VREFSC1_VREFST1                         equ        VREF1SC_VREFST
VREFSC1_VREFEN1                         equ        VREF1SC_VREFEN
mVREFSC1_MODE10                         equ        mVREF1SC_MODE0
mVREFSC1_MODE11                         equ        mVREF1SC_MODE1
mVREFSC1_VREFST1                        equ        mVREF1SC_VREFST
mVREFSC1_VREFEN1                        equ        mVREF1SC_VREFEN
VREFTRM2                                equ        VREF2TRM       
VREFTRM2_TRM20                          equ        VREF2TRM_TRM0  
VREFTRM2_TRM21                          equ        VREF2TRM_TRM1  
VREFTRM2_TRM22                          equ        VREF2TRM_TRM2  
VREFTRM2_TRM23                          equ        VREF2TRM_TRM3  
VREFTRM2_TRM24                          equ        VREF2TRM_TRM4  
VREFTRM2_TRM25                          equ        VREF2TRM_TRM5  
VREFTRM2_TRM26                          equ        VREF2TRM_TRM6  
VREFTRM2_TRM27                          equ        VREF2TRM_TRM7  
mVREFTRM2_TRM20                         equ        mVREF2TRM_TRM0 
mVREFTRM2_TRM21                         equ        mVREF2TRM_TRM1 
mVREFTRM2_TRM22                         equ        mVREF2TRM_TRM2 
mVREFTRM2_TRM23                         equ        mVREF2TRM_TRM3 
mVREFTRM2_TRM24                         equ        mVREF2TRM_TRM4 
mVREFTRM2_TRM25                         equ        mVREF2TRM_TRM5 
mVREFTRM2_TRM26                         equ        mVREF2TRM_TRM6 
mVREFTRM2_TRM27                         equ        mVREF2TRM_TRM7 
VREFSC2                                 equ        VREF2SC        
VREFSC2_MODE20                          equ        VREF2SC_MODE0  
VREFSC2_MODE21                          equ        VREF2SC_MODE1  
VREFSC2_VREFST2                         equ        VREF2SC_VREFST 
VREFSC2_VREFEN2                         equ        VREF2SC_VREFEN 
mVREFSC2_MODE20                         equ        mVREF2SC_MODE0 
mVREFSC2_MODE21                         equ        mVREF2SC_MODE1 
mVREFSC2_VREFST2                        equ        mVREF2SC_VREFST
mVREFSC2_VREFEN2                        equ        mVREF2SC_VREFEN
NVVREFTRM1                              equ        NVVREF1TRM
NVVREFTRM1_TRM10                        equ        NVVREF1TRM_TRM0
NVVREFTRM1_TRM11                        equ        NVVREF1TRM_TRM1
NVVREFTRM1_TRM12                        equ        NVVREF1TRM_TRM2
NVVREFTRM1_TRM13                        equ        NVVREF1TRM_TRM3
NVVREFTRM1_TRM14                        equ        NVVREF1TRM_TRM4
NVVREFTRM1_TRM15                        equ        NVVREF1TRM_TRM5
NVVREFTRM1_TRM16                        equ        NVVREF1TRM_TRM6
NVVREFTRM1_TRM17                        equ        NVVREF1TRM_TRM7
mNVVREFTRM1_TRM10                       equ        mNVVREF1TRM_TRM0
mNVVREFTRM1_TRM11                       equ        mNVVREF1TRM_TRM1
mNVVREFTRM1_TRM12                       equ        mNVVREF1TRM_TRM2
mNVVREFTRM1_TRM13                       equ        mNVVREF1TRM_TRM3
mNVVREFTRM1_TRM14                       equ        mNVVREF1TRM_TRM4
mNVVREFTRM1_TRM15                       equ        mNVVREF1TRM_TRM5
mNVVREFTRM1_TRM16                       equ        mNVVREF1TRM_TRM6
mNVVREFTRM1_TRM17                       equ        mNVVREF1TRM_TRM7
NVVREFTRM2                              equ        NVVREF2TRM      
NVVREFTRM2_TRM20                        equ        NVVREF2TRM_TRM0 
NVVREFTRM2_TRM21                        equ        NVVREF2TRM_TRM1 
NVVREFTRM2_TRM22                        equ        NVVREF2TRM_TRM2 
NVVREFTRM2_TRM23                        equ        NVVREF2TRM_TRM3 
NVVREFTRM2_TRM24                        equ        NVVREF2TRM_TRM4 
NVVREFTRM2_TRM25                        equ        NVVREF2TRM_TRM5 
NVVREFTRM2_TRM26                        equ        NVVREF2TRM_TRM6 
NVVREFTRM2_TRM27                        equ        NVVREF2TRM_TRM7 
mNVVREFTRM2_TRM20                       equ        mNVVREF2TRM_TRM0
mNVVREFTRM2_TRM21                       equ        mNVVREF2TRM_TRM1
mNVVREFTRM2_TRM22                       equ        mNVVREF2TRM_TRM2
mNVVREFTRM2_TRM23                       equ        mNVVREF2TRM_TRM3
mNVVREFTRM2_TRM24                       equ        mNVVREF2TRM_TRM4
mNVVREFTRM2_TRM25                       equ        mNVVREF2TRM_TRM5
mNVVREFTRM2_TRM26                       equ        mNVVREF2TRM_TRM6
mNVVREFTRM2_TRM27                       equ        mNVVREF2TRM_TRM7

; **** 27.11.2009 113038
; EOF
