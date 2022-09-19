;include file for basic implementation of HCS08 instruction set
define HCS
;;;;supporting macro for rel function
macro HCS.addr_check	asigned*,aopcode*,aoffset*,aoperand
	if	0d <= asigned & asigned <= 255d
		if aoffset = 2
			db aopcode,asigned
		else if aoffset = 3
			if	0d <= aoperand & aoperand <= 255d
				db aopcode,aoperand,asigned
			else
				err "Address out of valued range"
			end if
		else if aoffset = 4
			if	0d <= aoperand & aoperand <= 255d
				dw (aopcode) bswap 2
				db aoperand,asigned
			else 
				err "Address out of valued range"
			end if
		else 
			err "Incorrect parameter passed to HCS.addr_check macro"
		end if
	else
		err "Target address not in range"
	end if
end macro

;;;Adressing modes macros
macro HCS.rel arel*,aopcode*,aoffset*,aoperand
	local signed,avalue
	rmatch *avalue,arel
		if avalue < aoffset
			signed = 0FFh + avalue + (1 - aoffset)
			HCS.addr_check signed,aopcode,aoffset,aoperand
		else 
			signed = avalue - aoffset;
			HCS.addr_check signed,aopcode,aoffset,aoperand
		end if
	else rmatch avalue,arel
		rmatch *,avalue
			signed = 0FFh + (1-aoffset)
			HCS.addr_check signed,aopcode,aoffset,aoperand
		else
			if avalue - $ >= aoffset
				signed = avalue - $ - aoffset
				HCS.addr_check signed,aopcode,aoffset,aoperand
			else
				signed = 0FFh + avalue + (1-aoffset) - $ 
				HCS.addr_check signed,aopcode,aoffset,aoperand
			end if
		end rmatch
	else 
		err "Error parsing instruction with relative address"
	end rmatch
end macro

macro HCS.imm avalue,areg,aopcode*
	rmatch ,areg
		if	0d <= avalue & avalue <= 255d
			db aopcode,avalue
		else if -128d <= avalue & avalue <= 127d
			local signed
			 signed =  0FFh + avalue + 1
			 db aopcode,signed
		else
			err "Constant value not in range"
		end if
	else 
		err "Invalid addressing mode - HCS.imm has only one parameter"
	end rmatch
end macro

macro HCS.imm16 avalue,areg,aopcode*
	rmatch ,areg
		if	0d <= avalue & avalue <= 65535d
			db aopcode
			dw (avalue) bswap 2
		else if -32768d <= avalue & avalue <= 32767d
			local signed
			 signed =  0FFFFh + avalue + 1
			 db aopcode
			 dw (signed) bswap 2
		else
			err "Constant value not in range"
		end if
	else 
		err "Invalid addressing mode - HCS.imm has only one parameter"
	end rmatch
end macro

macro HCS.ix areg, aopcode*
	rmatch =X?,areg
		db aopcode
	else
		err "Invalid addressing mode - Not HCS.ix"
	end rmatch
end macro

macro HCS.dirext avalue, aopcode*
				if	0d <= avalue & avalue <= 255d ;DIR
					db aopcode+010h,avalue
				else if 0d <= avalue & avalue <= 65535d ;EXT
					db aopcode + 020h
					dw (avalue) bswap 2
				else 
					err "Address value not in range"
				end if
end macro

macro HCS.dir avalue,aopcode*
				if	0d <= avalue & avalue <= 255d ;DIR
					db aopcode,avalue
				else 
					err "Address value not in range"
				end if
end macro

macro HCS.ix12 avalue, aopcode*
				if 0d = avalue	;HCS.ix
					db aopcode+050h	
				else if	0d < avalue & avalue <= 255d ;HCS.ix1
					db aopcode + 040h,avalue
				else if 0d <= avalue & avalue <= 65535d ;HCS.ix2
					db aopcode + 030h
					dw (avalue) bswap 2
				else 
					err "Address value not in range"
				end if
end macro

macro HCS.ix1 avalue, aopcode*
				if	0d <= avalue & avalue <= 255d ;HCS.ix1
					db aopcode,avalue
				else 
					err "Address value not in range"
				end if
end macro

macro HCS.sp1 avalue,aopcode*
				if	0d <= avalue & avalue <= 255d ;HCS.sp1
					dw (aopcode) bswap 2
					db avalue
				else 
					err "Address value not in range"
				end if
end macro

macro HCS.sp12 avalue,aopcode*
				if	0d <= avalue & avalue <= 255d ;HCS.sp1
					dw (aopcode + 09E40h) bswap 2
					db avalue
				else if 0d <= avalue & avalue <= 65535d ;HCS.sp2
					dw (aopcode + 09E30h)bswap 2
					dw (avalue) bswap 2
				else 
					err "Address value not in range"
				end if
end macro

;;;instrucion macros

;;Bit-Manipulation
irp mnem, BRSET, BRCLR
macro mnem? num*, address*,arel*
	if 0d <= num & num <= 7d
		if	0d <= address & address <= 255d 
			local signed,value
			rmatch *value,arel
				if value <= 2
					signed = 0FFh + value - 2;(+1-3)
					if	0d <= signed & signed <= 255d
						db 2*num+%-1,address,signed
					else
						err "Target address not in range"
					end if
				else 
					signed = value - 3;
					if	0d <= signed & signed <= 255d
						db 2*num+%-1,address,signed
					else
						err "Target address not in range"
					end if
				end if
			else rmatch value,arel
				rmatch *,arel
					db 2*num+%-1,address,0FDh
				else
					if value - $ >= 3
						signed = value - $ - 3
						if	0d <= signed & signed <= 255d
							db 2*num+%-1,address,signed
						else
							err "Target address not in range"
						end if	
					else
						signed = 0FFh + value - 2 - $ ;(+1-3)
						if	0d <= signed & signed <= 255d
							db 2*num+%-1,address,signed
						else
							err "Target address not in range"
						end if			
					end if
				end rmatch
			else
				err "Error parsing instruction with relative address"
			end rmatch
		else
			err "DIR Address value not in range"
		end if
	else
		err "Bit number out of range"
	end if
end macro
end irp

irp mnem, BSET, BCLR
macro mnem? num*, address*
	if 0d <= num & num <= 7d
		if 0d <= address & address <= 255d
			db 2*num+%+00Fh,address
		else
			err "Address value out of range"
		end if
	else
		err "Bit number out of range"
	end if
end macro
end irp
;;Branch
irp mnem, BRA, BRN, BHI, BLS, BCC, BCS, BNE, BEQ, \
		BHCC, BHCS, BPL, BMI, BMC, BMS, BIL, BIH
macro mnem? operand
	HCS.rel operand,020h + % - 1,2
end macro
end irp

irp mnem, BHS, BLO
macro mnem? operand
	HCS.rel operand,024h + % - 1,2
end macro
end irp
;;Read-Modify-Write
irp <mnem,opcode>, NEG, 030h, COM, 033h, LSR, 034h, ROR, 036h, ASR, 037h, LSL, 038h, ASL, 038h,\
				ROL, 039h, DEC, 03Ah
macro mnem? operand,reg
	local value
	rmatch ,operand ;HCS.ix
		HCS.ix reg,opcode+040h	
	else  rmatch value,operand
			rmatch ,reg
				HCS.dir value, opcode	
			else rmatch =X?,reg			
				HCS.ix1 value, opcode+030h
			else rmatch =SP?,reg
				HCS.sp1 value, opcode+09E30h
			else
				err "Invalid addressing mode - Unknown operand"
			end rmatch
	end rmatch	
end macro

macro mnem#A?
	db opcode + 010h
end macro

macro mnem#X?
	db opcode + 020h
end macro
end irp

;;has to be done separately becauese of unique syntax
macro DBNZ? operand,second*,third
	rmatch ,operand
		rmatch =X?,second ;IX
			HCS.rel third,07Bh,2
		else
			err "Incorect parameters - DBNZ - second parameter must be X, when first is empty"			
		end rmatch
	else rmatch =X?,second ;IX
		HCS.rel third,06Bh,3,operand
	else rmatch =SP?, second
		HCS.rel third,09E6Bh,4,operand	;HCS.sp1
	else rmatch ,third
		HCS.rel second,03Bh,3,operand	;DIR
	else
		err "Incorect parameters"
	end rmatch
end macro

irp <mnem,opcode>, DBNZA, 04Bh, DBNZX, 05Bh
macro mnem? operand*
	HCS.rel operand,opcode,2
end macro
end irp

irp <mnem,opcode>, INC, 03Ch, TST, 03Dh, CLR, 03Fh
macro mnem? operand,reg
	local value
	rmatch ,operand ;HCS.ix
		HCS.ix reg,opcode+040h	
	else  rmatch value,operand
			rmatch ,reg
				HCS.dir value, opcode	
			else rmatch =X?,reg			
				HCS.ix1 value, opcode+030h
			else rmatch =SP?,reg
				HCS.sp1 value, opcode+09E30h
			else
				err "Invalid addressing mode - Unknown operand"
			end rmatch
	end rmatch	
end macro

macro mnem#A?
	db opcode + 010h
end macro

macro mnem#X?
	db opcode + 020h
end macro
end irp

;;has to be done separately becauese of unique syntax
macro CBEQ? operand*,second*,third
	rmatch =X?=+,operand ;HCS.ix+
		HCS.rel second,071h,2					
	else rmatch =X?=+,second ;HCS.ix+1
		HCS.rel third,061h,3,operand
	else rmatch =SP?, second
		HCS.rel third,09E61h,4,operand	;HCS.sp1
	else rmatch ,third
		HCS.rel second,031h,3,operand	;DIR
	else
		err "Incorect parameters"
	end rmatch
end macro

irp <mnem,opcode>, CBEQA, 041h, CBEQX, 051h
macro mnem? operand*,arel*
	local value
	rmatch #value,operand
		if	0d <= value & value <= 255d 
			HCS.rel arel,opcode,3,operand
		else
			err "HCS.imm value not in range"
		end if
	else
		err "Wrong syntax"
	end rmatch
end macro
end irp

irp <mnem,opcode>, MUL, 042h, DIV, 052h, NSA, 062h, DAA, 072h
macro mnem? 
	db opcode
end macro
end irp

macro MOV? source*,dest*
	local value
	rmatch =X?=+,dest ;DIRHCS.ix+
		HCS.dir source,05Eh
	else rmatch =X?=+,source ;HCS.ix+DIR
		HCS.dir dest,07Eh
	else rmatch #value,source ;HCS.immDIR
		if	0d <= dest & dest <= 255d 
			if	0d <= value & value <= 255d
				db 06Eh,value,dest
			else if -128d <= avalue & avalue <= 127d
				local signed
				signed =  0FFh + avalue + 1
				db 06Eh,signed,dest
			else
				err "Constant value not in range"
			end if
		else
			err "Adress value not in range"
		end if
	else 
		if	0d <= source & source <= 255d 
			if	0d <= dest & dest <= 255d
				db 04Eh,source,dest
			else
				err "Target address not in range"
			end if
		else
			err "Source address not in range"
		end if
	end rmatch
end macro
;;Control
irp mnem, RTI?, RTS?, BGND?, SWI?, TAP?, TPA?, PULA?, PSHA?, PULX?, PSHX?, PULH?, PSHH?, CLRH?
macro mnem
	db 080h + % - 1
end macro
end irp

irp mnem, STOP?, WAIT? 
macro mnem 
	db 08Eh + % - 1	
end macro
end irp

irp mnem, BGE?, BLT?, BGT?, BLE? 
macro mnem operand
	HCS.rel operand,090h + % - 1,2
end macro
end irp

irp mnem,  TXS?, TSX?
macro mnem 
	db 094h + % - 1	
end macro
end irp

irp mnem,  TAX?, CLC?, SEC?, CLI?, SEI?, RSP?, NOP?
macro mnem 
	db 097h + % - 1
end macro
end irp

macro TXA? 
	db 09Fh	
end macro

;;Register/Memory operators
macro BSR? operand,reg
		HCS.rel operand,0ADh,2	;REL
end macro

irp <mnem,opcode>, AIS?, 0A7h, AIX?, 0AFh
macro mnem operand,reg
	local value
	rmatch #value,operand ;HCS.imm
		HCS.imm value,reg,opcode
	else
		err "Invalid adressing mode for this instrucion"
	end rmatch
end macro
end irp


irp <mnem,opcode>, SUB?, 0A0h, CMP?, 0A1h, SBC?, 0A2h, CPX?, 0A3h, AND?, 0A4h, \
	   BIT?, 0A5h, LDA?, 0A6h, EOR?, 0A8h, ADC?, 0A9h, ORA?, 0AAh, ADD?, 0ABh, LDX?, 0AEh
macro mnem operand,reg
	local value
	rmatch #value,operand ;HCS.imm
		HCS.imm value,reg,opcode
	else rmatch  ,reg
		rmatch =X?,operand
			db opcode+050h
		else
			HCS.dirext operand, opcode	
		end rmatch
	else rmatch =X?,reg
		rmatch ,operand
			HCS.ix12 0d, opcode
		else
			HCS.ix12 operand, opcode
		end rmatch
	else rmatch =SP?,reg
		rmatch ,operand
			HCS.sp12 0d, opcode
		else
			HCS.sp12 operand, opcode
		end rmatch
	else
		err "Invalid addressing mode - Unknown operand"	
	end rmatch	
end macro
end irp

irp <mnem,opcode>, STA?, 0A7h, STX?, 0AFh
macro mnem operand,reg
	local value
	rmatch ,operand ;HCS.ix
		HCS.ix reg,opcode+050h	
	else  rmatch value,operand
			rmatch ,reg
				HCS.dirext value, opcode	
			else rmatch =X?,reg			
				HCS.ix12 value, opcode
			else rmatch =SP?,reg
				HCS.sp12 value, opcode
			else
				err "Invalid addressing mode - Unknown operand"
			end rmatch
	end rmatch	
end macro
end irp

irp <mnem,opcode>, JMP?, 0ACh, JSR?, 0ADh
macro mnem operand,reg
	local value
	rmatch ,operand ;HCS.ix
		HCS.ix reg,opcode+050h	
	else  rmatch value,operand
			rmatch ,reg
				HCS.dirext value, opcode	
			else rmatch =X?,reg			
				HCS.ix12 value, opcode
			else
				err "Invalid addressing mode - Unknown operand"
			end rmatch
	end rmatch	
end macro
end irp

;;Has to be done separately becauese of unique positions in opcode map
macro LDHX? operand,reg
	local value
	rmatch #value,operand ;HCS.imm
		HCS.imm16 value,reg,045h
	else rmatch ,operand ;HCS.ix
		rmatch =X?,reg
			dw (09EAEh) bswap 2
		end rmatch
	else  rmatch value,operand
		rmatch ,reg
			if	0d <= value & value <= 255d ;DIR
				db 055h,value
			else if 0d <= value & value <= 65535d ;EXT
				db 032h
				dw (value) bswap 2
			else 
				err "Address value not in range"
			end if
		else rmatch =X?,reg			
			if	0d <= value & value <= 255d ;HCS.ix1
				dw (09ECEh) bswap 2
				db value
			else if 0d <= value & value <= 65535d ;HCS.ix2
				dw (09EBEh) bswap 2
				dw (value) bswap 2
			else 
				err "Address value not in range"
			end if	
		else rmatch =SP?,reg
			HCS.sp1 value,09EFEh
		else
			err "Invalid addressing mode - Unknown operand"
		end rmatch
	end rmatch	
end macro

macro STHX? operand,reg
	local value
	rmatch value,operand
		rmatch ,reg
			if	0d <= value & value <= 255d ;DIR
				db 035h,value
			else if 0d <= value & value <= 65535d ;EXT
				db 096h
				dw (value) bswap 2
			else 
				err "Address value not in range"
			end if
		else	rmatch =SP?,reg
			HCS.sp1 value,09EFFh
		else
			err "Invalid addressing mode - Unknown operand"
		end rmatch
	end rmatch	
end macro

macro CPHX? operand,reg
	local value
	rmatch #value,operand 
		HCS.imm16 value,reg,065h ;HCS.imm16
	else rmatch value,operand
		rmatch ,reg
			if	0d <= value & value <= 255d ;DIR
				db 075h,value
			else if 0d <= value & value <= 65535d ;EXT
				db 03Eh
				dw (value) bswap 2
			else 
				err "Address value not in range"
			end if
		else	rmatch =SP?,reg ;sp1
			HCS.sp1 value, 09EF3h
		else
			err "Invalid addressing mode - Unknown operand"
		end rmatch
	end rmatch	
end macro
