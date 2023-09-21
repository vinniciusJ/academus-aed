//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/course-view.h"
#include "../models/course.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/views.h"

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

// Requere do usuário as informações de um curso e retorna ele
// Pré-condição: nenhuma
// Pós-condição: um ponteiro de curso é retornado e deve ser desalocado posteriormente
Course * input_course(){
    printf("------------------------SISTEMA ACADEMUS--------------------------\n");
    printf("-----------------------Cadastro de cursos-------------------------\n\n");

    Course * course = (Course *) alloc(sizeof(Course));

    printf("Digite o código do curso: ");
    scanf("%d%*c", &course->code);

    printf("Digite o nome do curso (até %d caracteres): ", MAX_NAME_LENGTH);
    scanf("%[^\n]%*c", course->name);

    printf("\n[E] Exatas | [B] Biológicas | [H] Humanas\n");
    printf("Digite a área do curso: ");
    scanf("%c", &course->area);

    printf("\n");
    return course;
}

// Mostra no terminal um curso cadastrado
// Pré-condição: curso
// Pós-condição: curso é mostrado em tela
void show_course(Course course){
    printf("| %9d| %-49s| %-9s|\n", course.code, course.name, get_knowledge_area(course.area));
    printf("|----------|--------------------------------------------------|----------|\n");
}


// Mostra o cabeçalho da tabela dos cursos
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void show_course_table_header(){
    printf("+------------------------------------------------------------------------+\n");
    printf("| %-10s| %-49s| %-10s|\n", "Código", "Nome", "Área");
    printf("|----------|--------------------------------------------------|----------|\n");
}