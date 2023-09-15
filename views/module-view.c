//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>
#include "./headers/module-view.h"

// Imprime o menu de opções da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de módulos é impresso no terminal
void show_module_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|------------------------Seção de módulos------------------------|\n");
    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar módulo                                            |\n");
    printf("|[2] Listar módulos por curso                                    |\n");
    printf("|[3] Remover módulo                                              |\n");
    printf("+----------------------------------------------------------------+\n");
}