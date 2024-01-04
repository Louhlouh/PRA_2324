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
        BSNode<T>* search(BSNode<T>* n, T e) const{

            if (n == nullptr){ // condición base del método recursivo
                throw runtime_error("Element not found!");
            }

            else if ( n->elem < e ){ return search(n->right, e); }
            else if ( n->elem > e ){ return search(n->left, e); }

            else{ return n; } // n->elem == e
        }


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
        BSNode<T>* insert(BSNode<T>* n, T e){

            if (n == nullptr){ // condición base del método recursivo
                throw runtime_error("Element not found!");
            }

            else if ( n->elem == e ){ throw runtime_error("Duplicated element!"); }
            else if ( n->elem < e ){ n->right = insert(n->right, e); }
            else{ n->left = insert(n->left, e); }

            return n; 
        }


        /*---------- Recorrido e impresión del árbol -----------*/

        /*------------------------------------------------------*/
        //  PRINT_INORDER( OUT, N )                             //
        //  ·Recorrido inorden o simétrico del (sub-)árbol cuya //
        //      raíz es n para mostrar a través de out los      //
        //          elementos ordenados de menor a mayor        //
        /*------------------------------------------------------*/
        void print_inorder(ostream &out, BSNode<T>* n) const{

            if ( n != nullptr ){

                print_inorder(out, n->left);
                out << n->elem << " ";
                print_inorder(out, n->right);
            }
        }


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
        BSNode<T>* remove(BSNode<T>* n, T e){

            if ( n == nullptr ){ // condición base del método recursivo
                throw runtime_error("Element not found!");
            }

            else if ( n->elem < e ){ n->right = remove(n->right, e); }
            else if ( n->elem > e ){ n->left = remove(n->left, e); }
            else{

                if (( n->left != nullptr ) && (n->right != nullptr)){ //2 sucesores

                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                }

                else{ n = ( n->left != nullptr ) ? n->left : n->right; } //1 o 0 sucesores
            }

            return n;
        }

        /*------------------------------------------------------*/
        //  MAX( N )                                            //
        //  ·Método recursivo que devuelve el elemento de       //
        //      máximo valor contenido en el (sub-)árbol cuya   //
        //      raíz es n                                       //
        /*------------------------------------------------------*/
        T max(BSNode<T>* n) const{

            if ( n->right != nullptr ){ return max(n->right); }

            else{ return n->elem; }
        }

        /*------------------------------------------------------*/
        //  REMOVE_MAX( N )                                     //
        //  ·Método recursivo que elimina el elemento de        //
        //      máximo valor contenido en el (sub-)árbol cuya   //
        //      raíz es n                                       //
        /*------------------------------------------------------*/
        BSNode<T>* remove_max(BSNode<T>* n){

            if ( n->right == nullptr ){ //caso base

                BSNode<T>* removed = n->left;
                delete n;
                return removed;
            }

            else{

                n->right = remove_max(n->right); 
                return n;
            }
        }


        /*--------------------- Destrucción --------------------*/

        /*------------------------------------------------------*/
        //  DELETE_CASCADE( N )                                 //
        //  ·Método recursivo para liberación de la memoria     //
        //      dinámica ocupada por los objetos de tipo        //
        //      BSNode<T> que conforman el (sub-)árbol cuya     //
        //      raíz es n                                       //
        /*------------------------------------------------------*/
        void delete_cascade(BSNode<T>* n){

            if ( n != nullptr ){

                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }

    public:

        //////////////////////// MÉTODOS /////////////////////////

        /*----------------- Creación y tamaño ------------------*/

        /*------------------------------------------------------*/
        //  BSTree( VOID )                                      //
        //  ·Método constructor que crea un ABB vacío           //
        /*------------------------------------------------------*/
        BSTree(){

            this->nelem = 0; //no hay elementos
            this->root = nullptr;
        }

        /*------------------------------------------------------*/
        //  SIZE( VOID )                                        //
        //  ·Devuelve el número de elementos nelem del ABB      //
        /*------------------------------------------------------*/
        int size() const{

            return nelem;
        }


        /*--------------- Búsqueda de elementos ----------------*/

        /*------------------------------------------------------*/
        //  SEARCH( ELEM )                                      //
        //  ·Busca y devuelve el elemento e de tipo T en el ABB //
        //  ·Actúa como método lanzadera del método privado     //
        //      recursivo search(BSNode<T>* n, T e)             //
        //  ·Notar que deberá devolver el elemento contenido    //
        //      por el nodo devuelto por el método privado      //
        /*------------------------------------------------------*/
        T search(T e) const{

            return ( search(root, e)->elem );
        }

        /*------------------------------------------------------*/
        //  OPERATOR [] ( ELEM )                                //
        //  ·Sobrecarga del operador[] que actúa como interfaz  //
        //      al método search(T e)                           //
        /*------------------------------------------------------*/
        T operator[](T e) const{

            return search(e);
        }


        /*--------------- Inserción de elementos ---------------*/

        /*------------------------------------------------------*/
        //  INSERT( ELEM )                                      //
        //  ·Inserta el elemento e de tipo T de manera ordenada //
        //      en el ABB.                                      //
        //  ·Actúa como método lanzadera del método privado     //
        //      recursivo insert(BSNode<T>* n, T e)             //
        /*------------------------------------------------------*/
        void insert(T e){

            root = insert(root, e);
            nelem++;
        }


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
        friend ostream& operator<<(ostream &out, const BSTree<T> &bst){

            bst.print_inorder(out, bst.root);
            return out;
        }


        /*-------------- Eliminación de elementos --------------*/

        /*------------------------------------------------------*/
        //  REMOVE( ELEM )                                      //
        //  ·Elimina el elemento e de tipo T del ABB            //
        //  ·Actúa como método lanzadera del método privado     //
        //      recursivo remove(BSNode<T>* n, T e)             //
        /*------------------------------------------------------*/
        void remove(T e){

            root = remove(root, e);
            nelem--;
        }


        /*--------------------- Destrucción --------------------*/

        /*------------------------------------------------------*/
        //  ~BSTREE( VOID )                                     //
        //  ·Método destructor                                  //
        //  ·Delega en el método privado recursivo              //
        //      delete_cascade()                                //
        /*------------------------------------------------------*/
        ~BSTree(){

            if ( root != nullptr ){ delete_cascade(root); }
        }
};

#endif
