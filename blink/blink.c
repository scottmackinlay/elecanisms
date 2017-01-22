//This is my blink code that we will use to flash the LEDs on the PIC board. We can change this behavior with the switches.
//Step one is to include a couple libraries:
#include <p24FJ128GB206.h>
#include "config.h"
#include "common.h"
#include "ui.h"
#include "timer.h"

int16_t main(void) {
    //We initialize some magic in these three lines including the clock and timer dodads
    init_clock();
    init_ui();
    init_timer();
    //LED1 is going to start on
    led_on(&led1);

    timer_setPeriod(&timer2, .5); //this controls the frequency of blinking
    timer_start(&timer2); //start the timer

    while (1) {

        if (!sw_read(&sw2)) { //if switch two is pressed:
            led_write(&led2, 1); //turn LED2 on
            timer_stop(&timer2); //Stop the timer (and the blinking)
        } else {
            led_write(&led2,0); //otherwise, turn LED2 off
        }

        if (!sw_read(&sw3)) {   //if switch three is pressed:
            led_write(&led3, 1); //turn LED3 on
            timer_start(&timer2); //Start the timer up again.
        } else {
            led_write(&led3,0); //Else, turn the LED3 off
        }
        
        if (timer_flag(&timer2)) { //periodically:
            timer_lower(&timer2); 
            led_toggle(&led1); //switch LED1 from on to off and vice versa

        }

    }
}

