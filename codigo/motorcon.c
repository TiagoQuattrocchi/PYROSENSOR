#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

// defino los gpio pins para los LEDs
#define LED_verde 13
#define LED_amarillo 14
#define LED_rojo 15

void setup_pwm(uint 0) {
// Configuro el PWM en el numero de pin que indique GPIO 
gpio_set_function(0, GPIO_FUNC_PWM); 
// Obtengo el numero de slice para ese GPIO 
uint8_t slice = pwm_gpio_to_slice_num(0); 
// Obtengo una configuracion por defecto de PWM 
pwm_config config = pwm_get_default_config(); 
// Divido los 125 MHz de clock de la Pico por 125 
// para tener un clock de 1 MHz 
pwm_config_set_clkdiv(&config, 125.0); 
// Cambio el wrap a 50000 para tener una frecuencia 
// de PWM de 50 ms (wrap / fclk) 
pwm_config_set_wrap(&config, 50000); 
// Habilito el PWM 
pwm_init(slice, &config, true); 
// Configuro la salida de PWM en el GPIO al 
// 50% de actividad (level / wrap) 
pwm_set_gpio_level(0, 25000); 
}


int main(void) {
 

    stdio_init_all();
    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);
    //inicializo los pines y los selecciono como outputs
    gpio_init(LED_verde);
    
    gpio_init(LED_amarillo);
    gpio_init(LED_rojo);
    gpio_set_dir(LED_verde, GPIO_OUT);
    gpio_set_dir(LED_amarillo, GPIO_OUT);
    gpio_set_dir(LED_rojo, GPIO_OUT);
    
    while (true) {
        uint16_t pote_val = adc_read();
        uint16_t esc_pot = pote_val * 200.0 / 4095.0;
        uint16_t dif = esc_pot-temperatura;
        uint16_t prop =(diff*562)+5000;

        float temperatura = max6675_get_temp_c();

        if(dif >= 100) {
            // PWM 100%
        pwm_set_gpio_level(0,50000);
        }
        else if(dif <= 100 && dif >=  20) {
            // PWM proporcional
        pwm_set_gpio_level(0,prop);
        }
        else if(dif >=  20) {
            // PWM es minimo
        pwm_set_gpio_level(0,5000);
        }

      
    }
}
