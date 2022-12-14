
#include "Header.h"

//Dessa funktioner finns bara i denna filen och jag kistrar in dom i min setup s? att koden blir mer effektiv n?r den k?r. 
static inline void init_ports(void);
static inline void init_interrupts(void);

leds_state_t diod = LEDS_STATE_OFF;

void setup()
{
	init_interrupts();
	init_ports();
	fsm_reset();
		
	return;
}

// Definerar vad lampan/knappen ska g?ra
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB =	(1 << FORWARD_BUTTON) | (1 << BACKWARD_BUTTON) | (1 << TWO_JUMP_BUTTON_FORWARD);
	PORTD = (1 << RESET_BUTTON) | (1 << TWO_JUMP_BUTTON_BACK);
	
	return;
}

//S?tter upp mina interrupter
static inline void init_interrupts()
{
	asm("SEI");
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << BACKWARD_BUTTON) | (1 << FORWARD_BUTTON) | (1 << TWO_JUMP_BUTTON_FORWARD);
	
	EICRA = (1 << ISC01) | (1 << ISC10) | (1 << ISC11);
	EIMSK = (1 << INT0) | (1 << INT1);
}