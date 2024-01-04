#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

using namespace std;

/*------------------------------------------------------*/
//  CLASE TABLEENTRY<V>                                 //
//  ·Los pares clave->valor se representan mediante     //
//      una clase genérica TableEntry<V> con tipo       //
//      string para las claves y tipo V paramétrico V   //
//      para los valores                                //
/*------------------------------------------------------*/
template <typename V> 
class TableEntry {
    public:

        /////////////////////// ATRIBUTOS ////////////////////////
        /*------------------------------------------------------*/
        //  KEY                                                 //
        //  ·Elemento clave del par                             //
        /*------------------------------------------------------*/
        string key;


        /*------------------------------------------------------*/
        //  VALUE                                               //
        //  ·Elemento valor del par                             //
        /*------------------------------------------------------*/
        V value;


        ///////////////////// CLASES PROPIAS /////////////////////
        /*------------------------------------------------------*/
        //  TABLEENTRY( KEY , VALUE )                           //
        //  ·Método constructor con el par clave->valor         //
        /*------------------------------------------------------*/
        TableEntry(string key, V value){

            this->key = key;
            this->value = value;
        }


        /*------------------------------------------------------*/
        //  TABLEENTRY( KEY )                                   //
        //  ·Crea una entrada solo con la clave (sin valor)     //
        /*------------------------------------------------------*/
        TableEntry(string key){

            this->key = key;
            //this->value = NULL;
        }


        /*------------------------------------------------------*/
        //  TABLEENTRY( VOID )                                  //
        //  ·Crea una entrada con la clave "" (cadena vacía)    //
        //      y sin valor.                                    //
        /*------------------------------------------------------*/
        TableEntry(){

            this->key = "";
            //this->value = NULL;
        }


        /*------------------------------------------------------*/
        //  BOOL OPERATOR ==                                    //
        //  ·Sobrecarga global del operador == para determinar  //
        //      que dos instancias de TableEntry son iguales    //
        //      solo si comparten la misma clave (con           //
        //      independencia del valor)                        //
        /*------------------------------------------------------*/
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){

            return ( (te1.key.compare(te2.key) == 0) ? 1 : 0 );
        }


        /*------------------------------------------------------*/
        //  BOOL OPERATOR !=                                    //
        //  ·Sobrecarga global del operador != para determinar  //
        //      que dos instancias de TableEntry son diferentes //
        //      solo si sus claves son distintas (con           //
        //      independencia del valor)                        //
        /*------------------------------------------------------*/
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){

            return ( (te1.key.compare(te2.key) != 0) ? 1 : 0 );
        }


        /*------------------------------------------------------*/
        //  OPERATOR <<                                         //
        //  ·Sobrecarga global del operador << para imprimir el //
        //      contenido de la entrada (par clave->valor) por  //
        //          pantalla                                    //
        /*------------------------------------------------------*/
        friend ostream& operator<<(ostream &out, const TableEntry<V> &te){

            out << "('" << te.key << "' => " << te.value << ")";
            return out;
        }

};

#endif
