/**
 * @file src/letra.cpp
 * @author Paula Villanueva Núñez
 */

#include "letra.h"
#include <iostream>
#include <string>
using namespace std;

Letra::Letra(){
  l = '-';
  frecuencia = 0;
  puntuacion = 0;
}

Letra::Letra (char a, int frec, int puntos){
  l = a;
  frecuencia = frec;
  puntuacion = puntos;
}

Letra::Letra (const Letra & otro){
  copiar(otro);
}

Letra::~Letra(){
  liberarMemoria();
}

void Letra::liberarMemoria (){
  l = '-';
  frecuencia = 0;
  puntuacion = 0;
}

Letra & Letra::operator= (const Letra & otro){
  liberarMemoria();
  copiar(otro);
  return *this;
}

void Letra::copiar (const Letra & otro){
  l = otro.getLetra();
  frecuencia = otro.getFrecuencia();
  puntuacion = otro.getPuntuacion();
}

char Letra::getLetra () const{
  return l;
}

int Letra::getFrecuencia () const{
  return frecuencia;
}

int Letra::getPuntuacion () const{
  return puntuacion;
}

ostream & operator<< (ostream &os, const Letra & otro){
  os << "Letra: " << otro.l << endl;
  os << "Cantidad: " << otro.frecuencia << endl;
  os << "Puntos: " << otro.puntuacion << endl;

  return os;
}

istream & operator>> (istream & is, Letra & otro){
  string cadena;
  char letra;
  int frec, puntos;

  otro.liberarMemoria();

  getline(is, cadena);
  is >> letra >> frec >> puntos;

  Letra aux(letra, frec, puntos);

  otro = aux;

  return is;
}
