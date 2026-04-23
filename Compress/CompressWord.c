#include "../MainHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionSort(CharacterCount **list);
void assignBits(CharacterCount *characterCounts);
char *getCode(char letter);

int wordSize;
CharacterCode *characterCodes_;
int ccIndex_;

void convertToBytes(char word[], CharacterCount *characterCount, int wordSize_) {
    wordSize = wordSize_;
    for (int i = 0; i < wordSize; i++) {
        printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
    }

    printf("Sort the list below\n");

    insertionSort(&characterCount);
    for (int i = 0; i < wordSize; i++) {
        printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
    }

    encodeRunner(characterCount, word, wordSize);
    characterCodes_ = *getCharacterCodes();
    ccIndex_ = *getCharacterCodeLen();

    for (int i = 0; i < ccIndex_; i++) {
        printf("[%s %c]\n", characterCodes_[i].code, characterCodes_[i].letter);
    }

    //write data to file
    FILE *file = fopen("../compressedText.txt", "w");
    // printf("%d\n", wordLen);
    for (int i = 0; i < strlen(word); i++) {
    //use a helper method to get the correct code, then add in the code
    char *code = getCode(word[i]);
    fprintf(file, "%s", code);
    // fprintf(file)
    }

    fclose(file);
}


char *getCode(char letter) {
    for (int i = 0; i < ccIndex_; i++) {
        if (characterCodes_[i].letter == letter) {
            return characterCodes_[i].code;
        }
    }
    return NULL;
}

void insertionSort(CharacterCount **list) {
    CharacterCount *temp = *list;
    int i, j;
    CharacterCount key;
    for (i = 1; i < wordSize; i++) {
        key = temp[i];
        for (j = i - 1; j >= 0 && temp[j].count > key.count; j--) {
            temp[j + 1] = temp[j];
        }
        temp[j+1] = key;
    }
}



