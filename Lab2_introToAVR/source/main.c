/*	Author: bmans001
 *  Partner(s) Name: Alex
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpA = PINA;
    unsigned char temp_input = 0x00;
    while (1) {
        if (tmpA == 0x01) {
            tmpB = 0x01;
        }
        else {
           tmpB = 0x00; 
        }
        PORTB = tmpB;
    }
    return 1;
}
