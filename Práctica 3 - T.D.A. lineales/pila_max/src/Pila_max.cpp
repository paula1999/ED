/**
 * @file Pila_max.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include "Pila_max_VD.h"

using namespace std;

int main(){
  Pila_max pila1, pila2;
  int n;

  // Introducimos datos en pila1
  for (int i=0; i<5; i++){
    cout << "\nIntroduce numero" << endl;
    cin >> n;

    pila1.poner(n);

    cout << "Elemento en el tope de la pila: " << pila1.tope();
    cout << "Número de elementos de la pila: " << pila1.num_elementos();
  }

  // Usamos constructor de copia
  Pila_max pila3(pila1);

  cout << "\nLa pila que nos ha quedado es: ";
  pila3.imprimir();

  // Quitamos datos
  for (int i=0; i<3; i++){
    cout << "\nQuitando el elemento tope de la pila...\n";

    pila3.quitar();

    cout << "\nElemento en el tope de la pila: " << pila3.tope() << endl;
    cout << "\nElementos restantes en la pila: " << pila3.num_elementos() << endl;
  }

  // Usamos operator=
  pila2 = pila3;

  cout << "\nLa pila que nos ha quedado es: ";
  pila2.imprimir();

}
