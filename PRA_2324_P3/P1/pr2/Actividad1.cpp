#include <iostream>

using namespace std;

/* EXPLICACIÓN GENÉRICA

template <class h>
struct hash{ //definición de la clase hash
	size_t operator()(h val)const;
};
---- clase definida en la librería de c++ ----
template <typename T> 

hash<T> T_hash; //función hash operador que obtiene valores hash de tipo T 

int hash_val = T_hash(val_T); //utilización de la función T_hash mediante operador () definido en la clase
*/


#define RAND_SIZE 69

class val{	
	public:
		int i;
		float f;
		
		val(int i, float f){
			this->i = i;
			this->f = f;
		}
};

template <>
struct std::hash<val>{ //definición de la clase hash que obtiene el valor hash sumando los valores hash de sus dos atributos (a y b) 
	size_t operator()(const val& x)const{
		hash<int> int_hash;
		hash<float> float_hash;
		return int_hash(x.i) + float_hash(x.f);
	}
};



int main(){
	/*-------------INICIALIZAR VARIABLES-------------*/

	// ACTIVIDAD 1A //
	int i = 5;
	char c = 'e';
	float f = 5.5;
	double d = 5.55;
	string s = "eee";
	
	// ACTIVIDAD 1B //
	val x = val(1, 0.1);
	
	/*------CREAR Y CALCULAR ÍNDICE TABLAS HASH------*/	
	
	// ACTIVIDAD 1A //
	hash<int> int_hash; 
	size_t hash_val_int = int_hash(i);
	
	hash<char> char_hash; 
	size_t hash_val_char = char_hash(c);
	
	hash<float> float_hash; 
	size_t hash_val_float = float_hash(f);
	
	hash<double> double_hash; 
	size_t hash_val_double = double_hash(d);
	
	hash<string> string_hash; 
	size_t hash_val_string = string_hash(s);
	
	// ACTIVIDAD 1B // 
	hash<val> x_hash;
	size_t hash_val_x = x_hash(x); 
	
	/*-------------IMPRIMIR POR PANTALLA-------------*/ 
	
	// ACTIVIDAD 1A // 	
	cout << "Hash value for " << i << ": " << hash_val_int << " [Hash index: " << (hash_val_int % RAND_SIZE) << "]" << endl;
	cout << "Hash value for " << c << ": " << hash_val_char << " [Hash index: " << (hash_val_char % RAND_SIZE) << "]" << endl;
	cout << "Hash value for " << f << ": " << hash_val_float << " [Hash index: " << (hash_val_float % RAND_SIZE) << "]" << endl;
	cout << "Hash value for " << d << ": " << hash_val_double << " [Hash index: " << (hash_val_double % RAND_SIZE) << "]" << endl;
	cout << "Hash value for " << s << ": " << hash_val_string << " [Hash index: " << (hash_val_string % RAND_SIZE) << "]" << endl;
	
	// ACTIVIDAD 1B // 
	cout << "Hash value for [1, 0.1]: " << hash_val_x << " [Hash index: " << (hash_val_x % RAND_SIZE) << "]" << endl;
	
	return 0;
}
