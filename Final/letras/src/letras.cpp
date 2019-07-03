/**
 * @file src/letras.cpp
 * @author Paula Villanueva Núñez
 */

#include <fstream>
#include <iostream>
#include "bolsa_letras.h"
#include "conjunto_letras.h"
#include "letra.h"
#include <set>
#include <ctype.h>
#include "diccionario.h"
using namespace std;

/**
  * @brief Comprobamos si la solución es correcta
  * @param letras_aleatorias Letras aleatorias para formar una palabra
  * @param sol Palabra formada con las letras aleatorias
  * @return true si es válida, si no, false
  */
bool comprobar_solucion (multiset<char> letras_aleatorias, const string sol){
  bool parar = false;
  int contador = 0;
  set<char>::const_iterator it;

  for (int i=0; i<sol.size(); i++){
    parar = false;

    for (it=letras_aleatorias.begin(); it!=letras_aleatorias.end() && !parar; ++it){
      if ((*it) == toupper(sol[i])){
        contador++;
        parar = true;
        letras_aleatorias.erase(it);
        it = letras_aleatorias.begin();
      }
    }
  }

  if (contador == sol.size())
    return true;

  return false;
}

int main (int argc, char * argv[]){
  if (argc != 5){
    cout << "Error en los argumentos\n";
    return 1;
  }

  Conjunto_Letras conjunto1, conjunto2;
  Bolsa_letras bolsa, bolsa_aux;
  Letra letra_aux;
  int num_letras = atoi(argv[3]), puntuacion;
  bool modo_long = false;
  string sol, mejor_sol;
  multiset<char> letras_aleatorias;
  multiset<char>::const_iterator it;
  vector<string> posibles_soluciones;
  char respuesta = 'S';
  Diccionario D;
  char modo = *argv[4];

  if (modo == 'L')
    modo_long = true;

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
  g >> conjunto1;
  cout << "Las letras son: \n" << conjunto1 << endl;

  bolsa.aniadir_conjunto(conjunto1);

  while (respuesta == 'S'){
    bolsa_aux = bolsa;
    letras_aleatorias = bolsa.sacar_letra(num_letras);

    // Por si no se puede formar una solución válida
    while (D.sin_solucion(letras_aleatorias)){
      bolsa = bolsa_aux;   // Para no perder las letras aleatorias sacadas
      letras_aleatorias = bolsa.sacar_letra(num_letras);
    }

    cout << "Las letras aleatorias son :";

    for (it=letras_aleatorias.begin(); it!=letras_aleatorias.end(); ++it)
      cout << (*it) << " ";

    cout << "\nDime tu solucion: " << endl;
    cin >> sol;

    // Comprobamos si la solución es válida
    while (!(comprobar_solucion(letras_aleatorias, sol) && D.Esta(sol))){
      cout << "La solución introducida no es válida.\nIntroduce otra solucion:\n";
      cin >> sol;
    }

    puntuacion = conjunto1.calcular_puntuacion(sol);

    cout << sol << "\t" << "Puntuacion: " << puntuacion << endl;
    cout << endl << "Mis soluciones son:\n";

    posibles_soluciones = D.calcular_soluciones (letras_aleatorias);

    if (modo_long)
      conjunto1.mejor_solucion_l(posibles_soluciones);
    else
      conjunto1.mejor_solucion_p(posibles_soluciones);

    cout << "¿Quieres seguir jugando [S/N]?: ";
    cin >> respuesta;
  }
}
