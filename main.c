#include <stdio.h>
#include <stdlib.h>
#include "MainHEader.h"

int main(void) {

    // remove("compresedText.txt");
    // remove("DecompressedText.txt");
    // FILE *dummy = fopen("../Dummy.txt", "w");
    // fprintf(dummy, "Hello World");
    // fclose(dummy);
    //
    FILE *comFile = fopen("../CompressedText.txt", "w");

    fprintf(comFile, "");fclose(comFile);

    FILE *decFile = fopen("../DecompressedText.txt", "w");
    fprintf(decFile, "");fclose(decFile);


    getCharacters();

    return 0;
}