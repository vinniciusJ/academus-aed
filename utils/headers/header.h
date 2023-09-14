//
// Created by vinniciusj on 14/09/23.
//
#include "../../models/header.h"

#include "stdio.h"

#ifndef ACADEMUS_LIST_H
#define ACADEMUS_LIST_H


// Criar uma lista nova em um arquivo
// Pré-condição: arquivo aberto para leitura/escrita
// Pós-condição: arquivo é inicializado com uma lista vazia
void create_empty_list(FILE * file);

// Lê o cabeçalho do arquivo contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e deve ser um arquivo de lista
// Pós-condição: retorna o ponteiro para o cabeçalho lido
Header * read_header(FILE * file);

// Escreve no arquivo o cabeç alho contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: cabeçaalho escrito no arquivo
void set_header(const Header * header, FILE * file);

#endif //ACADEMUS_LIST_H
