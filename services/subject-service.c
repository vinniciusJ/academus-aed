//
// Created by vinniciusj on 15/09/23.
//
#include "headers/subject-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"


// Insere um item no arquivo lista
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