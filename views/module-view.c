//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "../utils/headers/utils.h"
#include "./headers/module-view.h"

// Imprime o menu o cabeçalho do menu da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: cabeçalho impresso no terminal
void show_module_menu_header(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|------------------------Seção de módulos------------------------|\n");
}

// Imprime o menu de opções da seção de módulos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção de módulos é impresso no terminal
void show_module_menu(){
    show_module_menu_header();

    printf("|[0] Voltar                                                      |\n");
    printf("|[1] Cadastrar módulo                                            |\n");
    printf("|[2] Listar módulos por curso                                    |\n");
    printf("|[3] Remover módulo                                              |\n");
    printf("+----------------------------------------------------------------+\n");
}

// Requere do usuário as informações de um módulo e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de módulo é retornado e deve ser desalocado posteriormente
Module * input_module(){
    show_module_menu_header();

    Module * module = (Module *) alloc(sizeof(Module));

    printf("Digite o ano letivo: ");
    scanf("%d%*c", &module->academic_year);

    printf("Digite o código da disciplina: ");
    scanf("%d%*c", &module->subject_code);

    printf("Digite o código do professor: ");
    scanf("%d%*c", &module->professor_code);

    printf("\n");

    return module;
}

// Mostra o cabeçalho da tabela dos módulos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_module_table_header(){
    printf("+-------------------------------------------------------------+\n");
    printf("| %10s| %-49s| %-49s|\n", "Ano letivo", "Disciplina", "Professor");
    printf("|----------|--------------------------------------------------|\n");
}

// Mostra no terminal uma linha que representa um módulos cadastrado, deve ser usada em tabelas
// Pré-condição: módulo
// Pós-condição: módulo é impresso no terminal
void show_module(Module module, Subject subject, Professor professor){
    printf("| %10d| %-49s| %-49s|\n", module.academic_year, subject.name, professor.name);
    printf("|----------|--------------------------------------------------|\n");
}