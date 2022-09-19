include "..\hcs08.inc"
include "..\derivative.inc"
include "cw.inc"

galois_lsfr2:
			pshh
			pula
			lsra
			rorx
			bcc nic2
			eor #10110100b
nic2:           
			psha
			pulh
			rts