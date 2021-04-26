/*	Author: Carlos Miranda cmira039@ucr.edu
 *  Partner(s) Name: n/a
 *	Lab Section: 23
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	
	//Inputs
	DDRA = 0x00; PORTA = 0xFF; 
	
	//Outputs
	DDRC = 0xFF; PORTC = 0x00; 
	
	//temp
	unsigned char tempC = 0x00;
	unsigned char ALowerNibble = 0x00;
	
	while(1) {
		
		tempC = 0x00;
		ALowerNibble = ~PINA & 0x0F;
		
		if(1 <= ALowerNibble && ALowerNibble <= 2)
		{
			tempC = 0x20;
		}
		
		else if(3 <= ALowerNibble && ALowerNibble <= 4)
		{
			tempC = 0x30;
		}
		
		else if(5 <= ALowerNibble && ALowerNibble <= 6)
		{
			tempC = 0x38;
		}
		
		else if(7 <= ALowerNibble && ALowerNibble <= 9)
		{
			tempC = 0x3C;
		}
		
		else if(10 <= ALowerNibble && ALowerNibble <= 12)
		{
			tempC = 0x3E;
		}
		
		else if(13 <= ALowerNibble && ALowerNibble <= 15)
		{
			tempC = 0x3F;
		}
		
		if(ALowerNibble <= 4)
		{
			tempC = tempC | 0x40;
		}
		
		PORTC = tempC;
	}
	return 1;
}
	


