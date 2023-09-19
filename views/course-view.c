//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/course-view.h"
#include "../models/course.h"
#include "../utils/headers/utils.h"

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

// Imprime o menu de opções da seção de cursos
// Pré-condição: nenhuma
// Pós-condição: o menu de opções da seção é impresso no terminal
Course * input_course(){
    printf("------------------------SISTEMA ACADEMUS--------------------------\n");
    printf("-----------------------Cadastro de cursos-------------------------\n\n");

    Course * course = (Course *) alloc(sizeof(Course));

    printf("Digite o código do curso: ");
    scanf("%d%*c", &course->code);

    printf("\nDigite o nome do curso: ");
    scanf("%[^\n]%*c", course->name);

    printf("\n[E] Exatas | [B] Biológicas | [H] Humanas");
    printf("\nDigite a área do curso: ");
    scanf("%c", &course->area);

    printf("\n");
    return course;
}