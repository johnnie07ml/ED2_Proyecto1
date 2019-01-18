
#pragma once
#include <stdarg.h>
#include <iostream>
#include <string>
#include <fstream>
#include "ArchivoMaestro.h"
#include "Estructuras.h"
using namespace std;

bool ArchivoMastro::buscar(int x) {
	ifstream cuentasIn("archivoInfo.dat", ios::in | ios::binary);
	if (!cuentasIn)
	{
		cout << "Error al abrir el archivo \n";
		return false;
	}

	cliente tmp;

	cuentasIn.seekg(0, ios::beg);
	cuentasIn.read(reinterpret_cast<char*>(&tmp), sizeof(cliente));

	while (!cuentasIn.eof())
	{
		if (tmp.n_cuenta == x)
		{
			cuentasIn.close();
			return true;
		}
		cuentasIn.read(reinterpret_cast<char*>(&tmp), sizeof(cliente));
	}
	cuentasIn.close();
	return false;
}

void ArchivoMastro::crear(int x, char nombre[20]) {
	cliente nuevo = cliente(x);
	strcpy_s(nuevo.nombre, sizeof(nuevo.nombre), nombre);
	ofstream cuentasOut("archivoInfo.dat", ios::out | ios::app | ios::binary);

	if (!cuentasOut) {
		cout << "Error al intentar abrir el Archivo Maestro" << endl;
		return;
	}

	//Setteamos el saldo INICIALMENTE en 0
	cuentasOut.seekp(0, ios::end);      //Busca y Coloca
	cuentasOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(cliente));
	cuentasOut.close();
}

void ArchivoMastro::deposito(int x, double y) {
	if (buscar(x) == false) {
		cout << "Cuenta Inexistente!" << endl;
		return;
	}

	ifstream cuentasIn("archivoInfo.dat", ios::in | ios::binary);

	if (!cuentasIn) {
		cout << "Error al abrir el archivo!" << endl;
		return;
	}

	cliente temporal;

	cuentasIn.seekg(0, ios::beg);

	cuentasIn.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));

	while (!cuentasIn.eof()) {
		if (temporal.n_cuenta == x) {
			ofstream cuentaOut("archivoInfo.dat", ios::out | ios::binary);
			temporal.saldo = temporal.saldo + y;
			cuentaOut.write((char *)(&temporal), sizeof(cliente));
		}
		cuentasIn.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));
	}
	agregarTrans(1, x, y);

	cuentasIn.close();
}

void ArchivoMastro::retiro(int x, int y) {
	if (buscar(x) == false) {
		cout << "Cuenta Inexistente!" << endl;
		return;
	}

	ifstream archivo("archivoInfo.dat", ios::in | ios::binary);

	if (!archivo) {
		cout << "Error al abrir el archivo!" << endl;
		return;
	}

	cliente temporal;

	archivo.seekg(0, ios::beg);

	archivo.read(reinterpret_cast<char *>(&temporal), sizeof(cliente));

	while (!archivo.eof()) {

		if (temporal.n_cuenta == x) {

			ofstream archivoOut("archivoInfo.dat", ios::out | ios::binary);
			temporal.saldo = temporal.saldo - y;
			archivoOut.write((char *)(&temporal), sizeof(cliente));
		}
		agregarTrans(2, x, y);

		archivo.close();
	}
}

void ArchivoMastro::transacciones(int x) {

	if (buscar(x) == false) {
		cout << "Cuenta Inexistente!" << endl;
		return;
	}

	ifstream transaccionIn("archivoTransacciones.dat", ios::in | ios::binary);

	if (!transaccionIn) {
		cout << "Error al abrir el archivo!" << endl;
		return;
	}

	transa temporal;

	transaccionIn.seekg(0, ios::beg);
	transaccionIn.read(reinterpret_cast<char *>(&temporal), sizeof(transa));

	while (!transaccionIn.eof()) {

		if (temporal.numero == x) {
			cout << "Tipo de Transaccion: " << temporal.tipo << ", Saldo: " << temporal.saldo << endl;
		}
		transaccionIn.read(reinterpret_cast<char *>(&temporal), sizeof(transa));
	}

	transaccionIn.close();
}

void ArchivoMastro::agregarTrans(int tip, int clie, double saldo) {
	transa nuevo = transa(clie, tip, saldo);
	ofstream cuentasOut("archivoTransacciones.dat", ios::out | ios::app | ios::binary);

	if (!cuentasOut) {
		cout << "Error al intentar abrir el Archivo" << endl;
		return;
	}

	//Setteamos el saldo INICIALMENTE en 0
	cuentasOut.seekp(0, ios::end);      //Busca y Coloca
	cuentasOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(transa));
	cuentasOut.close();
}


