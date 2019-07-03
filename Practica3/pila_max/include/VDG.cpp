/**
 * @file VDG.cpp
 * @author Paula Villanueva Nuñez
*/

#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;
/*

  ** Funci�n de abstracci�n:
     ----------------------

     fA : tipo_rep  -------> Tipo Abstracto
        {datos, num_comp}--> { datos[0], datos[1], ..., datos[num_comp - 1]}


  ** Invariante de Representaci�n:
     ----------------------------
     Cualquier objeto del tipo_rep, {datos, num_comp}, debe cumplir:
     - num_comp >= 0;
     - datos: apunta a una zona con capacidad para albergar a
       'num_comp' objetos de la clase T.
 */

template <class T>
VectorDinamico<T>::VectorDinamico(){
  datos = 0;
  num_comp = 0;
}

template <class T>
VectorDinamico<T>::VectorDinamico(int num_elem){
  datos = new T[num_elem];

  if (datos == 0){
      cerr << "Memoria insuficiente\n";
      exit(-1);
  }

  num_comp = num_elem;
}

template <class T>
void VectorDinamico<T>::copiar(const VectorDinamico & otro){
  num_comp = otro.dimension();
  datos = new T[otro.dimension()];

  for (int i=0; i<num_comp; i++)
    datos[i] = otro.componente(i);
}

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico & otro){
  copiar(otro);
}

template <class T>
void VectorDinamico<T>::liberarMemoria(){
  delete[] datos;
  datos = 0;
  num_comp = 0;
}

template <class T>
VectorDinamico<T>::~VectorDinamico(){
  liberarMemoria();
}


template <class T>
int VectorDinamico<T>::redimensionar(int num_elem){
  /* Si piden el mismo tama�o que tiene: no hacer nada */
  if (num_elem == num_comp)
    return 0;

  /* Reserva nuevo espacio */
  T * p = new T [num_elem];

  if (p == 0){
    return 1;
  }

  /* Si el vector estaba vac�o, simplemente iniciar a 0 */
  if (num_comp == 0){
    delete[] datos;
    datos = 0;
    p[0] = {0,0};
    datos = p;

    num_comp = num_elem;

    return 0;
  }

  /* Copiar los componentes que se mantienen */
  num_comp = num_elem;

  for (int i=num_comp-1; i>0; i--){
    p[i] = {datos[i-1].ele, datos[i-1].maximo};
  }

  p[0] = {0,0};

  delete[] datos;
  datos = p;

  return 0;
}


template <class T>
int VectorDinamico<T>::dimension() const{
  return num_comp;
}

template <class T>
T VectorDinamico<T>::componente(int i) const{
  assert (0 <= i && i < num_comp);

  return datos[i];
}


template <class T>
void VectorDinamico<T>::asignar_componente(int i, const T & valor){
  if (!redimensionar(1))
    datos[i] = {valor.ele, valor.maximo};
}

template <class T>
void VectorDinamico<T>::insertar(int i, const T & elem){
  if (!redimensionar(num_comp+1)){
    datos[i] = {elem.ele, elem.maximo};
  }
}


template <class T>
T & VectorDinamico<T>::operator[](int i){
  assert (0 <= i && i < num_comp);

  return datos[i];
}

template <class T>
bool VectorDinamico<T>::posicionValida(int i){
  return (i<num_comp && i>=0);
}

template <class T>
void VectorDinamico<T>::borrar(int i){
  if (posicionValida(i)){
    if ((i == 0) && (num_comp == 1)){
      liberarMemoria();
    }
    else{
      T * p = new T[num_comp-1];

      for (int j=0; j<num_comp-1; j++){
        p[j] = datos[j+1];
      }

      delete[] datos;
      datos = p;
      num_comp--;
    }
  }
}

template <class T>
VectorDinamico<T> & VectorDinamico<T>::operator= (const VectorDinamico & otro){
  if (this != &otro){
    liberarMemoria();
    copiar(otro);
  }

  return *this;
}
