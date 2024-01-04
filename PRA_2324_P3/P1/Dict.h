#ifndef DICT_H
#define DICT_H
#include <string>

using namespace std;

/*------------------------------------------------------*/
//  INTERFAZ GENÉRICA DICT<V>                           //
//  ·Determina de qué manera se puede gestionar un      //
//      Diccionario de pares clave->valor               //
//  -La clave será de tipo string y el valor de tipo    //
//      V cualquiera.                                   //
//  ·Dict<V> será una clase abstracta, pura y genérica  //
//  ·Implementación en el HashTable<V>                  //
/*------------------------------------------------------*/
template <typename V>
class Dict {
    public:

        /*------------------------------------------------------*/
        //  INSERT( KEY , VALUE )                               //
        //  ·Inserta el par key->value en el diccionario        //
        //  -Lanza una excepción runtime_error si key ya existe //
        //      en el diccionario                               //
        /*------------------------------------------------------*/
        virtual void insert(string key, V value) = 0;


        /*------------------------------------------------------*/
        //  SEARCH( KEY )                                       //
        //  ·Busca el valor correspondiente a key               //
        //  ·Devuelve el valor value asociado si key está       //
        //      en el diccionario                               //
        //  -Lanza una excepción runtime_error si key no se     //
        //      encuentra en el diccionario                     //
        /*------------------------------------------------------*/
        virtual V search(string key) = 0;


        /*------------------------------------------------------*/
        //  REMOVE( KEY )                                       //
        //  ·Elimina el par key->value si se encuentra en el    //
        //      diccionario                                     //
        //  -Lanza una excepción runtime_error si key no se     //
        //      encuentra en el diccionario                     //
        /*------------------------------------------------------*/
        virtual V remove(string key) = 0;


        /*------------------------------------------------------*/
        //  ENTRIES( VOID )                                     //
        //  ·Devuelve el número de elementos que tiene el       //
        //      diccionario                                     //
        /*------------------------------------------------------*/
        virtual int entries() = 0;

};

#endif
