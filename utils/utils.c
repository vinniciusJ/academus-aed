//
// Created by vinniciusj on 14/09/23.
//
//
// Created by vinniciusj on 14/09/23.
//
#include <stdio.h>

#include "headers/utils.h"

void * alloc(size_t size){
    void * ptr = malloc(size);

    if(ptr == NULL){
        printf("Não há espaço em memória\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

void * free_space(void * ptr){
    free(ptr);

    return NULL;
}