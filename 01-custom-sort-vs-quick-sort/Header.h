#pragma once
#include "VectorEnteros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//Imprime un array de números si su longitud es menor o igual que 10.
void imprimirArray(int *nums, int len);

//Filtro para QuickSort que ordena los numeros de mayor a menor.
int ordenQSort(const void * a, const void * b);