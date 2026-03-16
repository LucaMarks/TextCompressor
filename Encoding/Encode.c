#include "../mainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(CharacterCount *characterCount, char word[] ,int size);

void treeRunner(CharacterCount *characterCount, char word[], int size) {
    makeTree(characterCount, word, size);

}

void makeTree(CharacterCount *characterCount, char word[], int size) {
    //build a huffman tree assuming the characterCount array is already sorted
    //build from the bottom right up
    // for (int i = 0; i < size; i++) {
        treeNode *node = createNode(characterCount[0]);
    treeNode myNode = *node;
    printf("from tree -> [%c, %d]\n", myNode.cc.letter, myNode.cc.count);
    // }
}