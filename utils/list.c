//
// Created by vinniciusj on 14/09/23.
//
#include <stdlib.h>

#include "headers/utils.h"
#include "../models/header.h"
#include "headers/list.h"
#include "headers/header.h"

// Lê uma nó da lista em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista e a posição deve ser uma posição válida da lista
// Pós-condição: ponteiro para nó lido é retornado
void * read_node(int position, size_t size, FILE * file){
    void * item = alloc(size);

    fseek(file, sizeof(Header) + position * size, SEEK_SET);
    fread(item, size, 1, file);

    return item;
}

// Escreve um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista, deve passar o tamanho do nó e a posição deve ser valida no arquivo
// Pós-condição: nó escrito no arquivo
void set_node(void * node, size_t size, int position, FILE * file){
    fseek(file, sizeof(Header) + position * size, SEEK_SET);
    fwrite(node, size, 1, file);
}
