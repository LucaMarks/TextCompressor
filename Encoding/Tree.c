#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *createLeafNode(CharacterCount value) {
    // printf("creating leaf node...\n");
    TreeNode *result = malloc(sizeof(TreeNode));
    if (result != NULL) {
        result -> left = NULL;
        result -> right = NULL;
        result->isLeaf = true;
        result->letter = value.letter;
        result->level = value.count;
    }
    return result;
}
TreeNode *createNode(int level) {
    // printf("Creating node...\n");
    TreeNode *result = malloc(sizeof(TreeNode));
    if (result != NULL) {
        result -> left = NULL;
        result -> right = NULL;
        result->isLeaf = false;
        result->level = level;
    }
    return result;
}

void setLeft(TreeNode *node, TreeNode *value) {
    node->left = value;
}
void setRight(TreeNode *node, TreeNode *value) {
    node->right = value;
    // printf("%d\n", (*value).level);
    // if (value->level == 3) {
    //     printf("right from head set correctly!\n");
    // }
}