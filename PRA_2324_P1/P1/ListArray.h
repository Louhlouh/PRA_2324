#include "List.h"
#include <ostream>
#include <exception>

using namespace std;


template <typename T> 
class ListArray : public List<T> {

    private:

        T* arr;
        //puntero al inicio del array que almacenará los elementos (de tipo T) de la lista de forma contigua

        int max;
        //tamaño actual del array que podrá alterarse en caso necesario mediante el método resize(int)

        int n;
        //número de elementos que contiene la lista

        static const int MINSIZE = 2;
        //tamaño mínimo del array

        /*
            ESTRATEGIA DE USO DE RESIZE:
            1.Crear un nuevo array dinámico de new_size elementos con operador new (T *aux = new T[new_size])
            2.Copiar el contenido del array actual (arr) en el nuevo array (aux[j] = arr[i])
            3.Liberar los recursos de memoria que ocupa arr con el operador delete[] (~ListArray)
            4.Actualizar el puntero arr para que apunte a la dirección de memoria en la que se encuentra el nuevo array (arr = aux)
            5.Actualizar max (resize(new_size) --> max = new_size)
        */
        void resize(int new_size)
        {
        //método privado que se encargará de redimensionar el array al tamaño especificado
        //tiene como objetivo incrementar o reducir la capacidad del array (si está lleno o "vacío")
        //puede ser invocado por insert(), append(), prepend() y remove()

            T* aux = new T[new_size];

            for ( int i = 0; i < size(); i++ ){

                aux[i] = arr[i];

            }

            delete[] arr; //elimina arr
            arr = aux;  //arr toma el valor de aux
            max = new_size; 

        }

    public:
        
        ListArray()
        {
        //método constructor sin argumentos
        //se encarga de reservar la memoria dinámica para crear un array de MINSIZE elementos tipo T
        //además, inicializa el resto de atributos de la instancia

            arr = new T[0];
            max = 0;
            n = 0;

        }

        ~ListArray()
        {
        //método destructor que se encarga de liberar la memoria dinámica reservada

            delete arr;

        }
        
        T operator[](int pos)
        {
        //sobrecarga del operador []
        //devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size() - 1]) 

            if ( pos < 0 || pos >= size() ){

                throw out_of_range("Posición fuera de rango");

            }

            return arr[pos];

        }
        
        friend ostream&operator<<(ostream &out, const ListArray<T> &list)
        {
        //sobrecarga del operador << 
        //imprime una instancia de ListArray<T> por pantalla

            out << "ListArray = [";

            if( list.max > 0 ){

                for (int i = 0; i < list.max; i++){

                    out << list.arr[i];

                    if (i != list.max - 1){

                        out << ", ";

                    }

                }

            }
            
            out << "]" << endl;

            return out;
        }
        
        //CLASES DE LIST.H

        void insert(int pos, T e) override //uso de resize, append (pos = size() - 1) y prepend (pos = 0)
        {  
        //inserta el elemento e en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size()])  

            if ( pos < 0 || pos > size() ){

                throw out_of_range("Posición fuera de rango");

            }

            if (pos == 0){ prepend(e); }

                else if (pos == size()){ append(e); }

                else{

                    n++;

                    resize(n);

                    if ( pos < n ){

                        for ( int i = 0; i < n - pos; i++){

                            arr[n - i] = arr[n - 1 - i];

                        }

                    }

                    arr[pos] = e;

                }  

        }

        void append(T e) override //uso de resize
        { 
        //inserta el elemento e al final de la lista

            n++;

            resize(n);

            arr[size() - 1] = e;

        }

        void prepend(T e) override //uso de resize
        {
        //inserta el elemento e al principio de la lista

            n++;

            resize(n);

            for ( int i = size() - 1; i > 0; i--){

                arr[i] = arr[i - 1]; 

            } 

            arr[0] = e;
        }

        T remove(int pos) override //uso de resize
        { 
        //elimina y devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size() - 1])  
        
            if ( pos < 0 || pos > size() - 1 ){

                throw out_of_range("Posición fuera de rango");

            }

            int removed = arr[pos];

            if (pos < n){

                for( int i = pos; i < n; i++ ){

                    arr[i] = arr[i + 1];

                }

            }

            n--;
            resize(n);

            return removed;
       
        }

        T get(int pos) override
        { 
        //devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size() - 1])

            if ( pos < 0 || pos >= size() ){

                throw out_of_range("Posición fuera de rango");

            }

            return arr[pos];

        }

        int search(T e) override
        { 
        //devuelve la posición en la que se encuentra la primera ocurrencia del elemento e o -1 si no se encuentra

            for ( int i = 0; i < size(); i++){

                if ( arr[i] == e ){    

                    return i;

                }    

            }

            return -1;

        }

        bool empty() override
        { 
        //indica si la lista está vacía

            return ( ( n == 0 ) ? true : false );

        }

        int size() override
        { 
        //devuelve el número de elementos de la lista

            return n;

        }

};
