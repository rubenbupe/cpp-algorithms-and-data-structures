//
// Created by Rubén Buzón Pérez on 2019-03-11.
//

#include "ListaContigua.h"
#include "stdlib.h"
#include "iostream"
#include "assert.h"


ListaContigua::ListaContigua(){
    this->n = 0;
    this->vector = NULL;
    this->capacidad = 0;
}

ListaContigua::~ListaContigua() {
    if(this->vector != NULL)
        free(vector);
}


int ListaContigua::getValor(int posicion){
    assert(posicion >= 0 && posicion < this->n);

    return this->vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor) {
    assert(posicion >= 0 && posicion < this->n);

    this->vector[posicion] = nuevoValor;
}

int ListaContigua::getN(){
    return this->n;
}

int ListaContigua::getCapacidad(){
    return this->capacidad;
}

bool ListaContigua::isLlena(){
    assert(this->n <= this->capacidad);

    return n == this->capacidad;
}

void ListaContigua::insertarAlFinal (int nuevoValor){

    insertar(nuevoValor,n);
}

void ListaContigua::eliminarAlFinal() {
    eliminar(n-1 );

}

void ListaContigua::insertar(int nuevoValor, int i){

    if(isLlena()){
        this->vector = (int *) realloc(this->vector, (this->capacidad + INCREMENTO) * sizeof(int));
        this->capacidad += INCREMENTO;
    }

    if(n != i)
        memmove(this->vector+i+1, this->vector+i, (n-i)*sizeof(int));

    this->vector[i] = nuevoValor;
    this->n ++;
}

void ListaContigua::eliminar(int i){
    memmove(this->vector+i, this->vector+(i+1), (n-i)*sizeof(int));
    this->n--;

    if(this->capacidad - this->n >= 2*INCREMENTO){
        this->vector = (int *) realloc(this->vector, (this->capacidad - INCREMENTO) * sizeof(int));
        this->capacidad -= INCREMENTO;
    }

}

void ListaContigua::concatenar(const ListaContigua *otraLista) {
    this->vector = (int*)realloc(this->vector, (this->n + otraLista->n) * sizeof(int));

    for(int i = 0; i < otraLista->n; i++)
        this->vector[this->n+i] = otraLista->vector[i];

    this->n += otraLista->n;
    this->capacidad = this->n;

}

int ListaContigua::buscar(int num) {
    int i;

    for(i = 0; i < this->n; i++)
        if(this->vector[i] == num)
            break;

    return (i == n) ? -1 : i;
}
