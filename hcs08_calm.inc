;include file implementing HCS08 instruction set using CALM instructions
define HCS
;;;;supporting macro for HCS.rel function
calminstruction HCS.addr_check asigned*,aopcode*,aoffset*,aoperand
	check	0d <= asigned & asigned <= 255d
	jno	rangeErr
	check 	aoffset = 2
	jno check3
	arrange cmd,=db aopcode,asigned
	jump ending
check3:check	0d <= aoperand & aoperand <= 255d
		jno addrErr
	check aoffset = 3
		jno check4	
		arrange cmd,=db aopcode,aoperand,asigned
		jump ending
check4: check aoffset = 4
		jno paramErr
		compute bigend, (aopcode and 0FFh)
		arrange cmd,=db 09Eh,bigend
		assemble cmd
		arrange cmd,=db aoperand,asigned
		jump ending
addrErr:arrange cmd,=err "Address out of valued range"
	jump ending
paramErr:arrange cmd,=err "Incorrect parameter passed to HCS.addr_check macro"
	jump ending
rangeErr:	arrange cmd,=err "Target address not in range"
ending:	assemble cmd
end calminstruction

;;;addressing modes macros
calminstruction HCS.rel arel,aopcode,aoffset,aoperand
	match *avalue,arel
	jno label
	check avalue < aoffset
	jno unsigned
	compute signed,0FFh + avalue + (1 - aoffset)
	call HCS.addr_check,signed,aopcode,aoffset,aoperand
	exit 
unsigned: compute signed,avalue - aoffset;
	call HCS.addr_check,signed,aopcode,aoffset,aoperand
	exit
label: match avalue,arel
	jno ParsErr
	match *,avalue
	jno unsigned_label
	compute	signed,0FFh + (1-aoffset)
	call HCS.addr_check,signed,aopcode,aoffset,aoperand
	exit
unsigned_label: check avalue - $ >= aoffset
	jno signed_branch
	compute	signed, avalue - $ - aoffset
	call HCS.addr_check,signed,aopcode,aoffset,aoperand
	exit
signed_branch: compute signed,0FFh + avalue + (1-aoffset) - $ 
	call HCS.addr_check,signed,aopcode,aoffset,aoperand
	exit
ParsErr:	arrange cmd,=err "Error parsing instruction with relative address"
ending:assemble cmd
end calminstruction

calminstruction HCS.imm avalue,areg,aopcode*
	match ,areg
	jno ParsErr
	check	0d <= avalue & avalue <= 255d
	jno negat
	arrange	cmd,=db aopcode,avalue
	jump ending
negat: check -128d <= avalue & avalue <= 127d
	jno rangeErr
	compute signed,0FFh + avalue + 1
	arrange cmd,=db aopcode,signed
	jump ending
rangeErr:	arrange cmd,=err "Constant value not in range"
	jump ending
ParsErr:	arrange cmd,=err "Invalid addressing mode - HCS.imm has only one parameter"
ending:assemble cmd
end calminstruction

;;instrucion macros

;;Branch
irp mnem, BRA, BRN, BHI, BLS, BCC, BCS, BNE, BEQ, \
		BHCC, BHCS, BPL, BMI, BMC, BMS, BIL, BIH
calminstruction mnem? operand,reg
	compute opcode, 020h + % - 1
	arrange offset,02h
	call HCS.rel,operand,opcode,offset
end calminstruction
end irp

irp mnem, RTI?, RTS?, BGND?, SWI?, TAP?, TPA?, PULA?, PSHA?, PULX?, PSHX?, PULH?, PSHH?, CLRH?
calminstruction mnem
	arrange cmd,=db (080h + % - 1)
	assemble cmd
end calminstruction
end irp

irp mnem, STOP?, WAIT?
calminstruction mnem
	arrange cmd,=db (08Eh + % - 1)
	assemble cmd
end calminstruction
end irp

irp mnem, TAX?, CLC?, SEC?, CLI?, SEI?, RSP?, NOP?
calminstruction mnem
	arrange cmd,=db (097h + % - 1)
	assemble cmd
end calminstruction
end irp

irp <mnem,opcode>, AIS?, 0A7h, AIX?, 0AFh
calminstruction mnem operand,reg
	match #value,operand ;HCS.imm
	jno ParsErr
	compute aopcode,opcode
	call HCS.imm,value,reg,aopcode
	exit
ParsErr:	arrange cmd,=err "Invalid addressing mode"
assemble cmd
end calminstruction
end irp



