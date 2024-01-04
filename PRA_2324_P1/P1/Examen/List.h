#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {

    public:

        virtual void insert(int pos, T e) = 0; 
        //inserta el elemento e en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size()])  

        virtual void append(T e) = 0;
        //inserta el elemento e al final de la lista

        virtual void prepend(T e) = 0;
        //inserta el elemento e al principio de la lista

        virtual T remove(int pos) = 0;
        //elimina y devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size() - 1])  

        virtual T get(int pos) = 0;
        //devuelve el elemento situado en la posición pos
        //lanza una excepción out_of_range si la posición pos no es valida (fuera de [0, size()])          

        virtual int search(T e) = 0;
        //devuelve la posición en la que se encuentra la primera ocurrencia del elemento e o -1 si no se encuentra

        virtual bool empty() = 0;
        //indica si la lista está vacía

        virtual int size() = 0;
        //devuelve el número de elementos de la lista

                                //////////EXAMEN//////////

        virtual void invert_list() = 0;
        //invierte los elementos existentes en la lista

};

#endif
