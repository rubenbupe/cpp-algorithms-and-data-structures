#include "impresionListasEnlazadas.h"

using namespace std;

void imprimirListaEnlazada(ListaEnlazada *lista){
    int n = lista->getN();
    cout << "n=" << n << "|ListaEnlazada=";

    if(n == 0)
        cout << "vacia" << endl;
    else {
        for (int i = 0; i < n - 1; i++)
            cout << lista->getValor(i) << ",";

        cout << lista->getValor(n-1) << endl;


    }

}
