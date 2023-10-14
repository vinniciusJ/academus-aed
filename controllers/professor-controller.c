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
#include "../utils/headers/list.h"

// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_professor_router(){
    int option = 0;

    show_professor_menu();
    option = input_option();

    system("clear");

    switch (option) {
        case 0:
            start_app_router();
            break;
        case 1:
            create_professor();
            break;
        case 2:
            show_professors();
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

    show_sucess_message("Professor(a) cadastrado com sucesso!");

    show_professor_table_header();
    show_professor(*professor);

    free_space(professor);
    fclose(file);

    wait_to_continue();
}

// Lida com a visualização de todos os professores
// Pré-condição: nenhuma
// Pós-condição: mostra todos os professores cadastrados no arquivo
void show_professors(){
    FILE * file = open_list_file("professor.bin");
    Header * header = read_header(file);

    int position = header->head_position;
    ProfessorNode * professor_node = NULL;

    if(position == -1){
        show_alert("Não existe nenhum professor cadastrado no sistema");
        return;
    }
    show_professor_table_header();

    do{
        professor_node = (ProfessorNode *) read_node(position, sizeof(ProfessorNode), file);
        position = professor_node->next;

        show_professor(professor_node->value);
    }while(position != -1);

    fclose(file);
    wait_to_continue();
}