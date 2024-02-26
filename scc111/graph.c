#include <stdio.h>
#include <string.h>

const int MAX_SET = 10;
/*
Funnily enough, when passing an array as a paramter to a function, one must declare the size of the array,
at least in the smllest array size within the multidimensional array.

E.g in my case, the tuples within the array of tuples
*/

int in_set(int set[][2], int a, int b){
    //Thinking about returning a 0 to indicate false and 1 to indicate true
    for(int i=0; i<10; i++){
        //Iterating across the max number of tuples stored
        if(set[i][0] == a && set[i][1] == b){
            //Boom - we've found a matching tuple
            //Remember that 1 means it's true - the match exists
            return 1;
        }
    }
    //Unfortunately, we've not found a matching tuple
    return 0;
}

void add_to_set(int set[][2], int map[MAX_SET][MAX_SET], int a, int b){
    for(int i=0; i<MAX_SET; i++){
        if(set[i][0] == 0 && set[i][1] == 0){
            //Found our next gap to insert another tuple in
            set[i][0] = a;
            set[i][1] = b;
            //1 will represent the existence of the tuple marked at (a,b)
            map[a][b] = 1;
            return;
        }
    }
    printf("Unfortunately, there's no more space to insert another tuple.\n");
}

int remove_from_set(int set[][2], int map[MAX_SET][MAX_SET], int a, int b){
    for(int i=9; i<0; i--){
        if(set[i][0] != 0 && set[i][1] != 0){
            //Found our next gap to remove another tuple - indicated by double 0s
            set[i][0] = 0;
            set[i][1] = 0;
            //Resets this part of the array to indicate that this tuple doesn't exist
            map[a][b] = 0;
            break;
        }
    }
    printf("Unfortunately, there are no more tuples to delete.\n");
}

int num_elements(int set[MAX_SET][2]){
    int goOn = 1;
    int numElements = 0;
    int elem1, elem2 = 0;
    while(goOn == 1){
        if(numElements < MAX_SET) {
            elem1 = set[numElements][0];
            elem2 = set[numElements][1];
            if(elem1 != 0 && elem2 != 0) numElements += 1;
        }
        else{
            goOn = 0;
        }
    }
    return numElements;
}

void print_set(int set[MAX_SET][2]){
    for(int i=0; i<MAX_SET; i++){
        printf("Element %d: {%d,%d}\n",i+1, set[i][0], set[i][1]);
    }
}

int is_reflexive(int set[][2]){
    //For every element, there must be a tuple of its duplicates
    for(int i=0; i<MAX_SET; i++){
        if(in_set(set, set[i][0], set[i][0]) == 0 || in_set(set, set[i][1], set[i][1]) == 0) return 0;
    }
    return 1;
}
int is_symmetric(int set[][2]){
    //If there's a tuple (2,1), then there must be a (1,2) tuple somewhere
    for(int i=0; i<MAX_SET; i++){
        if(in_set(set, set[i][0], set[i][1]) == 1 && in_set(set, set[i][1], set[i][0]) == 0) return 0;
    }
    return 1;
}

//This function isn't working perfectly yet
int is_transitive(int set[][2], int map[MAX_SET][MAX_SET]){
    int elem1, elem2, elem3 = 0;
    for(int i=0; i < MAX_SET; i++){
        elem1 = set[i][0];
        elem2 = set[i][1];
        if(elem1 != 0 && elem2 != 0){
            for(int j=0; i<MAX_SET; j++){
            //Iterating across all possible tuple combinations using the second element in the first tuple
            if(map[elem2][j] == 1){
                //We've found one of such tuple combinations
                if(in_set(set, elem1, j) == 0) return 0;
            }
        }
        }else{
            continue;
        }
    }
    return 1;
}

int main(){
    /*
        We would suggest representing a social media account as an integer,
        and a ‘binary relation’ (link/ friend relationship) as a tuple.
    */
    int graph[MAX_SET][2]; //Creates a 2D containing 10x2 arrays
    //Much faster way to initialise an array filled with a single character - unfortnuately needs the string.h library
    memset(graph, 0, sizeof(graph));
    

    int map[MAX_SET][MAX_SET]; //Creates a 2D array containing 10*10 arrays
    memset(map, 0, sizeof(map));


    //Each row is the first digit of the tuple and the column is the 2nd

    // Add some tuples
    add_to_set(graph, map, 1, 1);
    add_to_set(graph, map, 2, 1);
    add_to_set(graph, map,  2, 2);
    add_to_set(graph, map, 1, 2);
    add_to_set(graph, map, 2, 3);
    add_to_set(graph, map, 3, 2);
    add_to_set(graph, map, 3, 3);
    add_to_set(graph, map, 3, 1);
    add_to_set(graph, map, 1, 3);

    print_set(graph);

    int reflexive, symmetric, transitive = 0;
    reflexive = is_reflexive(graph);
    symmetric = is_symmetric(graph);
    transitive = is_transitive(graph, map);

    printf("The values of this set's reflexivity, symmetry and transistivity are as follows: %d,%d,%d\n", reflexive, symmetric, transitive);

}