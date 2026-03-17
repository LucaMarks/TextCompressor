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
    int currRow = 0;
    int rowSize = 0;

    //add a 2d array of nodes where the list represents an array of rows
    //  -> Or this is done by priority queue which is probably a better approach
    //  -> Or just refactor this later
    treeNode **treeArray = malloc((sizeof(treeNode) * characterCount[size-1].count) * size);
    treeNode *node = createNode(characterCount[0]);
    printf("adding node to tree -> [%c, %d]\n", node[0].cc.letter, node[0].cc.count);
    for (int i = 1; i < size; i++) {
        //make row
        if (node->cc.count > currRow+1) {//node[i] might not be the correct thing to do, it's not an array
            currRow = node[i].cc.count -1;
            rowSize = 0;
            //need to add up values from previous row

        } else if (node[i].cc.count == currRow -1) {// add one to the same row
            treeNode *newLeftNode = createNode(characterCount[i]);
            treeArray[currRow][rowSize] = *newLeftNode;

            rowSize++;
        }
        printf("adding node to tree -> [%c, %d]\n", node[i].cc.letter, node[i].cc.count);
    }
}
