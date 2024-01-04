#ifndef LISTLINKED_H
#define LISTLINKED_H


#include "P1/List.h"
#include "P1/Node.h"
#include <ostream>
#include <exception>
#include <string>

#define TRUE 1
#define FALSE 0

std::string info = "Posición inválida!";

template <typename T> 
class ListLinked : public List<T> {
 
	private:
	
		/****************************************************************/
		/*                           *first                             */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Puntero al primer nodo de la secuencia enlazada que almacena */
		/* los datos de la lista (de tipo T genérico).                  */
		/*                                                              */
		/****************************************************************/
		
		Node<T> *first;
		
		/****************************************************************/
		/*                              n                               */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Número de elementos que contiene la lista.                  */
		/*                                                              */
		/****************************************************************/
		
		int n;
	
	public:
		
		//----// INSERT //--------------------------------------+
		void insert(int pos, T e) override
		{
			if ( !(pos < 0 || pos > size()) )
			{
				if(size() == 0)
				{
    				first = new Node(e);
    				n++;
    			}
    			else if (pos == 0) { prepend(e); }
    			else if (pos == size()) { append(e); }
    			else
    			{
    				int i = 0;
    				Node<T> *aux = first;
    				Node<T> *prevAux = nullptr;
    				while (i < pos)
    				{
    					prevAux = aux;
    					aux = aux->next;
    					i++;
    				}
    				Node<T> *insert = new Node(e, aux);
    				prevAux->next = insert;
    				n++;
    			}
    		}
			else { throw std::out_of_range(info); }
		}
		//------------------------------------------------------+



		//----// APPEND //--------------------------------------+
		void append(T e) override
		{
			Node<T> *insert = new Node(e);
			Node<T> *aux = first;
			for(int i = 0; i < (size()-1); i++) {
				aux = aux->next;
			}
			aux->next = insert;
    		n++;
		}
		//------------------------------------------------------+



		//----// PREPEND //-------------------------------------+
		void prepend(T e) override
		{
			Node<T> *insert = new Node(e, first);
			first = insert;
    		n++;
		}
		//------------------------------------------------------+
		
		

		//----// REMOVE //--------------------------------------+
		T remove(int pos) override
		{
			T removed;
			if ( (pos >= 0 && pos < size()) )
			{
				Node<T> *prevMark = nullptr;
    				Node<T> *mark = first;
    				int i = 0;

 				// Removing the FIRST
 				if (pos == 0)
 				{
 					first = mark->next;
 				}
    				
    				// Removing an INTERMEDIARY & BACK
    				else
    				{
    					while (i < pos)
					{
  						prevMark = mark;
  						mark = mark->next;
  						i++;
					}
					prevMark->next = mark->next;
    				}
    				
				removed = mark->data;
				delete mark;
 				n--;
 			}
			else { throw std::out_of_range(info); }
			
			return removed;	
		}
		//------------------------------------------------------+
		
		
		
		//----// GET //-----------------------------------------+
		T get(int pos) override
		{
			T wanted;
			if ( (pos >= 0 && pos < size()) )
			{
				Node<T> *aux = first;
 				int i = 0;
			
				while (i < pos)
				{
  					aux = aux->next;
  					i++;
				}
				wanted = aux->data;
 			}
			else { throw std::out_of_range(info); }
			
			return wanted;
		}
		//------------------------------------------------------+
		
		

		//----// SEARCH //--------------------------------------+
		int search(T e) override
		{
  			Node<T> *aux = first;
 			int posi = 0;
 			 
  			while ((aux != nullptr) && (aux->data != e))
  			{
  				aux = aux->next;
  				posi++;
  			}
 
  			if (aux == nullptr) { posi = -1; }

 			return posi;
		}
		//------------------------------------------------------+
		
		

		//----// EMPTY //---------------------------------------+
		bool empty() override
		{
			bool answer;
			(n == 0) ? (answer = TRUE) : (answer = FALSE);
			
			return answer;		
		}
		//------------------------------------------------------+
				
				
		
		//----// SIZE //----------------------------------------+
		int size() override
		{
			return n;
		}
		//------------------------------------------------------+
		
		/****************************************************************/
		/*                        ListLinked                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método constructor sin argumentos. Inicializará los dos      */
		/* atributos de instancia (first será nullptr).                 */
		/*                                                              */
		/****************************************************************/

		ListLinked()
		{
			first = nullptr;
			n = 0;
		}
	
		/****************************************************************/
		/*                       ~ListLinked                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Método destructor. Se encargará de liberar la memoria        */
		/* dinámica reservada por los nodos Node<T> que componen la     */
		/* secuencia. Ver la nota de abajo para más detalles.           */
		/*                                                              */
		/****************************************************************/
		
        	~ListLinked()
        	{
        		Node<T> *aux;
        		
        		while (size() > 0)
        		{
        			aux = first->next;
        			Node<T> *prevAux = first;
        			first = aux;
        			delete prevAux;
        			n--;
        		}
        	}
	
		/****************************************************************/
		/*                        operator[]                            */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga del operador []. Devuelve el elemento situado en  */
		/* la posición pos. Lanza una excepción std::out_of_range si la */
		/* posición no es válida (fuera del intervalo [0, size()-1]).   */
		/*                                                              */
		/* ENTRADA: int pos.                                            */
		/*                                                              */
		/* SALIDA: Devuelve el elemento T situado en la posición pos.   */
		/****************************************************************/
		
        	T operator[](int pos)
        	{
        		return get(pos);
		}
	
		/****************************************************************/
		/*                         operator <<                          */
		/*--------------------------------------------------------------*/
		/*                                                              */
		/* DESCRIPCION:                                                 */
		/* Sobrecarga global del operador << para imprimir una instancia*/
		/* de ListArray<T> por pantalla. Incluir la cabecera  <ostream> */
		/* en el .h.                                                    */
		/*                                                              */
		/* ENTRADA: std::ostream &out, const ListArray<T> &list.        */
		/*                                                              */
		/* SALIDA: Imprime instancia.                                   */
		/****************************************************************/
		
 		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
 		{
 			out << "List => [";
 			if (list.n == 0) { out << ""; }
 			else
 			{
 				Node<T> *aux = list.first;
 				for (int i = 0; i < list.n; i++)
 				{
 					out << std::endl << "  " << aux->data;
 					aux = aux->next;
 				}
 				out << std::endl;
 			}
 			
 			out << "]";
 			
 			return out;
 		}
		
};

#endif
