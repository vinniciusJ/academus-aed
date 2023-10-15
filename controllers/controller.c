//
// Created by nikoly on 13/10/23.
//
#include "headers/controller.h"
#include "../utils/headers/file.h"
#include "../services/headers/service.h"
#include "../views/headers/views.h"

// Lida com a inclusão em lote
// Pré-condição: nenhuma
// Pós-condição: inclusão de dados no arquivo de lote concluida
void create_in_batch() {
    FILE * file = open_read_file("data.txt");

    insert_in_batch(file);

    //wait_to_continue();
    fclose(file);
}