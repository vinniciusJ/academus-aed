//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/subject-view.h"
#include "../models/subject.h"
#include "../utils/headers/utils.h"

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

// Requere do usuário as informações de uma disciplina e retorna ela
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de disciplina é retornado e deve ser desalocado posteriormente
Subject * input_subject(){
    printf("------------------------SISTEMA ACADEMUS--------------------------\n");
    printf("---------------------Cadastro de disciplina-----------------------\n\n");

    Subject * subject = (Subject *) alloc(sizeof(Subject));

    printf("Digite o código da disciplina: ");
    scanf("%d%*c", &subject->code);

    printf("Digite o nome da disciplina (até %d caracteres): ", NAME_LENGTH);
    scanf("%[^\n]%*c", subject->name);

    printf("Digite o código do curso que a disciplina pertence: ");
    scanf("%d%*c", &subject->course_code);

    printf("Digite a série da disciplina: ");
    scanf("%d%*c", &subject->year);

    printf("\n");
    return subject;
}