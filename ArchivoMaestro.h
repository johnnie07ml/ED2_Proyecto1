#pragma once
#include"Estructuras.h"
#ifndef ArchivoMastro
#define ArchivoMastro

class banco {
public:
	banco();
	void crear(int x, char y[20]);
	void deposito(int x, double y);
	void retiro(int x, double y);
	void transacciones(int x);
	void agregarTrans(int x, int y, double saldo);
	bool buscar(int x);

};

#endif // !ArchicoMastro
