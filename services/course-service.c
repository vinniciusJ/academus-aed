//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "../utils/headers/list.h"
#include "headers/course-service.h"
#include "../utils/headers/utils.h"

// Insere um curso no arquivo lista
// Pré-condição: um novo curso e um arquivo aberto para escrita
// Pós-condição: status da inserção do curso
Status * insert_course(Course course, FILE * file) {
    Header * header = read_header(file);
    Status * status = validate_course(course, file);

    if(status->code == 1) {
        CourseNode node = {course, header->head_position};

        if (header->free_position == -1) {
            set_node(&node, sizeof(CourseNode), header->top_position, file); // Escrevendo nó no arquivo lista

            header->head_position = header->top_position;
            header->top_position++;
        } else {
            CourseNode *aux = read_node(header->free_position, sizeof(CourseNode), file);

            set_node(aux, sizeof(CourseNode), header->free_position, file);
            header->head_position = header->free_position;
            header->head_position = aux->next;

            free_space(aux);
        }
        set_header(header, file);
    }
    free_space(header);

    return status;
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

// Valida o curso e retorna um status da inserção de acordo com o resultado
// Pré-condição: um novo curso e um arquivo aberto para leitura
// Pós-condição: status para a inserção
Status * validate_course(Course course, FILE * file) {
    Status * status = (Status *) alloc(sizeof(Status));

    if(get_course_by_code(course.code, file)) {
        status->code = 0;
        char message[256];
        sprintf(message, "Já existe um curso cadastrado com o código %d! Portanto o curso não foi cadastrado.", course.code);
        strcpy(status->message, message);
    } else {
        status->code = 1;
        strcpy(status->message, "Curso cadastrado com sucesso!");
    }

    return status;
}
