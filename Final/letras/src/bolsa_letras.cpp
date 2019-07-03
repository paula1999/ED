/**
 * @file src/bolsa_letras.cpp
 * @author Paula Villanueva Núñez
 */

#include "bolsa_letras.h"
#include "letra.h"
#include "conjunto_letras.h"
#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Bolsa_letras::Bolsa_letras (const Bolsa_letras & otro){
  bolsa = otro.bolsa;
}

void Bolsa_letras::liberarMemoria (){
  bolsa.liberarMemoria();
}

Bolsa_letras::~Bolsa_letras (){
  liberarMemoria();
}

void Bolsa_letras::aniadir_conjunto (const Conjunto_Letras & otro){
  bolsa = otro;
}

int Bolsa_letras::getFrecuencia (const char caracter) const{
  int frec = bolsa.getFrecuencia(caracter);
  return frec;
}

multiset<char> Bolsa_letras::sacar_letra (const int tamanio){
  multiset<char> aux;
  int tam, aleatorio, contador=0;
  set<Letra>::const_iterator it;
  set<Letra> conjunto;
  char l;

  tam = bolsa.getFrecuenciaTotal();
  conjunto = bolsa.getConjunto();

  srand(time(NULL));

  while (tamanio != contador){
    aleatorio = (rand() % tam) + 1;
    it = conjunto.begin();

    // Aumentamos la posición del iterador un número aleatorio
    while ((it != conjunto.end()) && (aleatorio != 0)){
      aleatorio -= (*it).getFrecuencia();

      if (aleatorio <= 0)
        aleatorio = 0; // Para detener el bucle
      else
        it++;
    }

    if (it != conjunto.end()){
      l = (*it).getLetra();

      if (getFrecuencia(l) > 0){
        aux.insert(l);
        contador++;
        bolsa.quitarFrecuencia(l, 1);
      }
    }
  }

  return aux;
}

Bolsa_letras & Bolsa_letras::operator= (const Bolsa_letras & otro){
  bolsa = otro.bolsa;
}

ostream & operator<< (ostream &os, const Bolsa_letras & otro){
  os << "Letras disponibles:\n" << otro.bolsa;

  return os;
}
