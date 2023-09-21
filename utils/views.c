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

void wait_to_continue(){
    int c;


    printf("Press Enter to continue...");

    fflush(stdout);

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}