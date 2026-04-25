#include "../MainHeader.h"
#include "../Tree.h"
#include <stdio.h>
#include <stdlib.h>

void makeTree(TreeNode **head, CharacterCount *characterCount, int size);
TreeNode *getLeafNodes(CharacterCount *characterCount, int size);
void cleanUpArray(TreeNode **nodes, int size);
void connectToHead(TreeNode **nodes);
void assignValues(TreeNode *currNode, int currDir, char *path, int pathIndex, char *word);
CharacterCode *characterCodes;
int ccIndex = 0;

CharacterCode **getCharacterCodes() {
    return &characterCodes;
}
int *getCharacterCodeLen() {
    return &ccIndex;
}

TreeNode *encodeRunner(CharacterCount *characterCount, char word[], int size) {
    int leafNodes = sizeof(*characterCount) / sizeof(CharacterCount);
    characterCodes = malloc( ((2 * leafNodes) - 1) * sizeof(CharacterCode));
    // printf("Made it here!\n");
    TreeNode *head = malloc(sizeof(TreeNode));
    makeTree(&head, characterCount, size);
    //debug
    // printf("%d\n", head->level);
    printf("[%d] <- [%d] -> [%d]\n", head->left->level, head->level, head->right->level);
    char *path = malloc(size * sizeof(char));
    assignValues(head, -1, path, 0, word);

    // for (int i = 0; i < ccIndex; i++) {
    //     printf("[%s %c]\n", characterCodes[i].code, characterCodes[i].letter);
    // }

    free(path);
    // free(characterCodes);
    // free(head);
    return head;
}

void makeTree(TreeNode **head, CharacterCount *characterCount, int size) {

    TreeNode *leafs = getLeafNodes(characterCount, size);

    TreeNode *nodes = malloc(sizeof(TreeNode) * size);
    int nodeSize = 0;

    for (int i = 0; i < size; i+=2) {
        TreeNode *node = createNode(leafs[i].level + leafs[i+1].level);

        node->right = &leafs[i];
        node->left = &leafs[i+1];

        nodes[nodeSize] = *node;
        nodeSize++;

    }
    if (nodeSize == 2) {
        connectToHead(&nodes);

        // free(*head);
        //should be just one node
        *head = nodes;
    }
}
TreeNode *getLeafNodes(CharacterCount *characterCount, int size) {
    TreeNode *nodes = malloc(size * sizeof(TreeNode));
    for (int i = 0; i < size; i++) {
        // printf("leaf node ->[%c %d]\n", characterCount[i].letter, characterCount[i].count);
        nodes[i] = *createLeafNode(characterCount[i]);
        // nodes[i].isLeaf = true;
        // printf("leaf node -> [%c %d]\n", nodes[i].letter, nodes[i].level);
    }
    return nodes;
}
void connectToHead(TreeNode **nodes) {

    TreeNode *head = createNode((*nodes)[0].level + (*nodes)[1].level);
    // head->right = createNode(nodes[0]->level);
    // head->left = createNode(nodes[1]->level);

    head->right = &(*nodes)[0];
    head->left = &(*nodes)[1];
    // printf("%d\n", head->right->level);

    // free(*nodes);
    *nodes = head;
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

void assignValues(TreeNode *currNode, int currDir, char *path, int pathIndex, char *word) {
    if (sizeof(*currNode) != sizeof(TreeNode)) {return;}


    if (currDir == -1) {
        assignValues(currNode, 0, path, pathIndex, word);
        assignValues(currNode, 1, path, pathIndex, word);
        return;
    }


    //read right
    if (currDir == 0) {

        // printf("Made it here!\n");
        path[pathIndex] = '1';pathIndex++;

        currNode = currNode->right;
    }

    //read left
    if (currDir == 1) {
        path[pathIndex] = '0';pathIndex++;
        currNode = currNode->left;


    }

    //base case
    if (currNode->isLeaf) {
        //path is lokey all malloced in the same place
        //therefore what's just going to be stored is the last path *char to end up here

        //clean up
        // char *temp = realloc(path, pathIndex * sizeof(char));
        // char *temp = realloc(path, 2);
        //save path
        path[pathIndex] = '\0';
        char *savedPath = malloc(pathIndex+1);
        // path = temp;
        // printf("currPath: %s(Encode assignValues)\n", path);
        for (int i = 0; i < pathIndex; i++) {
            savedPath[i] = path[i];
        }
        savedPath[pathIndex] = '\0';
        // *savedPath = path;

        // printf("%c, %c\n", path[0], path[1]);

        //create a new characterCode
        CharacterCode *characterCode = malloc(sizeof(CharacterCode));
        characterCode->letter = currNode->letter;
        characterCode->code = savedPath;

        characterCodes[ccIndex] = *characterCode; ccIndex++;


        return;
    }


    printf("[%c %d] <- [%c %d] -> [%c %d]\n", currNode->left->letter, currNode->left->level, currNode->letter, currNode->level, currNode->right->letter, currNode->right->level);

    assignValues(currNode, 0, path, pathIndex, word);
    assignValues(currNode, 1, path, pathIndex, word);
}