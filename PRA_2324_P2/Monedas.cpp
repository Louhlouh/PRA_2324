//	 ALUMNO: Lourdes Francés Llimerá
//PARA EJECUTAR: g++ -o Monedas Monedas.cpp 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LGREEN "\x1B[38;2;17;245;120m"
#define ROSE "\x1B[38;2;255;151;203m"
#define LBLUE "\x1B[38;2;53;149;240m"

#define ORANGE  "\x1B[38;2;255;128;0m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

int devolver_monedas(vector<int> &v, vector<int> &b, int m){

	int size = v.size();

	//vector de vectores int con tamaño de fila = size y tamaño de columna = m+1 
	vector<vector<int>> aux (size, vector<int>(m + 1 , -1)); 

	aux[0][0] = 0;

	//rellenar la primera fila con 0
	for ( int j = 0 ; j < m + 1 ; j++ ){

		 if ( j >= v[0] && aux[0][j - v[0]] != -1 ){

			aux[0][j] = 1 + aux[0][j - v[0]];			

		}

	}
	
	for ( int i = 1 ; i < size ; i++ ){
	
		aux[i][0] = 0;
	
		for ( int j = 1 ; j < m + 1 ; j++ ){
			
			if ( j < v[i] || aux[i][j - v[i]] == -1 ){

				aux[i][j] = aux[i - 1][j];

			}
			else if ( aux[i - 1][j] != -1 ){

				aux[i][j] = min( aux[i - 1][j], 1 + aux[i][j - v[i]] );

			}
			else{

				aux[i][j] = 1 + aux[i][j - v[i]];

			}
		}
	}

	//2º apartado

	int i = size - 1;
	int j = m;

	while ( i >= 0 && j != 0){
		
		if ( i == 0 || aux[i][j] != aux[i - 1][j] ){

			b[i] = b[i] + 1;
			j = j - v[i];		

		}

		else{
			
			i--;

		}
		
	}

	return ( ( aux[size - 1][m] != -1 ) ? aux[size - 1][m] : -1 ); //si devuelve -1 tarda en cargar

}

int main(int argc, char** argv){
	
	vector<int> v;
	int m, n; 

    cout << LBLUE << ">> Ingresa la cantidad de monedas: " << RESET;
   	cin >> n;

	vector<int> b(n, 0); //vector nuevo

    cout << LBLUE << ">> Ingresa las monedas una por una:" << RESET << endl;

   	for (int i = 0; i < n; i++) { 

		int valor;
		cout << ROSE << "				Moneda " << i + 1 << ": " << RESET;
		cin >> valor;
		v.push_back(valor);

    }

    cout << LGREEN << "<< Las monedas ingresadas son: " << RESET;

    int size_v = v.size();

    for (int i = 0; i < size_v; i++) {

        cout << v[i] << " ";

    }

	cout << endl;

	cout << LBLUE << ">> Ingresa la cantidad a devolver: " << RESET;
	cin >> m;
	
	int monedas = devolver_monedas(v, b, m);

	if (monedas == -1) {

    	cout << LGREEN << "<< No hay una solución válida para devolver " << m << " uds." << RESET << endl;
	
	} 

	else {

		cout << LGREEN << "<< La cantidad mínima de monedas necesarias para devolver " << m << " uds. es de: " << RESET << endl; 
		cout << ROSE << "				" << monedas << " monedas" << RESET << endl;

		cout << LGREEN << "<< Cantidad de cada tipo de moneda:" << RESET << endl;

		int size_b = b.size();

		for (int i = 0; i < size_b; i++) {

			cout << ROSE << "				Moneda " << i + 1 << " [" << v[i] << "]: " << b[i] << " monedas" << RESET << endl;

		}

	}

	return 0;

}
