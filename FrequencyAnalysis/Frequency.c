#include "Frequency.h"
#include <stdio.h>
#include <string.h>

typedef struct{
    char letter;
    int count;
}CharacterCount;

int getCharacters();
void getRepeatingCharacters(char word[], CharacterCount characterCount[]);
int checkRepeatingCharacter(CharacterCount characterCount[], char character);
void printCharacterCount(CharacterCount characterCount[]);

int getCharacters() {
    //read the file
    FILE *file = fopen("../text.txt", "r");
    char buffer[1024] = {0};

    if (file == NULL) {
        printf("Error finding file!\n");
        return 1;
    }

    char *words[24];

    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        // words[count] = buffer;
        buffer[strcspn(buffer, "\n")] = 0;
        words[count] = strdup(buffer);

        count++;
    }

    for (int i = 0; i < count; i++) {

        printf("%d\n", strlen(words[i]));

        CharacterCount characterCount[strlen(words[i]) + 1];
        //lokey this line is optional
        memset(characterCount, 0, sizeof(characterCount));

        getRepeatingCharacters(words[i], characterCount);
        printCharacterCount(characterCount);
    }

    fclose(file);
}
void printCharacterCount(CharacterCount characterCount[]) {
    for (int i = 0; i < characterCount[i].letter != '\0'; i++) {
        printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
    }
}

void getRepeatingCharacters(char word[], CharacterCount characterCount[]) {

    int nextSlot = 0;
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
            printf("\n");
        }
    }
    characterCount[nextSlot].letter = '\0';
}
int checkRepeatingCharacter(CharacterCount characterCount[], char character) {
    printf("Checking for %c ->", character);
    for (int i =0; i < characterCount[i].letter != '\0'; i++) {
        if (characterCount[i].letter == character) {
            printf(" %c already exists\n", character);
            return i;
        }
    }
    printf("\n");
    return -1;
}