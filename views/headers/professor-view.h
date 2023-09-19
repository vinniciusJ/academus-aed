//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_PROFESSOR_VIEW_H
#define ACADEMUS_PROFESSOR_VIEW_H

#include "../../models/professor.h"

// Imprime o menu de opções da seção de professores
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de professores é impresso no terminal
void show_professor_menu();

// Requere do usuário as informações de um professor e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de professor é retornado e deve ser desalocado posteriormente
Professor * input_professor();

#endif //ACADEMUS_PROFESSOR_VIEW_H
