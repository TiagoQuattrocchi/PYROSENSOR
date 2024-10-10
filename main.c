#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main(void) {
 

    stdio_init_all();
    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);
    
    
    while (true) {
        
        uint16_t pote_val = adc_read();
        uint16_t esc_pot = pote_val * 200 / 4095;

    }
}
