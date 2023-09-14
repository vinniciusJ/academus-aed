//
// Created by vinniciusj on 13/09/23.
//
#include "stdio.h"
#include "headers/views.h"

int input_option(){
    int option = 0;

    printf("Escolha uma opção das listadas acima: ");
    scanf("%d%*c", &option);
    printf("\n");

    return option;
}

void show_invalid_option_message(){
    printf("Opção inválida, informe uma opção valida!\n");
}