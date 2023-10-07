//
// Created by vinniciusj on 15/09/23.
//

#include <stdio.h>

#include "../../models/course.h"

#ifndef ACADEMUS_COURSE_SERVICE_H
#define ACADEMUS_COURSE_SERVICE_H

// Insere um value no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: value salvo no arquivo lista
void insert_course(Course course, FILE * file);

// Busca um curso pelo código na lista
// Pré-condição: código do curso e um arquivo lista aberto para leitura
// Pós-condição: curso ou NULL caso não tenha sido encontrado
Course * get_course_by_code(int code, FILE * file);

#endif //ACADEMUS_COURSE_SERVICE_H
