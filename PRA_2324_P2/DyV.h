#ifndef DYH_H
#define DYH_H

#include <iostream>
#include <ostream>
#include <vector>

#include <cstdlib>
#include <ctime>

#define LGREEN "\x1B[38;2;17;245;120m"
#define ROSE "\x1B[38;2;255;151;203m"
#define LBLUE "\x1B[38;2;53;149;240m"

#define ORANGE  "\x1B[38;2;255;128;0m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

using namespace std;

//// BÚSQUEDA BINARIA ////

template <typename T> 

int busqueda_binaria(T x, vector<T> &v, int ini, int fin){
	
	if (ini > fin){
	
		cout << RED << x << " no se encuentra en el array." << RESET << endl << endl;
		return -1;
		
	}
	
	else {
	
		int medio = ( ini + fin ) / 2;
		if ( v[medio] == x ){

			return medio;
			
		}
		
		else{
		
			if ( v[medio] > x){
			//x está más a la izquierda en el vector
			
				return busqueda_binaria(x, v, ini, medio - 1); 
				//se busca x en la 1ª mitad del vector 
				
			}
			
			else{
			
				return busqueda_binaria(x, v, medio + 1, fin);
				
			}
		}
	}
}

template <typename U> 

void show_v(vector<U> &v, int size){

	for(int i = 0; i < size; i++){
	
		cout << " " << v[i];	
		
	}

}

//// QUICK SORT ////

template <typename X> 

void Intercambiar(vector<X> &v, int i, int j){

	X aux = v[i];
	v[i] = v[j];
	v[j] = aux;

}

//// ÚLTIMO ELEMENTO ////
template <typename W> 

int Partition_ultimo_elemento(vector<W> &v, int ini, int fin){

	W x = v[fin];
	int i = ini;

	for (int j = ini; j < fin; j++){

		if (v[j] <= x){

			Intercambiar(v, i, j);
			i++;

		}

	}

	Intercambiar(v, i, fin);

	return i;

}

template <typename V> 

void QuickSort_ultimo_elemento(vector<V> &v, int ini, int fin){

	if (ini < fin){

		int pivot = Partition_ultimo_elemento(v, ini, fin);
		QuickSort_ultimo_elemento(v, ini, pivot - 1);
		QuickSort_ultimo_elemento(v, pivot + 1, fin);

	}

}

//// PRIMER ELEMENTO ////

template <typename Y> 

int Partition_primer_elemento(vector<Y> &v, int ini, int fin){

	Y x = v[ini];   
	int i = ini;    

	for (int j = ini + 1; j <= fin; j++){ 

		if (v[j] <= x){ 

			i++;
			Intercambiar(v, i, j); 

		}

	}

	Intercambiar(v, i, ini);

	return i;

}

template <typename Z> 

void QuickSort_primer_elemento(vector<Z> &v, int ini, int fin){

	if (ini < fin){

		int pivot = Partition_primer_elemento(v, ini, fin);
		QuickSort_primer_elemento(v, ini, pivot - 1);
		QuickSort_primer_elemento(v, pivot + 1, fin);

	}

}

	//// ELEMENTO CENTRAL ////

template <typename A> 

int Partition_elemento_central(vector<A> &v, int ini, int fin){

	int medio = (ini + fin) / 2;
	A x = v[medio];
	int i = ini;
	int j = fin;

	  	while (i <= j){

	      	while (v[i] < x){

	          	i++;

	      	}

	      	while (v[j] > x){

	          	j--;

	      	}

	    if (i <= j){

			Intercambiar(v, i, j);
	        i++;
	        j--;

	    }

	}

    return i;
}

template <typename B> 

void QuickSort_elemento_central(vector<B> &v, int ini, int fin){

	if (ini < fin){

		int pivot = Partition_elemento_central(v, ini, fin);
		QuickSort_elemento_central(v, ini, pivot - 1);
		QuickSort_elemento_central(v, pivot, fin);

	}

}

	//// ELEMENTO ALEATORIO ////

template <typename C> 

int Partition_elemento_aleatorio(vector<C> &v, int ini, int fin){

	srand(time(nullptr));

	C x = v[ini + rand() % (fin - ini + 1)];
	int i = ini;
	int j = fin;

	while (i < j){

        while (v[i] < x){
        
            i++;
        
        }
        
        while (v[j] > x){
        
            j--;
        
        }
        
        if (i < j){
        
			Intercambiar(v, i, j);
        
        }

    }

    return j;

}

template <typename D> 

void QuickSort_elemento_aleatorio(vector<D> &v, int ini, int fin){

	if (ini < fin){

		int pivot = Partition_elemento_aleatorio(v, ini, fin);
		QuickSort_elemento_aleatorio(v, ini, pivot - 1);
		QuickSort_elemento_aleatorio(v, pivot + 1, fin);

	}

}

#endif
