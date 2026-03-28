#include "../mainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(CharacterCount *characterCount, int size);
TreeNode *getLeafNodes(CharacterCount *characterCount, int size);
void cleanUpArray(TreeNode **nodes, int size);
void printNodes(TreeNode *nodes, int size);
void connectToHead(TreeNode **nodes, int **size_);

void assignValues(TreeNode *headNode, int size);

void encodeRunner(CharacterCount *characterCount, char word[], int size) {
    printf("\n");
    makeTree(characterCount, size);
    TreeNode *head = malloc(sizeof(TreeNode));
    assignValues(&head, size);
}

//build huffman tree
//every item in characterCount is a leaf node
void makeTree(TreeNode **head, CharacterCount *characterCount, int size) {
    // printf("Size is %d", size);
    TreeNode *leafs = getLeafNodes(characterCount, size);
    //add up all leaf nodes in this order
    TreeNode *nodes = malloc(size * sizeof(TreeNode));
    int nodeSize = 0;
    // printf("leaf node -> [%c %d]\n", leafs[0].letter, leafs[0].level);
    for (int i = 0; i < size; i+=2) {
        // printf("Made it here %d\n", i);
        // printf("leaf node -> [%c %d]\n", leafs[i].letter, leafs[i].level);
        TreeNode *node = createNode(leafs[i].level + leafs[i+1].level);
        setRight(node, &leafs[i]);
        setLeft(node, &leafs[i+1]);
        nodes[nodeSize] = *node;
        // printf("working node -> [%d]\n", nodes[i].level);
        // i++;
        nodeSize++;
    }

    cleanUpArray(&nodes, nodeSize);
    //print nodes has a runtime error
    printNodes(nodes, nodeSize);
    int *nodeSizep = &nodeSize;
    connectToHead(&nodes, &nodeSizep);
    nodeSize = *nodeSizep;
    printf("Head node -> %d\n", nodes[0].level);
    // printf("size -> %d", nodeSize);
    free(*head);
    *head = &nodes[0];
}
void connectToHead(TreeNode **nodes, int **size_) {
    int *size = *size_;
    // printf("curr size %d\n", size);
    //do the same thing as before
    TreeNode *nextLevelNodes = malloc(*size * sizeof(TreeNode));
    int nodeSize = 0;
    for (int i = 0; i < *size; i+=2) {
        printf("%d + %d\n", (*nodes[i]).level, (*nodes[i+1]).level);
        TreeNode *node = createNode((*nodes[i]).level + (*nodes[i+1]).level);
        nextLevelNodes[i] = *node;
        printf("%d val->%d\n", i, nextLevelNodes[i].level);

        // printf("%d, [%c %d] <- [%c %d] -> [%c %d]\n", i, nextLevelNodes[i].left.(&letter), nextLevelNodes[i].left->level, 'z', nextLevelNodes[i].level, nextLevelNodes[i].right->letter, nextLevelNodes[i].right->level);
        nodeSize++;
    }
    cleanUpArray(&nextLevelNodes, nodeSize);
    //this is for the word mississippi only. Need to refactor this and makeTree() in order to support other words
    //not every word will end at this # of iterations
    // TreeNode **headNode = &nodes;
    free(*nodes);
    *nodes = nextLevelNodes;
    // free(*size_);
    *size_ = &nodeSize;

}
TreeNode *getLeafNodes(CharacterCount *characterCount, int size) {
    TreeNode *nodes = malloc(size * sizeof(TreeNode));
    for (int i = 0; i < size; i++) {
        // printf("leaf node ->[%c %d]\n", characterCount[i].letter, characterCount[i].count);
        nodes[i] = *createLeafNode(characterCount[i]);
        // printf("leaf node -> [%c %d]\n", nodes[i].letter, nodes[i].level);
    }
    return nodes;
}
void cleanUpArray(TreeNode **nodes, int size) {
    TreeNode *newNodes = malloc(size * sizeof(TreeNode));
    for (int i = 0; i < size; i++) {
        newNodes[i] = (*nodes)[i];
        // printf("%d ", newNodes[i].level);
        // printf("%d, [%c %d]\n", i, nodes[i]->letter, nodes[i]->level);
        // printf("%d, [%c %d] <- [%c %d] -> [%c %d]\n", i, nodes[i]->left->letter, nodes[i]->left->level, 'z', nodes[i]->level, nodes[i]->right->letter, nodes[i]->right->level);
    }
    free(*nodes);
    *nodes = newNodes;
}

//will need to refactor this to handle more cases
void printNodes(TreeNode *nodes, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, [%c %d] <- [%c %d] -> [%c %d]\n", i, nodes[i].left->letter, nodes[i].left->level, 'z', nodes[i].level, nodes[i].right->letter, nodes[i].right->level);
    }
}


void assignValues(TreeNode *headNode, int size){
    CharacterCode *characterCodes = malloc(size * sizeof(CharacterCode));
    int currIndex = 0;
    char currCode[4];
    int currCodeLen = 0;
    TreeNode *nextNode = headNode;
    while (nextNode->isLeaf == false) {
        if (nextNode->left->isLeaf) {
            // characterCodes[currIndex] = malloc(sizeof(CharacterCode));
            CharacterCode newCode;
            newCode.letter = nextNode->left->letter;
            newCode.code = currCode;
            characterCodes[currIndex] = newCode;
            currIndex++;
        }
        else {
            currCode[currCodeLen] = '0';currCodeLen++;
        }
    }
}