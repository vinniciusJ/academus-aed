cmake_minimum_required(VERSION 3.26)
project(academus C)

set(CMAKE_C_STANDARD 11)

add_executable(academus main.c
        models/course.h
        models/subject.h
        models/professor.h
        models/module.h
        app.h
        app.c
        controllers/headers/course-controller.h
        views/headers/course-view.h
        views/course-view.c
        controllers/course-controller.c
        controllers/headers/subject-controller.h
        views/headers/subject-view.h
        views/subject-view.c
        controllers/subject-controller.c
        utils/headers/views.h
        utils/views.c
        controllers/headers/professor-controller.h
        controllers/professor-controller.c
        views/headers/professor-view.h
        views/professor-view.c
        controllers/headers/module-controller.h
        views/headers/module-view.h
        views/module-view.c
        controllers/module-controller.c
        utils/headers/file.h
        utils/file.c
        models/header.h
        utils/header.c
        utils/headers/header.h
        utils/headers/utils.h
        utils/utils.c
        utils/headers/list.h
        utils/list.c)
