//
// Created by vinniciusj on 13/09/23.
//
#include "./headers/module-controller.h"
#include "../utils/headers/views.h"
#include "../views/headers/module-view.h"
#include "../app.h"

// Inicia a navegação na seção de módulo
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_module_router(){
    int option = 0;

    show_module_menu();
    option = input_option();

    switch (option) {
        case 0:
            start_app_router();
            break;
        default:
            show_invalid_option_message();
            start_module_router();
    }

    start_module_router();
}
