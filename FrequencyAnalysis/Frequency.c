#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../MainHeader.h"

int getCharacters();
int getRepeatingCharacters(char word[], CharacterCount **characterCount);
int checkRepeatedCharacter(CharacterCount *characterCount, int size, char character);
void cleanUpCharacterCount(CharacterCount **characterCount, int size);

// char *words[24];

int getCharacters() {
    //read the file
        char buffer[255];
        char *currLine;

        FILE *file = fopen("../text.txt", "r");
        while (fgets(buffer, sizeof(buffer), file)) {
            buffer[strcspn(buffer, "\n")] = 0;
            CharacterCount *characterCount = malloc((strlen(buffer)+1) * sizeof(CharacterCount));

            int size = getRepeatingCharacters(buffer, &characterCount);
            // printf(" size is -> %d\n", size); works till here

            cleanUpCharacterCount(&characterCount, size);

            convertToBytes(buffer, characterCount, size);


            free(characterCount);

        }
        fclose(file);
}
void cleanUpCharacterCount(CharacterCount **characterCount, int size) {

    printf("size -> %d (clenaUpCharacterCount)\n", size);
    // printf("%p\n", (void*)characterCount);
    CharacterCount *buff = malloc(size * sizeof(CharacterCount));


    for (int i = 0; i < size; i++) {
        buff[i] = (*characterCount)[i];
    }

    free(*characterCount);

    *characterCount = buff;
}


int getRepeatingCharacters(char *word, CharacterCount **characterCount) {
    int index = 0;

    // for (int i = 0; i < strlen(word); i++) {printf("%c\n", word[i]);}

    for (int i = 0; i < strlen(word); i++) {
        int repeatedCharacter = checkRepeatedCharacter(*characterCount, index, word[i]);
        // printf("running here\n");

        if (repeatedCharacter > -1) {

            // printf("adding existing letter %c\n", word[i]);
            //letter has already been accounted for
            (*characterCount)[repeatedCharacter].count++;
        }
        else {
            //letter has not already been accounted for & we need to create a new characterCount object
            // printf("adding new letter...%c\n", word[i]);
            (*characterCount)[index].letter = word[i];
            (*characterCount)[index].count = 1;

            index++;
        }
    }
    return index;
}
int checkRepeatedCharacter(CharacterCount *characterCount, int size, char character) {
    printf("Checking letter %c(checkRepatedCharacter)\n", character);

    for (int i = 0; i < size; i++) {
        if (characterCount[i].letter == character) {
            return i;
        }
    }
    return -1;
}