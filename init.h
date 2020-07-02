#ifndef INIT_H
#define INIT_H

#include <stdint.h>
#include "stm32f030x6.h"

//*********** Описание пинов-портов ******************
#define IO_PORTA        GPIOA  
#define IO_A0           0
#define IO_A1           1
#define IO_A2           2
#define IO_A3           3
#define IO_SEC          4
#define IO_SEC10        5
#define IO_MIN          6
#define IO_MIN10        7
#define IO_HOUR         8
#define IO_HOUR10       9
#define IO_DOT1         10
#define IO_DOT2         11
#define IO_BUZZER       12
#define IO_180V         15
    
#define IO_PORTB        GPIOB
#define IO_PWRSENS      0
#define IO_LED          1
#define IO_BAT_INC      3
#define IO_BAT_DEC      4
#define IO_BAT_MOD      5
#define IO_TX           6
#define IO_RX           7

//********* Макросы работы с портами ****************

void mcu_init();


#endif