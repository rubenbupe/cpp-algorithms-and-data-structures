//
// Created by Rubén Buzón Pérez on 2019-03-11.
//

#include "impresionListasContiguas.h"
using namespace std;

void imprimirListaContigua (ListaContigua *lista){
    cout << "n=" << lista->getN() << "|";
    cout << "MAX=" << lista->getCapacidad() << "|";
    cout << "ListaContigua=";
    if(lista->getN() == 0)
        cout << "vacia" << endl;
    else {
        for (int i = 0; i < lista->getN() - 1; i++) {
            cout << lista->getValor(i) << ",";
        }
        cout << lista->getValor(lista->getN() - 1) << endl;
    }
}
