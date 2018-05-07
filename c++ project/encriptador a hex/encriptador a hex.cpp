// encriptador a hex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
//esta es la libreria usada para tener los comandos std::hex std::oct std::dec
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

void mensaje();
void encript();

int main()
{
	cout << "Encriptador 1.0 string a hexdecimal" << endl;
	mensaje();
	cout << "\npresione una tecla apara continuar\n" << endl;
	_getch();
    return 0;
}

void encript() {
	ifstream fe("mensaje.txt");
	ofstream file ("mEncript.txt");
	char men[128];
	int imen[128];
	int opcion = 0;
	fe.getline(men, 256);
	/*guardamos los archivos en la variable men para luego convertirlos a entero con imen
	pasando imen despues a hexadecimal en el segundo ciclo for para despues guardar todo en un archivo de texto
	*/
	for (int i = 0; i < (sizeof(men)/sizeof(*men)); i++) {
		imen[i] = men[i];
	}
	for (int i = 0; i < (sizeof(imen)/sizeof(*imen)); i++) {
		file << "0x" << hex << imen[i] << " ";
	}
	cout << "\nmensaje encriptado con exito, espere por favor... \n" << endl;
	Sleep(500);
	file.close();
	fe.close();
	//aqui debio guardarse el encriptado en el archivo de encriptacion
	cout << "desea abrir el encriptado? \nescriba 1 para abrir" << endl;
	cin >> opcion;
	if (opcion == 1) {
		system("notepad.exe mEncript.txt");
	}
}

void mensaje() {
	/*aqui guardamos la variable men en un archivo de texto utilizando ofstream
	also para getline ocupas la libreria <string>
	*/
	string men;
	ofstream fs("mensaje.txt");
	getline(cin, men);
	fs << men << endl;
	fs.close();
	cout << "espere por favor...\n";
	Sleep(300);
	cout << "mensaje guardado con exito..." << endl;
	encript();

}

