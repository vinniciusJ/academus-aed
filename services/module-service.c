//
// Created by vinniciusj on 15/09/23.
//
#include "headers/module-service.h"
#include "headers/subject-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"

#include "../models/subject.h"

typedef struct {
    int current;
    int previous;
    int next;
    ModuleNode * value;
} Position;

// Pré-condição: um novo módulo e um arquivo aberto para escrita
// Pós-condição: módulo salvo no arquivo lista
void insert_module(Module module, FILE * file){
    Header * header = read_header(file);
    ModuleNode node = { module, header->head_position };

    if(header->free_position == -1){
        set_node(&node, sizeof(ModuleNode), header->top_position, file); // Escrevendo nó no arquivo lista
        header->head_position = header->top_position;
        header->top_position++;
    }
    else{
        ModuleNode * aux = read_node(header->free_position, sizeof(ModuleNode), file);

        set_node(&node, sizeof(ModuleNode), header->free_position, file);
        header->head_position = header->free_position;
        header->head_position = aux->next;

        aux = free_space(aux);
    }

    set_header(header, file);
}

Position get_module_position(Module module, Header * header, FILE * file){
    int position = header->head_position;
    int previous = header->head_position;

    ModuleNode * aux = NULL;

    int subject_code = module.subject_code;
    int academic_year = module.academic_year;

    while(position != -1  && (aux = read_node(position, sizeof(ModuleNode), file)) != NULL){
        if(aux->value.academic_year == academic_year && aux->value.subject_code == subject_code){
            break;
        }

        previous = position;
        position = aux->next;

        aux = free_space(aux);
    }

    Position module_position = { position, previous, aux->next, aux };

    return module_position;
}

// Retira um módulo do arquivo lista
// Pré-condição: arquivo aberto para escrita e deve ser um arquivo lista
// Pós-condição: módulo retirado da lista caso pertença a ela
void remove_module(Module module, FILE * file){
    Header * header = read_header(file);

    Position position = get_module_position(module, header, file);

    if(position.current != -1){
        if(position.current == position.previous){
            header->head_position = position.next;
        }
        else{
            ModuleNode * previous = read_node(position.previous, sizeof(ModuleNode), file);

            previous->next = position.next;
            set_node(previous, sizeof(ModuleNode), position.previous, file);
            free_space(previous);
        }

        position.value->next = header->free_position;
        header->free_position = position.current;

        set_node(position.value, sizeof(ModuleNode), position.current, file);
        set_header(header, file);

        free_space(position.value);
    }

    free_space(header);
}

ModuleNode * get_module_by_course(int course_code, int start_position, FILE * modules_file, FILE * subjects_file){
    Header * header = read_header(modules_file);

    ModuleNode * module_node = NULL;
    Subject * subject = NULL;

    int position = start_position == -1 ? header->head_position : start_position;

    if(is_list_empty(header)){
        return NULL;
    }

    while(position != -1){
        module_node = read_node(position, sizeof(ModuleNode), modules_file);

        Module module = module_node->value;
        subject = get_subject_by_code(module.subject_code, subjects_file);

        if(subject != NULL && subject->course_code == course_code){
            return module_node;
        }

        position = module_node->next;
    }

    return NULL;
}

Module * get_module_by(int academic_year, int subject_code, FILE * modules_file){
    Header * header = read_header(modules_file);
    ModuleNode * module_node = NULL;

    int position = header->head_position;

    if(is_list_empty(header)){
        return NULL;
    }

    while(position != -1){
        module_node = read_node(position, sizeof(ModuleNode), modules_file);

        Module module = module_node->value;

        if(module.subject_code == subject_code && module.academic_year == academic_year){
            return &module_node->value;
        }

        position = module_node->next;
    }

    return NULL;
}
