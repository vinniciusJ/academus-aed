//
// Created by vinniciusj on 13/09/23.
//
#include "./headers/module-controller.h"
#include "../utils/headers/views.h"
#include "../views/headers/module-view.h"
#include "../app.h"

void module_router(){
    int option = 0;

    show_module_menu();
    option = input_option();

    switch (option) {
        case 0:
            show_menu();
            break;
        default:
            show_invalid_option_message();
            module_router();
    }

    module_router();
}
