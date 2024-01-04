#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

/*------------------------------------------------------*/
//  INTERFAZ GENÉRICA BSTree<T>                         //
//  ·Representa los Árboles de Búsqueda Binarios        //
//  ·Esta almacenará un puntero al nodo raíz del árbol, //
//      de tipo BSNode<T>, así como un contador del     //
//      número de elementos almacenados en el árbol     //
/*------------------------------------------------------*/
template <typename T>
class BSTree {

    private:

        /////////////////////// ATRIBUTOS ////////////////////////

        /*------------------------------------------------------*/
        //  NELEM                                               //
        //  ·Número de elementos almacenados en el ABB          //
        /*------------------------------------------------------*/
        int nelem;

        /*------------------------------------------------------*/
        //  ROOT                                                //
        //  ·Nodo raíz del ABB                                  //
        /*------------------------------------------------------*/
        BSNode<T>* root;

        //////////////////////// MÉTODOS /////////////////////////

        /*--------------- Búsqueda de elementos ----------------*/

        /*------------------------------------------------------*/
        //  SEARCH( N, ELEM )                                   //
        //  ·Método recursivo para buscar elementos en el ABB   //
        //  ·Busca y devuelve el elemento e de tipo T si se     //
        //      encuentra en el (sub-)árbol cuya raíz es n      //
        //  ·De lo contrario lanza un runtime_error             //
        /*------------------------------------------------------*/
        BSNode<T>* search(BSNode<T>* n, T e) const;

        /*--------------- Inserción de elementos ---------------*/

        /*------------------------------------------------------*/
        //  INSERT( N, ELEM )                                   //
        //  ·Método recursivo para la inserción ordenada de     //
        //      elementos                                       //
        //  ·Inserta el elemento e de tipo T de manera ordenada //
        //      en el (sub-)árbol cuya raíz es n                //
        //  ·Devuelve el nodo que encabeza dicho (sub-)árbol    //
        //      modificado                                      //
        //  ·Si el elemento e ya existe, lanza un runtime_error //
        /*------------------------------------------------------*/
        BSNode<T>* insert(BSNode<T>* n, T e);

        /*---------- Recorrido e impresión del árbol -----------*/

        /*------------------------------------------------------*/
        //  PRINT_INORDER( OUT, N )                             //
        //  ·Recorrido inorden o simétrico del (sub-)árbol cuya //
        //      raíz es n pActúa como método lanzadera del método privado     //
        //      recursivo remove(BSNode<T>* n, T e)             //ara mostrar a través de out los      //
        //          elementos ordenados de menor a mayor        //
        /*------------------------------------------------------*/
        void print_inorder(ostream &out, BSNode<T> n) const;

        /*-------------- Eliminación de elementos --------------*/

        /*------------------------------------------------------*/
        //  REMOVE( N, ELEM )                                   //
        //  ·Método recursivo para la eliminación de elementos  //
        //  ·Elimina el elemento e del subárbol cuya raíz es n  //
        //  ·Devuelve el nodo que encabeza dicho (sub-)árbol    //
        //      modificado                                      //
        //  ·En caso de eliminar un nodo con dos sucesores      //
        //      (izquierdo y derecho), aplicará la politica de  //
        //      reemplazo por el elemento máximo del subárbol   //
        //      izquierdo                                       //
        //  ·Para ello, se apoyará en los métodos privados      //
        //      auxiliares max() y remove_max()                 //
        //  ·Si el elemento e no existe, lanza un runtime_error //
        /*------------------------------------------------------*/
        BSNode<T>* remove(BSNode<T>* n, T e);

        /*------------------------------------------------------*/
        //  MAX( N )                                            //
        //  ·Método recursivo que devuelve el elemento de       //
        //      máximo valor contenido en el (sub-)árbol cuya   //
        //      raíz es n                                       //
        /*------------------------------------------------------*/
        T max(BSNode<T>* n) const;

        /*------------------------------------------------------*/
        //  REMOVE_MAX( N )                                     //
        //  ·Método recursivo que elimina el elemento de        //
        //      máximo valor contenido en el (sub-)árbol cuya   //
        //      raíz es n                                       //
        /*------------------------------------------------------*/
        BSNode<T>* remove_max(BSNode<T>* n);

        /*--------------------- Destrucción --------------------*/

        /*------------------------------------------------------*/
        //  DELETE_CASCADE( N )                                 //
        //  ·Método recursivo para liberación de la memoria     //
        //      dinámica ocupada por los objetos de tipo        //
        //      BSNode<T> que conforman el (sub-)árbol cuya     //
        //      raíz es n                                       //
        /*------------------------------------------------------*/
        void delete_cascade(BSNode<T>* n);

    public:
.
        //////////////////////// MÉTODOS /////////////////////////

        /*----------------- Creación y tamaño ------------------*/

        /*------------------------------------------------------*/
        //  BSTree( VOID )                                      //
        //  ·Puntero al nodo sucesor derecho                    //
        /*------------------------------------------------------*/
        BSTree();

        /*------------------------------------------------------*/
        //  SIZE( VOID )                                        //
        //  ·Devuelve el número de elementos nelem del ABB      //
        /*------------------------------------------------------*/
        int size() const;

        /*--------------- Búsqueda de elementos ----------------*/

        /*------------------------------------------------------*/
        //  SEARCH( ELEM )                                      //
        //  ·Busca y devuelve el elemento e de tipo T en el ABB //
        //  ·Actúa como método lanzadera del método privado     //
        //      recursivo search(BSNode<T>* n, T e)             //
        //  ·Notar que deberá devolver el elemento contenido    //
        //      por el nodo devuelto por el método privado      //
        /*------------------------------------------------------*/
        T search(T e) const;

        /*------------------------------------------------------*/
        //  OPERATOR [] ( ELEM )                                //
        //  ·Sobrecarga del operador[] que actúa como interfaz  //
        //      al método search(T e)                           //
        /*------------------------------------------------------*/
        T operator[](T e) const;

        /*--------------- Inserción de elementos ---------------*/

        /*------------------------------------------------------*/
        //  INSERT( ELEM )                                      //
        //  ·Inserta el elemento e de tipo T de manera ordenada //
        //      en el ABB.                                      //
        //  ·Actúa como método lanzadera del método privado     //
        //      recursivo insert(BSNode<T>* n, T e)             //
        /*------------------------------------------------------*/
        void insert(T e);

        /*---------- Recorrido e impresión del árbol -----------*/

        /*------------------------------------------------------*/
        //  OPERATOR << ( OUT, BSTREE )                         //
        //  ·Sobrecarga del operador << para mostrar a través   //
        //      de out los contenidos del ABB bst, realizando   //
        //      un recorrido inorden o simétrico del árbol para //
        //      mostrar los elementos ordenados de menor a mayor//
        //  ·Delega en el método privado recursivo              //
        //      print_inorder()                                 //
        /*------------------------------------------------------*/
        friend ostream& operator<<(ostream &out, const BSTree<T> &bst);

        /*-------------- Eliminación de elementos --------------*/

        /*------------------------------------------------------*/
        //  REMOVE( ELEM )                                      //
        //  ·Elimina el elemento e de tipo T del ABB            //
        //  ·Actúa como método lanzadera del método privado     //
        //      recursivo remove(BSNode<T>* n, T e)             //
        /*------------------------------------------------------*/
        void remove(T e);

        /*--------------------- Destrucción --------------------*/

        /*------------------------------------------------------*/
        //  ~BSTREE( VOID )                                     //
        //  ·Método destructor                                  //
        //  ·Delega en el método privado recursivo              //
        //      delete_cascade()                                //
        /*------------------------------------------------------*/
        ~BSTree();

};

#endif
