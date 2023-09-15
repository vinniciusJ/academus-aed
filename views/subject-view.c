//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/subject-view.h"

// Imprime o menu de opções da seção de disciplinas
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de disciplinas é impresso no terminal
void show_subject_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|----------------------Seção de disciplinas----------------------|\n");
    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar disciplina                                        |\n");
    printf("|[2] Listar todas as disciplinas                                 |\n");
    printf("+----------------------------------------------------------------+\n");
}
