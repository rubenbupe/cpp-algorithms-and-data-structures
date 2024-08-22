//
// Created by Rubén Buzón Pérez on 2019-05-30.
//

#include "TablaHashDeEstudiantes.h"
using namespace std;

TablaHashDeEstudiantes::TablaHashDeEstudiantes(int capacidad) {
    capacidad = 10;
    this->capacidad = capacidad;
    this->alumnos = (struct Elemento**) malloc(capacidad * sizeof(struct Elemento*));
    for(int i = 0; i < capacidad; i++){
        this->alumnos[i] = new struct Elemento;
        this->alumnos[i]->nombre = nullptr;
        this->alumnos[i]->n_matricula = -1;
        this->alumnos[i]->ocupado = 0;

    }
}

bool TablaHashDeEstudiantes::existeAlumno(int matricula) {
    return this->alumnos[obtenerPosicion(matricula)]->n_matricula == matricula;
}

int TablaHashDeEstudiantes::obtenerPosicion(int clave) {
    return clave % this->capacidad;
}

char *TablaHashDeEstudiantes::obtenerEstudiante(int matricula) {
    assert(existeAlumno(matricula));

    return this->alumnos[obtenerPosicion(matricula)]->nombre;
}

void TablaHashDeEstudiantes::insertarEstudiante(int matricula, char *nombre) {
    assert(alumnos[obtenerPosicion(matricula)]->ocupado == false);

    this->alumnos[obtenerPosicion(matricula)]->n_matricula = matricula;
    strcpy( this->alumnos[obtenerPosicion(matricula)]->nombre, nombre);
    this->alumnos[obtenerPosicion(matricula)]->ocupado = true;
}

void TablaHashDeEstudiantes::eliminarEstudiante(int matricula) {
    assert(alumnos[obtenerPosicion(matricula)]->ocupado);

    alumnos[obtenerPosicion(matricula)]->ocupado = false;
}

void TablaHashDeEstudiantes::imprimirTabla() {

    cout << "Tabla Hash de alumnos: " << endl << endl;
    cout << this->capacidad;

    for(int i = 0; i < this->capacidad; i++){
        cout << "Posicion " << i;
        cout << " | Flag: " << this->alumnos[i]->ocupado;
        cout << " | Clave: " << this->alumnos[i]->n_matricula;
        cout << " | Nombre: " << this->alumnos[i]->nombre;
        cout << endl;
    }

}
