
#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL // sätter klockslaget till 16Mhz

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//PORTB
//Lampor
#define LED1 0 
#define LED2 1
#define LED3 2

//Knappar
#define BACKWARD_BUTTON 3
#define FORWARD_BUTTON 4
#define TWO_JUMP_BUTTON_FORWARD 5

//PORTD
//Knappar
#define RESET_BUTTON 2
#define TWO_JUMP_BUTTON_BACK 3

//Angiven port

#define LED1_ON PORTB |= (1 << LED1)
#define LED2_ON PORTB |= (1 << LED2)
#define LED3_ON PORTB |= (1 << LED3)

#define LED1_OFF PORTB &= ~(1 << LED1)
#define LED2_OFF PORTB &= ~(1 << LED2)
#define LED3_OFF PORTB &= ~(1 << LED3)

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))

#define BACKWARD_BUTTON_PRESSED (PINB &(1 << BACKWARD_BUTTON))
#define FORWARD_BUTTON_PRESSED (PINB &(1 << FORWARD_BUTTON))
#define TWO_JUMP_BUTTON_FORWARD_PRESSED (PINB &(1 << TWO_JUMP_BUTTON_FORWARD))

#define RESET_BUTTON_PRESSED (PIND &(1 << RESET_BUTTON))
#define TWO_JUMP_BUTTON_BACK_PRESSED (PIND &(1 << TWO_JUMP_BUTTON_BACK))

//Gör så att koden kan lösa av tillstånds namnet vad den ska göra
typedef enum {true, false} bool;	
	
typedef enum
{
	LEDS_STATE_OFF,
	LEDS_STATE_ON,
	LEDS_STATE_SLOW,
	LEDS_STATE_MEDIUM,
	LEDS_STATE_FAST

}leds_state_t;

extern leds_state_t diod; // Gör diod till en globalt namn så att den ses överallt.

//Mina olika funktioner

void setup(void);
void fsm_reset(void);
void fsm_update(void);
void fsm_set_output(void);
void blink_slow();
void blink_medium();
void blink_fast();


#endif /* HEADER_H_ */