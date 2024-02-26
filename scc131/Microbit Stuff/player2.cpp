#include "MicroBit.h"
#include "MicroBitDisplay.h"

MicroBit uBit;

//Basic variables
int state = 0;
int cursorPos = 0;
int selectedPos = -1;
//0 for false and 1 for true
int haveSelected = 0;

//Gameplay variables
//This player can only make 8 guesses
int previousGuesses[8];
int guessNumber = -1;

//Annoying smiley faces which have to be coded in
MicroBitImage smileyFace("0,255,0,255,0\n0,255,0,255,0\n255,0,0,0,255\n0,255,255,255,0\n0,0,0,0,0,0\n");
MicroBitImage sadFace("0,255,0,255,0\n0,255,0,255,0\n0,255,255,255,0\n255,0,0,0,255\n0,0,0,0,0,0\n");
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
        if(cursorPos == selectedPos && cursorPos != previousGuesses[guessNumber] && guessNumber < 7){
            //This player has made a guess
            previousGuesses[++guessNumber] = cursorPos;
            //Apparently should play a sound - double-check the video to find out which sound
            //This first value indicates that the data has been sent correctly
            transData[0] = 255;
            //This is the position which we wish to send to the other player
            transData[1] = selectedPos;
            uBit.radio.datagram.send(transData);
            haveSelected = 0;
        }
        selectedPos = cursorPos;
        
    }
    
}

void restartGame(){
    uBit.display.clear();
    state = 0;
    cursorPos = 0;
    selectedPos = -1;
    haveSelected = 0;

    previousGuesses[8] = {-1};
    guessNumber = -1;

}

void receiveData(MicroBitEvent e)
{
    //This is where the device would start to recieve data
    PacketBuffer p  = uBit.radio.datagram.recv();

    if (p[0] == 255)
    {
        selectedPos = p[1]; //Can use this to show the current guess of the opponent
        
        //Basically could just switch the value of the switch variable
            //Then do the player-specific stuff nested in if statements
        if(state == 0) state = 1;
        else state = 0;
    }
    else if(p[0] == 100){
        if(p[1] == 100){
            //Then Player 1 has won
            uBit.audio.soundExpressions.play("sad");
            uBit.sleep(100);
            uBit.display.print(sadFace);
        }
        else if(p[1] == 200){
            //Then Player 2 has won
            uBit.display.print(smileyFace);
            uBit.sleep(100);
            uBit.audio.soundExpressions.play("happy");
        }
        state = 0;
    }
}

int main(){

    // Initialise the micro:bit
    uBit.init();
    uBit.radio.enable();

   // Ensure that different levels of brightness can be displayed
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

    

    // --- ADD LINES TO main() AS REQUIRED ---
    while(1){
        if(state==1){
            //Should only be checking for inputs when the device is active

            //Before I do anything else, if we have made our 8th guess, it's game over
            if(guessNumber == 7){
                //Then Player 1 has won
                uBit.audio.soundExpressions.play("sad");
                uBit.sleep(100);
                uBit.display.print(sadFace);
                restartGame();
            } 

            // Set up listeners for button A, B and the combination A and B.
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
            uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, onButtonAB);

            //Flashing pixel
            uBit.display.image.setPixelValue(cursorPos%5,cursorPos/5,255);

            //Should edit this to keep alit all previous guesses at a lower intensity
            for(int i=0;i<guessNumber;i++){
                if(previousGuesses[i] != -1) uBit.display.image.setPixelValue(previousGuesses[i]%5,previousGuesses[i]/5,50);
            }
            uBit.sleep(100);
            uBit.display.clear();
            uBit.sleep(100);
        }
        else{
            // Set up a listener for the radio.
            uBit.display.print("W");
            uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, receiveData);
            uBit.sleep(100);
        }

    }
    
    /*
    //Also need to determine what to do when the MicroBit is active/pasive
    */
}