//
// Created by vinniciusj on 13/09/23.
//
#include <stdlib.h>

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

// Imprime uma mensagem de sucesso recebida por parâmetro
// Pré-condição: nenhuma
// Pós-condição: mensagem de sucesso impressa no terminal em verde
void show_sucess_message(char * message) {
    printf("\033[1;32m  %s \033[1;0m\n", message);
}

char * get_knowledge_area(char code){
    switch (code) {
        case 'E':
            return "Exatas";
        case 'B':
            return "Biológicas";
        case 'H':
            return "Humanas";
        default:
            return "";
    }
}

// Imprime uma mensagem de alerta com a cor amarela
// Pré-condição: uma mensagem de alerta
// Pós-condição: mensagem impressa no terminal
void show_alert(char * alert){
    printf("\033[1;33m%s\033[0m\n", alert);

    wait_to_continue();
}

void wait_to_continue(){
    int c;

    printf("Pressione 'Enter' para continuar...");

    fflush(stdout);

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);

    system("clear");
}
