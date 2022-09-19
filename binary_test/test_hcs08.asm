        cpu     68HCS08
        page    0
		
		brset0  $12,*
        brset1  $12,*+1
        brset2  $12,*+2
        brset3  $12,*+3
        brset4  $12,*+4
        brset5  $12,*+5
        brset6  $12,*+6
        brset7  $12,*+7
        brclr0  $12,*+8
        brclr1  $12,*+9
        brclr2  $12,*+10
        brclr3  $12,*+11
        brclr4  $12,*+12
        brclr5  $12,*+13
        brclr6  $12,*+14
        brclr7  $12,*+15

        bset0   $12
        bset1   $12
        bset2   $12
        bset3   $12
        bset4   $12
        bset5   $12
        bset6   $12
        bset7   $12
        bclr0   $12
        bclr1   $12
        bclr2   $12
        bclr3   $12
        bclr4   $12
        bclr5   $12
        bclr6   $12
        bclr7   $12

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

        neg     $12
        nega
        negx
        neg     $12,x
        neg     ,x

        com     $12
        coma
        comx
        com     $12,x
        com     ,x

        lsr     $12
        lsra
        lsrx
        lsr     $12,x
        lsr     ,x

        ror     $12
        rora
        rorx
        ror     $12,x
        ror     ,x

        asr     $12
        asra
        asrx
        asr     $12,x
        asr     ,x

        lsl     $12
        lsla
        lslx
        lsl     $12,x
        lsl     ,x

        rol     $12
        rola
        rolx
        rol     $12,x
        rol     ,x

        dec     $12
        deca
        decx
        dec     $12,x
        dec     ,x

        inc     $12
        inca
        incx
        inc     $12,x
        inc     ,x

        tst     $12
        tsta
        tstx
        tst     $12,x
        tst     ,x

        clr     $12
        clra
        clrx
        clr     $12,x
        clr     ,x

        mul
        rti
        rts
        swi
        tax
        clc
        sec
        cli
        sei
        rsp
        nop
        stop
        wait
        txa

        sub     #$12
        sub     $12
        sub     $1234
        sub     $1234,x
        sub     $12,x
        sub     ,x

        cmp     #$12
        cmp     $12
        cmp     $1234
        cmp     $1234,x
        cmp     $12,x
        cmp     ,x

        cpx     #$12
        cpx     $12
        cpx     $1234
        cpx     $1234,x
        cpx     $12,x
        cpx     ,x

        sbc     #$12
        sbc     $12
        sbc     $1234
        sbc     $1234,x
        sbc     $12,x
        sbc     ,x

        and     #$12
        and     $12
        and     $1234
        and     $1234,x
        and     $12,x
        and     ,x

        bit     #$12
        bit     $12
        bit     $1234
        bit     $1234,x
        bit     $12,x
        bit     ,x

        lda     #$12
        lda     $12
        lda     $1234
        lda     $1234,x
        lda     $12,x
        lda     ,x

        sta     $12
        sta     $1234
        sta     $1234,x
        sta     $12,x
        sta     ,x

        eor     #$12
        eor     $12
        eor     $1234
        eor     $1234,x
        eor     $12,x
        eor     ,x

        adc     #$12
        adc     $12
        adc     $1234
        adc     $1234,x
        adc     $12,x
        adc     ,x

        ora     #$12
        ora     $12
        ora     $1234
        ora     $1234,x
        ora     $12,x
        ora     ,x

        add     #$12
        add     $12
        add     $1234
        add     $1234,x
        add     $12,x
        add     ,x

        jmp     $12
        jmp     $1234
        jmp     $1234,x
        jmp     $12,x
        jmp     ,x

        bsr     *
        jsr     $12
        jsr     $1234
        jsr     $1234,x
        jsr     $12,x
        jsr     ,x

        ldx     #$12
        ldx     $12
        ldx     $1234
        ldx     $1234,x
        ldx     $12,x
        ldx     ,x

        stx     $12
        stx     $1234
        stx     $1234,x
        stx     $12,x
        stx     ,x



		adc     #$55
        adc     $20
        adc     $2030
        adc     ,x
        adc     0,x
        adc     $40,x
        adc     $4050,x
        adc     ,sp
        adc     $40,sp
        adc     $4050,sp
		
        add     #$55
        add     $20
        add     $2030
        add     ,x
        add     $40,x
        add     $4050,x
        add     $40,sp
        add     $4050,sp

        aix     #34

        ais     #-16

        and     #$55
        and     $20
        and     $2030
        and     ,x
        and     $40,x
        and     $4050,x
        and     $40,sp
        and     $4050,sp

        asla
        aslx
        asl     $20
        asl     ,x
        asl     $40,x
        asl     $40,sp

        asra
        asrx
        asr     $20
        asr     ,x
        asr     $40,x
        asr     $40,sp

        bcc     *

        bclr    0,$20
        bclr    1,$20
        bclr    2,$20
        bclr    3,$20
        bclr    4,$20
        bclr    5,$20
        bclr    6,$20
        bclr    7,$20

        bcs     *

        beq     *

        bge     *

        bgt     *

        bhcc    *

        bhcs    *

        bhi     *

        bhs     *

        bih     *

        bil     *

        bit     #$55
        bit     $20
        bit     $2030
        bit     ,x
        bit     $40,x
        bit     $4050,x
        bit     $40,sp
        bit     $4050,sp

        ble     *

        blo     *

        bls     *

        blt     *

        bmc     *

        bmi     *

        bms     *

        bne     *

        bpl     *

        bra     *

        brclr   0,$20,*
        brclr   1,$20,*
        brclr   2,$20,*
        brclr   3,$20,*
        brclr   4,$20,*
        brclr   5,$20,*
        brclr   6,$20,*
        brclr   7,$20,*

        brn     *

        brset   0,$20,*
        brset   1,$20,*
        brset   2,$20,*
        brset   3,$20,*
        brset   4,$20,*
        brset   5,$20,*
        brset   6,$20,*
        brset   7,$20,*

        bset    0,$20
        bset    1,$20
        bset    2,$20
        bset    3,$20
        bset    4,$20
        bset    5,$20
        bset    6,$20
        bset    7,$20

        bsr     *

        cbeq    $20,*
        cbeq    x+,*
        cbeq    $40,x+,*
        cbeq    $40,sp,*

        cbeqa   #$55,*
        cbeqx   #$66,*

        clc

        cli

        clra
        clrx
        clrh
        clr     $20
        clr     ,x
        clr     $40,x
        clr     $40,sp

        cmp     #$55
        cmp     $20
        cmp     $2030
        cmp     ,x
        cmp     $40,x
        cmp     $4050,x
        cmp     $40,sp
        cmp     $4050,sp

        coma
        comx
        com     $20
        com     ,x
        com     $40,x
        com     $40,sp

        cphx    #$55aa
        cphx    $20

        cpx     #$55
        cpx     $20
        cpx     $2030
        cpx     ,x
        cpx     $40,x
        cpx     $4050,x
        cpx     $40,sp
        cpx     $4050,sp

        daa

        dbnza   *
        dbnzx   *

        dbnz    $20,*
        dbnz    ,x,*
        dbnz    $40,x,*
        dbnz    $40,sp,*

        deca
        decx
        dec     $20
        dec     ,x
        dec     $40,x
        dec     $40,sp

        div

        eor     #$55
        eor     $20
        eor     $2030
        eor     ,x
        eor     $40,x
        eor     $4050,x
        eor     $40,sp
        eor     $4050,sp

        inca
        incx
        inc     $20
        inc     ,x
        inc     $40,x
        inc     $40,sp

        jmp     $20
        jmp     $2030
        jmp     ,x
        jmp     $40,x
        jmp     $4050,x

        jsr     $20
        jsr     $2030
        jsr     ,x
        jsr     $40,x
        jsr     $4050,x

        lda     #$55
        lda     $20
        lda     $2030
        lda     ,x
        lda     $40,x
        lda     $4050,x
        lda     $40,sp
        lda     $4050,sp

        ldhx    #$55aa
        ldhx    $20

        ldx     #$55
        ldx     $20
        ldx     $2030
        ldx     ,x
        ldx     $40,x
        ldx     $4050,x
        ldx     $40,sp
        ldx     $4050,sp

        lsla
        lslx
        lsl     $20
        lsl     ,x
        lsl     $40,x
        lsl     $40,sp

        lsra
        lsrx
        lsr     $20
        lsr     ,x
        lsr     $40,x
        lsr     $40,sp

        mov     #$55,$20
        mov     $20,$40
        mov     x+,$20
        mov     $40,x+

        mul

        nega
        negx
        neg     $20
        neg     ,x
        neg     $40,x
        neg     $40,sp

        nop

        nsa

        ora     #$55
        ora     $20
        ora     $2030
        ora     ,x
        ora     $40,x
        ora     $4050,x
        ora     $40,sp
        ora     $4050,sp

        psha

        pshh

        pshx

        pula

        pulh

        pulx

        rola
        rolx
        rol     $20
        rol     ,x
        rol     $40,x
        rol     $40,sp

        rora
        rorx
        ror     $20
        ror     ,x
        ror     $40,x
        ror     $40,sp

        rsp

        rti

        rts

        sbc     #$55
        sbc     $20
        sbc     $2030
        sbc     ,x
        sbc     $40,x
        sbc     $4050,x
        sbc     $40,sp
        sbc     $4050,sp

        sec

        sei

        sta     $20
        sta     $2030
        sta     ,x
        sta     $40,x
        sta     $4050,x
        sta     $40,sp
        sta     $4050,sp

        sthx    $20

        stop

        stx     $20
        stx     $2030
        stx     ,x
        stx     $40,x
        stx     $4050,x
        stx     $40,sp
        stx     $4050,sp

        sub     #$55
        sub     $20
        sub     $2030
        sub     ,x
        sub     $40,x
        sub     $4050,x
        sub     $40,sp
        sub     $4050,sp

        swi
		
		tap

        tax

        tpa

        tsta
        tstx
        tst     $20
        tst     ,x
        tst     $40,x
        tst     $40,sp

        tsx

        txa

        txs

        wait
		
        bgnd

        cphx    #$55aa
        cphx    $20
        cphx    $2030
        cphx    $40,sp

        ldhx    #$55aa
        ldhx    $20
        ldhx    $2030
        ldhx    ,x
        ldhx    $40,x
        ldhx    $4050,x
        ldhx    $40,sp

        sthx    $20
        sthx    $2030
        sthx    $40,sp
