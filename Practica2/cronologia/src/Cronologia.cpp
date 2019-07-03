/**
 * @file Cronologia.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include "Cronologia.h"
#include "Fecha_Historica.h"

using namespace std;

//Resize
  void Cronologia::resize(int r){
     if (r > reservados){
      Fecha_Historica *aux = new Fecha_Historica[r];

      for (int i=0; i<neventos; i++)
        aux[i] = event[i];

      delete[] event;
      event = aux;
      reservados = r;
     }
  }

//Ordena
  void Cronologia::ordenar(){
     for (int i=neventos-1; i>0; --i){
      for (int j=0; j<i; ++j){
         if (event[j].getAnio() > event[j+1].getAnio()){
            Fecha_Historica aux;
            aux = event[j];
            event[j] = event[j+1];
            event[j+1] = aux;
         }
       }
     }
}

//Constructor vacío
  Cronologia::Cronologia():reservados(0),neventos(0),event(0){}


//Constructor con parámetro cadena de Fecha_Historica y número de objetos
  Cronologia::Cronologia(Fecha_Historica *eh, int n){
     copiar(eh, n, n);
  }

//Constructor de copias
   Cronologia::Cronologia(const Cronologia& c){
      event = new Fecha_Historica[c.reservados];
      neventos = c.neventos;
      reservados = c.neventos;

      for (int i=0; i<neventos; ++i)
         event[i] = c.event[i];
   }

//Añade objeto de Fecha_Historica
  void Cronologia::aniadirEvento(Fecha_Historica& eh){
     if (neventos == reservados){
        if (neventos == 0)
           resize(1);
        else
           resize(2*reservados);
     }

     event[neventos] = eh;
     neventos++;
     ordenar();
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  int Cronologia::buscarAnio(int f) const{
     int i = 0;
     bool valido = false;

     while (i < neventos && !valido){
        if (event[i].getAnio() == f)
           valido = true;
        else
           ++i;
     }

     if(!valido)
        i = -1;

     return i;
  }

//Los eventos del año de posicion
  Fecha_Historica Cronologia::buscaranioevento(int posicion) const{
    assert (posicion >= 0);
    Fecha_Historica ev = event[posicion];

    return ev;
  }


//Busca un evento en la Cronología y devuelve su posición en el vector
  Cronologia Cronologia::buscarEventos(string s) const{
     Cronologia nuevo;

     for (int i=0; i < neventos; ++i){
        Fecha_Historica aux;

        if(event[i].buscarEventos(s,aux)){
           nuevo.aniadirEvento(aux);
        }
     }

     nuevo.ordenar();
     return nuevo;
   }

//Libera memoria
   void Cronologia::liberarMemoria(){
     neventos = 0;
     reservados = 0;
     delete[] event;
   }

//Reserva memoria
   void Cronologia::reservarMemoria(int r){
     if (r > 0){
       reservados = r;
       event = new Fecha_Historica[r];
     }
     else
       reservados = 0;
   }

//Copia fechas históricas en una cronología
   void Cronologia::copiar(Fecha_Historica *e, int r, int ev){
     liberarMemoria();
     reservarMemoria(r);
     neventos = ev;

     for (int i=0; i<neventos; i++)
       event[i] = e[i];
   }

//Operador de asignación
   Cronologia& Cronologia::operator=(const Cronologia& c){
     if (this != &c){
       copiar(c.event, c.reservados, c.neventos);
     }

     return *this;
   }

//Número de eventos
   int Cronologia::getEventos () const{
     return neventos;
   }

//Cronología de los años con el máximo número de eventos
   Cronologia Cronologia::maximoNumEventos() const{
     int max = 0;
     Cronologia cmax;

     for (int i=0; i<neventos; i++){
       if (event[i].getEventos() > max)
          max = event[i].getEventos();
     }

     for (int i=0; i<neventos; i++){
       if (event[i].getEventos() == max){
         cmax.aniadirEvento(event[i]);
       }
     }

     return cmax;
   }

   Cronologia Cronologia::intervalo(const int aniodesde, const int aniohasta) const{
     Cronologia c_interv;

     for (int i=buscarAnio(aniodesde); i<=buscarAnio(aniohasta); i++){
         if (i != -1)
            c_interv.aniadirEvento(event[i]);
     }

     return c_interv;
   }

//Operador <<
  ostream& operator<< (ostream& os, const Cronologia& c){
     for (int i=0; i<c.neventos; i++)
        os << c.event[i];

     return os;
  }

//Operador >>
  istream& operator>> (istream& is, Cronologia& c){
     Fecha_Historica b;

     while (is >> b){
        c.aniadirEvento(b);
     }

     return is;
  }
