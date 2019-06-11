#include <stdio.h> //librerias
#include <stdint.h>

#include "board.h" 
#include "periph/gpio.h"
#include "periph_conf.h"

#define TEST_FLANK      GPIO_FALLING

#ifdef BTN0_PIN /* assuming that first button is always BTN0 */
static void cb(void *arg)
{
    printf("Pressed BTN%d\n", (int)arg);
}
#endif

int main(void)
{
 
//Declaración del botón 
   #ifdef BTN0_PIN 
    if (gpio_init_int(BTN0_PIN, BTN0_MODE, TEST_FLANK, cb)) {
        puts("[FAILED] init BTN0!");
        return 1;
    }
	
#endif


//Declaración del LED
#ifdef LED0_ON
    LED0_OFF;
#endif



 while (1) {
#ifdef BTN0_PIN
        LED0_ON;
        dumb_delay(DELAY_LONG);
#endif

    }

    return 0;
}