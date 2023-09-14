//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>
#include <stdlib.h>

#include "app.h"
#include "controllers/headers/course-controller.h"
#include "controllers/headers/subject-controller.h"
#include "controllers/headers/professor-controller.h"
#include "controllers/headers/module-controller.h"
#include "utils/headers/views.h"

void show_menu(){
    printf("+------------------------SISTEMA ACADEMUS------------------------+\n");
    printf("|[0] - Sair do sistema                                           |\n");
    printf("|[1] - Ir para a seção de cursos                                 |\n");
    printf("|[2] - Ir para a seção de disciplinas                            |\n");
    printf("|[3] - Ir para a seção de professores                            |\n");
    printf("|[4] - Ir para a seção de módulos                                |\n");
    printf("|[5] - Importar dados em lote                                    |\n");
    printf("+----------------------------------------------------------------+\n");
}

void app_router(){
    int option = 0;

    show_menu();
    option = input_option();

    switch (option) {
        case 0:
            exit(EXIT_SUCCESS);
        case 1:
            controller_router();
            break;
        case 2:
            subject_router();
            break;
        case 3:
            professor_router();
            break;
        case 4:
            module_router();
            break;
        default:
            show_invalid_option_message();
            app_router();
    }

    app_router();
}