#include "../MainHeader.h"
#include <stdio.h>
#include <stdlib.h>



void insertionSort(CharacterCount **list);
void assignBits(CharacterCount *characterCounts);
int wordSize;

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



