#include "iostream"
#include "ListaEnlazada.h"
#include "Pila.h"
#include "impresionListasEnlazadas.h"
using namespace std;


int main () {

    int opt, valor;
    Pila pila;

    cout << "MENU:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Cima" << endl;
    cout << "4. Salir" << endl;


    do{

        cout << "Por favor, introduce una opcion del 1 al 4: ";
        cin >> opt;

        switch (opt){
            case 1:
                cout << "Introduce el valor a introducir: ";
                cin >> valor;
                pila.push(valor);
                break;
            case 2:
                if(!pila.isVacia())
                    cout << "La cima de la pila es " << pila.pop() << endl;
                else
                    cout << "La pila esta vacia, por lo tanto no se puede hacer pop" << endl;
                break;
            case 3:
                if(!pila.isVacia())
                    cout << "La cima de la pila es " << pila.verCima() << endl;
                else
                    cout << "La pila esta vacia, por lo tanto no se puede ver la cima" << endl;
                break;
            case 4:
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        if(opt > 0 && opt < 5){
            cout << "Pila completa: ";
            imprimirListaEnlazada(&pila);
        }

    }while(opt != 4);

    return 0;
}

