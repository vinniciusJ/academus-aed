//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_VIEWS_H
#define ACADEMUS_VIEWS_H

// Escaneia um valor inteiro pelo terminal informado pelo usuário
// Pré-condição: nenhuma
// Pós-condição: retorna o valor digitado pelo usuário
int input_option();

// Imprime uma mensagem de sucesso recebida por parâmetro
// Pré-condição: nenhuma
// Pós-condição: mensagem de sucesso impressa no terminal em verde
void show_sucess_message(char * message);

// Imprime uma mensagem de erro para uma opção inválida
// Pré-condição: nenhuma
// Pós-condição: mensagem de erro impressa no terminal
void show_invalid_option_message();

// Imprime uma mensagem de alerta com a cor amarela
// Pré-condição: uma mensagem de alerta
// Pós-condição: mensagem impressa no terminal
void show_alert(char * alert);

char * get_knowledge_area(char code);
void wait_to_continue();


#endif //ACADEMUS_VIEWS_H
