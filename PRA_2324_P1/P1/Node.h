#include <ostream>

template <typename T> 
class Node {
    public:

        T data; //elemento almacenado de tipo genérico
        Node<T>* next; //puntero al siguiente nodo de la secuencia

        Node(T data, Node<T>* next = nullptr){    
        //método constructor
        //next será nullptr en caso de que no se proporcione
            
            this-> data = data;
            this-> next = next;

        }
        
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
        //sobrecarga global del operador << para imprimir una instancia de Node<T> por pantalla (solo data)

            out << " " << node.data;
                
            return out;
            
        }
    

};