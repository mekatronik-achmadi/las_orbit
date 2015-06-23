#include "avr_header.h"

volatile unsigned char loop_railing,vrailing;

int main(void){

    DDRB |= (1<<LED) | (1<<MB1) | (1<<MB2) ;
    PORTB |= (1<<LED) ;

    PORTD |= (1<<SW2A) | (1<<SW2B);

    PORTE |= (1<<SW1C);

    DDRH |= (1<<MA);

    UART_Setup();

    ADC_Setup();

    sei();
    while(1){
        PORTB ^= (1<<LED);
        _delay_ms(500);
        vrailing=read_adc(TRRAILLING);
    }
}
