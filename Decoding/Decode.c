#include "../MainHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decodeRunner(TreeNode *headNode);
char *convertLine(TreeNode *headNode, char *line);
//global var
int currLine = 0;

void decodeRunner(TreeNode *headNode) {
    currLine++;
    // printf("This runs!\n");

    FILE *file = fopen("../CompressedText.txt", "r");
    FILE *decompressed = fopen("../DecompressedText.txt", "a");

    char line[255];
    //get to the right line
    for (int i = 0; i < currLine; i++){
        fgets(line, sizeof(line), file);
    }
    int len = strlen(line);
    // printf("%d\n", len);
    char *newLine = malloc(len -1);
    int i = 0;
    for (i = 0; i < len-1; i++) {
        newLine[i] = line[i];
    }
    newLine[i] = '\0';
    printf("new line -> %s\n", newLine);

    char *convertedLine = convertLine(headNode, newLine);
    printf("%s\n\n", convertedLine);
    //write line if it's correct
    fprintf(decompressed, "%s\n", convertedLine);

    free(newLine);
    free(convertedLine);

    fclose(file);
    fclose(decompressed);
}

char *convertLine(TreeNode *headNode, char *line) {
    char *sentence = malloc(255 * sizeof(char));
    int sentenceIndex = 0;

    TreeNode *currNode = headNode;

    // printf("strlen -> %d", strlen((line)));
    for (int i = 0; i < strlen(line)+1; i++) {
        // printf("this Runs!\n");
        if (line != NULL) {
            // printf("%c", line[i]);
            if (currNode->isLeaf) {
                sentence[sentenceIndex] = currNode->letter;sentenceIndex++;
                printf("Letter %c found!\n", sentence[sentenceIndex-1]);
                currNode = headNode;
                }
            if (line[i] == '0') {
                currNode = currNode->left;
                // printf("0\n");
            }
            if (line[i] == '1') {
                currNode = currNode->right;
                // printf("1\n");
            }

        }else{printf("Error! line index %d is null for given line (Decode.c 10)\n");return NULL;}
    }
    // printf("%d\n", strlen(sentence));
    sentence[sentenceIndex] = '\0';
    char *sentenceBuff = realloc(sentence, strlen(sentence) + 1);
    // //clean up sentence
    // //realocate
    // char *sentenceBuff = malloc((sentenceIndex) * sizeof(char));
    //this is always going to be problematic since sentenceIndex = 14 for mississippi when it should be 11
    // for (int i = 0; i < sentenceIndex; i++) {
    //
    // // printf("This works!\n");
    //     // printf("%c", sentence[i]);
    //     sentenceBuff[i] = sentence[i];
    // }
    // sentence[sentenceIndex] = '\0';
    // printf("%s\n", sentenceBuff);
    // free(sentence);
    // // free(sentenceBuff);
    //
    // // printf("%s\n", sentence);
    return sentenceBuff;
}