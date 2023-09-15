//
// Created by vinniciusj on 15/09/23.
//
#include "headers/module-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"
#include "../models/professor.h"

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

    ModuleNode * aux = (ModuleNode *) read_node(position, sizeof(ModuleNode), file);

    int subject_code = module.subject_code;
    int professor_code = module.professor_code;

    while(position != -1  && (aux = read_node(position, sizeof(ModuleNode), file)) != NULL){
        if(aux->item.professor_code == professor_code && aux->item.subject_code != subject_code){
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
    ModuleNode * aux = NULL;

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
