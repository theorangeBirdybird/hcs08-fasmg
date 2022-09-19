include 'MC9S08LH64.inc'

macro feed_watchdog
	STA SRS
end macro

macro DC.B value
	db	value
end macro

macro DS.B times
	repeat times
		db	0
	end repeat
end macro

macro DC.W value
	db value bswap 2
end macro

macro DS.W times
	repeat times
		dw 0
	end repeat
end macro
	