
define SREC
format binary as 's19'

virtual at 0
	SREC.digits:: db '0123456789ABCDEF'
end virtual

macro SREC.byte value
	SREC.checksum = (SREC.checksum + (value)) and 0FFh
	local digit
	load digit:byte from SREC.digits:(value) shr 4
	db digit
	load digit:byte from SREC.digits:(value) and 0Fh
	db digit
end macro

macro SREC.line length,address,type,value
	local digit
	SREC.checksum = 0
	db 'S'
	load digit:byte from SREC.digits:(type) and 0Fh   ;SREC.byte type
	db digit
	SREC.byte (length+3)	;length+address_length(2)+checksum_length(1)
	SREC.byte (address) shr 8
	SREC.byte (address) and 0FFh
	
	SREC.data = value
	repeat length
		SREC.byte SREC.data and 0FFh
		SREC.data = SREC.data shr 8
	end repeat
	SREC.data = (-SREC.checksum-1) and 0FFh ;pro tvar v 1. doplnku
	SREC.byte SREC.data
	db 13,10
end macro

macro SREC.seg address:0
	virtual at address
end macro

macro SREC.endseg
	local code,address,high,size,bytes
	code:: address = $$
	       size = $-$$
	end virtual
	while size
		if size>20h
			load bytes:20h from code:address
			SREC.line 20h,address and 0FFFFh,1,bytes
			address = address + 20h
			size = size - 20h
		else
			load bytes:size from code:address
			SREC.line size,address and 0FFFFh,1,bytes
			break
		end if
	end while
end macro

macro ORG? address
	if $ <> address
		SREC.endseg
		SREC.seg address
	end if
end macro

SREC.entry = 0

macro ABSENTRY address
	SREC.entry = address
end macro

SREC.line lengthof __source__,0,0,__source__
SREC.seg

postpone
	SREC.endseg
	SREC.line 0,SREC.entry,9,0
end postpone
