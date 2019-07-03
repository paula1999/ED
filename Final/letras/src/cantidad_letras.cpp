/**
 * @file src/cantidad_letras.cpp
 * @author Paula Villanueva Núñez
 */

#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "conjunto_letras.h"
using namespace std;

int main (int argc, char * argv[]){
  Diccionario D;
  Conjunto_Letras conjunto;

  if (argc != 4){
    cout << "Argumentos incorrectos\n";
    return 0;
  }

  ifstream f(argv[1]);

  if (!f){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  cout << "Cargando diccionario..." << endl;
  f >> D;

  ifstream g(argv[2]);

  if (!g){
    cout << "No puedo abrir el fichero " << argv[2] << endl;
    return 0;
  }

  cout << "Cargando letras..." << endl;
  g >> conjunto;

  D.pasar_a_fichero(argv[3]);
}
