//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/subject-controller.h"
#include "../views/headers/subject-view.h"
#include "../views/headers/views.h"
#include "../utils/headers/utils.h"
#include "../app.h"
#include "../utils/headers/file.h"
#include "../models/subject.h"
#include "../services/headers/subject-service.h"
#include "../services/headers/course-service.h"
#include "../models/header.h"
#include "../utils/headers/list.h"

// Inicia a navegação na seção de disciplina
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_subject_router(){
    int option = 0;

    show_subject_menu();
    option = input_option();

    system("clear");

    switch (option) {
        case 0:
            start_app_router();
            break;
        case 1:
            create_subject();
            break;
        case 2:
            show_subjects();
            break;
        default:
            show_invalid_option_message();
            start_subject_router();
    }

    start_subject_router();
}

// Lida com a criação de disciplina
// Pré-condição: nenhuma
// Pós-condição: disciplina criada e inserido no arquivo
void create_subject() {
    FILE * subject_file = open_list_file("subject.bin");
    FILE * course_file = open_list_file("course.bin");

    Subject * subject = input_subject();

    Status * status = insert_subject(*subject, subject_file);
    Course * course = NULL;

    if(status->code == 1) {
        course = get_course_by_code(subject->course_code, course_file);

        show_sucess_message(status->message);
        show_subject_table_header();
        show_subject(*subject, *course);
    } else {
        show_error_message(status->message);
    }

    free_space(status);
    free_space(subject);

    fclose(course_file);
    fclose(subject_file);

    wait_to_continue();
}

// Lida com a visualização de todas as disciplinas
// Pré-condição: nenhuma
// Pós-condição: mostra todos as matérias cadastradas no arquivo
void show_subjects() {
    FILE * subject_file = open_list_file("subject.bin");
    FILE * course_file = open_list_file("course.bin");

    Header * header = read_header(subject_file);

    int position = header->head_position;

    SubjectNode * subject_node = NULL;
    Course * course = NULL;

    if(is_list_empty(header)){
        show_alert("Não há nenhuma disciplina cadastrada!");
        return;
    }

    show_subject_table_header();

    do{
        subject_node = (SubjectNode *) read_node(position, sizeof(SubjectNode), subject_file);
        course = get_course_by_code(subject_node->value.course_code, course_file);
        position = subject_node->next;

        show_subject(subject_node->value, *course);
    } while (position != -1);

    fclose(course_file);
    fclose(subject_file);

    wait_to_continue();
}