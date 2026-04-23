#ifndef TEXTCOMPRESSOR_MAINHEADER_H
#define TEXTCOMPRESSOR_MAINHEADER_H

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

void encodeRunner(CharacterCount *characterCount, char word[], int size);
void convertToBytes(char word[], CharacterCount *characterCount, int wordSize_);
#endif //TEXTCOMPRESSOR_MAINHEADER_H