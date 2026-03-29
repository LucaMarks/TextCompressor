#include "../mainHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct{
//     char letter;
//     int count;
// }CharacterCount;

int getCharacters();
void getRepeatingCharacters(char word[], CharacterCount characterCount[]);
int checkRepeatingCharacter(CharacterCount characterCount[], char character);
void printCharacterCount(CharacterCount *characterCount);

void cleanupCharacterCount(CharacterCount **characterCount);

int nextSlot = 0;
char *words[24];
int ind = 0;
int size = 0;

int getCharacters() {
    //read the file
    FILE *file = fopen("../text.txt", "r");
    char buffer[1024] = {0};

    if (file == NULL) {
        printf("Error finding file!\n");
        return 1;
    }


    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        // words[count] = buffer;
        buffer[strcspn(buffer, "\n")] = 0;
        words[count] = strdup(buffer);

        count++;
    }

    for (ind = 0; ind < count; ind++) {

        printf("%d\n", strlen(words[ind]));

        CharacterCount *characterCount = malloc((strlen(words[ind]) + 1) * sizeof(CharacterCount));
        //lokey this line is optional
        memset(characterCount, 0, sizeof(characterCount));

        getRepeatingCharacters(words[ind], characterCount);
        printf("\n");
        printCharacterCount(characterCount);
        printf("\n");
        cleanupCharacterCount(&characterCount);
        size = nextSlot;
        printf("Frequency Analysis Finished\n");
        convertToBytes(words[ind], characterCount, size);
    }

    fclose(file);

}
void printCharacterCount(CharacterCount *characterCount) {
    for (int i = 0; i < nextSlot; i++) {
        printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
    }
}

// need to fix this with the pointers or sum
// void cleanupCharacterCount(CharacterCount *characterCount[]) {
//
//     // nextSlot--;
//     CharacterCount buffCharacterCount[nextSlot];
//     for (int i = 0; i < nextSlot; i++) {
//         printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
//         buffCharacterCount[i] = characterCount[i];
//     }
//     free(characterCount);
//     characterCount = &buffCharacterCount;
//     // printCharacterCount(buffCharacterCount);
// }
void cleanupCharacterCount(CharacterCount **characterCount) {
    CharacterCount *newArray = malloc(nextSlot * sizeof(CharacterCount));
    for (int i = 0; i < nextSlot; i++) {
        newArray[i] = (*characterCount)[i];
        printf("[%c, %d]\n", newArray[i].letter, newArray[i].count);
    }

    free(*characterCount);
    //new array is a pointer
    *characterCount = newArray;
}

void getRepeatingCharacters(char word[], CharacterCount characterCount[]) {

    nextSlot = 0;
    for (int i = 0; i < strlen(word); i++) {
        int repeatedCharacter = checkRepeatingCharacter(characterCount, word[i]);
        if (repeatedCharacter > -1) {
            //the letter has already been accounted for
            characterCount[repeatedCharacter].count++;
        }else{//the letter has not already been accounted for and we need to create a new letter for it
            // printf("adding %c\n", word[i]);
            characterCount[nextSlot].letter = word[i];
            characterCount[nextSlot].count = 1;

            nextSlot ++;
            // printCharacterCount(characterCount);
            // printf("\n");
        }
    }
    // nextSlot--;
    // characterCount[nextSlot].letter = '\0';
}
int checkRepeatingCharacter(CharacterCount characterCount[], char character) {
    printf("Checking for %c ->", character);
    for (int i = 0; i < nextSlot; i++) {
        // printf("    %c\n", characterCount[i].letter);
        if (characterCount[i].letter == character) {
            printf(" %c already exists\n", character);
            return i;
        }
    }
    printf("\n");
    return -1;
}