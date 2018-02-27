#include "mbed.h"
#include "DebouncedInterrupt.h"

DigitalOut led1(LED1);
//InterruptIn mybutton(PC_13);//NUCLEO F401RE
//InterruptIn pa8(PA_8);
//InterruptIn pa9(PA_9);
//InterruptIn pb10(PB_10);

Serial pc(SERIAL_TX, SERIAL_RX);

// Interrupt Service Routine on button press.
void button_push_isr( void )
{
    pc.printf("\n\r button interrupt \n\r");
}

/*
{
    pc.printf("\n\r mybutton pressed \n\r");
}

void pressed_pa8()
{
    pc.printf("\n\r pa8_button pressed \n\r");
}

void pressed_pa9()
{
    pc.printf("\n\r pa9_button pressed \n\r");
}

void pressed_pb10()
{
    pc.printf("\n\r pb10_button pressed \n\r");
}*/

// main() runs in its own thread in the OS
int main() {

pc.printf("\n\r new run 3but \n\r");

/*debounce code*/
DebouncedInterrupt user_interrupt(PA_9);
user_interrupt.attach(button_push_isr, IRQ_RISE, 500, true);

  //mybutton.rise(&pressed_mybutton);
  //pa8.rise(&pressed_pa8);
  //pa9.rise(&pressed_pa9);
 
    while (true) {
        led1 = !led1;
        pc.printf("\n\r toggle led \n\r");
        wait(0.5);
    }
}
