//
// Created by lucst on 2026-03-10.
//

#ifndef TEXTCOMPRESSOR_FREQUENCY_H
#define TEXTCOMPRESSOR_FREQUENCY_H

typedef struct {
    char letter;
    int count;
}CharacterCount;
typedef struct CharacterCode{
    char letter;
    char *code;
}CharacterCode;

// int size;
int getCharacters();

void encodeRunner(CharacterCount *characterCount, char word[], int size);
void convertToBytes(char word[], CharacterCount *characterCount, int size);
#endif