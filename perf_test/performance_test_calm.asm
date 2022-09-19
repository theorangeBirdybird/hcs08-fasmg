;this file is used for compilation benchmarking. Not for executing
include '..\hcs08_calm.inc'
include '..\derivative.inc'
include '..\srec.inc'

	ABSENTRY _Startup
	ORG ROMStart
_Startup:
repeat 1000
        bra     *-1
        brn     *-2
        bhi     *-3
        bls     *-4
        bcc     *-5
        bcs     *-6
        bne     *-7
        beq     *-8
        bhcc    *-9
        bhcs    *-10
        bpl     *-11
        bmi     *-12
        bmc     *-13
        bms     *-14
        bil     *-15
        bih     *-16
				
		rti
		rts
		bgnd
		tap
		tpa
		pula
		psha
		pulx
		pshx
		pulh
		pshh
		clrh
		
		tax
        clc
        sec
        cli
        sei
        rsp
        nop

		stop
		wait
		
		aix     #34
		
        ais     #-16
end repeat
spurious:				; placed here so that security value
			NOP			; does not change all the time.
			RTI

            ORG	$FFFA

			DC.W  spurious			;
			DC.W  spurious			; SWI
			DC.W  _Startup			; Reset