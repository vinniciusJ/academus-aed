//
// Created by vinniciusj on 15/09/23.
//
#include <stdio.h>

#include "../../models/module.h"

#ifndef ACADEMUS_MODULE_SERVICE_H
#define ACADEMUS_MODULE_SERVICE_H

// Insere um item no arquivo lista
// Pré-condição: um novo módulo e um arquivo aberto para escrita
// Pós-condição: módulo salvo no arquivo lista
void insert_module(Module module, FILE * file);

#endif //ACADEMUS_MODULE_SERVICE_H