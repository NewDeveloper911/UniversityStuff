#include <stdio.h>

int main(){
    int squareLength = 0;
    scanf("%i", &squareLength);
    for(int i=0; i < squareLength; i++){
        for(int j=0; j < squareLength; j++){
            if(i > 0 && i < (squareLength-1) && j > 0 && j < (squareLength-1)) {printf(" ");} 
            else {printf("*");}
        }
        printf("\n");
    }
}