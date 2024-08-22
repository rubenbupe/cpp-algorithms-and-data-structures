//
// Created by Rubén Buzón Pérez on 2019-03-25.
//

#ifndef ACTIVIDAD_4_5_IMPRESIONLISTASENLAZADAS_H
#define ACTIVIDAD_4_5_IMPRESIONLISTASENLAZADAS_H

#pragma once
#include "ListaEnlazada.h"
#include "iostream"

// Imprime una lista enlazada por pantalla (su "n" y sus elementos), con un maximo de 20 elementos
// Parámetros:
// - lista: puntero a la lista enlazada que queremos imprimir
// Precondición: lista!=NULL
// Complejidad temporal: O(n^2). Realmente es O(1) porque como maximo imprime 20 elementos
// Complejidad espacial: O(1)
void imprimirListaEnlazada(ListaEnlazada *lista);



#endif //ACTIVIDAD_4_5_IMPRESIONLISTASENLAZADAS_H
