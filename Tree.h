#ifndef TEXTCOMPRESSOR_TREE_H
#define TEXTCOMPRESSOR_TREE_H

#include "MainHeader.h"

TreeNode *createLeafNode(CharacterCount value);
TreeNode *createNode(int level);
void setLeft(TreeNode *node, TreeNode *value);
void setRight(TreeNode *node, TreeNode *value);

#endif //TEXTCOMPRESSOR_TREE_H