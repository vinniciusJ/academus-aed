//
// Created by vinniciusj on 14/09/23.
//
#include "stdlib.h"
#include "header.h"
#include <stdio.h>

#ifndef ACADEMUS_LIST_H
#define ACADEMUS_LIST_H

// Lê uma nó da lista em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista e a posição deve ser uma posição válida da lista
// Pós-condição: ponteiro para nó lido é retornado
void * read_node(int position, size_t size, FILE * file);

// Escreve um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista, deve passar o tamanho do nó e a posição deve ser valida no arquivo
// Pós-condição: nó escrito no arquivo
void set_node(void * node, size_t size, int position, FILE * file);


#endif //ACADEMUS_LIST_H
