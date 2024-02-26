#include <stdio.h>
#include <stdbool.h>

int main(){
    int scores[10] = {0};
    int score = 10;
    int temp, lastFull= 0;
    bool swapped, full = false;
    while (score != 0){
        printf("Enter high score (0 to exit):\n");
        scanf("%d", &score);

        //Scanning for the next available spot in the array
        for(int i=0; i<10; i++) {
            //Found one
            if(scores[i] == 0){
                full = false;
                //Greater than the smallest value in the array
                if(score > scores[9]){
                    full = false;
                    scores[i] = score;
                    lastFull = i;
                    break;
                }
            }
            else{
                if(i == 9) printf("The array is full unfortunately. You can't put any more in.\n");
            }
        }

        //Sorting algorithm part
        //Insertion sort because it's simpler to program
        for(int i=0; i < 10; i++){
            int current = scores[i];
            int index2 = i;
            while(index2 > 0 && scores[index2-1] < current){
                scores[index2] = scores[index2 - 1];
                index2 -= 1;
            }
            scores[index2] = current;
        }

        printf("*** HIGH SCORE TABLE ***\n");
        for(int i=0;i<10;i++){
            printf("%d - %d\n", i+1, scores[i]);
        }
        printf("Highest score = %d\n", scores[0]);
        printf("Lowest score = %d\n", scores[lastFull]);
    }
}
