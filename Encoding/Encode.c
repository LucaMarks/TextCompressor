#include "../mainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(CharacterCount *characterCount, char word[], int size);
TreeNode *getLeafNodes(CharacterCount *characterCount, int size);
void cleanUpArray(TreeNode **nodes, int size);
void printNodes(TreeNode *nodes, int size);

void treeRunner(CharacterCount *characterCount, char word[], int size) {
    makeTree(characterCount, word, size);
}

//build huffman tree
//every item in characterCount is a leaf node
void makeTree(CharacterCount *characterCount, char word[], int size) {
    TreeNode *leafs = getLeafNodes(characterCount, size);
    //add up all leaf nodes in this order
    TreeNode *nodes = malloc(size * sizeof(TreeNode));
    int nodeSize = 0;
    // printf("leaf node -> [%c %d]\n", leafs[0].letter, leafs[0].level);
    for (int i = 0; i < size; i++) {
        // printf("Made it here %d\n", i);
        // printf("leaf node -> [%c %d]\n", leafs[i].letter, leafs[i].level);
        TreeNode *node = createNode(leafs[i].level + leafs[i+1].level);
        setRight(node, &leafs[i]);
        setLeft(node, &leafs[i+1]);
        nodes[i] = *node;
        // printf("working node -> [%d]\n", nodes[i].level);
        i++;
        nodeSize++;
    }
    //issue with cleanUpArray
    cleanUpArray(nodes, nodeSize);
    printNodes(nodes, nodeSize);

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
        newNodes[i] = *nodes[i];
    }
    free(*nodes);
    *nodes = newNodes;
}

//will need to refactor this to handle more cases
void printNodes(TreeNode *nodes, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%c %d] <- [%c %d] -> [%c %d]\n", nodes[i].left->letter, nodes[i].left->level, nodes[i].letter, nodes[i].level, nodes[i].right->letter, nodes[i].right->level);
    }
}