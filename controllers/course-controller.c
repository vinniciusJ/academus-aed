//
// Created by vinniciusj on 13/09/23.
//

#include "headers/course-controller.h"
#include "../views/headers/course-view.h"
#include "../app.h"
#include "../utils/headers/views.h"

// Inicia a navegação na seção de cursos
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_course_controller(){
    int option = 0;

    show_course_menu();
    option = input_option();

    switch (option) {
        case 0:
            start_app_router();
            break;
        default:
            show_invalid_option_message();
            start_course_controller();
    }

    start_course_controller();
}
