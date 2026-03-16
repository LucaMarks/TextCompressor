#include "../mainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(CharacterCount *characterCount, char word[], int size);

void treeRunner(CharacterCount *characterCount, char word[], int size) {
    makeTree(characterCount, word, size);
}

/*
    build huffman tree:
    step 1 -> put all the cc's of same count in a row
    step 2 -> add them up two at a time
    step 3 ->

 */

void makeTree(CharacterCount *characterCount, char word[], int size) {
    //build a huffman tree assuming the characterCount array is already sorted
    //build from the bottom right up
    int prevLetterCount = 1;
    int currRow = 0;

    //maybe need an array of nodes, should look at how java does trees
    treeNode *node = createNode(characterCount[0]);
    printf("adding node to tree -> [%c, %d]\n", node[0].cc.letter, node[0].cc.count);
    for (int i = 1; i < size; i++) {
        //make row
        if (node[i].cc.count > prevLetterCount) {
            prevLetterCount = node[i].cc.count;
            currRow++;
            //need to add up values
        } else if (node[i].cc.count == prevLetterCount) {
            treeNode *newLeftNode = createNode(characterCount[i]);
        }
        printf("adding node to tree -> [%c, %d]\n", node[i].cc.letter, node[i].cc.count);
    }
}
