#include <iostream>
#include "ArchivoMaestro.h"
using namespace std;

int main() {
	banco ban();
	int cuentaActiva = 0;
	cout << "Bienvenido \n1.Crear cuenta \n2.Ingresar a cuenta\n";
	char op1 = 0;
	cin >> op1;

	if (op1 == '1') {
		char nom[20];
		cout << "Ingrese su nombre\n";
		cin >> nom;
		int x = 0;
		do {
			if (x != 0) {
				cout << "\nNumero de cuenta ya existente\n";
			}
			cout << "Ingrese numero de cuenta:\n";
			cin >> x;
			
		} while (ban().buscar(x));
		ban().crear(x, nom);
		cout << "\nCuenta creada con exito\n";
		cuentaActiva = x;
	}
	else if (op1 == '2') {
		int p = 0;
		do {
			if (p != 0) {
				cout << "Cuenta no encontrada intente de nuevo\n";
			}

			cout << "Ingrese numero de cuenta que desea ultilizar:\n";
			cin >> p;
		} while (ban().buscar(p) == false);
		cuentaActiva = p;
	}




	bool rep = true;
	char op = 0;
	if (cuentaActiva != 0) {
		while (rep == true) {
			cout << "\nQue desea hacer? \n1.Abonar\n2.Retirar\n3.Obtener transacciones \n4.Salir\n";
			cin >> op;
			switch (op) {
			case '1':
				cout << "\n--------------\n";

				rep = true;
				break;
			case '2':
				cout << "\n--------------\n";

				rep = true;
				break;
			case '3':
				cout << "\n--------------\n";

				rep = true;
				break;
			case '4':
				cout << "\n--------------\nGracias por probarme\n";
				rep = false;
				break;
			default:
				cout << "Ingreso una opcion invalida" << endl;
				rep = true;
				break;
			}
		}
	}
	else {
		cout << "Ingreso algo mal\n";
	}
	system("pause");
}
	