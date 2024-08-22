#include <iostream>
#include "Header.h"

#define LEN 1000

using namespace std;

int main() {
	VectorEnteros *original, *ordenadoIneficiente, *ordenadoQSort;
	int lenInput;
	time_t start, end;

	srand(time(NULL));

	cout << "Introduce el tamano del vector <numero mayor o igual que 1>: ";
	cin >> lenInput;

	cout << endl;

	original = new VectorEnteros(lenInput);
	ordenadoIneficiente = new VectorEnteros(*original, lenInput);
	ordenadoQSort = new VectorEnteros(*original, lenInput);

	cout << "El vector original es el siguiente: " << endl;
	imprimirArray(original->getNums(), original->getLen());

	cout << endl;

	start = clock();
	ordenadoIneficiente->ordenar();
	end = clock();

	cout << "Clocks de inicio con ordenacion por seleccion:\t" << start << endl;
	cout << "Clocks de fin con ordenacion por seleccion:\t" << end << endl;
	cout << "CLOCKS_PER_SEC:\t\t\t\t\t" << CLOCKS_PER_SEC << endl;
	cout << "Con ordenacion por seleccion he tardado " << (end - start) / (float)CLOCKS_PER_SEC << " segundos en ordenarlo." << endl;
	cout << "El vector resultado es:" << endl;
	imprimirArray(ordenadoIneficiente->getNums(), ordenadoIneficiente->getLen());

	cout << endl;

	start = clock();
	qsort(ordenadoQSort->getNums(), ordenadoQSort->getLen(), sizeof(int), ordenQSort);
	end = clock();

	cout << "Clocks de inicio con ordenacion por QuickSort:\t" << start << endl;
	cout << "Clocks de fin con ordenacion por QuickSort:\t" << end << endl;
	cout << "CLOCKS_PER_SEC:\t\t\t\t\t" << CLOCKS_PER_SEC << endl;
	cout << "Con ordenacion por QuickSort he tardado " << (end - start) / (double)CLOCKS_PER_SEC << " segundos en ordenarlo." << endl;
	cout << "El vector resultado es:" << endl;
	imprimirArray(ordenadoQSort->getNums(), ordenadoQSort->getLen());


	return 0;
}