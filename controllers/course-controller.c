//
// Created by vinniciusj on 13/09/23.
//

#include "headers/course-controller.h"
#include "../views/headers/course-view.h"
#include "../app.h"
#include "../utils/headers/views.h"

void controller_router(){
    int option = 0;

    show_course_menu();
    option = input_option();

    switch (option) {
        case 0:
            show_menu();
            break;
        default:
            show_invalid_option_message();
            controller_router();
    }

    controller_router();
}
