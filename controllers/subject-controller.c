//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/subject-controller.h"
#include "../views/headers/subject-view.h"
#include "../utils/headers/views.h"
#include "../utils/headers/utils.h"
#include "../app.h"
#include "../utils/headers/file.h"
#include "../models/subject.h"
#include "../services/headers/subject-service.h"
#include "../models/header.h"
#include "../utils/headers/list.h"

// Inicia a navegação na seção de disciplina
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_subject_router(){
    int option = 0;

    show_subject_menu();
    option = input_option();

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
    FILE * file = open_list_file("subject.bin");
    Subject * subject = input_subject();

    insert_subject(*subject, file);

    show_sucess_message("Disciplina cadastrada com sucesso!");
    show_subject_table_header();
    show_subject(*subject);

    free_space(subject);
    fclose(file);

    wait_to_continue();
}

// Lida com a visualização de todos as matérias
// Pré-condição: nenhuma
// Pós-condição: mostra todos as matérias cadastradas no arquivo
void show_subjects() {
    FILE * file = open_list_file("subject.bin");
    Header * header = read_header(file);

    int position = header->head_position;
    SubjectNode * subject_node = NULL;

    show_subject_table_header();

    do{
        subject_node = (SubjectNode *) read_node(position, sizeof(SubjectNode), file);
        position = subject_node->next;

        show_subject(subject_node->item);
    } while (position != -1);

    fclose(file);
    wait_to_continue();
}