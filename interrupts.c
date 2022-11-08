
#include "Header.h"

//Vad varje interruppt gör.

ISR(INT0_vect)
{
	fsm_reset();
	return;
}

ISR(INT1_vect)
{
	if(TWO_JUMP_BUTTON_BACK_PRESSED)fsm_update();
}

ISR(PCINT0_vect)
{
	if(FORWARD_BUTTON_PRESSED || BACKWARD_BUTTON || TWO_JUMP_BUTTON_FORWARD_PRESSED)fsm_update();
}
