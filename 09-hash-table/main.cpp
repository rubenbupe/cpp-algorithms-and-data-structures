#include <iostream>
#include "TablaHashDeEstudiantes.h"

using namespace std;


int main() {

    int opt, clave;
    char nombre[100];
    TablaHashDeEstudiantes *tablaHashDeEstudiantes = new TablaHashDeEstudiantes(5);

    do{
        cout << "Elige una opcion" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Imprimir tabla" << endl;
        cout << "2. Comprobar si existe un estudiante" << endl;
        cout << "3. Ver estudiante" << endl;
        cout << "4. Insertar Estudiante" << endl;
        cout << "5. Eliminar estudiante" << endl;

        cin >> opt;

        switch (opt){
            case 0:break;
            case 1:
                tablaHashDeEstudiantes->imprimirTabla();
                break;
            case 2:
                cout << "Introduce el numero de matricula: ";
                cin >> clave;
                cout << ((tablaHashDeEstudiantes->existeAlumno(clave)) ? "Existe" : "No existe" )<< endl;
                break;
            case 3:
                cout << "Introduce el numero de matricula: ";
                cin >> clave;
                cout << tablaHashDeEstudiantes->obtenerEstudiante(clave) << endl;
                break;
            case 4:
                cout << "Introduce el numero de matricula: ";
                cin >> clave;
                cout << "Introduce el nombre del alumno";
                cin >> nombre;
                tablaHashDeEstudiantes->insertarEstudiante(clave, nombre);
                cout << "Done";
                break;
            case 5:
                cout << "Introduce el numero de matricula: ";
                cin >> clave;
                tablaHashDeEstudiantes->eliminarEstudiante(clave);
                cout << "Done";
                break;
        }


    }while(opt != 0);

    return 666;
}