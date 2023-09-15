//
// Created by vinniciusj on 15/09/23.
//

#include <stdio.h>

#include "../../models/subject.h"

#ifndef ACADEMUS_SUBJECT_SERVICE_H
#define ACADEMUS_SUBJECT_SERVICE_H

// Insere um item no arquivo lista
// Pré-condição: uma nova disciplina e um arquivo aberto para escrita
// Pós-condição: disciplina salvo no arquivo lista
void insert_subject(Subject subject, FILE * file);

#endif //ACADEMUS_SUBJECT_SERVICE_H
