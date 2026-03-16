#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

treeNode *createNode(CharacterCount value) {
    treeNode *result = malloc(sizeof(treeNode));
    if (result != NULL) {
        result -> left = NULL;
        result -> right = NULL;
        result -> cc = value;
    }
    return result;
}

void setLeft(treeNode *node, treeNode *value) {
    node->left = value;
}
void setRight(treeNode *node, treeNode *value) {
    node->right = value;
}