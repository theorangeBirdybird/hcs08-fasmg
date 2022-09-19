define CW
format binary as 'txt'

virtual at 0
	CW.digits:: db '0123456789ABCDEF'
end virtual

macro CW.byte value
	local digit
	load digit:byte from CW.digits:(value) shr 4
	db digit
	load digit:byte from CW.digits:(value) and 0Fh
	db digit
end macro

macro CW.seg address:0
	virtual at address	
end macro

macro CW.endseg
	local code,address,size,bajt
	code:: address = $$
			size = $-$$
	end virtual
	if address = 0 & size <> 0
		db 9,'DC.B '
	end if
	repeat size
		db '$'
		load bajt:byte from code:address
		CW.byte bajt
		if size <> %
			db ','
		else
			db 13,10
		end if
		address=address+1
	end repeat
end macro

macro ORG? address
	if $ <> address
		CW.endseg
		local low,high
		low = address and 0FFh
		high = address shr 8
		db 9,'ORG $'
		CW.byte high
		CW.byte low
		db 13,10,9,'DC.B '
		CW.seg address
	end if
end macro

CW.seg

postpone
		CW.endseg
end postpone
