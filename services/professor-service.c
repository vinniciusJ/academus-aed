//
// Created by vinniciusj on 15/09/23.
//
#include <string.h>
#include "headers/professor-service.h"
#include "../utils/headers/list.h"
#include "../utils/headers/utils.h"

// Insere um value no arquivo lista
// Pré-condição: um novo professor e um arquivo aberto para escrita
// Pós-condição: status da inserção do professor
Status * insert_professor(Professor professor, FILE * file){
    Header * header = read_header(file);
    ProfessorNode node = {professor, header->head_position };
    Status * status = validate_professor(professor, file);

   if(status->code == 1) {
        if (header->free_position == -1) {
            set_node(&node, sizeof(ProfessorNode), header->top_position, file); // Escrevendo nó no arquivo lista
            header->head_position = header->top_position;
            header->top_position++;
        } else {
            ProfessorNode *aux = read_node(header->free_position, sizeof(ProfessorNode), file);

            set_node(aux, sizeof(ProfessorNode), header->free_position, file);
            header->head_position = header->free_position;
            header->head_position = aux->next;

            aux = free_space(aux);
        }

        set_header(header, file);
    }

    free_space(header);

    return status;
}

// Busca um professor pelo código na lista
// Pré-condição: código do professor e um arquivo lista aberto para leitura
// Pós-condição: professor ou NULL caso não tenha sido encontrado
Professor * get_professor_by_code(int code, FILE * file){
    Header * header = read_header(file);
    ProfessorNode * node = NULL;

    int position = header->head_position;

    if(is_list_empty(header)){
        return NULL;
    }

    while (position != -1){
        node = read_node(position, sizeof(ProfessorNode), file);
        position = node->next;

        if(node != NULL && node->value.code == code){
            return &node->value;
        }
    }

    return NULL;
}

// Valida o professor e retorna um status da inserção de acordo com o resultado
// Pré-condição: um novo professor e um arquivo aberto para leitura
// Pós-condição: status para a inserção (código 1 para sucesso e 0 para erro)
Status * validate_professor(Professor professor, FILE * file) {
    Status * status = (Status *) alloc(sizeof(Status));

    if(get_professor_by_code(professor.code, file)) {
        status->code = 0;
        char message[256];
        sprintf(message, "Já existe um(a) professor(a) com o código %d! Portanto o(a) professor(a) não foi cadastrado(a).", professor.code);
        strcpy(status->message, message);
    } else {
        status->code = 1;
        strcpy(status->message, "Professor(a) cadastrado(a) com sucesso!");
    }

    return status;
}
