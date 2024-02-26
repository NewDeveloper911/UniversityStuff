# Requirements for "Guess the Pixel"

Number of players = 2

***Basic rules to play***
    1- PLayer 1 selects a pixel - **player on the left**
        **W shows on Player 2's screen as they wait**
        --> **Letter T appears on display when transmission is completed**
        --> **A sound is played**
        --> **Selected pixel is shown again on the first player's Microbit**
    2- PLayer 2 guess the pixel - **player on the right**
    3a - Player 2 guesses correctly within 8 guesses
        __Transmit a bad game over number in the packetBuffer__
        __Selected pixel for Player 1 blinks twice__
        --> __happy face appears__
        --> __happy sound is played__
    3b- After 8 incorrect guesses, Player 2 loses
        __Transmit a good game over number in the packetBuffer__
        --> __sad face appears__
        --> __sad sound is played__

    4 - Game restarts

***Controls***
    B - moves the cursor to the right
    **uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_ANY, onButtonPressed);**
        If it moves right at the end of a row, it moves down a row and starts from the left again
    A - moves the cursor to the left
    **uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_ANY, onButtonPressed);**
        Basically the opposite of the B button
    AB - Selects the pixel that the cursor is currently on
    **uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_ANY, onButtonPressed);**
        --> Pressing it again on a different pixel than currently-selected will then select that new pixel
        --> Pressing it again on that same pixel = finalised selection
            -->Control is then given to the other player - they will guess the pixel

***Basic playing requirements***

* every time the user on the right makes a guess, the respective pixel is lit on the display of **both** micro:bit devices.
    --> Player 1 knows how close guesses have been - just like in Battefield
    --> Player 2 then keeps a record of previous guesses

* when one device is active **(selecting/guessing)**, the other is passive
    __Button presses on passive Microbits should do nothing__
    __Must communicate state changes with other device as when one switches, the other must too__
    *For Player 1, this is just showing the cursor from Player 2 trying to guess theirs
    *For Player 2. just the **W**

*    uBit.audio.setVolume(200); __The higher the value, the louder the sound__

*    uBit.audio.soundExpressions.play("happy"); __Plays a pre-set happy sound__

*    uBit.audio.soundExpressions.play("sad"); __Plays a pre-set sad sound__

## Useful documentation to use
 
    * https://makecode.microbit.org/device/screen
    * https://lancaster-university.github.io/microbit-docs/data-types/image/#manipulating-images
    * https://lancaster-university.github.io/microbit-docs/ubit/display/
    * https://lancaster-university.github.io/microbit-docs/ubit/radio/ - for 2-player microbit communication
    * https://lancaster-university.github.io/microbit-docs/data-types/image/#setpixelvalue


## Necessary variables

    * __int__ variable;
        **Use a int variable to store the state**
            --> 0 for passive
            --> 1 for active

    * __int__ cursorPos
        *Values within 1 and 25
            cursorPos // 5 should give the row of the cursor (y-coordinate)
            (cursorPos % 5) should give the column number of the cursor (x-coordinate)

## Number codes for transmission

__All need to be greater than 25, as this is what I'll be using to store guesses__

    --> 255 - Normal tranmissions
        --> Then packerBuffer[2] will hold the selectedPos for player 1 or the current guess for player 2
    --> 100 - Game over
        --> In packetBuffer[2], I can send the following numbers to indicate who has won
            --> 100 - Player 1 has won
            --> 200 - player 2 has won
                