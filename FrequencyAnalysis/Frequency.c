#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../MainHeader.h"

int getCharacters();
int getRepeatingCharacters(char word[], CharacterCount **characterCount);
int checkRepeatedCharacter(CharacterCount *characterCount, int size, char character);
void cleanUpCharacterCount(CharacterCount **characterCount, int size);

char *words[24];

int getCharacters() {
    //read the file
    FILE *file = fopen("../text.txt", "r");
    char buffer[1024] = {0};
    if (file == NULL) {
    printf("File not found!\n");
    return 1;
    }

    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        words[count] = strdup(buffer);

        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", strlen(words[i]));


        CharacterCount *characterCount = malloc(strlen(words[i]) +1 * sizeof(CharacterCount));

        memset(characterCount, 0, sizeof(CharacterCount));

        int size = getRepeatingCharacters(words[i], &characterCount);
        cleanUpCharacterCount(&characterCount, size);

        convertToBytes(words[i], characterCount, size);
    }


    fclose(file);

}
void cleanUpCharacterCount(CharacterCount **characterCount, int size) {
    CharacterCount *buff = malloc(size * sizeof(CharacterCount));

    for (int i = 0; i < size; i++) {
        buff[i] = (*characterCount)[i];
    }

    free(*characterCount);

    *characterCount = buff;
}


int getRepeatingCharacters(char *word, CharacterCount **characterCount) {
    int index = 0;

    for (int i = 0; i < strlen(word); i++) {
        int repeatedCharacter = checkRepeatedCharacter(*characterCount, index, word[i]);

        if (repeatedCharacter > -1) {
            //letter has alreay been accounted for
            characterCount[repeatedCharacter]->count++;
        }
        else {
            //letter has not already been accounted for & we need to create a new characterCount object
            characterCount[index]->letter = word[i];
            characterCount[index]->count = 1;

            index++;
        }
    }
    return index;
}
int checkRepeatedCharacter(CharacterCount *characterCount, int size, char character) {

    for (int i = 0; i < size; i++) {
        if (characterCount[i].letter == character) {
            return i;
        }
    }
    return -1;
}