#include "avr_header.h"

volatile unsigned char loop_railing,vrailing;

void TIM0_Setup(void){
    TCCR0B|=(0<<CS02)|(1<<CS01)|(1<<CS00);
    TIMSK0|=(1<<TOIE0);
}

ISR(TIMER0_OVF_vect){
    if(!(PINE & (1<<SW1C))){

        loop_railing++;
        if(loop_railing==vrailing){
            if(!(PINE & (1<<SW2A))){
                PORTB &= ~(1<<MB2);
            }
            if(!(PINE & (1<<SW2B))){
                PORTB &= ~(1<<MB1);
            }
        }

        if(loop_railing==255){
           loop_railing=0;
           if(!(PINE & (1<<SW2A))){
               PORTB |= (1<<MB2);
               PORTB &= ~(1<<MB1);
           }
           if(!(PINE & (1<<SW2B))){
               PORTB |= (1<<MB1);
               PORTB &= ~(1<<MB2);
           }
        }

    }
}
