//
// Created by Rubén Buzón Pérez on 2019-03-26.
//

#ifndef ACTIVIDAD_4_5_PILA_H
#define ACTIVIDAD_4_5_PILA_H


#include "ListaEnlazada.h"

class Pila: public ListaEnlazada {

public:
    Pila();

    void push(int valor);
    int pop();
    int verCima();
    bool isVacia();
};


#endif //ACTIVIDAD_4_5_PILA_H
