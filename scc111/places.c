#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Can declare records in C using structures
struct location{
    char name[20];
    float latitude;
    float longitude;
};

int add_new_location(struct location newLoc, struct location *list, int numLocations){
    if(numLocations < 10){
        list[numLocations] = newLoc;
    }

}
void print_locations(struct location *list, int numLocations){
    for(int i=0;i<numLocations;i++){
        printf("Place %d is %s at %.6f, %.6f\n", i, list[i].name, list[i].latitude, list[i].longitude);
    }

}

int main(){
    const char *joints[] = {"Barkers", "The Mill", "County", "Library", "Pitch"};
    struct location places[10];
    int numLocations = 0;
    for(int i=0;i<5;i++){
        struct location l1;
        //HAve to use strcpy to assign string values to a variable in a structure
        strcpy(l1.name, joints[i]);
        l1.latitude = ((float)random()/(float)(RAND_MAX)) * 91;
        l1.longitude = ((float)random()/(float)(RAND_MAX)) * 181;
        add_new_location(l1, places, numLocations);
        numLocations++;
    }
    print_locations(places, numLocations); 
}



