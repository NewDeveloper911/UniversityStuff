#include "MicroBit.h"

MicroBit uBit;

//This is an example of an event handler
void onButtonPressed(MicroBitEvent e)
{
    //This method is a more asynchronous way of checking double button presses
    if(e.value == MICROBIT_BUTTON_EVT_UP) uBit.display.print("C");
    //Notice that now the micro:bit does not need to go to sleep for a few milliseconds when both buttons are pressed.
}

int main()
{
    uBit.init();
    //Format:
    //1 - Id of the button to listen to
        //Examples are MICROBIT_ID_BUTTON_A, MICROBIT_ID_BUTTON_B and MICROBIT_ID_BUTTON_AB
    //2 - Event of interest
        //Examples are 
        /*
            MICROBIT_BUTTON_EVT_DOWN
            MICROBIT_BUTTON_EVT_UP
            MICROBIT_BUTTON_EVT_CLICK
            MICROBIT_BUTTON_EVT_LONG_CLICK
            MICROBIT_BUTTON_EVT_HOLD
            MICROBIT_BUTTON_EVT_DOUBLE_CLICK

            MICROBIT_EVT_ANY - this is the * wildcard in this case
        */
    //3 Function/Event handler to run when event is triggered
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_ANY, onButtonPressed);

    /*
        while(1){
        //Normie way of checking button presses

            if(uBit.buttonA.isPressed()) uBit.display.print("A");
            if(uBit.buttonA.isPressed()) uBit.display.print("B");
            if(uBit.buttonAB.isPressed()){
                uBit.display.print("A");
                //Sleep is required for synchronous button checking to avoid errors?
                uBit.sleep(100);
            }
       uBit.sleep(100);
    }
    */
   release_fiber()
    
}