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
    char line[256];

    while(fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, " %c", &type) != 1) {
            continue;
        }

        printf("\ntype: %c\n", type);

        switch (type) {
            case 'C':
                read_course(line);
                break;
            case 'D':
                read_subject(line);
                break;
            case 'P':
                read_professor(line);
                break;
            case 'M':
                read_module(line);
                break;
        }
    }
}

// Lê os dados de um curso do arquivo de lote
// Pré-condição: Linha atual ser do tipo Course (caracter C já ter sido lido)
// Pós-condição: inclusão do curso
void read_course(const char *line) {
    Course * course = alloc(sizeof(Course));

    sscanf(line, "C;%d;%[^;];%c", &course->code, course->name, &course->area);

    show_course(*course);
    free(course);
}

// Lê os dados de uma disciplina do arquivo de lote
// Pré-condição: Linha atual ser do tipo Subject (caracter D já ter sido lido)
// Pós-condição: inclusão da disciplina
void read_subject(const char *line) {
    Subject * subject = alloc(sizeof(Subject));

    sscanf(line, "D;%d;%[^;];%d;%d", &subject->code, subject->name, &subject->course_code, &subject->year);

    show_subject(*subject);
    free(subject);
}

// Lê os dados de um professor(a) do arquivo de lote
// Pré-condição: Linha atual ser do tipo Professor (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void read_professor(const char *line) {
    Professor * professor = alloc(sizeof(Professor));

    sscanf(line, "P;%d;%[^;]", &professor->code, professor->name);

    show_professor(*professor);
    free(professor);
}

// Lê os dados de um modulo do arquivo de lote
// Pré-condição: Linha atual ser do tipo Module (caracter P já ter sido lido)
// Pós-condição: inclusão do professor(a)
void read_module(const char *line) {
    Module * module = alloc(sizeof(Module));

    sscanf(line, "M;%d;%d;%d", &module->subject_code, &module->professor_code, &module->academic_year);

    printf("\n%d, %d, %d\n", module->subject_code, module->professor_code, module->academic_year);

    free(module);
}