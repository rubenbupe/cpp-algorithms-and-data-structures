//
// Created by Rubén Buzón Pérez on 2019-03-22.
//

#ifndef ACTIVIDAD4_4_NODO_H
#define ACTIVIDAD4_4_NODO_H

#pragma once

// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
    int elemento; // El elemento que guarda el nodo
    Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
    Nodo *anteriorNodo;
};


#endif //ACTIVIDAD4_4_NODO_H
