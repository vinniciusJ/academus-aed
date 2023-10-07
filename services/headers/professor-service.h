//
// Created by vinniciusj on 15/09/23.
//
#include <stdio.h>

#include "../../models/professor.h"

#ifndef ACADEMUS_PROFESSOR_SERVICE_H
#define ACADEMUS_PROFESSOR_SERVICE_H

// Insere um value no arquivo lista
// Pré-condição: um novo professor e um arquivo aberto para escrita
// Pós-condição: professor salvo no arquivo lista
void insert_professor(Professor professor, FILE * file);

#endif //ACADEMUS_PROFESSOR_SERVICE_H
