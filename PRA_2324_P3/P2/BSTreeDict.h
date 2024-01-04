#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "../P1/Dict.h"
#include "BSTree.h"
#include "../P1/TableEntry.h"

using namespace std;

/*------------------------------------------------------*/
//  INTERFAZ GENÉRICA BSTreeDict<T>                     //
//  ·Expecie de proxy entre la interfaz Dict<V> y la    //
//      la clase BSTree<T>                              //
//  ·Esta soportará la gestión de los elementos del     //
//      diccionario                                     //
/*------------------------------------------------------*/
template <typename V>
class BSTreeDict: public Dict<V>{

    private:

        /////////////////////// ATRIBUTOS ////////////////////////

        /*------------------------------------------------------*/
        //  TREE                                                //
        //  ·ABB con elementos de tipo TableEntry<V> para       //
        //      gestionar los elementos de un diccionario       //
        /*------------------------------------------------------*/
        BSTree< TableEntry<V> >* tree;


    public:

        //////////////////// MÉTODOS PROPIOS /////////////////////

        /*------------------------------------------------------*/
        //  BSTREEDICT( VOID )                                  //
        //  ·Constructor                                        //
        //  ·Crea un ABB vacío con memoria dinámica             //
        /*------------------------------------------------------*/
        BSTreeDict(){
            
            tree = new BSTree< TableEntry<V> >;
        }

        /*------------------------------------------------------*/
        //  ~BSTREEDICT( VOID )                                 //
        //  ·Destructor                                         //
        //  ·Se encargará de liberar la memoria dinámica        //
        //      ocupada por el ABB tree                         //
        /*------------------------------------------------------*/
        ~BSTreeDict(){

            delete tree;
        }

        /*------------------------------------------------------*/
        //  OPERADOR << ( OUT, BS )                             //
        //  ·Sobrecarga global del operador << para imprimir el //
        //      contenido del Diccionario por pantalla          //
        /*------------------------------------------------------*/
        friend ostream& operator<<(ostream &out, const BSTreeDict<V> &bs){

            out << *bs.tree << endl;

            return out;
        }

        /*------------------------------------------------------*/
        //  OPERADOR [] ( KEY )                                 //
        //  ·Sobrecarga del operador[]                          //
        //  ·Actúa como interfaz al método de interfaz heredado //
        //      search(std::string key)                         //
        /*------------------------------------------------------*/
        V operator[](string key){

            return search(key);
        }


        ////////////////////// MÉTODOS DICT //////////////////////

        /*------------------------------------------------------*/
        //  INSERT( KEY , VALUE )                               //
        //  ·Inserta el par key->value en el diccionario        //
        //  -Lanza una excepción runtime_error si key ya existe //
        //      en el diccionario                               //
        /*------------------------------------------------------*/
        void insert(string key, V value) override{

            TableEntry<V> aux(key, value);
            tree->insert(aux);
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

            TableEntry<V> aux(key);
            return tree->search(aux).value;
        }


        /*------------------------------------------------------*/
        //  REMOVE( KEY )                                       //
        //  ·Elimina el par key->value si se encuentra en el    //
        //      diccionario                                     //
        //  -Lanza una excepción runtime_error si key no se     //
        //      encuentra en el diccionario                     //
        /*------------------------------------------------------*/
        V remove(string key) override{

            TableEntry<V> aux(key);
            V removed = tree->search(aux).value;
            tree->remove(aux);

            return removed;
        }


        /*------------------------------------------------------*/
        //  ENTRIES( VOID )                                     //
        //  ·Devuelve el número de elementos que tiene el       //
        //      diccionario                                     //
        /*------------------------------------------------------*/
        int entries() override{

            return tree->size();
        }
};

#endif