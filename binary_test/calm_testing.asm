include "..\hcs08_calm.inc"

STOP
WAIT
AIS #42
HCS.addr_check 042h,042h,2,042h
HCS.addr_check 043h,043h,3,043h
HCS.addr_check 044h,09E68h,4,044h
HCS.rel 044h,09E68h,4,044h

		bra		*0
		brn		*0
loop:	bhi		loop+1		
loop2: 	bls 	loop2+2
loop3:	bcc		loop3+3	
		bih     *-1