#pragma once
#include "ListaContigua.h"

// Lista que siempre se mantiene ordenada de menor a mayor
class ListaContiguaOrdenada : public ListaContigua
{

public:

    // Inserta un elemento en la posicion adecuada para que la lista siga ordenada
    // Parámetro: el nuevo elemento a insertar
    // Complejidad temporal: O(n) -O(lgn) para buscar la posicion adecuada y O(n) para insertar el elemento ahí-
    // Complejidad espacial: O(n) -O(lgn) para buscar la posicion adecuada y O(n) para insertar el elemento ahí-
    void insertar(int nuevoValor);

    // Busca la posición de un elemento en la ListaContigua
    // Parámetro: el elemento a buscar
    // Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
    // Complejidad temporal y espacial: O(lgn), pues llama a buscarPosicion()
    int buscar(int elementoABuscar);

    // Elimina un elemento de la lista sin necesidad de dar su posición. Lo busca primero
    // con búsqueda binaria
    // Parámetro: elemento a eliminar
    // Precondición: elementoAEliminar existe
    // Complejidad temporal: O(n)
    // Complejidad espacial: O(lgn), porque llama a buscarPosicion()
    void eliminar(int elementoAEliminar);

private:

    // Busca, mediante la búsqueda binaria recursiva, un elemento en una sublista de la lista actual.
    // Si no existe, devuelve la posición en que debería ser insertado para mantener la lista ordenada
    // Parámetros:
    // - valorABuscar: el elemento que se quiere buscar entre lista[inicio] y lista[nSublista-1] (ambos inclusive)
    // - inicio: posicion de inicio de la sublista, dentro de la lista actual
    // - nSublista: número de posiciones (a contar desde inicio, inclusive) que mide la sublista en donde buscar
    // Retorno: si lo encuentra, devuelve su posición. Si no lo encuentra, devuelve la
    // posicion en que debería ser insertado para mantener ordenada a la lista (de 0 a m),
    // siendo m el tamaño de la sublista (posicionFinSublista-posicionInicioSublista+1)
    // Precondiciones:
    // - posicionInicioSublista pertenece a [0,n-1]
    // - posicionFinSublista pertenece a [0,n-1]
    // - posicionInicioSublista <= posicionFinSublista
    // Complejidad temporal y espacial: O(lgm), tal como calculamos en la actividad 3.5
    int buscarPosicion(int valorABuscar, int posicionInicioSublista, int posicionFinSublista);
};
