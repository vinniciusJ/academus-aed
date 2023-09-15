//
// Created by vinniciusj on 15/09/23.
//
#include "headers/module-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"

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