//
// Created by Rubén Buzón Pérez on 2019-04-26.
//

#include "ListaContiguaOrdenada.h"

void ListaContiguaOrdenada::insertar(int nuevoValor) {
    int i;
    for(i = 0; i < this->getN(); i++){
        if(this->getValor(i) >= nuevoValor)
            break;
    }

    ListaContigua::insertar(nuevoValor, i);
}

int ListaContiguaOrdenada::buscar(int elementoABuscar) {
    return ListaContigua::buscar(elementoABuscar);
}

void ListaContiguaOrdenada::eliminar(int elementoAEliminar) {
    ListaContigua::eliminar(elementoAEliminar);
}

int ListaContiguaOrdenada::buscarPosicion(int valorABuscar, int posicionInicioSublista, int posicionFinSublista) {
    int res;
    if(posicionInicioSublista <= posicionFinSublista){
        int m = (posicionFinSublista + posicionInicioSublista)/2;
        if(valorABuscar < this->getValor(m))
            res = this->buscarPosicion(valorABuscar, posicionInicioSublista, m-1);
        else if(valorABuscar > this->getValor(m))
            res = this->buscarPosicion(valorABuscar, m+1, posicionFinSublista);
        else res = m;
    }else res = posicionInicioSublista;

    return res;
}


