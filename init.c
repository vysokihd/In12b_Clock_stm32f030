#include <stdint.h>
#include "stm32f030x6.h"
#include "init.h"

#define IO_MODE_IN      0x00
#define IO_MODE_OUT     0x01
#define IO_MODE_ALT     0x02
#define IO_MODE_ANALOG  0x03

#define IO_PUSHPULL     0
#define IO_OPENDRAIN    1

#define IO_SPEED_LOW    0x00
#define IO_SPEED_MED    0x01
#define IO_SPEED_HI     0x03

#define IO_NOPULL       0x00
#define IO_PULLUP       0x01
#define IO_PULLDWN      0x02

#define IO_ALT_AF0      0x00
#define IO_ALT_AF1      0x01
#define IO_ALT_AF2      0x02
#define IO_ALT_AF3      0x03
#define IO_ATL_AF4      0x04
#define IO_ATL_AF5      0x05
#define IO_ATL_AF6      0x06
#define IO_ATL_AF7      0x07


void mcu_init()
{
   //Включение тактирование порта А и B
   RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;
   
   //Конфигурирование режима пинов порта А
   IO_PORTA->MODER |= (IO_MODE_OUT << (2 * IO_A0)) |
                      (IO_MODE_OUT << (2 * IO_A1)) |
                      (IO_MODE_OUT << (2 * IO_A2)) |
                      (IO_MODE_OUT << (2 * IO_A3)) |
                      (IO_MODE_OUT << (2 * IO_SEC)) |
                      (IO_MODE_OUT << (2 * IO_SEC10)) |
                      (IO_MODE_OUT << (2 * IO_MIN)) |
                      (IO_MODE_OUT << (2 * IO_MIN10)) |
                      (IO_MODE_OUT << (2 * IO_HOUR)) |
                      (IO_MODE_OUT << (2 * IO_HOUR10)) |
                      (IO_MODE_OUT << (2 * IO_DOT1)) |
                      (IO_MODE_OUT << (2 * IO_DOT2)) |
                      (IO_MODE_OUT << (2 * IO_BUZZER)) |
                      (IO_MODE_OUT << (2 * IO_180V));
   //Настройка состояния пинов порта А по умолчанию
   IO_PORTA->ODR |= (1 << IO_180V);
   
   //Конфигурирование режима пинов порта B
   IO_PORTB->MODER |= (IO_MODE_IN << (2 * IO_PWRSENS)) |
                      (IO_MODE_OUT << (2 * IO_LED)) |
                      (IO_MODE_IN << (2 * IO_BAT_INC)) |
                      (IO_MODE_IN << (2 * IO_BAT_DEC)) |
                      (IO_MODE_IN << (2 * IO_BAT_MOD)) |
                      (IO_MODE_ALT << (2 * IO_TX)) |
                      (IO_MODE_ALT << (2 * IO_RX));
   //Настройка подтяжки пинов порта B
   IO_PORTB->PUPDR |= (IO_PULLUP << (2 * IO_BAT_INC)) |
                      (IO_PULLUP << (2 * IO_BAT_DEC)) |
                      (IO_PULLUP << (2 * IO_BAT_MOD));
   
   
}