#ifndef TEXTCOMPRESSOR_TREE_H
#define TEXTCOMPRESSOR_TREE_H
#include "../mainHeader.h"

typedef struct treeNode {
    CharacterCount cc;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *createNode(CharacterCount value);
void setLeft(treeNode *node, treeNode *value);
void setRight(treeNode *node, treeNode *value);


#endif //TEXTCOMPRESSOR_TREE_H