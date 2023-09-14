//
// Created by vinniciusj on 14/09/23.
//
#include <stdlib.h>

#include "headers/file.h"

FILE  * open_file(char * filename, char * mode){
    FILE * file = NULL;

    file = fopen(filename, mode);

    if(file == NULL){
        printf("Não foi possível encontrar o arquivo %s\n", filename);
        exit(EXIT_FAILURE);
    }

    return file;
}