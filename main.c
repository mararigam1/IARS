#include <stdio.h>
#include <stdint.h>

#include "board.h"
#include "periph_conf.h"
#include "periph/gpio.h"

//#define BTN0_PIN            GPIO_PIN(1, 6)

#ifdef CLOCK_CORECLOCK
#define DELAY_SHORT         (CLOCK_CORECLOCK / 50)
#else
#define DELAY_SHORT         (500000UL)
#endif
#define DELAY_LONG          (DELAY_SHORT * 4)

void dumb_delay(uint32_t delay)
{
    for (uint32_t i = 0; i < delay; i++) {
        __asm__("nop");
    }
}


int main(void)
{
LED1_ON;
while (1){
LED1_TOGGLE;
LED0_TOGGLE;
dumb_delay(DELAY_SHORT);
}
}
