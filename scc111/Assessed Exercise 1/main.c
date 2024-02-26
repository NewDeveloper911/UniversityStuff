#include <stdio.h>
#include <ctype.h>

int vowels_to_numbers(FILE *plainFile, FILE *cipherFile){
    if(plainFile == NULL || cipherFile == NULL){
        //If the file pointers are null
        return 0;
    }
    else{
        int c;
        char *currentChar;

        //Array of vowels to look for in the fileContent
        char vowels[]= {'a','e','i','o','u'};
        //Corresponding numbers to insert into the cipherFile text
        char numbers[] = {'2','3','1','0','4'};

        while((c = getc(plainFile)) != EOF){
            //Runs for every character in the vowels array
            for(int j=0;j<5;j++){
                //If a vowel has been found, replace it
                if(c == vowels[j]){
                    putc(numbers[j], cipherFile);
                    break;
                }
                else{
                    //Otherwise the normal character gets appended to the cipherFile text
                    if(j==4) putc(c, cipherFile);
                }
            }
        }

        //Should return 1 here as the file should be successfully encrypted
        return 1;
    }
    
}

int remove_vowels(FILE *plainFile, FILE *cipherFile){
    if(plainFile == NULL || cipherFile == NULL){
        //If the file pointers are null
        return 0;
    }
    else{
        int c;

        //Array of vowels to look for in the fileContent
        char vowels[]= {'a','e','i','o','u'};

        while((c = getc(plainFile)) != EOF){
            //Runs for every character in the vowels array
            for(int j=0;j<5;j++){
                //If a vowel has been found, skip it
                if(c == vowels[j]){
                    break;
                }
                else{
                    //Otherwise the normal character gets appended to the cipherFile text
                    if(j==4) putc(c, cipherFile);
                }
            }
        }

        //Should return 1 here as the file should be successfully encrypted
        return 1;
    }
}

int caesar_cipherFile(FILE *plainFile, FILE *cipherFile){
    if (plainFile == NULL || cipherFile == NULL) return 0;
    else{
        int c;
        while((c = getc(plainFile)) != EOF){
            if(isalpha(c) != 0){
                //This specific character is a letter
                //Now I must check if it is a 'z'
                if(c == 122){
                    putc('a', cipherFile);
                }
                else{
                    //Must  increment the character by one and put that in the cipherFile text
                    c++;
                    putc(c, cipherFile);
                }
            }
            else{
                //Want to skip the \n characters and escape
                if(c == '\\') c = getc(plainFile);
                else{ putc(c, cipherFile);}
            }
        }
    }
}

int main(){
    FILE *plainFile;
    FILE *cipherFile;
    int option = 0;

    //Opening all necessary files for the program
    plainFile = fopen("plain.txt","r");
    cipherFile = fopen("cipher.txt", "w");

    //Presents the options to the user
    printf("Which encryption algorithm would you like to use?\nPlease select from the following options:\n");
    printf("1: Vowels to numbers\n2: Remove vowels\n3: Caesar cipher\n");
    scanf("%d", &option);

    //The user makes their choice and the relevant procedure is run
    switch(option){
        case 1:
            vowels_to_numbers(plainFile, cipherFile);
            break;
        case 2:
            remove_vowels(plainFile, cipherFile);
            break;
        case 3:
            caesar_cipherFile(plainFile, cipherFile);
            break;
    }

    //Not forgetting to close files when done with them
    fclose(plainFile);
    fclose(cipherFile);

    return 0;
}