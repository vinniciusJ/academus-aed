//
// Created by vinniciusj on 15/09/23.
//
#include "headers/professor-service.h"
#include "../utils/headers/list.h"
#include "../utils/headers/utils.h"

// Insere um value no arquivo lista
// Pré-condição: um novo professor e um arquivo aberto para escrita
// Pós-condição: professor salvo no arquivo lista
void insert_professor(Professor professor, FILE * file){
    Header * header = read_header(file);
    ProfessorNode node = {professor, header->head_position };

    if(header->free_position == -1){
        set_node(&node, sizeof(ProfessorNode), header->top_position, file); // Escrevendo nó no arquivo lista
        header->head_position = header->top_position;
        header->top_position++;
    }
    else{
        ProfessorNode * aux = read_node(header->free_position, sizeof(ProfessorNode), file);

        set_node(aux, sizeof(ProfessorNode), header->free_position, file);
        header->head_position = header->free_position;
        header->head_position = aux->next;

        aux = free_space(aux);
    }

    set_header(header, file);
}