#pragma once
#ifndef Estructuras
#define Estructras

struct cliente
{
	int n_cuenta;
	char* nombre;
	double saldo;

	cliente(int y) {
		nombre = 0;
		n_cuenta = y;
		saldo = 0;
	}
	cliente() {
		nombre = 0;
		n_cuenta = 0;
		saldo = 0;
	}
};//size of 32
struct transa
{
	int numero;
	int tipo;
	double saldo;

	transa(int num, int tip, double x) {
		numero = num;
		tipo = tip;
		saldo = x;
	}
	transa() {
		numero = 0;
		tipo = 0;
		saldo = 0;
	}
};

#endif // !Estructuras
