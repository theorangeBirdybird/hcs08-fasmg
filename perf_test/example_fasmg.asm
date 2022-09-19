; BPC-MIC domaci uloha c.1
; Prijmeni a jmeno autora: Navratil Jan
; VUT Login autora: xnavra66
; ID autora: 221006
;
;*******************************************************************
;* This stationery serves as the framework for a user application. *
;* For a more comprehensive program that demonstrates the more     *
;* advanced functionality of this processor, please see the        *
;* demonstration applications, located in the examples             *
;* subdirectory of the "Freescale CodeWarrior for HC08" program    *
;* directory.                                                      *
;*******************************************************************

; Include derivative-specific definitions
            include '..\hcs08.inc'
			INCLUDE '..\derivative.inc'
			include '..\srec.inc'   
;
; export symbols
;
            ABSENTRY _Startup
;
; variable/data section
;
            ORG    RAMStart         ; Insert your data definition here
c1: DC.W   $3456
c2: DC.W   $789 
vysl: DS.W   1 
;
; code section
;
            ORG    ROMStart
            

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI			; enable interrupts

mainLoop:
            ; Insert your code here
            ; Hodnotu prommenych c1 a c2 je nutne zadat pres prohlizec prommenych pri debugu
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
			
			AIS #2     
            
            feed_watchdog
            BRA    mainLoop
			
;**************************************************************
;* spurious - Spurious Interrupt Service Routine.             *
;*             (unwanted interrupt)                           *
;**************************************************************

spurious:				; placed here so that security value
			NOP			; does not change all the time.
			RTI

;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************

            ORG	$FFFA

			DC.W  spurious			;
			DC.W  spurious			; SWI
			DC.W  _Startup			; Reset
