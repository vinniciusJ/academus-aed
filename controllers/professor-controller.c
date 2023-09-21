//
// Created by vinniciusj on 13/09/23.
//
#include "headers/professor-controller.h"
#include "../views/headers/professor-view.h"
#include "../utils/headers/views.h"
#include "../utils/headers/file.h"
#include "../utils/headers/utils.h"
#include "../app.h"
#include "../models/professor.h"
#include "../services/headers/professor-service.h"

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
        case 1:
            create_professor();
            break;
        default:
            show_invalid_option_message();
            start_professor_router();
    }

    start_professor_router();
}

// Lida com a criação do professor
// Pré-condição: nenhuma
// Pós-condição: professor criado e inserido no arquivo
void create_professor() {
    FILE * file = open_list_file("professor.bin");
    Professor * professor = input_professor();

    insert_professor(*professor, file);

    show_sucess_message("Professor cadastrado com sucesso!");

    free_space(professor);
}
