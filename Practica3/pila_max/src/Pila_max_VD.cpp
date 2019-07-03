/**
 * @file Pila_max_VD.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include <cassert>
#include "Pila_max_VD.h"

using namespace std;

ostream & operator<<(ostream & os, elemento & a){
  os << a.ele << ". Máximo: " << a.maximo << endl;

  return os;
}


Pila_max::~Pila_max(){
  datos.liberarMemoria();
}

Pila_max& Pila_max::operator= (const Pila_max & otra){
  if (this != &otra){
    datos = otra.datos;
  }

  return *this;
}

bool Pila_max::vacia() const{
  return (datos.dimension()==0);
}

elemento & Pila_max::tope(){
  assert(datos.dimension()>0);       //Si la pila est� vac�a, abortar

  return datos[0]; //Devuelve el elemento del tope de la pila
}

const elemento & Pila_max::tope() const{
  assert(datos.dimension()>0);       //Si la pila est� vac�a, abortar

  return datos.componente(0); //Devuelve el elemento del tope de la pila
}

void Pila_max::poner(const int & elem){
  if (datos.dimension() == 0){
    elemento a = {elem, elem};
    datos.asignar_componente(0,a);
  }
  else{
    if (datos[0].maximo>=elem){
      elemento a = {elem, datos[0].maximo};
      datos.insertar(0,a);
    }
    else{
      elemento a = {elem, elem};
      datos.insertar(0,a);
    }
  }
}


void Pila_max::quitar(){
  assert(datos.dimension()>0);       //Si la pila est� vac�a, abortar
  datos.borrar(0);
}

int Pila_max::num_elementos() const{
  return datos.dimension();
}

void Pila_max::imprimir() const{
  elemento a;

  cout << "\n";

  for (int i=0; i<datos.dimension(); i++){
    a = datos.componente(i);
    cout << a;
  }
}
