47      	if(SCI1S1_RDRF)
001a07:   0B244D BRCLR 5,0x24,*+80 isrSCI1rec+0x51 (0x1a57)
49      		if (datarx == 0)
001a0a:   320102 LDHX 0x0102
001a0d:   260E BNE *+16 isrSCI1rec+0x17 (0x1a1d)
51      			if (SCI1D == 0x02)
001a0f:   B627 LDA 0x27
001a11:   A102 CMP #0x02
001a13:   2642 BNE *+68 isrSCI1rec+0x51 (0x1a57)
52      				datarx = 1;
001a15:   AE01 LDX #0x01
001a17:   8C CLRH
001a18:   960102 STHX 0x0102
72      }
001a1b:   8A PULH
001a1c:   80 RTI  0x000000 (0)
56      			if (SCI1D == 0x02)
001a1d:   B627 LDA 0x27
001a1f:   A102 CMP #0x02
001a21:   2607 BNE *+9 isrSCI1rec+0x24 (0x1a2a)
57      				i=0;
001a23:   5F CLRX
001a24:   8C CLRH
001a25:   960100 STHX 0x0100
72      }
001a28:   8A PULH
57      				i=0;
001a29:   80 RTI  0x000000 (0)
58      			else if(i < 5)
001a2a:   320100 LDHX 0x0100
001a2d:   650005 CPHX #0x0005
001a30:   240F BCC *+17 isrSCI1rec+0x3b (0x1a41)
59      				buf[i++] = SCI1D;
001a32:   89 PSHX
001a33:   AF01 AIX #1
001a35:   960100 STHX 0x0100
001a38:   8C CLRH
001a39:   B627 LDA 0x27
001a3b:   88 PULX
001a3c:   D70104 STA 260,X
72      }
001a3f:   8A PULH
59      				buf[i++] = SCI1D;
001a40:   80 RTI  0x000000 (0)
62      				datarx = 0;
001a41:   5F CLRX
001a42:   8C CLRH
001a43:   960102 STHX 0x0102
63      				i = 0;
001a46:   960100 STHX 0x0100
64      				if (SCI1D == 0x03)
001a49:   B627 LDA 0x27
001a4b:   A103 CMP #0x03
001a4d:   2608 BNE *+10 isrSCI1rec+0x51 (0x1a57)
66      					buf[5] = '\0';
001a4f:   CF0109 STX 0x0109
67      					dataready = 1;
001a52:   A601 LDA #0x01
001a54:   C7010A STA 0x010A
72      }
001a57:   8A PULH
001a58:   80 RTI  0x000000 (0)
1547    void _IMUL_STAR08(int i, ...) {
001a59:   A7FE AIS #-2
1554                    STHX     1,SP
001a5b:   9EFF01 STHX 1,SP
001a5e:   95 TSX
1555                    LDA      i:1
001a5f:   E605 LDA 5,X
1556                    LDX      j:1
001a61:   EE01 LDX 1,X
1557                    MUL
001a63:   42 MUL
1558                    PSHA
001a64:   87 PSHA
1559                    PSHX
001a65:   89 PSHX
001a66:   95 TSX
1560                    LDA      i:1
001a67:   E607 LDA 7,X
1561                    LDX      j:0
001a69:   EE02 LDX 2,X
1562                    MUL
001a6b:   42 MUL
001a6c:   95 TSX
1563                    ADD      1,SP
001a6d:   FB ADD ,X
1564                    PSHA
001a6e:   87 PSHA
1565                    LDA      i:0
001a6f:   E606 LDA 6,X
1566                    LDX      j:1
001a71:   EE03 LDX 3,X
1567                    MUL
001a73:   42 MUL
001a74:   95 TSX
1568                    ADD      1,SP
001a75:   FB ADD ,X
1569                    STA      j:0
001a76:   E703 STA 3,X
1570                    AIS      #2
001a78:   A702 AIS #2
1571                    PULA
001a7a:   86 PULA
1572                    STA      j:1
001a7b:   E704 STA 4,X
1573                    PULH
001a7d:   8A PULH
1574                    PULX
001a7e:   88 PULX
1575                    RTS  ! {A + X}, {H + SR}
001a7f:   81 RTS  0x000000 (0)