//
// Created by Rubén Buzón Pérez on 2019-03-25.
//

#ifndef ACTIVIDAD_4_5_NODO_H
#define ACTIVIDAD_4_5_NODO_H

#pragma once

// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
    int elemento; // El elemento que guarda el nodo
    Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
    Nodo *anteriorNodo;
};


#endif //ACTIVIDAD_4_5_NODO_H
