include "..\MC9S08LH64.inc"
include "srec.inc"
include "..\hcs08.inc"

ORG RAMStart 
c1: dw  1000 bswap 2 ;03E8h
c2: dw	400 bswap 2	 ;0190h
res: dw 0


ORG ROMStart
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
            STA SRS 
            BRA    mainLoop
			spurious:				; placed here so that security value
			NOP			; does not change all the time.
			RTI

ORG	$FFFA

			dw  spurious bswap 2			;
			dw  spurious bswap 2			; SWI
			dw  _Startup bswap 2			; Reset