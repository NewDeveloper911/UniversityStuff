#include <stdio.h>

int main(){
    float femurLength, tibiaLength = 0.0;
    //This line is used to get the computer to expect a float as input
    //This input is then going to be stored in the variable femurLength
    printf("You should tell me how long the femur is.\n");
    scanf("%f", &femurLength);
    printf("You should tell me how long the tibia is.\n");
    scanf("%f", &tibiaLength);
    printf("Height = %.2fcm ± %.2f\n", 2.38 * femurLength + 61.41, 3.27);
    printf("Tibia length = %.2f\n", tibiaLength);
}