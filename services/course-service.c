//
// Created by vinniciusj on 15/09/23.
//
#include "../utils/headers/list.h"
#include "headers/course-service.h"
#include "../utils/headers/utils.h"

// Insere um value no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: value salvo no arquivo lista
void insert_course(Course course, FILE * file){
    Header * header = read_header(file);

    CourseNode node = { course, header->head_position };

    if(header->free_position == -1){
        set_node(&node, sizeof(CourseNode), header->top_position, file); // Escrevendo nó no arquivo lista

        header->head_position = header->top_position;
        header->top_position++;
    }
    else{
        CourseNode * aux = read_node(header->free_position, sizeof(CourseNode), file);

        set_node(aux, sizeof(CourseNode), header->free_position, file);
        header->head_position = header->free_position;
        header->head_position = aux->next;

        aux = free_space(aux);
    }

    set_header(header, file);
    free_space(header);
}

// Busca um curso pelo código na lista
// Pré-condição: código do curso e um arquivo lista aberto para leitura
// Pós-condição: curso ou NULL caso não tenha sido encontrado
Course * get_course_by_code(int code, FILE * file){
    Header * header = read_header(file);
    CourseNode * node = NULL;

    int position = header->head_position;

    if(is_list_empty(header)){
        return NULL;
    }

    while (position != -1){
        node = read_node(position, sizeof(CourseNode), file);
        position = node->next;

        if(node != NULL && node->value.code == code){
            return &node->value;
        }
    }

    return NULL;
}
