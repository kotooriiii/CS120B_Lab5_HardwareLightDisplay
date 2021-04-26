/*	Author: Carlos Miranda cmira039@ucr.edu
 *  Partner(s) Name: n/a
 *	Lab Section: 23
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://youtu.be/p6a0MMFxeYw
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum LightState {INIT, WAIT,ACTION, WAIT_RELEASE} LIGHT_STATE;

unsigned char LIGHT_CODE[6] =
{
	0x01,0x02,0x04,0x08,0x10,0x20
};

unsigned char currIndex = 0x00;
unsigned char lightCodeLen = 0x06;

unsigned char IPINA()
{
	return ~PINA;
}

unsigned char isOnlyA0()
{
	return IPINA() & 0x01;
}

void tickCounter()
{
	switch(LIGHT_STATE)
	{
		case INIT:
		LIGHT_STATE = WAIT;
		break;
		
		case WAIT:
		
		if(!isOnlyA0())
		{
			LIGHT_STATE = WAIT;
		}
		else 
		{
			LIGHT_STATE = ACTION;
		}
		break;

		case ACTION:
		LIGHT_STATE = WAIT_RELEASE;
		break;
		
		case WAIT_RELEASE:
		if(!isOnlyA0())
		{
			LIGHT_STATE = WAIT;
		}
		else 
		{
			LIGHT_STATE = WAIT_RELEASE;
		}
		break;
	}
	
	switch(LIGHT_STATE)
	{
		case INIT:
		PORTB = 0x00;
		currIndex = 0x00;
		break;
		
		case WAIT:
		break;

		case ACTION:
		if(currIndex < lightCodeLen)
		{
			PORTB = LIGHT_CODE[currIndex];
			currIndex++;
		}
		else
		{
			PORTB = 0x00;
			currIndex = 0x00;
		}
		break;
		
		case WAIT_RELEASE:
		break;
	}
}

int main(void) 
{
	
	//Inputs
	DDRA = 0x00; PORTA = 0xFF; 
	
	//Outputs
	DDRB = 0xFF; PORTB = 0x00; 
	
	LIGHT_STATE = INIT;
	currIndex = 0x00;
		
	while(1) 
	{
		tickCounter();
	}
	return 0;
}
	



