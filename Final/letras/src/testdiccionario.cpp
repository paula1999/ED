/**
 * @file src/testdiccionario.cpp
 * @author Paula Villanueva Núñez
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "diccionario.h"
using namespace std;

int main (int argc, char *argv[]){
  string p;
  Diccionario D;
  int longitud;

  if (argc != 2){
    cout << "Los parámetros son: " << endl << "1.- El fichero con las palabras";
    return 0;
  }

  ifstream f(argv[1]);

  if (!f){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  cout << "Cargando diccionario..." << endl;
  f >> D;
  cout << "Leido el diccionario..." << endl << D;
  cout << "Dime la longitud de las palabras que quieres ver: ";
  cin >> longitud;

  vector<string> v = D.PalabrasLongitud(longitud);

  cout << "Palabras de longitud " << longitud << endl;

  for (unsigned int i=0; i<v.size(); i++)
    cout << v[i] << endl;

  cout << "Dime una palabra: ";
  cin >> p;

  if (D.Esta(p))
    cout << "Sí, esa palabra existe\n";
  else
    cout << "Esa palabra no existe\n";
}
