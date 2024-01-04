#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

using namespace std;

/*------------------------------------------------------*/
//  INTERFAZ BSNode<T>                                  //
//  ·La representación de los nodos de un Árbol Binario //
//      de Búsqueda es una estructura ternaria en que   //
//      se guarda el elemento y dos punteros,uno al     //
//      sucesor (sub-árbol) izquierdo y otro al derecho //
/*------------------------------------------------------*/
template <typename T>
class BSNode {

    public:

        /////////////////////// ATRIBUTOS ////////////////////////

        /*------------------------------------------------------*/
        //  ELEM                                                //
        //  ·Elemento de tipo T almacenado en el nodos          //
        /*------------------------------------------------------*/
        T elem;

        /*------------------------------------------------------*/
        //  LEFT                                                //
        //  ·Puntero al nodo sucesor izquierdo                  //
        /*------------------------------------------------------*/
        BSNode<T>* left;

        /*------------------------------------------------------*/
        //  RIGHT                                               //
        //  ·Puntero al nodo sucesor derecho                    //
        /*------------------------------------------------------*/
        BSNode<T>* right;

        //////////////////////// MÉTODOS /////////////////////////

        /*------------------------------------------------------*/
        //  BSNODE ( ELEM, LEFT, RIGHT )                        //
        //  ·Método constructor que crea un BSNode con el       //
        //      elemento elem y los punteros a los nodos        //
        //      sucesores left y  right proporcionados (nulos   //
        //      por defecto)                                    //
        /*------------------------------------------------------*/
        BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr){

            this->elem = elem;
            this->left = left;
            this->right = right;

        }


        /*------------------------------------------------------*/
        //  OPERATOR << ( OUT, BSNODE )                         //
        //  ·Sobrecarga global del operador << para imprimir el //
        //      nodo por pantalla. Por simplicidad, puedes      //
        //      limitarte a imprimir el atributo elem           //
        /*------------------------------------------------------*/
        friend ostream& operator<<(ostream &out, const BSNode<T> &bsn){

            out << bsn.elem;

            return out;

        }

};

#endif
