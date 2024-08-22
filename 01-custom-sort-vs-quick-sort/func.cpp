#include "Header.h"
using namespace std;

void imprimirArray(int *nums, int len) {
	int i;

	if (len > 10)
		cout << "<demasiados componentes para mostrar>" << endl;
	else {
		for (i = 0; i < len; i++)
			cout << *(nums + i) << " ";
		cout << endl;
	}
}


int ordenQSort(const void * a, const void * b){
	if (*(int*)a < *(int*)b) return 1;
	if (*(int*)a == *(int*)b) return 0;
	if (*(int*)a > *(int*)b) return -1;
}

