//
// Created by Rubén Buzón Pérez on 2019-05-30.
//

#ifndef ACTIVIDAD_6_1_TABLAHASHDEESTUDIANTES_H
#define ACTIVIDAD_6_1_TABLAHASHDEESTUDIANTES_H

#include "Elemento.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"


class TablaHashDeEstudiantes {
    int capacidad;
    struct Elemento **alumnos;

    int obtenerPosicion(int clave);

public:
    explicit TablaHashDeEstudiantes(int capacidad);
    bool existeAlumno(int matricula);
    char *obtenerEstudiante(int matricula);
    void insertarEstudiante(int matricula, char *nombre);
    void eliminarEstudiante(int matricula);
    void imprimirTabla();

};


#endif //ACTIVIDAD_6_1_TABLAHASHDEESTUDIANTES_H
