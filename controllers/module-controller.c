//
// Created by vinniciusj on 13/09/23.
//
#include <stdlib.h>
#include <stdio.h>

#include "./headers/module-controller.h"
#include "../utils/headers/views.h"
#include "../views/headers/module-view.h"
#include "../app.h"
#include "../utils/headers/file.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"
#include "../services/headers/module-service.h"
#include "../services/headers/professor-service.h"
#include "../services/headers/subject-service.h"

#define MODULES_FILE "modules.bin"

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
        case 1:
            create_module();
            break;
        case 2:
            show_modules();
            break;
        default:
            show_invalid_option_message();
            start_module_router();
    }

    start_module_router();
}

// Lida com a criação de um módulo
// Pré-condição: nenhuma
// Pós-condição: módulo criado e inserido no arquivo
void create_module(){
    FILE * file = open_list_file(MODULES_FILE);
    Module * module = input_module();

    insert_module(*module, file);

    show_sucess_message("Módulo cadastrado com sucesso!");

    free_space(module);
    fclose(file);
}

// Lida com a visualização de todos os módulos
// Pré-condição: nenhuma
// Pós-condição: mostra todos os módulos cadastrados no arquivo
void show_modules(){
    FILE * module_file = open_list_file(MODULES_FILE);
    FILE * professor_file = open_list_file("professor.bin");
    FILE * subject_file = open_list_file("subject.bin");

    Header * header = read_header(module_file);

    int position = header->head_position;

    ModuleNode * module_node = NULL;
    Professor * professor = NULL;
    Subject  * subject = NULL;

    if(is_list_empty(header)){
        show_alert("Nenhum módulo cadastrado no arquivo");
        return;
    }

    show_module_table_header();

    while(position != -1){
        module_node = read_node(position, sizeof(ModuleNode), module_file);
        Module module = module_node->value;

        professor = get_professor_by_code(module.professor_code, professor_file);
        subject = get_subject_by_code(module.subject_code, subject_file);

        show_module(module, *subject, *professor);

        free_space(subject);
        free_space(professor);

        position = module_node->next;
    }

    fclose(module_file);
    fclose(professor_file);
    fclose(subject_file);

    wait_to_continue();
}
