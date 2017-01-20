#include <p24FJ128GB206.h>
#include "config.h"
#include "common.h"
#include "ui.h"
#include "timer.h"

int16_t main(void) {
    init_clock();
    init_ui();
    init_timer();

    led_on(&led1);

    timer_setPeriod(&timer2, .5);
    timer_start(&timer2);

    while (1) {

        if (!sw_read(&sw2)) {
            led_write(&led2, 1);
            timer_stop(&timer2);
        } else {
            led_write(&led2,0);
        }

        if (!sw_read(&sw3)) {
            led_write(&led3, 1);
            timer_start(&timer2);
        } else {
            led_write(&led3,0);
        }
        
        if (timer_flag(&timer2)) {
            timer_lower(&timer2);
            led_toggle(&led1);

        }

    }
}

