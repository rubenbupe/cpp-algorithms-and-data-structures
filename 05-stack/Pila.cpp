//
// Created by Rubén Buzón Pérez on 2019-03-26.
//

#include "Pila.h"

Pila::Pila() : ListaEnlazada(){};

void Pila::push(int valor) {
    this->insertar(0, valor);
}

int Pila::pop() {
    assert(this->getN() > 0);
    int valor;

    valor = this->verCima();
    this->eliminar(0);

    return valor;
}

int Pila::verCima() {
    assert(this->getN() > 0);

    return this->getValor(0);
}

bool Pila::isVacia() {
    return this->getN() <= 0;
}





