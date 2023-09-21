//
// Created by vinniciusj on 15/09/23.
//
#include "../utils/headers/list.h"
#include "headers/course-service.h"
#include "../utils/headers/utils.h"

// Insere um item no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: item salvo no arquivo lista
void insert_course(Course course, FILE * file){
    Header * header = read_header(file);

    printf("head position = %d\n", header->head_position);
    printf("top position = %d\n", header->top_position);
    printf("free position = %d\n", header->free_position);

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
