// #include "../MainHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **wordList;
char *getLetter(char *code, CharacterCode *characterCodes, int ccIndex);

void decodeRunner(CharacterCode *characterCodes, int ccIndex) {
    //open file
    FILE *file = fopen("../compressedText.txt", "r");
    char buffer[255];

    if (file == NULL) {
        printf("FILE IS EQUAL TO NULL!!!\n");
        return;
    }

    //25 words allocated
        //->dummy #
    wordList = malloc(25);
    *wordList = malloc(25);

    int lineCount = 0;
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        // printf("Made it here!");
        wordList[lineCount] = malloc(strlen(buffer) + 1);
        wordList[lineCount] = buffer;
        lineCount++;
    }
    //need to loop through each char to get this right
    //otherwise we will have issues since lineCount var is 1 for this demo
    //this will only run once for demo
    //count represents how many characters we have per line
    //  -> this will need to be refactored after demo
    int count = 0;
    for(int i = 0; i < lineCount; i++){
        for (int j = 0; j < strlen(wordList[i]); j++) {
            count++;
        }
    }


    //will also need to make a new characterCount array
    char **codes;
    int currCodeIndex = 0;
    //change these later
    //storing 26 words (codes)
    codes = malloc(26 * sizeof(char));
    *codes = malloc(2 * sizeof(char));
    // *codes = &malloc(2 * sizeof(char));

    //assume every character code has the same # of bits
    int codeSize = sizeof(*(characterCodes[0].code));
    // printf("%d\n", codeSize);
    printf("%d\n", count);
    //temp
    int currLineCount = 0;
    for (int i = 0; i < count-1; i+=codeSize+1) {
        printf("%d, [%c, %c]\n", i, wordList[currLineCount][i], wordList[currLineCount][i+1]);
        codes[currCodeIndex][0] = wordList[currLineCount][i];
        codes[currCodeIndex][1] = wordList[currLineCount][i+1];
        currCodeIndex++;

    }
    //would probably be a good idea to free xtra space in codes pointer
    for (int i = 0; i < currCodeIndex; i++) {

        char *letter = (getLetter(codes[currCodeIndex], characterCodes, ccIndex));

        printf("%c\n", *letter);
        free(letter);
    }
}

char *getLetter(char *code, CharacterCode *characterCodes, int ccIndex) {

    for (int i = 0; i < ccIndex; i++) {

        if (characterCodes[i].code == code) {
            char *letter = malloc(sizeof(char));
            *letter = characterCodes[i].letter;
            return letter;
        }
    }
    return NULL;
}
