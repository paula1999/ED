/**
 * @file src/diccionario.cpp
 * @author Paula Villanueva Núñez
 */

#include "diccionario.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <ctype.h>
using namespace std;

int Diccionario::size() const{
  return datos.size();
}

vector<string> Diccionario::PalabrasLongitud (const int longitud) const{
  vector<string> aux;
  set<string>::iterator it;

  for (it=datos.begin(); it!=datos.end(); ++it)
    if ((*it).size() == longitud)
      aux.push_back((*it));

  return aux;
}

bool Diccionario::Esta (const string palabra) const{
  if (size() > 0){
    bool esta = false;
    set<string>::iterator it;

    for (it=datos.begin(); it!=datos.end() && !esta; ++it)
      if ((*it) == palabra)
        esta = true;

    return esta;
  }
  else
    return false;
}

void Diccionario::insert (string palabra){
  if (!Esta(palabra))
    datos.insert(datos.end(), palabra);
}

double Diccionario::contador_letra (const char & l) const{
  set<string>::iterator it;
  string aux;
  double contador = 0;

  for (it=datos.begin(); it!=datos.end(); ++it){
    aux = *it;

    for (int i=0; i<=aux.size(); i++)
      if (l == aux[i])
        contador++;
  }

  return contador;
}

bool Diccionario::pasar_a_fichero (const char *fichero) const{
    bool salvado = false;
    ofstream fo;
    set<string>::const_iterator it_D;
    double contador1=0, contador2;

    fo.open(fichero);

    if (fo){
      fo << "#Letra\tFabs\tFrel\n";

      for (char i='a'; i!='z'+1; ++i)
        contador1 += contador_letra(i);

      for (char i='a'; i!='z'+1; ++i){
        contador2 = contador_letra(i);

        fo << i << "\t" << contador2 << "\t" << contador2/contador1 << endl;
      }

      if (fo)
        salvado = true;

      fo.close();
    }

    return salvado;

}

vector<string> Diccionario::calcular_soluciones (multiset<char> & letras) const{
  set<string>::const_iterator it;
  set<char>::const_iterator it2;
  multiset<char> aux = letras;
  string dic;
  bool esta;
  int k = 0, contador = 0;
  vector<string> posibles_soluciones;

  for (it=datos.begin(); it!=datos.end(); ++it){
    contador = 0;
    dic = (*it);
    k = 0;
    esta = true;
    letras = aux;

    while (esta){
      esta = false;
      it2 = letras.find(toupper(dic[k]));

      if (it2 != letras.end()){
        esta = true;
        contador++;
        k++;
        letras.erase(it2);
      }
    }

    if (contador == dic.size())
      posibles_soluciones.push_back(dic);
  }

  return posibles_soluciones;
}

bool Diccionario::sin_solucion (multiset<char> & letras) const{
  vector<string> aux;
  aux = calcular_soluciones(letras);

  if (aux.size() == 0)
    return true;
  else
    return false;
}

istream & operator>> (istream & is, Diccionario & D){
  Diccionario Daux;
  string palabra;

  while (is >> palabra)
    Daux.insert(palabra);

  D = Daux;

  return is;
}

ostream & operator<< (ostream & os, const Diccionario & D){
  set<string>::const_iterator it;

  for (it=D.datos.begin(); it!=D.datos.end(); ++it)
    os << endl << (*it) << endl << "******************" << endl;

  return os;
}

const string & Diccionario::iterator::operator *(){
  return *it;
}

typename Diccionario::iterator & Diccionario::iterator::operator ++(){
  ++it;
}
typename Diccionario::iterator & Diccionario::iterator::operator --(){
  --it;
}
bool Diccionario::iterator::operator== (const iterator &i){
  return i.it == it;
}
bool Diccionario::iterator::operator!= (const iterator &i){
  return i.it != it;
}

typename Diccionario::iterator Diccionario::begin(){
  iterator i;
  i.it = datos.begin();

  return i;
}
typename Diccionario::iterator Diccionario::end(){
  iterator i;
  i.it = datos.end();

  return i;
}
