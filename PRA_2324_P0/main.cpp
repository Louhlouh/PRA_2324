#include <iostream>
#include "BrazoRobotico.h"

using namespace std;

int main(){
	
	BrazoRobotico br(0, 0, 0, false);
	cout << "Coordenadas iniciales: (" << br.getX() << ", " << br.getY()<< ", " << br.getZ() << ")" << endl;
	cout << (br.getSujetar() ? "Está sujetando un objeto." : "No está sujetando un objeto.") << endl << endl;

	cout << "Se va a mover el brazo a las coordenadas (2, 3, 4)." << endl;
	br.mover(2, 3, 4);
	cout << "Coordenadas tras mover: (" << br.getX() << ", " << br.getY()<< ", " << br.getZ() << ")" << endl;
	cout << (br.getSujetar() ? "Está sujetando un objeto." : "No está sujetando un objeto.") << endl << endl;

	cout << "Se va a coger un objeto." << endl;
	br.coger();
	cout << (br.getSujetar() ? "Está sujetando un objeto." : "No está sujetando un objeto.") << endl << endl;

	cout << "Se va a soltar un objeto." << endl;
	br.soltar();
	cout << (br.getSujetar() ? "Está sujetando un objeto." : "No está sujetando un objeto.") << endl << endl;

	return 0;
}
