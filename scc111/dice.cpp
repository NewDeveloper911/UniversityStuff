#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()

class Dice{
    public:
    //C++ constructors
        Dice(int numSides);

        //This is an example of a getter - this is public to accesss private variables
        int getSides(){
            return numSides;
        }

        int roll(){
            srand(time(NULL));
            return (rand() % numSides) + 1;
        }
    private:
        int numSides = 6;
};

Dice::Dice(int numberofSides){
    numSides = numberofSides;
}

class Player{
    public:
        char name[20];
        int score = 0;
        int makeGuess(){
            int playerGuess = 7;
            while(playerGuess > 6 || playerGuess < 1) scanf("%d", &playerGuess);
            return playerGuess;
        }

        void updateScore(){
            score++;
        }

        void displayScore(){
            printf("This player's current score is %d\n", score);
        }
};

int main() {
    //Getting the right variables inputted
    int numPlayers, numRounds;
    printf("Hey, how many players do you want to play?\n");
    scanf("%d", &numPlayers);
    printf("Hey, how many rounds do you want to play?\n");
    scanf("%d", &numRounds);

    Dice newDice(6);
    Player players[numPlayers];

    for(int i=0;i<numRounds;i++){
        //Every player's turn should run in order
        for(int j=0;j<numPlayers;j++){
            printf("Hey, player %d. Please make a guess for the die.\n", j+1);
            int dieGuess = players[j].makeGuess();
            int dieRoll = newDice.roll();

            if(dieGuess == dieRoll){
                printf("Congrats. You guessed correctly.\n");
                players[j].updateScore();
            }
            else{
                printf("Skill issue\n");
            }
            printf("The actual die roll was %d\n", dieRoll);

        }

        printf("\n--- Scores after Round %d ---\n", i+1);
        for(int j=0;j<numPlayers;j++){
            printf("For player %d, their score was:\n", j+1);
            players[j].displayScore();
            printf("\n");
        }
    }

    printf("\n--- Final scores ---\n");
    for(int j=0;j<numPlayers;j++){
            printf("For player %d, their score was:\n", j+1);
            players[j].displayScore();
            printf("\n");
    }

    int maxScoreIndex = 0;
    for(int j=0;j<numPlayers;j++){
        if(players[j].score > players[maxScoreIndex].score) maxScoreIndex = j;
    }
    printf("The player with the highest score was Player %d with the score: %d\n", maxScoreIndex+1, players[maxScoreIndex].score);
        

    return 0;
}