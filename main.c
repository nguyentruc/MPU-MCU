//*****************************************************************
// PICDEM Explorer 18 Demo for LCD display
// Filename : main.c
//
// By Rockie Roper
// Converted from the ASM that come with the demo board
//
// Created on 2009-06-05
//
// Compiler is the C18 from MPLAB
// 
//*****************************************************************
#include <p18F8722.h>

#pragma config  OSC = HSPLL
#pragma config 	FCMEN = OFF
#pragma config 	IESO = OFF
#pragma config 	PWRT = OFF           
#pragma config 	BOREN = OFF
#pragma config 	WDT = OFF 
#pragma config 	MCLRE = ON  
#pragma config 	LVP = OFF  
#pragma config 	XINST = OFF 

#pragma udata UDATA_ACS
unsigned char LCDText[16*2+1];

#pragma code

void main(void)
{
	int			tmpcnt = 0;
	OSCTUNEbits.PLLEN = 1;

  // Initialize the LCD display
	LCDInit();	
	
	ADCON1 = 0b00001110;
	TXSTA = 0b10100100;
	SPBRG = 0xff;
	RCSTA = 0b10010000;
	
	TRISBbits.TRISB0 = 1;
	TRISAbits.TRISA5 = 1;

  while(1)
  	{
	  	// Write the cammand to start on line 1
			LCDLine_1();  
			// Write the data one char at a time.
			d_write('H');
			d_write('e');
			d_write('l');
			d_write('l');
			d_write('0');
			// Write the cammand to start on line 2
			LCDLine_2();
			// Write the data to line 2 one char at a time
			// You can put this in a loop and read from a table
			d_write('P');
			d_write('I');
			d_write('C');
			d_write('1');
			d_write('8');
			delay_1s();
			tmpcnt++;
			switch(tmpcnt)
				{
					case 10:
						d_write(' ');
						d_write('1');
						d_write('0');
						break;
					case 20:
						d_write(' ');
						d_write('2');
						d_write('0');
						break;
					case 30:
						d_write(' ');
						d_write('3');
						d_write('0');
						break;
					case 40:
						d_write(' ');
						d_write('4');
						d_write('0');
						break;
				}
		}
}