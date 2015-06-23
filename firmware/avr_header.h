#ifndef AVR_HEADER
#define AVR_HEADER

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>

#include "las_uart.h"
#include "las_adc.h"
#include "las_tim.h"

#define LED 7 //B
#define MB1 6 //B
#define MB2 5 //B
#define MA  4 //H

#define SW2A 2 //D
#define SW2B 3 //D
#define SW1C 4 //E

#define TRFILLER 0
#define TRRAILLING 1
#define TRSERVO 2

#define IRQ_Start sei()

#endif
