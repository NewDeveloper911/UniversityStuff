#include <stdio.h>

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int pascal(int n, int r){
    return factorial(n) / (factorial(n-r) * factorial(r));
}

int main(){
    //Keep in mind that due to double digits, this pascal triangle no loonger looks perfect after row 6
    int rows, spacesOnRow = 0;
    scanf("%i", &rows);
    spacesOnRow = 2 * rows - 1;
    for(int n=0; n < rows; n++){
        for(int j=0; j < spacesOnRow / 2; j++){ printf(" ");}
        //C throws a hissy fit if you try to use %i to represent integers. Just use %d instead
        for(int r=0; r < n+1; r++) {printf("%d ", pascal(n, r));}
        for(int j=0; j < spacesOnRow / 2 - 1; j++){ printf(" ");}
        printf("\n");
        spacesOnRow -= 2;
    }
}