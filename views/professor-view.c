//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>
#include "headers/professor-view.h"

// Imprime o menu de opções da seção de professores
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de professores é impresso no terminal
void show_professor_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|----------------------Seção de professores----------------------|\n");
    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar professor(a)                                      |\n");
    printf("|[2] Listar todos os professores(as)                             |\n");
    printf("+----------------------------------------------------------------+\n");
}