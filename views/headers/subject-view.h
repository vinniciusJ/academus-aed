//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_SUBJECT_VIEW_H
#define ACADEMUS_SUBJECT_VIEW_H

#include "../../models/subject.h"

// Imprime o menu de opções da seção de disciplinas
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de disciplinas é impresso no terminal
void show_subject_menu();

// Requere do usuário as informações de uma disciplina e retorna ela
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de disciplina é retornado e deve ser desalocado posteriormente
Subject * input_subject();

#endif //ACADEMUS_SUBJECT_VIEW_H
