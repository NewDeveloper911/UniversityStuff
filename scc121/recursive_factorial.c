#include <stdio.h>

long factorial(long num){
    //The largest number whose factorial can be correectly computed using int is 12
    //That's because the number of availabe digits in 2's complement is 32
    //Long overcomes this issue by using 64 bits instead of 32
    //Any larger numbers would result in overflow
    if(num == 0){
        return 1;
    }
    return num * factorial(num-1);
}

int main(){
    long number;
    printf("Please enter a number:\n");
    scanf("%d", &number);
    printf("%d", factorial(number));
}
