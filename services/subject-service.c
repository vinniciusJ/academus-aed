//
// Created by vinniciusj on 15/09/23.
//
#include "headers/subject-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"


// Insere um value no arquivo lista
// Pré-condição: uma nova disciplina e um arquivo aberto para escrita
// Pós-condição: disciplina salvo no arquivo lista
void insert_subject(Subject subject, FILE * file){
    Header * header = read_header(file);
    SubjectNode node = {subject, header->head_position };

    if(header->free_position == -1){
        set_node(&node, sizeof(SubjectNode), header->top_position, file); // Escrevendo nó no arquivo lista

        header->head_position = header->top_position;
        header->top_position++;
    }
    else{
        SubjectNode * aux = read_node(header->free_position, sizeof(SubjectNode), file);

        set_node(aux, sizeof(SubjectNode), header->free_position, file);
        header->head_position = header->free_position;
        header->head_position = aux->next;

        aux = free_space(aux);
    }

    set_header(header, file);
    free_space(header);
}

// Busca uma disciplina pelo código na lista
// Pré-condição: código da disciplina e um arquivo lista aberto para leitura
// Pós-condição: disciplina ou NULL caso não tenha sido encontrado
Subject * get_subject_by_code(int code, FILE * file){
    Header * header = read_header(file);
    SubjectNode * node = NULL;

    int position = header->head_position;

    if(is_list_empty(header)){
        return NULL;
    }

    while (position != -1){
        node = read_node(position, sizeof(SubjectNode), file);
        position = node->next;

        if(node != NULL && node->value.code == code){
            return &node->value;
        }
    }

    return NULL;
}