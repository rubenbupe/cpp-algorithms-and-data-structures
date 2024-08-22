#include "iostream"
#include "ListaContigua.h"
#include "impresionListasContiguas.h"

using namespace std;


int main() {

	// Creamos una ListaContigua que nos servirá para las pruebas
	ListaContigua lista, lista2;
	int posBuscar;


	cout << "Lista creada:" << endl;

	imprimirListaContigua(&lista);

	for(int i = 0; i <= 10; i++){
		cout << "Anadido " << i << " en la posicion " << i << endl;
		lista.insertarAlFinal(i);
		imprimirListaContigua(&lista);
	}

	for(int i = 0; i < 5; i++){
		cout << "Anadido " << 100+i << " en la posicion " << i << endl;
		lista.insertar(100 + i, 0);
		imprimirListaContigua(&lista);
	}

	cout << "Anadido 200 en la posicion 3" << endl;
	lista.insertar(200, 3);
	imprimirListaContigua(&lista);

	cout << "Eliminados ultimos 5 elementos" << endl;
	for(int i = 0; i < 5; i++) {
		lista.eliminarAlFinal();
		imprimirListaContigua(&lista);
	}


	cout << "Eliminados primeros 5 elementos" << endl;
	for(int i = 0; i < 5; i++) {
		lista.eliminar(0);
		imprimirListaContigua(&lista);
	}

	posBuscar = lista.buscar(100);
	if(posBuscar >= 0)
		cout << "Se ha encontrado el 100 en la posicion " << posBuscar << endl;
	else
		cout << "No se ha encontrado el 100 en la lista" << endl;


	posBuscar = lista.buscar(2);
	if(posBuscar >= 0)
		cout << "Se ha encontrado el 2 en la posicion " << posBuscar << endl;
	else
		cout << "No se ha encontrado el 2 en la lista" << endl;


	posBuscar = lista.buscar(5);
	if(posBuscar >= 0)
		cout << "Se ha encontrado el 5 en la posicion " << posBuscar << endl;
	else
		cout << "No se ha encontrado el 5 en la lista" << endl;


	posBuscar = lista.buscar(20);
	if(posBuscar >= 0)
		cout << "Se ha encontrado el 20 en la posicion " << posBuscar << endl;
	else
		cout << "No se ha encontrado el 20 en la lista" << endl;


	cout << "Creada la lista 2" << endl;
	for(int i = 0; i < 6; i++){
		lista2.insertarAlFinal(500+i);
		imprimirListaContigua(&lista2);
	}

	cout << "Concatenada la lista 2 a la lista 1" << endl;
	lista.concatenar(&lista2);
	imprimirListaContigua(&lista);


	/*cout << endl << endl;
	lista.insertar(222, 5);
    imprimirListaContigua(&lista);
    lista.eliminar(5);
    imprimirListaContigua(&lista);


    cout << endl << endl;

	lista2.insertarAlFinal(999);
	lista2.insertarAlFinal(998);
	lista2.insertarAlFinal(997);

	lista.concatenar(&lista2);
	imprimirListaContigua(&lista2);
	imprimirListaContigua(&lista);

	cout << lista.buscar(1) << endl;
	cout << lista.buscar(999) << endl;
	cout << lista.buscar(997) << endl;
	cout << lista.buscar(-1) << endl;*/


	return 0;
}

