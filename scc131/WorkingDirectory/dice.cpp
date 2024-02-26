#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define DEBUG 1

class Dice {
    public:
        int numSides,guess;
        Dice(int sides);
        Dice(){};

        int roll(){
            int rollResult = rand() % numSides;
            numSides = rollResult;
            if(!DEBUG);
                printf("%d\n",rollResult);
            return rollResult;
        }

        void makeAGuess(){
            printf("Make a guess from 1 to %d.\n", numSides);
            //This isn't necessarily possible - still keeps default value of 0
            scanf("%d",&guess);
        }
};

Dice::Dice(int sides){
    if(sides >= 2)
        numSides = sides;
    else{
        printf("You can't create a Dice with less than two sides. A default value of 6 is chosen.\n");
        numSides = 6;
    }
        
}
void printResult(Dice d, int rolled_number){
    if (d.guess-rolled_number==0)
        printf("Lucky you! You WON..\n");
    else
        printf("Better luck next time! the dice rolled %d\n", rolled_number);
        
}

int main() {
    srand(time(NULL));

    int numSides = 0;
    printf("Enter the number of sides: ");
    scanf("%d",&numSides);
    Dice sixSidedDice(numSides);
    sixSidedDice.makeAGuess();

    int rolled_number = sixSidedDice.roll();

    printResult(sixSidedDice, rolled_number);


    return 0;
}