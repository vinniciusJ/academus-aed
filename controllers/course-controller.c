//
// Created by vinniciusj on 13/09/23.
//

#include "headers/course-controller.h"
#include "../views/headers/course-view.h"
#include "../app.h"
#include "../utils/headers/views.h"
#include "../utils/headers/file.h"
#include "../services/headers/course-service.h"
#include "../utils/headers/utils.h"

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
        case 1:
            create_course();
            break;
        default:
            show_invalid_option_message();
            start_course_controller();
    }

    start_course_controller();
}

// Lida com a criação do curso
// Pré-condição: nenhuma
// Pós-condição: curso criado e inserido no arquivo course.bin
void create_course() {
    FILE * file = open_file("course.bin", "wb");
    Course * course = input_course();

    insert_course(*course, file);

    show_sucess_message("Curso cadastrado com sucesso!");

    free_space(course);
}