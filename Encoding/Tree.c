#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *createLeafNode(CharacterCount value) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (node != NULL) {
        node->left = NULL;
        node->right = NULL;
        node->isLeaf = true;
        node->letter = value.letter;
        node->level = value.count;
    }
    return node;
}


TreeNode *createNode(int level) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (node != NULL) {
        node->left = NULL;
        node->right = NULL;
        node->isLeaf = false;
        node->level = level;
    }
    return node;
}

void setLeft(TreeNode *node, TreeNode *value) {
    node->left = value;
}
void setRight(TreeNode *node, TreeNode *value) {
    node->right = value;
}