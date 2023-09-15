//
// Created by vinniciusj on 13/09/23.
//
#include "stdio.h"
#include "headers/views.h"

// Escaneia um valor inteiro pelo terminal informado pelo usuário
// Pré-condição: nenhuma
// Pós-condição: retorna o valor digitado pelo usuário
int input_option(){
    int option = 0;

    printf("Escolha uma opção das listadas acima: ");
    scanf("%d%*c", &option);
    printf("\n");

    return option;
}

// Imprime uma mensagem de erro para uma opção inválida
// Pré-condição: nenhuma
// Pós-condição: mensagem de erro impressa no terminal
void show_invalid_option_message(){
    printf("Opção inválida, informe uma opção valida!\n");
}