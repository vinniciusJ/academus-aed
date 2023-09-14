//
// Created by vinniciusj on 14/09/23.
//
#include <stdlib.h>

#include "headers/utils.h"
#include "../models/header.h"
#include "headers/list.h"
#include "headers/header.h"


void * read_node(int position, size_t size, FILE * file){
    void * item = alloc(size);

    fseek(file, sizeof(Header) + position * size, SEEK_SET);
    fread(item, size, 1, file);

    return item;
}

void set_node(void * node, size_t size, int position, FILE * file){
    fseek(file, sizeof(Header) + position * size, SEEK_SET);
    fwrite(node, size, 1, file);
}
