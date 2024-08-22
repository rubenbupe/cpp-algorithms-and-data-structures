
#include "ListaEnlazada.h"

Nodo *ListaEnlazada::getNodo(int posicion) {
    //assert(posicion >= 0 && posicion < this->n);

    Nodo *nodoActual;
    int direccionBusqueda;

    if(posicion == this->posicionUltimoNodoAccedido )
        nodoActual = this->punteroUltimoNodoAccedido;
    else if(posicion == this->posicionUltimoNodoAccedido + 1 && this->posicionUltimoNodoAccedido != -1)
        nodoActual = this->punteroUltimoNodoAccedido->siguienteNodo;
    else if(posicion == this->posicionUltimoNodoAccedido - 1)
        nodoActual = this->punteroUltimoNodoAccedido->anteriorNodo;
    else {
        nodoActual = this->lista;
        if(posicion < n/2)
            for (int i = 0; i < posicion; i++)
                nodoActual = nodoActual->siguienteNodo;
        else
            for (int i = n-posicion; i > 0; i--)
                nodoActual = nodoActual->anteriorNodo;
    }


    this->punteroUltimoNodoAccedido = nodoActual;
    this->posicionUltimoNodoAccedido = posicion;

    return nodoActual;
}

ListaEnlazada::ListaEnlazada() {
    this->n = 0;
    this->lista = NULL;
    this->posicionUltimoNodoAccedido = -1;
    this->punteroUltimoNodoAccedido = NULL;

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




    if(posicion == 0 && this->n == 0) {
        this->lista = nuevoNodo;
        nuevoNodo->siguienteNodo = nuevoNodo;
        nuevoNodo->anteriorNodo = nuevoNodo;
    }else{
        Nodo * siguienteNodo = getNodo(posicion);
        nuevoNodo->siguienteNodo = siguienteNodo;
        nuevoNodo->anteriorNodo = siguienteNodo->anteriorNodo;
        nuevoNodo->anteriorNodo->siguienteNodo = nuevoNodo;
        nuevoNodo->siguienteNodo->anteriorNodo = nuevoNodo;
        if(posicion == 0)
            this->lista = nuevoNodo;
    }

    this->n++;
    this->posicionUltimoNodoAccedido = -1;
    this->punteroUltimoNodoAccedido = NULL;


}


void ListaEnlazada::eliminar(int posicion) {
    assert(posicion >= 0 && posicion < n);

    Nodo *nodoEliminar;
    nodoEliminar = getNodo(posicion);


    /*if(posicion == 0){
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
    }*/

    if(this->n == 1){
        delete nodoEliminar;
        this->lista = NULL;
    }else{
        nodoEliminar->siguienteNodo->anteriorNodo = nodoEliminar->anteriorNodo;
        nodoEliminar->anteriorNodo->siguienteNodo = nodoEliminar->siguienteNodo;
        if(posicion == 0)
            this->lista = nodoEliminar->siguienteNodo;
        delete nodoEliminar;
    }


    this->n--;
    this->posicionUltimoNodoAccedido = -1;
    this->punteroUltimoNodoAccedido = NULL;

}

ListaEnlazada::~ListaEnlazada() {

    while(n > 0){
        eliminar(0);
    }

}

void ListaEnlazada::concatenar(ListaEnlazada &lista2) {

    for(int i = 0; i < lista2.n; i++){
        this->insertar(this->n, lista2.getValor(i));
    }

}

int ListaEnlazada::buscar(int valor) {
    int i;

    for (i = 0; i < this->n; i++){
        if (getNodo(i)->elemento == valor)
            break;
    }

    return (this->n == 0 || i == this->n) ? -1 : i;
}



