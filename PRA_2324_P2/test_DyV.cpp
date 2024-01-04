#include "DyV.h"
#include <chrono>

void Inicializar_variables(vector<int> &v_int, vector<double> v_double, vector<char> v_char){

	v_int = {80, 52, 9, 21};
	v_double = {83.4, 5.3, 23.2, 51.6};
	v_char = {'h', 's', 'v', 'b'};

}

void Medicion_Tiempos(){

	vector<int> v_int;
	vector<double> v_double;
	vector<char> v_char;

	Inicializar_variables(v_int, v_double, v_char);

	int size_int = v_int.size();
	int size_double = v_double.size();
	int size_char = v_char.size();	

	//// ÚLTIMO ////

	auto start = std::chrono::system_clock::now();
	QuickSort_ultimo_elemento(v_int, 0, size_int - 1);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	std::cout << "Time QuickSort último elemento int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_ultimo_elemento(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort último elemento double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_ultimo_elemento(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort último elemento char: " << duration.count() << "s" << std::endl;

	//// PRIMERO ////

	start = std::chrono::system_clock::now();
	QuickSort_primer_elemento(v_int, 0, size_int - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort primer elemento int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_primer_elemento(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort primer elemento double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_primer_elemento(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort primer elemento char: " << duration.count() << "s" << std::endl;

	//// CENTRAL ////

	start = std::chrono::system_clock::now();
	QuickSort_elemento_central(v_int, 0, size_int - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento central int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_elemento_central(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento central double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_elemento_central(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento central char: " << duration.count() << "s" << std::endl;

	//// ALEATORIO ////

	start = std::chrono::system_clock::now();
	QuickSort_elemento_aleatorio(v_int, 0, size_int - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento aleatorio int: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_elemento_aleatorio(v_double, 0, size_double - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento aleatorio double: " << duration.count() << "s" << std::endl;

	start = std::chrono::system_clock::now();
	QuickSort_elemento_aleatorio(v_char, 0, size_char - 1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	std::cout << "Time QuickSort elemento aleatorio char: " << duration.count() << "s" << std::endl;

}

int main(int argc, char** argv){
	
	//// BÚSQUEDA BINARIA ////

	cout << "		>> " << RED << "BÚSQUEDA BINARIA" << RESET << " <<		" << endl << endl;

	vector<int> v_int = {8, 15, 23, 51};
	int x_int = 8;
	int size_int = v_int.size();
	
	vector<double> v_double = {8.4, 15.3, 23.2, 51.6};
	double x_double = 23.2;
	int size_double = v_double.size();
	
	vector<char> v_char = {'a', 'e', 'h', 'v'};
	char x_char = 'v';
	int size_char = v_char.size();	
	
	cout << "Vector original int:" << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;
	
	cout << "Se va a buscar el número " << CYAN << x_int << RESET << " dentro del vector y se devolverá su posición." << endl << endl;
	
	cout << "Búsqueda binaria: " << LBLUE << busqueda_binaria(x_int, v_int, 0, size_int - 1) << RESET << endl << endl;
	
	cout << "Vector original double:" << ROSE;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;
		
	cout << "Se va a buscar el número " << MAGENTA << x_double << RESET << " dentro del vector y se devolverá su posición." << endl << endl;
		
	cout << "Búsqueda binaria: " << ROSE << busqueda_binaria(x_double, v_double, 0, size_double - 1) << RESET << endl << endl;
	
	cout << "Vector original char:" << LGREEN;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;
	
	cout << "Se va a buscar la letra " << ORANGE << x_char << RESET << " dentro del vector y se devolverá su posición." << endl << endl;
	
	cout << "Búsqueda binaria: " << LGREEN << busqueda_binaria(x_char, v_char, 0, size_char - 1) << RESET << endl << endl;

	//// QUICK SORT ÚLTIMO ////

	cout << "		>> " << RED << "QUICK SORT ÚLTIMO" << RESET << " <<		" << endl << endl;
	
	//inicializamos las variables con valores desordenados y manteniendo el tamaño
	Inicializar_variables(v_int, v_double, v_char);
	
	cout << "Se va a ordenar el vector: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	QuickSort_ultimo_elemento(v_int, 0, size_int - 1);

	cout << "Vector ordenado: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	cout << "Se va a ordenar el vector: " << ROSE;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;

	QuickSort_ultimo_elemento(v_double, 0, size_double - 1);

	cout << "Vector ordenado: " << MAGENTA;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;
		
	cout << "Se va a ordenar el vector: " << LGREEN;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	QuickSort_ultimo_elemento(v_char, 0, size_char - 1);

	cout << "Vector ordenado: " << ORANGE;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	//// QUICK SORT PRIMERO ////

	cout << "		>> " << RED << "QUICK SORT PRIMERO" << RESET << " <<		" << endl << endl;
	
	Inicializar_variables(v_int, v_double, v_char);
	
	cout << "Se va a ordenar el vector: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	QuickSort_primer_elemento(v_int, 0, size_int - 1);

	cout << "Vector ordenado: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	cout << "Se va a ordenar el vector: " << ROSE;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;

	QuickSort_primer_elemento(v_double, 0, size_double - 1);

	cout << "Vector ordenado: " << MAGENTA;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;
		
	cout << "Se va a ordenar el vector: " << LGREEN;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	QuickSort_primer_elemento(v_char, 0, size_char - 1);

	cout << "Vector ordenado: " << ORANGE;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	//// QUICK SORT CENTRAL ////

	cout << "		>> " << RED << "QUICK SORT CENTRAL" << RESET << " <<		" << endl << endl;
	
	Inicializar_variables(v_int, v_double, v_char);
	
	cout << "Se va a ordenar el vector: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	QuickSort_elemento_central(v_int, 0, size_int - 1);

	cout << "Vector ordenado: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	cout << "Se va a ordenar el vector: " << ROSE;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;

	QuickSort_elemento_central(v_double, 0, size_double - 1);

	cout << "Vector ordenado: " << MAGENTA;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;
		
	cout << "Se va a ordenar el vector: " << LGREEN;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	QuickSort_elemento_central(v_char, 0, size_char - 1);

	cout << "Vector ordenado: " << ORANGE;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	//// QUICK SORT ALEATORIO ////

	cout << "		>> " << RED << "QUICK SORT ALEATORIO" << RESET << " <<		" << endl << endl;
	
	Inicializar_variables(v_int, v_double, v_char);

	cout << "Se va a ordenar el vector: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	QuickSort_elemento_aleatorio(v_int, 0, size_int - 1);

	cout << "Vector ordenado: " << LBLUE;
	show_v(v_int, size_int);
	cout << RESET << endl << endl;

	cout << "Se va a ordenar el vector: " << ROSE;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;

	QuickSort_elemento_aleatorio(v_double, 0, size_double - 1);

	cout << "Vector ordenado: " << MAGENTA;
	show_v(v_double, size_double);
	cout << RESET << endl << endl;
		
	cout << "Se va a ordenar el vector: " << LGREEN;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	QuickSort_elemento_aleatorio(v_char, 0, size_char - 1);

	cout << "Vector ordenado: " << ORANGE;
	show_v(v_char, size_char);
	cout << RESET << endl << endl;

	cout << "		>> " << RED << "MEDICIÓN DE TIEMPOS" << RESET << " <<		" << endl << endl;

	Medicion_Tiempos();

	return 0;

}






