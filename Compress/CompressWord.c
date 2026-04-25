#include "../MainHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionSort(CharacterCount **list);
void assignBits(CharacterCount *characterCounts);
char *getCode(char letter);
void pad();
char **getBits(char **line);

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

    TreeNode *headNode = encodeRunner(characterCount, word, wordSize);
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

    //b4 we do decode runner
    /*
        Convert to bytes
        pad the end
     */

    pad();

    // printf("This runs!");

    // free(characterCodes_);
    decodeRunner(headNode);



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

void pad() {
    FILE *file = fopen("../compressedText.txt", "r");

    char buff[255];

    char *line;

    while (fgets(buff, sizeof(buff), file) != NULL) {
        //might be better to make the realloc instead
        line = malloc(strlen(buff)+1);
        line = buff;
        //split to bits
        // getBits(&line);
        //# of 0 bits we need to add
        // printf("Need to add %d bits\n", numBytes);
    }

    int numBytes = 8 - strlen(line) % 8;
    // printf("%d % 8 = %d\n", strlen(line), numBytes);



    FILE *writeFile = fopen("../compressedText.txt", "a");
    // fprintf(writeFile, "%s", bits);
    for (int i = 0; i < numBytes; i++) {
        fprintf(writeFile, "0");
        // printf("%c", bits[i]);
    }


    // printf("Made it here\n");
    fclose(writeFile);

    // fseek(read)
    // fprintf()

}
