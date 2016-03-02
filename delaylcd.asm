#ifdef __18F8722
	list p=18F8722
	#include p18F8722.inc
#endif

D_LCD_DATA UDATA_ACS
temp_1		RES 1
temp_2		RES 1
temp_3		RES 1
Dreg1 		res 1
Dreg2 		res 1

PROG1	CODE

;------------------ 100ms Delay --------------------------------
		GLOBAL delay_100ms
delay_100ms
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	call Delaysmall
	return

		GLOBAL Delaysmall
Delaysmall ;100ms at 4Mhz
	movlw	0xFF
	movwf	temp_1
	movlw	0x83
	movwf	temp_2

d100l1
	decfsz	temp_1,F
	bra	d100l1
	decfsz	temp_2,F
	bra	d100l1
	return

;---------------- 1s Delay -----------------------------------
		GLOBAL delay_1s
delay_1s
	call	Ldelay
	call	Ldelay
	call	Ldelay
	call 	Ldelay
	call	Ldelay
	call 	Ldelay
	call 	Ldelay
	call 	Ldelay
	call	Ldelay
	call 	Ldelay
	return




Ldelay		;1S at f Mhx
	movlw	0xFF
	movwf	temp_1
	movwf	temp_2
	movlw	0x05
	movwf	temp_3
d1l1
	decfsz	temp_1,F
	bra	d1l1
	decfsz	temp_2,F
	bra	d1l1
	decfsz	temp_3,F
	bra	d1l1
	return	

	GLOBAL Delay
Delay
	nop
	nop
	nop
	nop
	decfsz	Dreg1
	goto Delay
	decfsz	Dreg2
	goto Delay
	return

	GLOBAL SDelay
SDelay
	decfsz	Dreg1
	goto SDelay
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2
	decfsz	Dreg1
	goto	$-2

	return
	
	END	