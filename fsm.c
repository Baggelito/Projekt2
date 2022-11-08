
#include "Header.h"
/*
Vad f�r kod som finns i varje funktion f�r fsm_reset, fsm_update och fsm_set_output
*/
void fsm_reset(void)
{
	diod = LEDS_STATE_OFF;
	LEDS_OFF;
	
	return;
}

void fsm_update(void)
{
	switch(diod) //Anv�nder switch ist�llet f�r en massa if satser f�r att l�ttare kunna skriva min kod.
				 //Case �r i vilket tillst�nd koden �r i.
	{
		case LEDS_STATE_OFF:
		{
			if(FORWARD_BUTTON_PRESSED)
			{
				diod = LEDS_STATE_SLOW;
			}	
			else if(TWO_JUMP_BUTTON_FORWARD)
			{
				diod = LEDS_STATE_MEDIUM;
			}
			else if(BACKWARD_BUTTON)
			{
				diod = LEDS_STATE_ON;
			} 
			else if(TWO_JUMP_BUTTON_BACK_PRESSED)
			{
				diod = LEDS_STATE_FAST;
			}
			break;
		}
		case LEDS_STATE_ON:
		{
			if(FORWARD_BUTTON_PRESSED)
			{
				diod = LEDS_STATE_OFF;
			}
			else if(TWO_JUMP_BUTTON_FORWARD)
			{
				diod = LEDS_STATE_SLOW;
			}
			else if(BACKWARD_BUTTON)
			{
				diod = LEDS_STATE_FAST;
			}
			else if(TWO_JUMP_BUTTON_BACK_PRESSED)
			{
				diod = LEDS_STATE_MEDIUM;
			}
			break;
		}
		
		case LEDS_STATE_SLOW:
		{
			if(FORWARD_BUTTON_PRESSED)
			{
			diod = LEDS_STATE_MEDIUM;
			}
			else if(TWO_JUMP_BUTTON_FORWARD)
			{
			diod = LEDS_STATE_FAST;
			}
			else if(BACKWARD_BUTTON)
			{
				diod = LEDS_STATE_OFF;
			}
			else if(TWO_JUMP_BUTTON_BACK_PRESSED)
			{
			diod = LEDS_STATE_ON;
			}
			break;
		}
		
		case LEDS_STATE_MEDIUM:
		{
			if(FORWARD_BUTTON_PRESSED)
			{
				diod = LEDS_STATE_FAST;
			}
			else if(TWO_JUMP_BUTTON_FORWARD)
			{
				diod = LEDS_STATE_ON;
			}
			else if(BACKWARD_BUTTON)
			{
				diod = LEDS_STATE_SLOW;
			}
			else if(TWO_JUMP_BUTTON_BACK_PRESSED)
			{
				diod = LEDS_STATE_OFF;
			}
			break;
		}
		
		case LEDS_STATE_FAST:
		{
			if(FORWARD_BUTTON_PRESSED)
			{
				diod = LEDS_STATE_ON;
			}
			else if(TWO_JUMP_BUTTON_FORWARD)
			{
				diod = LEDS_STATE_OFF;
			}
			else if(BACKWARD_BUTTON)
			{
				diod = LEDS_STATE_MEDIUM;
			}
			else if(TWO_JUMP_BUTTON_BACK_PRESSED)
			{
				diod = LEDS_STATE_SLOW;
			}
			break;
		}
	}
	
}

void fsm_set_output(void)
{
		
		if (diod == LEDS_STATE_OFF) LEDS_OFF;
		else if (diod == LEDS_STATE_ON) LEDS_ON;
		else if (diod == LEDS_STATE_SLOW) blink_slow();
		else if (diod == LEDS_STATE_MEDIUM) blink_medium();
		else if (diod == LEDS_STATE_FAST) blink_fast();
		else fsm_reset();
		
		return;	
}