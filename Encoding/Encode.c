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
    //  -> Or just refactor to that later

    /*
        this needs some work
        at the start of the loop, we need to create a new node (don't do this outside the loop)
        this is not an initialization, this should be dont at the start of every iteration
        then we need to figure out where to put it using logic
            -> The first option might not necesarily go in the [0][0] spot

        can't lie i think i did this backwards
        why would you build a tree from the bottom up
        should probably rewrite this, no need for a 2d array right?
        what might be better is to create the head node, and go down from there
        we should be able to do this since we already know the count of each variable
     */
    treeNode **treeArray = malloc((sizeof(treeNode) * characterCount[size-1].count) * size);
    treeNode *node = createNode(characterCount[0]);
    printf("adding node to tree -> [%c, %d]\n", node[0].cc.letter, node[0].cc.count);
    for (int i = 1; i < size; i++) {
        if (i == 1) {
            // treeNode *newNode = createNode(characterCount[i]);
            // treeArray[currRow][rowSize] = *newNode;;
            treeArray[currRow][rowSize] = *createNode(characterCount[i-1]);
            continue;
        }


        //make row
        if (node->cc.count > currRow+1) {
            printf("moving up a row\n");
            currRow = node[i].cc.count -1;
            rowSize = 0;
            //we should add the node for curr i b4 we move on since the next if statement will not get triggered
            //need to add up values from previous row

        } else if (node[i-1].cc.count == currRow -1) {// add one to the same row
            printf("    adding to row %d", currRow);
            treeNode *newLeftNode = createNode(characterCount[i]);
            treeArray[currRow][rowSize] = *newLeftNode;

            rowSize++;
        }
        printf("adding node to tree -> [%c %d], row num=%d\n", treeArray[currRow][rowSize].cc.letter, treeArray[currRow][rowSize].cc.count, currRow);
    }
}
