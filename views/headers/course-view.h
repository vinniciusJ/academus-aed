//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_COURSE_VIEW_H
#define ACADEMUS_COURSE_VIEW_H

#include "../../models/course.h"

// Imprime o menu de opções da seção de cursos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção é impresso no terminal
void show_course_menu();

// Requere do usuário as informações de um curso e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de curso é retornado e deve ser desalocado posteriormente
Course * input_course();

#endif //ACADEMUS_COURSE_VIEW_H
