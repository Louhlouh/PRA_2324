#include "List.h"
#include "Node.h"

#include <ostream>
#include <exception>

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first; //puntero al primer nodo de la secuencia enlazada que almacena los datos de la lista
        int n; //número de elementos que contiene la lista

    public:

        ListLinked()
        {   
        //método constructor sin argumentos (siendo first = nullptr)

            this-> first = nullptr;
            this-> n = 0;

        }

        /*
        ESTRATEGIA
// 1.Situar un puntero aux que apunte al nodo first->next
// 2.Liberar la memoria ocupada por el nodo al que apunta first
// 3.Actualizar first para que apunte a la mismo nodo que aux
// 4.Repetir los pasos 1-3 hasta que se alcance el final de la secuencia
        */
        ~ListLinked()
        {  
        //método destructor que se encarga de liberar la memoria dinámica reservada por los Nodos<T>
        
            Node<T>* aux = first->next; 

            while (aux != nullptr){

                delete first;           
                first->next = aux->next;    
                aux = first->next;   

            }     

        }
    
        T operator[](int pos)
        {  
        //sobrecarga del [] que devuelve el elemento situado en la posición pos
        //lanza una excepción si la posición no es válida (fuera de [0, size() - 1])

            if (pos < 0 || pos > size()-1){ throw out_of_range("Posición inválida"); }
                 
            Node<T>* aux = first;

            for ( int i = 0; i != pos; i++ ){

                aux = aux->next;

            }

            return aux->data;  //devuelve la información del número contenido en aux

        }
        
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
        {  
        //sobrecarga global del operador << para imprimir una instancia de ListLinked<T> por pantalla
            
            out << "List = [ ";

            if(0 < list.n){ //comprobamos si hay algún elemento 

                Node<T>* aux = list.first;

                while (aux != nullptr){

                    out << aux->data << " "; 
                    aux = aux->next;

                }

            } 

            out << "]" << endl;

            return out;

        }


        //MÉTODOS LIST.H

        void insert(int pos, T e) override //uso append (pos = size() - 1) y prepend (pos = 0)
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

                    Node<T>* prev = nullptr;
                    Node<T>* aux = first;

                    int i = 0;

                    while ( aux != nullptr && i < pos ){

                        prev = aux;
                        aux = aux->next;

                        i++;

                    }
                    
                    prev->next = new Node(e, aux);    

                } 
        }

        void append(T e) override 
        {  
        //inserta el elemento e al final de la lista

            n++;

            Node<T>* prev = nullptr;
            Node<T>* aux = first;

            int i = 0;

            while ( aux != nullptr && i < size() ){ 

                prev = aux;
                aux = aux->next;

                i++;
            }
                
            prev->next = new Node(e, aux); 

        }

        void prepend(T e) override
        {  //uso de resize
            //inserta el elemento e al final de la lista

            n++;

            first = new Node(e, first);

        }

        T remove(int pos) override
        { 
        //elimina y devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size() - 1])  
        
            if ( pos < 0 || pos > size() - 1 ){

                throw out_of_range("Posición fuera de rango");

            }

            n--;    
            
            Node<T>* prev = nullptr;
            Node<T>*aux = first;

            for (int i = 0; i != pos; i++){

                prev = aux;
                aux = aux->next;

            }

            int remove = aux->data;  

            if (aux == first) { //primer elemento
                    first = aux->next; 
            }

            else { 
                prev->next = aux->next; 
            }
            
            delete aux; //liberamos memoria
           
            return remove;

        }

        T get(int pos) override
        {
        //devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size() - 1])

            if ( pos < 0 || pos > size() - 1 ){

                throw out_of_range("Posición fuera de rango");

            }

            Node<T>* aux = first;

            int i = 0;

            while ( aux != nullptr && i != pos ){   

                i++;
                aux = aux->next;

            }

            return aux->data; 

        }
        
        int search(T e) override
        { 
        //devuelve la posición en la que se encuentra la primera ocurrencia del elemento e o -1 si no se encuentra
            
            Node<T>* aux = first;
            int i = 0;

            while ( aux != nullptr && aux->data != e ){

                aux = aux->next;
                i++;

            }

            return ( ( aux == nullptr ) ? -1 : i );

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