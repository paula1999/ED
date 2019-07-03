/**
 * @file pruebacronologia.cpp
 * @author Paula Villanueva Nuñez
*/

#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
  int anio, posicion, aniodesde, aniohasta;
  string palabra;

  if (argc != 2){
      cout << "Dime el nombre del fichero con la cronologia" << endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
   }

   Cronologia mi_cronologia;

   f >> mi_cronologia; //Cargamos en memoria

   cout << "Cronología leida del archivo: " << endl << mi_cronologia << endl;

   //Dada una palabra, imprimir los eventos que la contienen
   cout << endl << "Introduce la palabra para buscar sus eventos asociados: " << endl;
   cin >> palabra;

   Cronologia buscadora = mi_cronologia.buscarEventos(palabra); // Utilización del operador =

   Cronologia copia(buscadora); //Utilización del constructor de copias

   if (copia.getEventos() == 0)
     cout << endl << "No se han encontrado eventos con \"" << palabra << "\"" << endl;
   else
     cout << endl << "Evento encontrado con \"" << palabra << "\":" << endl << copia;


   //Dado un año, imprimir los eventos de ese año
   cout << endl << "Introduce el año en el que buscar los eventos:" << endl;
   cin >> anio;

   posicion = mi_cronologia.buscarAnio(anio);

   if (posicion == -1)
     cout << "No se encontraron eventos en el año " << anio << endl;
   else
     cout << mi_cronologia.buscaranioevento(posicion);


   //Buscar los eventos de un intervalo
   cout << endl << "Introduce el intervalo de años en los que buscar los eventos" << endl;
   cin >> aniodesde >> aniohasta;

   Cronologia c_intervalo;
   c_intervalo = mi_cronologia.intervalo(aniodesde, aniohasta);
   cout << c_intervalo;


   //Imprimir los años con el máximo número de eventos de toda la cronología
   Cronologia max = mi_cronologia.maximoNumEventos();

   cout << endl << "Los años en los que sucedieron el máximo número de eventos son: " << endl << max << endl;

}
