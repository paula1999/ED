/**
 * @file src/conjunto_letras.cpp
 * @author Paula Villanueva Núñez
 */

#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <ctype.h>
#include "conjunto_letras.h"
#include "letra.h"
#include "diccionario.h"
using namespace std;

bool operator< (const Letra & l1, const Letra & l2){
	if (l1.getLetra() < l2.getLetra())
		return true;

	return false;
}

Conjunto_Letras::~Conjunto_Letras(){
  liberarMemoria();
}

void Conjunto_Letras::liberarMemoria(){
  conjunto.clear();
}

int Conjunto_Letras::getSize () const{
	return conjunto.size();
}

set<Letra> Conjunto_Letras::getConjunto () const{
	return conjunto;
}

Conjunto_Letras & Conjunto_Letras::operator= (const Conjunto_Letras & otro){
  liberarMemoria();
  copiar(otro);

	return *this;
}

void Conjunto_Letras::copiar (const Conjunto_Letras & otro){
  conjunto = otro.conjunto;
}

void Conjunto_Letras::addLetra (const Letra & otro){
	conjunto.insert(otro);
}

int Conjunto_Letras::getFrecuencia (const char caracter) const{
	int frec = 0;
	set<Letra>::const_iterator it;

	for (it=conjunto.begin(); it!=conjunto.end(); ++it)
		if ((*it).getLetra() == toupper(caracter))
			frec = (*it).getFrecuencia();

	return frec;
}

int Conjunto_Letras::getFrecuenciaTotal () const{
	int frec = 0;
	set<Letra>::const_iterator it;

	for (it=conjunto.begin(); it!=conjunto.end(); ++it)
			frec += (*it).getFrecuencia();

	return frec;

}

void Conjunto_Letras::quitarFrecuencia (const char otro, const int frec){
	set<Letra>::const_iterator it;
	int f;

	for (it=conjunto.begin(); it!=conjunto.end(); ++it){
		if (((*it).getLetra()) == toupper(otro)){
			f = (*it).getFrecuencia() - frec;
			Letra aux (otro, f, (*it).getPuntuacion());
			conjunto.erase(it);	// Borramos la letra con la anterior frecuencia
			addLetra(aux);	// Añadimos la letra con la nueva frecuencia
			it = --conjunto.end();	// Para evitar el fallo al comparar con conjunto.end() en la siguiente iteración
		}
	}
}

bool Conjunto_Letras::esta_letra (const Letra & otro, set<Letra>::const_iterator & it) const{
	it = conjunto.find(otro);

	if (it != conjunto.end())
		return true;
	else
		return false;
}

bool Conjunto_Letras::comprobar_solucion (const string sol) const{
	bool parar = false;
	int contador = 0;
	char letra;
	set<Letra>::const_iterator it;

	for (it=conjunto.begin(); it!=conjunto.end(); ++it){
		parar = false;
		letra = (*it).getLetra();

		for (int i=0; i<sol.size() && !parar; i++){
			if (letra == toupper(sol[i])){
				contador++;
				parar = true;
			}
		}
	}

	if (contador == sol.size())
		return true;
	return false;
}

int Conjunto_Letras::calcular_puntuacion (const string sol) const{
	set<Letra>::const_iterator it;
	int puntuacion = 0;

	for (int i=0; i<sol.size(); i++)
		for (it=conjunto.begin(); it!=conjunto.end(); ++it)
			if ((*it).getLetra() == toupper(sol[i]))
				puntuacion += (*it).getPuntuacion();

	return puntuacion;
}

void Conjunto_Letras::mejor_solucion_l (const vector<string> & posibles_soluciones) const{
	int puntuacion, tamanio_max = 0, puntuacion_max;
	string mejor_sol;

	for (int i=0; i<posibles_soluciones.size(); i++){
		puntuacion = posibles_soluciones[i].length();
		cout << posibles_soluciones[i] << "\t\tPuntuacion: " << puntuacion << endl;

		if (posibles_soluciones[i].size() > tamanio_max){
			tamanio_max = posibles_soluciones[i].size();
			mejor_sol = posibles_soluciones[i];
			puntuacion_max = puntuacion;
		}
	}

	cout << "\nMi mejor solucion: " << mejor_sol <<  " con " << puntuacion_max << " puntos" << endl;
}

void Conjunto_Letras::mejor_solucion_p (const vector<string> & posibles_soluciones) const{
	int puntuacion, puntuacion_max = 0;
	string mejor_sol;

	for (int i=0; i<posibles_soluciones.size(); i++){
		puntuacion = calcular_puntuacion(posibles_soluciones[i]);
		cout << posibles_soluciones[i] << "\t\tPuntuacion: " << puntuacion << endl;

		if (puntuacion_max < puntuacion){
			puntuacion_max = puntuacion;
			mejor_sol = posibles_soluciones[i];
		}

	}

	cout << "\nMi mejor solucion: " << mejor_sol <<  " con " << puntuacion_max << " puntos" << endl;
}

ostream & operator<< (ostream &os, const Conjunto_Letras & otro){
	set<Letra>::const_iterator it;

  os << "#Letra\tCantidad\tPuntuacion\n";

  for (it=otro.conjunto.begin(); it!=otro.conjunto.end(); ++it)
    os << (*it).getLetra() << "\t" << (*it).getFrecuencia() << "\t\t" << (*it).getPuntuacion() << endl;

  return os;
}

istream & operator>> (istream & is, Conjunto_Letras & otro){
  otro.liberarMemoria();

  Letra aux_letra;
  Conjunto_Letras aux_conjunto;

  while (is >> aux_letra)
    aux_conjunto.addLetra(aux_letra);

  otro = aux_conjunto;

  return is;
}
