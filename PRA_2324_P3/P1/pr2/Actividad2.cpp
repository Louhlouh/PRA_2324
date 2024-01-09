#include <iostream>
#include <unordered_map>
#include <string>

#define TRUE 1
#define FALSE 0

using namespace std;

/* EXPLICACIÓN UNORDERED_MAP

template < class Key, 
	class Ty,
	clash Hash = hash<Key>,
	class Pred = equal_to<Key>,
	class Alloc = allocator<pair<const Key, Ty>> >
class unordered_map;

FUNCIONES DE UNORDERED_MAP
	at(key) : Busca un elemento con la clave especificada
	bucket(key) : Obtiene el número de depósito para un valor de clave
	bucket_count() : Obtiene el número de depósitos
	bucket_size() : Obtiene el tamaño de un depósito
	count(key) : Busca el número de elementos que coinciden con una clave especificada
	empty() : Comprueba si el Diccionario está vacío
	find(key) : Busca un elemento que coincide con la clave
		Devuelve un objeto unordered_map<string, int>::iterador 
		Contendrá en ->first la clave y en ->second el valor si se encuentra en la tabla
		Si no se ha encontrado, devuelve el valor ht.end()
	insert(element) : Inserta un nuevo elemento
	load_factor() : Calcula el factor de carga
	max_load_factor() : Calcula el factor de carga máximo
	size() : Cuenta el número de elementos
	begin(num_bucket) y end(num_buckets) : Iteración del numero de buckets. 
		Devuelven un unordered_map<string, int>::local_iterator al primer y ultimo elemento que haya en el bucket num_bucket. 
		Tienen la componente clave en ->first y valor en ->second
	erase(key) :  Devuelve un int con el número de elementos eliminados (0 o 1)

CREACIÓN DE UNORDERED_MAP: unordered_map<string, int> name;
INSERTAR ELEMENTOS : 	name.insert({"One", 1})   o   name["Two"] = 2;
IMPRIMIR VALORES : 	cout << "\n\nPrinting unordered_map..." << endl;
			for( unordered_map<string, int>::iterator itr = name.begin(); itr != name.end(); itr++){
				cout << " " << itr->first << ":" << itr->second << endl;
			}
*/

//PASO 1
void print_ht(unordered_map<string, int> &ht){
	
	int bucket_count = ht.bucket_count();

	cout << "	----- HASH TABLE -----" << endl;
	cout << "	Num. buckets: " << bucket_count << endl;
	cout << "	Num. elements: " << ht.size() << endl;
	cout << "	Max. load factor: " << ht.max_load_factor() << endl;
	cout << "	Current load factor: " << ht.load_factor() << endl;
	cout << endl;
	
	for( int i = 0; i < bucket_count; i++ ){
		cout << "	BUCKET " << i << ":";
		for ( unordered_map<string, int>::local_iterator itr = ht.begin(i); itr != ht.end(i); itr++ ){
				cout << " [" << itr->first << " : " << itr->second << "]	";
		}
		cout << endl << endl;
	}
}

//PASO 2
bool insert_in_ht(unordered_map<string, int> &ht, string key, int val){ //insert({key, val}).second
	
	bool inserted = ht.insert({key, val}).second;
	cout << "	-> K(" << key << ":" << val << ") ";

	if(inserted){
		cout << "inserted in bucket " << ht.bucket(key) << "!";
	}
	else{
		cout << "NOT INSERTED! KEY " << key << " already in hash table...";	
	}
	
	cout << endl << endl;
	return inserted;
}

//PASO 3
unordered_map<string, int>::iterator search_in_ht(unordered_map<string, int> &ht, string key){

	unordered_map<string, int>::iterator searched = ht.find(key);
	cout << "	-> Key " << key;
	
	if( searched == ht.end() ){
		cout << " NOT FOUND in hash...";
	}
	else{
		cout << " FOUND in hash: ";
		cout << "[" << searched->first << ":" << searched->second << "], ";
		cout << "bucket " << ht.bucket(key);
	}
	
	cout << endl << endl;
	return searched;
}

//PASO 4
bool delete_in_ht(unordered_map<string, int> &ht, string key){

	int removed = ht.erase(key);
	cout << "	-> Key " << key;
	
	if( removed == 0 ){
		cout << " NOT FOUND in hash and CAN'T be removed";
	}
	else{
		cout << " FOUND in hash and REMOVED ";
	}
	
	cout << endl << endl;
	return removed;
	
	
}

//PASO 5
#define SIZE 50

int main(){

	unordered_map<string, int> ht;
	//unordered_map<string, int> ht(SIZE);
	
	///// INSERT /////
	print_ht(ht);
	insert_in_ht(ht, "One", 1);
	insert_in_ht(ht, "Two", 2);
	insert_in_ht(ht, "Three", 3);
	insert_in_ht(ht, "Four", 4);
	insert_in_ht(ht, "One", 56);
	print_ht(ht);
	cout << endl;
	
	///// SEARCH /////
	search_in_ht(ht, "One");
	search_in_ht(ht, "Two");
	search_in_ht(ht, "Three");
	search_in_ht(ht, "Four");
	search_in_ht(ht, "Five");
	cout << endl;
	
	///// DELETE /////
	delete_in_ht(ht, "One");
	delete_in_ht(ht, "Two");
	delete_in_ht(ht, "Three");
	delete_in_ht(ht, "Four");
	delete_in_ht(ht, "Five");
	cout << endl;
	
	///// REHASH /////
	/*ht.rehash(SIZE);
	print_ht(ht);
	cout << endl;*/
	
	return 0;
}


