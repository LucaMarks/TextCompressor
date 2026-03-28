#include "../mainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(CharacterCount *characterCount, char word[], int size);
TreeNode *getLeafNodes(CharacterCount *characterCount, int size);
void cleanUpArray(TreeNode **nodes, int size);
void printNodes(TreeNode *nodes, int size);
void connectToHead(TreeNode *nodes, int size);

void treeRunner(CharacterCount *characterCount, char word[], int size) {
    printf("\n");
    makeTree(characterCount, word, size);
}

//build huffman tree
//every item in characterCount is a leaf node
void makeTree(CharacterCount *characterCount, char word[], int size) {
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
    //issue with cleanUpArray
    cleanUpArray(&nodes, nodeSize);
    //print nodes has a runtime error
    printNodes(nodes, nodeSize);
    connectToHead(nodes, nodeSize);
}
// void connectToHead(TreeNode *nodes, int size) {
//     //do the same thing as before
//     TreeNode *nextLevelNodes = malloc(size * sizeof(TreeNode));
//     int nodeSize = 0;
//     for (int i = 0; i < size; i+=2) {
//         TreeNode *node = createNode(nodes[i].level + nodes[i+1].level);
//         nextLevelNodes[i] = *node;
//         printf("")
//         nodeSize++;
//     }
// }

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