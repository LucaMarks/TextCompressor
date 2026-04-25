#ifndef TEXTCOMPRESSOR_MAINHEADER_H
#define TEXTCOMPRESSOR_MAINHEADER_H

typedef struct TreeNode {

    bool isLeaf;
    char letter;
    int level;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

typedef struct CharacterCount {
    char letter;
    int count;
}CharacterCount;
typedef struct CharacterCode {
    char letter;
    char *code;
}CharacterCode;

int getCharacters();

CharacterCode **getCharacterCodes();
int *getCharacterCodeLen();

TreeNode *encodeRunner(CharacterCount *characterCount, char word[], int size);
void convertToBytes(char word[], CharacterCount *characterCount, int wordSize_);

void decodeRunner(TreeNode *headNode);
#endif //TEXTCOMPRESSOR_MAINHEADER_H