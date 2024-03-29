/**
 * @file VDG.h
 * @author Paula Villanueva Nuñez
*/

#ifndef __VDG_H__
#define __VDG_H__

/**
   VectorDinamico::VectorDinamico, ~VectorDinamico, redimensionar,
   dimension, componente, asignar_componente, operator[]

   Este TDA representa vectores de objetos de la clase T cuyo tama�o
   puede cambiar en tiempo de ejecuci�n.
   Son mutables.
   Residen en memoria din�mica.

   Requisitos para la instanciaci�n:

   La clase T debe tener las siguientes operaciones:
   - Constructor por defecto
   - Constructor de copia
   - Operador de asignaci�n
  */

template <class T>
class VectorDinamico {
public:
/*
 *  Operaciones
 */

 /**
    Constructor: crea un vector din�mico vacío.

    @doc
      Crear un vector din�mico inicializado a 0.
   */
  VectorDinamico();
  /**
     Constructor: crea un vector din�mico.

     @param num_elem: N�mero de componentes del nuevo vector.
            num_elem >= 0.

     @doc
       Crear un vector din�mico con num_elem componentes.
    */
  VectorDinamico(int num_elem);

  /**
   Constructor: crea un vector dinámico

   @param otro: vector dinámico que se quiere copiar.
   */
  VectorDinamico(const VectorDinamico & otro);

  /**
    @brief Copia un vector dinámico en el actual
    @param otro: vector dinámico copiado
    */
  void copiar(const VectorDinamico & otro);

  /**
    @brief Borra el contenido del vector dinámico
    */
  void liberarMemoria();

  /**
     Destructor.

     @doc
       Destruye v liberando los recursos que empleaba.
    */
  ~VectorDinamico();

  /**
     Modifica el tama�o del receptor.

     @param num_elem: nuevo tama�o del vector. num_elem >= 0.

     @return 0, si �xito.
             1, si se producen errores.

     @doc
       Modifica el tama�o del receptor, dej�ndolo con num_elem componentes.
     a) Si dimension() < num_elem, los anteriores elementos del receptor
        se conservan en sus posiciones y las nuevas componentes se
        inician a 0.
     b) Si dimension() <= num_elem, las primeras num_elem componentes
        de ve se mantienen en sus posiciones.
     Si todo el proceso culmina con �xito, devuelve 0. Si se produce
     alg�n error, devuelve 1.
    */
  int redimensionar(int num_elem);

  /**
     Devuelve el n�mero de componentes del receptor.

     @return n�mero de componentes del receptor.
    */
  int dimension() const;

  /**
     Acceso a una componente del vector.

     @param i: indice de la componente a obtener. 0 <= i < dimension().

     @return componente i-�sima del vector receptor.
    */
  T componente(int i) const;

  /**
     Modifica el valor de una componente del vector.

     @param i: indice de la componente a modificar. 0 <= i < dimension().
     @param valor: nuevo valor a asignar a la componente

     @doc
       Modifica la componente i-�sima de v, que pasa a ser 'valor'.
    */
  void asignar_componente(int i, const T & elem);

  //void insertar(int i, const elemento & elem);

  /**
     Acceso a una componente del vector, con posibilidad de modificaci�n.

     @param i: indice de la componente a obtener. 0 <= i < dimension().

     @return referencia a la componente i-�sima del vector receptor.
    */
  T & operator[](int i);

  /**
    @brief Evalúa si la posición @a i es válida
    @param i: posición evaluada
    @return true si la posición es válida, si no, false.
    */
  bool posicionValida(int i);

  /**
    @brief Borra los elementos de la posición @a i
    @param i: posición de los elementos que van a ser borrados
    */
  void borrar(int i);

  /**
    @brief Operador de asignaci�n
    @param otra: El vector dinámico que se va a asignar.
    */
  VectorDinamico<T> & operator= (const VectorDinamico & otro);

  /**
    @brief inserta en la posición @a i el elemento @a elem
    @param i: posición en la que se va a insertar
    @param elem: elemento que se va a insertar
    */
  void insertar(int i, const T & elem);

 private:
  T * datos;
  int num_comp;
};


#include "VDG.cpp"

#endif
