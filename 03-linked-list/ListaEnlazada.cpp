
#include "ListaEnlazada.h"

Nodo *ListaEnlazada::getNodo(int posicion) {
    //assert(posicion >= 0 && posicion < this->n);

    Nodo *nodoActual = this->lista;

    for(int i = 0; i < posicion; i++)
        nodoActual = nodoActual->siguienteNodo;

    return nodoActual;
}

ListaEnlazada::ListaEnlazada() {
    this->n = 0;
    this->lista = NULL;

}

int ListaEnlazada::getValor(int posicion) {
    assert(posicion >= 0 && posicion < this->n);

    Nodo* nodoActual = getNodo(posicion);

    return nodoActual->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor) {
    assert(posicion >= 0 && posicion < this->n);

    Nodo* nodoActual = getNodo(posicion);

    nodoActual->elemento = nuevoValor;

}

int ListaEnlazada::getN() {
    return this->n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor) {
    assert(posicion >= 0 && posicion <= n);

    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->elemento = nuevoValor;



    if(posicion == 0){
        if(this->n != 0)
            nuevoNodo->siguienteNodo = getNodo(0);
        else
            nuevoNodo->siguienteNodo = NULL;
        this->lista = nuevoNodo;
    }
    else {
        if(this->n == posicion)
            nuevoNodo->siguienteNodo =  NULL;
        else
            nuevoNodo->siguienteNodo = getNodo(posicion);
        this->getNodo(posicion-1)->siguienteNodo = nuevoNodo;
    }

    this->n++;

}


void ListaEnlazada::eliminar(int posicion) {
    assert(posicion >= 0 && posicion < n);

    Nodo *nodoEliminar;
    nodoEliminar = getNodo(posicion);


    if(posicion == 0){
        if(this->n != 0)
            this->lista = getNodo(posicion+1);
        else
            this->lista = NULL;
        delete nodoEliminar;
    }else{
        if(posicion != n)
            getNodo(posicion-1)->siguienteNodo = nodoEliminar->siguienteNodo;
        else
            getNodo(posicion-1)->siguienteNodo = NULL;
        delete nodoEliminar;
    }


    this->n--;
}

ListaEnlazada::~ListaEnlazada() {

    while(n > 0){
        eliminar(0);
    }

}



