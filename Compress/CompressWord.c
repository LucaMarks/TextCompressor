#include "CompressWord.h"
#include "../FrequencyAnalysis/Frequency.h"
#include <stdio.h>
#include <stdlib.h>

void insertionSort(CharacterCount **list, int size);

void convertToBytes(char word[], CharacterCount *characterCount, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
    }

    printf("\n");
    //sort the list
    insertionSort(&characterCount, size);

    for (int i = 0; i < size; i++) {
        printf("[%c, %d]\n", characterCount[i].letter, characterCount[i].count);
    }
}
void insertionSort(CharacterCount **list, int size) {
    CharacterCount *temp = *list;
    int i, j;
    CharacterCount key;
    for (i = 1; i < size; i++) {
        key = temp[i];
        for (j = i - 1; j >= 0 && temp[j].count > key.count; j--) {
            temp[j + 1] = temp[j];
        }
        temp[j+1] = key;
    }
    *list = temp;
}


