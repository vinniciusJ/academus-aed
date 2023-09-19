//
// Created by vinniciusj on 15/09/23.
//

#include <stdio.h>

#include "../../models/course.h"

#ifndef ACADEMUS_COURSE_SERVICE_H
#define ACADEMUS_COURSE_SERVICE_H

// Insere um item no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: item salvo no arquivo lista
void insert_course(Course course, FILE * file);

#endif //ACADEMUS_COURSE_SERVICE_H
