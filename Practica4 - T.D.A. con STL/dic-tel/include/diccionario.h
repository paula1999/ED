/**
 * @file diccionario.h
 * @author Paula Villanueva Nuñez
*/

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;
 };

 /*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 un funtor.
 */
template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave < d2.clave)
		     return true;

	   return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/
template <class T,class U>
class Diccionario{
	  private:
 		    list<data<T,U> > datos;

		    void Copiar(const Diccionario<T,U>& D);

		    void Borrar();

	  public:
      /**
        * @brief Constructor por defecto
        */
		 Diccionario():datos(list<data<T,U> >()){}

     /**
       * @brief Constructor de copias
       * @param D Diccionario del que se hará la copia.
       */
		 Diccionario(const Diccionario &D){
			   Copiar(D);
		 }

     /**
       * @brief Destructor
       */
		 ~Diccionario(){}

     /**
       * @brief Operador de asignaci�n
       * @param D Diccionario que se va a asignar.
       */
		 Diccionario<T,U> & operator=(const Diccionario<T,U> &D);

    /**
      * @brief Busca la clave p en el diccionario
      * @param p Clave buscada
      * @param p it_out Iterador que apunta a la clave
      * @return Devuelve true si está la clave, devuelve false si no
    */
		bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out);

     /**
       * @brief Inserta un nuevo registro en el diccionario
       * @param clave Clave que se inserta
       * @param info Información asociada a la clave insertada
     */
		 void Insertar(const T& clave,const list<U> &info);

     /**
       * @brief Añade al final una nueva información asociada a una clave.
       * @param s Clave
       * @param p Información asociada a la clave
     */
		 void AddSignificado_Palabra(const U & s ,const T &p);

      /**
        * @brief Devuelve la información asociada a una clave
        * @param p Clave de la que queremos buscar información
        * @return Devuelve la lista con la información asociada a la clave
      */
		  list<U> getInfo_Asoc(const T & p);

     /**
       * @brief Devuelve el tamaño del diccionario
       * @return Devuelve el tamaño del diccionario
     */
		 int size()const;

     /**
       * @brief Borra una palabra del diccionario
       * @param p Palabra que se va a borrar
     */
     void borrar_Palabra (const T &p);

     /**
       * @brief Devuelve el diccionario con las palabras que empiezan por @a l
       * @param l Letra por la que empezarán las palabras del diccionario devuelto
       * @return Devuelve el diccionario con las palabras que empiezan por @a l
     */
     Diccionario<T,U> buscar_Letra (const T &l);

     /**
       * @brief Devuelve el diccionario con las palabras con el máximo número de significados
       * @return Devuelve el diccionario con las palabras con el máximo número de significados
     */
     Diccionario<T,U> max_significado();

     /**
       @brief Escritura del diccionario
       @param os: flujo de salida. Es MODIFICADO
       @param D: diccionario que se escribe
       @return el flujo de salida
      */
     friend ostream & operator<< (ostream & os, const Diccionario<string,string> & D);

     /**
       @brief Lectura del diccionario
       @param is: flujo de entrada. ES MODIFICADO
       @param D: diccionario. ES MODIFICADO
       @return el flujo de entrada
     */
     friend istream & operator>> (istream & is,Diccionario<string,string> &D);

		 /*Funciones begin y end asociadas al diccionario*/
		 typename list<data<T,U> >::iterator begin();

		 typename list<data<T,U> >::iterator end();

		 typename list<data<T,U> >::const_iterator begin() const;

		 typename list<data<T,U> >::const_iterator end() const;
};

#include "diccionario.cpp"

#endif
