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

    free_space(subject);
}
