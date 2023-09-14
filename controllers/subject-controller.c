//
// Created by vinniciusj on 13/09/23.
//
#include <stdio.h>

#include "headers/subject-controller.h"
#include "../views/headers/subject-view.h"
#include "../utils/headers/views.h"
#include "../app.h"

void subject_router(){
    int option = 0;

    show_subject_menu();
    option = input_option();

    switch (option) {
        case 0:
            app_router();
            break;
        default:
            show_invalid_option_message();
            subject_router();
    }

    subject_router();
}