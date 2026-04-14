#ifndef TEXTCOMPRESSOR_TREE_H
#define TEXTCOMPRESSOR_TREE_H

#include "../MainHeader.h"

typedef struct TreeNode {

    bool isLeaf;
    char letter;
    int level;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode *createLeafNode(CharacterCount value);
TreeNode *createNode(int level);
void setLeft(TreeNode *node, TreeNode *value);
void setRight(TreeNode *node, TreeNode *value);

#endif //TEXTCOMPRESSOR_TREE_H