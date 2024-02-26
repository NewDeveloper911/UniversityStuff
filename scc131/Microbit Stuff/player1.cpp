#include "MicroBit.h"
#include "MicroBitDisplay.h"

MicroBit uBit;

//Basic variables
int state = 1;
int cursorPos = 0;
int selectedPos = -1;
//0 for false and 1 for true
int haveSelected = 0;

//Shared variables - essentially
int player2Guesses[8] = {-1};
int player2CurrentGuess = 0;
PacketBuffer transData(2);

// Event handler for button A
void onButtonA(MicroBitEvent e)
{
    if(cursorPos < 24 )cursorPos += 1;
    else cursorPos = 0; 
}

// Event handler for button B
void onButtonB(MicroBitEvent e)
{
    if(cursorPos > 0 )cursorPos -= 1;
    else cursorPos = 24;    
}

// Event handler for buttons A and B pressed together
void onButtonAB(MicroBitEvent e)
{
    //Could accomplish this by just telling the other device when they can switch state
    if(haveSelected == 0) {
        selectedPos = cursorPos;
        haveSelected=1;
    }
    else{
        if(cursorPos == selectedPos){
            //Too lazy right now to have the other device send a signal when it has
            //successfully received the signal, ngl. Just pretend like there's not issue
            PacketBuffer transData(2);
            //This first value indicates that the data has been sent correctly
            transData[0] = 255;
            //This is the position which we wish to send to the other player
            transData[1] = selectedPos;

            uBit.radio.datagram.send(transData);

            //Too lazy right now to have the other device send a signal when it has
            //successfully received the signal, ngl. Just pretend like there's not issue
            uBit.display.print("T");
            uBit.sleep(100);
            //Tell the other device to switch state
            state = 0;
        }
        selectedPos = cursorPos;
        
    }
    
}

void receiveData(MicroBitEvent e)
{
    //This is where the device would start to recieve data
    PacketBuffer  p  = uBit.radio.datagram.recv();

    if (p[0] == 255)
    {
        player2Guesses[player2CurrentGuess++] = p[1];
    }
}

void restartGame(){
    uBit.display.clear();
    state = 1;
    cursorPos = 0;
    selectedPos = -1;
    haveSelected = 0;

    player2Guesses[8] = {-1};
    player2CurrentGuess = 0;

}

int main(){

    // Initialise the micro:bit
    uBit.init();
    uBit.radio.enable();

   // Ensure that different levels of brightness can be displayed
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

    while(1){
        //Will always be showing the selectedPos - except when the letter "T" is being printed to screen
        if(selectedPos > 0) uBit.display.image.setPixelValue(selectedPos%5,selectedPos/5,150);

        if(state==1){
            //Should only be checking for inputs when the device is active

            // Set up listeners for button A, B and the combination A and B.
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, onButtonAB);

            //Flashing pixel
            uBit.display.image.setPixelValue(cursorPos%5,cursorPos/5,255);
            uBit.sleep(100);
            uBit.display.clear();
            uBit.sleep(100);
        }
        else{
            // Set up a listener for the radio.
            uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, receiveData);

            if(player2CurrentGuess == 8){
                //Then PLayer 1 has won - send the appropiate signals
                //This first value indicates that the game is over
                transData[0] = 100;
                //This tells the other player who won
                transData[1] = 100;
                uBit.radio.datagram.send(transData);

                //Too lazy right now to have the other device send a signal when it has
                //successfully received the signal, ngl. Just pretend like there's not issue
                uBit.display.print("T");
                uBit.sleep(100);
                restartGame();
            }
            else{
                //Show all of the current guesses from Player 2
                for(int i=0;i<player2CurrentGuess;i++){
                    if(player2Guesses[i] != -1) uBit.display.image.setPixelValue(player2Guesses[i]%5,player2Guesses[i]/5,50);
                    if(player2Guesses[i] == selectedPos){
                        //Then PLayer 2 has won - send the appropiate signals
                        //This first value indicates that the game is over
                        transData[0] = 100;
                        //This tells the other player who won
                        transData[1] = 200;
                        uBit.radio.datagram.send(transData);

                        //Too lazy right now to have the other device send a signal when it has
                        //successfully received the signal, ngl. Just pretend like there's not issue
                        uBit.display.print("T");
                        uBit.sleep(100);

                        restartGame();

                    }
                }
            }
        }
    }
}