#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../PRA_2324_P1/ListLinked.h"  

using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:

        /////////////////////// ATRIBUTOS ////////////////////////
        /*------------------------------------------------------*/
        //  N                                                   //
        //  ·Número de elementos almacenados actualmente en la  //
        //      tabla hash                                      //
        /*------------------------------------------------------*/
        int n;


        /*------------------------------------------------------*/
        //  MAX                                                 //
        //  ·Tamaño de la tabla hash (nº total de cubetas)      //
        /*------------------------------------------------------*/
        int max;


        /*------------------------------------------------------*/
        //  TABLE                                               //
        //  ·Tabla de cubetas                                   //
        //  -Representadas por un array de punteros a listas    //
        //      enlazadas (tipo ListLinked<T>) que almacenan    //
        //      pares clave->valor (tipo TableEntry<V>)         //
        /*------------------------------------------------------*/
        ListLinked<TableEntry<V>>* table;


        ///////////////////// CLASES PROPIAS /////////////////////
        /*------------------------------------------------------*/
        //  H( KEY )                                            //
        //  ·Función hash que devuelve la posición (cubeta) en  //
        //      la tabla hash de key                            //
        //  -Se calculará como el resto de la división entre la //
        //      suma de los valores ASCII numéricos de los      //
        //      caracteres de la clave y el tamaño de la tabla  //
        //      hash                                            //
        //  *El método at(i) de string permite obtener el       //
        //      carácter situado en la posición i de un string  //
        //  *La función int(c) permite obtener el valor ASCII   //
        //      numérico del carácter c                         //
        /*------------------------------------------------------*/
        int h(string key){

            int sumaASCII = 0;

            for( int i = 0; i < key.size(); i++ ){

                sumaASCII += int(key.at(i));
            }

            return ( sumaASCII % capacity() );
        }


    public:

        ///////////////////// CLASES PROPIAS /////////////////////
        /*------------------------------------------------------*/
        //  HASHTABLE( SIZE )                                   //
        //  ·Método constructor                                 //
        //  -Reservará memoria dinámica para crear una tabla    //
        //      "table" de tamaño size                          //
        //  -Inicializará los atributos n y max de la clase     //
        /*------------------------------------------------------*/
        HashTable(int size){

            this->table = new ListLinked<TableEntry<V>>[size];
            this->n = 0;
            this->max = size;
        }


        /*------------------------------------------------------*/
        //  ~HASHTABLE( VOID )                                  //
        //  ·Método destructor                                  //
        //  -Se encargará de liberar la memoria dinámica        //
        //      reservada al crear la tabla "table"             //
        /*------------------------------------------------------*/
        ~HashTable(){

            delete[] table;
        }


        /*------------------------------------------------------*/
        //  CAPACITY( VOID )                                    //
        //  ·Devuelve el número total de cubetas de la tabla    //
        /*------------------------------------------------------*/
        int capacity(){

            return max;
        }


        /*------------------------------------------------------*/
        //  OPERATOR <<                                         //
        //  ·Sobrecarga global del operador << para imprimir el //
        //      contenido de la tabla hash por pantalla         //
        /*------------------------------------------------------*/
        friend ostream& operator<<(ostream &out, const HashTable<V> &th){

            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << endl;
            out << "==============" << endl << endl;

            for( int i = 0; i < th.max; i++ ){

                out << "== Cubeta " << i << " ==" << endl << endl;
                out << th.table[i] << endl << endl;
            }

            out << "==============" << endl << endl;
            return out;
        }

        /*------------------------------------------------------*/
        //  OPERATOR []( KEY )                                  //
        //  ·Sobrecarga del operador []                         //
        //  ·Devuelve el valor correspondiente a key            //
        //  -Si no existe, lanza la excepción runtime_error     //
        /*------------------------------------------------------*/
        V operator[](string key){

            return search(key);
        }


        /////////////////////// CLASES DICT //////////////////////
        /*------------------------------------------------------*/
        //  INSERT( KEY , VALUE )                               //
        //  ·Inserta el par key->value en el diccionario        //
        //  -Lanza una excepción runtime_error si key ya existe //
        //      en el diccionario                               //
        /*------------------------------------------------------*/
        void insert(string key, V value) override{

            int pos = h(key);
            TableEntry<V> aux(key, value);

            if( table[pos].search(aux) == -1){

                table[pos].insert(table[pos].size(), aux);
                n++;
            }

            else{

                throw runtime_error("Key '" + key + "' already exists!");
            }
        }


        /*------------------------------------------------------*/
        //  SEARCH( KEY )                                       //
        //  ·Busca el valor correspondiente a key               //
        //  ·Devuelve el valor value asociado si key está       //
        //      en el diccionario                               //
        //  -Lanza una excepción runtime_error si key no se     //
        //      encuentra en el diccionario                     //
        /*------------------------------------------------------*/
        V search(string key) override{

            int pos = h(key);
            TableEntry<V> aux(key);
            int listPos = table[pos].search(aux);

            if( listPos == -1 ){

                throw runtime_error("Key '" + key + "' not found!");
            }

            else{

                return table[pos].get(listPos).value;
            }
        }


        /*------------------------------------------------------*/
        //  REMOVE( KEY )                                       //
        //  ·Elimina el par key->value si se encuentra en el    //
        //      diccionario                                     //
        //  -Lanza una excepción runtime_error si key no se     //
        //      encuentra en el diccionario                     //
        /*------------------------------------------------------*/
        V remove(string key) override{

            int pos = h(key);
            TableEntry<V> aux(key);
            int listPos = table[pos].search(aux);

            if( listPos == -1){

                throw runtime_error("Key '" + key + "' not found!");
            }

            else{

                n--;
                return table[pos].remove(listPos).value;
            }
        }


        /*------------------------------------------------------*/
        //  ENTRIES( VOID )                                     //
        //  ·Devuelve el número de elementos que tiene el       //
        //      diccionario                                     //
        /*------------------------------------------------------*/
        int entries() override{

            return n;
        }
};

#endif
