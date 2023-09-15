//
// Created by vinniciusj on 14/09/23.
//
#include <stdio.h>

#ifndef ACADEMUS_FILE_H
#define ACADEMUS_FILE_H

// Abre um arquivo
// Pré-condição: nome válido de arquivo e o modo para abertura
// Pós-condição: retorna um arquivo aberto
FILE * open_file(char * filename, char * mode);

#endif //ACADEMUS_FILE_H
