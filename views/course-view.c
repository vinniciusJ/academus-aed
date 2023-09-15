//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/course-view.h"

// Imprime o menu de opções da seção de cursos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção é impresso no terminal
void show_course_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|------------------------Seção de cursos-------------------------|\n");
    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar curso                                             |\n");
    printf("|[2] Listar todos os cursos                                      |\n");
    printf("+----------------------------------------------------------------+\n");
}

