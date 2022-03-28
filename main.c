#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include <tusb.h>

const uint8_t LED_R = 17;
const uint8_t LED_G = 16;
const uint8_t LED_B = 25;
    
const uint8_t keys[] = {
    3,
    4,
    29,
    1,
    2,
    0,
};

void init_keys()
{
    for (uint8_t i = 0; i < sizeof(keys); i++) {
        gpio_init(keys[i]);
        gpio_set_dir(keys[i], GPIO_IN);
        gpio_pull_up(keys[i]);
    }
}

void init_leds() 
{
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 1);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 1);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_put(LED_B, 1);
}

void red_led() 
{
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 1);
    gpio_put(LED_B, 1);
}

void green_led() 
{
    gpio_put(LED_R, 1);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 1);
}

void blue_led() 
{
    gpio_put(LED_R, 1);
    gpio_put(LED_G, 1);
    gpio_put(LED_B, 0);
}
int main() 
{
    stdio_init_all();
    //while (!tud_cdc_connected()) { sleep_ms(100);  }

    init_keys();
    init_leds();

    int select_key = -1;

    uint time = to_ms_since_boot(get_absolute_time());
    while (true) {
        for (uint8_t i = 0; i < sizeof(keys); i++) {
            if ((to_ms_since_boot(get_absolute_time()) - time) > 20) {
                time = to_ms_since_boot(get_absolute_time());
        
                bool state = gpio_get(keys[i]);
                if (state == false) {
                    select_key = i;
                    printf("Key %d was pressed\n", i);
                    
                }
            }
        }

        switch (select_key) {
            case 0:
                green_led();
                break;
            case 1:
                blue_led();
                break;
            case 2:
                red_led();
                break;
            case 3:
                blue_led();
                break;
            case 4:
                red_led();
                break;
            case 5:
                green_led();
                break;
            default:
                //printf("Invalid key\n");
                break;
        }
    }
}
