#pragma once
class VectorEnteros{
	int * nums;
	int len;

public:
	VectorEnteros(int len);
	VectorEnteros(VectorEnteros &original, int len);
	~VectorEnteros();
	void ordenar();
	int* getNums();
	int getLen();
};

