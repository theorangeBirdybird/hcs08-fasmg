;example testing some of the HCS08 operations
include "hcs08.inc"
RAMEnd equ   $00000FFF
;This program performs following function (4*c1-c2)/5,
;where c1 and c2 are variables defined at the end of this outputted segment
;the result is written to variable res.

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI			; enable interrupts

mainLoop:
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
			STA res
			LDA 2,SP
			DIV
			STA	res+1 ;(4*c1-c2)/5
			
			AIS #2   
            
            BRA    mainLoop
c1: dw  1000 bswap 2 ;03E8h
c2: dw	400 bswap 2	 ;0190h
res: rw 1