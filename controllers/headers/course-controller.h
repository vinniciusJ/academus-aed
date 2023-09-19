//
// Created by vinniciusj on 13/09/23.
//

#ifndef ACADEMUS_COURSE_CONTROLLER_H
#define ACADEMUS_COURSE_CONTROLLER_H

// Inicia a navegação na seção de cursos
// Pré-condição: nenhuma
// Pós-condição: redireciona o usuário para o recurso solicitado na seção
void start_course_controller();

// Lida com a criação do curso
// Pré-condição: nenhuma
// Pós-condição: curso criado e inserido no arquivo course.bin
void create_course();

#endif //ACADEMUS_COURSE_CONTROLLER_H
