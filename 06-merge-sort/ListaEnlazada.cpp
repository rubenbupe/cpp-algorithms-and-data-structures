
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



int ListaEnlazada::buscar(int valor) {
    int i;

    for (i = 0; i < this->n; i++){
        if (getNodo(i)->elemento == valor)
            break;
    }

    return (this->n == 0 || i == this->n) ? -1 : i;
}

void ListaEnlazada::ordenar() {
    ordenarPorMergeSortRecursivo(this);
}

void ListaEnlazada::ordenarPorMergeSortRecursivo(ListaEnlazada *lista) {

    if(lista->n > 1){
        ListaEnlazada l1, l2;
        repartir(lista, &l1, &l2);
        ordenarPorMergeSortRecursivo(&l1);
        ordenarPorMergeSortRecursivo(&l2);
        combinar(&l1, &l2, lista);
    }



}

void ListaEnlazada::repartir(ListaEnlazada *listaCompleta, ListaEnlazada *sublista1, ListaEnlazada *sublista2) {
    assert(listaCompleta != NULL && sublista1 != NULL && sublista2 != NULL);
    assert(listaCompleta->n >= 2 );
    assert(sublista1->n == 0 && sublista2->n == 0 );
    int listaCompletaLen = listaCompleta->n;

    for(int i = 0; i < listaCompletaLen/2; i++){
        sublista1->insertar(i, listaCompleta->getValor(0));
        listaCompleta->eliminar(0);
    }
    for (int i = listaCompletaLen/2; i < listaCompletaLen;i++){
        sublista2->insertar(i - listaCompletaLen/2, listaCompleta->getValor(0));
        listaCompleta->eliminar(0);
    }
}

void ListaEnlazada::combinar(ListaEnlazada *origen1, ListaEnlazada *origen2, ListaEnlazada *destino) {
    assert(origen1 != NULL && origen2 != NULL && destino != NULL);
    assert(origen1->n >= 1 && origen2->n >= 1);
    assert(destino->n == 0);
    int totalLen = origen1->n + origen2->n;

    while(totalLen > 0){

        if(origen1->n == 0) {
            destino->insertar(destino->n, origen2->getValor(0));
            origen2->eliminar(0);
        }else if(origen2->n == 0) {
            destino->insertar(destino->n, origen1->getValor(0));
            origen1->eliminar(0);
        }else{
            if (origen2->getValor(0) < origen1->getValor(0)){
                destino->insertar(destino->n, origen2->getValor(0));
                origen2->eliminar(0);
            }else{
                destino->insertar(destino->n, origen1->getValor(0));
                origen1->eliminar(0);
            }
        }


        totalLen --;
    }

}

bool ListaEnlazada::isOrdenada(ListaEnlazada *lista) {
    for(int i = 0; i < lista->n - 1; i++){
        if(lista->getValor(i) > lista->getValor(i + 1))
            return false;
    }
    return true;
}




