//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "headers/subject-service.h"
#include "../utils/headers/utils.h"
#include "../utils/headers/list.h"
#include "headers/course-service.h"
#include "../utils/headers/file.h"

// Insere um value no arquivo lista
// Pré-condição: uma nova disciplina e um arquivo aberto para escrita
// Pós-condição: status da inserção da disciplina
Status * insert_subject(Subject subject, FILE * file){
    Header * header = read_header(file);
    SubjectNode node = {subject, header->head_position };

    Status * status = validate_subject(subject, file);

    if(status->code == 1){
        if (header->free_position == -1) {
            set_node(&node, sizeof(SubjectNode), header->top_position, file); // Escrevendo nó no arquivo lista

            header->head_position = header->top_position;
            header->top_position++;
        } else {
            SubjectNode *aux = read_node(header->free_position, sizeof(SubjectNode), file);

            set_node(aux, sizeof(SubjectNode), header->free_position, file);
            header->head_position = header->free_position;
            header->head_position = aux->next;

            aux = free_space(aux);
        }

        set_header(header, file);
    }
    free_space(header);

    return status;
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

// Valida a disciplina e retorna um status da inserção de acordo com o resultado
// Pré-condição: uma nova disciplina e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_subject(Subject subject, FILE * file) {
    FILE * course_file = open_list_file("course.bin");
    Status * status = (Status *) alloc(sizeof(Status));
    status->code = 0;

    char message[1000];

    int code_already_exists = !!get_subject_by_code(subject.code, file);
    int invalid_course = !get_course_by_code(subject.course_code, course_file);

    if(code_already_exists && invalid_course) {
        sprintf(message, "Já existe uma disciplina cadastrada com o código %d e não existe um curso cadastrado com o código %d! Portanto, a disciplina não foi cadastrada.", subject.code, subject.course_code);
    }

    else if(code_already_exists) {
        sprintf(message, "Já existe uma disciplina cadastrada com o código %d! Portanto, a disciplina não foi cadastrada.", subject.code);
    }

    else if(invalid_course) {
        sprintf(message, "Não existe um curso cadastrado com o código %d! Portanto, a disciplina não foi cadastrada.", subject.course_code);
    }

    else {
        status->code = 1;
        sprintf(message, "Disciplina cadastrada com sucesso!");
    }

    strcpy(status->message, message);

    fclose(course_file);
    return status;
}