/**
 * @file Fecha_Historica.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Fecha_Historica.h"

using namespace std;

//Resize simple
  void Fecha_Historica::resize(int r){
     string *aux = new string[r];

     for (int i=0; i<numeventos; ++i){
        aux[i] = str[i];
     }

     delete[] str;
     str = aux;
     reservados = r;
  }

//Constructor vacío
  Fecha_Historica::Fecha_Historica():anio(0),reservados(0),numeventos(0),str(0){}


//Constructor con parametros año, cadena de eventos y número de eventos a añadir
  Fecha_Historica::Fecha_Historica(int a, string *s, int n){
    assert(a >= 0 && a<= 9999);
    liberarMemoria();
    anio = a;
    copiar(s, n, n);
  }

//Libera memoria
  void Fecha_Historica::liberarMemoria(){
    anio = 0;
    numeventos = 0;
    reservados = 0;
    delete[] str;
  }

//Reserva memoria
  void Fecha_Historica::reservarMemoria(int r){
    if (r < 0)
      reservados = 0;
    else
      reservados = r;

    str = new string[reservados];
  }

//Copia strings en una Fecha_Historica
  void Fecha_Historica::copiar(string *s, int r, int ev){
    assert(ev <= r);
    numeventos = ev;
    reservarMemoria(r);

    for (int i=0; i<numeventos; i++)
      str[i] = s[i];
  }

//Operador de asignación
  Fecha_Historica& Fecha_Historica::operator=(const Fecha_Historica &e){
     if (this != &e){
       anio = e.anio;
       copiar(e.str, e.reservados, e.numeventos);
     }
      return *this;
  }


//Constructor de copias
   Fecha_Historica::Fecha_Historica(const Fecha_Historica& e){
      *this  = e;
   }


//Método de acceso a año
   int Fecha_Historica::getAnio() const{
    return anio;
   }


//Añade un evento
  void Fecha_Historica::aniadirevento(string& event){
     if (numeventos == reservados){
        if (numeventos == 0)
           resize(1);
        else
           resize(2*reservados);
     }

     str[numeventos] = event;
     numeventos++;
  }


//Buscador de eventos
  bool Fecha_Historica::buscarEventos(string s, Fecha_Historica &matches){
     bool encontrado = false;

     for (int i=0; i<numeventos; ++i){
        if (str[i].find(s) != -1 ){
           matches.aniadirevento(str[i]);
           encontrado = true;
        }
     }

     if (encontrado){
        matches.anio = anio;
     }

     return encontrado;
   }

//Número de eventos de la Fecha_Historica
   int Fecha_Historica::getEventos() const{
     return numeventos;
   }

//Número de eventos reservados
   int Fecha_Historica::getReservados() const{
     return reservados;
   }

//String de una posición
   string Fecha_Historica::getString(int posicion) const{
     return str[posicion];
   }


//Operador <<
  ostream& operator<< (ostream& os, const Fecha_Historica& e){
    os << e.getAnio();

    for (int i=0; i<e.numeventos; i++){
       os << "#" << e.str[i];
    }

    os << endl;

    return os;
  }

//Operador >>
  istream& operator>> (istream& is, Fecha_Historica& e){
    string ev;
    char caracter;
    int contador = 1, j = 0;

    e.liberarMemoria();

    is >> e.anio >> caracter;

    getline(is, ev);

    for (int i=0; i<ev.size(); i++){
      if (ev[i] == '#'){
        contador++;
      }
    }

    string *aux = new string[contador];

    for (int i=0; i<ev.size(); i++){
      if (ev[i] == '#'){
        j++;
      }
      else{
        aux[j].push_back(ev[i]);
      }
    }


    e.reservarMemoria(contador);

    for (int i=0; i<contador; i++){
      e.aniadirevento(aux[i]);
    }

    delete[] aux;

    return is;
  }
