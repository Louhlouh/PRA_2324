//	 ALUMNO: Lourdes Francés Llimerá
//PARA EJECUTAR: g++ -o Mochila Mochila.cpp 

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

void show_aux(vector<vector<int>> aux, int m, int size){ //hecho para comprobar errores

	for (int i = 0; i < size + 1; i++){
		for (int j = 0; j < m + 1; j++){
			cout << "Aux[" << i << "][" << j << "] = " << aux[i][j] << endl;
		}
		cout << endl;
	}

}

int devolver_beneficio(vector<int> &p, vector<int> &b, vector<int> &v, int m){ 

	int size = p.size(); //n

	//vector de vectores int con tamaño de fila = n + 1 y tamaño de columna = m + 1 iniciado a 0
	vector<vector<int>> aux (size + 1, vector<int>(m + 1 , 0));  
	
	for ( int i = 1 ; i < size + 1 ; i++ ){
		
		for ( int j = 1 ; j < m + 1 ; j++ ){

				if ( j >= p[i - 1] ){ 
				//objeto <= peso del requerido

					if (aux[i - 1][j] == 0){
					//está vacío

						aux[i][j] = b[i - 1];

					}

					aux[i][j] = max( aux[i - 1][j], b[i - 1] + aux[i - 1][j - p[i - 1]] ); //j - p[i] indica el espacio sobrante
								   //b anterior     b actual + b anterior si peso lo permite

				}
				else{ 
				//objeto > peso del requerido

					aux[i][j] = aux[i - 1][j];

				}

		}

	}

	//2a PARTE 
	int i = size, j = m; 

	while( i > 0 && j > 0){ 

		if ( aux[i][j] != aux[i - 1][j] ){ //se incluye el objeto actual

			v[i - 1] = 1;
			j = j - p[i - 1]; //se elimina el peso del objeto incluido
	
		}

		i--;

	}

	return aux[size][m];

}

int main(int argc, char** argv){
	
	int m, n;
	vector<int> p;
	vector<int> b; 

    cout << LBLUE << ">> Ingresa la cantidad de objetos: " << RESET;
   	cin >> n;

   	vector<int> v(n, 0); //2a Parte

   	cout << endl;

	if (n <= 0){ //comprobamos que peso > 0

		cout << RED << "	<< Error a la hora de ingresar la cantidad de objetos. Debe ser un número mayor a 0 >>	" << RESET << endl << endl;
		return 1;

	}

    cout << LBLUE << ">> Ingresa el peso máximo: " << RESET;
   	cin >> m;

   	cout << endl;

	if (m <= 0){ //comprobamos que peso > 0

		cout << RED << "	<< Error a la hora de ingresar el peso máximo. Debe ser un número mayor a 0 >>	" << RESET << endl << endl;
		return 1;

	}

   	cout << LBLUE << ">> Ingresa los pesos uno por uno (siendo estos menores al peso máximo):" << RESET << endl;

   	for (int i = 0; i < n; i++) { 

		int valor;
		cout << ROSE << "				Peso " << i + 1 << ": " << RESET;
		cin >> valor;

		while (valor <= 0){ //comprobamos que peso > 0

			cout << ROSE << "				Peso " << i + 1 << ": " << RESET;
			cin >> valor;

		}

		p.push_back(valor);

    }

    cout << endl;


    cout << LBLUE << ">> Ingresa los beneficios uno por uno:" << RESET << endl;

   	for (int i = 0; i < n; i++) { 

		int valor;
		cout << ROSE << "				Beneficio " << i + 1 << ": " << RESET;
		cin >> valor;

		while (valor <= 0){ //comprobamos que beneficio > 0

			cout << ROSE << "				Beneficio " << i + 1 << ": " << RESET;
			cin >> valor;

		}

		b.push_back(valor);

    }

    cout << endl;

    cout << LGREEN << "<< Los (pesos-beneficios) ingresados son: " << RESET;

    for (int i = 0; i < n; i++) {

        cout << "(" << p[i] << "-" << b[i] << ") ";

    }

    cout << endl << endl;

    int beneficio_maximo = devolver_beneficio(p, b, v, m);

    if ( beneficio_maximo == 0 ){

    	cout << RED << "	<< Los pesos son mayores que el peso máximo >>	" << RESET << endl << endl;

    }

    else {

    cout << LGREEN << "<< Máximo beneficio: " << RESET << beneficio_maximo << endl << endl;

    }

    //2a Parte

    for (int i = 0; i < n; i++){

    	cout << LGREEN << "Objeto [ " << i << " ]: " << RESET << ( (v[i] == 1) ? "1" : "0" ) << endl << endl;

    }

	return 0;

}