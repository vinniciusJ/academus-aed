//
// Created by vinniciusj on 13/09/23.
//
#include "headers/professor-controller.h"
#include "../views/headers/professor-view.h"
#include "../utils/headers/views.h"
#include "../app.h"

// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_professor_router(){
    int option = 0;

    show_professor_menu();
    option = input_option();

    switch (option) {
        case 0:
            start_app_router();
            break;
        default:
            show_invalid_option_message();
            start_professor_router();
    }

    start_professor_router();
}