/**
 * @file guiatlf.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include <string.h>
#include "guiatlf.h"

using namespace std;

istream & operator>>(istream &is, pair<string,string> &d){
	  getline(is,d.first,'\t');
	  getline(is,d.second, '\n');

	  return is;
}

Guia_Tlf::Guia_Tlf(const Guia_Tlf & gt){
  datos = gt.datos;
}

Guia_Tlf::~Guia_Tlf(){
  clear();
}

Guia_Tlf & Guia_Tlf::operator=(const Guia_Tlf & gt){
  datos = gt.datos;
  return *this;
}

string & Guia_Tlf::operator[](const string &nombre) {
    return datos[nombre];
}

string Guia_Tlf::gettelefono(const string & nombre){
    map<string,string>::iterator it = datos.find(nombre);

    if (it == datos.end())
      return string("");
    else
      return it->second;
}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(string nombre, string tlf){
    pair<string,string> p (nombre,tlf);
    pair< map<string,string> ::iterator,bool> ret;

    ret = datos.insert(p);
    return ret;
}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(pair<string,string> p){
  pair<map<string,string> ::iterator,bool> ret;

  ret = datos.insert(p);

  return ret;
}

void Guia_Tlf::borrar(const string &nombre){
 map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
 map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre

 datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
  map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
  map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
  map<string,string>::iterator it, aux;
  bool salir = false;

  for (it=itlow; it!=itupper && !salir; ++it){
     if (it->second == tlf){
       aux = datos.erase(it);
       salir = true;
			 it = aux;
     }
  }
}

int Guia_Tlf::size() const{
    return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre){
    return datos.count(nombre);
}

void Guia_Tlf::clear(){
    datos.clear();
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
  Guia_Tlf aux(*this);
  map<string,string>::const_iterator it;

  for (it=g.datos.begin(); it!=g.datos.end();++it){
    aux.insert(it->first,it->second);
  }

  return aux;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
  Guia_Tlf aux(*this);
  map<string,string>::const_iterator it;

  for (it=g.datos.begin(); it!=g.datos.end();++it){
    aux.borrar(it->first,it->second);
  }

  return aux;
}

Guia_Tlf Guia_Tlf::interseccion (const Guia_Tlf & g) const{
  Guia_Tlf aux;
  map<string,string>::const_iterator it1, it2;

  for (it1=g.datos.begin(); it1!=g.datos.end(); ++it1){
    for (it2=datos.begin(); it2!=datos.end(); ++it2){
      if (it1->first == it2->first && it2->second == it1->second){
        aux.insert(it1->first, it1->second);
      }
    }
  }

  return aux;
}

bool Guia_Tlf::cambiar_num (const string & nombre, const string & nuevo_num){
	bool exito = false;
	string telf = gettelefono(nombre);

	if (telf != ""){
		borrar(nombre, telf);
		insert(nombre, nuevo_num);
		exito = true;
	}

	return exito;
}

Guia_Tlf Guia_Tlf::buscar_caracter (char & caracter) const{
	Guia_Tlf aux;
	map<string,string>::const_iterator it;
	string nombre;

	for (it=datos.begin(); it!=datos.end(); ++it){
		nombre = it->first;
		if (nombre[0] == caracter){
			aux.insert(it->first, it->second);
		}
	}

	return aux;
}

ostream & operator<<(ostream & os, Guia_Tlf & g){
    map<string,string>::iterator it;

    for (it=g.datos.begin(); it!=g.datos.end(); ++it){
        os << it->first << "\t" << it->second << endl;
    }

    return os;
}

istream & operator>>(istream & is, Guia_Tlf & g){
    pair<string,string> p;
    Guia_Tlf aux;

    while (is >> p){
      aux.insert(p);
    }

    g = aux;

    return is;
}
