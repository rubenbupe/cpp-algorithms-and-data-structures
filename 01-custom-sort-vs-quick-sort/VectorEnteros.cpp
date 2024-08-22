#include "Header.h"


VectorEnteros::VectorEnteros(int len) {
	int i;
	
	this->nums = (int*)malloc(len * sizeof(int));
	for (i = 0; i < len; i++)
		*(this->nums + i) = rand();

	this->len = len;

}

VectorEnteros::VectorEnteros(VectorEnteros &original, int len) {
	int i;

	this->nums = (int*)malloc(len * sizeof(int));
	for (i = 0; i < len; i++)
		*(this->nums + i) = *(original.nums + i);

	this->len = len;
}


VectorEnteros::~VectorEnteros(){
	if (this->nums != NULL)
		free(this->nums);
}


void VectorEnteros::ordenar() {
	int i, start, iMayor, tmp;

	for (start = 0; start < this->len; start++) {
		for (i = start + 1, iMayor = start; i < this->len; i++) 
			if (*(this->nums + i) > *(this->nums + iMayor))
				iMayor = i;

		tmp = *(this->nums + start);
		*(this->nums + start) = *(this->nums + iMayor);
		*(this->nums + iMayor) = tmp;
	}
}

int* VectorEnteros::getNums() {
	return this->nums;
}

int VectorEnteros::getLen() {
	return this->len;
}