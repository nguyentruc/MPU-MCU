#include <p18f8722.h>
 
// this is our chip select (CS) pin according to our pic18 explorer board's connections
#define CS PORTAbits.RA2
// addresses from MCP23S17's datasheet, think of the IODIR as TRIS and GPIO as PORT for the MCP23S17 (no the PIC micro)
#define IODIRA_ADDRESS 0x00
#define IODIRB_ADDRESS 0x01
#define GPIOA_ADDRESS 0x12
#define GPIOB_ADDRESS 0x13
#define LINE_1	0x00
#define LINE_2	0x40

void setIODIR(char, char);
void setGPIO(char, char);
void lcdCommand(char);
void lcdChar(unsigned char);
void lcdGoTo(char);
void lcdWriteString(rom unsigned char*);
void lcd_init();	
