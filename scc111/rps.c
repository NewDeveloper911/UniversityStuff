#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    bool stillPlaying = true;

    //Used pointers to make accessing strings easier
    const char *choices[]= {"Rock","Paper","Scissors"};
    //This is the index in the constant array
    int compChoice = 0;
    int  playerChoice = 0;
    int  gamesPlayed = 0;
    int  gamesWon = 0;
    int  gamesLost = 0;
    int gamesTied = 0;

    while(stillPlaying){
        printf("Welcome to rock, paper, scissors!\n");
        printf("Please enter 1 for Rock, 2 for paper or 3 for Scissors, and 0 to quit.\n");
        scanf("%d", &playerChoice);
        if(playerChoice < 1){
            stillPlaying = false;
        }
        else{
            playerChoice -= 1;
            if(playerChoice >= 0 && playerChoice <= 2){
                printf("Player chose: %s\n", choices[playerChoice]);
                compChoice =  rand() % 3;
                printf("Machine chose: %s\n", choices[compChoice]);
                if(playerChoice - compChoice == 1 || playerChoice - compChoice == -2){
                    //Then the player has won
                    printf("Hurrah. You won.\n");
                    gamesWon += 1;
                }
                else if(compChoice - playerChoice == 1 || compChoice - playerChoice == -2){
                    printf("Sorry, you lost this round!\n");
                    gamesLost += 1;
                }
                else if(compChoice ==  playerChoice){
                    printf("You've picked the same thing as the bot, therefore another tie.\n");
                    gamesTied += 1;
                }
                printf("\n\n");
                gamesPlayed += 1;
            }
        }   
    }
    printf("Games played: %d, games won: %d, games lost:%d, games tied: %d\n", gamesPlayed, gamesWon, gamesLost, gamesTied);
    return 0;
}