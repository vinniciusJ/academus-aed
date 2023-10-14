//
// Created by nikoly on 13/10/23.
//

#include "headers/service.h"
#include "../models/course.h"
#include "../models/subject.h"
#include "../models/professor.h"
#include "../models/module.h"
#include "../utils/headers/utils.h"

#include "../views/headers/course-view.h"
#include "../views/headers/subject-view.h"
#include "../views/headers/professor-view.h"
#include "../views/headers/module-view.h"

// Lida com a inclusão em lote
// Pré-condição: nenhuma
// Pós-condição: inclusão de dados no arquivo de lote concluida
void insert_in_batch(FILE * file) {
    char type;

    while(fscanf(file, "%c", &type) != EOF) {
        printf("\ntype: %c\n", type);
        switch (type) {
            case 'C':
                read_course(file);
                break;
            case 'D':
                read_subject(file);
                break;
            case 'P':
                read_professor(file);
                break;
            case 'M':
                printf("oi");
                read_module(file);
                break;
        }
    }
}

// Lê os dados de um curso do arquivo de lote
// Pré-condição: Linha atual ser do tipo Course (caracter C já ter sido lido)
// Pós-condição: inclusão do curso
void read_course(FILE * file) {
    char trash;
    Course * course = alloc(sizeof(Course));

    fscanf(file, "%c", &trash);
    fscanf(file, "%d", &course->code);
    fscanf(file, "%c", &trash);
    fscanf(file, "%[^;]", course->name);
    fscanf(file, "%c", &trash);
    fscanf(file, "%c", &course->area);
    //fscanf(file, "%c", &trash);

    show_course(*course);
    free(course);
}

// Lê os dados de uma disciplina do arquivo de lote
// Pré-condição: Linha atual ser do tipo Subject (caracter D já ter sido lido)
// Pós-condição: inclusão da disciplina
void read_subject(FILE * file) {
    char trash;
    Subject * subject = alloc(sizeof(Subject));

    fscanf(file, "%c", &trash);
    fscanf(file, "%d", &subject->code);
    fscanf(file, "%c", &trash);
    fscanf(file, "%[^;]", subject->name);
    fscanf(file, "%c", &trash);
    fscanf(file, "%d", &subject->course_code);
    fscanf(file, "%c", &trash);
    fscanf(file, "%d", &subject->year);
    //fscanf(file, "%c", &trash);

    show_subject(*subject);
    free(subject);
}

// Lê os dados de um professor(a) do arquivo de lote
// Pré-condição: Linha atual ser do tipo Professor (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void read_professor(FILE * file) {
    char trash;
    Professor * professor = alloc(sizeof(Professor));

    fscanf(file, "%c", &trash);
    fscanf(file, "%d", &professor->code);
    fscanf(file, "%c", &trash);
    fscanf(file, "%[^\n]", professor->name);
    fscanf(file, "%c", &trash);
    //fscanf(file, "%c", &trash);

    show_professor(*professor);
    free(professor);
}

// Lê os dados de um modulo do arquivo de lote
// Pré-condição: Linha atual ser do tipo Module (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void read_module(FILE * file) {
    char trash;
    Module * module = alloc(sizeof(Module));

    fscanf(file, "%c", &trash);
    fscanf(file, "%d", &module->subject_code);
    fscanf(file, "%c", &trash);
    fscanf(file, "%d", module->academic_year);
    fscanf(file, "%c", &trash);
    fscanf(file, "%d", module->professor_code);
    //fscanf(file, "%c", &trash);

    free(module);
}