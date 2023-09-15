//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/subject-controller.h"
#include "../views/headers/subject-view.h"
#include "../utils/headers/views.h"
#include "../app.h"

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
        default:
            show_invalid_option_message();
            start_subject_router();
    }

    start_subject_router();
}