#include <p18f8722.h>
#include "lcd.h"

// configuration bits
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config WDT = OFF        // Watchdog Timer (WDT disabled (control is placed on the SWDTEN bit))

void main(){
	lcd_init();
    // send characters
    lcdWriteString("All About Me!"); // using the string function
    lcdGoTo(LINE_2); // go to line two
    lcdChar('A'); // using the single character function
    lcdChar('S');
    lcdChar('S');
    lcdChar('I');
    lcdChar('G');
    lcdChar('N');
    lcdChar('M');
    lcdChar('E');
    lcdChar('N');
    lcdChar('T');
    lcdChar('_');
 	lcdGoTo(LINE_1);
	lcdWriteString("All About You!");
    while(1){
 
    }
}
