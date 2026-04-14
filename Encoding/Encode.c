#include "../MainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(TreeNode **head, CharacterCount *characterCount, int size);
TreeNode *getLeafNodes(CharacterCount *characterCount, int size);
void cleanUpArray(TreeNode **nodes, int size);


void encodeRunner(CharacterCount *characterCount, char word[], int size) {
    // printf("Made it here!\n");
    TreeNode *head = malloc(sizeof(TreeNode));
    makeTree(&head, characterCount, size);


}

void makeTree(TreeNode **head, CharacterCount *characterCount, int size) {

    TreeNode *leafs = getLeafNodes(characterCount, size);

    TreeNode *nodes = malloc(sizeof(TreeNode) * size);
    int nodeSize = 0;

    for (int i = 0; i < size; i+=2) {
        TreeNode *node = createNode(leafs[i].level + leafs[i+1].level);
        node->left = &leafs[i];
        node->right = &leafs[i+1];

        nodes[nodeSize] = *node;
        nodeSize++;

    }
    if (nodeSize == 2) {
        connectToHead
    }
}
TreeNode *getLeafNodes(CharacterCount *characterCount, int size) {
    TreeNode *nodes = malloc(size * sizeof(TreeNode));
    for (int i = 0; i < size; i++) {
        // printf("leaf node ->[%c %d]\n", characterCount[i].letter, characterCount[i].count);
        nodes[i] = *createLeafNode(characterCount[i]);
        nodes[i].isLeaf = true;
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