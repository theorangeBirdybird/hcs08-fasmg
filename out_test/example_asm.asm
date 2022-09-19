;*******************************************************************
;* This stationery serves as the framework for a user application. *
;* For a more comprehensive program that demonstrates the more     *
;* advanced functionality of this processor, please see the        *
;* demonstration applications, located in the examples             *
;* subdirectory of the "Freescale CodeWarrior for HC08" program    *
;* directory.                                                      *
;*******************************************************************

; export symbols
include "..\hcs08.inc"
include "..\derivative.inc"
include "cw.inc"

; variable/data section 
ORG $0060
; Insert here your data definition. For demonstration, temp_byte is used.
c1: dw   $3456 bswap 2
c2: dw   $789 bswap 2
vysl: dw  0h

; code section

; this assembly routine is called the C/C++ application
example_asm:
 			LDX c1+1
			LDA #4
			MUL
			PSHA
			PSHX
			LDX c1
			LDA #4
			MUL
			ADD 1,SP
			STA 1,SP	;4*c1
			
			LDA 2,SP
			SUB c2+1
			STA 2,SP
			LDA 1,SP
			SBC c2
			STA 1,SP	;4*c1-c2
			
			CLRH
			LDA 1,SP
			LDX	#5
			DIV
			STA vysl
			LDA 2,SP
			DIV
			STA	vysl+1 ;(4*c1-c2)/5
			LDHX vysl
			
			AIS #2
			
			RTS
                   ; return to caller
