#include "headers/header.h"
#include "headers/utils.h"

// Escreve no arquivo o cabeç alho contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: cabeçaalho escrito no arquivo
void set_header(const Header * header, FILE * file){
    fseek(file, 0, SEEK_SET);
    fwrite(header, sizeof(header), 1, file);
}

// Criar uma lista nova em um arquivo
// Pré-condição: arquivo aberto para leitura/escrita
// Pós-condição: arquivo é inicializado com uma lista vazia
void create_empty_list(FILE * file){
    Header * header = (Header *) alloc(sizeof(Header));

    header->head_position = -1;
    header->top_position = 0;
    header->free_position = -1;

    set_header(header, file);

    free_space(header);
}

// Lê o cabeçalho do arquivo contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e deve ser um arquivo de lista
// Pós-condição: retorna o ponteiro para o cabeçalho lido
Header * read_header(FILE * file){
    Header * header = (Header *) alloc(sizeof(Header));

    fseek(file, 0, SEEK_SET);
    fread(header, sizeof(header), 1, file);

    return header;
}
