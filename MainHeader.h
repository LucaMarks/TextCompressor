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

#endif //TEXTCOMPRESSOR_MAINHEADER_H