//
// Created by lucst on 2026-03-10.
//

#ifndef TEXTCOMPRESSOR_FREQUENCY_H
#define TEXTCOMPRESSOR_FREQUENCY_H

typedef struct {
    char letter;
    int count;
}CharacterCount;
typedef struct {
    char letter;
    int code;
}CharacterCode;

// int size;
int getCharacters();

void convertToBytes(char word[], CharacterCount *characterCount, int size);
#endif