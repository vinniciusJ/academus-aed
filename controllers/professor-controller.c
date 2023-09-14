//
// Created by vinniciusj on 13/09/23.
//
#include "headers/professor-controller.h"
#include "../views/headers/professor-view.h"
#include "../utils/headers/views.h"
#include "../app.h"

void professor_router(){
    int option = 0;

    show_professor_menu();
    option = input_option();

    switch (option) {
        case 0:
            show_menu();
            break;
        default:
            show_invalid_option_message();
            professor_router();
    }

    professor_router();
}