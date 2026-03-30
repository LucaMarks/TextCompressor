#include "../mainHeader.h"
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(TreeNode **head, CharacterCount *characterCount, int size);
TreeNode *getLeafNodes(CharacterCount *characterCount, int size);
void cleanUpArray(TreeNode **nodes, int size);
void printNodes(TreeNode *nodes, int size);
void connectToHead(TreeNode **nodes, int **size_);

void assignValues(TreeNode *nextNode, int currDir, char path[], int pathIndex);
CharacterCode *characterCodes;
int characterCodesIndex = 0;

void encodeRunner(CharacterCount *characterCount, char word[], int size) {
    printf("\n");
    TreeNode *head = malloc(sizeof(TreeNode));
    makeTree(&head, characterCount, size);
    printf("Head nodee -> %d\n", (*head).level);
    // printf("first node on right -> %d\n", (*head).right->level);
    // printf("first node on right bool -> %d\n", head->right->isLeaf);
    characterCodes = malloc(sizeof(CharacterCode) * size);
    assignValues(head, -1, "", 0);
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
        // printf("%d + %d ", leafs[i].level, leafs[i+1].level);
        TreeNode *node = createNode(leafs[i].level + leafs[i+1].level);
        node->isLeaf = false;
        setRight(node, &leafs[i]);
        setLeft(node, &leafs[i+1]);
        nodes[nodeSize] = *node;
        // if (nodes[nodeSize].level == 11) {
        //     printf("this is the head node\n");
        // }
        // printf("working node -> [%d]\n", nodes[i].level);
        // i++;
        nodeSize++;
    }
    printf("\n");
    cleanUpArray(&nodes, nodeSize);
    //print nodes has a runtime error
    printNodes(nodes, nodeSize);
    int *nodeSizep = &nodeSize;
    connectToHead(&nodes, &nodeSizep);
    nodeSize = *nodeSizep;
    // printf("size -> %d", nodeSize);
    //there is only 1 item in nodes[] at this point due to connectToHead
    // printf("Head node from array -> %d\n", nodes[nodeSize-1].level);
    // printf("first node on right -> %d", nodes[nodeSize-1].left->level);
    free(*head);
    *head = &nodes[nodeSize-1];
}
void connectToHead(TreeNode **nodes, int **size_) {
    int *size = *size_;
    // printf("curr size %d\n", size);
    //do the same thing as before
    TreeNode *nextLevelNodes = malloc(*size * sizeof(TreeNode));
    int nodeSize = 0;
    for (int i = 0; i < *size; i+=2) {
        printf("%d + %d\n", (*nodes[i]).level, (*nodes[i+1]).level);
        // printf("%d & %d\n", (*nodes[i]).isLeaf, (*nodes[i+1]).isLeaf);
        //check that right node has a right child
        // printf("right node right child check -> %d\n", nodes[i]->right->level); //this passes
        TreeNode *node = createNode((*nodes[i]).level + (*nodes[i+1]).level);
        node->isLeaf = false;
        setRight(node, nodes[i]);
        setLeft(node, nodes[i+1]);
        // node->right = (nodes[i]);
        // node->left = (nodes[i+1]);
        // printf("%d & %d\n", node->right->isLeaf, node->left->isLeaf);
        // printf("right of head level -> %d\n", nodes[i]->level);
        // printf("Check node right of head -> %d\n", node->right->level);
        nextLevelNodes[i] = *node;
        printf("%d val->%d\n", i, nextLevelNodes[i].level);

        // printf("%d, [%c %d] <- [%c %d] -> [%c %d]\n", i, nextLevelNodes[i].left.(&letter), nextLevelNodes[i].left->level, 'z', nextLevelNodes[i].level, nextLevelNodes[i].right->letter, nextLevelNodes[i].right->level);
        nodeSize++;
    }
    cleanUpArray(&nextLevelNodes, nodeSize);
    printf("%d & %d\n", nextLevelNodes[0].right->isLeaf, nextLevelNodes[0].left->isLeaf);
    //this is for the word mississippi only. Need to refactor this and makeTree() in order to support other words
    //not every word will end at this # of iterations
    // TreeNode **headNode = &nodes;
    free(*nodes);
    *nodes = nextLevelNodes;
    // printf("I'm right here!\n");
    // printf("size should be 1 %d\n", nodeSize-1);
    // nodes[0]->right->isLeaf = false; // this is a temp fix
    // printf("%d & %d\n", nodes[0]->right->isLeaf, nodes[0]->left->isLeaf);
    // printf("first node on right -> %d, size should be 1 -> %d\n", nextLevelNodes[0].right->level, nodeSize);
    // free(*size_);
    *size_ = &nodeSize;

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

//will need to refactor this to handle more cases
void printNodes(TreeNode *nodes, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, [%c %d] <- [%c %d] -> [%c %d]\n", i, nodes[i].left->letter, nodes[i].left->level, 'z', nodes[i].level, nodes[i].right->letter, nodes[i].right->level);
    }
}

void assignValues(TreeNode *nextNode, int currDir, char path[], int pathIndex) {
    // printf("Head nodee -> %d\n", (*nextNode).level);
    if (currDir == -1) {

        assignValues(nextNode, 1, "", 0);
        assignValues(nextNode, 0, "", 0);
    }
    if (currDir == 1) {
        //base case
        // printf("second level -> %d\n", nextNode->left->level);
        // printf("bool -> %d\n", nextNode->right->isLeaf);
        // if (!nextNode->isLeaf) {
        //     printf("%d is not a leaf\n", nextNode->level);
        // }
        if (nextNode->right->isLeaf) {
            CharacterCode newCode;
            newCode.letter = nextNode->right->letter;
            newCode.code = path;
            characterCodes[characterCodesIndex] = newCode;
            return;
        }
        //add to curr path & keep going
        path[pathIndex] = '1';pathIndex++;
        // printf("this works -> %c\n", path[pathIndex -1]);

        assignValues(nextNode, 1, path, pathIndex);
        assignValues(nextNode, 0, path, pathIndex);
    }
    else if (currDir == 0) {
        //base case
        if (nextNode->left->isLeaf) {
            CharacterCode newCode;
            newCode.letter = nextNode->left->letter;
            newCode.code = path;
            characterCodes[characterCodesIndex] = newCode;
            return;
        }
        //add to currPath & keep going
        path[pathIndex] = '0';pathIndex++;

        assignValues(nextNode, 1, path, pathIndex);
        assignValues(nextNode, 0, path, pathIndex);
    }
}